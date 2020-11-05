#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "fun.h"

int main(void) 
{
  int res = 0, err;
  err = Find("data.txt", &res);
  if (err == -1)
    printf("error\n");
  else  printf("maximum: %d\n", res);
  return 0;
}
