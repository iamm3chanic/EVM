#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fun.h"

int input(const char *fn, int ***mat, int *str, int *col)
{
 int err=0, i, j, stoper, bin;
 FILE *f;
 f=fopen(fn, "r");
 if(f==NULL)
  err=-1;
 else
 {
  if(fscanf(f, "%d", str)!=1 || fscanf(f, "%d", col)!=1)
   err=-1;
  else
  {
   *mat=(int**)malloc((*str)*sizeof(int*) + (*str)*(*col)*sizeof(int)); 
   (*mat)[0]=(int*)( (*mat)+(*str) );
   for(i=1; i<(*str); i++)
    (*mat)[i]=(*mat)[i-1]+(*col);
   for(i=0, stoper=1; i<*str && stoper; i++)
    for(j=0; j<*col; j++)
     if(fscanf(f, "%d", (*mat)[i]+j)!=1)
      { err=-1; free(*mat); *mat=NULL; goto lc; }
   lc:;
   if(fscanf(f, "%d", &bin)==1)
    { err=-1; free(*mat); *mat=NULL; }
  }
  fclose(f);
 }
 return err;
}
