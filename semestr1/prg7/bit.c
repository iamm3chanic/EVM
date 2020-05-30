#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) 
{
  int a, bit, i;
  scanf("%d", &a);
  scanf("%d", &i);
  scanf("%d", &bit);
  if (bit==0) 
  {
   a=a&~(1<<i);
  }
  else if (bit==1)
  {
   a=a|(1<<i);
  }
  printf("%d ", a);
  printf("\n");
  return 0;
}