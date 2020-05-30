#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fun.h"

void edit(int **mat, int *str, int *strlen)
{
 int  i=0, j=0, b,s,p,maxlen,k, *tmp1=NULL, *tmp2=NULL;
 if((*str)>1)
 {
  //naydem mega dlinnuyu stroku
    for(i=1,maxlen=strlen[0]; i<(*str); i++)
    { if (strlen[i]>maxlen) maxlen=strlen[i];  }
    
   tmp1=(int*) malloc((maxlen+1) * sizeof(int));
   tmp2=(int*) malloc((maxlen+1) * sizeof(int));
   
    
   for(j=0;j<maxlen;j++)
    {
     for(i=0, s=0;i<(*str);i++)if(j<=strlen[i])
     {
      s+=(mat[i][j]); 
     }                         //summa eltov stolbca
     tmp1[j]=s;
    }
    
   for(j=0;j<maxlen;j++)
    {
     (tmp2[j])=0;                        //sozd massiv nuley
    }
   for(i=0;i<(*str);i++)
    {
    	for(j=0;j<strlen[i];j++)
    	{
    	 (tmp2[j])++;
    	}                          //stolko ne dyr v kagdom stolbce
    }
    
   lk:
   for(i=0;i<(*str); i++)
   {
     for(j=0, b=0; j<strlen[i]; j++)
     {
      if( (mat[i][j])*(tmp2[j])==(tmp1[j]) ) b++;
     }                                              //sred arifm
     if(b==strlen[i])     
      {
         for(k=i; k<(*str-1); k++)
         {
             mat[k]=mat[k+1];
         }                               //udalyaem stroku
        	 (*str)--;
        	 for(p=0;p<strlen[i];p++)
        	 (tmp2[p])--;
        	 for(p=0;p<strlen[i];p++)
        	 {(tmp1[p])-=(mat[i][p]);}
        	 for(p=i;p<(*str)-1;p++)
        	 strlen[p]=strlen[p+1];
        	 b=0;
        	 goto lk;
      }
   }
   
   free(tmp1); tmp1=NULL; 
   free(tmp2); tmp2=NULL; 
 }
}
