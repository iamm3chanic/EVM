#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "fun.h"

void edit(SStudent **s, SStudent ***neww, int n, int *m)
{
 int i,j,dif,b,proc;
 SStudent t;
 printf("Input procent of students to delete:\n");
 scanf("%d",&proc);
 *m=n*(100-proc)/100;
 *neww=(SStudent**)malloc((*m)*sizeof(**neww));
 for(j=0;j<(*m);j++) (*neww)[j]=(SStudent*)malloc(sizeof(***neww));
  
  for(i=n-*m,j=0; (i<n)&&(j<*m); i++,j++)
  memcpy((*neww)[j],(s)[i],sizeof(**s));
}