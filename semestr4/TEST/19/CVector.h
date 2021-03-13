/*
 * CVector.h
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
#include <algorithm>
using namespace std;
//--------------------------------------------------------------
//----------- Определение класса -------------------------------
//--------------------------------------------------------------
/*
TODO:  move constructor, operators

DONE: some tests, const functions
*/
class CFabricVector;
class CVector
{
protected:
    size_t n;                 //Размер вектора
    vector<int> ptrArr;     //Указатель на массив элементов
    //char* OutFile;
public:
    CVector (const CVector&v) {CopyOnly(v);}
    CVector()      { SetZero(); /*n=0; ptrArr = new int[n];*/ /*ptrArr = (int*)realloc(ptrArr, n*sizeof(int));*/ }
    CVector(size_t num)   { n = num;  for(size_t i=0;i<num;i++) ptrArr.push_back(0); }
    virtual ~CVector()    { Clean(); }
    
    CVector ( CVector && ) = default; 	//move constructor
    //CVector&  operator= ( CVector&& );  //move assignment
    size_t getN() const{ return n; }                      //getter
    //void setN(int dimension) { n = dimension; ptrArr =(int*)realloc(ptrArr, n*sizeof(int));}   //setter
    vector<int> getPtrArr() const{ return ptrArr; }
    void SetZero(){n=0;}
    void Clean() {ptrArr.clear();/*if(ptrArr!=NULL)delete [] ptrArr;*/ SetZero();}
    void setPtrArr(vector<int> arr)  { for (size_t i=0; i < n; i++ ) {ptrArr[i] = arr[i]; } } 
    void GetVector();
    void ShowVector();
    void CopyOnly(const CVector &v);
    void setPos(size_t i, int f) {if(/*i<0||*/i>=n) 
     {vector<int> tmp; for(size_t j=0;j<n;j++){tmp.push_back(ptrArr[j]);} 
     for(size_t j=n+1;j<i;j++){tmp.push_back(0);} tmp.push_back(f); ptrArr=tmp;n=i+1; }//memmove(ptrArr,tmp,(i+1)*sizeof(int));} //ptrArr=tmp; if(tmp)delete[]tmp;}
     //delete[]ptrArr; ptrArr=new int[i]; n=i; memcpy(ptrArr,tmp,i*sizeof(int));} 
     else ptrArr[i]=f;}
    /*const*/ CVector& operator=(const CVector& v);
    //CVector &operator=( CVector0 &b);
    /*const */ //CVector& operator+(const CVector &v);
    /*const  CVector& operator-(const CVector &v);*/
    int operator *(const CVector &v);
    int &operator[](size_t i){if(/*i<0||*/i>n-1) throw -1; return (this->ptrArr)[i];}
    //int &operator[](int i){if(i<0||i>n-1) throw -1; return ptrArr[i];}

    virtual int output()=0;
    virtual const string getF()const=0;
    virtual void setText(string c)=0;
    virtual bool cmp(int a, int b) {if(a==b) return 0; return 1;}
    
    void Sort(){sort (ptrArr.begin(), ptrArr.end());}
    
    static int Input(const char *fn, vector<CVector*> &v, vector<CFabricVector*> &fabric);
    
 
    friend ostream &operator<<(ostream& /*&cout*/, CVector& );
    friend istream &operator>>(istream& /*&cin*/, CVector& ); 
};

CVector& operator+(const CVector &lhs, const CVector &rhs);
CVector& operator-(const CVector &lhs, const CVector &rhs);


class CVector1: public CVector {
   private:
      string OutFile;
   public:
      CVector1 (const CVector1 &v):CVector(v){if(this!=&v)OutFile=v.OutFile;} //{ strncpy(OutFile,v.OutFile,sizeof(OutFile));OutFile[sizeof(OutFile)-1]='\0';}}
      CVector1() {n=0;}
      CVector1(int num) : CVector(num){}//OutFile[sizeof(OutFile)-1]='\0';}
      //CVector0(int num)   { n = num;   ptrArr = new int [num];  }
      ~CVector1()    {/*delete [] ptrArr; ptrArr=NULL;n=0;*/}
      //~CVector0() : ~CVector() {}
      CVector1 &operator=( CVector1&b){if(this!=&b){ptrArr=b.getPtrArr(); n=b.getN(); OutFile=b.getF();} return *this;}
      CVector1 &operator=( CVector&b){if(this!=&b){ptrArr=b.getPtrArr(); n=b.getN();} return *this;}
      //CVector1& operator+(const CVector1 &v);
      //{if(n==v.getN()){CVector1 w(n);for (size_t i=0; i < n; i++ ) {w.setPos(i,ptrArr[i]+v.getPtrArr()[i]);} *this=w;return *this;} else {cout << "Вектора должны быть одинаковой длины!\n"; throw -1;}}
      //CVector1& operator-(const CVector1 &v);//{if(n==v.getN()){CVector1 w(n);for (size_t i=0; i < n; i++ ) {w.setPos(i,ptrArr[i]-v.getPtrArr()[i]);} *this=w;return *this;} else {cout << "Вектора должны быть одинаковой длины!\n"; throw -1;}}
      void SetZero(){n=0;}
      void Clean() {ptrArr.clear(); SetZero();}
      const string getF() const{return OutFile;}
      void setText(string c)  { OutFile=c; } 
      int output(); 
      virtual bool cmp(int a, int b) {if(a==b) return 0;return 100;}
      
};

//иначе имеем ambiguating
CVector1& operator+(const CVector1 &lhs, const CVector1 &rhs);
CVector1& operator-(const CVector1 &lhs, const CVector1 &rhs);

class CFabricVector
{
public:
 virtual CVector *Create() = 0;
 virtual ~CFabricVector() {}
};


class CFabricVector1: public CFabricVector
{
public:
 virtual CVector *Create() {return new CVector1;}
 virtual ~CFabricVector1() {}
};
