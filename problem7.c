/*

Problem description:
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10 001st prime number?

Solution:
We make use of the "prime" function in this problem. It predictably checks whether or not a number is prime,
returning 1 if it is prime and 0 otherwise. We can simply make an infinite loop and go through
every number, checking whether or not it is prime. We will increment a variable called "count"
by 1 each time we find a prime. When "count" reaches 10001, we end the program and print out the 
most recent prime as the answer. The answer is 104743




Author: Noah Wagnon
Date created: 13 May 2019
Date last modified: 14 May 2019

*/


#include <stdio.h>

int prime(int value){
    if (value == 1)
        return 0; //One is not prime
    if (value == 2) 
        return 1; //two is prime
    if (value % 2 == 0)
        return 0; //even numbers are not prime
    for (int i = 3; i <= value / 2; i += 2){
        if (value % i == 0) return 0; // not prime;
    }
    return 1;//is prime
}

int main(){
    int primeCount = 0;
    int i = 2;
    const int check = 10001;
while (1){
if (prime(i) == 1){
    ++primeCount;
}
if (primeCount == check){
    printf("The solution is %d\n", i);
    return 0;
}
++i;
}


return 0;
}
