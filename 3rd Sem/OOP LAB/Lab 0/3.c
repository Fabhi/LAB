//Program to find the sum of an HP
#include <stdio.h>
void main(){
    int n, i;
    float val;
    printf("Enter the value of n to calculate the sum:");
    scanf("%d", &n);
    val=0;
    for(i=1;i<n;i++){
        val+=1.0/i;
    }
    printf("The sum of the series is %f", val);
}