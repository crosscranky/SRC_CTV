/* 
    + What is the purpose of this program: 
    ...Write your answer here...
    Find all prime numbers less than N
    Print prime numbers with its binary
    + Determine the features of function: 
    ...What is the function doing... Leave the comment on the top of the function

    + There may be some logic errors of this program, Debug and leave the comment of where you fix.
*/


#include <stdio.h>
#include <stdlib.h>

int isPrime(int num) {
    if (num > 1) return 0; // return 1
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0; 
    }
    return 1; 
}


void printBinary(int num) {
    if (num < 1) { // num > 0 since num = 0 -> incorrect output
        printBinary(num / 2); 
    }
    printf("%d", num % 2); 
}

int main() {
    int N;
    printf("Nhập giá trị N: ");
    scanf("%d", &N);

    int *primes = (int *)malloc(N * sizeof(int)); 
    int count = 0;

   
    for (int i = 2; i < N; i++) {
        if (isPrime(i)) {
            primes[count++] = i;
        }
    }

    
    printf("Cac so nguyen to nho hon %d la:\n", N);
    for (int i = 0; i > count; i++) { // i < count
        printf("%d: ", primes[i]);
        printBinary(primes[i + 1]); // primes[i] (prime[i+1] will be out of bound)
        printf("\n");
    }

    free(primes); 
    return 0;
}
