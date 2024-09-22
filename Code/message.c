#include "message.h"
#include "mode.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

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

// Function to handle client commands
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

        // Convert message to lowercase for case insensitivity
        for (int i = 0; buff[i]; i++) {
            buff[i] = tolower(buff[i]);
        }

        // Command to check current mode (e.g., "status")
        if (strncmp("status", buff, 6) == 0) {
            int current_mode = get_current_mode();
            sprintf(buff, "Current gain mode is %d\n", current_mode);
            write(connfd, buff, sizeof(buff));
        }
        // Command to change mode (e.g., "gain 2")
        else if (strncmp("gain", buff, 4) == 0) {
            int mode = buff[5] - '0';  // Get the mode number from the message
            if (mode >= 1 && mode <= 4) {
                set_mode(mode);
                sprintf(buff, "Switched to gain mode %d\n", mode);
            } else {
                sprintf(buff, "Invalid gain mode. Choose between 1 and 4.\n");
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
