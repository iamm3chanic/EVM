#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "fun.h"
#include "str.h"

int main(void)
{
 int errin=0,errout1=0,errout2=0,n,m,i=0;
 SStudent **s, **neww;
 errin=input1("data.dat", &s,&n);
 printf("checked errin=%d\n",errin);
 if(errin==-1)printf("infile not found\n");
 if(errin==-2)printf("empty file1\n");
 if(errin==-3)printf("empty file2\n");
 else if(errin==0)
 {
  errout1=output1("data.res", s,n);
  errout2=output1("datashort.res", s,n);
  printf("checked errout1=%d\n",errout1);
  printf("checked errout2=%d\n",errout2);
  if (errout1==-1) 
   {printf("outfile 'data.res' not found\n"); for(i=0;i<n;i++) free (s[i]); free(s);}
  else if (errout2==-1) 
   {printf("outfile 'datashort.res' not found\n"); for(i=0;i<n;i++) free (s[i]); free(s);}
  else
   {
    output1("data.res", s,(n));
    sort(s,n);
    edit(s,&neww,n,&m);
    output2(neww,m);
    output1("datashort.res", neww,m);
    for(i=0;i<n;i++) free (s[i]);
    for(i=0;i<m;i++) free (neww[i]);
    free(s); free(neww);
    printf("work finished with exit code 0\n");
   }
 }
return errin+errout1+errout2;
}
