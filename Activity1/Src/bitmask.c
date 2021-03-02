#include "bitmask.h"

// Function to set the kth bit of n 

int setBit(int n, int k) 
{ 
    return (n | (1 << (k - 1))); 
} 
  
// Function to clear the kth bit of n 

int resetBit(int n, int k) 
{ 
    return (n & (~(1 << (k - 1)))); 
} 
  
// Function to toggle the kth bit of n 

int flipBit(int n, int k) 
{ 
    return (n ^ (1 << (k - 1))); 
} 

//query

int query(int n, int k)
{
    return (n & (1 << (k - 1)));
}