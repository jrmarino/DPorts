--- libmpdemux/demux_rtp.cpp.orig	2012-03-05 19:14:38.000000000 +0100
+++ libmpdemux/demux_rtp.cpp	2013-11-16 23:39:54.000000000 +0100
@@ -19,7 +19,7 @@
  * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
  */
 
-#define RTSPCLIENT_SYNCHRONOUS_INTERFACE 1
+// Patch from Armin K. <krejzi at email dot com>
 
 extern "C" {
 // on MinGW, we must include windows.h before the things it conflicts
@@ -94,15 +94,6 @@
 
 extern "C" char* network_username;
 extern "C" char* network_password;
-static char* openURL_rtsp(RTSPClient* client, char const* url) {
-  // If we were given a user name (and optional password), then use them:
-  if (network_username != NULL) {
-    char const* password = network_password == NULL ? "" : network_password;
-    return client->describeWithPassword(url, network_username, password);
-  } else {
-    return client->describeURL(url);
-  }
-}
 
 static char* openURL_sip(SIPClient* client, char const* url) {
   // If we were given a user name (and optional password), then use them:
@@ -126,6 +117,19 @@
 extern AVCodecContext *avcctx;
 #endif
 
+static char fWatchVariableForSyncInterface;
+static char* fResultString;
+static int fResultCode;
+
+static void responseHandlerForSyncInterface(RTSPClient* rtspClient, int responseCode, char* responseString) {
+  // Set result values:
+  fResultCode = responseCode;
+  fResultString = responseString;
+
+  // Signal a break from the event loop (thereby returning from the blocking command):
+  fWatchVariableForSyncInterface = ~0;
+}
+
 extern "C" int audio_id, video_id, dvdsub_id;
 extern "C" demuxer_t* demux_open_rtp(demuxer_t* demuxer) {
   Boolean success = False;
@@ -154,13 +158,19 @@
 	  rtsp_transport_http = demuxer->stream->streaming_ctrl->url->port;
 	  rtsp_transport_tcp = 1;
 	}
-	rtspClient = RTSPClient::createNew(*env, verbose, "MPlayer", rtsp_transport_http);
+	rtspClient = RTSPClient::createNew(*env, url, verbose, "MPlayer", rtsp_transport_http);
 	if (rtspClient == NULL) {
 	  fprintf(stderr, "Failed to create RTSP client: %s\n",
 		  env->getResultMsg());
 	  break;
 	}
-	sdpDescription = openURL_rtsp(rtspClient, url);
+	fWatchVariableForSyncInterface = 0;
+	rtspClient->sendDescribeCommand(responseHandlerForSyncInterface);
+	env->taskScheduler().doEventLoop(&fWatchVariableForSyncInterface);
+	if (fResultCode == 0)
+	    sdpDescription = fResultString;
+	else
+	    delete[] fResultString;
       } else { // SIP
 	unsigned char desiredAudioType = 0; // PCMU (use 3 for GSM)
 	sipClient = SIPClient::createNew(*env, desiredAudioType, NULL,
@@ -244,8 +254,12 @@
 
 	if (rtspClient != NULL) {
 	  // Issue a RTSP "SETUP" command on the chosen subsession:
-	  if (!rtspClient->setupMediaSubsession(*subsession, False,
-						rtsp_transport_tcp)) break;
+	  fWatchVariableForSyncInterface = 0;
+	  rtspClient->sendSetupCommand(*subsession, responseHandlerForSyncInterface, False, rtsp_transport_tcp);
+	  env->taskScheduler().doEventLoop(&fWatchVariableForSyncInterface);
+	  delete[] fResultString;
+	  if (fResultCode != 0) break;
+
 	  if (!strcmp(subsession->mediumName(), "audio"))
 	    audiofound = 1;
 	  if (!strcmp(subsession->mediumName(), "video"))
@@ -256,7 +270,11 @@
 
     if (rtspClient != NULL) {
       // Issue a RTSP aggregate "PLAY" command on the whole session:
-      if (!rtspClient->playMediaSession(*mediaSession)) break;
+      fWatchVariableForSyncInterface = 0;
+      rtspClient->sendPlayCommand(*mediaSession, responseHandlerForSyncInterface);
+      env->taskScheduler().doEventLoop(&fWatchVariableForSyncInterface);
+      delete[] fResultString;
+      if (fResultCode != 0) break;
     } else if (sipClient != NULL) {
       sipClient->sendACK(); // to start the stream flowing
     }
@@ -645,7 +663,8 @@
   MediaSession* mediaSession = rtpState->mediaSession;
   if (mediaSession == NULL) return;
   if (rtpState->rtspClient != NULL) {
-    rtpState->rtspClient->teardownMediaSession(*mediaSession);
+    fWatchVariableForSyncInterface = 0;
+    rtpState->rtspClient->sendTeardownCommand(*mediaSession, NULL);
   } else if (rtpState->sipClient != NULL) {
     rtpState->sipClient->sendBYE();
   }
