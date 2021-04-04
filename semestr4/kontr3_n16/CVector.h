/*
 * CVector.h
 */
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <omp.h>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;
//--------------------------------------------------------------
//----------- Определение класса -------------------------------
//--------------------------------------------------------------

class CFabricVector;
class CVector
{
protected:
    //size_t n;                 //Размер вектора
    vector<double> pointer;     //Указатель на массив элементов
public:
    CVector (const CVector&v) {CopyOnly(v);}
    CVector(const vector<double> &v){CopyOnly(v);}

    CVector()      { pointer.clear(); }
    CVector(size_t num)   {  pointer.resize(num); }
    virtual ~CVector()    { }
    
    CVector ( CVector &&o ) {pointer=std::move(o.getPointer());} 	//move constructor
    CVector&  operator= ( CVector&& )=default;  //move assignment
    size_t getN() const{ return pointer.size(); }                      //getter
    //void setN(int dimension) { n = dimension; pointer =(double*)realloc(pointer, n*sizeof(double));}   //setter
    vector<double> getPointer() const{ return pointer; }

    void Clean() {pointer.clear();}
    void setPointer(vector<double> arr)  { pointer=std::move(arr); } 
    void GetVector();
    void ShowVector();
    void CopyOnly(const CVector &v);
    void CopyOnly(const vector<double> &v){if(pointer!=v) copy(v.begin(),v.end(),back_inserter(pointer));}
    void setPos(size_t i, double f) {if(i>=pointer.size()) 
     {vector<double> tmp; for(size_t j=0;j<pointer.size();j++){tmp.push_back(pointer[j]);} 
     for(size_t j=pointer.size()+1;j<i;j++){tmp.push_back(0);} tmp.push_back(f); pointer=tmp;/*pointer.size()=i+1; */}
     else pointer[i]=f;}
    /*const*/ CVector& operator=(const CVector& v);
    //CVector &operator=( CVector0 &b);
    /*const */ //CVector& operator+(const CVector &v);
    /*const  CVector& operator-(const CVector &v);*/
    double operator *(const CVector &v);
    double &operator[](size_t i){if(i>pointer.size()-1) throw -1; return (this->pointer)[i];}
    //double &operator[](int i){if(i<0||i>n-1) throw -1; return pointer[i];}

    virtual int output()=0;
    virtual const string getF()const=0;
    virtual void setText(string c)=0;
    static int Input(const char *fn, vector<CVector*> &v, vector<CFabricVector*> &fabric);
    static int OMPTest(const char *fn);
 
    friend ostream &operator<<(ostream& /*&cout*/, CVector& );
    friend istream &operator>>(istream& /*&cin*/, CVector& ); 
};

//CVector& operator+(const CVector &lhs, const CVector &rhs);
//CVector& operator-(const CVector &lhs, const CVector &rhs);

class CVector0: public CVector {
   private:
      string OutFile;
   public:
      CVector0 (const CVector0 &v):CVector(v){if(this!=&v){ OutFile=v.OutFile;}}
      CVector0 (const vector<double>v): CVector(v){}
      CVector0() {pointer.clear();}
      CVector0(int num) : CVector(num){}
      CVector0 ( CVector0 &&v ):CVector(v){OutFile=v.OutFile;v.OutFile="";}
      ~CVector0()    {}
      void CopyOnly(const CVector0 &v) {if(this!=&v){pointer= v.pointer; OutFile=v.getF();}}
      CVector0 &operator=( CVector0 b){if(this!=&b){pointer=b.getPointer(); /*n=b.getN();*/ OutFile=b.getF();} return *this;}
      CVector0 &operator=( CVector &b){if(this!=&b){pointer=b.getPointer();/* n=b.getN();*/} return *this;}
      void Clean() {pointer.clear();}
      const string getF() const{return OutFile;}
      void setText(string c)  { OutFile=c; } 
      int output(); //в строку
      friend ostream &operator<<(ostream& , CVector0 );
};

CVector0 operator+(const CVector&a,const CVector&b);
CVector0 operator-(const CVector&a,const CVector&b);

class CVector1: public CVector {
   private:
      string OutFile;
   public:
      CVector1 (const CVector1 &v):CVector(v){if(this!=&v)OutFile=v.OutFile;} 
      CVector1 (const vector<double>v): CVector(v){}
      CVector1() {pointer.clear();}
      CVector1(int num) : CVector(num){}//OutFile[sizeof(OutFile)-1]='\0';}
      CVector1 ( CVector1 &&o ) 
           { 
             pointer=std::move(o.getPointer());
             OutFile=std::move(o.getF());            
            }
      ~CVector1()    {}
      CVector1 &operator=( CVector1 b){if(this!=&b){pointer=b.getPointer(); OutFile=b.getF();} return *this;}
      CVector1 &operator=( CVector&b){if(this!=&b){pointer=b.getPointer(); } return *this;}
      
      void Clean() {pointer.clear(); }
      const string getF() const{return OutFile;}
      void setText(string c)  { OutFile=c; } 
      int output(); //в столбец
      friend ostream &operator<<(ostream& , CVector1 );
};


CVector1 operator+(const CVector1 &lhs, const CVector1 &rhs);
CVector1 operator-(const CVector1 &lhs, const CVector1 &rhs);

class CFabricVector
{
public:
 virtual CVector *Create() = 0;
 virtual ~CFabricVector() {}
};

class CFabricVector0: public CFabricVector
{
public:
 virtual CVector *Create() {return new CVector0;}
 virtual ~CFabricVector0() {}
};

class CFabricVector1: public CFabricVector
{
public:
 virtual CVector *Create() {return new CVector1;}
 virtual ~CFabricVector1() {}
};
