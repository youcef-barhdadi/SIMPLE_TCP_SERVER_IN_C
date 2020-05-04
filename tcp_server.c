
#include "sock.h"


int main(int argc, char **argv)
{
	int listenfd, confd, n;
	struct sockaddr_in servaddr;
	uint8_t buff[MAXLINE +1];
	uint8_t recvline[MAXLINE +1];
	// socket function take 3 arr and return file descriptor
	// first is dommine AF_INT == intern
	// SOCK_STREAM is TCP 
	// 0 is IP protocl

	if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("NIKE MOK");
		return 1;
	}

	bzero(&servaddr, sizeof(servaddr));
	// fill sockadrr_in  struct with info
	servaddr.sin_family = AF_INET; // internt address 
	servaddr.sin_addr.s_addr =  htonl(INADDR_ANY); // any addres on the host like 0.0.0.0
	servaddr.sin_port = htons(SERVER_PORT); //set the port  we use htons fot the BIG ENDING

	// bind the addres with the socket 
	if ((bind(listenfd, (SA *)&servaddr, sizeof(servaddr))) < 0)
	{
		perror("NIKE MOK");
		return  1;
	}

	// tell the kernal  to start listen on the sockt (addres + porst) , for any comming requist
	// 10 means that the kernal can waits for 10 requist at the time if 11 requist come the connection will refuse
	if ((listen(listenfd, 10)) < 0)
	{
		perror("NIKE MOK");
		return 1;
	}
	while (1)
	{
		struct sockaddr_in addr;
		socklen_t addr_len;

		printf("waiting for a cooniction on port %d\n", SERVER_PORT);
		fflush(stdout);
		// accept blocks unitil an incoming connection arrives
		// it returns a file descriptor to the connection
		confd = accept(listenfd, (SA*)NULL, NULL);

	
		memset(recvline, 0, MAXLINE);

		n = read(confd, recvline, MAXLINE -1 );
		if (n < 0)
		{
			printf("error\n");
			perror(" == >");
			return 1;
		}
		recvline[n] = 0;

		printf("%s\n", recvline);

		close(confd);
	}


		close(listenfd);




	return 0;
}
