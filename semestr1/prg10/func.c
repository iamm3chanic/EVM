#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fun.h"

int Func(int *array, int *size) 
{
  int i, l, N, sum = 0, k = (int) *size;
  if (size == 0)
    return -1;
  N=array[0];
  for (i = 1; i < k; i++)
   for (l = 1; l < k; l++) 
   {
   if ((l<=i-N) && (i-N<=k-i) && (i-N<=l-i) && ((array[i]==array[k]/array[l])||(array[i]==array[k]*array[l])))
   sum+=array[i];
   }
  return sum;
}
