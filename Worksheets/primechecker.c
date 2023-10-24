#include <stdio.h>

int isPrime(int isitaprime) {
    int prime, factors = 0;

    // 1 is not a prime number
    if (isitaprime == 1){
        prime = 0;
        return prime;
    } else {
        // a loop which divides the parameter by each number until itself
        for (int i = 1; i < isitaprime; i++){
        //if the modulus is 0 then it is a factor
            if (isitaprime % i == 0){
                factors = factors + 1 ;
            }
        }
        // if the factors are 1 and itself it is a prime number - return 1
        if (factors == 2){
            prime = 1;
            return prime;
        } else {
            prime = 0;
            return prime;
        }
    }
}

int main(){
    int number;
    int prime;

    // user enters a number
    printf("Enter a number: ");
    scanf("%d", &number);

    //calls function
    prime = isPrime(number);

    if (prime == 1){
    printf("The number is prime");
    } else {
     printf("The number is not prime");   
    }
}