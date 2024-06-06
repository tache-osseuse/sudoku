#include "custom_widgets.h"

void showDialog(GtkWidget* widget, gpointer window, const char* text, bool error_flag){
    GtkWidget* dialog;
    GtkMessageType message_type = error_flag ? GTK_MESSAGE_ERROR : GTK_MESSAGE_INFO;
    const char* icon_name = error_flag ? "dialog-error" : "dialog-information";
    const char* header = error_flag ? "Error!" : "Success!";
    dialog = gtk_message_dialog_new(GTK_WINDOW(window),
                                    GTK_DIALOG_DESTROY_WITH_PARENT,
                                    message_type,
                                    GTK_BUTTONS_OK,
                                    text);
    gtk_window_set_title(GTK_WINDOW(dialog), header);
    gtk_window_set_icon_name(GTK_WINDOW(dialog), icon_name);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

void showTicTac(GtkWidget* widget, gpointer window){
    GtkWidget* table_window;
    table_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(table_window), 400, 400);
    gtk_window_set_title(GTK_WINDOW(table_window), "game session");
    gtk_window_set_icon_name(GTK_WINDOW(table_window), "document-properties");
    gtk_window_set_transient_for(GTK_WINDOW(table_window), GTK_WINDOW(window));
    gtk_window_set_modal(GTK_WINDOW(table_window), TRUE);

    GtkWidget *table = gtk_table_new(9, 9, TRUE);
    gtk_container_add(GTK_CONTAINER(table_window), table);
    for (int i = 0; i < 9; i++) { // rows
        for (int j = 0; j < 9; j++) { // columns
            char label_text[20];
            snprintf(label_text, sizeof(label_text), "%d,%d", i + 1, j + 1);
            GtkWidget *label = gtk_label_new(label_text);
            gtk_table_attach(GTK_TABLE(table), label, j, j + 1, i, i + 1,
                             GTK_EXPAND | GTK_FILL, GTK_EXPAND | GTK_FILL, 0, 0);
        }
    }
    gtk_widget_show_all(table_window);
}

void showTable(GtkWidget* widget, gpointer window){
    GtkWidget* table_window, *scrolled_table;
    table_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(table_window), 400, 400);
    gtk_window_set_title(GTK_WINDOW(table_window), "logs");
    gtk_window_set_icon_name(GTK_WINDOW(table_window), "document-properties");
    gtk_window_set_transient_for(GTK_WINDOW(table_window), GTK_WINDOW(window));
    gtk_window_set_modal(GTK_WINDOW(table_window), TRUE);

    scrolled_table = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_table), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_container_add(GTK_CONTAINER(table_window), scrolled_table);

    GtkWidget *table = gtk_table_new(100, 3, FALSE);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrolled_table), table);
    for (int i = 0; i < 100; i++) { // rows
        for (int j = 0; j < 3; j++) { // columns
            char label_text[20];
            snprintf(label_text, sizeof(label_text), "%d,%d", i + 1, j + 1);
            GtkWidget *label = gtk_label_new(label_text);
            gtk_table_attach(GTK_TABLE(table), label, j, j + 1, i, i + 1,
                             GTK_EXPAND | GTK_FILL, GTK_EXPAND | GTK_FILL, 0, 0);
        }
    }
    gtk_widget_show_all(table_window);
}
