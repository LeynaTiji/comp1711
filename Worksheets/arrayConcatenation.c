#include <stdio.h>

int main(){
    int array1[] = {1,2,3};
    int array2[] = {4,5,6};
    int newarray[6];
    
    for (int i = 0; i < 3;)
    {
        newarray[i] = array1[i];
        i++;
    }

    for (int j = 3; j < 6;)
    {
        newarray[j] = array2[j - 3];
        j++;
    }

    for (int a = 0; a< 6; a++)
    {
        printf("%d\n", newarray[a]);
    }
    return 0;
}