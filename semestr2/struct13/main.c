#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "fun.h"
#include "str.h"

int main(void)
{
 int errin=0,errout=0,n,i=0;
 SStudent **s, **great;
 errin=input1("data.dat", &s,&n);
 printf("checked errin=%d\n",errin);
 if(errin==-1)printf("infile not found\n");
 if(errin==-2)printf("empty file1\n");
 if(errin==-3)printf("empty file2\n");
 else if(errin==0)
 {
  errout=output1("data.res", s,n);
  printf("checked errout=%d\n",errout);
  if (errout==-1) 
   {printf("outfile not found\n"); for(i=0;i<n;i++) free (s[i]); free(s);}
  else
   {
    sort(s,n);
    edit(s,&great,n);
    output2(great,(n+2));
    output1("data.res", great,(n+2));
    for(i=0;i<n;i++) free (s[i]);
    for(i=0;i<n+2;i++) free (great[i]);
    free(s); free(great);
    printf("work finished with exit code 0\n");
   }
 }
return errin+errout;
}
