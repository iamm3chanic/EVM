#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fun.h"

void heapify(int *arr, int size, int i)
{
 int largest,left,right,t;
 largest=i;
 left = 2*i + 1;
 right = 2*i + 2;
   //printf("hereeeeeeeee\n");
 if (left < size && arr[left] > arr[largest])
  largest=left;
 if (right < size && arr[right] > arr[largest])
  largest=right;
 if (largest != i)
  {
  t=arr[i];
  arr[i]=arr[largest];
  arr[largest]=t;
  heapify(arr, size, largest);
  }
 //
}
/*
void heapify(int arr[], int n, int i)
{
    int largest = i;   
// Инициализируем наибольший элемент как корень
    int l = 2*i + 1; // левый = 2*i + 1
    int r = 2*i + 2; // правый = 2*i + 2

 // Если левый дочерний элемент больше корня
    if (l < n && arr[l] > arr[largest])
        largest = l;

   // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(arr, n, largest);
    }
}*/
