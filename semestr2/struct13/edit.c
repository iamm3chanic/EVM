#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "fun.h"

void edit(SStudent **s, SStudent ***great, int n)
{
 int i,j,dif,b,m;
 char u[256]="----------------------";
 SStudent t;
 dif=n/10;
 m=n+2;
 *great=(SStudent**)malloc((m)*sizeof(**great));
 for(j=0;j<(m);j++) (*great)[j]=(SStudent*)malloc(sizeof(***great));
 printf("dif=%d\n",dif);
 printf("n=%d\n",n);
 printf("m=%d\n",m);
  for(i=0; (i<dif); i++)
  memcpy((*great)[i],(s)[i],sizeof(**s));
  for(i=dif+1; i<(m-dif-1); i++)
  memcpy((*great)[i],(s)[i-1],sizeof(**s));
  for(i=m-dif; i<m; i++)
  memcpy((*great)[i],(s)[i-2],sizeof(**s));
  strcpy(((*great)[dif])->name, u);
  strcpy(((*great)[m-dif-1])->name, u);
  (*great)[dif]->group=0;
  (*great)[dif]->rating=0.0;
  (*great)[m-dif-1]->group=0;
  (*great)[m-dif-1]->rating=0.0;
}