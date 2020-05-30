#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fun.h"

int Find(const char *fn, int *res )
{
 int a=1,b=1,x,xprev;
 FILE *f;
 f=fopen(fn,"r");
 if(f!=NULL)
 {  
   *res=1;
   fscanf(f,"%d",&xprev);
   while(fscanf(f,"%d",&x)==1)
   {    
    if (x>xprev)  a=a+1;
    else if (x<xprev)  b=b+1;
    xprev=x;
   }
   if(a>b) *res=0;
   if(a<b) *res=1;
   if(a==b) *res=2;
  fclose(f);
  return 0;
 }
 else
 return -1;
}
