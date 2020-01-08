//Program to generate prime numbers.
#include <stdio.h>
int main(){
    int n, i, j, primes[1000];
    printf("Enter the value of n:");
    scanf("%d",&n);
    for(i=2;i<n;i++){
        primes[i]=i;
    }
    for(i=2;i*i<n;i++){
        if(primes[i]!=0){
            for(j=2;j<n;j++){
                if(primes[i]*j>n){
                    break;
                }
                else{
                    primes[primes[i]*j]=0;
                }
            }
        }
    }
    for(i = 2; i<=n; i++)
    {
        //If number is not 0 then it is prime
        if (primes[i]!=0)
            printf("%d\n",primes[i]);
    }
    return 0;
}