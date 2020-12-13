/*
Написать программу на языке С, которая вводит все слова, разделенные пробелами, табуляциями и 
переходами на следующую строчку, из файла http://lectures.stargeo.ru/tO.txt в массив строк 
(строки длиной не более 256 символов), лексикографически сортирует массив строк методом быстрой 
сортировки QSort и выводит полученный массив в файл ./t0.txt по одной строке в строку файла. 
Можно использовать любую собственную реализацию алгоритма QSort.
ПОКА НЕ ДО КОНЦА*/
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "fun.h"

int main(void) 
{
  int err, size, i,p=0;
  //char *(array[256]) ;//= NULL;
  char **array;
  err = Input("data.txt", &(array), &size);
  if (err != 0)
  {
    printf("error = %d\n",err);
  }
  else 
  {
   printf("it was: \n");
   for (i = 0; i < size; i++)
     printf("%s\n", array[i]);
   printf("\n");
   QSort1(array,p,size-1);
    //if (err1 != 0)
     // printf("error 2\n");
   // else
   printf("it is: \n");
      for (i = 0; i < size; i++)
        printf("%s\n", array[i]);
  }
  printf("\n");
  for(i=0;i<size;i++) {if(array[i])free(array[i]);}
  if(array)free(array);
  //array = NULL;
  return err;
}
