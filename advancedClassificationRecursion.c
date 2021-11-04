#include <stdio.h>


/*
helper to get the number of digits in given number.
for example: 1. intput:407, output:3. 
2.input:78, output:2.
*/
int digits(int num)
{
    int ans = 1;
    while (num >= 10)
    {
        num = num/10;
        ans++;
    }
    return ans;
}
/*
this is a recursive Helper fuction for isArmstrong.
when isArmstrong gets an input, it sends the number and his digits size into this helpper. 
this helper sums up the number ^ digits.
*/
int isArmstrongRecu(int num,int d)
{
    int sum = 1;
    int dig = digits(num); 

    if(dig == 1){
        for(int i=0; i<d; i++)
        {
            sum *= num;
        }
        return sum;
    }
    else
    {
        int tmp = num%10;
        for(int i=0; i<d;i++)
        {
            sum *= tmp;
        }
        return sum + isArmstrongRecu( num/10 , d) ;
    } 
   
}
/*
this is a recursive helper for isPolindrom - if num[low] = num[high] , it will call itself with low++ and high-- 
(so it will check the next pair of digits). 
*/
int isPalindromeRecu(char num[],int low,int high)
{
    if(high == low){return 1;}
    else if(high == low+1)
    {
        if(num[high] == num[low])
        {
            return 1;
        }
        else {return 0;}
    }
    else
    {
        if(num[high] == num[low])
        {
            return isPalindromeRecu(num, low+1, high-1);
        }
        else
        {
            return 0;
        }
    }
}



/*
the main function to find a Armstrong number.
here it checkout the number of digits(with the function "digits()") and then using isArmstrongRecu() to determine the sum of the input.
*/
int isArmstrong(int a)
{
    int digit = digits(a);
    int ans = 0;
    int sum = isArmstrongRecu(a , digit);
    if(a == sum){ans = 1;}
    return ans;
}

/*
the main function to find a Palindrome number.
here it converts the int into String (char array), and send the string to isPalindromeRecu, that returns true/false (1\0).

*/
int isPalindrome(int a)
{
    int dig = digits(a);
    char numStr [dig];
    sprintf(numStr,"%d",a);
    return isPalindromeRecu(numStr,0,sizeof(numStr)-1);  
}
