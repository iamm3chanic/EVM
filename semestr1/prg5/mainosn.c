#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "fun.h"

int main(void) 
{
  int err1, err, size, *array = NULL, i;
  err = Input("data.txt", &array, &size);
  if (err != 0)
  {
    printf("error\n");
  }
  else 
  {
   for (i = 0; i < size; i++)
     printf("%d ", array[i]);
   printf("\n");
   err1 = Sdvig(array, size);
    if (err1 != 0)
      printf("error 2\n");
    else
      for (i = 0; i < size; i++)
        printf("%d ", array[i]);
  }
  printf("\n");
  if(array)free(array);
  array = NULL;
  return err1;
}
