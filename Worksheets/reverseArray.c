#include <stdio.h>

void reverseArray(int* array, int length){
    int reversed[15];

    for (int j = 0; j <= length; j++){
        reversed[j] = array[length - (j + 1)];
    }

    for (int i = 0; i <= length; i++){
        array[i] = reversed[i] ;
    }

}

int main(){
    int numarray[] = {1,2,3,4,5,6,7,8};
    int length = 8;

    reverseArray(numarray, length);

    return 0;
}