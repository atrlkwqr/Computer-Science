#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int input = 0;
    int fn = 0, fn1 = 0, fn2 = 0;

    scanf("%d", &input);
    
    for(int i = 0; i < input + 1; i++){
        if(i == 0) {
            fn2 = 0;
            printf("%d %d\n", i, fn2);
        }
        else if(i == 1) {
            fn1 = 1;
            printf("%d %d\n", i, fn1);
        }
        else{
            fn = fn1 + fn2;
            fn2 = fn1;
            fn1 = fn;
            printf("%d %d\n", i, fn);
        }
    }



    return 0;
}
