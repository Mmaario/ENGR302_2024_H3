#ifndef SOCKET_H
#define SOCKET_H

int create_socket();
int accept_connection(int sockfd);
void close_socket(int sockfd);

#endif