#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "fun.h"

int main(void) 
{
  int err1, err2, size, *array = NULL, i, j;
  err1 = read("data.txt", &array, &size);
  if (err1 != 0)
   {
   printf("error 1\n");
   }
  else printf("input:\n");
   {
   for (i=0; i<size; i++)
   printf("%d ", array[i]);
   printf("\n");
   }
  sort(array, size);
  err2 = check(array, size);
  if (err2 != 0)
    printf("error 2\n");
  else printf("output:\n");
   for (j=0; j<size; j++)
   printf("%d ", array[j]);
   printf("\n");
  if(array)free(array);
  array = NULL;
  return err2;
}
