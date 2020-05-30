
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 void Merge(int *a1,int n1,int *a2,int n2,int *r)
 {int i1,i2,i;
 for(i1=0,i2=0,i=0;i1<n1&&i2<n2;)
 if(a1[i1]<a2[i2])
 r[i++]=a1[i1++];
 else
 r[i++]=a2[i2++];
 while(i1<n1)r[i++]=a1[i1++];
 while(i2<n2)r[i++]=a2[i2++];
 }
 
 void MSort(int *m,int n,int *t)
 {int n1,n2;
 if(n<=1)return;
 n1=n/2;n2=n-n1;
 MSort(m,n1,t);
 MSort(m+n1,n2,t);
 Merge(m,n1,m+n1,n2,t);
 memcpy(m,t,n*sizeof(int));
 }
#define SWAP(a,b) {tt=(a); (a)=(b); (b)=tt;}
 
 void BSort(int *m,int n)
 {int i,j,tt;
 for(i=n-1;i>0;i--)
 for(j=0;j<i;j++)
 if(m[j]>m[j+1])SWAP(m[j],m[j+1]);
 }
 
 void MSort2(int *m,int n,int *t)
 {int i,k,k2,tt;
 k=1;
 {//m+i,k,m+i+k,k
 for(i=0,k2=k;i+1<n;i+=2)
 if(m[i]>m[i+1])SWAP(m[i],m[i+1]);
 }
 for(k=2;k<n;k*=2)
 {//m+i,k,m+i+k,k
 for(i=0,k2=k;i+k<n;i+=2*k)
 {
 if(n-i-k<k2)k2=n-i-k;
 Merge(m+i,k,m+i+k,k2,t);
 memcpy(m+i,t,(k+k2)*sizeof(int));
 }
 }
 }
 
 void MSortX(int *m,int n,int *t)
 {int n1,n2,n3,n4;
 if(n<=1)return;
 n1=n/2;n3=n-n1;
 n2=n1/2;n1=n1-n2;
 n4=n3/2;n3=n3-n4;
#pragma omp parallel sections
 {
#pragma omp section
 {MSort(m,n1,t);}
#pragma omp section
 {MSort(m+n1,n2,t+n1);}
#pragma omp section
 {MSort(m+n1+n2,n3,t+n1+n2);}
#pragma omp section
 {MSort(m+n1+n2+n3,n4,t+n1+n2+n3);}
 }
#pragma omp parallel sections

 {
#pragma omp section
 {Merge(m,n1,m+n1,n2,t);memcpy(m,t,(n1+n2)*sizeof(int));}
#pragma omp section
 {Merge(m+n1+n2,n3,m+n1+n2+n3,n4,t+n1+n2);memcpy(m+n1+n2,t+n1+n2,(n3+n4)*sizeof(int));}
 }
 Merge(m,n1+n2,m+n1+n2,n3+n4,t);
 memcpy(m,t,n*sizeof(int));
 }
 
 void MSort2X(int *m,int n,int *t)
 {int i,k,k2,tt;
 k=1;
 {//m+i,k,m+i+k,k
#pragma omp parallel for private(tt)
 for(i=0;i<n-1;i+=2)
 if(m[i]>m[i+1])SWAP(m[i],m[i+1]);
 }
 for(k=2;k<n;k*=2)
 {//m+i,k,m+i+k,k
#pragma omp parallel for private(k2)
 for(i=0;i<n-k;i+=2*k)
 {
 k2=k;
 if(n-i-k<k2)k2=n-i-k;
 Merge(m+i,k,m+i+k,k2,t+i);
 memcpy(m+i,t+i,(k+k2)*sizeof(int));
 }
 }
 }
 
