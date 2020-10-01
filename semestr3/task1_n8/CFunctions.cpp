/*
 * CFunctions.cpp

 */
#include<iostream>
#include<string.h>
#include <ctime>
#include <cstdlib>
#include "CList1.h"
#include "CDynamic.h"
using namespace std;
//////////////////CLASS METHODS///////////////////////////

///////////////Arr
void Arr::setArr(double*array)  { 
      memcpy(v, array, GetN()*sizeof(double));
      } 
      
void Arr::InputTo(int pos, double d)  {
       for(int i=pos;i<5;i++) {v[i]=v[i-1];}
        v[pos-1]=d;
       }    
       
void Arr::CopyOnly(const Arr &b) {
       if(this!=&b)
	{SetZero();nreal=b.nreal;n=b.n;memcpy(v=new double[n],b.v, b.n*sizeof(double));}
       } 
         
////////////CDynamic
void CDynamic::AddArr(Arr a)        
    {
   //for cheat
    double* tmp;
    tmp=new double[n_real+a.GetN()];
    for(int i=0;i<getM();i++)
    { arrList.GoToNext();}
     arrList.AddAfter(a);
     tmp=cheatArr.getArr();
    for(int i=0;i<n_real;i++) {tmp[i]=cheatArr.getArr()[i];}
    for(int i=1;i<=a.GetN();i++) {tmp[n_real+i]=a[i];}
    setLength(n_real+a.GetN());
    cheatArr.setArr(tmp); //cout << "this is cheat:"<<cheatArr;
   //for list
      /*arrList.GoToBegin();
      for(; arrList.GetCur().getArr()!=NULL; ) {arrList.GoToNext();}
      arrList.AddAfter(a);*/
    }
    
void CDynamic::CopyOnly(const CDynamic &v)    
    {
     CList1<Arr> arrList;
     if(this!=&v)
     //{memcpy(&arrList, &v.arrList, v.m*sizeof(double)); 
     arrList=v.arrList;
     cheatArr=v.cheatArr;
    }
    
void CDynamic::SetCheat(double* a)
    {
     cheatArr.setArr(a);
    }
    
void CDynamic::InputTo(int pos, double d)      
    {
      //for cheat
      for(int i=pos;i<n_real;i++) {cheatArr[i]=cheatArr[i-1];}
      cheatArr[pos-1]=d;
      //for list
      Arr a;
      arrList.GoToBegin();
      for(int i=0; i<pos/5; i++) {arrList.GoToNext();}
      a= arrList.GetCur();   //memcpy(a, arrList.GetCur(), sizeof(Arr)); 
      a.InputTo(pos%5, d);
      arrList.SetCur(a);
    }
    
void CDynamic::InputInto(int pos, double d)      
    {
      for(int i=pos;i<n_real;i++) {cheatArr[i]=cheatArr[i-1];}
      cheatArr[pos-1]=d;
    }
    
void CDynamic::InputAfter(int pos, double d)      
    {
      for(int i=pos;i<n_real;i++) {cheatArr[i]=cheatArr[i-1];}
      cheatArr[pos-1]=d;
    }
    
CDynamic& CDynamic::operator=(const CDynamic& v)
    {
        if(this!=&v) 
        {Clean(); CopyOnly(v);}
        return *this;
    }

double rand_d(double b, double e){ return b + (rand() % static_cast<unsigned int>((e - b) * 1000)) / 1000.;  }
     
void CDynamic::AutoSet()     
    {
     srand( time(0) ); // автоматическая рандомизация
     int ran=1 + rand() % 100;
     double *tmp=new double[ran];
      cout << "Random size = " << ran << endl;
      setLength(ran);
      for(int i=0;i<ran;i++) {tmp[i]=rand_d(-100, 100);}
      SetCheat(tmp);
      cout << "Random array: " << endl;
      cout << getCheat();
    } 
    
////////////CTmpArr
CTmpArr::operator double()
{if(i>=0&&i<v->n)return v->v[i];return 0;}

