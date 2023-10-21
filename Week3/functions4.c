#include <stdio.h>

float fahr_to_kelvin(float temperature);
float fahr_to_cels(float temperature);

int main(){
    int option;
    float temperature;

    printf("Enter the temperature you would like to convert:");
    scanf("%f", &temperature);

    printf("\n");
    printf("Enter 0 to convert to celsius:\n");
    printf("Enter 1 to convert to kelvin:\n");
    printf("Enter 2 to quit:\n");
    scanf("%d", &option);

    switch(option){
    {
        case 0: printf ("%.2f to celsius is %.2f\n", temperature, fahr_to_cels(temperature));
        break;

        case 1: printf("%.2f to kelvin %.2f\n", temperature, fahr_to_kelvin(temperature));
        break;

        case 2: break;

        default: break;
    }
    }
}

float fahr_to_cels(float temperature){
    float celcius;
    celcius = (temperature - 32)/1.8;
    return celcius;
}

float fahr_to_kelvin(float temperature){
    float kelvin;
    kelvin = fahr_to_cels(temperature) + 273.15;
    return kelvin;
}