/*
 * CFunctions.cpp
 * 8. Определить класс CVector для работы с вектором вещественных
 * чисел. Длина вектора задается в конструкторе класса. В классе
 * должны быть определены необходимые конструкторы, деструктор, операторы сло-
 * жения, вычитания, скалярного умножения.
 * Написать функцию и конструктор сохранения переменной данного
 * типа в файл и загрузки из файла.
 * В отдельном файле должен быть написан тест на данный класс.
 *      Created on: 14.02.2021
 */
 
#include<iostream>
#include<fstream>
#include <sstream>
#include"CIntN.h"
//size_t glob_n;
//////////////////CLASS METHODS///////////////////////////
//////CIntN
void CIntN::CopyOnly(const CIntN &v)
    {
     if(this!=&v)
     {memcpy(array=new unsigned short int[n=v.n], v.array, v.n*sizeof(unsigned short int)); }
    }
void CIntN::GetIntN()        //Задать вектор
    {
        //cout << "Введите размерность вектора: "; cin >> n;
        for (size_t i=0; i < n; i++ )
        {
            cout << "Введите элемент числа № " << i << ": ";
            cin >> array[i];
        }
    }
void CIntN::ShowIntN()       //Показать вектор
    {
        cout << "Число {";
        for (size_t i=0; i < n; i++)
        {  
            cout << array[i];
        }    
        cout << "}\n";
    }
 
CIntN& CIntN::operator=(const CIntN& v)
    {
        if(this!=&v) 
        {if(array!=NULL)delete [] array;
         CopyOnly(v);}
        return *this;
    }
/*CIntN& CIntN::operator=( CIntN0 &b)
{ 
if(this!=&b )
{memcpy(array,b.getPtrArr(),b.getN()*sizeof(unsigned short int)); n=b.getN();} 
return *this;
}*/
/*static */
CIntN** CIntN::Input(const char *fn)
{

CIntN **v=new CIntN*[11]; 
memset(v,0,sizeof(CIntN*)*11);
//CIntN **v=NULL;
std::ifstream finput; 
//char mystring[100];
   finput.open(fn, ios::in);
   if (!finput) {
    cout << "File error - can't open to read data!";
    cin.sync(); cin.get(); throw -1;
   }
   
       bool b; unsigned short int k=0; int n=0;
       char s[15]; string str;
     //for(int i=0;!(finput.eof());i++)
     //if ((fgets(mystring[i], 100, f) != NULL) ) // считать символы из файла
      size_t i=0;
      //LC:
      while(getline(finput,str))
      {stringstream ss(str);
      //finput.getline(mystring, 100);
       //вырезать имя файла и присвоить его
      ss >> b;
      //if(b==1) {goto lk;}
      ss >> s;
      //cout<<"\ns="<<s<<endl;
      ss >> n;
      //cout<<"n="<<n<<endl;
      if(b==0) { v[i]=new CIntN0(n); //maybe need to kill vec
                 v[i]->setText(s);
                 }
      else if(b==1) {v[i]=new CIntN1(n); //maybe need to kill vec
                     v[i]->setText(s);
                    }
      //cout<<"xxx";
      for(int j=0;(ss>>k)&&(j<n);j++)
      {
       if(k>9) {cout<<"WRONG DATA! Цифра принимает значение от 0 до 9.\n"; finput.close();delete[]v;throw -1;}
       (*v[i]).setPos(j,k);
      }
      //cout<<endl;
      //if(finput.eof()){break;}
      i++;
       }   
       //REMEMBER IT!
       glob_n=i;
   
     //  lk:
    finput.close();
     //fclose (f);

return v;
}
//////CIntN0    
int CIntN0::output(const char *FileName)
{
   
   if(FileName){
   std::ofstream foutput;
   if (!foutput) {
    cout << "File error - can't open to write data!";
    cin.sync(); cin.get(); throw -1;
   }
   foutput.open(OutFile, ios::out | ios::app);
       for(size_t i=0;i<n;i++){foutput<<array[i];} 
       foutput<<endl;
       //cout<<*this;
          
     //  lk:
    foutput.close();
  }
     return 0;

}
    
