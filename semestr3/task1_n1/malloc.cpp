#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "walloC.h"
//------------------------------------
#define NMEM 100000000
#define NMEMptr 100000
struct SMEM
{SMEM(){ptr=NULL;l=l0=0; sf[0]='\0'; iLine=0;} void *ptr; int l,l0;char sf[64]; int iLine;};
char MEM[NMEM];
SMEM MEMptr[NMEMptr]; int nMEMptr=0;
int WCheckMemCleaning(void);
//------------------------------------
void FAtExit(void)
{
WCheckMemCleaning();
}
//------------------------------------
class CTestMemClass
{public:
 CTestMemClass(){atexit(FAtExit);}
 ~CTestMemClass(){if(0)WCheckMemCleaning();}
};
CTestMemClass TestMemClass;
//------------------------------------
void *realloc(void *buf,size_t n) throw()
{
 void *p;int i,l0;
 int n0=n;
 n=(n+3)/4*4;
 if(buf==NULL)
  return malloc(n);
 for(i=0;i<nMEMptr;i++)
 {
  if(MEMptr[i].ptr==buf)
  {
   l0=MEMptr[i].l0;
   if(MEMptr[i].l>=(int)n)
   {
    MEMptr[i].l=n;
    MEMptr[i].l0=n0;
    return MEMptr[i].ptr;
   }
   else
   {
    p=malloc(n);
    memcpy(p,buf,l0);
    free(MEMptr[i].ptr);
    return p;
   }
  }
 }
 printf("Incorrect pointer in realloc().Can't reallocate memory.\n");
 return NULL;
}
//------------------------------------
void *calloc(size_t n,size_t size) throw()
{
 void *p;
 p=malloc(size*n);
 memset(p,0,size*n);
 return p;
}
//------------------------------------
void *malloc(size_t n) throw()
{void *ptr=MEM; int i;
 //printf("Malloc n=%d\n",(int)n);
 int n0=n;
 n=(n+3)/4*4;
 for(i=0;i<nMEMptr;i++)
 {
  if(MEMptr[i].ptr!=NULL && MEMptr[i].l>0)
  {
   if( (size_t)(((char*)(MEMptr[i].ptr))-(char*)ptr)>=n)
   {
    if(i>0&&MEMptr[i-1].ptr==NULL)
    {
     MEMptr[i-1].ptr=ptr;
     MEMptr[i-1].l=n;
     MEMptr[i-1].l0=n0;
     return ptr;
    }
    else
    {int j;
     for(j=nMEMptr;j>i;j--)
      MEMptr[j]=MEMptr[j-1];
     nMEMptr++;
     MEMptr[i].ptr=ptr;
     MEMptr[i].l=n;
     MEMptr[i].l0=n0;
     return ptr;
    }
   }
   else //if(MEMptr[i].ptr-ptr)>=n)
   {
    ptr=((char*)MEMptr[i].ptr)+MEMptr[i].l;
   }
  }
 }
 MEMptr[nMEMptr].ptr=ptr;
 MEMptr[nMEMptr].l=n;
 MEMptr[nMEMptr].l0=n0;
 nMEMptr++;
return ptr;
return NULL;
}

