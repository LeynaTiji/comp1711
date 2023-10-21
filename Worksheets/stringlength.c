#include <stdio.h>

int str_len(char wordforarray){
    int length = 0;
    char wordarray[] = "wordforarray" ;
    for (int i = 0; wordarray[i] != '\0'; i++){
        length = length + 1 ;
        return length;
    }
}

int main(){
    char word;

    printf("Enter a word: ");
    scanf("%c\n", &word);

    printf("The length of the word is: %d\n", str_len(word));
}