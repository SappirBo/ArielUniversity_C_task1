#include <stdio.h>


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

int isArmstrong(int a)
{
    
    int digit = digits(a);
    int ans = 0;
    int sum = isArmstrongRecu(a , digit);
    if(a == sum){ans = 1;}
    return ans;
}

int isPalindrome(int a)
{
    // int check = digits(a);

    if (digits(a)==1){ return 1;}
    else if(digits(a)==2)
    {
        if(a/10 == a%10){return 1;}
        else {return 0;}
    }
    else
    {
        int d = 1;
        for(int i=1;i<digits(a); i++)
        {
            d *= 10;
        } 

    //    int num1 = a%10;
   //     int num2 = a/d;

        if(a%10 != a/d){return 0;}
        else
        {
            int clone = a; 
            clone = (a - d*(a%10))/10;
            return isPalindrome(clone);  
        }

    }

}
