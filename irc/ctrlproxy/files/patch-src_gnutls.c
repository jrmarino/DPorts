
$FreeBSD: head/irc/ctrlproxy/files/patch-src_gnutls.c 340725 2014-01-22 17:40:44Z mat $

--- src/gnutls.c.orig
+++ src/gnutls.c
@@ -18,7 +18,6 @@
 
 #include <glib.h>
 
-#include <gcrypt.h>
 #include <gnutls/gnutls.h>
 #include <gnutls/x509.h>
 
@@ -452,9 +451,6 @@
 static void
 _gnutls_init (void)
 {
-	/* to disallow usage of the blocking /dev/random */
-	gcry_control (GCRYCTL_ENABLE_QUICK_RANDOM, 0);
-
 	gnutls_global_init ();
 	gnutls_inited = TRUE;
 }
