#include<iostream>
#include"class.h"


// ==== ComplexNumber's Functions ========


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
	double n1, n2; char s, i;
	if(stream >> n1){
		number.Re=n1;
		if(stream.peek()=='\n')
			return stream;
		if(stream >> s){
			if(s=='i')
				number.Im=1;
			else if(s=='+'){
				if(stream >> n2 && stream >> i && i=='i')
					number.Im=n2;
				else if(stream >> i && i=='i')
					number.Im=1;
			}
			else if(s=='-'){
				if(stream >> n2 && stream >> i && i=='i')
					number.Im=-n2;
				else if(stream >> i && i=='i')
					number.Im=-1;
			}
		}
		else
			number.Im=0;
	}
	else{
		if(stream >> s){
			number.Re=0;
			if(s=='i')
				number.Im=1;
			if(s=='-'){
				if(stream >> n2)
					number.Im=n2;
				else
					number.Im=-1;
			}
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


// ==== Show Functions ========


void CComplexVector1::show(const char *sf){
  if(sf){
   std::ofstream foutput;
   if (!foutput) {
    cout << "File error - can't open to write data!";
    cin.sync(); cin.get(); throw -1;
   }
   foutput.open(sf, ios::out | ios::app);
       foutput<<"{\n";
       for(size_t i=0;i<n;i++)
        {
         double im=v[i].GetIm(), re=v[i].GetRe();
		
		if(re>0 || re<0){
			if(im>0)
				foutput<<re<<"+i"<<im<<endl;
			else if(im<0)
				foutput<<re<<"-i"<<-im<<endl;
			else
				foutput<<re<<endl;
		} 
		else{ 
			if(im>0 || im<0)
				foutput<<"i"<<im<<endl;
			else
				foutput<<0<<endl;
		} 
        } 
       foutput<<"}"<<endl;
 
    foutput.close();
  }
     
	/*FILE *f;
	f=fopen(sf,"w");
	fprintf(f, "T1{\n");
	for(int i=0;i<n;i++)
	{
		double im=v[i].GetIm(), re=v[i].GetRe();
		
		if(re>0 || re<0){
			if(im>0)
				fprintf(f,"%f+%fi\n",re,im);
			else if(im<0)
				fprintf(f,"%f%fi\n",re,im);
			else
				fprintf(f,"%f\n",re);
		} 
		else{ 
			if(im>0 || im<0)
				fprintf(f,"%fi\n",im);
			else
				fprintf(f,"0\n");
		} 
			
	}
	fprintf(f, "}\n");
	fclose(f);*/
}

void CComplexVector2::show(const char *sf){
   if(sf){
   std::ofstream foutput;
   if (!foutput) {
    cout << "File error - can't open to write data!";
    cin.sync(); cin.get(); throw -1;
   }
   foutput.open(sf, ios::out | ios::app);
       foutput<<"{ ";
       for(size_t i=0;i<n;i++)
        {
         double im=v[i].GetIm(), re=v[i].GetRe();
		
		if(re>0 || re<0){
			if(im>0)
				foutput<<re<<"+i"<<im<<", ";
			else if(im<0)
				foutput<<re<<"-i"<<-im<<", ";
			else
				foutput<<re<<endl;
		} 
		else{ 
			if(im>0 || im<0)
				foutput<<"i"<<im<<", ";
			else
				foutput<<0<<", ";
		} 
        } 
       foutput<<"}"<<endl;
 
    foutput.close();
    }
	/*FILE *f;
	f=fopen(sf,"w");
	for(size_t i=0;i<n;i++)
	{
		double im=v[i].GetIm(), re=v[i].GetRe();
		fprintf(f, "T2{ ");
		if(re>0 || re<0){
			if(im>0)
				fprintf(f,"%f+%fi ",re,im);
			else if(im<0)
				fprintf(f,"%f%fi ",re,im);
			else
				fprintf(f,"%f ",re);
		} 
	else{ 
		if(im>0 || im<0)
			fprintf(f,"%fi ",im);
		else
			fprintf(f,"0 ");} 
		fprintf(f, "} ");
	}
	fclose(f);*/
}


// ==== ComplexVector2's Functions ========


CComplexVector2 operator+(const CComplexVector &lhs, const CComplexVector &rhs){
	if(lhs.n>rhs.n){
		CComplexVector2 result(lhs.n);
		for(size_t i=0; i<rhs.n; i++)
			result.v[i]=lhs[i]+rhs[i];	
		for(size_t i=rhs.n; i<lhs.n; i++)
			result.v[i]=lhs[i];
		return result;
	}
	else{
		CComplexVector2 result(rhs.n);
		for(size_t i=0; i<lhs.n; i++)
			result.v[i]=lhs[i]+rhs[i];	
		for(size_t i=lhs.n; i<rhs.n; i++)
			result.v[i]=rhs[i];
		return result;
	}
}
CComplexVector2 operator-(const CComplexVector &lhs, const CComplexVector &rhs){
	if(lhs.n>rhs.n){
		CComplexVector2 result(lhs.n);
		for(size_t i=0; i<rhs.n; i++)
			result.v[i]=lhs[i]-rhs[i];	
		for(size_t i=rhs.n; i<lhs.n; i++)
			result.v[i]=lhs[i];
		return result;
	}
	else{
		CComplexVector2 result(rhs.n);
		for(size_t i=0; i<lhs.n; i++)
			result.v[i]=lhs[i]-rhs[i];	
		for(size_t i=lhs.n; i<rhs.n; i++)
			result.v[i]=(-1)*rhs[i];
		return result;
	}
}

ComplexNumber operator*(const CComplexVector &lhs, CComplexVector &rhs){
	ComplexNumber result;
	rhs.Conjugation();
	if(lhs.n>rhs.n){
		for(size_t i=0; i<rhs.n; i++)
			result=result+lhs[i]*rhs[i];
	}
	else{
		for(size_t i=0; i<lhs.n; i++)
			result=result+lhs[i]*rhs[i];
	}
	rhs.Conjugation();
	return result;
}


// ==== Create Function ========


CComplexVector *CComplexVector::create(int Type, const ComplexNumber *b, const int &nn){
	CComplexVector *t;
	if(Type==1){
		t=new CComplexVector1(b,nn);return t;
	}
	else{
		t=new CComplexVector2(b,nn);return t;	
	}
}

/*

void CComplexVector1::show(){
	cout << endl << "T1(";
	for(int i=0; i<n; i++){
		cout << endl << v[i];
	}
	cout << endl << ")";
}

void CComplexVector2::show(){
		cout << endl <<"T2{";
	for(int i=0; i<n; i++){
		if(i==n-1)
			cout << v[i];
		else
			cout << v[i] << " ";
	}
	cout << "}";
}
*/
