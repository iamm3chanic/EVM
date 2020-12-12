/*ПОКА НЕ ГОТОВО*/
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

template<class T,int n_=13> class CSet
{
	T *v;
	char *used;
	int nused;
	int n;
public:
	CSet(){n=n_; v=new T[n]; used=new char[(n+7)/8]; memset(used,0,(n+7)/8); nused=0;}
	~CSet(){clean();}
	void clean(){delete[] v; delete[] used; SetZero();}
	void SetZero(){v=NULL;used=NULL;nused=0;n=0;}
	int h(const T&x){return x%n;}
	bool Used(int i){return used[i/8]&(1<<(i%8));}
	void SetUsed(int i){ used[i/8]|=(1<<(i%8));}
	void SetUnused(int i){ used[i/8]&=~(1<<(i%8));}
	int Find(const T&x){int i; for(i=h(x);Used(i);i=(i+1)%n){if(x==v[i])return 1;} return 0;}
	int Insert(const T&x){if(nused>=n-1)return -2; int i; for(i=h(x);Used(i);i=(i+1)%n){if(x==v[i])return -1;} SetUsed(i); v[i]=x; nused++; return 0;}
	void show(ostream &cout){cout<<"{"; for(int i=0;i<n;i++){if(Used(i))cout<<v[i]<<" ";}cout<< "}" << endl;}
	int Erase(const T&x){int i; for(i=h(x);Used(i);i=(i+1)%n){if(x==v[i]){clean(i); nused--; return 0;}} return -1;}
	void clean(int i);
};

template<class T,int n_> ostream &operator<<(ostream &cout, CSet<T,n_> &s){s.show(cout);return cout;}

template<class T,int n_> void CSet<T,n_>::clean(int i){
	int j;
	SetUnused(i);
	for(j=(i+1)%n;Used(j);j=(j+1)%n) if((h(v[j])<=i&&i<j) || (j<h(v[j])&&h(v[j])<=i) || (i<j&&j<h(v[j])) )
		{v[i]=v[j]; SetUsed(i); clean(j); break;}
}

int main(void){
	CSet<int> s;
	for(int i=0;i<11;i++){s.Insert(i*i);cout<<s;}
	for(int i=0;i<11;i++){if(s.Find(i*i)) cout<<"ok ";else cout<<"error"; }
	if(s.Find(15*15))
		{cout<<"error ";}
	else {cout <<"not found";}
	cout<<endl; cout<< " " <<endl;
	for(int i=0;i<11;i++){s.Erase(i*i);cout<<s;}
	return 0;
}
