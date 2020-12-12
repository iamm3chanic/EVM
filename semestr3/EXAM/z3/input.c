#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fun.h"

int Input(const char *fn, char ***s, int *n)
{
 FILE *f;
 int i,err;//,t;//,i,err,r,m=0,c=0,t;
 //float sh;
 char str[256],u[256];//,*ss,sss[512],k[256],*p,*o,u[512],*uu,*oo,*pp;
 f=fopen(fn,"r");
 if(f==NULL){err=-1;goto lm;}//not found
 else{
 if(fgets(str,256,f)==NULL) {err=-2; goto lc;}//empty file
 else{
 rewind(f);
 //if(sscanf(str,"%d",&t)!=1) {err=-3; goto lc;}//empty file2
 
 //else
 //{
  rewind(f);
  for(*n=0;fgets(str,256,f)!=NULL&&sscanf(str,"%s",u)==1;(*n)++)
  {}printf("n=%d\n",*n);
  *s=(char**)malloc((*n+1)*sizeof(char**));
  for(i=0;i<(*n);i++) (*s)[i]=(char*)malloc(256*sizeof(char));
  rewind(f);
  for(*n=0;fgets(str,256,f)!=NULL&&sscanf(str,"%s",(*s)[*n])==1;(*n)++)
  {
   //printf("name=%s\n",(*s)[*n]);
  }
  err=0;
 }}//}
 lc:
 fclose(f);
 lm:
 return err;
}
/*int Input(const char *filename, char (**array)[256], int *size) 
{
  int i;
  FILE *file;
  file = fopen(filename, "r");
  if (file == NULL)
    return -1;
  if (fscanf(file, "%d", size) != 1) 
  {
    fclose(file);
    return -2;
  }
  // *array = (float*) malloc(*size * sizeof(float));
  *(array )= (char**) malloc(*size * sizeof(char*)*256);
  if (*array == NULL) 
  {
    fclose(file);
    return -3;
  }
  for (i = 0; i < *size; i++)
    if (fscanf(file, "%s", (**array) + i) != 1) 
    {
      free(*array);
      fclose(file);
      return -4;
    }
  fclose(file);
  return 0;
}*/
