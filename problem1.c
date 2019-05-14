/*
    Problem description: If we list all the natural numbers below 10 that are multiples of 3 or 5, 
    we get 3, 5, 6 and 9. The sum of these multiples is 23. Find the sum of all the multiples of 3 or 5 below 1000.

    Solution: Simply use a for loop and make use of the mod operator to find the sum. 
    The answer is 233168

    Author: Noah Wagnon
    Date created: 11 May 2019
    Date last modified: 14 May 2019

*/

#include <stdio.h>

int main(){
    int sum = 0;
    for (int i = 1; i < 1000; ++i){
        if ( (i % 3 == 0) || (i % 5 == 0) )
            sum = sum + i;
    }
    printf("The solution is %d\n", sum);
}
