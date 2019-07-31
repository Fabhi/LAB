//Program to find the sum of natural numbers till n
#include <stdio.h>
void main(){
    int i,n;
    printf("Enter the value of n:");
    scanf("%d", &n);
    i=n*(n+1)/2;
    printf("The sum of %d numbers is %d",n,i);
}