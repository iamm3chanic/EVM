#include "CVector.h"

void CVector::SetZero() { v.clear(); }

CVector::CVector(const CVector& b) { CopyOnly(b); }

CVector& CVector::operator=(const CVector& b) {
	if (this != &b) {
		 CopyOnly(b); 
	}
	return *this;
}

CVector::CVector(const vector < double> &b) {
	//this->n = n;
	v = b;
}

void CVector::CopyOnly(const CVector& b) { 
	//n = b.n; 
	v = b.v;
}

void CVector::print() {
	for (auto i = v.begin(); i != v.end(); ++i) cout << *i << ' ';
	cout << endl;
}

int CVector::length()const { return v.size(); }
vector<double> CVector::Vector()const{ return v; }

const double& CVector::operator[](int i) const{
	if (i < 0 || i>=length()) {
		printf("Error.Incorrect index\n");
		throw - 4;
	}
	return v[i];
}
double CVector::operator*(const CVector& b) {
	if (length() != b.length()) {
		printf("Error. Incorrect length\n");
		return 0;
	}
	else {
		double res=0;
		for (int i = 0; i < length(); i++) res+=v[i]*b[i];
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
	if (a.length() != b.length()) {
		printf("Error. Incorrect length\n");
		throw -1;
	}
	
		vector<double>d(a.length());
		for (int i = 0; i < a.length(); i++) d[i] = a.v[i] + b[i];
		CVectorHori res(d); //res=res;
		return res;
	
}
CVectorHori operator-(const CVector& a, const CVector& b) {
	if (a.length() != b.length()) {
		printf("Error. Incorrect length\n");
		throw -1;
	}
	else {
		vector<double>d(a.length());
		for (int i = 0; i < a.length(); i++) d[i] = a.v[i] - b[i];
		CVectorHori res(d);
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

int CVector::OMPTest(const char *fn)
{
 cout << "Starting Parallel Test."<<endl;
 float  var; time_t t1,t2,t3,t4;
 vector<CVectorHori> v; vector<double> p;
 ifstream f(fn); string str;
 while(getline(f,str))
 {
 //cout<<str<<endl;
  stringstream ss(str); istream_iterator<string> it(ss);
  //it=ss;
  if(it!=istream_iterator<string>())
  {
   
    CVectorHori w(p);
    size_t i; 
 
    
    ++it;
    for(i=0;it!=istream_iterator<string>();++it,i++) 
     {
      (w)[i]=atof(it->c_str());  

     }
    v.push_back(w);
   
  }
 }
 
 t1=clock();
    for(size_t j=0;/*(ss>>k)&&*/(j<v.size());j++)
    {
      //v[j]=v[j]*v[j];
      var= v[j] * v[j];
      var=var;
      for(size_t count=0;count<20;count++)
      {
      v[j] = v[j] + v[j];
      v[j] = v[j] - v[j];
      var= v[j] * v[j];
      }
    }
 t2=clock();
    //float Time=(t2-t1);
    //Time=(float)(t2-t1);
 
 cout << "NON-PARALLEL FOR: TIME = "<<t2-t1<<" nanosec"<<endl;
 t3=clock();
#pragma omp parallel for private (var) //shared(w)
    for(size_t j=0;(j<v.size());j++)
    {
      var= v[j] * v[j];
      var=var;
      for(size_t count=0;count<20;count++)
      {
      v[j] = v[j] + v[j];
      v[j] = v[j] - v[j];
      var= v[j] * v[j];
      }
    }
 t4=clock();//localtime(&t2);
    //float Time=(t4-t3);
 
 cout << "PARALLEL FOR: TIME = "<<(t4-t3)/4<<" nanosec"<<endl;
return 0;
}


Temp& Temp::operator=(double c) {
	if (i < 0)throw - 3;
	if (i >= v->length()) {
		//v->length() = i + 1;
		v->v.resize(i + 1);
	}
	v->v[i] = c;
	return*this;
}
Temp::operator double() {
	if (i < 0)throw - 2;
	if (i >= v->length())return 0;
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
