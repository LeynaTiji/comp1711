#include <stdio.h>

int main() {
    int numberArray[4];
    int runningTotal = 0;
    int a;

    // allows the user to create the numbers held in each array space
    for (a = 0; a<5;a++)
    {
        printf("Enter a number: ");
        scanf("%i", &numberArray[a]);
    }

    // loop and keep a running total to find the sum of all the integers in the array
    for (a = 0; a<5;a++)
    {
        runningTotal = numberArray[a] + runningTotal;
    }

    //print running total
    printf("Running Total is: %i\n", runningTotal);

    return 0;
}