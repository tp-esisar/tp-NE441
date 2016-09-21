#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	int sock;
	struct sockaddr_in addr;

	if (argc != 4) {
		printf ("Usage : exo.e IP Port Message");
		exit(0);
	}

	//Création de la Socket
	if ((sock = socket (AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("Socket creation error");
		return -1;
	}		

	//Construction du paquet
	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(argv[2]));
	if((inet_pton(AF_INET,argv[1],&addr.sin_addr)) <= 0) {
		perror("Address creation error");
		return -1;
	}
	bzero(addr.sin_zero, 8);

	//Envoi du paquet
	if (sendto(sock, argv[3], strlen(argv[3]), 0, (struct sockaddr *)&addr, sizeof(addr)) != strlen(argv[3])) {
	 	perror("Request error");
	 	return -1;
	}
	
	close(sock);	
	
	printf("Envoie réussi !\n");
	return 0;
}

