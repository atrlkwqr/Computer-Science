#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 0;
    scanf("%d", &n);
    
    if(1<=n && n<=20) {
        
        for (int i = n; i >= 0; i--){
            
            for (int j = 0; j < i; j++){
                printf("-");
            }
            
            printf("+");
            
            for (int k = 0; k < (n - i) * 2; k++) {
                printf("-");
            }

            printf("+\n");
        }

        for (int i = 1; i < n; i++){

            for(int j = 0; j < i; j++){
                printf("-");
            }

            printf("+");

            for(int k = 0; k < (n - i) * 2; k++){
                printf("-");
            }

            printf("+\n");
        }

        for(int b = 0; b < n; b++){
            printf("-");
        }

        printf("++\n");

    }
    else {
        return 0;
    }
}
