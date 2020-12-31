#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_THREADS (10)

pthread_t tid[MAX_THREADS];

#define BUFFSIZE 4096
#define SERVERPORT 7799


// 쓰레드 함수
void *t_function(void *data)
{
    pid_t pid;            // process id
    pthread_t tid;        // thread id
 
    pid = getpid();
    tid = pthread_self();
 
    char* thread_name = (char*)data;
    int i = 0;
 
}


// file.txt파일을 r권한으로 만들어 정해진 버퍼크기만큼 send 수행 
void send_file(FILE *fp, int sockfd){
  int n;
  char data[BUFFSIZE] = {0};


    pthread_t p_thread[MAX_THREADS];
    int thr_id;
    int status;
    char p1[] = "thread_1";
    char p2[] = "thread_2";
    char p3[] = "thread_3";
    char pM[] = "thread_m";
 
    //3초 대기 후 쓰레드 생성
    sleep(3);


    // 1번 쓰레드 생성
    // 쓰레드 생성시 함수는 t_function
    // t_function 의 매개변수로 p1 을 넘긴다. 
    thr_id = pthread_create(&p_thread[0], NULL, t_function, (void *)p1);
    // 2번 쓰레드 생성
    thr_id = pthread_create(&p_thread[1], NULL, t_function, (void *)p2);
    // 3번 쓰레드 생성
    thr_id = pthread_create(&p_thread[2], NULL, t_function, (void *)p3);
    // main() 함수에서도 쓰레드에서 돌아가고 있는 동일한 함수 실행
    t_function((void *)pM);


    while(fgets(data, BUFFSIZE, fp) != NULL) {
        if (send(sockfd, data, sizeof(data), 0) == -1) {
            perror("[-]Error in sending file.");
            exit(1);
        }
        bzero(data, BUFFSIZE);
    }

      // 쓰레드 종료를 기다린다.
    for(int i = 0; i < 10; i++){
      pthread_join(p_thread[i], (void **)&status);
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