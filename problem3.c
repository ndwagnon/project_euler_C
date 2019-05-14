/*

Problem description: 
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?

Solution: An extremely useful mathematical fact for this problem is as follows:
all composite numbers can be expressed as a product of prime numbers. With this in mind,
if we find a prime number that is a factor of our target number, we can continuously
divide until there is a remainder. For example, 147 = 3 * 7 * 7
The last factor will always be the highest prime. This significantly lowers the target number and makes
it possible for the computer to do the calculation in a reasonable amount of time. I 
implemented this in the "check function". The answer is 6857.


Author: Noah Wagnon
Date created: 11 May 2019
Date last modified: 14 May 2019

*/

#include <stdio.h>

int check(long value){
    int answer = 1;

    if (value % 2 == 0){
        while (value % 2 == 0) {
           value = value / 2; answer = 2;
        }
    }

    for (int i = 3; i <= value; i += 2){ //check all odd numbers
       while (value % i == 0) {
           value = value / i; answer = i;
        }
    }
    return answer;
}

int main(){
int solution = check(600851475143);
printf("The solution is %d\n", solution);

return 0;
}
