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
#include"CVektor.h"
//size_t glob_n;
//////////////////CLASS METHODS///////////////////////////
//////CVektor
void CVektor::CopyOnly(const CVektor &v)
    {
     if(this!=&v)
     {memcpy(ptrArr=new float[n=v.n], v.ptrArr, v.n*sizeof(float)); }
    }
void CVektor::GetVektor()        //Задать вектор
    {
        //cout << "Введите размерность вектора: "; cin >> n;
        for (int i=0; i < n; i++ )
        {
            cout << "Введите элемент вектора № " << i << ": ";
            cin >> ptrArr[i];
        }
    }
void CVektor::ShowVektor()       //Показать вектор
    {
        cout << "Вектор {";
        for (int i=0; i < n; i++)
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
        {if(ptrArr!=NULL)delete [] ptrArr;
         CopyOnly(v);}
        return *this;
    }
/*CVektor& CVektor::operator=( CVektor0 &b)
{ 
if(this!=&b )
{memcpy(ptrArr,b.getPtrArr(),b.getN()*sizeof(float)); n=b.getN();} 
return *this;
}*/
/*static */CVektor** CVektor::Input(const char *fn)
{

CVektor **v=new CVektor*[11]; 
//CVektor **v=NULL;
std::ifstream finput; 
//char mystring[100];
   finput.open(fn, ios::in);
   if (!finput) {
    cout << "File error - can't open to read data!";
    cin.sync(); cin.get(); throw -1;
   }
   
       bool b; float k=0; int n=0;
       char s[15];
     //for(int i=0;!(finput.eof());i++)
     //if ((fgets(mystring[i], 100, f) != NULL) ) // считать символы из файла
      size_t i=0;
      //LC:
      while(1)
      {
      //finput.getline(mystring, 100);
       //вырезать имя файла и присвоить его
      finput >> b;
      //if(b==1) {goto lk;}
      finput >> s;
      cout<<"s="<<s<<endl;
      finput >> n;
      cout<<"n="<<n<<endl;
      if(b==0) {CVektor0 vec=CVektor0(n);
                 vec.setText(s);
                 cout<<vec<<endl; //ПОЧЕМУ БЕЗ ЭТОЙ СТРОЧКИ НЕ РАБОТАЕТ?
                 (v[i])=&vec;}
      else if(b==1) {CVektor1 vec=CVektor1(n);
                 vec.setText(s);
                 cout<<vec<<endl;  //ПОЧЕМУ БЕЗ ЭТОЙ СТРОЧКИ НЕ РАБОТАЕТ?
                 (v[i])=&vec;}
      //cout<<"xxx";
      for(int j=0;(finput>>k)&&(j<n);j++)
      {//(*v[i])[j]=k; 
      (*v[i]).setPos(j,k);
      cout<<(*v[i])[j]<<" ";
      }//{cout<<k<<" ";*v[i]=k;}
      cout<<endl;
    //cout<<"xxx";
      //i++;
      finput.getline(s,30); //КАК ПЕРЕЙТИ НА СЛЕДУЮЩУЮ СТРОКУ?
      if(finput.eof()){break;}
      i++;
       }   
       //REMEMBER IT!
       glob_n=i;
   
     //  lk:
    finput.close();
     //fclose (f);

return v;
}
//////CVektor0    
int CVektor0::output(const char *FileName)
{
 //FILE *f = fopen(FileName , "r");
  // char mystring[100];
 
   //if (f == NULL) perror("Ошибка открытия файла");
   //else
   std::ifstream finput;
   finput.open(FileName, ios::in);
   {
     //for(int i=0;i<10;i++)
     //if ((fgets(mystring[i], 100, f) != NULL) ) // считать символы из файла
      {
      //finput.getline(mystring, 100);
       //вырезать имя файла и присвоить его
       bool b; float k; int n=0;
       char s[15];
      finput >> b;
      if(b==1) {goto lk;}
      finput >> s;
      cout<<"s="<<s<<endl;
      finput >> n;
      cout<<n<<endl;
      CVektor0 vek=CVektor0(n);
      //cout<<"xxx";
      for(int j=0;(finput>>k)&&(j<n);j++)
      {cout<<k<<" ";vek[j]=k;}
    //cout<<"xxx";
    //cout << b << " " << s << "\n";
      strncpy(OutFile,s,15);
    //cout<<"777";
       }   
       lk:
    finput.close();
     //fclose (f);
   }
if(FileName)
{for(int k=0;k<n;k++){cout<<ptrArr[k]<<" ";}} return 0;


}
    
