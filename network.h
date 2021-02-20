#ifndef __WATCHER_NETWORK__
#define __WATCHER_NETWORK__

#include <linux/socket.h>
#include <net/sock.h>

#define DEFAULT_BUFFER_SIZE 1024
#define DEFAULT_PORT 8888

/* Setup needed structures for sending data over a kernel socket. */
void setup_send_buffer(char *send_buffer, struct kvec *send_vec, struct msghdr *send_msg);

/* Connect to a remote server from the kernel. */
int server_connect(struct socket *sock, struct sockaddr_in *s_addr, const char *host, const int port);

/* Send data to a remote server from the kernel. */
int server_send(struct socket *sock, char *send_buffer); 

/* Shutdown and free the connection structure memory. */
void server_free(struct socket *sock);
#endif
