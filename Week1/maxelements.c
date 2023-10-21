#include <stdio.h>

int main(){
    int numberArray[4];
    int anumber = 0 ;
    int a;

    // allows the user to create the numbers held in each array space
    for (a = 0; a<5;a++)
    {
        printf("Enter a number: ");
        scanf("%i", &numberArray[a]);
    }

    // create a for loop that find max val

    for (a = 0; a<5;a++)
    {
        // if the value is bigger than the value in anumber then anumber hold this value
    if (anumber < numberArray[a]){
        anumber = numberArray[a];
    }
    }
    printf("The maximum value is: %i\n ", anumber);

    return 0;
}