#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fun.h"

int main(void)
{
 int err=0, **mat=NULL, str, *strlen, i, j;
 FILE *f;
 err=input1("data.dat", &mat, &str, &strlen);
 if(err!=0)
  printf("error");
 else
 {
  edit(mat, &str, strlen);
  f=fopen("data.res", "w");
  if(f!=NULL)
  {
   for(i=0; i<str; i++)
    {
     for(j=0; j<strlen[i]; j++)      
     { fprintf(f, "%d ", mat[i][j]);  }
      fprintf(f, "\n");
    }
  }
   fclose(f);
 }
  free(mat); mat=NULL;
  free(strlen); strlen=NULL;
 return err;
}