CTmpArr &CTmpArr::operator=(const double &b)
{
if(i>=0)
{
if(i>=v->n)
{int n2=(i+1)*2; double *w=new double[n2]; memset(w,0,sizeof(double)*n2); 
memcpy(w,v->v,v->n*sizeof(double)); 
delete[] v->v; v->v=w; v->n=n2;
}
if(v->nreal<i+1) {v->nreal=i+1;} v->v[i]=b;
}
return *this;
}

//////////////////FRIEND FUNCTIONS////////////////////////
ostream& operator<<(ostream& cout, Arr a)
{
for(int i=0;i<a.GetN();i++)
{cout<<a[i]<<" ";} cout<<endl; 
return cout;
} 

istream& operator>>(istream& cin, Arr& a)
{
double p;
for(int i=0;i<a.GetN();i++)
 {
        cout << "Введите элемент массива Arr № " << (i+1) << ": ";
        cin >> p; a[i]=p;     
 }
 return cin;
}

ostream &operator<<(ostream& cout, CDynamic &v) 
{
   cout << "Массив {";
    for (int i=0; i < v.getLength(); i++)
    { 

     if(i<v.getLength()-1)
      cout << v.getCheat().getArr()[i] << ", "; // cout << v.getCheat()[i] ; 
     else 
      cout << v.getCheat()[i] ; 
     }
   cout << "}\n";

return cout;
}

istream &operator>>(istream& cin , CDynamic &v) 
{
int i,j,k; double tmp[100], cur[5]; double t;
   //for cheat
   for (i=0; i < v.getLength(); i++ ) 
        {
        cout << "Введите элемент списка № " << (i+1) << ": ";
         cin >> t;
         tmp[i]=t;
        }
        v.SetCheat(tmp);
    //for list
  Arr tmpArr;
  int m_tmp=v.getM();
  v.arrList.Clean();
  for (i=0,k=0; i < m_tmp; i++ ) 
        {
           for (j=0; j < 4; j++,k++ )
            {cur[j]= v.getCheat().getArr()[k];}
            //!!!!breaks!!!!//cout << v.getCheat()->getArr()[k] <<endl;
            v.arrList.GoToBegin();   
             for (j=0; j < i; j++ )          
            v.arrList.GoToNext();
           // for (k=0; k < i; k++ ) 
            tmpArr.setArr(cur);
            v.arrList.AddAfter(tmpArr);
        }
return cin;
}

void SortUp(CDynamic& dyn)
{
if(dyn.getList().IsEmpty()){cout << "empty list\n";}

int i=dyn.getLength(); // Длина неотсортированной части массива
int f; //flag
double t;
double *m=new double[dyn.getLength()];  //=dyn.getCheat().getArr();
 memset(m,0, dyn.getLength()*sizeof(double)); 
 memcpy(m, dyn.getCheat().getArr(), dyn.getLength()*sizeof(double));
 for(int k=0;k<dyn.getLength();k++)
  {
  cout<<m[k]<<" ";} cout<<"\n";
  cout<<"\nHere we go sorting...\n";
  do {
   f=0; //Предположим, что массив является отсортированным
   for (int k=0;k<i-1;k++)
   if (m[k]>m[k+1])
    {
    t=m[k]; m[k]=m[k+1]; m[k+1]=t; // Обмен
    f=1; // Массив был неотсортированным
    }
   i--;
   } while (f && i>1);
//output
for(int k=0;k<dyn.getLength();k++)
{cout<<m[k]<<" ";} cout<<"\n";
cout<<"\nSorted!\n";
}

int Check(CDynamic& dyn)
{
if(dyn.getList().IsEmpty()){return 0;}
else return -1;
}

int BinSearch(CDynamic &v, int leftBound, int rightBound)
{ 
    int left = 0;
    int right = v.getLength();
    int mid = 0;

    while (!(left >= right))
    {
        mid = left + (right - left) / 2;

cout<<v.getCheat().getArr()[mid]<<endl;
        if ((v.getCheat().getArr()[mid] > leftBound)&&(v.getCheat().getArr()[mid] < rightBound))
            {cout<<"\nFOUND!\nindex: "<<mid<<"\nvalue: "<<v.getCheat().getArr()[mid]<<endl;return mid;}

        if (v.getCheat().getArr()[mid] > rightBound)
            right = mid;
        else
            left = mid + 1;
    }
    return -(1 + left);
} 
