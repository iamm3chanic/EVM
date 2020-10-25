#pragma once
int WCheckMemCleaning();
void* operator new(size_t nSize, const char* lpszFileName, int nLine);
void* operator new[](size_t nSize, const char* lpszFileName, int nLine);
void *calloc(size_t n,size_t size, const char* lpszFileName, int nLine) throw();
void *realloc(void *buf,size_t n, const char* sf, int iLine) throw();
void *malloc(size_t n,const char *sf,int iLine) throw();

#define malloc(SIZE) malloc((SIZE),__FILE__, __LINE__)
#define realloc(PTR,SIZE) realloc((PTR),(SIZE),__FILE__, __LINE__)
#define calloc(NUM,SIZE) calloc((NUM),(SIZE),__FILE__, __LINE__)
#define new new(__FILE__, __LINE__)

