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
    int clone = a;
    int check =0;
    int digits = 1;
    int j;
    int ans = 0;
    while(clone >= 10)
    {
        clone = clone/10;
        digits++;
    }
    clone = a;
    for(int i=0; i<digits; i++)
    {
        j = digits -i - 1;
        check += (myPow(10,j))*(clone%10);
        clone = clone/10; 
    }
    if(check == a){ans = 1;}
    return ans;

}
