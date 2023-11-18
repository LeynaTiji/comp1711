#include <stdio.h>

int main(){

    int maxInt = 2147483647; 
    float maxFloat= 3.402823466;
    double maxDbl = 1.7976931348623158;
    char maxChar = 127;

    printf("The maximum integer, float, double and char is %d %f %f %c\n", maxInt, maxFloat, maxDbl, maxChar);


    return 0;
}