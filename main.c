#include "ui/bindings.h"

#ifdef _WIN32
int WinMain(void* hInstance, void* hPrevInstance, char** argv, int nCmdShow)
#else
int main(int argc, char ** argv)
#endif
{
    GtkApplication* app;
    int status;
    app = gtk_application_new("gtk.games", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), 0, argv);
    g_object_unref(app);
    return status;
}