/////CIntN1
int CIntN1::output(const char *FileName)
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
       for(size_t i=0;i<n;i++){foutput<<" "<<array[i]<<endl;} 
       foutput<<"}\n";
        // cout<<*this;
         //foutput<<this;
  
          
    foutput.close();
  }
}
return 0;
}
    
    
    
/////////OPERATORS///////////////
CIntN& operator+(const CIntN &lhs, const CIntN &rhs)
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
        if((lhs).getPtrArr()[i]+(rhs).getPtrArr()[i]<10)
         (res).setPos( i, (lhs).getPtrArr()[i]+(rhs).getPtrArr()[i]);
        else 
         {
          (res).setPos( i, ((lhs).getPtrArr()[i]+(rhs).getPtrArr()[i])%10);
          if(i>0) 
           {(res).setPos( i-1, (lhs).getPtrArr()[i-1]+(rhs).getPtrArr()[i-1] + 1); i--;}
          else if(i==0)
           {
            (res).setPos( i, (lhs).getPtrArr()[i]+(rhs).getPtrArr()[i]);
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
     CIntN1 w(lhs.getPtrArr(),f);
    for (size_t i=lhs.getN()-rhs.getN(); i > 0; i-- ) 
      {
        if((lhs).getPtrArr()[i]+(rhs).getPtrArr()[i]<10)
         (res).setPos( i, (lhs).getPtrArr()[i]+(rhs).getPtrArr()[i]);
        else 
         {
          (res).setPos( i, ((lhs).getPtrArr()[i]+(rhs).getPtrArr()[i])%10);
          (res).setPos( i-1, (lhs).getPtrArr()[i-1]+(rhs).getPtrArr()[i-1] + 1); i--;       
         }
        }
    return res;
    }
}

CIntN& operator-(const CIntN &lhs, const CIntN &rhs) 
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
        if((lhs).getPtrArr()[i]-(rhs).getPtrArr()[i]>=0)
         (res).setPos( i, (lhs).getPtrArr()[i]-(rhs).getPtrArr()[i]);
        else 
         {
          (res).setPos( i, ((lhs).getPtrArr()[i]-(rhs).getPtrArr()[i])%10);
          if(i>0) 
           {(res).setPos( i-1, (lhs).getPtrArr()[i-1]-(rhs).getPtrArr()[i-1] - 1); i--;}
          else if(i==0)
           {
            (res).setPos( i, (lhs).getPtrArr()[i]-(rhs).getPtrArr()[i]);
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
     CIntN1 w(lhs.getPtrArr(),f);
    for (size_t i=lhs.getN()-rhs.getN(); i > 0; i-- ) 
      {
        if((lhs).getPtrArr()[i]-(rhs).getPtrArr()[i]>=0)
         (res).setPos( i, (lhs).getPtrArr()[i]-(rhs).getPtrArr()[i]);
        else 
         {
          (res).setPos( i, ((lhs).getPtrArr()[i]-(rhs).getPtrArr()[i])%10);
          (res).setPos( i-1, (lhs).getPtrArr()[i-1]-(rhs).getPtrArr()[i-1] - 1); i--;       
         }
        }
    return res;
    }
} 
CIntN1 operator+ (const CIntN1 &a, const CIntN1 &b)
{          
 if(a.getN()==b.getN())
  {
 CIntN1 w(a.getPtrArr(),a.getN());
   for (size_t i=a.getN()-1; i > 0; i-- ) 
      {
        if((a).getPtrArr()[i]+(b).getPtrArr()[i]<10)
         (w).setPos( i, (a).getPtrArr()[i]+(b).getPtrArr()[i]);
        else 
         {
          (w).setPos( i, ((a).getPtrArr()[i]+(b).getPtrArr()[i])%10);
          if(i>0) 
           {(w).setPos( i-1, (a).getPtrArr()[i-1]+(b).getPtrArr()[i-1] + 1); i--;}
          else if(i==0)
           {
            (w).setPos( i, (a).getPtrArr()[i]+(b).getPtrArr()[i]);
            //единичку к началу приписать еще
           }
         }
        }
 return w;
  }
  else 
  {
   CIntN1 w(a.getPtrArr(),a.getN());
   for (size_t i=a.getN()-b.getN(); i > 0; i-- ) 
      {
        if((a).getPtrArr()[i]+(b).getPtrArr()[i]<10)
         (w).setPos( i, (a).getPtrArr()[i]+(b).getPtrArr()[i]);
        else 
         {
          (w).setPos( i, ((a).getPtrArr()[i]+(b).getPtrArr()[i])%10);
          (w).setPos( i-1, (a).getPtrArr()[i-1]+(b).getPtrArr()[i-1] + 1); i--;       
         }
        }
 return w;
  }
}

