#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fun.h"

void sortheap(int *arr, int size, int i)
{
 int largest,left,right,t;
 largest=i;
 left = 2*i + 1;
 right = 2*i + 2;
 if (left < size && arr[left] > arr[largest])
  largest=left;
 if (right < size && arr[right] > arr[largest])
  largest=right;
 if (largest != i)
  {
  t=arr[i];
  arr[i]=arr[largest];
  arr[largest]=t;
  }
 sortheap(arr, size, largest);
}