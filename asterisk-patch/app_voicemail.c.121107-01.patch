*** apps/app_voicemail.c.org	2012-09-26 06:13:46.000000000 +0900
--- apps/app_voicemail.c	2012-11-07 00:25:29.415566181 +0900
***************
*** 7458,7463 ****
--- 7458,7490 ----
  	return d;
  }
  
+ /* Japanese Syntax */
+ static int get_folder_ja(struct ast_channel *chan, int start)
+ {
+       int x;
+       int d;
+       char fn[256];
+       for (x = start; x< 5; x++) {    /* For all folders */
+               if ((d = ast_say_number(chan, x, AST_DIGIT_ANY, ast_channel_language(chan), (char *) NULL)))
+                       return d;
+               snprintf(fn, sizeof(fn), "vm-%s", mbox(NULL, x));     /* Folder name */
+               d = vm_play_folder_name(chan, fn);
+               if (d)
+                       return d;
+               d = ast_waitfordigit(chan, 500);
+               if (d)
+                       return d;
+       }
+       d = ast_play_and_wait(chan, "vm-tocancel"); /* "or pound to cancel" */
+       if (d)
+               return d;
+       d = ast_play_and_wait(chan, "jp-oshitekudasai");
+       if (d)
+               return d;
+       d = ast_waitfordigit(chan, 4000);
+               return d;
+ }
+ 
  /*!
   * \brief plays a prompt and waits for a keypress.
   * \param chan
***************
*** 7479,7485 ****
  	while (((res < '0') || (res > '9')) &&
  			(res != '#') && (res >= 0) &&
  			loops < 4) {
! 		res = get_folder(chan, 0);
  		loops++;
  	}
  	if (loops == 4) { /* give up */
--- 7506,7516 ----
  	while (((res < '0') || (res > '9')) &&
  			(res != '#') && (res >= 0) &&
  			loops < 4) {
!                 /* res = get_folder(chan, 0); */
!                 if (!strcasecmp(ast_channel_language(chan),"ja"))   /* Japanese syntax */
!                       res = get_folder_ja(chan, 0);
!                 else /* Default syntax */
! 		      res = get_folder(chan, 0);
  		loops++;
  	}
  	if (loops == 4) { /* give up */
***************
*** 8241,8246 ****
--- 8272,8279 ----
  		res = ast_say_date_with_format(chan, t, AST_DIGIT_ANY, ast_channel_language(chan), "'vm-received' q  H 'digits/kai' M ", NULL);
  	} else if (!strncasecmp(ast_channel_language(chan), "it", 2)) {     /* ITALIAN syntax */
  		res = ast_say_date_with_format(chan, t, AST_DIGIT_ANY, ast_channel_language(chan), "'vm-received' q 'digits/at' 'digits/hours' k 'digits/e' M 'digits/minutes'", NULL);
+ 	} else if (!strcasecmp(ast_channel_language(chan),"ja")) {     /* Japanese syntax */
+ 		res = ast_say_date_with_format(chan, t, AST_DIGIT_ANY, ast_channel_language(chan), "PHM q 'jp-ni' 'vm-received'", NULL);
  	} else if (!strncasecmp(ast_channel_language(chan), "nl", 2)) {     /* DUTCH syntax */
  		res = ast_say_date_with_format(chan, t, AST_DIGIT_ANY, ast_channel_language(chan), "'vm-received' q 'digits/nl-om' HM", NULL);
  	} else if (!strncasecmp(ast_channel_language(chan), "no", 2)) {     /* NORWEGIAN syntax */
***************
*** 9071,9076 ****
--- 9104,9155 ----
  	}
  	return res;
  }
+ 
+ /* Japanese syntax */
+ static int vm_intro_ja(struct ast_channel *chan,struct vm_state *vms)
+ {
+       /* Introduce messages they have */
+       int res;
+       res = ast_play_and_wait(chan, "vm-youhave");
+       if (!res) {
+               if (vms->newmessages) {
+                       res = ast_play_and_wait(chan, "vm-INBOX");
+                       if (!res)
+                               res = ast_play_and_wait(chan, "vm-message");
+                       if (!res)
+                               res = ast_play_and_wait(chan, "jp-ga");
+                       if (!res)
+                               res = say_and_wait(chan, vms->newmessages, ast_channel_language(chan));
+                       if (vms->oldmessages && !res)
+                               res = ast_play_and_wait(chan, "vm-and");
+ 
+               }
+               if (!res && vms->oldmessages) {
+                       res = ast_play_and_wait(chan, "vm-Old");
+                       if (!res)
+                               res = ast_play_and_wait(chan, "vm-message");
+                       if (!res)
+                               res = ast_play_and_wait(chan, "jp-ga");
+                       if (!res)
+                               res = say_and_wait(chan, vms->oldmessages, ast_channel_language(chan));
+               }
+               if (!res) {
+                       if (!vms->oldmessages && !vms->newmessages) {
+                               res = ast_play_and_wait(chan, "vm-messages");
+                               if (!res)
+                                       res = ast_play_and_wait(chan, "jp-wa");
+                               if (!res)
+                                       res = ast_play_and_wait(chan, "jp-wa");
+                               if (!res)
+                                       res = ast_play_and_wait(chan, "vm-no");
+                       }
+                       else if (!res) {
+                               res = ast_play_and_wait(chan, "jp-arimasu");
+                       }
+               }
+       }
+       return res;
+ } /* Japanese */
  	
  /* Default English syntax */
  static int vm_intro_en(struct ast_channel *chan, struct vm_state *vms)
***************
*** 9795,9800 ****
--- 9874,9881 ----
  		return vm_intro_he(chan, vms);
  	} else if (!strncasecmp(ast_channel_language(chan), "it", 2)) {  /* ITALIAN syntax */
  		return vm_intro_it(chan, vms);
+ 	} else if (!strncasecmp(ast_channel_language(chan), "ja", 2)) {  /* JAPANESE syntax */
+ 		return vm_intro_ja(chan, vms);
  	} else if (!strncasecmp(ast_channel_language(chan), "nl", 2)) {  /* DUTCH syntax */
  		return vm_intro_nl(chan, vms);
  	} else if (!strncasecmp(ast_channel_language(chan), "no", 2)) {  /* NORWEGIAN syntax */
