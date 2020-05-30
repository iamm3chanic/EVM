#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fun.h"

int Find(const char *filename, int *res) 
{
  int x = 0, temp = 0, prev = 0, pred = 0, maximum = 0;
  FILE *file;

  file = fopen(filename, "r");
  if (file != NULL) 
  {
    if (fscanf(file, "%d", &x) != 1)
    {
      fclose(file);
      return 0;
    } else 
    {
      temp = x;
      prev = x;
      pred = x;
      maximum = x;
      while (fscanf(file, "%d", &x) == 1) 
      {
        temp = prev + x;
        if ((temp - prev) >= maximum) 
        {
          maximum = temp - prev;
        }
        if (temp >= maximum) 
        {
          maximum = temp;
        }
        if (x > 0 && prev < 0 && pred < 0) 
        {
          temp = x;
        }
        prev = temp;
        pred = x;
      }
      *res = maximum;
    }
  }
  fclose(file);
  return 0;
}
