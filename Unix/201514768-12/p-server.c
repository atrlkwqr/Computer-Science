#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFSIZE 4096
#define SERVERPORT 7799

int main(void){
    int i, s_sock, c_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t c_addr_size;
    char buf[BUFFSIZE] = {0};
    char hello[] = "Hello~I am Server!\n";
    
    //소켓 생성
    s_sock = socket(AF_INET, SOCK_STREAM, 0);

    int option = 1;
    setsockopt(s_sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

    bzero(&server_addr, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVERPORT);

    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    //소켓 이름 지정
    if(bind(s_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("[S]Can't bind a socket");
        exit(1);
    }

    listen(s_sock, 1);

    //연결과 예외 처리
    c_addr_size = sizeof(struct sockaddr);

    for(i = 0; i < 3; i++) {
      printf("[S] waiting for a client..#%02d\n", i);
      c_sock = accept(s_sock, (struct sockaddr *) &client_addr, &c_addr_size);
      if(c_sock == -1) {
          perror("[S] Can't accept a connection");
          exit(1);
      }

      printf("[S] Connected: client IP addr=%s port=%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

      if(send(c_sock, hello, sizeof(hello)+1, 0) == -1) {
          perror("[S] Can't send message");
          exit(1);
      }

      printf("[S] I said Hello to Client!\n");

      if (recv(c_sock, buf, BUFFSIZE, 0) == -1) {
          perror("[S] Can't receive message");
          exit(1);
      }
    
      printf("[S] Client says: %s\n", buf);
      
      close(c_sock);
    }
    
    close(s_sock);

    return 0;
}