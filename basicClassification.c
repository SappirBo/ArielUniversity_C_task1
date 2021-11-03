#include <stdio.h>


int isPrime(int a)
{
    if(a==0||a==1){return 0;}
    else if(a==2||a==3){return 1;}
    else
    {
    _Bool ans = 1;

    for(int i=2;i<a; i++){
        if(a%i == 0){
            ans = 0;
        }
        if(ans == 0){break;}
    }
    return ans;
    }
}

/*
This is a helper function for isSstrong.
It's input is a number "num", and it's output is num! (the factorial).   
*/
int factorial(int num)
{
    int ans = 1;
    for(int i=1; i<=num; ++i){
        ans *= i;
    }
    return ans;
}

int isStrong(int a)
{
  int digit;
  int clone = a;
  int tmp = 0;
  int ans = 0;
    while(clone >=10)
    { 
      digit = clone%10;
      clone = clone/10;
      tmp += factorial(digit);
    }
  tmp += factorial(clone);
  if(tmp == a ){ans = 1;}
  return ans;
}

