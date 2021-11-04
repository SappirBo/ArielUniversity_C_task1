#include <stdio.h>
#include "NumClass.h"
 
/*
Basic main for print.
given two numbers (scanf() ), this main will print all the numbers bitween them.
*/
int main()
{
    int num1,num2;
    scanf("%d", &num1);
    scanf("%d", &num2);

    printf("The Armstrong numbers are:");
    for(int i = num1; i<=num2; i++)
    {
        if(isArmstrong(i)==1)
        {
            printf(" %i",i);
        }
    }
    printf("\n");
    
    printf("The Palindromes are:");
    for(int i = num1; i<=num2; i++)
    {
        if(isPalindrome(i)==1)
        {
            printf(" %i",i);
        }
    }
    printf("\n");
    
    printf("The Prime numbers are:");
    for(int i = num1; i<=num2; i++)
    {
        if(isPrime(i)==1)
        {
            printf(" %i",i);
        }
    }

    printf("\n");

    printf("The Strong numbers are:");
    for(int i = num1; i<=num2; i++)
    {
        if(isStrong(i)==1)
        {
            printf(" %i",i);
        }
    }

    printf("\n");


}

