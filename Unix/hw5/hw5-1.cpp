#include <stdio.h>
#include <stdlib.h>

int main(){

    char name[5][10] = {"Adam", "Bob", "Charlie", "Duck", "Ellen"};
    
    int score[5][4] = {
        {97, 90, 88, 95},
        {76, 89, 75, 83},
        {60, 70, 88, 82},
        {83, 89, 92, 85},
        {75, 73, 72, 78}
    };

    int sum = 0;
    float aver = 0;

    for(int i = 0; i < 5; i++){
        printf("%s\t", name[i]);
        for(int j = 0; j < 4; j++){
            sum += score[i][j];
        }
        aver = (float)sum / 4.00;
        printf("%d\t%.2lf\n", sum, aver);
        sum =0;
        aver = 0;
    }


    return 0;
}