void *malloc(size_t n,const char *sf,int iLine) throw()
{void *ptr=MEM; int i;
 //printf("Malloc n=%d\n",(int)n);
 int n0=n;
 n=(n+3)/4*4;
 for(i=0;i<nMEMptr;i++)
 {
  if(MEMptr[i].ptr!=NULL && MEMptr[i].l>0)
  {
   if( (size_t)(((char*)(MEMptr[i].ptr))-(char*)ptr)>=n)
   {
    if(i>0&&MEMptr[i-1].ptr==NULL)
    {
     MEMptr[i-1].ptr=ptr;
     MEMptr[i-1].l=n;
     MEMptr[i-1].l0=n0;
     strncpy(MEMptr[i-1].sf,sf,sizeof(MEMptr[i-1].sf)); MEMptr[i-1].sf[sizeof(MEMptr[i-1].sf)-1]='\0';
     MEMptr[i-1].iLine=iLine;
     return ptr;
    }
    else
    {int j;
     for(j=nMEMptr;j>i;j--)
      MEMptr[j]=MEMptr[j-1];
     nMEMptr++;
     MEMptr[i].ptr=ptr;
     MEMptr[i].l=n;
     MEMptr[i].l0=n0;
     strncpy(MEMptr[i].sf,sf,sizeof(MEMptr[i].sf)); MEMptr[i].sf[sizeof(MEMptr[i].sf)-1]='\0';
     MEMptr[i].iLine=iLine;
     return ptr;
    }
   }
   else //if(MEMptr[i].ptr-ptr)>=n)
   {
    ptr=((char*)MEMptr[i].ptr)+MEMptr[i].l;
   }
  }
 }
 MEMptr[nMEMptr].ptr=ptr;
 MEMptr[nMEMptr].l=n;
 MEMptr[nMEMptr].l0=n0;
 strncpy(MEMptr[nMEMptr].sf,sf,sizeof(MEMptr[nMEMptr].sf)); MEMptr[nMEMptr].sf[sizeof(MEMptr[nMEMptr].sf)-1]='\0';
 MEMptr[nMEMptr].iLine=iLine;
 nMEMptr++;
return ptr;
return NULL;
}

void *calloc(size_t n,size_t size, const char* lpszFileName, int nLine) throw()
{
 void *p;
 p=malloc(size*n, lpszFileName, nLine);
 memset(p,0,size*n);
 return p;
}

void *realloc(void *buf,size_t n, const char* sf, int iLine) throw()
{
 void *p;int i,l0;
 int n0=n;
 n=(n+3)/4*4;
 if(buf==NULL)
  return malloc(n,sf,iLine);
 for(i=0;i<nMEMptr;i++)
 {
  if(MEMptr[i].ptr==buf)
  {
   l0=MEMptr[i].l0;
   strncpy(MEMptr[i].sf,sf,sizeof(MEMptr[i].sf)); MEMptr[i].sf[sizeof(MEMptr[i].sf)-1]='\0';
   MEMptr[i].iLine=iLine;
   if(MEMptr[i].l>=(int)n)
   {
    MEMptr[i].l=n;
    MEMptr[i].l0=n0;
    return MEMptr[i].ptr;
   }
   else
   {
    p=malloc(n,sf,iLine);
    memcpy(p,buf,l0);
    free(MEMptr[i].ptr);
    return p;
   }
  }
 }
 printf("Incorrect pointer in realloc().Can't reallocate memory.\n");
 return NULL;
}
//------------------------------------

void MEMCheckLastPtrs()
{
 int i;
 for(i=nMEMptr-1;i>=0;i--)
  if(MEMptr[i].ptr==NULL)
  {MEMptr[i].l=MEMptr[i].l0=0; nMEMptr=i;}
  else
   break;
}

