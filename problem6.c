/*

Problem description: 
The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385
The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)2 = 55^2 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and 
the square of the sum is 3025 − 385 = 2640.
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

Solution:
This is probably the simplest problem so far in the project. We simply make two int variables and initialize
them to 0. Then make a for loop from 1-100 and on one variable, square the "i" value and add it to the sum. For
the other variable, just add the "i" value. After the for loop square the "squareSum" variable. Then we simply
subtract the two and print out the answer. The answer is 25164150.

Author: Noah Wagnon
Date created: 13 May 2019
Date last modified 14 May 2019

*/

#include <stdio.h>

int main(){
int sumSquares = 0, squareSum = 0;

for (int i = 1; i <= 100; ++i){
sumSquares = sumSquares + (i * i);
squareSum = squareSum + i;
}
squareSum = squareSum * squareSum;

printf("The sum of squares is %d. The square of sums is %d. The difference is %d\n ", sumSquares, squareSum, (squareSum - sumSquares));

    return 0;
}
