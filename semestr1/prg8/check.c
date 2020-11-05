#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fun.h"

int check(int *array, int size)
{
 int i, err=0;
 for(i = 0; i<size-1; i++)
  if(array[i]>array[i+1])
  err--;
 return err;
}
