#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fun.h"

void edit(int **mat, int *str, int col)
{
 int  i=0, j=0, b,s,p, *tmp=NULL;
 if ((*str)>1)
 {
  tmp=(int*) malloc(col * sizeof(int));
  for(j=0;j<col;j++)
  {
   s=0;
   for(i=0;i<(*str);i++)
    s=s+(mat[i][j]);  //summa eltov stolbca
   tmp[j]=s;
  }
 
  for(p=-1,i=0;i<(*str); i++)
  {
   for(b=0, j=0; j<col; j++)
    if(((mat[i][j])*(*str))==(tmp[j])) //sred arifm
     b++; 
   if(b==col)
    {p=i;break;}
  }
  free(tmp); tmp=NULL;
  
  if(p>=0)
   for((*str)--,i=p; i<(*str); i++)
     mat[i]=mat[i+1];
 }
 else
 { (*str)=0; }
}
