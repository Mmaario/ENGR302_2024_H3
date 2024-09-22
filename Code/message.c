#include "message.h"
#include "mode.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX 80

// Function to read and send a file's contents to the client
void send_file_contents(int connfd, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        char error_message[] = "Error: Could not open file\n";
        write(connfd, error_message, sizeof(error_message));
        return;
    }

    char line[MAX];
    while (fgets(line, sizeof(line), file) != NULL) {
        write(connfd, line, strlen(line));
    }

    fclose(file);
}

void handle_client(int connfd) {
    char buff[MAX];

    // On connection, send the welcome file
    send_file_contents(connfd, "welcome.txt");

    // Infinite loop for chat
    for (;;) {
        bzero(buff, MAX);

        // Read message from client
        read(connfd, buff, sizeof(buff));
        printf("From client: %s\n", buff);

        // Command to query current mode
        if (strncmp("get_mode", buff, 8) == 0) {
            int current_mode = get_current_mode();
            sprintf(buff, "Current mode is %d\n", current_mode);
            write(connfd, buff, sizeof(buff));
        }
        // Command to switch mode (e.g., "set_mode 3")
        else if (strncmp("set_mode", buff, 8) == 0) {
            int mode = buff[9] - '0';  // Get the mode number from the message
            if (mode >= 0 && mode < 6) {
                set_mode(mode);
                sprintf(buff, "Switched to mode %d\n", mode);
            } else {
                sprintf(buff, "Invalid mode. Choose between 0 and 5.\n");
            }
            write(connfd, buff, sizeof(buff));
        }
        // Command to show help (e.g., "help")
        else if (strncmp("help", buff, 4) == 0) {
            send_file_contents(connfd, "help.txt");
        }
        // Exit the server
        else if (strncmp("exit", buff, 4) == 0) {
            printf("Server Exit...\n");
            break;
        }
        else {
            sprintf(buff, "Unknown command\n");
            write(connfd, buff, sizeof(buff));
        }
    }

    close(connfd);  // Close the connection
}
