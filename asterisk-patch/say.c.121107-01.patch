*** main/say.c.org	2012-09-26 08:09:40.000000000 +0900
--- main/say.c	2012-11-06 18:43:03.301319699 +0900
***************
*** 350,355 ****
--- 350,356 ----
  static int ast_say_number_full_se(struct ast_channel *chan, int num, const char *ints, const char *language, const char *options, int audiofd, int ctrlfd);
  static int ast_say_number_full_zh(struct ast_channel *chan, int num, const char *ints, const char *language, int audiofd, int ctrlfd);
  static int ast_say_number_full_gr(struct ast_channel *chan, int num, const char *ints, const char *language, int audiofd, int ctrlfd);
+ static int ast_say_number_full_ja(struct ast_channel *chan, int num, const char *ints, const char *language, int audiofd, int ctrlfd);
  static int ast_say_number_full_ru(struct ast_channel *chan, int num, const char *ints, const char *language, const char *options, int audiofd, int ctrlfd);
  static int ast_say_number_full_ka(struct ast_channel *chan, int num, const char *ints, const char *language, const char *options, int audiofd, int ctrlfd);
  static int ast_say_number_full_hu(struct ast_channel *chan, int num, const char *ints, const char *language, int audiofd, int ctrlfd);
***************
*** 372,377 ****
--- 373,379 ----
  static int ast_say_date_nl(struct ast_channel *chan, time_t t, const char *ints, const char *lang);
  static int ast_say_date_pt(struct ast_channel *chan, time_t t, const char *ints, const char *lang);
  static int ast_say_date_gr(struct ast_channel *chan, time_t t, const char *ints, const char *lang);
+ static int ast_say_date_ja(struct ast_channel *chan, time_t t, const char *ints, const char *lang);
  static int ast_say_date_ka(struct ast_channel *chan, time_t t, const char *ints, const char *lang);
  static int ast_say_date_hu(struct ast_channel *chan, time_t t, const char *ints, const char *lang);
  static int ast_say_date_th(struct ast_channel *chan, time_t t, const char *ints, const char *lang);
***************
*** 389,394 ****
--- 391,397 ----
  static int ast_say_date_with_format_pt(struct ast_channel *chan, time_t t, const char *ints, const char *lang, const char *format, const char *tzone);
  static int ast_say_date_with_format_zh(struct ast_channel *chan, time_t t, const char *ints, const char *lang, const char *format, const char *tzone);
  static int ast_say_date_with_format_gr(struct ast_channel *chan, time_t t, const char *ints, const char *lang, const char *format, const char *tzone);
+ static int ast_say_date_with_format_ja(struct ast_channel *chan, time_t t, const char *ints, const char *lang, const char *format, const char *tzone);
  static int ast_say_date_with_format_th(struct ast_channel *chan, time_t t, const char *ints, const char *lang, const char *format, const char *tzone);
  static int ast_say_date_with_format_vi(struct ast_channel *chan, time_t t, const char *ints, const char *lang, const char *format, const char *tzone);
  
***************
*** 400,405 ****
--- 403,409 ----
  static int ast_say_time_pt_BR(struct ast_channel *chan, time_t t, const char *ints, const char *lang);
  static int ast_say_time_zh(struct ast_channel *chan, time_t t, const char *ints, const char *lang);
  static int ast_say_time_gr(struct ast_channel *chan, time_t t, const char *ints, const char *lang);
+ static int ast_say_time_ja(struct ast_channel *chan, time_t t, const char *ints, const char *lang);
  static int ast_say_time_ka(struct ast_channel *chan, time_t t, const char *ints, const char *lang);
  static int ast_say_time_hu(struct ast_channel *chan, time_t t, const char *ints, const char *lang);
  static int ast_say_time_th(struct ast_channel *chan, time_t t, const char *ints, const char *lang);
***************
*** 413,418 ****
--- 417,423 ----
  static int ast_say_datetime_pt_BR(struct ast_channel *chan, time_t t, const char *ints, const char *lang);
  static int ast_say_datetime_zh(struct ast_channel *chan, time_t t, const char *ints, const char *lang);
  static int ast_say_datetime_gr(struct ast_channel *chan, time_t t, const char *ints, const char *lang);
