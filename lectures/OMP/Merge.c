#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SWAP(a,b) {tt=(a); (a)=(b); (b)=tt;}

void Merge(int *a1,int n1, int *a2,int n2, int *r)
{ 
 int i1,i2,i;
 for (i1=0, i2=0, i=0;i1<n1&&i2<n2;)
 if (a1[i1]<a2[i2])r[i++]=a1[i1++];
 else r[i++]=a2[i2++];
 while(i1<n1) r[i++]=a1[i1++];
 while(i2<n2) r[i++]=a2[i2++];
}

void MSort(int *m,int n,int *t)
{
 int n1,n2,i;
 if(n<=1)return;
 n1=n/2; n2=n-n1;
 MSort (m,n1,t);
 MSort(m+n1,n2,t);
 Merge(m,n1,m+n1,n2,t);
 memcpy (m,t,n*sizeof(int));
}

void MSort2(int *m,int n,int *t)
{
 int n1,n2,n3,n4;
 if (n<=1)return;
 n1=n/2; n3=n-n1;
 n2=n1/2; n1=n1-n2;
 n4=n3/2; n3=n3-n4;
#pragma omp parallel sections
 {
#pragma omp section
 {MSort(m,n1,t);}
#pragma omp section
 {MSort (m+n1,n2,t+n1);}
#pragma omp section
 {MSort (m+n1+n2,n3,t+n1+n2);}
#pragma omp section
 {MSort (m+n1+n2+n3,n4,t+n1+n2+n3);}
 }
#pragma omp parallel sections
 {
#pragma omp section
 {Merge(m,n1, m+n1,n2, t); memcpy(m,t, (n1+n2)*sizeof(int));}
#pragma omp section
{Merge(m+n1+n2,n3,m+n1+n2+n3,n4,t+n1+n2); memcpy(m+n1+n2, t+n1+n2, (n3+n4)*sizeof(int));}
 }
Merge(m,n1+n2, m+n1+n2,n3+n4,t);
memcpy(m,t,n*sizeof(int));
}
 
void MSort3(int *m,int n,int *t)
{
int k,k2,i,tt;
//for (k=1;k<n;k*=2)
k=1;
 {
 k2=k;
#pragma omp parallel for private(tt)
 for(i=0;i<n-1;i+=2)
  if(m[i]>m[i+1]) SWAP(m[i],m[i+1]);
 }
 for(k=2;k<n;k*=2)
 {
  k2=k;
#pragma omp parallel for private(k2)
 for(i=0;i<n-k;i+=2*k)
  {k2=k;
   if(n-i-k<k2)k2=n-i-k;
   Merge(m+i,k, m+i+k,k2,t+i);
   memcpy(m+i,t+i,(k+k2)*sizeof(int));
  }
 }
}

int main(void)
{
 int i,*a,*a0,*t,*b,n=100000; time_t t0,t1;
 a0=(int*)malloc(n*sizeof(int)); a=(int*)malloc(n*sizeof(int)); t=(int*)malloc(n*sizeof(int)); b=(int*)malloc(n*sizeof(int));
 for(i=0;i<n;i++)a0[i]=rand()%n;
//
 memcpy(b,a0,n*sizeof(int));
 time(&t0); MSort(b,n,t); time(&t1); printf("MSort:%d\n", (int)(t1-t0));
 for(i=1;i<n;i++) if(b[i]<b[i-1]) printf ("Err1:i=%d\n",i);
//
 memcpy(a,a0,n*sizeof(int));
 time(&t0); MSort3(a,n,t); time(&t1); printf("MSort3:%d\n", (int)(t1-t0));
 for(i=0;i<n;i++) if(a[i]!=b[i]) printf ("Err2:i=%d\n",i);
//
 memcpy(a,a0,n*sizeof(int));
 time(&t0); MSort2(a,n,t); time(&t1); printf("MSort2:%d\n", (int)(t1-t0));
 for(i=0;i<n;i++) if(a[i]!=b[i]) printf ("Err3:i=%d\n",i);
//
free(a0) ;a0=NULL; free(a); a=NULL; free(t); t=NULL; free(b); b=NULL;
printf("done\n");
return 0;
}
