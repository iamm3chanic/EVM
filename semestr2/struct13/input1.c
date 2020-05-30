#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "fun.h"
#include "str.h"

int input1(const char *fn, SStudent ***s, int *n)
{
 FILE *f;
 int l,i,err,r,m=0,c=0,t;
 float sh;
 char str[512],*ss,sss[512],k[256],*p,*o,u[512],*uu,*oo,*pp;
 f=fopen(fn,"r");
 if(f==NULL){err=-1;goto lm;}//not found
 else{
 if(fgets(str,512,f)==NULL) {err=-2; goto lc;}//empty file
 else{
 if(sscanf(str,"%d",&t)!=1) {err=-3; goto lc;}//empty file2
 
 else
 {
  rewind(f);
  for(*n=0;fgets(str,512,f)!=NULL&&sscanf(str,"%d %s %f",&r,u,&sh)==3;(*n)++)
  {}//printf("n=%ld\n",*n);
  *s=(SStudent**)malloc((*n)*sizeof(**s));
  for(i=0;i<(*n);i++) (*s)[i]=(SStudent*)malloc(sizeof(***s));
  rewind(f);
  for(*n=0;fgets(str,512,f)!=NULL&&sscanf(str,"%d %s %f",&((*s)[*n]->group),(*s)[*n]->name,&((*s)[*n]->rating))==3;(*n)++)
  {
//   printf("name=%s\n",(*s)[*n]->name);
  }
  err=0;
 }}}
 lc:
 fclose(f);
 lm:
 return err;
}
