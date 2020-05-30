#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "fun.h"
#include "str.h"

int output1(const char *fn, SStudent **s,int n)
{
 FILE *ff;
 int err=0,i;
 ff=fopen(fn,"w");
 if(ff==NULL) {err=-1;goto lc;}//not found
 else
  {
  for(i=0;i<n;i++)
  {
   fprintf(ff, "%d %s %f\n", s[i]->group,s[i]->name,s[i]->rating);
  }
  err=0;
  fclose(ff);
 }
 lc:
 return err;
}
