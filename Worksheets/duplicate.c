#include <stdio.h>

int main(){
    int array_of_numbers[] = {1,2,5,4,3,3,7,8};
    int a, duplicate; 
    int count = 0;
    int temp = 0;

    for (a = 0; a < 7; a++)
    {
        if (temp == array_of_numbers[a])
        {
            duplicate = array_of_numbers[a];
            count = 1;
        }
        temp = array_of_numbers[a];
    }

    if (count = 1)
    {
    printf("The duplicate value is %d\n", duplicate);
    }

    return 0;
}