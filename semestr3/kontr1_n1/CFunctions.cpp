#include<iostream>
#include"CClass.h"
using namespace std;

ostream &operator<<(ostream &cout, const ComplexNumber &number){
	double Im=number.GetIm(), Re=number.GetRe();
	if(!(Im<0)&&!(Im>0) && !(Re<0)&&!(Re>0))
		cout << "0";
	else if(!(Re<0)&&!(Re>0))
		cout << Im << "i";
	else if(Im>0)
		cout << Re << "+" << Im << "i";
	else if(Im<0)
		cout << Re << Im << "i";
	else
		cout << Re;
	return cout;
}
ComplexNumber operator+(const int &lhs, const ComplexNumber &rhs) {
	ComplexNumber result(lhs+rhs.GetRe(),rhs.GetIm());
	return result;
}
ComplexNumber operator-(const int &lhs, const ComplexNumber &rhs) {
	ComplexNumber result(lhs-rhs.GetRe(),rhs.GetIm());
	return result;
}
ComplexNumber operator*(const int &lhs, const ComplexNumber &rhs) {
	ComplexNumber result(lhs*rhs.GetRe(),lhs*rhs.GetIm());
	return result;
}
ComplexNumber operator+(const double &lhs, const ComplexNumber &rhs) {
	ComplexNumber result(lhs+rhs.GetRe(),rhs.GetIm());
	return result;
}
ComplexNumber operator-(const double &lhs, const ComplexNumber &rhs) {
	ComplexNumber result(lhs-rhs.GetRe(),rhs.GetIm());
	return result;
}
ComplexNumber operator*(const double &lhs, const ComplexNumber &rhs) {
	ComplexNumber result(lhs*rhs.GetRe(),lhs*rhs.GetIm());
	return result;
}

ostream &operator<<(ostream &cout, const CComplexVector &vector){
	cout << "(";
	for(int i=0; i<LENGHT; i++){
		if(i==LENGHT-1)
			cout << vector.v[i];
		else
			cout << vector.v[i] << " ";
	}
	cout << ")";
	return cout;
}

ComplexNumber CComplexVector::operator*(const CComplexVector &rhs){
	CComplexVector res;
	ComplexNumber result;
	for(int i=0; i<LENGHT; i++){
		ComplexNumber r(rhs.v[i].GetRe(), -rhs.v[i].GetIm());
		res.v[i]=r;
	}
	for(int i=0; i<LENGHT; i++){
		result=result+v[i]*res.v[i];
	}
	return result;
}
