/*
Let A = {1, 2, 3, 4, 5, 6, 8, 9, 10, 12, ...} be a series of positive numbers whose prime
factors only include 2, 3, 5. Note that 1 is typically treated as the first number of this
series. See that the 10th number of this series is 12. Write a program to find the n-th
number of this series. In this program, input is the n as positive integer.
*/

#include <stdio.h>

int isSeries(int num) {
    if (num <= 0) {
        return 0;
    }
    while(num%2 == 0){
        num /= 2;
    }
    while(num%3 == 0){
        num /= 3;
    }
    while(num%5 == 0){
        num /= 5;
    }
    return(num==1);
}

int main() {
    int n, count=0, number =1;
    printf("Enter n: ");
    scanf("%d", &n);

    while(count < n){
        if(isSeries(number)){
            count ++;
            if(count == n){
                printf("The %dth number in A is %d", n, number);
                break;
            }
        }
        number ++;
    }
    return 0;
}