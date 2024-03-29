#ifndef ETTERCAP_GTK_H
#define ETTERCAP_GTK_H
#define G_DISABLE_CONST_RETURNS
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

#define LOGO_FILE "ettercap.png"
#define LOGO_FILE_SMALL "ettercap-small.png"
#define ICON_FILE "ettercap.svg"

#ifndef GTK_WRAP_WORD_CHAR
#define GTK_WRAP_WORD_CHAR GTK_WRAP_WORD
#endif

struct gtk_conf_entry {
   char *name;
   short value;
};

struct resolv_object {
   /* Widget type to be updated */
   GType type;
   /* Widget to be updated */
   GtkWidget *widget;
   /* List Stores are not of type GtkWidget */
   GtkListStore *liststore;
   /* some attributes needed to update the widget */
   GtkTreeIter treeiter;
   guint column;
   /* The IP address to resolve */
   struct ip_addr *ip;
};

/* ec_gtk.c */
extern GtkWidget *window;  /* main window */
extern GtkWidget *notebook;
extern GtkWidget *main_menu;
extern GtkUIManager *menu_manager;
extern guint merge_id;
extern GTimer *progress_timer;

extern void set_gtk_interface(void);
extern void gtkui_about(void);
extern void gtkui_message(const char *msg);
extern void gtkui_input(const char *title, char *input, size_t n, void (*callback)(void));
extern void gtkui_exit(void);

extern void gtkui_sniff_offline(void);
extern void gtkui_sniff_live(void);


extern gboolean gtkui_iptoa_deferred(gpointer data);
extern gboolean gtkui_combo_enter(GtkWidget *widget, GdkEventKey *event, gpointer data);
extern void gtkui_dialog_enter(GtkWidget *widget, gpointer data);
extern gboolean gtkui_context_menu(GtkWidget *widget, GdkEventButton *event, gpointer data);
extern void gtkui_filename_browse(GtkWidget *widget, gpointer data);
extern char *gtkui_utf8_validate(char *data);
extern GtkWidget *gtkui_box_new(gint orientation, gint spacing, gboolean homogenious);

/* MDI pages */
extern GtkWidget *gtkui_page_new(char *title, void (*callback)(void), void (*detacher)(GtkWidget *));
extern void gtkui_page_present(GtkWidget *child);
extern void gtkui_page_close(GtkWidget *widget, gpointer data);
extern void gtkui_page_close_current(void);
extern void gtkui_page_detach_current(void);
extern void gtkui_page_attach_shortcut(GtkWidget *win, void (*attacher)(void));
extern void gtkui_page_right(void);
extern void gtkui_page_left(void);

/* ec_gtk_menus.c */
/*
 * 0 for offline menus
 * 1 for live menus
 */
extern void gtkui_create_menu(int live);
extern void gtkui_create_tab_menu(void);

/* ec_gtk_start.c */
extern void gtkui_start_sniffing(void);
extern void gtkui_stop_sniffing(void);

/* ec_gtk_filters.c */
extern void gtkui_load_filter(void);
extern void gtkui_stop_filter(void);

/* ec_gtk_hosts.c */
#ifdef WITH_IPV6
extern void toggle_ip6scan(void);
#endif
extern void gtkui_scan(void);
extern void gtkui_load_hosts(void);
extern void gtkui_save_hosts(void);
extern void gtkui_host_list(void);
extern gboolean gtkui_refresh_host_list(gpointer data);

/* ec_gtk_view.c */
extern void gtkui_show_stats(void);
extern void toggle_resolve(void);
extern void gtkui_vis_method(void);
extern void gtkui_vis_regex(void);
extern void gtkui_wifi_key(void);

/* ec_gtk_targets.c */
extern void toggle_reverse(void);
extern void gtkui_select_protocol(void);
extern void wipe_targets(void);
extern void gtkui_select_targets(void);
extern void gtkui_current_targets(void);
extern void gtkui_create_targets_array(void);

/* ec_gtk_view_profiles.c */
extern void gtkui_show_profiles(void);

/* ec_gtk_mitm.c */
extern void gtkui_arp_poisoning(void);
extern void gtkui_icmp_redir(void);
extern void gtkui_port_stealing(void);
extern void gtkui_dhcp_spoofing(void);
#ifdef WITH_IPV6
extern void gtkui_ndp_poisoning(void);
#endif
extern void gtkui_mitm_stop(void);

/* ec_gtk_redirect.c */
extern void gtkui_sslredir_show(void);

/* ec_gtk_logging.c */
extern void toggle_compress(void);
extern void gtkui_log_all(void);
extern void gtkui_log_info(void);
extern void gtkui_log_msg(void);
extern void gtkui_stop_log(void);
extern void gtkui_stop_msg(void);

/* ec_gtk_plugins.c */
extern void gtkui_plugin_mgmt(void);
extern void gtkui_plugin_load(void);
extern gboolean gtkui_refresh_plugin_list(gpointer data);

/* ec_gtk_view_connections.c */
extern void gtkui_show_connections(void);

/* ec_gtk_conf.c */
extern void gtkui_conf_set(char *name, short value);
extern short gtkui_conf_get(char *name);
extern void gtkui_conf_read(void);
extern void gtkui_conf_save(void);

#ifndef OS_WINDOWS
/* ec_gtk_help.c */
extern void gtkui_help(void);
#endif

#endif

/* EOF */

// vim:ts=3:expandtab

