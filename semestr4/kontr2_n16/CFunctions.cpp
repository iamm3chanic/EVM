/*
 * CFunctions.cpp
 */
 
#include"CVector.h"
//#include <omp.h>
//////////////////CLASS METHODS///////////////////////////
//////CVector
void CVector::CopyOnly(const CVector &v)
    {
     if(this!=&v)
     {pointer=v.pointer;}
    }
void CVector::GetVector()        //Задать вектор
    {
        //cout << "Введите размерность вектора: "; cin >> n;
        for (size_t i=0; i < pointer.size(); i++ )
        {
            cout << "Введите элемент вектора № " << i << ": ";
            cin >> pointer[i];
        }
    }
void CVector::ShowVector()       //Показать вектор
    {
        cout << "Вектор {";
        for (size_t i=0; i < pointer.size(); i++)
        {  
         if(i<pointer.size()-1)
            cout << pointer[i] << ", ";
         else
            cout << pointer[i];
        }    
        cout << "}\n";
    }
 
CVector& CVector::operator=(const CVector& v)
    {
        if(this!=&v) 
        {//if(pointer!=NULL) //delete [] pointer;
         CopyOnly(v);}
        return *this;
    }

/*static */
int CVector::Input(const char *fn, vector<CVector*> &v, vector<CFabricVector*> &fabric)
{
 ifstream f(fn); string str;
 while(getline(f,str))
 {
 //cout<<str<<endl;
  stringstream ss(str); istream_iterator<string> it(ss);
  //it=ss;
  if(it!=istream_iterator<string>())
  {
   if((*it)[0]-'0'>=0 && (*it)[0]-'1' < static_cast<int>(fabric.size()))
   {
    CVector *w=fabric[(*it)[0]-'0']->Create();
    size_t i; char s[15]={0}; //++it;// size_t n=0;
 
    ++it;
    strcpy(s,it->c_str());
    //ss >> s;
    ++it;
    (*w).setText(s);
    for(i=0;/*i<n &&*/ it!=istream_iterator<string>();++it,i++) 
     {
      (*w).setPos(i,atof(it->c_str()));  

     }
     //cout<<"vec="<<*w;
    v.push_back(w);
   }
  }
 }
return 0;
}


//////CVector0    
int CVector0::output()
{
   std::ofstream foutput;
   if (!foutput) {
    cout << "File error - can't open to write data!";
    cin.sync(); cin.get(); throw -1;
   }
   foutput.open(OutFile, ios::out | ios::app);
       for(size_t i=0;i<pointer.size();i++){foutput<<pointer[i]<<" ";} 
       foutput<<endl;
       //cout<<*this;
          
     //  lk:
    foutput.close();
     return 0;

}
    
/////CVector1
int CVector1::output()
{
  std::ofstream foutput;
   if (!foutput) {
    cout << "File error - can't open to write data!";
    cin.sync(); cin.get(); throw -1;
   }
  
   foutput.open(OutFile, ios::out | ios::app);
   {
       foutput<<"{\n";
       for(size_t i=0;i<pointer.size();i++){foutput<<" "<<pointer[i]<<endl;} 
       foutput<<"}\n";
        // cout<<*this;
         //foutput<<this;
          
    foutput.close();
  }

return 0;
}
    
    
    
/////////OPERATORS///////////////

CVector0 operator+(const CVector&a,const CVector&b)
{          
 if(a.getN()!=b.getN())
  {
     cout << "Вектора должны быть одинаковой длины!\n"; 
     throw -1;
  } 	
 CVector0 w(a.getPointer());
 for(size_t i=0;i<w.getN();i++)
  w.setPos(i,a.getPointer()[i]+b.getPointer()[i]);
 return w;
}

CVector0 operator-(const CVector&a,const CVector&b)
{
 if(a.getN()!=b.getN())
  {
     cout << "Вектора должны быть одинаковой длины!\n"; 
     throw -1;
  }   	
 CVector0 w(a.getPointer());
 for(size_t i=0;i<w.getN();i++)
  w.setPos(i,a.getPointer()[i]-b.getPointer()[i]);
 return w;
}

CVector1 operator+ (const CVector1 &a, const CVector1 &b)
{
 if(a.getN()!=b.getN())
    {
     cout << "Вектора должны быть одинаковой длины!\n"; 
     throw -1;
    }
  else 
     {
 CVector1 w(a.getPointer());
 for(size_t i=0;i<w.getN();i++)
  w.setPos(i,a.getPointer()[i]+b.getPointer()[i]);
 return w;
     }
}
CVector1 operator- (const CVector1 &a, const CVector1 &b)
{
 if(a.getN()!=b.getN())
    {
     cout << "Вектора должны быть одинаковой длины!\n"; 
     throw -1;
    }
  else 
     {
 CVector1 w(a.getPointer());
 for(size_t i=0;i<w.getN();i++)
  w.setPos(i,a.getPointer()[i]-b.getPointer()[i]);
 return w;
     }
}

double CVector::operator *(const CVector &v)
    {
      double r=0;
     //n=v.n;
     if(pointer.size()==v.pointer.size())
     {
     for (size_t i=0; i < v.pointer.size(); i++ ) {
        r += v.pointer[i]*pointer[i];
        }
     return r;
     }
    else 
    {
     cout << "Вектора должны быть одинаковой длины!\n"; 
     throw -1;
    }
    }

//////////////////FRIEND FUNCTIONS////////////////////////

ostream &operator<<(ostream& cout, CVector &v) 
{
   cout << "Вектор {";
     for (size_t i=0; i < v.pointer.size(); i++)
     { 
     if(i<v.getN()-1)
 //        cout << v.getPointer()[i]  << ", ";
       cout << v.pointer[i]  << ", ";
     else //if(i == v.n-1)
 //        cout << v.getPointer()[i]; 
        cout << v.pointer[i] ;
     }    
   cout << "}\n";

return cout;
}
ostream &operator<<(ostream& cout, CVector0 v) 
{
   cout << "Вектор {";
     for (size_t i=0; i < v.pointer.size(); i++)
     { 
     if(i<v.getN()-1)
 //        cout << v.getPointer()[i]  << ", ";
       cout << v.pointer[i]  << ", ";
     else //if(i == v.n-1)
 //        cout << v.getPointer()[i]; 
        cout << v.pointer[i] ;
     }    
   cout << "}\n";

return cout;
}
ostream &operator<<(ostream& cout, CVector1 v) 
{
   cout << "Вектор {";
     for (size_t i=0; i < v.pointer.size(); i++)
     { 
     if(i<v.getN()-1)
 //        cout << v.getPointer()[i]  << ", ";
       cout << v.pointer[i]  << ", ";
     else //if(i == v.n-1)
 //        cout << v.getPointer()[i]; 
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
            cin >> p;      //v.pointer[i];
            v.pointer[i]=p;
        }
return cin;
}


