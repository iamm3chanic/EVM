/*
 * CFunctions.cpp
 */
 
#include"CIntN.h"
//#include <omp.h>
//////////////////CLASS METHODS///////////////////////////
//////CIntN
void CIntN::CopyOnly(const CIntN &v)
    {
     if(this!=&v)
     {pointer=v.pointer;}
    }
void CIntN::GetIntN()        //Задать вектор
    {
        //cout << "Введите размерность вектора: "; cin >> n;
        for (size_t i=0; i < pointer.size(); i++ )
        {
            cout << "Введите элемент вектора № " << i << ": ";
            cin >> pointer[i];
        }
    }
void CIntN::ShowIntN()       //Показать вектор
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
 
CIntN& CIntN::operator=(const CIntN& v)
    {
        if(this!=&v) 
        {//if(pointer!=NULL) //delete [] pointer;
         CopyOnly(v);}
        return *this;
    }

/*static */
int CIntN::Input(const char *fn, vector<CIntN*> &v, vector<CFabricIntN*> &fabric)
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
    CIntN *w=fabric[(*it)[0]-'0']->Create();
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



//////CIntN0    
int CIntN0::output()
{
   std::ofstream foutput;
   if (!foutput) {
    cout << "File error - can't open to write data!";
    cin.sync(); cin.get(); throw -1;
   }
   foutput.open(OutFile, ios::out | ios::app);
       for(size_t i=0;i<pointer.size();i++){foutput<<pointer[i];} 
       foutput<<endl;
       //cout<<*this;
          
     //  lk:
    foutput.close();
     return 0;

}
    
/////CIntN1
int CIntN1::output()
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

CIntN0 operator+(const CIntN &a,const CIntN &b)
{   	
 CIntN0 w(a.getPointer());
 for(size_t i=0;i<w.getN();i++)
  w.setPos(i,a.getPointer()[i]+b.getPointer()[i]);
 return w;
}
/*CIntN& operator+(const CIntN &lhs, const CIntN &rhs)
{
 if(lhs.getN()==rhs.getN())
     {
     //const CIntN& w=rhs; 
     const CIntN& u=lhs; 
     CIntN& l=const_cast<CIntN&>(u);//=const_cast<CIntN&>(w);
     //CIntN& r=const_cast<CIntN&>(tmpr);
     CIntN& res=l;//CIntN& res(lhs.getN());
     for (size_t i=lhs.getN(); i > 0; i-- ) 
      {
        if((lhs).getPointer()[i]+(rhs).getPointer()[i]<10)
         (res).setPos( i, (lhs).getPointer()[i]+(rhs).getPointer()[i]);
        else 
         {
          (res).setPos( i, ((lhs).getPointer()[i]+(rhs).getPointer()[i])%10);
          if(i>0) 
           {(res).setPos( i-1, (lhs).getPointer()[i-1]+(rhs).getPointer()[i-1] + 1); i--;}
          else if(i==0)
           {
            (res).setPos( i, (lhs).getPointer()[i]+(rhs).getPointer()[i]);
            //единичку к началу приписать еще
           }
         }
        }
     return (res);
     }
    else 
    {
    const CIntN& u=lhs; 
     CIntN& l=const_cast<CIntN&>(u);//=const_cast<CIntN&>(w);
     //CIntN& r=const_cast<CIntN&>(tmpr);
     CIntN& res=l;
    size_t f=lhs.getN()?(lhs.getN()>rhs.getN()):rhs.getN();
     CIntN1 w(lhs.getPointer(),f);
    for (size_t i=lhs.getN()-rhs.getN(); i > 0; i-- ) 
      {
        if((lhs).getPointer()[i]+(rhs).getPointer()[i]<10)
         (res).setPos( i, (lhs).getPointer()[i]+(rhs).getPointer()[i]);
        else 
         {
          (res).setPos( i, ((lhs).getPointer()[i]+(rhs).getPointer()[i])%10);
          (res).setPos( i-1, (lhs).getPointer()[i-1]+(rhs).getPointer()[i-1] + 1); i--;       
         }
        }
    return res;
    }
}*/

CIntN0 operator-(const CIntN&a,const CIntN&b)
{  	
 CIntN0 w(a.getPointer());
 for(size_t i=0;i<w.getN();i++)
  w.setPos(i,a.getPointer()[i]-b.getPointer()[i]);
 return w;
}

