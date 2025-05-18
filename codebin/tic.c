#include <gtk/gtk.h>
#include <string.h>

static char board[3][3]; // Game board
static char current_player = 'X'; // Start with player 'X'

// Update the button label when clicked
void on_button_clicked(GtkWidget *button, gpointer data) {
    const char *id = (const char *)data;

    // Parse the row and column from button ID
    int row = id[0] - '0';
    int col = id[1] - '0';

    // If the cell is empty, place the current player's symbol
    if (board[row][col] == '\0') {
        board[row][col] = current_player;

        char label[2] = {current_player, '\0'};
        gtk_button_set_label(GTK_BUTTON(button), label);

        // Toggle player
        current_player = (current_player == 'X') ? 'O' : 'X';
    }
}

// Create the main Tic Tac Toe grid
GtkWidget* create_grid(GtkWidget *grid) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            char *id = g_strdup_printf("%d%d", row, col); // Unique ID for each button
            GtkWidget *button = gtk_button_new_with_label(" "); // Empty button

            gtk_grid_attach(GTK_GRID(grid), button, col, row, 1, 1); // Attach to grid
            g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), id); // Handle clicks
        }
    }
    return grid;
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Create the main application window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Tic Tac Toe");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    // Create a 3x3 grid for the board
    GtkWidget *grid = gtk_grid_new();
    create_grid(grid);

    // Add the grid to the window
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Handle window close
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Show the window and grid
    gtk_widget_show_all(window);

    gtk_main();
    return 0;
}