#undef SWAP
#define SWAP(a,b,tt) {tt=(a); (a)=(b); (b)=tt;}
 
 void QSort1(int *m,int p,int q)
 {int i,j,tt;
 if(p>=q)return;
 i=p;j=q;//M=m[j], [p,i-1]<=M<=[j,q]
 while(1)
 {
 while(m[i]<m[j])i++;//M=m[j], [p,i-1]<=M<=[j,q]
 SWAP(m[i],m[j],tt);//M=m[i], [p,i]<=M<=[j,q]
 j--;//M=m[i], [p,i]<=M<=[j+1,q]
 if(i>=j)
 {
 //i==j:
// [p,j]<=M<=[j+1,q] OSTAVITb
 //i==j+1: [p,j]<=M<=[j+1,q]
 QSort1(m,p,j);QSort1(m,j+1,q);return;
 }
 while(m[i]<m[j])j--;//M=m[i], [p,i]<=M<=[j+1,q]
 SWAP(m[i],m[j],tt);//M=m[j], [p,i]<=M<=[j,q]
 i++;//M=m[j], [p,i-1]<=M<=[j,q]
 if(i>=j)
 {
 //i==j (M=m[i]): [p,j]<=M<=[j+1,q]
 //i==j+1:



//[p,j]<=M<=[j+1,q] OSTAVITb
 QSort1(m,p,j);QSort1(m,j+1,q);return;
 }
 }
 }
 
 int QSort1_(int *m,int p,int q)
 {int i,j,tt;
 if(p>=q)return p;
 i=p;j=q;//M=m[j], [p,i-1]<=M<=[j,q]
 while(1)
 {
 while(m[i]<m[j])i++;//M=m[j], [p,i-1]<=M<=[j,q]

 SWAP(m[i],m[j],tt);//M=m[i], [p,i]<=M<=[j,q]
 j--;//M=m[i], [p,i]<=M<=[j+1,q]
 if(i>=j)
 {
 //i==j:
// [p,j]<=M<=[j+1,q] OSTAVITb
 //i==j+1: [p,j]<=M<=[j+1,q]
 return j;
 }
 while(m[i]<m[j])j--;//M=m[i], [p,i]<=M<=[j+1,q]
 SWAP(m[i],m[j],tt);//M=m[j], [p,i]<=M<=[j,q]
 i++;//M=m[j], [p,i-1]<=M<=[j,q]
 if(i>=j)
 {
 //i==j (M=m[i]): [p,j]<=M<=[j+1,q]
 //i==j+1:



//[p,j]<=M<=[j+1,q] OSTAVITb
 return j;
 }
 }
 }
 
 void QSort1X(int *m,int n)
 {int j[9]={-1,0,0,0,0,0,0,0,n-1},i;//{j[k]+1,j[k]}
 j[4]=QSort1_(m,0,n-1);
#pragma omp parallel sections
 {
#pragma omp section
 {j[2]=QSort1_(m,0,j[4]);}
#pragma omp section
 {j[6]=QSort1_(m,j[4]+1,j[8]);}
 }
#pragma omp parallel sections
 {
#pragma omp section
 {j[1]=QSort1_(m,0,j[2]);}
#pragma omp section
 {j[3]=QSort1_(m,j[2]+1,j[4]);}
#pragma omp section
 {j[5]=QSort1_(m,j[4]+1,j[6]);}
#pragma omp section
 {j[7]=QSort1_(m,j[6]+1,j[8]);}
 }
#pragma omp parallel for
 for(i=0;i<8;i++)
 QSort1(m,j[i]+1,j[i+1]);
 }
 
 void QSort2(int *m,int p,int q)
 {int i,j,M,tt;
 l1:
 if(p>=q)return;
 if(q-p>20)
 {
 i=p+rand()%(q-p+1);
 SWAP(m[p],m[i],tt);
 }
 i=p;j=q;M=m[i];//[p,i-1]<=M<=[j+1,q]
 while(1)
 {
 while(m[i]<M)i++;//[p,i-1]<=M<=[j+1,q]
 while(M<m[j])j--;//[p,i-1]<=M<=[j+1,q]
 if(i>=j)
 {
 //i==j (M=m[i]): [p,j]<=[j+1,q]
 //i==j+1:



//[p,j]<=[j+1,q] OSTAVITb
 if(q-j>j-p)
 {
 QSort2(m,p,j);
 p=j+1;
 goto l1;

 }
 else
 {
 QSort2(m,j+1,q);
 q=j;
 goto l1;
 }
 //return;
 }
 SWAP(m[i],m[j],tt);//[p,i]<=M<=[j,q]
 i++;j--;//[p,i-1]<=M<=[j+1,q]
 }
 }
 
 void QSort2X(int *m,int n)
 {int j[9]={-1,0,0,0,0,0,0,0,n-1},i;//{j[k]+1,j[k]}
 j[4]=QSort1_(m,0,n-1);
#pragma omp parallel sections
 {
#pragma omp section
 {j[2]=QSort1_(m,0,j[4]);}
#pragma omp section
 {j[6]=QSort1_(m,j[4]+1,j[8]);}
 }
#pragma omp parallel sections
 {
#pragma omp section
 {j[1]=QSort1_(m,0,j[2]);}
#pragma omp section
 {j[3]=QSort1_(m,j[2]+1,j[4]);}
#pragma omp section
 {j[5]=QSort1_(m,j[4]+1,j[6]);}
#pragma omp section
 {j[7]=QSort1_(m,j[6]+1,j[8]);}
 }
#pragma omp parallel for
 for(i=0;i<8;i++)
 QSort2(m,j[i]+1,j[i+1]);
 }
 
