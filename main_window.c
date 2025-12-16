```c
#include "main_window.h"
#include "../common/log.h"
#include "../recovery/scanner.h"
#include "../recovery/recover.h"

static void on_scan_clicked(GtkButton* button, gpointer user_data) {
    (void)button; (void)user_data;
    log_info("Scan started");
    scan_result_t result = scan_drive("/"); // placeholder path
    log_info("Scan completed: found %d items", result.count);
    // TODO: populate UI list with result.items
}

static void on_recover_clicked(GtkButton* button, gpointer user_data) {
    (void)button; (void)user_data;
    log_info("Recovery started");
    int ok = recover_file("/tmp/example.deleted", "/tmp/recovered.bin");
    log_info("Recovery %s", ok ? "succeeded" : "failed");
}

GtkWidget* create_main_window(void) {
    GtkWidget* window = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(window), "Data Recovery Tool");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

    GtkWidget* header = gtk_header_bar_new();
    gtk_header_bar_set_title(GTK_HEADER_BAR(header), "Data Recovery");
    gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(header), TRUE);
    gtk_window_set_titlebar(GTK_WINDOW(window), header);

    GtkWidget* box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 8);
    gtk_widget_set_margin_top(box, 12);
    gtk_widget_set_margin_bottom(box, 12);
    gtk_widget_set_margin_start(box, 12);
    gtk_widget_set_margin_end(box, 12);
    gtk_window_set_child(GTK_WINDOW(window), box);

    GtkWidget* btn_scan = gtk_button_new_with_label("Scan Drive");
    g_signal_connect(btn_scan, "clicked", G_CALLBACK(on_scan_clicked), NULL);

    GtkWidget* btn_recover = gtk_button_new_with_label("Recover Selected");
    g_signal_connect(btn_recover, "clicked", G_CALLBACK(on_recover_clicked), NULL);

    GtkWidget* list = gtk_list_view_new(NULL); // TODO: set model later

    gtk_box_append(GTK_BOX(box), btn_scan);
    gtk_box_append(GTK_BOX(box), btn_recover);
    gtk_box_append(GTK_BOX(box), list);

    return window;
}
```
