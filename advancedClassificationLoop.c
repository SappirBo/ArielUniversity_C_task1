#include <stdio.h>


/*
Helper function for is Armstrong, it's doind pow in the amount of time the it gets.
for example: pow(5,4) = 5*5*5*5 = 5^4.
*/
int myPow(int num,int amount)
{
    int ans = 1;
    for(int i=0; i<amount;i++)
    {
        ans *= num;
    }
    return ans;
}

//helper to get the number of digits in given number.
//for example: 1. intput:407, output:3. 
//2.input:78, output:2.
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

int isArmstrong(int a)
{

    int clone = a ;
    int digits = 1;
    int tmp = 0;
    int check = 0;
    int ans = 0;
    while(clone >= 10)
    {
        clone = clone/10;
        digits++;
    }
    clone = a;
    while(clone >=10)
    {
        tmp = clone%10;
        check += myPow(tmp , digits);
        clone = clone/10;
    }
    check += myPow(clone,digits);
    if(check == a){ans = 1;}
    return ans;
}

int isPalindrome(int a)
{
    int ans = 1;
    int dig = digits(a);
    char numStr [dig];
    char check [dig];
    sprintf(numStr,"%d",a);

    for(int i=0; i<dig ;i++)
    {
        check[i] = numStr[dig-i-1];
    }
    for(int i=0;i<dig;i++)
    {
        if(check[i] != numStr[i])
        {
            ans = 0;
        }
        if(ans == 0){break;}
    }
    return ans;
}
