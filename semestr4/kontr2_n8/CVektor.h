/*
 * CVector.h
 * 8. Определить класс CVector для работы с вектором вещественных
 * чисел. Длина вектора задается в конструкторе класса. В классе
 * должны быть определены необходимые конструкторы, деструктор, операторы сло-
 * жения, вычитания, скалярного умножения.
 * Написать функцию и конструктор сохранения переменной данного
 * типа в файл и загрузки из файла.
 * В отдельном файле должен быть написан тест на данный класс.
 *      Created on: 02.03.2021
 */
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
//--------------------------------------------------------------
//----------- Определение класса -------------------------------
//--------------------------------------------------------------
/*
TODO:  move constructor, operators

DONE: some tests, const functions
*/
class CFabricVektor;
class CVektor
{
protected:
    size_t n;                 //Размер вектора
    float *ptrArr;     //Указатель на массив элементов
    //char* OutFile;
public:
    CVektor (const CVektor&v) {CopyOnly(v);}
    CVektor()      { SetZero(); /*n=0; ptrArr = new float[n];*/ /*ptrArr = (float*)realloc(ptrArr, n*sizeof(float));*/ }
    CVektor(size_t num)   { n = num;   ptrArr = new float [num]; memset(ptrArr,0,n*sizeof(float)); }
    virtual ~CVektor()    { Clean(); }
    
    CVektor ( CVektor && ) = default; 	//move constructor
    //CVektor&  operator= ( CVektor&& );  //move assignment
    size_t getN() const{ return n; }                      //getter
    //void setN(int dimension) { n = dimension; ptrArr =(float*)realloc(ptrArr, n*sizeof(float));}   //setter
    float* getPtrArr() const{ return ptrArr; }
    void SetZero(){ptrArr=NULL;n=0;}
    void Clean() {if(ptrArr!=NULL)delete [] ptrArr; SetZero();}
    void setPtrArr(float* arr)  { for (size_t i=0; i < n; i++ ) {ptrArr[i] = arr[i]; } } 
    void GetVektor();
    void ShowVektor();
    void CopyOnly(const CVektor &v);
    void setPos(size_t i, float f) {if(/*i<0||*/i>=n) 
     {float *tmp=new float[i+1]; for(size_t j=0;j<n;j++){tmp[j]=ptrArr[j];} 
     for(size_t j=n+1;j<i;j++){tmp[j]=0;} tmp[i]=f; delete[]ptrArr;ptrArr=tmp;n=i+1; }//memmove(ptrArr,tmp,(i+1)*sizeof(float));} //ptrArr=tmp; if(tmp)delete[]tmp;}
     //delete[]ptrArr; ptrArr=new float[i]; n=i; memcpy(ptrArr,tmp,i*sizeof(float));} 
     else ptrArr[i]=f;}
    /*const*/ CVektor& operator=(const CVektor& v);
    //CVektor &operator=( CVektor0 &b);
    /*const */ //CVektor& operator+(const CVektor &v);
    /*const  CVektor& operator-(const CVektor &v);*/
    float operator *(const CVektor &v);
    float &operator[](size_t i){if(/*i<0||*/i>n-1) throw -1; return (this->ptrArr)[i];}
    //float &operator[](int i){if(i<0||i>n-1) throw -1; return ptrArr[i];}

    virtual int output(const char *FileName=NULL)=0;
    virtual const char* getF()const=0;
    virtual void setText(char* c)=0;
    static int Input(const char *fn, vector<CVektor*> &v, vector<CFabricVektor*> &fabric);
    
 
    friend ostream &operator<<(ostream& /*&cout*/, CVektor& );
    friend istream &operator>>(istream& /*&cin*/, CVektor& ); 
};

CVektor& operator+(const CVektor &lhs, const CVektor &rhs);
CVektor& operator-(const CVektor &lhs, const CVektor &rhs);

