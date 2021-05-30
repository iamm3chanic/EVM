#include"class.h"

ostream &operator<<(ostream &stream, const ComplexNumber &number){
	double Im=number.GetIm(), Re=number.GetRe();
	if(Re>0 || Re<0){
	if(Im>0)
		stream << Re << "+" << Im << "i";
	else if(Im<0)
		stream << Re << Im << "i";
	else
		stream << Re;}
	else{ 
		if(Im>0 || Im<0)
			stream << Im << "i";
		else
			stream << 0;}
	return stream;
}
istream &operator>>(istream &stream, ComplexNumber &number){
	string digit;
	stream >> digit;
	istringstream ss(digit);
	if(digit[0]=='i'){
		number.SetRe(0);
		number.SetIm(1);
	}
	else if(digit[0]=='-' && digit[1]=='i'){
		number.SetRe(0);
		number.SetIm(-1);
	}
	else{
		double n1;
		ss >> n1;
		string digit1;
		ss >> digit1;
		if(digit1[0]=='+' && digit1[1]=='i'){
			number.SetRe(n1);
			number.SetIm(1);
		}
		else if(digit1[0]=='-' && digit1[1]=='i'){
			number.SetRe(n1);
			number.SetIm(-1);
		}
		else if(digit1[0]=='i'){
			number.SetRe(0);
			number.SetIm(n1);
		}
		else{
			istringstream sss(digit1);
			double n2;
			number.SetRe(n1);
			if(sss >> n2)
				number.SetIm(n2);
		}
	}
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

CComplexVector2 operator+(const CComplexVector &lhs, const CComplexVector &rhs){
	time_t t1, t2;
	float Time;
	ofstream out;
	out.open("log-check.txt",ios::app);
	time(&t1);
	if(lhs.Size()>rhs.Size()){
		CComplexVector2 result(lhs.Size());
		#pragma omp parallel for
		for(size_t i=0; i<rhs.Size(); i++){
			ComplexNumber tmp=lhs[i]+rhs[i];
			result.Set(tmp,i);	
		}
		#pragma omp parallel for
		for(size_t i=rhs.Size(); i<lhs.Size(); i++)
			result.Set(lhs[i],i);
		return result;
	}
	else{
		CComplexVector2 result(rhs.Size());
		#pragma omp parallel for
		for(size_t i=0; i<lhs.Size(); i++){
			ComplexNumber tmp=lhs[i]+rhs[i];
			result.Set(tmp,i);	
		}
		#pragma omp parallel for
		for(size_t i=lhs.Size(); i<rhs.Size(); i++)
			result.Set(rhs[i],i);
		return result;
	}
	time(&t2);
	Time=static_cast<float>(t2-t1);
	//Time=Time;
	out << "TIME for operator+ : "<<Time<<"sec"<<endl;
	out.close();
}
CComplexVector2 operator-(const CComplexVector &lhs, const CComplexVector &rhs){
	if(lhs.Size()>rhs.Size()){
		CComplexVector2 result(lhs.Size());
		#pragma omp parallel for
		for(size_t i=0; i<rhs.Size(); i++){
			ComplexNumber tmp=lhs[i]-rhs[i];
			result.Set(tmp,i);	
		}
		#pragma omp parallel for
		for(size_t i=rhs.Size(); i<lhs.Size(); i++)
			result.Set(lhs[i],i);
		return result;
	}
	else{
		CComplexVector2 result(rhs.Size());
		#pragma omp parallel for
		for(size_t i=0; i<lhs.Size(); i++){
			ComplexNumber tmp=lhs[i]-rhs[i];
			result.Set(tmp,i);
		}
		#pragma omp parallel for
		for(size_t i=lhs.Size(); i<rhs.Size(); i++){
			ComplexNumber tmp=(-1)*rhs[i];
			result.Set(tmp,i);
		}
		return result;
	}
}

ComplexNumber operator*(const CComplexVector &lhs, const CComplexVector &rhs){
	ComplexNumber result;
	if(lhs.Size()>rhs.Size()){
		#pragma omp parallel for
		for(size_t i=0; i<rhs.Size(); i++){
			ComplexNumber tmp=rhs[i];
			tmp.Conjugation();
			result=result+lhs[i]*tmp;
		}
	}
	else{
		#pragma omp parallel for
		for(size_t i=0; i<lhs.Size(); i++){
			ComplexNumber tmp=rhs[i];
			tmp.Conjugation();
			result=result+lhs[i]*tmp;
		}
	}
	return result;
}


void CComplexVector1::input(const string sf){
	ofstream out;
	out.open(sf);
	out << "Type-1(";
	for(size_t i=0; i<w.size();i++){
		out << w[i] << " ";
	}
	out << ")" << endl;
	out.close();
}

void CComplexVector2::input(const string sf){
	ofstream out;
	out.open(sf);
	out << "Type-2(";
	for(size_t i=0; i<w.size();i++){
		out << w[i] << endl;
	}
	out << ")" << endl;
	out.close();
}

int CComplexVector::ParallelTest(vector<CComplexVector*> &v)
{
 cout << "Starting Parallel Test."<<endl;
 float Time=0; time_t t1,t2;
 ComplexNumber var;
 time(&t1);
    for(size_t j=0;/*(ss>>k)&&*/(j<v.size());j++)
    {
      var= *v[j] * *v[j];
      var=var;
      for(size_t count=0;count<7000;count++)
      {
      *v[j] = *v[j] + *v[j];
      *v[j] = *v[j] - *v[j];
      var= *v[j] * *v[j];
      }
    }
 time(&t2);
    Time=static_cast<float>(t2-t1);
 cout << "NON-PARALLEL FOR: TIME = "<<Time<<"sec"<<endl;
 time(&t1);
#pragma omp parallel for private (var)//shared(w)
    for(size_t j=0;/*(ss>>k)&&*/(j<v.size());j++)
    {
      var= *v[j] * *v[j];
      var=var;
      for(size_t count=0;count<7000;count++)
      {
      *v[j] = *v[j] + *v[j];
      *v[j] = *v[j] - *v[j];
      var= *v[j] * *v[j];
      }
    }
 time(&t2);
    Time=static_cast<float>(t2-t1);
 
 cout << "PARALLEL FOR: TIME = "<<Time<<"sec"<<endl;
return 0;
}
