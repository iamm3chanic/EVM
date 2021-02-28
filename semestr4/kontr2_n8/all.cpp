/*
 * Main.cpp
 * 8. Определить класс CVector для работы с вектором вещественных
 * чисел. Длина вектора задается в конструкторе класса. В классе
 * должны быть определены необходимые конструкторы, деструктор, операторы сло-
 * жения, вычитания, скалярного умножения.
 * Написать функцию и конструктор сохранения переменной данного
 * типа в файл и загрузки из файла.
 * В отдельном файле должен быть написан тест на данный класс.
 *      Created on: 14.02.2021
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
#define N 10
//--------------------------------------------------------------
//----------- Определение класса -------------------------------
//--------------------------------------------------------------
class CFabricVektor;
class CVektor
{
protected:
    size_t n;                 //Размер вектора
    float *ptrArr;     //Указатель на массив элементов
    //char* OutFile;
public:
    CVektor (const CVektor&v) {CopyOnly(v);}
    CVektor()      { SetZero(); /*n=0; ptrArr = new float[n];*/ /*ptrArr = (float*)realloc(ptrArr, n*sizeof(float));*/ }
    CVektor(size_t num)   { n = num;   ptrArr = new float [num]; memset(ptrArr,0,n*sizeof(float)); }
    virtual ~CVektor()    { Clean(); }
    
    CVektor ( CVektor && ) = default; 	//move constructor
    //CVektor&  operator= ( CVektor&& );  //move assignment
    size_t getN() { return n; }                      //getter
    //void setN(int dimension) { n = dimension; ptrArr =(float*)realloc(ptrArr, n*sizeof(float));}   //setter
    float* getPtrArr() { return ptrArr; }
    void SetZero(){ptrArr=NULL;n=0;}
    void Clean() {if(ptrArr!=NULL)delete [] ptrArr; SetZero();}
    void setPtrArr(float* arr)  { for (size_t i=0; i < n; i++ ) {ptrArr[i] = arr[i]; } } 
    void GetVektor();
    void ShowVektor();
    void CopyOnly(const CVektor &v);
    void setPos(size_t i, float f) {if(/*i<0||*/i>n-1) throw -1; 
    if(!ptrArr){ptrArr = new float[i];memset(ptrArr,0,i*sizeof(float)); }
    ptrArr[i]=f;}
    /*const*/ CVektor& operator=(const CVektor& v);
    //CVektor &operator=( CVektor0 &b);
    /*const*/ CVektor& operator+(const CVektor &v);
    /*const*/ CVektor& operator-(const CVektor &v);
    float operator *(const CVektor &v);
    float &operator[](size_t i){if(/*i<0||*/i>n-1) throw -1; return (this->ptrArr)[i];}
    //float &operator[](int i){if(i<0||i>n-1) throw -1; return ptrArr[i];}

    virtual int output(const char *FileName=NULL)=0;
    virtual char* getF()=0;
    virtual void setText(char* s)=0;
    //static CVektor **Input(const char *fn);
    static int Input(const char *fn, vector<CVektor*> &v, vector<CFabricVektor*> &fabric);
    
    friend float Skalar   (CVektor& , CVektor&);  //Склярное произведение
 
    friend CVektor& Kommutativ(const CVektor& , const CVektor& );//Сложение векторов
    friend CVektor& Netativ   (const CVektor& , const CVektor& );//Вычитание векторов
    friend int NReader();
    friend ostream &operator<<(ostream& /*&cout*/, CVektor& );
    friend istream &operator>>(istream& /*&cin*/, CVektor& ); 
};

//CVektor **glob_v; size_t glob_n;

class CVektor0: public CVektor {
   private:
      char OutFile[15];
   public:
      CVektor0() {ptrArr=NULL;/*OutFile=NULL;*/n=0;}
      CVektor0(size_t num) : CVektor(num){memset(OutFile,0,15);/* n = num;   ptrArr = new float [num]; memset(ptrArr,0,n*sizeof(float));*/}
      //CVektor0(int num)   { n = num;   ptrArr = new float [num];  }
      ~CVektor0()    {delete [] ptrArr; ptrArr=NULL;n=0;}
      //~CVektor0() : ~CVektor() {}
      //CVektor0 &operator=( CVektor0&b){if(this!=&b){memcpy(ptrArr,b.getPtrArr(),b.getN()*sizeof(float)); n=b.getN();} return *this;}
      CVektor0 &operator=( CVektor&b){if(this!=&b){memcpy(ptrArr,b.getPtrArr(),b.getN()*sizeof(float)); n=b.getN();} return *this;}
      void SetZero(){ptrArr=NULL;n=0;}
      void Clean() {delete [] ptrArr; SetZero();}
      char* getF() {return OutFile;}
      void setText(char* c)  { strncpy(OutFile,c,14); } 
      int output(const char *FileName); //в строку
      //CVektor0& operator-(const CVektor0 &v);
};

