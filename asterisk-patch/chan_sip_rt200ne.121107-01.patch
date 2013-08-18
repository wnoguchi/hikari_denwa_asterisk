*** channels/chan_sip.c.org	2012-11-06 01:29:46.000000000 +0900
--- channels/chan_sip.c	2012-11-07 01:17:43.349619018 +0900
***************
*** 813,818 ****
--- 813,822 ----
   */
  static int can_parse_xml;
  
+ /* RT-200NE HACK */
+ static char global_rt200ne[MAX_RT200NE][20];
+ static int  global_rt200ne_cnt = 0;
+ 
  /*! \name Object counters @{
   *  \bug These counters are not handled in a thread-safe way ast_atomic_fetchadd_int()
   *  should be used to modify these values. */
***************
*** 1480,1485 ****
--- 1484,1490 ----
  static char *sip_unregister(struct ast_cli_entry *e, int cmd, struct ast_cli_args *a);
  static char *sip_show_settings(struct ast_cli_entry *e, int cmd, struct ast_cli_args *a);
  static char *sip_show_mwi(struct ast_cli_entry *e, int cmd, struct ast_cli_args *a);
+ static char *sip_show_rt200ne(struct ast_cli_entry *e, int cmd, struct ast_cli_args *a);
  static const char *subscription_type2str(enum subscriptiontype subtype) attribute_pure;
  static const struct cfsubscription_types *find_subscription_type(enum subscriptiontype subtype);
  static char *complete_sip_peer(const char *word, int state, int flags2);
***************
*** 18133,18138 ****
--- 18138,18172 ----
  #undef FORMAT2
  }
  
+ /*! \brief Show registered RT-200NEs */
+ static char *sip_show_rt200ne(struct ast_cli_entry *e, int cmd, struct ast_cli_args *a)
+ {
+       int     tmp_i;
+ 
+       switch (cmd) {
+          case CLI_INIT:
+                  e->command = "sip show rt200ne";
+                  e->usage =
+                          "Usage: sip show rt200ne\n"
+                          "       List RT-200NE(s) settings.\n";
+                  return NULL;
+          case CLI_GENERATE:
+                  return NULL;
+          }
+ 
+        if (a->argc != 3)
+                return CLI_SHOWUSAGE;
+        if (global_rt200ne_cnt == 0){
+                ast_cli(a->fd,"No RT-200NE(s)\n");
+        } else {
+                ast_cli(a->fd,"RT-200NE at ..\n");
+                for (tmp_i=0;tmp_i<global_rt200ne_cnt;tmp_i++){
+                        ast_cli(a->fd, "- %-16.16s\n", global_rt200ne[tmp_i]);
+                }
+        }
+ 
+        return CLI_SUCCESS;
+ }
  
  /*! \brief Convert transfer mode to text string */
  static char *transfermode2str(enum transfermodes mode)
***************
*** 21228,21233 ****
--- 21262,21272 ----
  	struct sip_auth *auth;	/* Realm authentication credential */
  	struct sip_auth_container *credentials;
  
+ 	/* RT-200NE HACK */
+ 	char tmp_addr[20];
+ 	char tmp_uri[256];
+ 	int tmp_i;
+ 
  	if (!ast_strlen_zero(p->domain))
  		snprintf(uri, sizeof(uri), "%s:%s", p->socket.type == SIP_TRANSPORT_TLS ? "sips" : "sip", p->domain);
  	else if (!ast_strlen_zero(p->uri))
***************
*** 21235,21240 ****
--- 21274,21301 ----
  	else
  		snprintf(uri, sizeof(uri), "%s:%s@%s", p->socket.type == SIP_TRANSPORT_TLS ? "sips" : "sip", p->username, ast_sockaddr_stringify_host_remote(&p->sa));
  
