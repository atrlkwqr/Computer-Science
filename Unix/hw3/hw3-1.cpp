#include <stdio.h>
#include <stdlib.h>

int main(){

    float fiveNum[5] = {98.56, 78.62, 78.69, 89.32, 95.29};

    float sum = 0;
    float avg = 0;

    // 총합
    for (int i = 0; i < 5; i++){
        sum += fiveNum[i];
    }

    // 평균
    avg = sum / 5.000f;

    printf("%.3lf\n", sum);
    printf("%.3lf\n", avg);

    return 0;
}
