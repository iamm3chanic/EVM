#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fun.h"

void edit(int **mat, int *str, int col)
{
 int A, i, j, del, *tmp;
 for(A=0, i=0, del=-1; i<*str; i++)
  for(j=0; j<col; j++)
   A+=mat[i][j];
 for(i=0; i<*str; i++)
  for(j=0; j<col; j++)
   if(A==(*str)*col*mat[i][j])
   { del=i; goto lc; }
 lc:;
 if(del!=-1)
 {
  for(i=del; i<*str-1; i++)
  { tmp=mat[i]; mat[i]=mat[i+1]; mat[i+1]=tmp; }
  *str-=1;
 }
}
