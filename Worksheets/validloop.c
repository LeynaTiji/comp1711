#include <stdio.h>

int main(){
    int number;
    
    printf("Enter a number between 0 and 100 (-1 to terminate): ");
    scanf("%d", &number);

    while (number != - 1){
        if (number > -1 || number < 101){
             printf("Valid input!\n");
           printf("Enter a number between 0 and 100 (-1 to terminate): ");
    scanf("%d", &number);
    }
    }
    printf("Program has been terminated\n");

    return 0;
}