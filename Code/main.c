#include "socket.h"
#include "message.h"
#include "mode.h"

int main() {
    // Initialize GPIO pins (0-5 for each mode)
    for (int i = 0; i < 6; i++) {
        export_gpio(i);
        set_gpio_direction(i, "out");
        set_gpio_value(i, 0);  // Start with all modes off
    }

    int sockfd = create_socket();
    int connfd = accept_connection(sockfd);

    // Handle client commands
    handle_client(connfd);

    // Close the socket after chatting
    close_socket(sockfd);
    return 0;
}