CIntN1 operator-(const CIntN1 &a, const CIntN1 &b)
{
 if(a.getN()==b.getN())
  {
 CIntN1 w(a.getPtrArr(),a.getN());
   for (size_t i=a.getN()-1; i > 0; i-- ) 
      {
        if((a).getPtrArr()[i]-(b).getPtrArr()[i]>=0)
         (w).setPos( i, (a).getPtrArr()[i]-(b).getPtrArr()[i]);
        else 
         {
          (w).setPos( i, ((a).getPtrArr()[i]-(b).getPtrArr()[i])%10);
          if(i>0) 
           {(w).setPos( i-1, (a).getPtrArr()[i-1]-(b).getPtrArr()[i-1] + 1); i--;}
          else if(i==0)
           {
            if((a).getPtrArr()[i]-(b).getPtrArr()[i]>=0)
             (w).setPos( i, (a).getPtrArr()[i]-(b).getPtrArr()[i]);
            else 
             (w).setPos( i, -(a).getPtrArr()[i]+(b).getPtrArr()[i]);
            //и нужен знак -
           }
         }
        }
 return w;
  }
  else 
  {
   CIntN1 w(a.getPtrArr(),a.getN());
   for (size_t i=a.getN()-b.getN(); i > 0; i-- ) 
      {
        if((a).getPtrArr()[i]-(b).getPtrArr()[i]>=0)
         (w).setPos( i, (a).getPtrArr()[i]-(b).getPtrArr()[i]);
        else 
         {
          (w).setPos( i, ((a).getPtrArr()[i]-(b).getPtrArr()[i])%10);
          (w).setPos( i-1, (a).getPtrArr()[i-1]-(b).getPtrArr()[i-1] + 1); i--;       
         }
        }
 return w;
  }
}
CIntN& CIntN::operator=(const CIntN&& v)
    {
        if(this!=&v) 
        {Clean(); CopyOnly(v);}
        return *this;
    }



//////////////////FRIEND FUNCTIONS////////////////////////

ostream &operator<<(ostream& cout, CIntN &v) 
{
   cout << "Число {";
     for (size_t i=0; i < v.n; i++)
     { 
        cout << v.array[i] ;
     }    
   cout << "}\n";

return cout;
}
ostream &operator<<(ostream& cout, CIntN1 v) 
{
   cout << "Число {";
     for (size_t i=0; i < v.n; i++)
     { 
        cout << v.array[i] ;
     }    
   cout << "}\n";

return cout;
}
istream &operator>>(istream& cin , CIntN &v) 
{
 for (size_t i=0,p; i < v.getN(); i++ )
        {
            cout << "Введите элемент числа № " << i << ": ";
            cin >> p;      //v.array[i];
            v.array[i]=p;
        }
return cin;
}


