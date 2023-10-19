#include <stdio.h>

float fahr_to_kelvin(float temperature);
float fahr_to_cels(float temperature);



int main(){
    int option;
    float temperature;

    printf("Enter the temperature you would like to convert:");
    scanf("%d", &temperature);

    printf("\n");
    printf("Enter 0 to convert to celsius:\n");
    printf("Enter 1 to convert to kelvin:\n");
    printf("Enter 2 to quit:\n");
    scanf("%d", &option);

    switch(option){
    {
        case 0: printf ("%f to celsius is %f\n", temperature, fahr_to_cels(temperature));
        break;

        case 1: printf(" Convert to kelvin\n");
        break;

        case 2: break;

        default: break;
    }
    }
}