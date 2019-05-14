/*

Problem description:
In the 20×20 grid below, four numbers along a diagonal line have been marked in red.
NOTE: I will not include the grid again because it is already in the code below.
The product of these numbers is 26 × 63 × 78 × 14 = 1788696.
What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20×20 grid?

Solution:
This problem is fairly simple to comprehend, but fairly rigorous to implement, as there is
simply a very large quantity of numbers to consider. The first step was to create a matrix and 
populate it with the numbers. This would have been easy, but the 0s in front of numbers and the 
spaces between numbers complicated matters, along with the fact that I had to convert the type
from char to int using ascii offset subtraction. After this was over, I split the program into 4 parts,
computing the max four-digit product vertically, horizontally, and both diagonal directions. 
After all the maxes were determined, I compared them at the end and reported the highest one as
the solution. The answer is 70600674.

Author: Noah Wagnon
Date created: 14 May 2019
Date last modified: 14 May 2019

*/

#include <stdio.h>
const int size = 4;//length of product chain
const char *num = \
"08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08\
49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00\
81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65\
52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91\
22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80\
24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50\
32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70\
67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21\
24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72\
21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95\
78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92\
16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57\
86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58\
19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40\
04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66\
88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69\
04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36\
20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16\
20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54\
01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48";


int main(){
    unsigned long long vertMax = 1, horMax = 1, diagMaxRight = 1, diagMaxLeft = 1, vertCurr = 1, horCurr = 1, diagCurrRight = 1, diagCurrLeft = 1;
    unsigned long long otherDiagCurrRight = 1, otherDiagMaxRight = 1, otherDiagCurrLeft = 1, otherDiagMaxLeft = 1;
    int array[20][20] = {0};
    int vertAns[4] = {0}, horAns[4] = {0}, diagAnsRight[4] = {0}, diagAnsLeft[4] = {0};
    int otherDiagAnsRight[4] = {0}, otherDiagAnsLeft[4] = {0};
    //for loop to populate the array
    for (int i = 0; i < 20; ++i){
        for (int j = 0; j < 59; j+=3){
            array[i][j/3] = 10 * (num[j + (i * 59)] - '0') + (num[j + 1 + (i * 59)] -'0');
        }
    }

    //for loop that computes the maximum vertical product
    for (int j = 0; j < 20; ++j){
        for (int i = 0; i < 17; ++i){
            vertCurr = 1;
            for (int k = 0; k < size; ++k){
                vertCurr = vertCurr * array[i + k][j];
            }
            if (vertCurr > vertMax){
                vertMax = vertCurr;
                for (int a = 0; a < size; ++a){
                    vertAns[a] = array[i + a][j];
                }
            }
        }
    }

    //for loop that computes the maximum horizontal product
    for (int i = 0; i < 20; ++i){
        for (int j = 0; j < 17; ++j){
            horCurr = 1;
            for (int k = 0; k < size; ++k){
                horCurr = horCurr * array[i][j + k];
            }
            if (horCurr > horMax){
                horMax = horCurr;
                for (int a = 0; a < size; ++a){
                    horAns[a] = array[i][j + a];
                }
            }
        }
    }

    //for loop that computes the maximum diagonal product of the right half
    for (int off = 0; off < 17; ++off){
        for (int p = 0; p < 17 - off; ++ p){
            diagCurrRight = 1;
            for (int k = 0; k < size; ++k){
                diagCurrRight = diagCurrRight * array[p + k][p + off + k];
            }
            if (diagCurrRight > diagMaxRight){
                diagMaxRight = diagCurrRight;
                for (int a = 0; a < size; ++a){
                    diagAnsRight[a] = array[p + a][p + off + a];
                }
            }
        }
    }

    //for loop that computes the maximum diagonal product of the left half
    for (int off = 1; off < 17; ++off){
        for (int p = 0; p < 17 - off; ++ p){
            diagCurrLeft = 1;
            for (int k = 0; k < size; ++k){
                diagCurrLeft = diagCurrLeft * array[p + k + off][p + k];
            }
            if (diagCurrLeft > diagMaxLeft){
                diagMaxLeft = diagCurrLeft;
                for (int a = 0; a < size; ++a){
                    diagAnsLeft[a] = array[p + a + off][p + a];
                }
            }
        }
    }

    //for loop that computes the maximum diagonal product of the right half of the other direction
    for (int off = 0; off < 17; ++off){
        for (int p = 19; p > 2 + off; --p){
            otherDiagCurrRight = 1;
            for (int k = 0; k < size; ++k){
                otherDiagCurrRight = otherDiagCurrRight * array[p - k][19 - p + off + k];
            }
            if (otherDiagCurrRight > otherDiagMaxRight){
                otherDiagMaxRight = otherDiagCurrRight;
                for (int a = 0; a < size; ++a){
                    otherDiagAnsRight[a] = array[p - a][19 - p + off + a];
                }
            }
        }
    }

    //for loop that computes the maximum diagonal product of the left half of the other direction
    for (int off = 1; off < 17; ++off){
        for (int p = 19; p > 2 + off; --p){
            otherDiagCurrLeft = 1;
            for (int k = 0; k < size; ++k){
                otherDiagCurrLeft = otherDiagCurrLeft * array[p - k - off][19 - p + k];
            }
            if (otherDiagCurrLeft > otherDiagMaxLeft){
                otherDiagMaxLeft = otherDiagCurrLeft;
                for (int a = 0; a < size; ++a){
                    otherDiagAnsLeft[a] = array[p - a + off][19 - p + a];
                }
            }
        }
    }

    unsigned long long solution = vertMax;
    if(horMax > solution)
        solution = horMax;
    if(diagMaxRight > solution)
        solution = diagMaxRight;
    if (diagMaxLeft > solution)
        solution = diagMaxLeft;
    if (otherDiagMaxRight > solution)
        solution = otherDiagMaxRight;
    if (otherDiagMaxLeft > solution)
        solution = otherDiagMaxLeft;
    printf("The solution is %llu\n", solution);
    return 0;
}
