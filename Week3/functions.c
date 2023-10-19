#include <stdio.h>

float sum(float a, float b){
    float answer;
    answer = a + b;
    return answer;
}

float main(){
    float x = 6.75432;
    float y = sum(5.819, x);

    printf("The sum of 5.819 and %.3f is %.3f\n", x, y);
}