+ static int ast_say_datetime_ja(struct ast_channel *chan, time_t t, const char *ints, const char *lang);
  static int ast_say_datetime_ka(struct ast_channel *chan, time_t t, const char *ints, const char *lang);
  static int ast_say_datetime_hu(struct ast_channel *chan, time_t t, const char *ints, const char *lang);
  static int ast_say_datetime_th(struct ast_channel *chan, time_t t, const char *ints, const char *lang);
***************
*** 469,474 ****
--- 474,481 ----
  		return ast_say_number_full_ka(chan, num, ints, language, options, audiofd, ctrlfd);
  	} else if (!strncasecmp(language, "gr", 2)) { /* Greek syntax */
  	   return ast_say_number_full_gr(chan, num, ints, language, audiofd, ctrlfd);
+ 	} else if (!strncasecmp(language, "ja", 2)) { /* Japanese syntax */
+ 	   return ast_say_number_full_ja(chan, num, ints, language, audiofd, ctrlfd);
  	} else if (!strncasecmp(language, "he", 2)) { /* Hebrew syntax */
  	   return ast_say_number_full_he(chan, num, ints, language, options, audiofd, ctrlfd);
  	} else if (!strncasecmp(language, "hu", 2)) { /* Hungarian syntax */
***************
*** 3309,3314 ****
--- 3316,3323 ----
  		return ast_say_date_ka(chan, t, ints, lang);
  	} else if (!strncasecmp(lang, "gr", 2)) { /* Greek syntax */
  		return ast_say_date_gr(chan, t, ints, lang);
+ 	} else if (!strncasecmp(lang, "ja", 2)) { /* Japanese syntax */
+ 		return ast_say_date_ja(chan, t, ints, lang);
  	} else if (!strncasecmp(lang, "he", 2)) { /* Hebrew syntax */
  		return ast_say_date_he(chan, t, ints, lang);
  	} else if (!strncasecmp(lang, "hu", 2)) { /* Hungarian syntax */
***************
*** 3658,3663 ****
--- 3667,3674 ----
  		return ast_say_date_with_format_fr(chan, t, ints, lang, format, tzone);
  	} else if (!strncasecmp(lang, "gr", 2)) { /* Greek syntax */
  		return ast_say_date_with_format_gr(chan, t, ints, lang, format, tzone);
+ 	} else if (!strncasecmp(lang, "ja", 2)) { /* Japanese syntax */
+ 		return ast_say_date_with_format_ja(chan, t, ints, lang, format, tzone);
  	} else if (!strncasecmp(lang, "it", 2)) { /* Italian syntax */
  		return ast_say_date_with_format_it(chan, t, ints, lang, format, tzone);
  	} else if (!strncasecmp(lang, "mx", 2)) { /* deprecated Mexican syntax */
***************
*** 6290,6295 ****
--- 6301,6308 ----
  		return ast_say_time_ka(chan, t, ints, lang);
  	} else if (!strncasecmp(lang, "gr", 2)) { /* Greek syntax */
  		return ast_say_time_gr(chan, t, ints, lang);
+ 	} else if (!strncasecmp(lang, "ja", 2)) { /* Japanese syntax */
+ 		return ast_say_time_ja(chan, t, ints, lang);
  	} else if (!strncasecmp(lang, "he", 2)) { /* Hebrew syntax */
  		return ast_say_time_he(chan, t, ints, lang);
  	} else if (!strncasecmp(lang, "hu", 2)) { /* Hungarian syntax */
***************
*** 6621,6626 ****
--- 6634,6641 ----
  		return ast_say_datetime_ka(chan, t, ints, lang);
  	} else if (!strncasecmp(lang, "gr", 2)) { /* Greek syntax */
  		return ast_say_datetime_gr(chan, t, ints, lang);
+ 	} else if (!strncasecmp(lang, "gr", 2)) { /* Japanese syntax */
+ 		return ast_say_datetime_ja(chan, t, ints, lang);
  	} else if (!strncasecmp(lang, "he", 2)) { /* Hebrew syntax */
  		return ast_say_datetime_he(chan, t, ints, lang);
  	} else if (!strncasecmp(lang, "hu", 2)) { /* Hungarian syntax */
***************
*** 7363,7368 ****
--- 7378,7448 ----
  	return res;
  }
  
