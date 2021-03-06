/*
 * CFunctions.cpp
 */
 
#include"CVektor.h"

//////////////////CLASS METHODS///////////////////////////
//////CVektor
void CVektor::CopyOnly(const CVektor &v)
    {
     if(this!=&v)
     {ptrArr=v.ptrArr; n=v.n; }
    }
void CVektor::GetVektor()        //Задать вектор
    {
        //cout << "Введите размерность вектора: "; cin >> n;
        for (size_t i=0; i < n; i++ )
        {
            cout << "Введите элемент вектора № " << i << ": ";
            cin >> ptrArr[i];
        }
    }
void CVektor::ShowVektor()       //Показать вектор
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
        {//if(ptrArr!=NULL) //delete [] ptrArr;
         CopyOnly(v);}
        return *this;
    }
/*CVektor& CVektor::operator=( CVektor0 &b)
{ 
if(this!=&b )
{memcpy(ptrArr,b.getPtrArr(),b.getN()*sizeof(float)); n=b.getN();} 
return *this;
}*/
/*static */
int CVektor::Input(const char *fn, vector<CVektor*> &v, vector<CFabricVektor*> &fabric)
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
    CVektor *w=fabric[(*it)[0]-'0']->Create();
    size_t i; int b;char s[15]={0}; //++it;// size_t n=0;
    b=(*it)[0]-'0';
    ++it;
    strcpy(s,it->c_str());
    //ss >> s;
    ++it;
    //it=ss;
    //f >> n;
      cout<<"b="<<b<<endl;//<<"; n="<<n<<endl;
      cout<<"s="<<s<<endl;
    (*w).setText(s);
    for(i=0;/*i<n &&*/ it!=istream_iterator<string>();++it,i++) 
     {
      (*w).setPos(i,atof(it->c_str()));  
      //(*w)[i]=atof(it->c_str());
      //cout<<"setting w<"<<i<<">="<<*it<<endl;
      //cout<<*w;
     }
     cout<<"vec="<<*w;
    v.push_back(w);
   }
  }
 }
return 0;
}

//////CVektor0    
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
       //cout<<*this;
          
     //  lk:
    foutput.close();
  }
     return 0;

}
    
/////CVektor1
int CVektor1::output(const char *FileName)
{
  // char mystring[100];
 
   //if (f == NULL) perror("Ошибка открытия файла");
   //else
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
        // cout<<*this;
         //foutput<<this;
  
          
    foutput.close();
  }
}
return 0;
}
    
    
    
/////////OPERATORS///////////////
CVektor& operator+(const CVektor &lhs, const CVektor &rhs)
{
 if(lhs.getN()==rhs.getN())
     {
     //const CVektor& w=rhs; 
     const CVektor& u=lhs; 
     //const CVektor& tmpl=lhs; const CVektor& tmpr=rhs;
     CVektor& l=const_cast<CVektor&>(u);//=const_cast<CVektor&>(w);
     //CVektor& r=const_cast<CVektor&>(tmpr);
     CVektor& res=l;//CVektor& res(lhs.getN());
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
CVektor& operator-(const CVektor &lhs, const CVektor &rhs) 
{
 if(lhs.getN()==rhs.getN())
     {
     const CVektor& tmpl=lhs; const CVektor& tmpr=rhs;
     CVektor& l=const_cast<CVektor&>(tmpl);//=const_cast<CVektor&>(w);
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
     //CVektor1& l=const_cast<CVektor1&>(tmpl);//=const_cast<CVektor&>(w);
    // очень проcили инициализировать ссылку
     const CVektor1& res=tmpl;
     for (size_t i=0; i < lhs.getN(); i++ ) {
        const_cast<CVektor1&>(res).setPos(i, (lhs).getPtrArr()[i]+(rhs).getPtrArr()[i]);
        }
        const_cast<CVektor1&>(lhs)=const_cast<CVektor1&>(tmpl);
        const_cast<CVektor1&>(rhs)=const_cast<CVektor1&>(tmpr);
     return const_cast<CVektor1&>(res);
     /*const CVektor1& res=rhs;
     for (size_t i=0; i < lhs.getN(); i++ ) {
        const_cast<CVektor1&>(res)[i]= const_cast<CVektor1&>(lhs).getPtrArr()[i]+const_cast<CVektor1&>(rhs).getPtrArr()[i];
        //r[i]=lhs[i]+rhs[i];
        }
     return const_cast<CVektor1&>(res);*/
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
     CVektor1& l=const_cast<CVektor1&>(tmpl);//=const_cast<CVektor&>(w);
     //CVektor1& r=const_cast<CVektor1&>(tmpr);
     CVektor1& res=l;
     for (size_t i=0; i < lhs.getN(); i++ ) {
      const_cast<CVektor1&>(res).setPos(i, (lhs).getPtrArr()[i]-(rhs).getPtrArr()[i]);
        //(res)[i]= (l).getPtrArr()[i]-(r).getPtrArr()[i];
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

float CVektor::operator *(const CVektor &v)
    {
      float r=0;
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

ostream &operator<<(ostream& cout, CVektor &v) 
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
istream &operator>>(istream& cin , CVektor &v) 
{
 for (size_t i=0,p; i < v.getN(); i++ )
        {
            cout << "Введите элемент вектора № " << i << ": ";
            cin >> p;      //v.ptrArr[i];
            v.ptrArr[i]=p;
        }
return cin;
}


