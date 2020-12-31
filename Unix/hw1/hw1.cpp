#include <stdio.h>
#include <stdlib.h>

int main(){
    int N = 0;
    scanf("%d", &N);
    
    if(N < -999 || N > 999) {
        printf("ERROR\n");
        return -1;
        }
    else {
        if(N > 0) {
            for(int i = 0; i < 100; i++){
                printf("%d\n", N+i);
            }
        }
    
        if(N < 0) {
            for(int i = 0; i < 100; i++){
                printf("%d\n", N-i);
            }
        }
        return 0;
    }
}
