#include <stdio.h>

int str_len(char* wordarray){
    int length = 0;
    for (int i = 0; wordarray[i] != '\0'; i++){
        //until the element = \0 the loop will run and the length will increment
        length++ ;
    }
    // returns length to main function
    return length;
}

char concatStrings(char* word1, char* word2, char* newword){

    int length1 = str_len(word1);
    int length2 = str_len(word2);

    for (int i = 0; i < length1; i++){
        newword[i] = word1[i];
        printf("%c", newword[i]);
    }

    for (int j = 0 ; j < length2; j++){
        newword[length1 + j] = word2[j];
        printf("%c", newword[length1+j]);
    }

}

int main(){
    char string1[] = "holi";
    char string2[] = "day";
    char newword[20];
    char concatenatedword[20];

    concatStrings(string1, string2, newword);
    
}