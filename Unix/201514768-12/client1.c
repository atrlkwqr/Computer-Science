#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFSIZE 4096
#define SERVERPORT 7799


// recv.txt파일을 w권한으로 만들어 받아온 버퍼만큼 write 수행 
void write_file(int sockfd){
    int n;
    FILE *fp;
    char *filename = "recv1.txt";
    char buffer[BUFFSIZE];

    fp = fopen(filename, "w");
    while (1) {
        n = recv(sockfd, buffer, BUFFSIZE, 0);
        if (n <= 0){
            break;
            return;
        }
        fprintf(fp, "%s", buffer);
        bzero(buffer, BUFFSIZE);
    }
    return;
}

int main(void){
    int c_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t c_addr_size;

    //소켓 생성
    c_sock = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&server_addr, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVERPORT);
    
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    //연결 요청과 실패 시 예외 처리
    if(connect(c_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Can't connect to a Server");
        exit(1);
    }

    printf("Check: c_sock=%d\n", c_sock);
    
    //jump to write_file()
    write_file(c_sock);
    printf("[+]Data written in the file successfully.\n");

    close(c_sock);

    return 0;
}