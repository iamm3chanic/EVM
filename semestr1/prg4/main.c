#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "fun.h"

int main(void) 
{
  int err1, err, size, *array = NULL, i, res = 0;
  err = Input("data.txt", &array, &size);
/* 
     for (i = 0; i < size; i++)
    printf("%d ", array[i]);
    printf("\n");
*/
//  err1 = Sdvig(array, size, &res);
  if (err != 0)
  {
    printf("error\n");
  }    
  else 
  {
    for (i = 0; i < size; i++)
    {
    printf("%d ", array[i]);
    printf("\n");
    }
    err1 = Sdvig(array, size, &res);
    if (err1 != 0)
      printf("error 2\n");
    else
      printf("number of the max element: %d", res);
  }
  printf("\n");
  free(array);
  array = NULL;
  return err1;
}
