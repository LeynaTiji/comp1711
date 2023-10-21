#include <stdio.h>

int main(){
    int numarray[] = {1,2,3,4,5};
    int a ;
    int tempint = 0;

    // a for loop to loop through each index in the array
    for (a=0; a<6; a++){
        tempint = numarray[a];
            numarray[a]= tempint;
    }

    for(a=0; a<5; a++){
        printf("%d", numarray[a]);
    }

}