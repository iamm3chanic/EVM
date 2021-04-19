/*
 * CIntN.h
 15. Определить класс CIntN для работы с целыми знаковыми числа-
ми, состоящими из N десятичных цифр, где N задается в конструкторе.
В классе должны быть определены необходимые конструкторы, деструк-
тор, операторы присваивания, сложения, вычитания.
Написать функцию и конструктор сохранения переменной данного
типа в файл и загрузки из файла.
В отдельном файле должен быть написан тест на данный класс.
 */
#pragma once
#include <iostream>
#include <math.h>
#include <string.h>
#include <cstdlib>
using namespace std;
//--------------------------------------------------------------
//----------- Определение класса -------------------------------
//--------------------------------------------------------------
/*
TODO:  move constructor, operators

*/
class CIntN
{
protected:
    size_t n;                 //Размер вектора
    unsigned short int *array;     //Указатель на массив элементов
    //char* OutFile;
public:
    CIntN(const CIntN&v) {CopyOnly(v);}
    CIntN(const unsigned short int *v,size_t n){CopyOnly(v,n);}
    CIntN()      { SetZero(); }
    CIntN(size_t num)   { n = num;   array = new unsigned short int [num]; memset(array,0,n*sizeof(unsigned short int)); }
    virtual ~CIntN()    { Clean(); }
    
    CIntN ( CIntN && ) = default; 	//move constructor
    CIntN&  operator= (const CIntN&& );  //move assignment
    size_t getN() const{ return n; }                      //getter
    //void setN(int dimension) { n = dimension; array =(unsigned short int*)realloc(array, n*sizeof(unsigned short int));}   //setter
    unsigned short int* getPtrArr() const{ return array; }
    void SetZero(){array=NULL;n=0;}
    void Clean() {if(array!=NULL)delete [] array; SetZero();}
    void setPtrArr(unsigned short int* arr)  { for (size_t i=0; i < n; i++ ) {array[i] = arr[i]; } } 
    void GetIntN();
    void ShowIntN();
    void CopyOnly(const CIntN &v);
    void CopyOnly(const unsigned short int *v,size_t num){this->n=num;memcpy(this->array=new unsigned short int[num],v,n*sizeof(unsigned short int));}
    void setPos(size_t i, unsigned short int f) {if(/*i<0||*/i>n-1) throw -1; 
    //if(!array){array = new unsigned short int[i];memset(array,0,i*sizeof(unsigned short int)); }
    array[i]=f;}
    /*const*/ CIntN& operator=(const CIntN& v);
    /*const */ //CIntN& operator+(const CIntN &v);
    /*const  CIntN& operator-(const CIntN &v);*/
    unsigned short int &operator[](size_t i){if(/*i<0||*/i>n-1) throw -1; return (this->array)[i];}
    //unsigned short int &operator[](int i){if(i<0||i>n-1) throw -1; return array[i];}

    virtual int output(const char *FileName=NULL)=0;
    virtual const char* getF()const=0;
    virtual void setText(char* c)=0;
    static CIntN **Input(const char *fn);
    
    friend unsigned short int Skalar   (CIntN& , CIntN&);  //Склярное произведение
 
    friend CIntN& Kommutativ(const CIntN& , const CIntN& );//Сложение векторов
    friend CIntN& Netativ   (const CIntN& , const CIntN& );//Вычитание векторов
    friend int NReader();
    friend ostream &operator<<(ostream& /*&cout*/, CIntN& );
    friend istream &operator>>(istream& /*&cin*/, CIntN& ); 
};

CIntN& operator+(const CIntN &lhs, const CIntN &rhs);
CIntN& operator-(const CIntN &lhs, const CIntN &rhs);

