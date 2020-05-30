#include <stdio.h>
#include <stdlib.h>
#include "fun.h"

int main(void)
{
 int err=0,res;
 err=Find( "data.txt", &res);
 if(err!=0)
  printf("Error!!!\n");
 else
 {
  if (res==0) printf("more");
  if (res==1) printf("less");
  if (res==2) printf("equal");
  printf(" than previous");
 } 
return err;
}
