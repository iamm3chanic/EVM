#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fun.h"

int Sdvig(int *array, int size, int *res) 
{
  int i, maximum = array[0], numbermax = 1;
  if (size == 0) 
  {
    return 1;
  }
  for (i = 1; i < size; i++) 
  {
    if (array[i] > maximum) 
    {
      maximum = array[i];
      numbermax = i + 1;
    }
  }
  *res = numbermax;
  return 0;
}
