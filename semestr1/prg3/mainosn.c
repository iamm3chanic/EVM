#include <stdio.h>
#include <stdlib.h>
#include "fun.h"

int main(void) 
{
 int res,err;
 err= Find("data.txt", &res);
 if(err==-1) printf ("error\n");
 else
 {
  if(res==0) printf ("noooooo\n");
  if(res==1) printf ("yeeeees\n");
 }
 return 0;
}
