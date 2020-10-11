#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fun.h"

int read(const char *filename, int **array, int *size) 
{
  int i;
  FILE *file;
  file = fopen(filename, "r");
  if (file == NULL)
    return -1;
  if (fscanf(file, "%d", size) != 1) 
  {
    fclose(file);
    return -2;
  }
  *array = (int*) malloc(*size * sizeof(int));
  if (*array == NULL) 
  {
    fclose(file);
    return -3;
  }
  for (i = 0; i < *size; i++)
    if (fscanf(file, "%d", (*array) + i) != 1) 
    {
      free(*array);
      fclose(file);
      return -4;
    }
  fclose(file);
  return 0;
}
