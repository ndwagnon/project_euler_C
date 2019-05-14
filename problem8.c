/*

Problem description:
The four adjacent digits in the 1000-digit number that have the greatest product are 9 × 9 × 8 × 9 = 5832.
NOTE: I will not include the 1000 digit number twice, as it can be viewed below in the code.
Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?

Solution: 
To solve this problem, We will need an array of 13 integers to store the solution. We also need to know
that the numbers are actually characters, therefore we will need to subtract '0' from them
to offset the ascii values. With this knowledge in mind, we can use a nested for loop to loop through
all possible 13 digit products and find the highest one. We will then allocate the array with these 13
digits and print them and their product. The product is 23514624000.

Author: Noah Wagnon
Date created: 13 May 2019
Date last modified: 14 May 2019

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int check = 13; // can be adjusted depending on how many digits the user wants
const char* num = "73167176531330624919225119674426574742355349194934\
96983520312774506326239578318016984801869478851843\
85861560789112949495459501737958331952853208805511\
12540698747158523863050715693290963295227443043557\
66896648950445244523161731856403098711121722383113\
62229893423380308135336276614282806444486645238749\
30358907296290491560440772390713810515859307960866\
70172427121883998797908792274921901699720888093776\
65727333001053367881220235421809751254540594752243\
52584907711670556013604839586446706324415722155397\
53697817977846174064955149290862569321978468622482\
83972241375657056057490261407972968652414535100474\
82166370484403199890008895243450658541227588666881\
16427171479924442928230863465674813919123162824586\
17866458359124566529476545682848912883142607690042\
24219022671055626321111109370544217506941658960408\
07198403850962455444362981230987879927244284909188\
84580156166097919133875499200524063689912560717606\
05886116467109405077541002256983155200055935729725\
71636269561882670428252483600823257530420752963450";

int main(){

long max = 0;
int valArr[check];
long value;

//nested for loop checks all possible 13 digit products and replaces the max with that product if necessary
for (int i = 0; i < (strlen(num) - check); ++i){
    value = 1;
    for (int j = i; j < i + check; ++j){
        value = value * (num[j] - '0'); //converts a character to its decimal value with ascii subtraction
    }
    if (value > max) {//replaces the max with the new value
        max = value;
        //replaces the array with with the new 13 digit chain
        for (int k = 0; k < check; ++k){
            valArr[k] = num[i+k] - '0';
        }
    }
}
    printf("The product is %ld.\n", max);
    printf("Here are the numbers: ");
    for (int i =0; i < check; ++i){
        printf("%d ", valArr[i]);
    }
    printf("\n");
    return 0;
}
