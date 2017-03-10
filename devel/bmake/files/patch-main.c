--- main.c.orig	2017-01-14 23:09:40 UTC
+++ main.c
@@ -1063,6 +1063,12 @@ main(int argc, char **argv)
 	    Var_Set(".MAKE.PID", tmp, VAR_GLOBAL, 0);
 	    snprintf(tmp, sizeof(tmp), "%u", getppid());
 	    Var_Set(".MAKE.PPID", tmp, VAR_GLOBAL, 0);
+	    Var_Set(".MAKE.OS.NAME",          OSNAME,  VAR_GLOBAL, 0);
+	    Var_Set(".MAKE.OS.VERSION",       OSVER,   VAR_GLOBAL, 0);
+	    Var_Set(".MAKE.OS.RELEASE",       OSREL,   VAR_GLOBAL, 0);
+	    Var_Set(".MAKE.OS.MAJOR",         OSMAJOR, VAR_GLOBAL, 0);
+	    Var_Set(".MAKE.OS.ARCHITECTURE",  OSARCH,  VAR_GLOBAL, 0);
+	    Var_Set(".MAKE.OS.ARCH.STANDARD", ARCHSTD, VAR_GLOBAL, 0);
 	}
 	if (makelevel > 0) {
 		char pn[1024];
