#include "myutils.h"
#include <stdarg.h>

// Factorial Program

int fact(int n)
{
    int i,f=1;
    for(i=1;i<=n;i++)
    {
        f=f*i;
    }
    return f;
}

// Prime number

int check_prime(int a)
{
   int c;
 
   for ( c = 2 ; c <= a - 1 ; c++ )
   { 
      if ( a%c == 0 )
     return 0;
   }
   return 1;
}

// Palindrome

int checkPalindrome(int number)
{
  int temp, remainder, rev=0;

  temp = number;

  while( number!=0 )
  {
     remainder = number % 10;

     rev = rev*10 + remainder;

     number /= 10;
  }

  if ( rev == temp ) 
  return 0;
  else 
  return 1;
}

// Vsum

int vsum(int a, ...) 
{
    
    va_list L;
    int z;

    z = 0;

    va_start(L, a);

   
    for (int i=0; i < a; i++)
    {
        z = z + va_arg(L, int);
    }

    va_end(L);

    return z;
}

