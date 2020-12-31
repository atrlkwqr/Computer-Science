#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int num[1000] = {0, };
    int maxFind[10] = {0, };

    for(int i = 0; i < 1000; i++){
        scanf("%d", &num[i]);
        if(num[i] == 0) maxFind[0]++;
        if(num[i] == 1) maxFind[1]++;
        if(num[i] == 2) maxFind[2]++;
        if(num[i] == 3) maxFind[3]++;
        if(num[i] == 4) maxFind[4]++;
        if(num[i] == 5) maxFind[5]++;
        if(num[i] == 6) maxFind[6]++;
        if(num[i] == 7) maxFind[7]++;
        if(num[i] == 8) maxFind[8]++;
        if(num[i] == 9) maxFind[9]++;
    }

    printf("0: %5d\n", maxFind[0]);
    printf("1: %5d\n", maxFind[1]);
    printf("2: %5d\n", maxFind[2]);
    printf("3: %5d\n", maxFind[3]);
    printf("4: %5d\n", maxFind[4]);
    printf("5: %5d\n", maxFind[5]);
    printf("6: %5d\n", maxFind[6]);
    printf("7: %5d\n", maxFind[7]);
    printf("8: %5d\n", maxFind[8]);
    printf("9: %5d\n", maxFind[9]);
    
    int max = 0;
    int maxNum = 0;

    max = maxFind[0];
    
    for (int i = 0; i < 10; i++) {
        if (maxFind[i] > max) {
            max = maxFind[i];
            maxNum = i;
        }
    }

    printf("%d\n", maxNum);
    printf("%d\n", max); 

    return 0;
}
