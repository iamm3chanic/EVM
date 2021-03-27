#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;
class Temp;
class CVectorHori;
class CVectorVert;


class CVector {
protected:
	vector<double> v;
	int n;
	string filename;
public:
	virtual int output(const string FileName) = 0;
	void SetFileName(const string s) { filename = s; };
	const string GetFileName() const{ return filename; };
	
	CVector() { SetZero(); }
	virtual ~CVector() { Clean(); }
	void Clean();
	void SetZero();
	CVector(const CVector& b);
	CVector(const vector<double> &b, int n);
	CVector& operator=(const CVector& b);
	void CopyOnly(const CVector& b);
	void print();
	int length()const;
	void Setn(int m) { Clean(); n = m; v.resize(n); }
	vector<double> Vector()const;
	const double& operator[](int i) const;
	double operator*(const CVector& b);
	Temp operator[](int i);
	friend class Temp;
	friend CVectorHori operator+(const CVector& a, const CVector& b);
	friend CVectorHori operator-(const CVector& a, const CVector& b);
};

class Temp
{
	CVector* v; int i;
	public:
		Temp(CVector* v, int i) { this->v = v; this->i = i; }
		Temp& operator=(double c);
		operator double();
};



class CVectorHori : public CVector
{
public:
	//using CVector::operator=;
	//CVectorHori &operator=(const CVectorHori &b){if(this!=&b){v=b.Vector(); n=b.length(); filename=b.GetFileName();} return *this;}
	//CVectorHori &operator=( CVectorHori b){if(this!=&b){v=b.Vector(); n=b.length(); filename=b.GetFileName();} return *this;}
        CVectorHori &operator=( CVector &b){if(this!=&b){v=b.Vector(); n=b.length(); filename=b.GetFileName();} return *this;}
	CVectorHori(){}
	~CVectorHori() {}
	CVectorHori(const CVector& b) : CVector(b) {}
	CVectorHori(const vector<double> b, int n) : CVector(b, n) {}
	friend CVectorHori operator+(const CVector& a, const CVector& b);
	friend CVectorHori operator-(const CVector& a, const CVector& b);
	int output(const string FileName) override;
};
class CVectorVert : public CVector
{
public:
	using CVector::operator=;
	CVectorVert() {}
	~CVectorVert() {}
	CVectorVert(const CVector& b) : CVector(b) {}
	CVectorVert(const vector<double> b, int n) :CVector(b, n) {}
	int output(const string FileName) override;
};

class Fabric
{
public:
	virtual CVector* Create() = 0;
	virtual ~Fabric() {}
};

class FabricHori : public Fabric {
public:
	virtual CVector* Create() override { return new CVectorHori; }
	virtual ~FabricHori() {}
};

class FabricVert : public Fabric {
public:
	virtual CVector* Create() override { return new CVectorVert; }
	virtual ~FabricVert() {}
};


extern CVector* create(string str, map<string, Fabric*> factory); 
