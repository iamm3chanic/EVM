#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fun.h"

int Input(const char *filename, int **array, int *n) 
{
  int nmax=2;
  FILE *file;
  file = fopen(filename, "r");
  if (file == NULL)
    return -1;
  if (fscanf(file, "%d", n) != 1) 
  {
    fclose(file);
    return -1;
  }
  *array = (int*) malloc(nmax*sizeof(int));
  for (*n = 0; fscanf(file, "%d", (*array)+*n)==1; (*array)++)
    if (*n>=nmax-1) 
    *array=(int*)realloc(*array,(nmax*=2)*sizeof(int));
  fclose(file);
  return 0;
}
