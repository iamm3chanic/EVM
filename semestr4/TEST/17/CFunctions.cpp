#include"CVektor.h"


void CVektor::CopyOnly(const CVektor &v)
    {
     if(this!=&v)
     {ptrArr=v.ptrArr; n=v.n; }
    }
void CVektor::GetVektor()        
    {
        
        for (size_t i=0; i < n; i++ )
        {
            cout << "Введите элемент вектора  " << i << ": ";
            cin >> ptrArr[i];
        }
    }
void CVektor::ShowVektor()       
    {
        cout << "Вектор {";
        for (size_t i=0; i < n; i++)
        {  
         if(i<n-1)
            cout << ptrArr[i] << ", ";
         else
            cout << ptrArr[i];
        }    
        cout << "}\n";
    }
 
CVektor& CVektor::operator=(const CVektor& v)
    {
        if(this!=&v) 
        {
         CopyOnly(v);}
        return *this;
    }
    
int CVektor::Input(const char *fn, vector<CVektor*> &v, vector<CFabricVektor*> &fabric)
{
 ifstream f(fn); string str;
 while(getline(f,str))
 {

  stringstream ss(str); istream_iterator<string> it(ss);
  if(it!=istream_iterator<string>())
  {
   if((*it)[0]-'0'>=0 && (*it)[0]-'1' < static_cast<int>(fabric.size()))
   {
    CVektor *w=fabric[(*it)[0]-'0']->Create();
    size_t i; int b;char s[15]={0}; 
    b=(*it)[0]-'0';
    ++it;
    strcpy(s,it->c_str());
    ++it;
      cout<<"b="<<b<<endl;
      cout<<"s="<<s<<endl;
    (*w).setText(s);
    for(i=0;/*i<n &&*/ it!=istream_iterator<string>();++it,i++) 
     {
      (*w).setPos(i,atof(it->c_str()));  
     }
     cout<<"vec="<<*w;
    v.push_back(w);
   }
  }
 }
return 0;
}

   
int CVektor0::output(const char *FileName)
{
   
   if(FileName){
   std::ofstream foutput;
   if (!foutput) {
    cout << "File error - can't open to write data!";
    cin.sync(); cin.get(); throw -1;
   }
   foutput.open(OutFile, ios::out | ios::app);
       for(size_t i=0;i<n;i++){foutput<<ptrArr[i]<<" ";} 
       foutput<<endl;
       
    foutput.close();
  }
     return 0;

}
    

int CVektor1::output(const char *FileName)
{
  
   if(FileName){
  std::ofstream foutput;
   if (!foutput) {
    cout << "File error - can't open to write data!";
    cin.sync(); cin.get(); throw -1;
   }
  
   foutput.open(OutFile, ios::out | ios::app);
   {
       foutput<<"{\n";
       for(size_t i=0;i<n;i++){foutput<<" "<<ptrArr[i]<<endl;} 
       foutput<<"}\n";
        
          
    foutput.close();
  }
}
return 0;
}
    
    
    

CVektor& operator+(const CVektor &lhs, const CVektor &rhs)
{
 if(lhs.getN()==rhs.getN())
     {
     
     const CVektor& u=lhs; 
     CVektor& l=const_cast<CVektor&>(u);
     CVektor& res=l;
     for (size_t i=0; i < lhs.getN(); i++ ) {
        (res).setPos(i, (lhs).getPtrArr()[i]+(rhs).getPtrArr()[i]);
        }
     return (res);
     }
    else 
    {
     cout << "Вектора должны быть одинаковой длины!\n"; 
     throw -1;
    }
}
CVektor& operator-(const CVektor &lhs, const CVektor &rhs) 
{
 if(lhs.getN()==rhs.getN())
     {
     const CVektor& tmpl=lhs; const CVektor& tmpr=rhs;
     CVektor& l=const_cast<CVektor&>(tmpl);
     CVektor& r=const_cast<CVektor&>(tmpr);
     CVektor& res=r;
     for (size_t i=0; i < lhs.getN(); i++ ) {
        (res)[i]= (l).getPtrArr()[i]+(r).getPtrArr()[i];
        }
     return (res);
     }
    else 
    {
     cout << "Вектора должны быть одинаковой длины!\n"; 
     throw -1;
    }
} 

CVektor1& operator+ (const CVektor1 &lhs, const CVektor1 &rhs)
{
 if(lhs.getN()==rhs.getN())
     {
      const CVektor1& tmpl=lhs; const CVektor1& tmpr=rhs;
     const CVektor1& res=tmpl;
     for (size_t i=0; i < lhs.getN(); i++ ) {
        const_cast<CVektor1&>(res).setPos(i, (lhs).getPtrArr()[i]+(rhs).getPtrArr()[i]);
        }
        const_cast<CVektor1&>(lhs)=const_cast<CVektor1&>(tmpl);
        const_cast<CVektor1&>(rhs)=const_cast<CVektor1&>(tmpr);
     return const_cast<CVektor1&>(res);
     }
    else 
    {
     cout << "Вектора должны быть одинаковой длины!\n"; 
     throw -1;
    }
}
CVektor1& operator-(const CVektor1 &lhs, const CVektor1 &rhs)
{
 if(lhs.getN()==rhs.getN())
     {
      const CVektor1& tmpl=lhs; const CVektor1& tmpr=rhs;
     CVektor1& l=const_cast<CVektor1&>(tmpl);
     CVektor1& res=l;
     for (size_t i=0; i < lhs.getN(); i++ ) {
      const_cast<CVektor1&>(res).setPos(i, (lhs).getPtrArr()[i]-(rhs).getPtrArr()[i]);
        }
        const_cast<CVektor1&>(lhs)=const_cast<CVektor1&>(tmpl);
        const_cast<CVektor1&>(rhs)=const_cast<CVektor1&>(tmpr);
     return (res);
     }
    else 
    {
     cout << "Вектора должны быть одинаковой длины!\n"; 
     throw -1;
    }
}


ostream &operator<<(ostream& cout, CVektor &v) 
{
   cout << "Вектор {";
     for (size_t i=0; i < v.n; i++)
     { 
     if(i<v.getN()-1)
       cout << v.ptrArr[i]  << ", ";
     else  
        cout << v.ptrArr[i] ;
     }    
   cout << "}\n";

return cout;
}

ostream &operator<<(ostream& cout, CVektor1 &v) 
{
   cout << "Вектор { ";
     for (size_t i=0; i < v.n; i++)
     { 
       cout << v.ptrArr[i]  << " ";
     }    
   cout << "}\n";

return cout;
}

istream &operator>>(istream& cin , CVektor &v) 
{
 for (size_t i=0,p; i < v.getN(); i++ )
        {
            cout << "Введите элемент вектора № " << i << ": ";
            cin >> p;      
            v.ptrArr[i]=p;
        }
return cin;
}
