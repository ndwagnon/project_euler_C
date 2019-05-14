/*

Problem description: 
A palindromic number reads the same both ways. The largest palindrome made from the product of 
two 2-digit numbers is 9009 = 91 × 99. Find the largest palindrome made from the product of two 3-digit numbers.

Solution: The product of two three-digit numbers is always 6 digits. 
A six digit palindrome has the form ijkkji. We can make a nested loop to start 
with the largest possible palindrome (999999) and work our way down until we find
a palindrome that has two whole number factors. The two whole number factors
are 913 and 993, and their product is the palindrome 906609. 

Author: Noah Wagnon
Date created: 12 May 2019
Date last modified: 14 May 2019

*/


#include <stdio.h>

int main(){
int extra, subject;
for (int i = 9; i > 0; --i){
    for (int j = 9; j >= 0; --j){
        for (int k = 9; k >= 0; --k){
             subject = (100001 * i) + (10010 * j) + (1100 * k); //create the palindrome
            for (int m = 999; m >= 100; --m){
                if (subject % m != 0) continue;
                extra = subject / m;
                if (extra >= 100 && extra <= 999){
                    printf("The solution is %d. The values are %d and %d\n", subject, extra, m);
                     return 0;
                }
            }
        }
    }
}



    return 0;
}
