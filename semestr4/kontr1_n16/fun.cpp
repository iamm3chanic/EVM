
#include<iostream>
#include<fstream>
#include <sstream>
#include"fun.h"


void CVector::CopyOnly(const CVector &v)
    {
     if(this!=&v)
     {memcpy(pointer=new double[n=v.n], v.pointer, v.n*sizeof(double)); }
    }

CVector& CVector::operator=(const CVector& v)
    {
        if(this!=&v) 
        {if(pointer!=NULL)delete [] pointer;
         CopyOnly(v);}
        return *this;
    }
CVector** CVector::Input(const char *fn, size_t *glob)
{

CVector **v=new CVector*[11]; 
memset(v,0,sizeof(CVector*)*11);
std::ifstream finput; 

   finput.open(fn, ios::in);
   if (!finput) {
    cout << "Can't open input file";
    cin.sync(); cin.get(); throw -1;
   }
   
       bool b; double k=0; int n=0;
       char s[15]; string str;
     
      size_t i=0;
     
      while(getline(finput,str))
      {stringstream ss(str);
      ss >> b;
      
      ss >> s;
     
      ss >> n;
    
      if(b==0) { v[i]=new CVector0(n);
                 v[i]->setText(s);
                 }
      else if(b==1) {v[i]=new CVector1(n);
                     v[i]->setText(s);
                    }
    
      for(int j=0;(ss>>k)&&(j<n);j++)
      {
      (*v[i]).setPos(j,k);
  
      }
     
      i++;
       }   
   
       *glob=i;
   
     
    finput.close();
     

return v;
}
   
int CVector0::output(const char *FileName)
{
   
   if(FileName){
   std::ofstream foutput;
   if (!foutput) {
    cout << "Can't open output file";
    cin.sync(); cin.get(); throw -1;
   }
   foutput.open(Outcome, ios::out | ios::app);
       for(size_t i=0;i<n;i++){foutput<<pointer[i]<<" ";} 
       foutput<<endl;
       
    foutput.close();
  }
     return 0;

}
    

int CVector1::output(const char *FileName)
{
  
   if(FileName){
  std::ofstream foutput;
   if (!foutput) {
    cout << "Can't open output file";
    cin.sync(); cin.get(); throw -1;
   }
  
   foutput.open(Outcome, ios::out | ios::app);
   {
       foutput<<"{\n";
       for(size_t i=0;i<n;i++){foutput<<pointer[i]<<endl;} 
       foutput<<"}\n";
          
    foutput.close();
  }
}
return 0;
}
    
    
    
CVector& operator+(const CVector &lhs, const CVector &rhs)
{
 if(lhs.getN()==rhs.getN())
     {
     
     const CVector& u=lhs; 
   
     CVector& l=const_cast<CVector&>(u);
    
     CVector& res=l;
     for (size_t i=0; i < lhs.getN(); i++ ) {
        (res).setPos(i, (lhs).getPointer()[i]+(rhs).getPointer()[i]);
        
        }
     return (res);
     }
    else 
    {
     cout << "The lenth of the vectors should be the same\n"; 
     throw -1;
    }
}
CVector& operator-(const CVector &lhs, const CVector &rhs) 
{
 if(lhs.getN()==rhs.getN())
     {
     const CVector& tmpl=lhs; const CVector& tmpr=rhs;
     CVector& l=const_cast<CVector&>(tmpl);//=const_cast<CVector&>(w);
     CVector& r=const_cast<CVector&>(tmpr);
     CVector& res=r;
     for (size_t i=0; i < lhs.getN(); i++ ) {
        (res)[i]= (l).getPointer()[i]+(r).getPointer()[i];
        }
     return (res);
     }
    else 
    {
     cout << "The lenth of the vectors should be the same\n"; 
     throw -1;
    }
} 

