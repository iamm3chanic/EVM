
/*
 * Classes.h
 6. Дано множество точек. Найти центр и радиус минимального круга, который содержит все эти точки.
 */
#pragma once
#include <iostream>
#include <math.h>
#include <string.h>
#define DIMENSION 2
using namespace std;
//--------------------------------------------------------------
//----------- Определение класса -------------------------------
//--------------------------------------------------------------
class CDot
{
private:
    double x,y;                      
public:
    CDot (const CDot&)= default;
    CDot()     { SetZero(); }
    CDot(double x1, double y1) { x=x1; y=y1; }
    void SetZero(){x=0;y=0;}
    void SetDot(double x1, double y1) { x=x1; y=y1; }      
    void ShowDot();       //Показать вектор
    double GetX(){return x;}
    double GetY(){return y;}
    CDot& operator=(const CDot& v);
    CDot operator+(const CDot &v);
    CDot operator-(const CDot &v);
    
    friend int NReader();       
    friend ostream &operator <<(ostream &cout, const CDot& );  
    friend istream &operator >>(istream &cin,  CDot& );  
    //friend bool IsInCircle(CDot d, CCircle c);
    friend class CCircle;                           
};  

class CCircle
{
private:
    double r; CDot d;                      
public:
    CCircle (const CCircle&)= default;
    CCircle()     { SetZero(); }
    CCircle(double r1, double x1, double y1) { r=r1; d.SetDot(x1,y1); }
    CCircle(double r1, CDot d1) { r=r1; d=d1; }
    void SetZero(){r=0;d.SetZero();}
    void SetCircle(double r1, double x1, double y1) { r=r1; d.SetDot(x1,y1); }      
    void ShowCircle();   
    CDot GetD() {return d;}  
    double GetR() {return r;} 
    CCircle& operator=(const CCircle& v);

    friend int NReader();       
    friend ostream &operator <<(ostream &cout, CCircle& );  
    friend istream &operator >>(istream &cin, CCircle& ); 
    friend bool IsInCircle(CDot d, CCircle c);
    friend void BuildCircle(CDot *d);
    friend void BuildCircle(CDot *d, int n);
    friend CCircle BuildCircle1(CDot *d, int n);
    friend double FindMax(CDot *d,int n);
    friend CDot* FindMaxD(CDot *d,int n);
    friend class CDot;              
};
  
template <class Type> class AutoFree
{
 public:
  AutoFree():ptr(NULL){};
  AutoFree(Type *p):ptr(p){};
  ~AutoFree()
  {
   if(ptr) {delete[] ptr; ptr=NULL;};
  };
  void own(Type *p)
  { ptr=p; };
 private:
  Type *ptr;
};

int NReader();  
bool IsInCircle(CDot d, CCircle c);
void BuildCircle(CDot *d, int n);
CCircle BuildCircle1(CDot *d, int n);
double FindMax(CDot *d,int n); 
CDot* FindMaxD(CDot *d,int n);
double sqr(double n);
