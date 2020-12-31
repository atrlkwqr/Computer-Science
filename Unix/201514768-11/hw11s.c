#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFSIZE 4096
#define SERVERPORT 7799

// file.txt파일을 r권한으로 만들어 정해진 버퍼크기만큼 send 수행 
void send_file(FILE *fp, int sockfd){
  int n;
  char data[BUFFSIZE] = {0};

  while(fgets(data, BUFFSIZE, fp) != NULL) {
    if (send(sockfd, data, sizeof(data), 0) == -1) {
      perror("[-]Error in sending file.");
      exit(1);
    }
    bzero(data, BUFFSIZE);
  }
}


int main(void){
    int s_sock, c_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t c_addr_size;
    FILE *fp;
    char *filename = "file.txt";
    
    //소켓 생성
    s_sock = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&server_addr, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVERPORT);

    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    //소켓 이름 지정
    if(bind(s_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Can't bind a socket");
        exit(1);
    }

    listen(s_sock, 1);

    //연결과 예외 처리
    c_addr_size = sizeof(struct sockaddr);
    c_sock = accept(s_sock, (struct sockaddr *) &client_addr, &c_addr_size);
    if(c_sock == -1) {
         perror("Can't accept a connection");
        exit(1);
    }

    printf("** Check: s_sock=%d c_sock=%d\n", s_sock, c_sock);
    printf("** Check: client IP addr=%s port=%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    //file.txt open 시도
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("[-]Error in reading file.");
        exit(1);
    }
    
    //jump to send_file()
    send_file(fp, c_sock);
    printf("[+]File data sent successfully.\n");

    close(c_sock);
    close(s_sock);

    return 0;
}