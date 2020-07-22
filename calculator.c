#include <gtk/gtk.h>
#include <string.h>
#include <stdbool.h>
#include "C:/Users/user/Desktop/Bittu/workspace/lib/calculate.h"

#include <windows.h>

char item[100] = "";
int result = 0;

void print2(GtkWidget *widget, gpointer text)
{
    strcat(item, text);
};

void print(GtkWidget *widget, gpointer entry)
{
    gtk_entry_set_text(GTK_ENTRY(entry), item);
};

void delete(GtkWidget *widget, gpointer entry)
{
    strcpy(item, "");
    gtk_entry_set_text(GTK_ENTRY(entry), item);
};
void clear(GtkWidget *widget, gpointer entry){
    item[strlen(item)-1] = '\0';
    gtk_entry_set_text(GTK_ENTRY(entry), item);
};
void eval(GtkWidget *widget, gpointer entry)
{
    result = calculate(item);
    sprintf(item, "%d", result);
    gtk_entry_set_text(GTK_ENTRY(entry), item);
};

int main(int argc, char *argv[])
{
    HWND var = GetConsoleWindow();
    ShowWindow(var, SW_HIDE);
    gtk_init(&argc, &argv);
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *entry;
    GtkWidget *layout;
    GtkWidget *grid;
    GtkWidget *image;
    GdkPixbuf *icon;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Calculator");
    gtk_window_set_default_size(GTK_WINDOW(window), 285, 380);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    gtk_window_set_icon_from_file(GTK_WINDOW(window), "./Calculator-icon.ico", NULL);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    layout = gtk_layout_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(window), layout);

    entry = gtk_entry_new();
    gtk_widget_set_size_request(entry, 260, 40);
    gtk_layout_put(GTK_LAYOUT(layout), entry, 10, 10);

    grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 15);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 20);
    gtk_layout_put(GTK_LAYOUT(layout), grid, 10, 60);

    image = gtk_image_new_from_icon_name("edit-delete", 5);
    button = gtk_button_new();
    gtk_button_set_image(GTK_BUTTON(button), image);
    gtk_widget_set_size_request(button, 55, 50);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 0, 1, 1);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(delete), entry);

    button = gtk_button_new_with_label("(");
    gtk_grid_attach(GTK_GRID(grid), button, 1, 0, 1, 1);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print2), "(");
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print), entry);

    button = gtk_button_new_with_label(")");
    gtk_grid_attach(GTK_GRID(grid), button, 2, 0, 1, 1);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print2), ")");
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print), entry);

    image = gtk_image_new_from_icon_name("edit-clear", 5);
    button = gtk_button_new();
    gtk_button_set_image(GTK_BUTTON(button), image);
    gtk_grid_attach(GTK_GRID(grid), button, 3, 0, 1, 1);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(clear), entry);
    ////////////////////
    button = gtk_button_new_with_label("1");
    gtk_widget_set_size_request(button, 55, 50);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 1, 1);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print2), "1");
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print), entry);

    button = gtk_button_new_with_label("2");
    gtk_grid_attach(GTK_GRID(grid), button, 1, 1, 1, 1);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print2), "2");
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print), entry);

    button = gtk_button_new_with_label("3");
    gtk_grid_attach(GTK_GRID(grid), button, 2, 1, 1, 1);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print2), "3");
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print), entry);

    button = gtk_button_new_with_label("+");
    gtk_grid_attach(GTK_GRID(grid), button, 3, 1, 1, 1);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print2), "+");
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print), entry);
    ////////////////////////
    button = gtk_button_new_with_label("4");
    gtk_widget_set_size_request(button, 55, 50);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 2, 1, 1);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print2), "4");
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print), entry);

    button = gtk_button_new_with_label("5");
    gtk_grid_attach(GTK_GRID(grid), button, 1, 2, 1, 1);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print2), "5");
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print), entry);

    button = gtk_button_new_with_label("6");
    gtk_grid_attach(GTK_GRID(grid), button, 2, 2, 1, 1);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print2), "6");
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print), entry);

    button = gtk_button_new_with_label("-");
    gtk_grid_attach(GTK_GRID(grid), button, 3, 2, 1, 1);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print2), "-");
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print), entry);
    /////////////////////
    button = gtk_button_new_with_label("7");
    gtk_widget_set_size_request(button, 55, 50);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 3, 1, 1);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print2), "7");
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print), entry);

    button = gtk_button_new_with_label("8");
    gtk_grid_attach(GTK_GRID(grid), button, 1, 3, 1, 1);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print2), "8");
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print), entry);

    button = gtk_button_new_with_label("9");
    gtk_grid_attach(GTK_GRID(grid), button, 2, 3, 1, 1);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print2), "9");
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print), entry);

    button = gtk_button_new_with_label("x");
    gtk_grid_attach(GTK_GRID(grid), button, 3, 3, 1, 1);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print2), "*");
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print), entry);
    //////////////
    button = gtk_button_new_with_label("/");
    gtk_widget_set_size_request(button, 55, 50);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 4, 1, 1);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print2), "/");
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print), entry);

    button = gtk_button_new_with_label("0");
    gtk_grid_attach(GTK_GRID(grid), button, 1, 4, 1, 1);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print2), "0");
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print), entry);

    button = gtk_button_new_with_label("^");
    gtk_grid_attach(GTK_GRID(grid), button, 2, 4, 1, 1);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print2), "^");
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(print), entry);

    button = gtk_button_new_with_label("=");
    gtk_grid_attach(GTK_GRID(grid), button, 3, 4, 1, 1);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(eval), entry);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
};