class CIntN0: public CIntN {
   private:
      char OutFile[15];
   public:
      CIntN0 (const CIntN0 &v):CIntN(v){if(this!=&v){ strncpy(OutFile,v.OutFile,15);}}
      CIntN0() {array=NULL;n=0;}
      CIntN0(int num) : CIntN(num){memset(OutFile,0,15);/* n = num;   array = new unsigned short int [num]; memset(array,0,n*sizeof(unsigned short int));*/}
      //CIntN0(int num)   { n = num;   array = new unsigned short int [num];  }
      ~CIntN0()    {delete [] array; array=NULL;n=0;}
      void CopyOnly(const CIntN0 &v) {if(this!=&v){memcpy(array=new unsigned short int[n=v.getN()], v.array, v.getN()*sizeof(unsigned short int)); strncpy(OutFile,v.getF(),15);}}
      //~CIntN0() : ~CIntN() {}
      CIntN0 &operator=( CIntN0&b){if(this!=&b){memcpy(array,b.getPtrArr(),b.getN()*sizeof(unsigned short int)); n=b.getN(); strcpy(OutFile,b.getF());} return *this;}
      CIntN0 &operator=( CIntN &b){if(this!=&b){memcpy(array,b.getPtrArr(),b.getN()*sizeof(unsigned short int)); n=b.getN();} return *this;}
      CIntN0 &operator+( CIntN &v){if(n==v.getN()){for (size_t i=0; i < n; i++ ) {array[i]= v.getPtrArr()[i]+array[i];} return *this;} else {cout << "Вектора должны быть одинаковой длины!\n"; throw -1;}}
      CIntN0 &operator-( CIntN &v){if(n==v.getN()){for (size_t i=0; i < n; i++ ) {array[i]= array[i]-v.getPtrArr()[i];} return *this;} else {cout << "Вектора должны быть одинаковой длины!\n"; throw -1;}}
      void SetZero(){array=NULL;n=0;}
      void Clean() {delete [] array; SetZero();}
      const char* getF() const{return OutFile;}
      void setText(char* c)  { strcpy(OutFile,c); } 
      int output(const char *FileName); //в строку
};

//иначе имеем ambiguating
//CIntN0& operator+(const CIntN0 &lhs, const CIntN0 &rhs);
//CIntN0& operator-(const CIntN0 &lhs, const CIntN0 &rhs);

class CIntN1: public CIntN {
   private:
      char OutFile[15];
   public:
      CIntN1 (const CIntN1 &v):CIntN(v){if(this!=&v){ strncpy(OutFile,v.OutFile,15);}}
      CIntN1() {array=NULL;n=0;}
      CIntN1(int num) : CIntN(num){memset(OutFile,0,15);}
      CIntN1(const unsigned short int *v,size_t n): CIntN(v,n){memset(OutFile,0,15);}
      virtual ~CIntN1()    {delete [] array; array=NULL;n=0;}
      
      CIntN1 &operator=( CIntN1&b){if(this!=&b){memcpy(array,b.getPtrArr(),b.getN()*sizeof(unsigned short int)); n=b.getN();} return *this;}
      CIntN1 &operator=( CIntN&b){if(this!=&b){memcpy(array,b.getPtrArr(),b.getN()*sizeof(unsigned short int)); n=b.getN();} return *this;}
      //CIntN1& operator+(const CIntN1 &v);
      //{if(n==v.getN()){CIntN1 w(n);for (size_t i=0; i < n; i++ ) {w.setPos(i,array[i]+v.getPtrArr()[i]);} *this=w;return *this;} else {cout << "Вектора должны быть одинаковой длины!\n"; throw -1;}}
      //CIntN1& operator-(const CIntN1 &v);//{if(n==v.getN()){CIntN1 w(n);for (size_t i=0; i < n; i++ ) {w.setPos(i,array[i]-v.getPtrArr()[i]);} *this=w;return *this;} else {cout << "Вектора должны быть одинаковой длины!\n"; throw -1;}}
      void SetZero(){array=NULL;n=0;}
      void Clean() {delete [] array; SetZero();}
      const char* getF() const{return OutFile;}
      void setText(char* c)  { strcpy(OutFile,c); } 
      int output(const char *FileName); //в столбец
    friend ostream &operator<<(ostream& /*&cout*/, CIntN1 );
};

//иначе имеем ambiguating
CIntN1 operator+(const CIntN1 &lhs, const CIntN1 &rhs);
CIntN1 operator-(const CIntN1 &lhs, const CIntN1 &rhs);
 
extern size_t glob_n;
