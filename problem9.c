/*

Problem description:
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

Solution: 
The most important fact in solving this problem efficiently is a + b + c = 1000.
Knowing this we can set a to 1, b to 2, and have c always = 1000 - a - b.
Then we can use a nested loop to loop through all combinations of a,b, and c
where a + b + c = 1000 until we find the one that is actually a pythagorean triple.
The answer is 31875000. 

Author: Noah Wagnon
Date created: 14 May 2019
Date last modified: 14 May 2019

*/

#include <stdio.h>

int main(){
    const int target = 1000;// 1000 for this problem, can be changed to fit other problems
    int a = 1, b = 2, c = target - a - b; // ensures that a + b + c = 1000
for ( a = 1; a < b; ++a){
    for (b = a + 1; b < c; ++b){
        c = target - a -b;//ensures that a + b + c = 1000
        if ( (c*c) == ( (a*a) + (b*b) ) ){//we have found the pythagorean triple.
            printf("The solution is %d\n", (a*b*c) );
            return 0;
        }
    }
}
    return 0;
}
