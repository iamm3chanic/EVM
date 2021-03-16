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

class CFabricVektor;
class CVektor
{
protected:
    size_t n;                 
    vector<float> ptrArr;     
    
public:
    CVektor (const CVektor&v) {CopyOnly(v);}
    CVektor()      { SetZero();  }
    CVektor(size_t num)   { n = num;  for(size_t i=0;i<num;i++) ptrArr.push_back(0); }
    virtual ~CVektor()    { Clean(); }
    
    CVektor ( CVektor && ) = default; 	//move constructor
    size_t getN() const{ return n; }                      
    vector<float> getPtrArr() const{ return ptrArr; }
    void SetZero(){n=0;}
    void Clean() {ptrArr.clear();SetZero();}
    void setPtrArr(vector<float> arr)  { for (size_t i=0; i < n; i++ ) {ptrArr[i] = arr[i]; } } 
    void GetVektor();
    void ShowVektor();
    void CopyOnly(const CVektor &v);
    void setPos(size_t i, float f) {if(/*i<0||*/i>=n) 
     {vector<float> tmp; for(size_t j=0;j<n;j++){tmp.push_back(ptrArr[j]);} 
     for(size_t j=n+1;j<i;j++){tmp.push_back(0);} tmp.push_back(f); ptrArr=tmp;n=i+1; }
     else ptrArr[i]=f;}
    /*const*/ CVektor& operator=(const CVektor& v);
    
    float &operator[](size_t i){if(/*i<0||*/i>n-1) throw -1; return (this->ptrArr)[i];}
  
    virtual int output(const char *FileName=NULL)=0;
    virtual const string getF()const=0;
    virtual void setText(string c)=0;
    static int Input(const char *fn, vector<CVektor*> &v, vector<CFabricVektor*> &fabric);
    
 
    friend ostream &operator<<(ostream& /*&cout*/, CVektor& );
    friend istream &operator>>(istream& /*&cin*/, CVektor& ); 
};

CVektor& operator+(const CVektor &lhs, const CVektor &rhs);
CVektor& operator-(const CVektor &lhs, const CVektor &rhs);

class CVektor0: public CVektor {
   private:
      string OutFile;
   public:
      CVektor0 (const CVektor0 &v):CVektor(v){if(this!=&v){ OutFile=v.OutFile;}}
      CVektor0() {n=0;}
      CVektor0(int num) : CVektor(num){}
     
      ~CVektor0()    {}
      void CopyOnly(const CVektor0 &v) {if(this!=&v){ptrArr= v.ptrArr;n=v.getN(); OutFile=v.getF();}}
      CVektor0 &operator=( CVektor0&b){if(this!=&b){ptrArr=b.getPtrArr(); n=b.getN(); OutFile=b.getF();} return *this;}
      CVektor0 &operator=( CVektor &b){if(this!=&b){ptrArr=b.getPtrArr(); n=b.getN();} return *this;}
      CVektor0 &operator+( CVektor &v){if(n==v.getN()){for (size_t i=0; i < n; i++ ) {ptrArr[i]= v.getPtrArr()[i]+ptrArr[i];} return *this;} else {cout << "¬ектора должны быть одинаковой длины!\n"; throw -1;}}
      CVektor0 &operator-( CVektor &v){if(n==v.getN()){for (size_t i=0; i < n; i++ ) {ptrArr[i]= ptrArr[i]-v.getPtrArr()[i];} return *this;} else {cout << "¬ектора должны быть одинаковой длины!\n"; throw -1;}}
      void SetZero(){n=0;}
      void Clean() {ptrArr.clear(); SetZero();}
      const string getF() const{return OutFile;}
      void setText(string c)  { OutFile=c; } 
      int output(const char *FileName); //в строку
};



class CVektor1: public CVektor {
   private:
      string OutFile;
   public:
      CVektor1 (const CVektor1 &v):CVektor(v){if(this!=&v)OutFile=v.OutFile;} 
      CVektor1() {n=0;}
      CVektor1(int num) : CVektor(num){}
      ~CVektor1()    {}
      CVektor1 &operator=( CVektor1&b){if(this!=&b){ptrArr=b.getPtrArr(); n=b.getN(); OutFile=b.getF();} return *this;}
      CVektor1 &operator=( CVektor&b){if(this!=&b){ptrArr=b.getPtrArr(); n=b.getN();} return *this;}
      void SetZero(){n=0;}
      void Clean() {ptrArr.clear(); SetZero();}
      const string getF() const{return OutFile;}
      void setText(string c)  { OutFile=c; } 
      int output(const char *FileName); 
      friend ostream &operator<<(ostream& , CVektor1& );
};


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