+ /* Japanese syntax */
+ static int ast_say_number_full_ja(struct ast_channel *chan, int num, const char *ints, const char *language, int audiofd, int ctrlfd)
+ {
+      int res = 0;
+      int playh = 0;
+      char fn[256] = "";
+      if (!num)
+              return ast_say_digits_full(chan, 0, ints, language, audiofd, ctrlfd);
+ 
+      while (!res && (num || playh)) {
+              if (num < 0) {
+                      ast_copy_string(fn, "digits/minus", sizeof(fn));
+                      if ( num > INT_MIN ) {
+                              num = -num;
+                      } else {
+                              num = 0;
+                      }
+              } else if (playh) {
+                      ast_copy_string(fn, "digits/hundred", sizeof(fn));
+                      playh = 0;
+              } else  if (num < 20) {
+                      snprintf(fn, sizeof(fn), "digits/%d", num);
+                      num = 0;
+              } else  if (num < 100) {
+                      snprintf(fn, sizeof(fn), "digits/%d", (num /10) * 10);
+                      num %= 10;
+              } else {
+                      if (num < 1000){
+                              snprintf(fn, sizeof(fn), "digits/%d", (num/100));
+                              playh++;
+                              num %= 100;
+                      } else {
+                              if (num < 1000000) { /* 1,000,000 */
+                                      res = ast_say_number_full_en(chan, num / 1000, ints, language, audiofd, ctrlfd);
+                                      if (res)
+                                              return res;
+                                      num %= 1000;
+                                      snprintf(fn, sizeof(fn), "digits/thousand");
+                              } else {
+                                      if (num < 1000000000) { /* 1,000,000,000 */
+                                              res = ast_say_number_full_en(chan, num / 1000000, ints, language, audiofd, ctrlfd);
+                                              if (res)
+                                                      return res;
+                                              num %= 1000000;
+                                              ast_copy_string(fn, "digits/million", sizeof(fn));
+                                      } else {
+                                              ast_debug(1, "Number '%d' is too big for me\n", num);
+                                              res = -1;
+                                      }
+                              }
+                      }
+              }
+              if (!res) {
+                      if (!ast_streamfile(chan, fn, language)) {
+                              if ((audiofd  > -1) && (ctrlfd > -1))
+                                      res = ast_waitstream_full(chan, ints, audiofd, ctrlfd);
+                              else
+                                      res = ast_waitstream(chan, ints);
+                      }
+                      ast_stopstream(chan);
+              }
+      }
+      return res;
+ }
+ 
  
  /*! \brief Greek support
   *
***************
*** 7408,7413 ****
--- 7488,7528 ----
  }
  
  
+ /* Japanese syntax */
+ int ast_say_date_ja(struct ast_channel *chan, time_t t, const char *ints, const char *lang)
+ {
+       struct ast_tm tm;
+       struct timeval tv = { t, 0 };
+       char fn[256];
+       int res = 0;
+       ast_localtime(&tv, &tm, NULL);
+       if (!res)
+               res = ast_say_number(chan, tm.tm_year + 1900, ints, lang, (char *) NULL);
+       if (!res)
+               res = ast_waitstream(chan, ints);
+       if (!res)
+               res = ast_streamfile(chan, "digits/nen", lang);
+       if (!res) {
+               snprintf(fn, sizeof(fn), "digits/mon-%d", tm.tm_mon);
+               res = ast_streamfile(chan, fn, lang);
+               if (!res)
+                       res = ast_waitstream(chan, ints);
+       }
+       if (!res)
+               res = ast_streamfile(chan, "digits/gatsu", lang);
+       if (!res)
+               res = ast_say_number(chan, tm.tm_mday, ints, lang, (char * ) NULL);
+       if (!res)
+               res = ast_streamfile(chan, "digits/nichi", lang);
+       if (!res) {
+               snprintf(fn, sizeof(fn), "digits/day-%d", tm.tm_wday);
+               res = ast_streamfile(chan, fn, lang);
+               if (!res)
+                       res = ast_waitstream(chan, ints);
+       }
+       return res;
+ }
+ 
  
  /*! \brief Greek support
   *
***************
*** 7465,7470 ****
--- 7580,7626 ----
  }
  
  
+ /* Japanese */
+ static int ast_say_time_ja(struct ast_channel *chan, time_t t, const char *ints, const char *lang)
+ {
+ 
+       struct timeval tv = { t, 0 };
+       struct ast_tm tm;
+       int res = 0;
+       int hour, pm=0;
+ 
+       ast_localtime(&tv, &tm, NULL);
+       hour = tm.tm_hour;
+ 
+       if (!hour)
+               hour = 12;
+       else if (hour == 12)
+               pm = 1;
+       else if (hour > 12) {
+               hour -= 12;
+               pm = 1;
+       }
+ 
+       if (pm) {
+               if (!res)
+                       res = ast_streamfile(chan, "digits/p-m", lang);
+       } else {
+               if (!res)
+                       res = ast_streamfile(chan, "digits/a-m", lang);
+       }
+       if (!res)
+               res = ast_say_number(chan, hour, ints, lang, (char *) NULL);
+       if (!res)
+               res = ast_streamfile(chan, "digits/ji", lang);
+       if (!res)
+               res = ast_say_number(chan, tm.tm_min, ints, lang, (char *) NULL);
+       if (!res)
+               res = ast_streamfile(chan, "digits/fun", lang);
+       if (!res)
+               res = ast_waitstream(chan, ints);
+       return res;
+ }
+ 
  
  /*! \brief Greek support
   */
