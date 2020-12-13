#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "fun.h"
#define SWAP(a,b,tt) {strcpy(tt,a); strcpy(a,b);strcpy(b,tt);}


int cmpfunc (const void * left, const void * right) {
	int wordlen;
	char *l = *(char **) left;
        char *r = *(char **) right;
        wordlen=(strlen(l)<strlen(r)) ? strlen(l) : strlen(r);
        //l += posofword;
        //r += posofword;
        return strncmp(l, r, wordlen);
}

void QSort1(char **strings, int size) 
{
   int n;

   printf("Before sorting the list is: \n");
   for( n = 0 ; n < size; n++ ) {
      printf("%s ", strings[n]);
   }

   qsort(strings, size, sizeof(char*), cmpfunc);

   printf("\nAfter sorting the list is: \n");
   for( n = 0 ; n < size; n++ ) {   
      printf("%s ", strings[n]);
   }
   printf("\n");
  
}

