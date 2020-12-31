#include <stdio.h>
#include <stdlib.h>

int main(){

    int n = 0x64636261;

    char *pn = (char*)&n;

    for(int i=0; i<4;i++) {
        printf("%c", *pn++);
    }

    printf("\n");

    char *p = (char*)&n + 1;

    printf("%c\n", *p++);
    printf("%c\n", *++p);
    printf("%c\n", (*p)++);
    printf("%c\n", ++*p);
    printf("%X\n", n);


    return 0;
}