CVector0& operator+(const CVector0 &lhs, const CVector0 &rhs)
{
 if(lhs.getN()==rhs.getN())
     {
      const CVector0& tmpl=lhs; const CVector0& tmpr=rhs;
     CVector0& l=const_cast<CVector0&>(tmpl);
     
     CVector0& res=l;
     for (size_t i=0; i < lhs.getN(); i++ ) {
      const_cast<CVector0&>(res).setPos(i, (lhs).getPointer()[i]+(rhs).getPointer()[i]);
        
        }
        const_cast<CVector0&>(lhs)=const_cast<CVector0&>(tmpl);
        const_cast<CVector0&>(rhs)=const_cast<CVector0&>(tmpr);
     return (res);
     }
    else 
    {
     cout << "The lenth of the vectors should be the same\n"; 
     throw -1;
    }
}
CVector0& operator-(const CVector0 &lhs, const CVector0 &rhs)
{
 if(lhs.getN()==rhs.getN())
     {
      const CVector0& tmpl=lhs; const CVector0& tmpr=rhs;
     CVector0& l=const_cast<CVector0&>(tmpl);
     
     CVector0& res=l;
     for (size_t i=0; i < lhs.getN(); i++ ) {
      const_cast<CVector0&>(res).setPos(i, (lhs).getPointer()[i]-(rhs).getPointer()[i]);
        
        }
        const_cast<CVector0&>(lhs)=const_cast<CVector0&>(tmpl);
        const_cast<CVector0&>(rhs)=const_cast<CVector0&>(tmpr);
     return (res);
     }
    else 
    {
     cout << "The lenth of the vectors should be the same\n"; 
     throw -1;
    }
}
CVector1& operator+ (const CVector1 &lhs, const CVector1 &rhs)
{
 if(lhs.getN()==rhs.getN())
     {
      const CVector1& tmpl=lhs; const CVector1& tmpr=rhs;
     
     const CVector1& res=tmpl;
     for (size_t i=0; i < lhs.getN(); i++ ) {
        const_cast<CVector1&>(res).setPos(i, (lhs).getPointer()[i]+(rhs).getPointer()[i]);
        }
        const_cast<CVector1&>(lhs)=const_cast<CVector1&>(tmpl);
        const_cast<CVector1&>(rhs)=const_cast<CVector1&>(tmpr);
     return const_cast<CVector1&>(res);
     
     }
    else 
    {
     cout << "The lenth of the vectors should be the same\n"; 
     throw -1;
    }
}
CVector1& operator-(const CVector1 &lhs, const CVector1 &rhs)
{
 if(lhs.getN()==rhs.getN())
     {
      const CVector1& tmpl=lhs; const CVector1& tmpr=rhs;
     CVector1& l=const_cast<CVector1&>(tmpl);
     
     CVector1& res=l;
     for (size_t i=0; i < lhs.getN(); i++ ) {
      const_cast<CVector1&>(res).setPos(i, (lhs).getPointer()[i]-(rhs).getPointer()[i]);
        
        }
        const_cast<CVector1&>(lhs)=const_cast<CVector1&>(tmpl);
        const_cast<CVector1&>(rhs)=const_cast<CVector1&>(tmpr);
     return (res);
     }
    else 
    {
     cout << "The lenth of the vectors should be the same\n"; 
     throw -1;
    }
}

double CVector::operator *(const CVector &v)
    {
      double r=0;
     //n=v.n;
     if(n==v.n)
     {
     for (size_t i=0; i < v.n; i++ ) {
        r += v.pointer[i]*pointer[i];
        }
     return r;
     }
    else 
    {
     cout << "The lenth of the vectors should be the same\n"; 
     throw -1;
    }
    }



ostream &operator<<(ostream& cout, CVector &v) 
{
   cout << "Вектор {";
     for (size_t i=0; i < v.n; i++)
     { 
     if(i<v.getN()-1)
 
       cout << v.pointer[i]  << ", ";
     else 
        cout << v.pointer[i] ;
     }    
   cout << "}\n";

return cout;
}
istream &operator>>(istream& cin , CVector &v) 
{
 for (size_t i=0,p; i < v.getN(); i++ )
        {
            cout << "Введите элемент вектора № " << i << ": ";
            cin >> p;     
            v.pointer[i]=p;
        }
return cin;
}


