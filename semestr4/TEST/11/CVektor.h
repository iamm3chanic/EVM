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
    vector<int> ptrArr;     //Указатель на массив элементов
public:
    CVektor (const CVektor&v) {CopyOnly(v);}
    CVektor(const vector<int>v,int n){CopyOnly(v,n);}
    CVektor()      { SetZero(); }
    CVektor(size_t num)   { n = num;  for(size_t i=0;i<num;i++) ptrArr.push_back(0); }
    virtual ~CVektor()    { Clean(); }
    
    CVektor ( CVektor && ) = default; 	//move constructor
    //CVektor&  operator= ( CVektor&& );  //move assignment
    size_t getN() const{ return n; }  
    vector<int> getPtrArr() const{ return ptrArr; }
    void SetZero(){n=0;}
    void Clean() {ptrArr.clear();/*if(ptrArr!=NULL)delete [] ptrArr;*/ SetZero();}
    void setPtrArr(vector<int> arr)  { for (size_t i=0; i < n; i++ ) {ptrArr[i] = arr[i]; } } 
    void GetVektor();
    void ShowVektor();
    void CopyOnly(const CVektor &v);
    void CopyOnly(const vector<int>v,int num){this->ptrArr=v; n=num;}
    void setPos(size_t i, int f) {if(/*i<0||*/i>=n) 
     {vector<int> tmp; for(size_t j=0;j<n;j++){tmp.push_back(ptrArr[j]);} 
     for(size_t j=n+1;j<i;j++){tmp.push_back(0);} tmp.push_back(f); ptrArr=tmp;n=i+1; }
     else ptrArr[i]=f;}
    /*const*/ CVektor& operator=(const CVektor& v);
    /*const //CVektor& operator+(const CVektor &v);*/
    /*const  CVektor& operator-(const CVektor &v);*/
    int operator *(const CVektor &v);
    int &operator[](size_t i){if(/*i<0||*/i>n-1) throw -1; return (this->ptrArr)[i];}
    //int &operator[](int i){if(i<0||i>n-1) throw -1; return ptrArr[i];}

    virtual int output()=0;
    virtual const string getF()const=0;
    virtual void setText(string c)=0;
    virtual int cmp(int a, int b) {if(a==b) return 0;if(a<b) return -1; return 1;}
    
    void DeleteOne(int det);
    void DeleteSame();
    
    static int Input(const char *fn, vector<CVektor*> &v, vector<CFabricVektor*> &fabric);
    
 
    friend ostream &operator<<(ostream& /*&cout*/, CVektor& );
    friend istream &operator>>(istream& /*&cin*/, CVektor& ); 
};

//CVektor& operator+(const CVektor &lhs, const CVektor &rhs);
//CVektor& operator-(const CVektor &lhs, const CVektor &rhs);


class CVektor1: public CVektor {
   private:
      string OutFile;
   public:
      CVektor1 (const CVektor1 &v):CVektor(v){if(this!=&v)OutFile=v.OutFile;} 
      CVektor1 (const vector<int>v,int num): CVektor(v,num){}
      CVektor1() {n=0;}
      CVektor1(int num) : CVektor(num){}//OutFile[sizeof(OutFile)-1]='\0';}
      //CVektor0(int num)   { n = num;   ptrArr = new int [num];  }
      ~CVektor1()    {/*delete [] ptrArr; ptrArr=NULL;n=0;*/}
      //~CVektor0() : ~CVektor() {}
      CVektor1 &operator=( CVektor1&b){if(this!=&b){ptrArr=b.getPtrArr(); n=b.getN(); OutFile=b.getF();} return *this;}
      CVektor1 &operator=( CVektor&b){if(this!=&b){ptrArr=b.getPtrArr(); n=b.getN();} return *this;}
      void SetZero(){n=0;}
      void Clean() {ptrArr.clear(); SetZero();}
      const string getF() const{return OutFile;}
      void setText(string c)  { OutFile=c; } 
      int output(); 
      virtual int cmp(int a, int b) {if(a==b) return 0;if(a<b) return -2; return 2;}
      friend ostream &operator<<(ostream& , CVektor1 );
};

CVektor1 operator+(const CVektor1&a,const CVektor1&b);
CVektor1 operator-(const CVektor1&a,const CVektor1&b);

class CFabricVektor
{
public:
 virtual CVektor *Create() = 0;
 virtual ~CFabricVektor() {}
};


class CFabricVektor1: public CFabricVektor
{
public:
 virtual CVektor *Create() {return new CVektor1;}
 virtual ~CFabricVektor1() {}
};
