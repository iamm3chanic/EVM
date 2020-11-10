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
	ComplexNumber ( ComplexNumber && ) = default;
	ComplexNumber (const ComplexNumber & ){}
	double GetRe() const {return Re;}
	double GetIm() const {return Im;}
	ComplexNumber &operator=(const ComplexNumber &x) {this->Re=x.Re; this->Im=x.Im; return *this;}
	ComplexNumber operator+(const ComplexNumber &x) {ComplexNumber result; result.Re=Re+x.Re; result.Im=Im+x.Im; return result;}
	ComplexNumber operator+(const double &x) {ComplexNumber result; result.Re=Re+x; result.Im=Im; return result;}
	ComplexNumber operator+(const int &x) {ComplexNumber result; result.Re=Re+x; result.Im=Im; return result;}
	ComplexNumber operator-(const ComplexNumber &x) {ComplexNumber result; result.Re=Re-x.Re; result.Im=Im-x.Im; return result;}
	ComplexNumber operator-(const double &x) {ComplexNumber result; result.Re=Re-x; result.Im=Im; return result;}
	ComplexNumber operator-(const int &x) {ComplexNumber result; result.Re=Re-x; result.Im=Im; return result;}
	ComplexNumber operator*(const ComplexNumber &x) {ComplexNumber result; result.Re=Re*x.Re-Im*x.Im; result.Im=Im*x.Re+Re*x.Im; return result;}
	ComplexNumber operator*(const double &x) {ComplexNumber result; result.Re=Re*x; result.Im=Im*x; return result;}
	ComplexNumber operator*(const int &x) {ComplexNumber result; result.Re=Re*x; result.Im=Im*x; return result;}
	friend ostream &operator<<(ostream &cout, const ComplexNumber &number);
};

class CComplexVector{
	ComplexNumber v[LENGHT];
public:
	CComplexVector(){for(int i=0; i<LENGHT; i++) v[i]=0;}
	CComplexVector(ComplexNumber *b){*v=*b; }
	//CComplexVector(CComplexVector &b){memcpy(this,&b,LENGHT*2*sizeof(CComplexVector));/*this->v=b.v;*/}
	CComplexVector ( CComplexVector && ) = default;
	CComplexVector(const CComplexVector &){/*memcpy(this,&b,LENGHT*2*sizeof(CComplexVector));*//*this->v=b.v;*/}
	//CComplexVector (const CComplexVector &b )=default;
 	CComplexVector &operator=(const CComplexVector &rhs) {*this=rhs;/*memcpy(this,&rhs,LENGHT*2*sizeof(CComplexVector));*/return *this;}
	CComplexVector operator+(const CComplexVector &rhs){CComplexVector result;for(int i=0; i<LENGHT; i++) result.v[i]=v[i]+rhs.v[i];return result;}
	CComplexVector operator-(const CComplexVector &rhs){CComplexVector result;for(int i=0; i<LENGHT; i++) result.v[i]=v[i]-rhs.v[i];return result;}
	friend ostream &operator<<(ostream &cout, const CComplexVector &vector);
	ComplexNumber operator*(const CComplexVector &rhs);
	void CopyOnly(CComplexVector &rhs){if(&rhs != this)copy(&rhs.v[0], &rhs.v[0] + LENGHT, &v[0]);}
};
void TestComplexNumber();
void TestComplexVector();
ComplexNumber operator+(const int &lhs, const ComplexNumber &rhs);
ComplexNumber operator-(const int &lhs, const ComplexNumber &rhs);
ComplexNumber operator*(const int &lhs, const ComplexNumber &rhs);

ComplexNumber operator+(const double &lhs, const ComplexNumber &rhs);
ComplexNumber operator-(const double &lhs, const ComplexNumber &rhs);
ComplexNumber operator*(const double &lhs, const ComplexNumber &rhs);