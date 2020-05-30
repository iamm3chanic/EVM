#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "fun.h"

int search(const char* fn, char* minword)
{
 int err=0, i, l;
 unsigned int minlen;
 char str[512], word[512], *begin;
 FILE *f; 
 f=fopen(fn, "r");
 if(f==NULL) err=-1;
 else
 {
  for(minword[512]='\0', minlen=512; fgets(str, 512, f)!=NULL; )
  {
   for(begin=str; sscanf(begin, "%s%n", word, &l)==1; begin+=l) //reads word
   {
    for(i=0; i<l-1; i++)
     if(word[i]<'A' || word[i]>'Z') goto lc; //engish huge letter
    if(word[0]=='A') //begins with A
    {
     if(strlen(word)<minlen)
     { strcpy(minword, word); minlen=strlen(word); } //min dlina
    }
    lc:;
   }
  }
  fclose(f);
 }
 return err;
}