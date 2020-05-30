#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "fun.h"

void sort(SStudent **s, int n)
{
 int i,j;
 SStudent t;
 for(i=0; i<n-1; i++) 
  for(j=0; j<n-1; j++)
  if ((((s)[j])->rating) > (((s)[j+1])->rating))
  {
   memcpy(&t,(s)[j],sizeof(**s));
   memcpy((s)[j],(s)[j+1],sizeof(**s));
   memcpy((s)[j+1],(&t),sizeof(**s));
  }
}