#include <stdio.h>

int main(){

    int num1, num2, num3;

    printf("Enter a number ");
    scanf("%d", &num1);

    printf("Enter another number ");
    scanf("%d", &num2);

    num3 = num1 + num2;
    printf("The sum of %d and %d is %d\n", num1, num2, num3);

    return 0;
}