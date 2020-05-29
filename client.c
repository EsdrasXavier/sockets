#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
  int socketDesc;
  struct sockaddr_in server;

  // AF_INET - IPv4, SOCK_STREAM - tcp, 0 - IP
  socketDesc = socket(AF_INET, SOCK_STREAM, 0);

  if (socketDesc == -1) {
    printf("Não foi possivel criar o socket.\n");
    return 1;
  }

  server.sin_addr.s_addr = inet_addr("172.217.28.132");
  server.sin_family = AF_INET;
  server.sin_port = htons(80);

  if (connect(socketDesc, (struct sockaddr *)&server, sizeof(server)) == -1) {
    printf("Não foi possivel conectar-se.\n");
    return 1;
  }

  return 0;
}
