/*
 * CFunctions.cpp
 */
 
#include"CVector.h"
#include <set>
//using namespace std;
//////////////////CLASS METHODS///////////////////////////
//////CVector
void CVector::CopyOnly(const CVector &v)
    {
     if(this!=&v)
     {ptrArr=v.ptrArr; n=v.n; }
    }

void CVector::GetVector()        //Задать вектор
    {
        //cout << "Введите размерность вектора: "; cin >> n;
        for (size_t i=0; i < n; i++ )
        {
            cout << "Введите элемент вектора № " << i << ": ";
            cin >> ptrArr[i];
        }
    }
void CVector::ShowVector()       //Показать вектор
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
 
CVector& CVector::operator=(const CVector& v)
    {
        if(this!=&v) 
        {//if(ptrArr!=NULL) //delete [] ptrArr;
         CopyOnly(v);}
        return *this;
    }
/*CVector& CVector::operator=( CVector0 &b)
{ 
if(this!=&b )
{memcpy(ptrArr,b.getPtrArr(),b.getN()*sizeof(int)); n=b.getN();} 
return *this;
}*/
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
    CVector *w=fabric[0]->Create();
    size_t i; char s[15]={0}; //++it;// size_t n=0;
    //b=(*it)[0]-'0';
    //++it;
    strcpy(s,it->c_str());
    //ss >> s;
    ++it;
      //cout<<"s="<<s<<endl;
    (*w).setText(s);
    for(i=0;/*i<n &&*/ it!=istream_iterator<string>();++it,i++) 
     {
      (*w).setPos(i,atof(it->c_str()));  
      //(*w)[i]=atof(it->c_str());
      //cout<<"setting w<"<<i<<">="<<*it<<endl;
      //cout<<*w;
     }
     //cout<<"vec="<<*w;
    v.push_back(w);
  }
 }
return 0;
}
  
/////CVector1
int CVector1::output()
{
  // char mystring[100];
 
   //if (f == NULL) perror("Ошибка открытия файла");
   //else
  
  std::ofstream foutput;
   if (!foutput) {
    cout << "File error - can't open to write data!";
    cin.sync(); cin.get(); throw -1;
   }
  
   foutput.open(OutFile, ios::out | ios::app);
   {
       foutput<<"{";
       for(size_t i=0;i<n;i++){foutput<<" "<<ptrArr[i];} 
       foutput<<" }\n";
        // cout<<*this;
         //foutput<<this;
  
          
    foutput.close();
  }
return 0;
}
    
    
    
/////////OPERATORS///////////////
CVector& operator+(const CVector &lhs, const CVector &rhs)
{
 if(lhs.getN()==rhs.getN())
     {
     //const CVector& w=rhs; 
     const CVector& u=lhs; 
     //const CVector& tmpl=lhs; const CVector& tmpr=rhs;
     CVector& l=const_cast<CVector&>(u);//=const_cast<CVector&>(w);
     //CVector& r=const_cast<CVector&>(tmpr);
     CVector& res=l;//CVector& res(lhs.getN());
     for (size_t i=0; i < lhs.getN(); i++ ) {
        (res).setPos(i, (lhs).getPtrArr()[i]+(rhs).getPtrArr()[i]);
        //r[i]=lhs[i]+rhs[i];
        }
     return (res);
     }
    else 
    {
     cout << "Вектора должны быть одинаковой длины!\n"; 
     throw -1;
    }
}
//поменять? это не похоже на правду... мняются исходники либо отбрасывается квалификатор...
CVector& operator-(const CVector &lhs, const CVector &rhs) 
{
 if(lhs.getN()==rhs.getN())
     {
     const CVector& tmpl=lhs; const CVector& tmpr=rhs;
     CVector& l=const_cast<CVector&>(tmpl);//=const_cast<CVector&>(w);
     CVector& r=const_cast<CVector&>(tmpr);
     CVector& res=r;
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

CVector1& operator+ (const CVector1 &lhs, const CVector1 &rhs)
{
 if(lhs.getN()==rhs.getN())
     {
      const CVector1& tmpl=lhs; const CVector1& tmpr=rhs;
     //CVector1& l=const_cast<CVector1&>(tmpl);//=const_cast<CVector&>(w);
    // очень проcили инициализировать ссылку
     const CVector1& res=tmpl;
     for (size_t i=0; i < lhs.getN(); i++ ) {
        const_cast<CVector1&>(res).setPos(i, (lhs).getPtrArr()[i]+(rhs).getPtrArr()[i]);
        }
        const_cast<CVector1&>(lhs)=const_cast<CVector1&>(tmpl);
        const_cast<CVector1&>(rhs)=const_cast<CVector1&>(tmpr);
     return const_cast<CVector1&>(res);
     /*const CVector1& res=rhs;
     for (size_t i=0; i < lhs.getN(); i++ ) {
        const_cast<CVector1&>(res)[i]= const_cast<CVector1&>(lhs).getPtrArr()[i]+const_cast<CVector1&>(rhs).getPtrArr()[i];
        //r[i]=lhs[i]+rhs[i];
        }
     return const_cast<CVector1&>(res);*/
     }
    else 
    {
     cout << "Вектора должны быть одинаковой длины!\n"; 
     throw -1;
    }
}
CVector1& operator-(const CVector1 &lhs, const CVector1 &rhs)
{
 if(lhs.getN()==rhs.getN())
     {
      const CVector1& tmpl=lhs; const CVector1& tmpr=rhs;
     CVector1& l=const_cast<CVector1&>(tmpl);//=const_cast<CVector&>(w);
     //CVector1& r=const_cast<CVector1&>(tmpr);
     CVector1& res=l;
     for (size_t i=0; i < lhs.getN(); i++ ) {
      const_cast<CVector1&>(res).setPos(i, (lhs).getPtrArr()[i]-(rhs).getPtrArr()[i]);
        //(res)[i]= (l).getPtrArr()[i]-(r).getPtrArr()[i];
        }
        const_cast<CVector1&>(lhs)=const_cast<CVector1&>(tmpl);
        const_cast<CVector1&>(rhs)=const_cast<CVector1&>(tmpr);
     return (res);
     }
    else 
    {
     cout << "Вектора должны быть одинаковой длины!\n"; 
     throw -1;
    }
}

int CVector::operator *(const CVector &v)
    {
      int r=0;
     //n=v.n;
     if(n==v.n)
     {
     for (size_t i=0; i < v.n; i++ ) {
        r += v.ptrArr[i]*ptrArr[i];
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
     for (size_t i=0; i < v.n; i++)
     { 
     if(i<v.getN()-1)
 //        cout << v.getPtrArr()[i]  << ", ";
       cout << v.ptrArr[i]  << ", ";
     else //if(i == v.n-1)
 //        cout << v.getPtrArr()[i]; 
        cout << v.ptrArr[i] ;
     }    
   cout << "}\n";

return cout;
}
istream &operator>>(istream& cin , CVector &v) 
{
 for (size_t i=0,p; i < v.getN(); i++ )
        {
            cout << "Введите элемент вектора № " << i << ": ";
            cin >> p;      //v.ptrArr[i];
            v.ptrArr[i]=p;
        }
return cin;
}


