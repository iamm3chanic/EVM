#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fun.h"

void sort(int *arr, int size)
{
 int i,j,t;
 for(i=0; i<size-1; i++)
  for(j=0; j<size-1; j++)
  if (arr[j]>arr[j+1])
  {
  t=arr[j];
  arr[j]=arr[j+1];
  arr[j+1]=t;
  }
}