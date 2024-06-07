#include "bindings.h"

static void onLogsButtonClicked(GtkWidget* widget, gpointer window){
    showTable(widget, window);
}

static void onLoginButtonClicked(GtkWidget* widget, gpointer window){
    if (storeEvent("Authorization")){
        showDialog(widget, window, "Authorization successful!", false);
    }
    else{
        showDialog(widget, window, "Authorization was failed!", true);
    }
}

void activate(GtkApplication* app, gpointer user_data){
    GtkWidget* window, *login_button, *logs_button, *button_box;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Sudoku");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);
    gtk_window_set_icon_name(GTK_WINDOW(window), "computer");

    button_box = gtk_button_box_new(GTK_ORIENTATION_VERTICAL);
    gtk_container_add(GTK_CONTAINER(window), button_box);

    login_button = gtk_button_new_with_label("Login");
    g_signal_connect(login_button, "clicked", G_CALLBACK(onLoginButtonClicked), NULL);
    gtk_container_add(GTK_CONTAINER(button_box), login_button);

    logs_button = gtk_button_new_with_label("Logs");
    g_signal_connect(logs_button, "clicked", G_CALLBACK(onLogsButtonClicked), NULL);
    gtk_container_add(GTK_CONTAINER(button_box), logs_button);

    gtk_widget_show_all(window);
}
