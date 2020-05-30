#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "fun.h"
#include "str.h"

void output2(SStudent **s, int n)
{
  int i=0,j;
  for(i=0;i<n;i++)
  {
   printf("%d %s %f\n", (s[i])->group, (s[i])->name, (s[i])->rating);
  }
}