class CVektor0: public CVektor {
   private:
      char OutFile[15];
   public:
      CVektor0 (const CVektor0 &v):CVektor(v){if(this!=&v){ strncpy(OutFile,v.OutFile,15);}}
      CVektor0() {ptrArr=NULL;n=0;}
      CVektor0(int num) : CVektor(num){memset(OutFile,0,15);/* n = num;   ptrArr = new float [num]; memset(ptrArr,0,n*sizeof(float));*/}
      //CVektor0(int num)   { n = num;   ptrArr = new float [num];  }
      ~CVektor0()    {if(ptrArr)delete [] ptrArr; ptrArr=NULL;n=0;}
      void CopyOnly(const CVektor0 &v) {if(this!=&v){memcpy(ptrArr=new float[n=v.getN()], v.ptrArr, v.getN()*sizeof(float)); strncpy(OutFile,v.getF(),15);}}
      //~CVektor0() : ~CVektor() {}
      CVektor0 &operator=( CVektor0&b){if(this!=&b){memcpy(ptrArr,b.getPtrArr(),b.getN()*sizeof(float)); n=b.getN(); strcpy(OutFile,b.getF());} return *this;}
      CVektor0 &operator=( CVektor &b){if(this!=&b){memcpy(ptrArr,b.getPtrArr(),b.getN()*sizeof(float)); n=b.getN();} return *this;}
      CVektor0 &operator+( CVektor &v){if(n==v.getN()){for (size_t i=0; i < n; i++ ) {ptrArr[i]= v.getPtrArr()[i]+ptrArr[i];} return *this;} else {cout << "Вектора должны быть одинаковой длины!\n"; throw -1;}}
      CVektor0 &operator-( CVektor &v){if(n==v.getN()){for (size_t i=0; i < n; i++ ) {ptrArr[i]= ptrArr[i]-v.getPtrArr()[i];} return *this;} else {cout << "Вектора должны быть одинаковой длины!\n"; throw -1;}}
      void SetZero(){ptrArr=NULL;n=0;}
      void Clean() {delete [] ptrArr; SetZero();}
      const char* getF() const{return OutFile;}
      void setText(char* c)  { strcpy(OutFile,c); } 
      int output(const char *FileName); //в строку
};

//иначе имеем ambiguating
//CVektor0& operator+(const CVektor0 &lhs, const CVektor0 &rhs);
//CVektor0& operator-(const CVektor0 &lhs, const CVektor0 &rhs);

class CVektor1: public CVektor {
   private:
      char OutFile[15];
   public:
      CVektor1 (const CVektor1 &v):CVektor(v){if(this!=&v){ strncpy(OutFile,v.OutFile,15);}}
      CVektor1() {ptrArr=NULL;n=0;}
      CVektor1(int num) : CVektor(num){memset(OutFile,0,15);/* n = num;   ptrArr = new float [num]; memset(ptrArr,0,n*sizeof(float));*/}
      //CVektor0(int num)   { n = num;   ptrArr = new float [num];  }
      ~CVektor1()    {delete [] ptrArr; ptrArr=NULL;n=0;}
      //~CVektor0() : ~CVektor() {}
      CVektor1 &operator=( CVektor1&b){if(this!=&b){memcpy(ptrArr,b.getPtrArr(),b.getN()*sizeof(float)); n=b.getN();} return *this;}
      CVektor1 &operator=( CVektor&b){if(this!=&b){memcpy(ptrArr,b.getPtrArr(),b.getN()*sizeof(float)); n=b.getN();} return *this;}
      //CVektor1& operator+(const CVektor1 &v);
      //{if(n==v.getN()){CVektor1 w(n);for (size_t i=0; i < n; i++ ) {w.setPos(i,ptrArr[i]+v.getPtrArr()[i]);} *this=w;return *this;} else {cout << "Вектора должны быть одинаковой длины!\n"; throw -1;}}
      //CVektor1& operator-(const CVektor1 &v);//{if(n==v.getN()){CVektor1 w(n);for (size_t i=0; i < n; i++ ) {w.setPos(i,ptrArr[i]-v.getPtrArr()[i]);} *this=w;return *this;} else {cout << "Вектора должны быть одинаковой длины!\n"; throw -1;}}
      void SetZero(){ptrArr=NULL;n=0;}
      void Clean() {delete [] ptrArr; SetZero();}
      const char* getF() const{return OutFile;}
      void setText(char* c)  { strcpy(OutFile,c); } 
      int output(const char *FileName); //в столбец
};

//иначе имеем ambiguating
CVektor1& operator+(const CVektor1 &lhs, const CVektor1 &rhs);
CVektor1& operator-(const CVektor1 &lhs, const CVektor1 &rhs);

class CFabricVektor
{
public:
 virtual CVektor *Create() = 0;
 virtual ~CFabricVektor() {}
};

class CFabricVektor0: public CFabricVektor
{
public:
 virtual CVektor *Create() {return new CVektor0;}
 virtual ~CFabricVektor0() {}
};

class CFabricVektor1: public CFabricVektor
{
public:
 virtual CVektor *Create() {return new CVektor1;}
 virtual ~CFabricVektor1() {}
};
