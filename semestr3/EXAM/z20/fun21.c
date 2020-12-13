#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "fun.h"
#define SWAP(a,b,tt) {strcpy(tt,a); strcpy(a,b);strcpy(b,tt);}

void QSort1(char **strings, int left, int right) 
{
   if(left<0||right>256) return; //правая граница не проверяется без передачи в функцию
    int i, j, p;
    i=left; 
    j=right;   
    char tt[256];
       //for(i=0;i<3;i++)  printf("%s\n",strings[i]);
    while (i!=j){
    //printf("---%s\t---",strings[i]); printf("\n");
        if((strcmp((strings[i]),(strings)[j])>0)!=(i<j))
        {        
            SWAP(strings[i],strings[j],tt);
            
            p=i;    
            i=j;        
          
            if (p<j)    
                j=p+1;
            else j=p-1;
        }
        else
        {
            if (i<j) j--; 
            else j++;
        };
    };
    
    if (left<i-1)
        QSort1(strings,left,i-1);
    if (i+1<right) 
        QSort1(strings,i+1,right);
}
/*int QSort1(char **m,int p,int q)
 {char* tt=NULL; int i,j;
 if(p>=q)return p;
 i=p;j=q;//M=m[j], [p,i-1]<=M<=[j,q]
 while(1)
 {
 while((m[i]<m[j])&&(i<q))i++;//M=m[j], [p,i-1]<=M<=[j,q]

 SWAP(m[i],m[j],tt);//M=m[i], [p,i]<=M<=[j,q]
 j--;//M=m[i], [p,i]<=M<=[j+1,q]
 if(i>=j)
 {
 return j;
 }
 while(m[i]<m[j])j--;//M=m[i], [p,i]<=M<=[j+1,q]
 SWAP(m[i],m[j],tt);//M=m[j], [p,i]<=M<=[j,q]
 i++;//M=m[j], [p,i-1]<=M<=[j,q]
 if(i>=j)
 {
 return j;
 }
 }
 }*/