/////CVektor1
int CVektor1::output(const char *FileName)
{
 //FILE *f = fopen(FileName , "r");
  // char mystring[100];
 
   //if (f == NULL) perror("Ошибка открытия файла");
   //else
   std::ifstream finput;
   finput.open(FileName, ios::in);
   {
     //for(int i=0;i<10;i++)
     //if ((fgets(mystring[i], 100, f) != NULL) ) // считать символы из файла
      {
      //finput.getline(mystring, 100);
       //вырезать имя файла и присвоить его
       bool b; float k; int n=0;
       char s[15];
      finput >> b;
      if(b==1) {goto lk;}
      finput >> s;
      cout<<"s="<<s<<endl;
      finput >> n;
      cout<<n<<endl;
      CVektor1 vek=CVektor1(n);
      //cout<<"xxx";
      for(int j=0;(finput>>k)&&(j<n);j++)
      {cout<<k<<" ";vek[j]=k;}
    //cout<<"xxx";
    //cout << b << " " << s << "\n";
      strncpy(OutFile,s,15);
    //cout<<"777";
       }   
       lk:
    finput.close();
     //fclose (f);
   }
if(FileName)
{for(int k=0;k<n;k++){cout<<ptrArr[k]<<" ";}} return 0;


}
    
    
    
    
/*CVektor& CVektor::operator=(const CVektor&& v)
    {
        if(this!=&&v) 
        {Clean(); CopyOnly(v);}
        return *this;
    }
CVektor& CVektor::operator+(const CVektor &v) 
    {
     CVektor &r;
    // r.SetZero();
     if(n==v.n)
     {
     //r.n=v.n;
     r=CVektor(v.n);
     for (int i=0; i < r.n; i++ ) {
        r.ptrArr[i]= v.ptrArr[i]+ptrArr[i];
        }
     return r;
     }
    else 
    {
     cout << "Вектора должны быть одинаковой длины!\n"; 
     throw -1;
    }
    }
CVektor& CVektor::operator-(const CVektor &v) 
    {
     CVektor& r;
     //r.SetZero();
     if(n==v.n)
     {
     r=CVektor(v.n);
     for (int i=0; i < r.n; i++ ) {
        r.ptrArr[i]= ptrArr[i]- v.ptrArr[i];
        }
     return r;
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
     for (int i=0; i < v.n; i++ ) {
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
*/
//////////////////FRIEND FUNCTIONS////////////////////////
/*CVektor& Kommutativ(const CVektor& vector1, const CVektor& vector2)
{
    CVektor temp;
    temp.SetZero();
    // *(temp.ptrArr)=0;
    if(vector1.n == vector2.n)
    {
    //temp.setN(vector1.n);
    temp=CVektor(vector1.n);
    for (int i=0; i < vector1.n; i++ ) {
      (temp.ptrArr[i]) = (vector1.ptrArr[i]) + (vector2.ptrArr[i]);
      }
      cout << "Сумма    - ";
     // cout << vector1->n << endl;
      temp.ShowVektor();
    return temp;
    }
    else 
    {
    cout << "Вектора должны быть одинаковой длины!\n";
    throw -1;
    }
}
CVektor& Netativ(const CVektor& vector1, const CVektor& vector2)
{
    CVektor temp;
    temp.SetZero();
    // *(temp.ptrArr)=0;
     if(vector1.n == vector2.n)
    {
    //temp.n=vector1.getN();
    temp=CVektor(vector1.n);
    for (int i=0; i < temp.n; i++ ) {
        *(temp.ptrArr+i) = (vector1.ptrArr[i]) - (vector2.ptrArr[i]);
        }
        cout << "Разность - ";
        temp.ShowVektor();
    return temp;
    }
    else 
    {
     cout << "Вектора должны быть одинаковой длины!\n";
    throw -1;
    }
}
float Skalar ( CVektor& vector1, CVektor& vector2)
{
    //static float temp;
    float temp;
    temp = 0;
    if(vector1.getN() == vector2.getN())
    {
    for (int i=0; i < (vector1).getN(); i++ ) {
       // temp += (vector1.getPtrArr()[i]) * (vector2.getPtrArr()[i]);
       temp += (vector1.ptrArr[i]) * (vector2.ptrArr[i]);
        }
    cout << "Скалярное произведение: " << temp << endl;
    return temp;
    }
    else 
    {
    cout << "Вектора должны быть одинаковой длины!\n";
    throw -1;
    }
}*/

ostream &operator<<(ostream& cout, CVektor &v) 
{
   cout << "Вектор {";
     for (int i=0; i < v.n; i++)
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
 for (int i=0,p; i < v.getN(); i++ )
        {
            cout << "Введите элемент вектора № " << i << ": ";
            cin >> p;      //v.ptrArr[i];
            v.ptrArr[i]=p;
        }
return cin;
}


