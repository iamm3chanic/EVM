/*
 *  CIntN.h
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
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <math.h>
#include <omp.h>
#include <string.h>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;
//--------------------------------------------------------------
//----------- Определение класса -------------------------------
//--------------------------------------------------------------

class CFabricIntN;
class CIntN
{
protected:
    //size_t n;                 //Размер вектора
    vector<unsigned short int> pointer;     //Указатель на массив элементов
public:
    CIntN (const CIntN&v) {CopyOnly(v);}
    CIntN(const vector<unsigned short int> &v){CopyOnly(v);}

    CIntN()      { pointer.clear(); }
    CIntN(size_t num)   {  pointer.resize(num); }
    virtual ~CIntN()    { }
    
    CIntN ( CIntN &&o ) {pointer=std::move(o.getPointer());} 	//move constructor
    CIntN&  operator= ( CIntN&& )=default;  //move assignment
    size_t getN() const{ return pointer.size(); }                      //getter
    vector<unsigned short int> getPointer() const{ return pointer; }

    void Clean() {pointer.clear();}
    void setPointer(vector<unsigned short int> arr)  { pointer=std::move(arr); } 
    void GetIntN();
    void ShowIntN();
    void CopyOnly(const CIntN &v);
    void CopyOnly(const vector<unsigned short int> &v){if(pointer!=v) copy(v.begin(),v.end(),back_inserter(pointer));}
    void setPos(size_t i, unsigned short int f) {if(i>=pointer.size()) 
     {vector<unsigned short int> tmp; for(size_t j=0;j<pointer.size();j++){tmp.push_back(pointer[j]);} 
     for(size_t j=pointer.size()+1;j<i;j++){tmp.push_back(0);} tmp.push_back(f); pointer=tmp;/*pointer.size()=i+1; */}
     else pointer[i]=f;}
    /*const*/ CIntN& operator=(const CIntN& v);
   
    unsigned short int &operator[](size_t i){if(i>pointer.size()-1) throw -1; return (this->pointer)[i];}

    virtual int output()=0;
    virtual const string getF()const=0;
    virtual void setText(string c)=0;
    static int Input(const char *fn, vector<CIntN*> &v, vector<CFabricIntN*> &fabric);
    static int OMPTest(const char *fn);
 
    friend ostream &operator<<(ostream& /*&cout*/, CIntN& );
    friend istream &operator>>(istream& /*&cin*/, CIntN& ); 
};


class CIntN0: public CIntN {
   private:
      string OutFile;
   public:
      CIntN0 (const CIntN0 &v):CIntN(v){if(this!=&v){ OutFile=v.OutFile;}}
      CIntN0 (const vector<unsigned short int>v): CIntN(v){}
      CIntN0() {pointer.clear();}
      CIntN0(int num) : CIntN(num){}
      CIntN0 ( CIntN0 &&v ):CIntN(v){OutFile=v.OutFile;v.OutFile="";}
      ~CIntN0()    {}
      void CopyOnly(const CIntN0 &v) {if(this!=&v){pointer= v.pointer; OutFile=v.getF();}}
      CIntN0 &operator=( CIntN0 b){if(this!=&b){pointer=b.getPointer(); /*n=b.getN();*/ OutFile=b.getF();} return *this;}
      CIntN0 &operator=( CIntN &b){if(this!=&b){pointer=b.getPointer();/* n=b.getN();*/} return *this;}
      void Clean() {pointer.clear();}
      const string getF() const{return OutFile;}
      void setText(string c)  { OutFile=c; } 
      int output(); //в строку
      friend ostream &operator<<(ostream& , CIntN0 );
};

CIntN0 operator+(const CIntN&a,const CIntN&b);
CIntN0 operator-(const CIntN&a,const CIntN&b);

class CIntN1: public CIntN {
   private:
      string OutFile;
   public:
      CIntN1 (const CIntN1 &v):CIntN(v){if(this!=&v)OutFile=v.OutFile;} 
      CIntN1 (const vector<unsigned short int>v): CIntN(v){}
      CIntN1() {pointer.clear();}
      CIntN1(int num) : CIntN(num){}//OutFile[sizeof(OutFile)-1]='\0';}
      CIntN1 ( CIntN1 &&o ) 
           { 
             pointer=std::move(o.getPointer());
             OutFile=std::move(o.getF());            
            }
      ~CIntN1()    {}
      CIntN1 &operator=( CIntN1 b){if(this!=&b){pointer=b.getPointer(); OutFile=b.getF();} return *this;}
      CIntN1 &operator=( CIntN&b){if(this!=&b){pointer=b.getPointer(); } return *this;}
      
      void Clean() {pointer.clear(); }
      const string getF() const{return OutFile;}
      void setText(string c)  { OutFile=c; } 
      int output(); //в столбец
      friend ostream &operator<<(ostream& , CIntN1 );
};


CIntN1 operator+(const CIntN1 &lhs, const CIntN1 &rhs);
CIntN1 operator-(const CIntN1 &lhs, const CIntN1 &rhs);

class CFabricIntN
{
public:
 virtual CIntN *Create() = 0;
 virtual ~CFabricIntN() {}
};

class CFabricIntN0: public CFabricIntN
{
public:
 virtual CIntN *Create() {return new CIntN0;}
 virtual ~CFabricIntN0() {}
};

class CFabricIntN1: public CFabricIntN
{
public:
 virtual CIntN *Create() {return new CIntN1;}
 virtual ~CFabricIntN1() {}
};
