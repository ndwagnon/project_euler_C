/*

Description:
Each new term in the Fibonacci sequence is generated by adding the previous two terms. 
By starting with 1 and 2, the first 10 terms will be:
1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.

Solution: I wrote a simple function called "fib" to solve this problem. It is a recursive function that 
stops at the base case when the ceiling has been reached. It keeps track of the three numbers at a time to keep
building and summing up the fibonacci sequence. The answer is 4613732.

Author: Noah Wagnon
Date created: 11 May 2019
Date last modified: 14 May 2019

*/




#include <stdio.h>
int sum = 0;
int fib(int curr, int prev, int before){
    
if ( (curr ) > 4000000) return sum;
sum = sum + fib(curr + prev, prev + before, prev);

if  ( ( (curr ) % 2) == 0 ) return sum + curr;
else return sum;

}
int main(){
    
    int curr = 2;
    int prev = 1;
    int before = 1;
    sum = fib(curr, prev, before);
    printf("The solution is %d\n", sum);

}