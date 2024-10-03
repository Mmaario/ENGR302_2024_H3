#include "socket.h"
#include "message.h"
#include "mode.h"
#include <unistd.h>
#include <stdio.h>

int main() {
    int GPIO_PINS [6] = {34,38,34,35,65};
    // Initialize GPIO pins (0-5 for each mode)
    //export_gpio(GPIO_PINS);
    usleep(10000);
    for (int i = 0; i < 6; i++) {
        set_gpio_direction(GPIO_PINS[i], "out");
        set_gpio_value(GPIO_PINS[i], 0);  // Start with all modes off
    }

    int sockfd = create_socket();
    int connfd = accept_connection(sockfd);

    // Handle client commands
    handle_client(connfd);

    // Close the socket after chatting
    close_socket(sockfd);
    return 0;
}