***************
*** 7500,7505 ****
--- 7656,7724 ----
  	return res;
  }
  
+ /* Japanese syntax */
+ int ast_say_datetime_ja(struct ast_channel *chan, time_t t, const char *ints, const char *lang)
+ {
+       struct timeval tv = { t, 0 };
+       struct ast_tm tm;
+       char fn[256];
+       int res = 0;
+       int hour, pm=0;
+ 
+       ast_localtime(&tv, &tm, NULL);
+ 
+       if (!res)
+               res = ast_say_number(chan, tm.tm_year + 1900, ints, lang, (char *) NULL);
+       if (!res)
+               res = ast_streamfile(chan, "digits/nen", lang);
+       if (!res) {
+               snprintf(fn, sizeof(fn), "digits/mon-%d", tm.tm_mon);
+               res = ast_streamfile(chan, fn, lang);
+               if (!res)
+                       res = ast_waitstream(chan, ints);
+       }
+       if (!res)
+               res = ast_streamfile(chan, "digits/gatsu", lang);
+       if (!res)
+               res = ast_say_number(chan, tm.tm_mday, ints, lang, (char *) NULL);
+       if (!res)
+               res = ast_streamfile(chan, "digits/nichi", lang);
+       if (!res) {
+               snprintf(fn, sizeof(fn), "digits/day-%d", tm.tm_wday);
+               res = ast_streamfile(chan, fn, lang);
+       if (!res)
+               res = ast_waitstream(chan, ints);
+       }
+ 
+       hour = tm.tm_hour;
+       if (!hour)
+               hour = 12;
+       else if (hour == 12)
+               pm = 1;
+       else if (hour > 12) {
+               hour -= 12;
+               pm = 1;
+       }
+       if (pm) {
+               if (!res)
+                       res = ast_streamfile(chan, "digits/p-m", lang);
+       } else {
+               if (!res)
+                       res = ast_streamfile(chan, "digits/a-m", lang);
+       }
+       if (!res)
+               res = ast_say_number(chan, hour, ints, lang, (char *) NULL);
+       if (!res)
+               res = ast_streamfile(chan, "digits/ji", lang);
+       if (!res)
+               res = ast_say_number(chan, tm.tm_min, ints, lang, (char *) NULL);
+       if (!res)
+               res = ast_streamfile(chan, "digits/fun", lang);
+       if (!res)
+               res = ast_waitstream(chan, ints);
+       return res;
+ }
+ 
  /*! \brief Greek support
   */
  static int ast_say_date_with_format_gr(struct ast_channel *chan, time_t t, const char *ints, const char *lang, const char *format, const char *tzone)
***************
*** 7673,7678 ****
--- 7892,8186 ----
  	return res;
  }
  
