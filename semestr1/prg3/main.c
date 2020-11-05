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
  if(res==0) printf ("no, it isn't a progression\n");
  if(res==1) printf ("yeeeees, it is a progression!\n");
 }
 return 0;
}
