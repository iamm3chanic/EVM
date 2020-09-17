#pragma once
#define LENGHT 3
#include<string.h>
using namespace std;

class ComplexNumber{
	double Re, Im;
public:
	ComplexNumber(){Re=0; Im=0;}
	ComplexNumber(double x){Re=x; Im=0;}
	ComplexNumber(double Re, double Im){this->Re=Re; this->Im=Im;}
	double GetRe() const {return Re;}
	double GetIm() const {return Im;}
	ComplexNumber operator+(const ComplexNumber &x) {ComplexNumber result; result.Re=Re+x.Re; result.Im=Im+x.Im; return result;}
	ComplexNumber operator+(const double &x) {ComplexNumber result; result.Re=Re+x; result.Im=Im; return result;}
	ComplexNumber operator+(const int &x) {ComplexNumber result; result.Re=Re+x; result.Im=Im; return result;}
	ComplexNumber operator-(const ComplexNumber &x) {ComplexNumber result; result.Re=Re-x.Re; result.Im=Im-x.Im; return result;}
	ComplexNumber operator-(const double &x) {ComplexNumber result; result.Re=Re-x; result.Im=Im; return result;}
	ComplexNumber operator-(const int &x) {ComplexNumber result; result.Re=Re-x; result.Im=Im; return result;}
	ComplexNumber operator*(const ComplexNumber &x) {ComplexNumber result; result.Re=Re*x.Re-Im*x.Im; result.Im=Im*x.Re+Re*x.Im; return result;}
	ComplexNumber operator*(const double &x) {ComplexNumber result; result.Re=Re*x; result.Im=Im*x; return result;}
	ComplexNumber operator*(const int &x) {ComplexNumber result; result.Re=Re*x; result.Im=Im*x; return result;}
	friend ostream &operator<<(ostream &stream, const ComplexNumber &number);
};

class CComplexVector{
	ComplexNumber v[LENGHT];
public:
	CComplexVector(){for(int i=0; i<LENGHT; i++) v[i]=0;}
	CComplexVector(ComplexNumber *b){memcpy(v,b,LENGHT*2*sizeof(b));}
	CComplexVector(CComplexVector &b){memcpy(this,&b,sizeof(b));}
	CComplexVector &operator=(const CComplexVector &rhs) {for(int i=0; i<LENGHT; i++) v[i]=rhs.v[i];return *this;}
	CComplexVector operator+(const CComplexVector &rhs){CComplexVector result;for(int i=0; i<LENGHT; i++) result.v[i]=v[i]+rhs.v[i];return result;}
	CComplexVector operator-(const CComplexVector &rhs){CComplexVector result;for(int i=0; i<LENGHT; i++) result.v[i]=v[i]-rhs.v[i];return result;}
	friend ostream &operator<<(ostream &stream, const CComplexVector &vector);
	ComplexNumber operator*(const CComplexVector &rhs);
};
void TestComplexNumber();
void TestComplexVector();
ComplexNumber operator+(const int &lhs, const ComplexNumber &rhs);
ComplexNumber operator-(const int &lhs, const ComplexNumber &rhs);
ComplexNumber operator*(const int &lhs, const ComplexNumber &rhs);

ComplexNumber operator+(const double &lhs, const ComplexNumber &rhs);
ComplexNumber operator-(const double &lhs, const ComplexNumber &rhs);
ComplexNumber operator*(const double &lhs, const ComplexNumber &rhs);
