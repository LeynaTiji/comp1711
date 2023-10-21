#include <stdio.h>

int main(){
    char string[] = "hello";
    int a;

    for (a = 5; a> -1; a--)
    {
    if (string[a] == '\0') {
        printf("\\0 \n");
    } else {
    printf("%c\n", string[a]);
    }
    }
    return 0;
}