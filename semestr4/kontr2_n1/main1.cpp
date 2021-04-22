#include"class.h"

int main(){
	vector<CFabrics*> fabric;
	vector<CComplexVector*> w;
	fabric.push_back(new CFabrics1);
	fabric.push_back(new CFabrics2);
	ifstream in("in.txt"); string str;
	while(getline(in,str)){
		int Type; string outfile; vector<ComplexNumber> vectmp;
		stringstream ss(str);
		ss >> Type >> outfile;
		for(ComplexNumber tmp;ss >> tmp;){
			vectmp.push_back(tmp);
		}
		CComplexVector *t=fabric[Type-1]->Create();
		*t=vectmp;
		t->input(outfile);
		w.push_back(t);
	}
	for(size_t i=0;i<w.size();i++){
		delete w[i];
	}
	for(size_t i=0;(i<fabric.size());i++)  {delete fabric[i];}
	return 0;
}
