#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    const char *str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\0";

    char input;
    int j = 0;
    char end = '0';

    scanf("%c", &input);
    
    if(input >= 97 && input <= 122) input -= 32;
    else if(input >= 65 && input <= 90) {}
    else return 1;

    while (1)
    {
        j++;

        if(str[j] == input) {
            
            for(int i = j; i >= 0; i--){
                printf("%c", str[i]);
            }
            

            for(int i = j + 1; i; i++){
                if((char)str[i] == end) {
                    printf("\n");
                    break;
                }
                else {
                    printf("%c", str[i]);
                }
            }

            break;
        }
    }
    
    return 0;
}