class CVektor1: public CVektor {
   private:
      char OutFile[15];
   public:
      CVektor1() {ptrArr=NULL;n=0;}
      CVektor1(size_t num) : CVektor(num){memset(OutFile,0,15);/* n = num;   ptrArr = new float [num]; memset(ptrArr,0,n*sizeof(float));*/}
      //CVektor0(int num)   { n = num;   ptrArr = new float [num];  }
      virtual ~CVektor1()    {delete [] ptrArr; ptrArr=NULL;n=0;}
      //~CVektor0() : ~CVektor() {}
      //CVektor1 &operator=( CVektor1&b){if(this!=&b){memcpy(ptrArr,b.getPtrArr(),b.getN()*sizeof(float)); n=b.getN();} return *this;}
      CVektor1 &operator=( CVektor&b){if(this!=&b){memcpy(ptrArr,b.getPtrArr(),b.getN()*sizeof(float)); n=b.getN();} return *this;}
      void SetZero(){ptrArr=NULL;n=0;}
      void Clean() {delete [] ptrArr; SetZero();}
      char* getF() {return OutFile;}
      void setText(char* c)  { strncpy(OutFile,c,14); } 
      int output(const char *FileName); //в столбец
};

class CFabricVektor
{
public:
 virtual CVektor *Create() = 0;
 virtual ~CFabricVektor() {}
};

class CFabricVektor0: public CFabricVektor
{
public:
 virtual CVektor *Create() {return new CVektor0;}
 virtual ~CFabricVektor0() {}
};

class CFabricVektor1: public CFabricVektor
{
public:
 virtual CVektor *Create() {return new CVektor1;}
 virtual ~CFabricVektor1() {}
};
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
        {if(ptrArr!=NULL)delete [] ptrArr;
         CopyOnly(v);}
        return *this;
    }

