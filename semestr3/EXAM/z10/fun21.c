#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "fun.h"
#define SWAP(a,b,tt) {strcpy(tt,a); strcpy(a,b); strcpy(b,tt);}

void QSort1(char **m, int p, int q) 
{
 char tt[256]; int i,j;
 if(p>=q)return ;
 i=p;j=q;//M=m[j], [p,i-1]<=M<=[j,q]
 while(1)
 {
 while(((strcmp((m[i]),(m)[j])>0)!=(i<j)/*m[i]<m[j]*/)&&(i<q))i++;
 //M=m[j], [p,i-1]<=M<=[j,q]
 if((strcmp((m[i]),(m)[j])!=0))
 {SWAP(m[i],m[j],tt);//M=m[i], [p,i]<=M<=[j,q]
 printf("SWAP\n");}
 j--;//M=m[i], [p,i]<=M<=[j+1,q]
 if(i>=j)
 {
 return ;
 }
 while((strcmp((m[i]),(m)[j])>0)!=(i<j)/*m[i]<m[j]*/)j--;
 //M=m[i], [p,i]<=M<=[j+1,q]
 
 SWAP(m[i],m[j],tt);//M=m[j], [p,i]<=M<=[j,q]
 
 i++;//M=m[j], [p,i-1]<=M<=[j,q]
 if(i>=j)
 {
 return ;
 }
 }
}

