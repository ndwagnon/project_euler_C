/*

Problem description: 
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

Solution: We use an infinite while loop to check the variable answer to see if it is divisible
by all numbers 1-20, if it fails one of the numbers immediately exit the loop and move on to the 
next even number. Continue this until we finally find the even number divisibly by 1-20 and then
end the program. That number is 232792560.

Author: Noah Wagnon
Date created: 13 May 2019
Date last modified 14 May 2019

*/



#include <stdio.h>

int main() {
    int answer = 20; //start with the value of the highest necessary factor (20 in this case)
while (1){
    for (int i = 1; i <= 20; ++i){
        if (answer % i != 0) break; //this value does not work
        if ( i == 20){//if i is 20, then the number has been divided evenly by all
        printf("The solution is %d\n", answer);//we found the answer
        return 0; //program is complete
        }
    }
    answer += 2; //increase the value by 2 and try again. 2 because we know the answer must be even. 

}

    return 0;
}
