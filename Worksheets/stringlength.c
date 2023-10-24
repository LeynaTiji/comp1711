#include <stdio.h>

int str_len(char * wordarray){
    int length = 0;
    for (int i = 0; wordarray[i] != '\0'; i++){
        //until the element = \0 the loop will run and the length will increment
        length++ ;
    }
    // returns length to main function
    return length;
}

int main(){
    char word[45] = "dsjkgjqpernfckdjdfadjfh";

    //pass the word as a parameter 
    printf("The length of the word is: %d\n", str_len(word));
}