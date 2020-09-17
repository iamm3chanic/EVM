#include<iostream>
#include"CClass.h"
using namespace std;

void TestComplexNumber(){
	ComplexNumber n1, n2(1), n3(1,0), n4(0,0), n5(1,1), n6(1,2), n10(2.4,5);
	cout << n1 << " " << n2 << " " << n3 << " " << n4 << " " << n5  << " " << n6 << " " << n10 << endl;
	ComplexNumber n7=n5-n6;
	ComplexNumber n8=n5+n6;
	ComplexNumber n9=n5*n6;
	cout << n7 << " " << n5-n6 << " " << n8 << " " << n9 << endl;
	cout << n10+1 << " " << 1+n10 << " " << n10+1.2 << " " << 1.2+n10 << " " << n10-3.4 << " " << 3.4-n10 << " " << 3*n10 << " " << n10*3 << " " << n10*2.5 << " " << 2.5*n10 << endl;
}

void TestComplexVector(){
	ComplexNumber n1(2,3), n2(3,4), n3(1,0), n4(2,0), n5(0,3), a1[LENGHT], a2[LENGHT], a3[LENGHT];
	for(int i=0; i<LENGHT; i++)
		a1[i]=n1*(i+1);
	CComplexVector v1(a1);
	cout << v1 << endl;
	for(int i=0; i<LENGHT; i++)
			a2[i]=n1*((i^2)/3);
	CComplexVector v2(a2);
	for(int i=0; i<LENGHT; i++)
		a3[i]=n2*((i+1)^2);
	CComplexVector v3(a3);
	cout << v2 << " " << v3 << " " << v2+v3 << " " << v2-v3 << " " << v2*v3 << endl;
	//Только при LENGHT=3;
	ComplexNumber a4[3] {n1,n2,n5}, a5[3] {n2,n1,n3};
	CComplexVector v4(a4), v5(a5);
	cout << v4 << " " << v5 << " " << v4*v5 << endl;
	CComplexVector v6(v4);
	cout << v6 << endl;
}
int main() {
	TestComplexNumber();
	cout << endl;
	TestComplexVector();
	return 0;
}

