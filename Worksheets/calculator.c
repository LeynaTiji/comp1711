#include <stdio.h>

float arithmetic(float num1, float num2, char operation){

    float answer;

    if (operation == '+'){
        answer = num1 + num2;
        return answer;
    } else if (operation == '-'){
        answer = num1 - num2;
        return answer;
    } else if (operation == '*'){
        answer = num1 * num2;
        return answer;
    } else {
        answer = num1 / num2;
        return answer;
    }
}

int main(){

    float num1, num2;
    int option;
    char operation;

    printf("Enter a number \n");
    scanf("%f", &num1);

    printf("Enter another number \n");
    scanf("%f", &num2);

    printf("\n");
    printf("Enter 1 to add your numbers:\n");
    printf("Enter 2 to subtract your numbers:\n");
    printf("Enter 3 to multiply your numbers:\n");
    printf("Enter 4 to divide your numbers:\n");
    printf("Enter 5 to quit:\n");
    scanf("%d", &option);

    if (option == 1){
        operation = '+';
    } else if (option == 2){
        operation = '-';
    } else if (option == 3){
        operation = '*';
    } else if (option == 4){
        operation = '/';
    }

    switch(option){
    {
        case 1: printf ("%.2f + %.2f = %.2f\n", num1, num2, arithmetic(num1, num2, operation));
        break;

        case 2: printf ("%.2f - %.2f = %.2f\n", num1, num2, arithmetic(num1, num2, operation));
        break;

        case 3: printf ("%.2f * %.2f = %.2f\n", num1, num2, arithmetic(num1, num2, operation));
        break;

        case 4: printf ("%.2f / %.2f = %.2f\n", num1, num2, arithmetic(num1, num2, operation));
        break;

        case 5: break;

        default: break;
    }
    }
}
