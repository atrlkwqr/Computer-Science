#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int square(int square_input){
    int square_result = pow(square_input, 2);
    return square_result;
}

int cube(int cube_input){
    int cube_result = pow(cube_input, 3);
    return cube_result;
}


int main(){
    
    int input = 0;

    scanf("%d", &input);
    int result = square(input) * cube(input);
    
    printf("%d %d\n", input, result);
    
    return 0;
}
