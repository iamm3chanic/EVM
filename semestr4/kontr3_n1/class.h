#pragma once 
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<omp.h>
#include<ctime>
#include<time.h>
#include<chrono>
#include<random>
using namespace std;
class CFabrics;

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
	ComplexNumber operator+(const ComplexNumber &x) {
		ComplexNumber result; 
		result.Re=Re+x.Re; 
		result.Im=Im+x.Im; 
		return result;
	}
	ComplexNumber operator+(const double &x) {
		ComplexNumber result; 
		result.Re=Re+x; 
		result.Im=Im; 
		return result;
	}
	ComplexNumber operator+(const int &x) {
		ComplexNumber result; 
		result.Re=Re+x; 
		result.Im=Im; 
		return result;
	}
	ComplexNumber operator-(const ComplexNumber &x) {
		ComplexNumber result; 
		result.Re=Re-x.Re; 
		result.Im=Im-x.Im; 
		return result;
	}
	ComplexNumber operator-(const double &x) {
		ComplexNumber result;
		 result.Re=Re-x; 
		 result.Im=Im; 
		 return result;
	}
	ComplexNumber operator-(const int &x) {
		ComplexNumber result; 
		result.Re=Re-x; 
		result.Im=Im; 
		return result;
	}
	ComplexNumber operator*(const ComplexNumber &x) {
		ComplexNumber result; 
		result.Re=Re*x.Re-Im*x.Im;
		result.Im=Im*x.Re+Re*x.Im; 
		return result;
	}
	ComplexNumber operator*(const double &x) {
		ComplexNumber result; 
		result.Re=Re*x; 
		result.Im=Im*x; 
		return result;
	}

	ComplexNumber operator*(const int &x) {
		ComplexNumber result; 
		result.Re=Re*x; 
		result.Im=Im*x; 
		return result;
	}
	void Conjugation(){
		Im=-Im;
	}
	friend ostream &operator<<(ostream &stream, const ComplexNumber &number);
	friend istream &operator>>(istream &stream, ComplexNumber &number);
};

ComplexNumber operator+(const int &lhs, const ComplexNumber &rhs);
ComplexNumber operator-(const int &lhs, const ComplexNumber &rhs);
ComplexNumber operator*(const int &lhs, const ComplexNumber &rhs);

ComplexNumber operator+(const double &lhs, const ComplexNumber &rhs);
ComplexNumber operator-(const double &lhs, const ComplexNumber &rhs);
ComplexNumber operator*(const double &lhs, const ComplexNumber &rhs);

class CComplexVector{
protected:
	vector<ComplexNumber> w;
public:
	CComplexVector(){}
	CComplexVector(const int &n){w.resize(n);}
	CComplexVector(const vector<ComplexNumber> rhs, const int &n){w=rhs; w.resize(n);}
	CComplexVector(const vector<ComplexNumber> rhs){w=rhs;}
	CComplexVector(const CComplexVector &rhs){w=rhs.w;}
	CComplexVector(CComplexVector &&rhs){
		w=move(rhs.w);
	}

	size_t Size()const{
		return w.size();
	}
	virtual ~CComplexVector(){}
	virtual void input(const string sf)=0;
	static int ParallelTest(vector<CComplexVector*> &v);

	CComplexVector &operator=(const CComplexVector &rhs){
		if(this!=&rhs){
			w=rhs.w;
			} 
		return *this;
	}
	CComplexVector &operator=(const vector<ComplexNumber> rhs){
		w=rhs;
		 return *this;
	}
	CComplexVector &operator=(CComplexVector &&rhs){
		if(this!=&rhs){
			w=move(rhs.w);
		} return *this;
	}

	ComplexNumber &operator[](size_t i)const{
		return const_cast<ComplexNumber&>(w[i]);
	}

	void Conjugation(){
		for(size_t i=0;i<w.size();i++)w[i].Conjugation();
	}
	void resize(size_t num){
		w.resize(num);
	}
	void Set(ComplexNumber rhs, int i){
		w[i]=rhs;
	}
	void CopyOnly(const CComplexVector &rhs){
		if(this!=&rhs){
			w=rhs.w;
		}
	}
};

class CComplexVector1 : public CComplexVector{
public:
	CComplexVector1(): CComplexVector(){};
	CComplexVector1(const int &n): CComplexVector(n){};
	CComplexVector1(const vector<ComplexNumber> rhs, const int &n): CComplexVector(rhs,n){}
	CComplexVector1(const CComplexVector1 &rhs): CComplexVector(rhs){}

	CComplexVector &operator=(const CComplexVector &rhs){
		if(this!=&rhs){
			CopyOnly(rhs);
		}
	return *this;}
	CComplexVector &operator=(const vector<ComplexNumber> rhs){
		w=rhs; 
		return *this;
	}

	virtual void input(const string sf);
};


// ==== Second Child Class CComplexVector2 ========


class CComplexVector2 : public CComplexVector{
public:
	CComplexVector2(): CComplexVector(){};
	CComplexVector2(const int &n): CComplexVector(n){};
	CComplexVector2(const vector<ComplexNumber> rhs, const int &n): CComplexVector(rhs,n){}
	CComplexVector2(const CComplexVector2 &rhs): CComplexVector(rhs){}

	CComplexVector &operator=(const CComplexVector &rhs){
		if(this!=&rhs){
			CopyOnly(rhs);
		}
		return *this;
	}
	CComplexVector &operator=(const vector<ComplexNumber> rhs){
		w=rhs;
		return *this;
	}

	virtual void input(const string sf);
};

CComplexVector2 operator+(const CComplexVector &lhs, const CComplexVector &rhs);
CComplexVector2 operator-(const CComplexVector &lhs, const CComplexVector &rhs);
ComplexNumber operator*(const CComplexVector &lhs, const CComplexVector &rhs); 


class CFabrics{
public:
	virtual CComplexVector *Create() = 0;
	virtual ~CFabrics() {}
};

class CFabrics1: public CFabrics{
	virtual CComplexVector *Create() {
		return new CComplexVector1;
	}
	virtual ~CFabrics1() {}
};
class CFabrics2: public CFabrics{
	virtual CComplexVector *Create() {
		return new CComplexVector2;
	}
	virtual ~CFabrics2() {}
};

