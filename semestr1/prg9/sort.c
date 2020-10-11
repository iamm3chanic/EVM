#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fun.h"

void sort(int *arr, int size)
{
 int t;
 for (int i = size/2 - 1; i>=0; i--)
  sortheap(arr, size, i);
 for (int i = size-1; i>=0; i--)
 {
  {
  t=arr[i];
  arr[i]=arr[0];
  arr[0]=t;
  }
  sortheap(arr, i, 0);
 }
}