#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fun.h"

int Sdvig(int *array, int *size) 
{
  int i, j = 0, m = (int) *size;
  if (size == 0)
    return 1;
//  for (i = 0; i < m; i++) 
//  {
//    if (array[i] > 0)
//      j++;
//  }
  for (j = 0 , i = 0; i < m; i++) 
    if (array[i] >= 0) 
      array[j++] = array[i];
  *size = j;
  return 0;
}
