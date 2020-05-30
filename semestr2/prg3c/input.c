#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fun.h"

int input1(const char *fn, int ***mat, int *str, int **strlen)
{
 FILE *f;
 int count=0, strcount=0,len,i,l;
 char sss[256],num[256];
 char *xxx;
 f=fopen(fn,"r");
 if(f==NULL)return -1;
 for(*str=0,count=0;fgets(sss,256,f)!=NULL; (*str)++)
  for(xxx=sss;(sscanf(xxx,"%s%n",num,&len)==1);xxx+=len,count++);
  {}
  if(count==0) return-1;
  else
  {
   //*str=strcount;
   //*strlen=count;
   *strlen=(int*)malloc((*str)*sizeof(int));
   *mat=(int**)malloc( (*str)*sizeof(int*)+(count+(*str))*sizeof(int) );
   rewind(f);
   (*mat)[0]=(int*)((*mat)+(*str));
   
   for(l=0;fgets(sss,256,f)!=NULL;l++)
   {
    for(i=0,xxx=sss;sscanf(xxx,"%d%n",(*mat)[l]+i,&len)==1;xxx+=len,i++)
    {}
    (*strlen)[l]=i;
    if(l<(*str)-1)
    {(*mat)[l+1]=(*mat)[l]+i;}
   }
  } 
return 0;
}
