#include "CVector.h"


void CVector::Clean() { SetZero(); }
void CVector::SetZero() { v.clear(); n = 0; }

CVector::CVector(const CVector& b) { CopyOnly(b); }

CVector& CVector::operator=(const CVector& b) {
	if (this != &b) {
		Clean(); CopyOnly(b); 
	}
	return *this;
}

CVector::CVector(const vector < double> &b, int n) {
	this->n = n;
	v = b;
}

void CVector::CopyOnly(const CVector& b) { 
	n = b.n; 
	v = b.v;
}

void CVector::print() {
	for (auto i = v.begin(); i != v.end(); ++i) cout << *i << ' ';
	cout << endl;
}

int CVector::length()const { return n; }
vector<double> CVector::Vector()const{ return v; }

const double& CVector::operator[](int i) const{
	if (i < 0 || i>=n) {
		printf("Error.Incorrect index\n");
		throw - 4;
	}
	return v[i];
}
double CVector::operator*(const CVector& b) {
	if (n != b.n) {
		printf("Error. Incorrect length\n");
		return 0;
	}
	else {
		double res=0;
		for (int i = 0; i < n; i++) res+=v[i]*b[i];
		return res;
	}
}


Temp CVector::operator[](int i) {
	if (i < 0) {
		throw - 1;
	}
	return Temp(this, i);
}

int CVectorHori::output(const string FileName)
{
	ofstream fout(FileName,ios_base::app);
	for (auto i = v.begin(); i != v.end(); ++i) {
		fout << *i << ' ';
	}
	fout << '\n';
	fout.close(); 
    return 0;
}

CVectorHori operator+(const CVector& a, const CVector& b) {
	if (a.n != b.n) {
		printf("Error. Incorrect length\n");
		throw -1;
	}
	
		vector<double>d(a.n);
		for (int i = 0; i < a.n; i++) d[i] = a.v[i] + b[i];
		CVectorHori res(d, a.n); //res=res;
		return res;
	
}
CVectorHori operator-(const CVector& a, const CVector& b) {
	if (a.n != b.n) {
		printf("Error. Incorrect length\n");
		throw -1;
	}
	else {
		vector<double>d(a.n);
		for (int i = 0; i < a.n; i++) d[i] = a.v[i] - b[i];
		CVectorHori res(d, a.n);
		return res;
	}
}

int CVectorVert::output(const string FileName)
{
	ofstream fout(FileName, ios_base::app);
	for (auto i = v.begin(); i != v.end(); ++i) {
		fout << *i << '\n';
	}
	fout << '\n';
	fout.close();
	return 0;
}

Temp& Temp::operator=(double c) {
	if (i < 0)throw - 3;
	if (i >= v->n) {
		v->n = i + 1;
		v->v.resize(i + 1);
	}
	v->v[i] = c;
	return*this;
}
Temp::operator double() {
	if (i < 0)throw - 2;
	if (i >= v->n)return 0;
	return v->v[i];
}

CVector* create(string str, map<string, Fabric*> factory) {
	auto search = factory.find(str);
	if (search == factory.end()) {
		std::cout << "Not found\n";
		throw - 1;
	}
		return factory[str]->Create();
}