#define c m[i]
#define l m[2*i+1]
#define r m[2*i+2]
#define HasR (2*i+2<n)
#define HasL (2*i+1<n)
 
 void Heapify(int *m,int i,int n)
 {int tt;
 while(HasR)
 {
 if(c>=l&&c>=r)return;
 if(l>r){SWAP(c,l,tt);i=2*i+1;}
 else{SWAP(c,r,tt);i=2*i+2;}
 }
 if(HasL&&l>c)SWAP(l,c,tt);
 }
 
#undef c
#undef l
#undef r
#undef HasR
#undef HasL
 
 void HSort(int *m,int n)
 {int i,tt;
 for(i=n-1;i>=0;i--)Heapify(m,i,n);//
 for(n--;n>0;n--){SWAP(m[0],m[n],tt);Heapify(m,0,n);}//
 }
 

 void CSort(int *m,int n,int *b,int B,int *r)
 {int i;
 memset(b,0,(B+1)*sizeof(int));
 for(i=0;i<n;i++)b[m[i]]++;
 for(i=1;i<=B;i++)b[i]+=b[i-1];
 for(i=n-1;i>=0;i--)r[--b[m[i]]]=m[i];
 }
 
 void DSort(int *m_,int n,int *b,int B,int *r)
 {int i;typedef union US2I_ {unsigned int i;unsigned short int s[2];}US2I;
 US2I*m=(US2I*)m_;
 memset(b,0,(B+1)*sizeof(int));
 for(i=0;i<n;i++)b[m[i].s[0]]++;
 for(i=1;i<=B;i++)b[i]+=b[i-1];
 for(i=n-1;i>=0;i--)r[--b[m[i].s[0]]]=m[i].i;
 //
 memcpy(m,r,n*sizeof(int));
 //
 memset(b,0,(B+1)*sizeof(int));
 for(i=0;i<n;i++)b[m[i].s[1]]++;
 for(i=1;i<=B;i++)b[i]+=b[i-1];
 for(i=n-1;i>=0;i--)r[--b[m[i].s[1]]]=m[i].i;
 }
 
 int main(void)
 {int *a0=NULL,*a=NULL,*b=NULL,*t=NULL,*b_=NULL,n=1000*1000*10,N=1,i;time_t t0,t1;
 a0=(int*)malloc(n*sizeof(int));
 a=(int*)malloc(n*sizeof(int));
 b=(int*)malloc(n*sizeof(int));
 b_=(int*)malloc(n*sizeof(int));
 t=(int*)malloc(n*sizeof(int));
 for(i=0;i<n;i++)a0[i]=((rand()+(rand()<<15))%n)&(~(1<<31));//0...RAND_MAX
 //--
 if(0)
 {
 time(&t0);
 for(i=0;i<N;i++)
 {
 memcpy(a,a0,n*sizeof(int));
 BSort(a,n);
 }
 time(&t1);
 printf("BSort:dtime=%d\n",(int)(t1-t0));
 for(i=1;i<n;i++)if(a[i-1]>a[i])printf("Error1: i=%d\n",i);
 }
 //--
 time(&t0);
 for(i=0;i<N;i++)
 {
 memcpy(a,a0,n*sizeof(int));
 MSort(a,n,t);
 }
 time(&t1);
 printf("MSort:dtime=%d\n",(int)(t1-t0));
 for(i=1;i<n;i++)if(a[i-1]>a[i])printf("Error1: i=%d\n",i);
 //--
 if(1){
 time(&t0);
 for(i=0;i<N;i++)
 {
 memcpy(b,a0,n*sizeof(int));
 MSort2(b,n,t);
 }
 time(&t1);
 printf("MSort2:dtime=%d\n",(int)(t1-t0));
 for(i=0;i<n;i++)if(b[i]!=a[i])printf("Error2: i=%d\n",i);
 }
 //--
 if(1){

 time(&t0);
 for(i=0;i<N;i++)
 {
 memcpy(b,a0,n*sizeof(int));
 MSortX(b,n,t);
 }
 time(&t1);
 printf("MSortX:dtime=%d\n",(int)(t1-t0));
 for(i=0;i<n;i++)if(b[i]!=a[i])printf("ErrorX: i=%d\n",i);
 }
 //--
 if(1){
 time(&t0);
 for(i=0;i<N;i++)
 {
 memcpy(b,a0,n*sizeof(int));
 MSort2X(b,n,t);
 }
 time(&t1);
 printf("MSort2X:dtime=%d\n",(int)(t1-t0));
 for(i=0;i<n;i++)if(b[i]!=a[i])printf("Error2X: i=%d\n",i);
 }
 //--
 if(1){
 time(&t0);
 for(i=0;i<N;i++)
 {
 memcpy(b,a0,n*sizeof(int));
 QSort1(b,0,n-1);
 }
 time(&t1);
 printf("QSort1:dtime=%d\n",(int)(t1-t0));
 for(i=0;i<n;i++)if(b[i]!=a[i])printf("ErrorQ1: i=%d\n",i);
 }
 //--
 if(1){
 time(&t0);
 for(i=0;i<N;i++)
 {
 memcpy(b,a0,n*sizeof(int));
 QSort1X(b,n);
 }
 time(&t1);
 printf("QSort1X:dtime=%d\n",(int)(t1-t0));
 for(i=0;i<n;i++)if(b[i]!=a[i])printf("ErrorQ1X: i=%d\n",i);
 }
 //--
 if(1){
 time(&t0);
 for(i=0;i<N;i++)
 {
 memcpy(b,a0,n*sizeof(int));
 QSort2(b,0,n-1);
 }
 time(&t1);
 printf("QSort2:dtime=%d\n",(int)(t1-t0));
 for(i=0;i<n;i++)if(b[i]!=a[i])printf("ErrorQ2: i=%d\n",i);
 }
 //--
 if(1){
 time(&t0);
 for(i=0;i<N;i++)
 {
 memcpy(b,a0,n*sizeof(int));
 QSort2X(b,n);
 }
 time(&t1);
 printf("QSort2X:dtime=%d\n",(int)(t1-t0));
 for(i=0;i<n;i++)if(b[i]!=a[i])printf("ErrorQ2X: i=%d\n",i);

 }
 //--
 if(1){
 time(&t0);
 for(i=0;i<N;i++)
 {
 memcpy(b,a0,n*sizeof(int));
 HSort(b,n);
 }
 time(&t1);
 printf("HSort:dtime=%d\n",(int)(t1-t0));
 for(i=0;i<n;i++)if(b[i]!=a[i])printf("HSort: i=%d\n",i);
 }
 //--
 if(0){
 time(&t0);
 for(i=0;i<N;i++)
 {
 memcpy(b_,a0,n*sizeof(int));
 CSort(b_,n,t,1<<16,b);
 }
 time(&t1);
 printf("CSort:dtime=%d\n",(int)(t1-t0));
 for(i=0;i<n;i++)if(b[i]!=a[i]){printf("CSort: i=%d\n",i);break;}
 }
 //--
 if(1){
 time(&t0);
 for(i=0;i<N;i++)
 {
 memcpy(b_,a0,n*sizeof(int));
 DSort(b_,n,t,1<<16,b);
 }
 time(&t1);
 printf("DSort:dtime=%d\n",(int)(t1-t0));
 for(i=0;i<n;i++)if(b[i]!=a[i]){printf("DSort: i=%d\n",i);break;}
 }
 //--
 free(a);a=NULL;free(a0);a0=NULL;free(b);b=NULL;free(t);t=NULL;free(b_);b_=NULL;
 printf("done\n");
 return 0;
 }