+ /* Japanese syntax */
+ int ast_say_date_with_format_ja(struct ast_channel *chan, time_t time, const char *ints, const char *lang, const char *format, const char *timezone)
+ {
+      struct timeval tv = { time, 0 };
+      struct ast_tm tm;
+      int res=0, offset, sndoffset;
+      char sndfile[256], nextmsg[256];
+ 
+      if (!format)
+            format = "YbdAPIMS";
+ 
+      ast_localtime(&tv, &tm, timezone);
+ 
+      for (offset=0 ; format[offset] != '\0' ; offset++) {
+              ast_log(LOG_DEBUG, "Parsing %c (offset %d) in %s\n", format[offset], offset, format);
+              switch (format[offset]) {
+                      /* NOTE:  if you add more options here, please try to be consistent with strftime(3) */
+                      case '\'':
+                              /* Literal name of a sound file */
+                              sndoffset=0;
+                              for (sndoffset=0 ; (format[++offset] != '\'') && (sndoffset < 256) ; sndoffset++)
+                                      sndfile[sndoffset] = format[offset];
+                              sndfile[sndoffset] = '\0';
+                              res = wait_file(chan,ints,sndfile,lang);
+                              break;
+                      case 'A':
+                      case 'a':
+                              /* Sunday - Saturday */
+                              snprintf(nextmsg,sizeof(nextmsg), "digits/day-%d", tm.tm_wday);
+                              res = wait_file(chan,ints,nextmsg,lang);
+                              break;
+                      case 'B':
+                      case 'b':
+                      case 'h':
+                              /* January - December */
+                              snprintf(nextmsg,sizeof(nextmsg), "digits/mon-%d", tm.tm_mon);
+                              res = wait_file(chan,ints,nextmsg,lang);
+                              break;
+                      case 'd':
+                      case 'e':
+                              /* First - Thirtyfirst */
+                              if (tm.tm_mday < 21) {
+                                      snprintf(nextmsg,sizeof(nextmsg), "digits/%d", tm.tm_mday);
+                                      res = wait_file(chan,ints,nextmsg,lang);
+                              } else if (tm.tm_mday < 30) {
+                                      /* Between 21 and 29 - two sounds */
+                                      res = wait_file(chan,ints, "digits/20",lang);
+                                      if (!res) {
+                                              snprintf(nextmsg,sizeof(nextmsg), "digits/%d", tm.tm_mday - 20);
+                                              res = wait_file(chan,ints,nextmsg,lang);
+                                      }
+                              } else if (tm.tm_mday == 30) {
+                                      /* 30 */
+                                      res = wait_file(chan,ints, "digits/30",lang);
+                              } else {
+                                      /* 31 */
+                                      res = wait_file(chan,ints, "digits/30",lang);
+                                      res = wait_file(chan,ints, "digits/1",lang);
+                              }
+                              res = wait_file(chan,ints, "digits/nichi",lang);
+                              break;
+                      case 'Y':
+                              /* Year */
+                              if (tm.tm_year > 99) {
+                                      res = wait_file(chan,ints, "digits/2",lang);
+                                      if (!res) {
+                                              res = wait_file(chan,ints, "digits/thousand",lang);
+                                      }
+                                      if (tm.tm_year > 100) {
+                                              if (!res) {
+                                                      /* This works until the end of 2020 */
+                                                      snprintf(nextmsg,sizeof(nextmsg), "digits/%d", tm.tm_year - 100);
+                                                      res = wait_file(chan,ints,nextmsg,lang);
+                                              }
+                                      }
+                              } else {
+                                      if (tm.tm_year < 1) {
+                                              /* I'm not going to handle 1900 and prior */
+                                              /* We'll just be silent on the year, instead of bombing out. */
+ 	                                       } else {
+ 							 res = wait_file(chan,ints, "digits/19",lang);
+                                              if (!res) {
+                                                      if (tm.tm_year <= 9) {
+                                                              /* 1901 - 1909 */
+                                                              res = wait_file(chan,ints, "digits/oh",lang);
+                                                              if (!res) {
+                                                                      snprintf(nextmsg,sizeof(nextmsg), "digits/%d", tm.tm_year);
+                                                                      res = wait_file(chan,ints,nextmsg,lang);
+                                                              }
+                                                      } else if (tm.tm_year <= 20) {
+                                                              /* 1910 - 1920 */
+                                                              snprintf(nextmsg,sizeof(nextmsg), "digits/%d", tm.tm_year);
+                                                              res = wait_file(chan,ints,nextmsg,lang);
+                                                      } else {
+                                                              /* 1921 - 1999 */
+                                                              int ten, one;
+                                                              ten = tm.tm_year / 10;
+                                                              one = tm.tm_year % 10;
+                                                              snprintf(nextmsg,sizeof(nextmsg), "digits/%d", ten * 10);
+                                                              res = wait_file(chan,ints,nextmsg,lang);
+                                                              if (!res) {
+                                                                      if (one != 0) {
+                                                                              snprintf(nextmsg,sizeof(nextmsg), "digits/%d", one);
+                                                                              res = wait_file(chan,ints,nextmsg,lang);
+                                                                      }
+                                                              }
+                                                      }
+                                              }
+                                      }
+                              }
+                              res = wait_file(chan,ints, "digits/nen",lang);
+                              break;
+                      case 'P':
+                      case 'p':
+                              /* AM/PM */
+                              if (tm.tm_hour > 11)
+                                      snprintf(nextmsg,sizeof(nextmsg), "digits/p-m");
+                              else
+                                      snprintf(nextmsg,sizeof(nextmsg), "digits/a-m");
+                              res = wait_file(chan,ints,nextmsg,lang);
+                              break;
+                      case 'I':
+                      case 'l':
+                              /* 12-Hour */
+                              if (tm.tm_hour == 0)
+                                      snprintf(nextmsg,sizeof(nextmsg), "digits/12");
+                              else if (tm.tm_hour > 12)
+                                      snprintf(nextmsg,sizeof(nextmsg), "digits/%d", tm.tm_hour - 12);
+                              else
+                                      snprintf(nextmsg,sizeof(nextmsg), "digits/%d", tm.tm_hour);
+                              res = wait_file(chan,ints,nextmsg,lang);
+                              if(!res) res = wait_file(chan,ints, "hours",lang);
+                              break;
+                      case 'H':
+                      case 'k':
+                              /* 24-Hour */
+                              if (format[offset] == 'H') {
+                                      /* e.g. oh-eight */
+                                      if (tm.tm_hour < 10) {
+                                              res = wait_file(chan,ints, "digits/0",lang);
+                                      }
+                               } else {
+                                      /* e.g. eight */
+                                      if (tm.tm_hour == 0) {
+                                              res = wait_file(chan,ints, "digits/0",lang);
+                                      }
+                              }
+                              if (!res) {
+                                      if (tm.tm_hour != 0) {
+                                              int remainder = tm.tm_hour;
+                                              if (tm.tm_hour > 20) {
+                                                      res = wait_file(chan,ints, "digits/20",lang);
+                                                      remainder -= 20;
+                                              }
+                                              if (!res) {
+                                                      snprintf(nextmsg,sizeof(nextmsg), "digits/%d", remainder);
+                                                      res = wait_file(chan,ints,nextmsg,lang);
+                                              }
+                                      }
+                              }
+                              res = wait_file(chan,ints, "hours",lang);
+                              break;
+                      case 'M':
+                              /* Minute */
+                              if (tm.tm_min < 10) {
+                                      res = wait_file(chan,ints, "digits/0",lang);
+                                      if (!res) {
+                                              snprintf(nextmsg,sizeof(nextmsg), "digits/%d", tm.tm_min);
+                                              res = wait_file(chan,ints,nextmsg,lang);
+                                      }
+                              } else if ((tm.tm_min < 21) || (tm.tm_min % 10 == 0)) {
+                                      snprintf(nextmsg,sizeof(nextmsg), "digits/%d", tm.tm_min);
+                                      res = wait_file(chan,ints,nextmsg,lang);
+                              } else {
+                                      int ten, one;
+                                      ten = (tm.tm_min / 10) * 10;
+                                      one = (tm.tm_min % 10);
+                                      snprintf(nextmsg,sizeof(nextmsg), "digits/%d", ten);
+                                      res = wait_file(chan,ints,nextmsg,lang);
+                                      if (!res) {
+                                              /* Fifty, not fifty-zero */
+                                              if (one != 0) {
+                                                      snprintf(nextmsg,sizeof(nextmsg), "digits/%d", one);
+                                                      res = wait_file(chan,ints,nextmsg,lang);
+                                              }
+                                      }
+                              }
+                              res = wait_file(chan,ints, "minutes",lang);
+                              break;
+                      case 'Q':
+                              /* Shorthand for "Today", "Yesterday", or ABdY */
+                              {
+                                      struct timeval now;
+                                      struct ast_tm tmnow;
+                                      time_t beg_today;
+ 
+                                      gettimeofday(&now,NULL);
+                                      ast_localtime(&now,&tmnow,timezone);
+                                      /* This might be slightly off, if we transcend a leap second, but never more off than 1 second */
+                                      /* In any case, it saves not having to do ast_mktime() */
+                                      beg_today = now.tv_sec - (tmnow.tm_hour * 3600) - (tmnow.tm_min * 60) - (tmnow.tm_sec);
+                                      if (beg_today < time) {
+                                              /* Today */
+                                              res = wait_file(chan,ints, "digits/today",lang);
+                                      } else if (beg_today - 86400 < time) {
+                                              /* Yesterday */
+                                               res = wait_file(chan,ints, "digits/yesterday",lang);
+                                      } else {
+                                               res = ast_say_date_with_format(chan, time, ints, lang, "ABdY", timezone);
+                                      }
+                              }
+                              break;
+                      case 'q':
+                              /* Shorthand for "" (today), "Yesterday", A (weekday), or ABdY */
+                              {
+                                      struct timeval now;
+                                      struct ast_tm tmnow;
+                                      time_t beg_today;
+ 
+                                      gettimeofday(&now,NULL);
+                                      ast_localtime(&now,&tmnow,timezone);
+                                      /* This might be slightly off, if we transcend a leap second, but never more off than 1 second */
+                                      /* In any case, it saves not having to do ast_mktime() */
+                                      beg_today = now.tv_sec - (tmnow.tm_hour * 3600) - (tmnow.tm_min * 60) - (tmnow.tm_sec);
+                                      if (beg_today < time) {
+                                              /* Today */
+                                      } else if ((beg_today - 86400) < time) {
+                                              /* Yesterday */
+                                              res = wait_file(chan,ints, "digits/yesterday",lang);
+                                      } else if (beg_today - 86400 * 6 < time) {
+                                              /* Within the last week */
+                                              res = ast_say_date_with_format(chan, time, ints, lang, "A", timezone);
+                                      } else {
+                                              res = ast_say_date_with_format(chan, time, ints, lang, "ABdY", timezone);
+                                      }
+                              }
+                              break;
+                      case 'R':
+                              res = ast_say_date_with_format(chan, time, ints, lang, "HM", timezone);
+                              break;
+                      case 'S':
+                              /* Seconds */
+                              if (tm.tm_sec == 0) {
+                                      snprintf(nextmsg,sizeof(nextmsg), "digits/%d", tm.tm_sec);
+                                      res = wait_file(chan,ints,nextmsg,lang);
+                              } else if (tm.tm_sec < 10) {
+                                      res = wait_file(chan,ints, "digits/0",lang);
+                                      if (!res) {
+                                              snprintf(nextmsg,sizeof(nextmsg), "digits/%d", tm.tm_sec);
+                                              res = wait_file(chan,ints,nextmsg,lang);
+                                      }
+                              } else if ((tm.tm_sec < 21) || (tm.tm_sec % 10 == 0)) {
+                                      snprintf(nextmsg,sizeof(nextmsg), "digits/%d", tm.tm_sec);
+                                      res = wait_file(chan,ints,nextmsg,lang);
+                              } else {
+                                      int ten, one;
+                                      ten = (tm.tm_sec / 10) * 10;
+                                      one = (tm.tm_sec % 10);
+                                      snprintf(nextmsg,sizeof(nextmsg), "digits/%d", ten);
+                                      res = wait_file(chan,ints,nextmsg,lang);
+                                      if (!res) {
+                                              /* Fifty, not fifty-zero */
+                                              if (one != 0) {
+                                                      snprintf(nextmsg,sizeof(nextmsg), "digits/%d", one);
+                                                      res = wait_file(chan,ints,nextmsg,lang);
+                                              }
+                                      }
+                              }
+                              res = wait_file(chan,ints, "digits/byou",lang);
+                              break;
+                      case 'T':
+                              res = ast_say_date_with_format(chan, time, ints, lang, "HMS", timezone);
+                              break;
+                      case ' ':
+                      case '	':
+                              /* Just ignore spaces and tabs */
+                              break;
+                      default:
+                              /* Unknown character */
+                              ast_log(LOG_WARNING, "Unknown character in datetime format %s: %c at pos %d\n", format, format[offset], offset);
+              }
+              /* Jump out on DTMF */
+              if (res) {
+                      break;
+              }
+      }
+      return res;
+ }
+ 
  /*! \brief Vietnamese syntax */
  int ast_say_date_with_format_vi(struct ast_channel *chan, time_t t, const char *ints, const char *lang, const char *format, const char *tzone)
  {
