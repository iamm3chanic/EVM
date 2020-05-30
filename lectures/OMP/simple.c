#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <time.h>

int main(void)

{
 int N=1000*100,n2=30;
 int i,*a,*b,*c; time_t t1,t2;
 
 a=(int*)malloc(N*sizeof(int));
 b=(int*)malloc(N*sizeof(int));
 c=(int*)malloc(N*sizeof(int));
 
 for(i=0;i<N;i++)
 {a[i]=i;b[i]=i;}

 printf("1 passed\n");

 time(&t1);

 for(int I=0;I<n2;I++)
 {
#pragma omp parallel for
 for(i=0;i<N;i++)
  a[i]=(int)(sqrt(b[i]*1.)*sqrt(1.*c[i]));
 }
 time(&t2);
 printf("2 time:%d\n",(int)(t2-t1));
 time(&t1);
 for(int I=0;I<n2;I++)
 {
 for(i=0;i<N;i++)
  a[i]=(int)(sqrt(b[i]*1.)*sqrt(1.*c[i]));
 }

 time(&t2);
 printf("3 time:%d\n",(int)(t2-t1));
 free(a);free(b);free(c);
 return 0;
}
