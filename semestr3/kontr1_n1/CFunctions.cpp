#include<iostream>
#include"CClass.h"

ostream &operator<<(ostream &stream, const ComplexNumber &number){
	double Im=number.GetIm(), Re=number.GetRe();
	if(Im==0 && Re==0)
		stream << 0;
	else if(Re==0)
		stream << Im << "i";
	else if(Im>0)
		stream << Re << "+" << Im << "i";
	else if(Im<0)
		stream << Re << Im << "i";
	else
		stream << Re;
	return stream;
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

ostream &operator<<(ostream &stream, const CComplexVector &vector){
	stream << "(";
	for(int i=0; i<LENGHT; i++){
		if(i==LENGHT-1)
			stream << vector.v[i];
		else
			stream << vector.v[i] << " ";
	}
	stream << ")";
	return stream;
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

