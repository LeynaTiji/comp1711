#include <stdio.h>

int main(){

    float area;
    float height;
    float width;

    printf("Enter the height of the rectangle: ");
    scanf("%f.3", &height);
    printf("Enter the width of the rectangle: ");
    scanf("%f.3", &width);
    area = height * width;

    printf("The area of the rectangle is %.3f\n", area);

    return 0;

}