#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fun.h"

int Find(const char *filename, int *res) 
{
  int xprev = 0, x = 0, z = 0, flag = 1; 
  FILE *file;
  file = fopen(filename, "r");
  if (file != NULL) 
  {
    if (fscanf(file, "%d", &xprev) != 1) 
    {
      *res=1;
      fclose(file);
      return 0;
    } 
    else 
    {
     if(fscanf(file, "%d", &x)==1)
     { 
      z = x - xprev;
      xprev=x;

      while (fscanf(file, "%d", &x) == 1) 
      {
       if ((x-xprev) != z) 
       {
         flag = 0;
         break;
       }
       x = xprev;
      }
     }
     if (flag==1) 
     {
       *res=1;
       fclose(file);
       return 0;
     } 
     else 
     {
       *res=0;
       fclose(file);
       return 0;
     }
    }
    fclose(file);
   } 
   else 
   return -1;
}