+ 	/* RT-200NE HACK */
+ 	strcpy(tmp_addr, ast_sockaddr_stringify_host(&p->sa));
+ 	/* ast_verbose(VERBOSE_PREFIX_3 "inet is  %s \n", tmp_addr); */
+ 	for (tmp_i=0;tmp_i<global_rt200ne_cnt;tmp_i++){
+ 		if(strcmp(tmp_addr, global_rt200ne[tmp_i]) == 0){
+ 			/* ast_verbose(VERBOSE_PREFIX_3 "Peer is RT-200NE\n"); */
+ 			if ((strcmp(uri, "domain") == 0) || (strcmp(uri, "sip:domain") == 0)) {
+ 				strncpy(tmp_uri, p->uri, sizeof(tmp_uri));
+ 				switch (method) {
+ 				case    SIP_REGISTER:
+ 					sprintf(uri, "sip:%s",tmp_addr);
+ 					break;
+ 				default:
+ 					*strchr(tmp_uri, '@') = '\0';
+ 					snprintf(uri, sizeof(uri), "%s@%s",tmp_uri,tmp_addr);
+ 					break;
+ 				}
+ 			}
+ 		}
+ 	}
+ 	/* RT-200NE HACK END */
+ 
  	snprintf(cnonce, sizeof(cnonce), "%08lx", ast_random());
  
  	/* Check if we have peer credentials */
***************
*** 30817,30822 ****
--- 30878,30887 ----
  
  	sip_cfg.matchexternaddrlocally = DEFAULT_MATCHEXTERNADDRLOCALLY;
  
+ 	/* RT-200NE HACK */
+ 	memset(global_rt200ne, 0, sizeof(global_rt200ne));
+ 	global_rt200ne_cnt = 0;
+ 
  	/* Copy the default jb config over global_jbconf */
  	memcpy(&global_jbconf, &default_jbconf, sizeof(struct ast_jb_conf));
  
***************
*** 31287,31292 ****
--- 31352,31362 ----
  			}
  		} else if (!strcasecmp(v->name, "matchexternaddrlocally") || !strcasecmp(v->name, "matchexterniplocally")) {
  			sip_cfg.matchexternaddrlocally = ast_true(v->value);
+ 		} else if (!strcasecmp(v->name, "rt200ne")) { /*RT-200NE HACK*/
+ 			if (global_rt200ne_cnt < MAX_RT200NE) {
+ 				ast_copy_string(global_rt200ne[global_rt200ne_cnt], v->value, sizeof(global_rt200ne));
+ 			global_rt200ne_cnt++;
+ 			}
  		} else if (!strcasecmp(v->name, "session-timers")) {
  			int i = (int) str2stmode(v->value);
  			if (i < 0) {
***************
*** 32754,32759 ****
--- 32824,32830 ----
  	AST_CLI_DEFINE(sip_show_registry, "List SIP registration status"),
  	AST_CLI_DEFINE(sip_unregister, "Unregister (force expiration) a SIP peer from the registry"),
  	AST_CLI_DEFINE(sip_show_settings, "Show SIP global settings"),
+ 	AST_CLI_DEFINE(sip_show_rt200ne, "Show RT-200NE settings"),
  	AST_CLI_DEFINE(sip_show_mwi, "Show MWI subscriptions"),
  	AST_CLI_DEFINE(sip_cli_notify, "Send a notify packet to a SIP peer"),
  	AST_CLI_DEFINE(sip_show_channel, "Show detailed SIP channel info"),
*** channels/sip/include/sip.h.org	2012-09-26 03:52:12.000000000 +0900
--- channels/sip/include/sip.h	2012-11-07 01:19:21.522326743 +0900
***************
*** 106,111 ****
--- 106,114 ----
  
  #define INITIAL_CSEQ              101    /*!< Our initial sip sequence number */
  
+ /* RT-200NE HACK */
+ #define MAX_RT200NE                   4       /* Number of RT-200NEs */
+ 
  #define DEFAULT_MAX_SE            1800   /*!< Session-Timer Default Session-Expires period (RFC 4028) */
  #define DEFAULT_MIN_SE            90     /*!< Session-Timer Default Min-SE period (RFC 4028) */
  
