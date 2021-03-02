#include "mystring.h"
#include "myutils.h"
#include "bitmask.h"
#include <stdio.h>
#include <stdarg.h>

int main()
{
    char s1[] = "NAGA";
    char s2[] = "ANJANEYA";
    char s3[] = "SRI";
    char s4[] = "ANJANEYA";
    int num = 8, num1 = 212, v1=3, v2=10, v3=100, v4=200, n=5, k=2;


//String
printf("copied string = %s\n", mystrcpy(s1,s2));
printf("length of the string = %d\n", mystrlen(s3));
printf("String after concatination = %s\n", mystrcat(s3, s4));
if(mystrcmp(s1, s2) == 1)
{
  printf("Same Strings\n");
}
else
printf("Strings are not Same\n");

//utils
printf("Factorial of given number is %d\n", fact(num));
if(check_prime(num)==1)
{
    printf("Prime Number\n");
}
else
printf("Not a Prime Number\n");
if(checkPalindrome(num1)==0)
{
    printf("Given Number is Palandrome\n");
}
else
printf("Not a Palandrome\n");
printf("Sum = %d\n", vsum(v1, v3, v4, v2));

//bitmask

printf("after setting the %dnd bit of %d = %d\n",k,n,setBit(n,k));
printf("after resetting the %dnd bit of %d = %d\n",k,n,resetBit(n,k));
printf("after flipping the %dnd bit of %d = %d\n",k,n,flipBit(n,k));
printf("after query the %dnd bit of %d = %d\n",k,n,query(n,k));
}
