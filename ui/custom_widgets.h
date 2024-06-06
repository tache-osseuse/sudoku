#ifndef CUSTOM_WIDGETS_H_INCLUDED
#define CUSTOM_WIDGETS_H_INCLUDED

#include <stdbool.h>

#include "bindings.h"

void showDialog(GtkWidget* widget, gpointer window, const char* text, bool error_flag);
void showTicTac(GtkWidget* widget, gpointer window);
void showTable(GtkWidget* widget, gpointer window);

#endif // CUSTOM_WIDGETS_H_INCLUDED