void free(void *ptr) throw()
{int i;if(ptr==NULL)return;
 for(i=0;i<nMEMptr;i++)
  if(MEMptr[i].ptr==ptr)
  {MEMptr[i].ptr=NULL; MEMptr[i].l=MEMptr[i].l0=0;break;}
 MEMCheckLastPtrs();
//printf("Free\n");
}
int WCheckMemCleaning(void)
{int N0Check=4;
 MEMCheckLastPtrs();
 if(nMEMptr>0)
 {int i,nbad=0,SetBad=0;
  i=0; 
   if(MEMptr[i].ptr!=NULL)//&&MEMptr[i].l0!=16)
   {
    //SetBad=1;
    //nbad++;
   }
  i=1; 
   if(MEMptr[i].ptr!=NULL)//&&MEMptr[i].l0!=46)
   {
    //SetBad=1;
    //nbad++;
   }
  i=2; 
   if(MEMptr[i].ptr!=NULL)//&&MEMptr[i].l0!=46)
   {
    //SetBad=1;
    //nbad++;
   }
  i=3; 
   if(MEMptr[i].ptr!=NULL)//&&MEMptr[i].l0!=46)
   {
    //SetBad=1;
    //nbad++;
   }
  for(i=N0Check;i<nMEMptr;i++)
  {
   if(MEMptr[i].ptr!=NULL)
   {
    SetBad=1;
    nbad++;
   }
  }
  if(SetBad)
   printf("WCheckMemCleaning: memory leaks:\n");
  else
  {
   printf("No memory leaks\n");
   return 0;
  }
  i=0; nbad=0;
   if(MEMptr[i].ptr!=NULL)//&&MEMptr[i].l0!=16)
   {
    //printf("block addr=%p (length=%d)\n",MEMptr[i].ptr,MEMptr[i].l0);
    //nbad++;
   }
  i=1; 
   if(MEMptr[i].ptr!=NULL)//&&MEMptr[i].l0!=46)
   {
    //printf("block addr=%p (length=%d)\n",MEMptr[i].ptr,MEMptr[i].l0);
    //nbad++;
   }
  for(i=N0Check;i<nMEMptr;i++)
  {
   if(MEMptr[i].ptr!=NULL)
   {
    if(MEMptr[i].sf[0])
     printf("%d)block addr=%p (length=%d; allocated: %d: '%s')\n",i,MEMptr[i].ptr,MEMptr[i].l0,MEMptr[i].iLine,MEMptr[i].sf);
    else
     printf("%d)block addr=%p (length=%d)\n",i,MEMptr[i].ptr,MEMptr[i].l0);
    nbad++;
   }
  }
  return nbad;
 }
 else
 {
  printf("WCheckMemCleaning: OK\n");
  return 0;
 }
}
int WCheckMemCleaning_old()
{
 MEMCheckLastPtrs();
 if(nMEMptr>0)
 {int i,nbad=0;
  printf("WCheckMemCleaning: memory leaks:\n");
  for(i=0;i<nMEMptr;i++)
  {
   if(MEMptr[i].ptr!=NULL)
   {
    printf("block addr=%p (length=%d)\n",MEMptr[i].ptr,MEMptr[i].l0);
    nbad++;
   }
  }
  return nbad;
 }
 else
 {
  printf("WCheckMemCleaning: OK\n");
  return 0;
 }
}

void *operator new(size_t n)
{
	void *ptr=(void*)malloc(n);
//	printf("n=%d\n",n);
	return ptr;
}
void operator delete(void *ptr)
{//printf("Free\n");
	free(ptr);
}
void operator delete(void *ptr,long long unsigned int size)
{//printf("Free\n");
size=size;
	free(ptr);
}
void *operator new[](size_t n)
{
	void *ptr=(void*)malloc(n);
//	printf("n[]=%d\n",n);
	return ptr;
}
void operator delete[](void *ptr)
{//printf("Free[]\n");
	free(ptr);
}
void operator delete[](void *ptr,long long unsigned int size)
{//printf("Free[]\n");
size=size;
	free(ptr);
}
/*
int main(int n,const char **v)
{n=n;v=v;
 {
 char *p0=new char[3];
  printf("p0=%d\n",p0);	
 char *p1=new char[3];
  printf("p1=%d\n",p1);	
 delete p0;
 delete p1;
 }
 {
 char *p0=new char[3];
  printf("p0=%d\n",p0);	
 char *p1=new char[3];
  printf("p1=%d\n",p1);	
  p0=(char*)realloc(p0,100);
 delete p0;
 delete p1;
 }
 {
  FILE *f;
  f=fopen("t.t","w");
  fprintf(f,"Hello!!!\n");
 }
 WCheckMemCleaning();
	return 0;
}
*/

void* operator new(size_t n, const char* lpszFileName, int nLine)
{lpszFileName=lpszFileName;nLine=nLine;
	void *ptr=(void*)malloc(n,lpszFileName, nLine);
//	printf("new!!!=%d\n",(int)n);
	return ptr;
}

void* operator new[](size_t n, const char* lpszFileName, int nLine)
{lpszFileName=lpszFileName;nLine=nLine;
	void *ptr=(void*)malloc(n,lpszFileName, nLine);
//	printf("new!!!!!=%d\n",(int)n);
	return ptr;
}