CIntN1 operator+ (const CIntN1 &a, const CIntN1 &b)
{          
 if(a.getN()==b.getN())
  {
 CIntN1 w(a.getPointer());
   for (size_t i=a.getN()-1; i > 0; i-- ) 
      {
        if((a).getPointer()[i]+(b).getPointer()[i]<10)
         (w).setPos( i, (a).getPointer()[i]+(b).getPointer()[i]);
        else 
         {
          (w).setPos( i, ((a).getPointer()[i]+(b).getPointer()[i])%10);
          if(i>0) 
           {(w).setPos( i-1, (a).getPointer()[i-1]+(b).getPointer()[i-1] + 1); i--;}
          else if(i==0)
           {
            (w).setPos( i, (a).getPointer()[i]+(b).getPointer()[i]);
            //единичку к началу приписать еще
           }
         }
        }
 return w;
  }
  else 
  {
   CIntN1 w(a.getPointer());
   for (size_t i=a.getN()-b.getN(); i > 0; i-- ) 
      {
        if((a).getPointer()[i]+(b).getPointer()[i]<10)
         (w).setPos( i, (a).getPointer()[i]+(b).getPointer()[i]);
        else 
         {
          (w).setPos( i, ((a).getPointer()[i]+(b).getPointer()[i])%10);
          (w).setPos( i-1, (a).getPointer()[i-1]+(b).getPointer()[i-1] + 1); i--;       
         }
        }
 return w;
  }
}
CIntN1 operator- (const CIntN1 &a, const CIntN1 &b)
{
 if(a.getN()!=b.getN())
    {
     cout << "Вектора должны быть одинаковой длины!\n"; 
     throw -1;
    }
  else 
     {
 CIntN1 w(a.getPointer());
 for(size_t i=0;i<w.getN();i++)
  w.setPos(i,a.getPointer()[i]-b.getPointer()[i]);
 return w;
     }
}

/*unsigned short int CIntN::operator *(const CIntN &v)
    {
      unsigned short int r=0;
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
*/
//////////////////FRIEND FUNCTIONS////////////////////////

ostream &operator<<(ostream& cout, CIntN &v) 
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
ostream &operator<<(ostream& cout, CIntN0 v) 
{
   cout << "Число {";
     for (size_t i=0; i < v.pointer.size(); i++)
     { 
        cout << v.pointer[i] ;
     }    
   cout << "}\n";

return cout;
}
ostream &operator<<(ostream& cout, CIntN1 v) 
{
   cout << "Число {";
     for (size_t i=0; i < v.pointer.size(); i++)
     { 
       cout << v.pointer[i]  ;
     }    
   cout << "}\n";

return cout;
}
istream &operator>>(istream& cin , CIntN &v) 
{
 for (size_t i=0,p; i < v.getN(); i++ )
        {
            cout << "Введите элемент числа № " << i << ": ";
            cin >> p;      //v.pointer[i];
            v.pointer[i]=p;
        }
return cin;
}

int CIntN::OMPTest(const char *fn)
{
 cout << "Starting Parallel Test."<<endl;
 //clock_t t1,t2,t3,t4;
 time_t T1,T2;
 vector<CIntN0> v; vector<unsigned short int> p;
 ifstream f(fn); string str;
 while(getline(f,str))
 {
 //cout<<str<<endl;
  stringstream ss(str); istream_iterator<string> it(ss);
  //it=ss;
  if(it!=istream_iterator<string>())
  {
   
    CIntN0 w(p);
    size_t i; 
 
    
    ++it;
    for(i=0;it!=istream_iterator<string>();++it,i++) 
     {
      (w).setPos(i,atof(it->c_str()));  

     }
    v.push_back(w);
   
  }
 }
 
 //t1=clock();
 T1 = time(NULL);
    for(size_t j=0;(j<v.size());j++)
    {
      for(size_t count=0;count<1000000;count++)
      {
      v[j] = v[j] + v[j];
      v[j] = v[j] - v[j];
      }
    }
 //t2=clock();
 T2 = time(NULL);
    //float Time=(t2-t1);
    //Time=(float)(t2-t1);
 
 cout << "NON-PARALLEL FOR: TIME = "<<T2-T1<<" sec"<<endl;
 T1 = time(NULL);
#pragma omp parallel for 
    for(size_t j=0;(j<v.size());j++)
    {
      for(size_t count=0;count<1000000;count++)
      {
      v[j] = v[j] + v[j];
      v[j] = v[j] - v[j];
      }
    }
 T2 = time(NULL);
    //float Time=(t4-t3);
 
 cout << "PARALLEL FOR: TIME = "<<T2-T1<<" sec"<<endl;
return 0;
}