/*int Input(const char *fn, CVektor** v)
{
 ifstream f(fn); string str;
 while(getline(f,str))
 {stringstream ss(str); istream_iterator<int> it;
  it=ss;
  if(it!=istream_iterator<int>())
  {
   if(*it>=1 && *it<=v.size())
   {
    CVektor *w=new CVektor(*it-1);
    size_t i; ++it;
    for(i=0;i<10 && it!=istream_iterator<int>();++it) (*w)[i++]=*it;
    v[i]=w;
   }
 }
 }
 return 0;
}*/
/*static*/ 
int CVektor::Input(const char *fn, vector<CVektor*> &v, vector<CFabricVektor*> &fabric)
{
 ifstream f(fn); string str;
 while(getline(f,str))
 {stringstream ss(str); istream_iterator<float> it;
  it=ss;
  if(it!=istream_iterator<float>())
  {
   if(*it>=1 && *it<=fabric.size())
   {
    CVektor *w=fabric[(*it)-1]->Create();
    size_t i; bool b;char s[15]; ++it; size_t n=5;
    f >> b;
    f >> s;
    //f >> n;
      cout<<"b="<<b<<"; n="<<n<<endl;
      cout<<"s="<<s<<endl;
    (*w).setText(s);
    for(i=0;i<n && it!=istream_iterator<float>();++it) {(*w)[i++]=*it; /*glob_n++;*/}
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
   {
       //for(int i=0;i<n;i++){foutput<<i+1<<")"<<ptrArr[i]<<" ";} 
       cout<<*this;
         //cout<<"xxx";
    //cout << b << " " << s << "\n";
     // strncpy(OutFile,s,15);
    //cout<<"777";
          
     //  lk:
    foutput.close();
     //fclose (f);
   }
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
  /*cout<<"CHECKING...\n";
  cout<<"OutFile = "<<OutFile;
  cout<<"\nn = "<<n<<endl;
  cout<<*ptrArr;*/
  
   foutput.open(OutFile, ios::out | ios::app);
   {
       for(size_t i=0;i<n;i++){foutput<<i+1<<") "<<ptrArr[i]<<endl;} 
        // cout<<this;
         //foutput<<this;
  
          
    foutput.close();
  }
}
return 0;
}
    
CVektor& CVektor::operator-(const CVektor &v) 
    {
     if(n==v.n)
     {
     for (size_t i=0; i < v.n; i++ ) { /*float t=ptrArr[i];*/ ptrArr[i]= ptrArr[i]- v.ptrArr[i]; }
     return *this;
     }
    else 
    { cout << "Вектора должны быть одинаковой длины!\n"; throw -1;}
    }    
CVektor& CVektor::operator+(const CVektor &v) 
    {
     if(n==v.n)
     {
     for (size_t i=0; i < v.n; i++ ) { ptrArr[i]= ptrArr[i] + v.ptrArr[i]; }
     return *this;
     }
    else 
    { cout << "Вектора должны быть одинаковой длины!\n"; throw -1;}
    } 
/*CVektor0& CVektor0::operator-(const CVektor0 &v) 
    {
     if(n==v.n)
     {
     for (size_t i=0; i < v.n; i++ ) { ptrArr[i]= ptrArr[i]- v.ptrArr[i]; }
     return *this;
     }
    else 
    { cout << "Вектора должны быть одинаковой длины!\n"; throw -1;}
    }*/
float CVektor::operator *(const CVektor &v)
    {
      float r=0;
     if(n==v.n)
     {
     for (size_t i=0; i < v.n; i++ ) {r += v.ptrArr[i]*ptrArr[i];}
     return r;
     }
    else 
    {cout << "Вектора должны быть одинаковой длины!\n"; throw -1;}
    }


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



vector<CFabricVektor*> fabric;
vector<CVektor*> v;

int main()
{
  try {
   cout << "test0. Input + output\n";
   /*CFabricVektor0 *f0 = new CFabricVektor0();
   CFabricVektor1 *f1 = new CFabricVektor1();
   fabric.push_back(f0);
   fabric.push_back(f1);*/
   //HERE WERE LEAKAGE
   fabric.push_back(new CFabricVektor0);
   fabric.push_back(new CFabricVektor1);
   //glob_v= (CVektor::Input("input.txt"));
   CVektor::Input("input.txt", v, fabric);
   //(**glob_v).Input("input.txt", glob_v);
   cout<<"global Number = "<<v.size()<<endl;
   for(size_t i=0;(i<v.size());++i)  
   {
   v[i]->ShowVektor();
   }
    for(size_t i=0;(i<v.size());i++)  
   {
   delete v[i]; //delete fabric[i];
   }
   //delete &f0; delete &f1;
    for(size_t i=0;(i<fabric.size());i++)  {delete fabric[i];}
   //delete &fabric;
  // delete[] glob_v;
  } catch(int err) {cout << "error=" <<err<<endl;} 
  
  try {
  cout << "test1. create vectors\n";
    int n;
    //CVektor v1, v2, sum, dif;
    //n = NReader();
    n=3;
    CVektor0 v1=CVektor0(n);
    CVektor0 v2=CVektor0(n);
    CVektor1 v3=CVektor1(n);
    CVektor1 v4=CVektor1(n);
    
    cout<< "SUCCESS\n";
  
    } catch(int err) {cout << "error=" <<err<<endl;}
  try {
  cout << "test2. CVektor0 and file\n";
    int i; char c[15]="out_test.txt";
    CVektor0 v1=CVektor0(3);
    v1.setPos(0,11); v1.setPos(1,22); v1.setPos(2,33);
    v1.setText(c);
    CVektor1 v2=CVektor1(3);
    v2.setPos(0,1111); v2.setPos(1,2222); v2.setPos(2,3333);
    v2.setText(c);
    i = v1.output("input.txt");
    if(i==0){cout<< "SUCCESS-0\n";}
    i = v2.output("input.txt");
    if(i==0){cout<< "SUCCESS-1\n";}
    else cout<< "Some error...\n";
    } catch(int err) {cout << "error=" <<err<<endl;}
    
    try {
    cout << "test3. operators +,-,*\n";
    int n=3;
    //n = NReader();
    cout<<"For CVektor0:\n";
    CVektor0 v1(n), v2(n), sum(n), dif(n);
    v1.setPos(0,11); v1.setPos(1,22); v1.setPos(2,33);
    v2.setPos(0,1); v2.setPos(1,2); v2.setPos(2,3);

    cout << v1;
    cout << v2;
    
    sum=v1+v2;
    dif=v1-v2; // при cout << dif  выводит первый вектор!
    cout << "Скалярное произведение = " << v1*v2 << endl;
    cout << "Сумма    = " << sum ;
    cout << "Разность = " << v1-v2 ;
    
    cout<<"For CVektor1:\n";
     CVektor1 v3(n), v4(n);
    v3.setPos(0,111); v3.setPos(1,222); v3.setPos(2,333);
    v4.setPos(0,1); v4.setPos(1,2); v4.setPos(2,3);

    cout << v3;
    cout << v4;
    
    cout << "Скалярное произведение = " << v3*v4 << endl;
    cout << "Сумма    = " << v3+v4 ;
    cout << "Разность = " << v3-v4 ;

    } catch(int err) {cout << "error=" <<err<<endl;}
        return 0;
}
