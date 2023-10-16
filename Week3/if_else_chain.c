#include <stdio.h>

int main(){

    int mark ;
    int a = 0;

    // a = 0 so loop will enter
    while (a != 1){
        printf("Enter your mark: ");
        scanf("%d", &mark);
        
        //is mark is negative or over 100 is it invalid
        if (mark < 0 || mark >100 )
        {
            printf("Invalid, enter your mark: ");
        scanf("%d", &mark);
        }
        else if (mark ==0)
        {
        printf("The mark of %d is zero\n", mark);
        a = 1;
        }
        else if (mark < 40)
        {
        printf("The mark of %d is a fail\n", mark);
        a = 1;
        }
        else
        {
        printf("The mark of %d is a pass\n", mark);
        a = 1;
        }
    }
    
    return 0;
}