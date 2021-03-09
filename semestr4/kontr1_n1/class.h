#pragma once 
#include<iostream>
#include<fstream>
#include<cstring>
#include<time.h>
using namespace std;


// ==== Class ComplexNumber ========


class ComplexNumber{
	double Re, Im;
public:
	ComplexNumber(){Re=0; Im=0;}
	ComplexNumber(double x){Re=x; Im=0;}
	ComplexNumber(double Re, double Im){this->Re=Re; this->Im=Im;}
	double GetRe() const {return Re;}
	double GetIm() const {return Im;}
	void SetRe(double Re) {this->Re=Re;}
	void SetIm(double Im) {this->Im=Im;}
	ComplexNumber operator+(const ComplexNumber &x) {ComplexNumber result; result.Re=Re+x.Re; result.Im=Im+x.Im; return result;}
	ComplexNumber operator+(const double &x) {ComplexNumber result; result.Re=Re+x; result.Im=Im; return result;}
	ComplexNumber operator+(const int &x) {ComplexNumber result; result.Re=Re+x; result.Im=Im; return result;}
	ComplexNumber operator-(const ComplexNumber &x) {ComplexNumber result; result.Re=Re-x.Re; result.Im=Im-x.Im; return result;}
	ComplexNumber operator-(const double &x) {ComplexNumber result; result.Re=Re-x; result.Im=Im; return result;}
	ComplexNumber operator-(const int &x) {ComplexNumber result; result.Re=Re-x; result.Im=Im; return result;}
	ComplexNumber operator*(const ComplexNumber &x) {ComplexNumber result; result.Re=Re*x.Re-Im*x.Im; result.Im=Im*x.Re+Re*x.Im; return result;}
	ComplexNumber operator*(const double &x) {ComplexNumber result; result.Re=Re*x; result.Im=Im*x; return result;}
	ComplexNumber operator*(const int &x) {ComplexNumber result; result.Re=Re*x; result.Im=Im*x; return result;}
	void Conjugation(){Im=-Im;}
	friend ostream &operator<<(ostream &stream, const ComplexNumber &number);
	friend istream &operator>>(istream &stream, ComplexNumber &number);
};

ComplexNumber operator+(const int &lhs, const ComplexNumber &rhs);
ComplexNumber operator-(const int &lhs, const ComplexNumber &rhs);
ComplexNumber operator*(const int &lhs, const ComplexNumber &rhs);

ComplexNumber operator+(const double &lhs, const ComplexNumber &rhs);
ComplexNumber operator-(const double &lhs, const ComplexNumber &rhs);
ComplexNumber operator*(const double &lhs, const ComplexNumber &rhs);


// ==== Base Class CComplexVector ========


class CComplexVector{	
public:
	ComplexNumber *v; size_t n;

	CComplexVector(){SetZero();}
	CComplexVector(const int &n){this->n=n; v=new ComplexNumber[this->n];}
	CComplexVector(const CComplexVector &rhs){CopyOnly(rhs);}
	virtual ~CComplexVector(){Clean();}

	static CComplexVector *create(int Type, const ComplexNumber *b, const int &nn);

	CComplexVector &operator=(const CComplexVector &rhs){if(this!=&rhs){Clean();CopyOnly(rhs);} return *this;}
	CComplexVector &operator=(CComplexVector &&rhs){if(this!=&rhs){delete v; n=rhs.n;v=rhs.v;rhs.SetZero();} return *this;}

	virtual void show(const char *sf) = 0;

	ComplexNumber &operator[](size_t i) const{return v[i];}

	void Conjugation(){for(size_t i=0;i<n;i++)v[i].Conjugation();}

	void SetZero(){v=NULL; n=0;}
	void Clean(){delete[] v; SetZero();}
	void CopyOnly(const CComplexVector &rhs){if(this!=&rhs){v=new ComplexNumber[n=rhs.n];memcpy(v,rhs.v,n*sizeof(ComplexNumber));}}
	void CopyOnly(const ComplexNumber *rhs, const int &n){this->n=n;memcpy(v=new ComplexNumber[this->n],rhs,(n)*sizeof(ComplexNumber));}                                                  
	
};


// ==== CComplexVector1 ========


class CComplexVector1 : public CComplexVector{
public:
	CComplexVector1(): CComplexVector(){};
	CComplexVector1(const size_t &n): CComplexVector(n){};
	CComplexVector1(const ComplexNumber *rhs, const int &n){this->n=n;CopyOnly(rhs,n);}
	CComplexVector1(const CComplexVector1 &rhs): CComplexVector(rhs){}
	CComplexVector1(CComplexVector1 &&rhs){n=rhs.n;v=rhs.v; rhs.SetZero();}

	CComplexVector &operator=(const CComplexVector &rhs){if(this!=&rhs){Clean();CopyOnly(rhs);} return *this;}
	CComplexVector &operator=(CComplexVector &&rhs){if(this!=&rhs){delete v; n=rhs.n;v=rhs.v;rhs.SetZero();} return *this;}

	virtual void show(const char *sf);
};


// ==== CComplexVector2 ========


class CComplexVector2 : public CComplexVector{
public:
	CComplexVector2(): CComplexVector(){};
	CComplexVector2(const size_t &n): CComplexVector(n){};
	CComplexVector2(const ComplexNumber *rhs, const int &n){this->n=n;CopyOnly(rhs,n);}
	CComplexVector2(const CComplexVector2 &rhs): CComplexVector(rhs){}
	CComplexVector2(CComplexVector2 &&rhs){n=rhs.n;v=rhs.v; rhs.SetZero();}

	CComplexVector &operator=(const CComplexVector &rhs){if(this!=&rhs){Clean();CopyOnly(rhs);} return *this;}
	CComplexVector &operator=(CComplexVector &&rhs){if(this!=&rhs){delete v; n=rhs.n;v=rhs.v;rhs.SetZero();} return *this;}

	virtual void show(const char *sf);
};


CComplexVector2 operator+(const CComplexVector &lhs, const CComplexVector &rhs);
CComplexVector2 operator-(const CComplexVector &lhs, const CComplexVector &rhs);
ComplexNumber operator*(const CComplexVector &lhs, CComplexVector &rhs); 


// ==== Test Functoins ========


void Test();
