
#pragma once
#include <iostream>
#include <math.h>
#include <string.h>
#include <cstdlib>
using namespace std;


class CVector
{
protected:
    size_t n;               
    double *pointer; 
public:
    CVector (const CVector&v) {CopyOnly(v);}
    CVector()      { SetZero();   }
    CVector(size_t num)   { n = num;   pointer = new double [num]; memset(pointer,0,n*sizeof(double)); }
    virtual ~CVector()    { Clean(); }
    
    
    size_t getN() const{ return n; }                    
   
    double* getPointer() const{ return pointer; }
    void SetZero(){pointer=NULL;n=0;}
    void Clean() {if(pointer!=NULL)delete [] pointer; SetZero();}
    void setPointer(double* arr)  { for (size_t i=0; i < n; i++ ) {pointer[i] = arr[i]; } } 
    void GetVector();
    void ShowVector();
    void CopyOnly(const CVector &v);
    void setPos(size_t i, double f) {if(i>n-1) {double *tmp=new double[i]; for(size_t j=0;j<n;j++){tmp[j]=pointer[j];} for(size_t j=n+1;j<i;j++){tmp[j]=0;} tmp[i]=f; delete[]pointer;pointer=new double[i]; n=i; memcpy(pointer,tmp,i*sizeof(double));} else pointer[i]=f;}
     CVector& operator=(const CVector& v);
    double operator *(const CVector &v);
    double &operator[](size_t i){if(i>n-1) throw -1; return (this->pointer)[i];}
    
    virtual int output(const char *FileName=NULL)=0;
    virtual const char* takeF()const=0;
    virtual void setText(char* c)=0;
    static CVector **Input(const char *fn, size_t *n);
    
    friend ostream &operator<<(ostream& , CVector& );
    friend istream &operator>>(istream& , CVector& ); 
};

CVector& operator+(const CVector &lhs, const CVector &rhs);
CVector& operator-(const CVector &lhs, const CVector &rhs);

class CVector0: public CVector {
   private:
      char Outcome[15];
   public:
      CVector0 (const CVector0 &v):CVector(v){if(this!=&v){ strncpy(Outcome,v.Outcome,15);}}
      CVector0() {pointer=NULL;n=0;}
      CVector0(int num) : CVector(num){Outcome[sizeof(Outcome)-1]='\0';}
      ~CVector0()    {}
      void CopyOnly(const CVector0 &v) {if(this!=&v){memcpy(pointer=new double[n=v.getN()], v.pointer, v.getN()*sizeof(double)); strncpy(Outcome,v.takeF(),15);}}
     
      CVector0 &operator=( CVector0&b){if(this!=&b){memcpy(pointer,b.getPointer(),b.getN()*sizeof(double)); n=b.getN(); strcpy(Outcome,b.takeF());} return *this;}
      CVector0 &operator=( CVector &b){if(this!=&b){memcpy(pointer,b.getPointer(),b.getN()*sizeof(double)); n=b.getN();} return *this;}
      //CVector0 &operator+( CVector &v){if(n==v.getN()){for (size_t i=0; i < n; i++ ) {pointer[i]= v.getPointer()[i]+pointer[i];} return *this;} else {cout << "Вектора должны быть одинаковой длины!\n"; throw -1;}}
      //CVector0 &operator-( CVector &v){if(n==v.getN()){for (size_t i=0; i < n; i++ ) {pointer[i]= pointer[i]-v.getPointer()[i];} return *this;} else {cout << "Вектора должны быть одинаковой длины!\n"; throw -1;}}
      void SetZero(){pointer=NULL;n=0;}
      void Clean() {delete [] pointer; SetZero();}
      const char* takeF() const{return Outcome;}
      void setText(char* c)  { strcpy(Outcome,c); } 
      int output(const char *FileName);
};

CVector0& operator+(const CVector0 &lhs, const CVector0 &rhs);
CVector0& operator-(const CVector0 &lhs, const CVector0 &rhs);



class CVector1: public CVector {
   private:
      char Outcome[15];
   public:
      CVector1 (const CVector1 &v):CVector(v){if(this!=&v){ strncpy(Outcome,v.Outcome,15);}}
      CVector1() {pointer=NULL;n=0;}
      CVector1(int num) : CVector(num){Outcome[sizeof(Outcome)-1]='\0';}
     
      ~CVector1()    {}
      CVector1 &operator=( CVector1&b){if(this!=&b){memcpy(pointer,b.getPointer(),b.getN()*sizeof(double)); n=b.getN();} return *this;}
      CVector1 &operator=( CVector&b){if(this!=&b){memcpy(pointer,b.getPointer(),b.getN()*sizeof(double)); n=b.getN();} return *this;}
      
      void SetZero(){pointer=NULL;n=0;}
      void Clean() {delete [] pointer; SetZero();}
      const char* takeF() const{return Outcome;}
      void setText(char* c)  { strcpy(Outcome,c); } 
      int output(const char *FileName); 
};


CVector1& operator+(const CVector1 &lhs, const CVector1 &rhs);
CVector1& operator-(const CVector1 &lhs, const CVector1 &rhs);

