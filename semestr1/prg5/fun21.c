#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fun.h"

int Sdvig(float *array, int size) 
{
  int i = 0, j = 0, m = 1, count = 0; float sum;
  if (size == 0)
    return -1;
  for (i=0,m=1;i < (size - 1);) 
  {
    count = i;
    if (array[count] >= array[count + 1]) 
    {
      i++;
      m++;
      continue;
    }
    for( ; count+1 < size && array[count] < array[count + 1];m++,count++); 
    for (sum=0, j = i; j < m; j++) 
      sum += array[j];
    for (j = i; j < m; j++) 
      array[j] = sum / (m - i);
    i = m;
    m++;
  }
  return 0;
}
