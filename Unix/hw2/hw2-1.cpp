#include <stdio.h>
#include <stdlib.h>

int main(){
    char character;
    float temp = 0.0;

    scanf("%c %f", &character, &temp);
    
    if (character == 'F' || character == 'f') {
        // 화씨 -> 섭씨
        float res = (temp - 32) * (5.0 / 9.0);
        printf("F:%.0f C:%.2f\n", res, temp);
    }
    else if (character == 'C' || character == 'c') {
        // 섭씨 -> 화씨
        float res = 32 + temp * (9.0 / 5.0);
        printf("C:%.0f F:%.2f\n", temp, res);
    }

    else {
        printf("Invalid command\n");
    }

    return 0;
}
