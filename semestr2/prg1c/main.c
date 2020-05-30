#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fun.h"

int main(void)
{
 int err=0, **mat=NULL, str, col, i, j;
 FILE *f;
 err=input("data.dat", &mat, &str, &col);
 if(err==0)
 {
  edit(mat, &str, col);
  f=fopen("data.res", "w");
  if(f!=NULL)
  {
   fprintf(f, "%d %d\n", str, col);
   for(i=0; i<str; i++)
   {
    for(j=0; j<col; j++)
     fprintf(f, "%d ", mat[i][j]);
    fprintf(f, "\n");
   }
   fclose(f);
  }
  free(mat); mat=NULL;
 }
 return err;
}
