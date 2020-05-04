#ifndef _SOCK_
#define _SOCK_
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <signal.h>
# include <fcntl.h>

#define SERVER_PORT 1337
#define MAXLINE 4096
#define SA struct sockaddr
#define MAX_CLINETS 100
#define BUFFER_SIZE 2048


# endif
