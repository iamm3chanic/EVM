/*
 * CFunctions.cpp

 */

#include<iostream>
#include<string.h>
#include "CList1.h"
#include "CDynamic.h"
using namespace std;
//////////////////CLASS METHODS///////////////////////////

///////////////Arr
void Arr::setArr(double*array)  { //edit
memcpy(v, array, GetN()*sizeof(double));
          /* int i=0;          for (i=0;i<GetN();i++)  v[i] = array[i];*/          
            //cout << "arr[0]=" << array[0]<< "; v[0]=" << v[0]<< endl;
            } 
void Arr::InputTo(int pos, double d)  {
        for(int i=pos;i<5;i++) {v[i]=v[i-1];}
        v[pos-1]=d;
        }      
////////////CDynamic
void CDynamic::AddArr(Arr a)        
    {
    double* tmp;
    tmp=new double[n_real+a.GetN()];
    for(int i=0;i<getM();i++)
    { arrList.GoToNext();}
     arrList.AddAfter(a);
     tmp=cheatArr.getArr();
    for(int i=0;i<n_real;i++) {tmp[i]=cheatArr.getArr()[i];}
    for(int i=1;i<=a.GetN();i++) {tmp[n_real+i]=a[i];}
    setLength(n_real+a.GetN());
    //cout << n_real+a.GetN();
    cheatArr.setArr(tmp);
    cout << "this is cheat:"<<cheatArr;
    
    
     // delete [] tmp;
    }
void CDynamic::CopyOnly(const CDynamic &v)    
    {
     CList1<Arr> arrList;
     if(this!=&v)
     //{memcpy(&arrList, &v.arrList, v.m*sizeof(double)); 
     arrList=v.arrList;
     cheatArr=v.cheatArr;
     //cout << "arr[i]=" << cheatArr[0]<<  endl;
    }
void CDynamic::SetCheat(double* a)
    {
     //cheatArr.setN(a.length);
     cheatArr.setArr(a);
     // cout << cheatArr[1] <<"  in setcheat\n";
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
      //memcpy(a, arrList.GetCur(), sizeof(Arr)); 
      a= arrList.GetCur();
      a.InputTo(pos%5, d);
      arrList.SetCur(a);
    }
void CDynamic::InputInto(int pos, double d)      
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
    
/*CDynamic& CDynamic::operator=(const CDynamic&& v)
    {
        if(this!=&&v) 
        {Clean(); CopyOnly(v);}
        return *this;
    }*/
  
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
{for(int i=0;i<a.GetN();i++){cout<<a[i]<<" ";} cout<<endl; return cout;} 


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
     // cout << v.getCheat()[i] << ", ";
      cout << v.getCheat().getArr()[i] << ", ";
     else 
      cout << v.getCheat()[i] ; //[i]?
     }
  /* for (int i=0; i < v.getLength(); i++)
    { 

     if(i<v.getLength()-1)
      cout << v.getCheat()[i]  << ", ";
     // cout << v.getCheat().getArr()[i] << ", ";
     else 
      cout << v.getCheat()[i] ; //[i]?
     }*/
   cout << "}\n";

return cout;
}
istream &operator>>(istream& cin , CDynamic &v) 
{
int i,j,k; double tmp[100], cur[5]; double t;
   for (i=0; i < v.getLength(); i++ ) 
        {
        cout << "Введите элемент списка № " << (i+1) << ": ";
         cin >> t;
         tmp[i]=t;
        }
        v.SetCheat(tmp);
    //Теперь сделаем, как просили, а не через cheatArr:

  Arr tmpArr;
  int m_tmp=v.getM();
  v.arrList.Clean();
  for (i=0,k=0; i < m_tmp; i++ ) 
        {
           for (j=0; j < 4; j++,k++ )
            //{cout << "Введите элемент списка № " << (i+1) << " массива  №" << (j+1) <<": ";
            //cin >> input; 
            {cur[j]=
           // v.getCheat()->getArr()[k];}
            v.getCheat().getArr()[k];}
            //!!!!breaks!!!!cout << v.getCheat()->getArr()[k] <<endl;
            //cout << v.getCheat().getArr()[k] <<endl;
            v.arrList.GoToBegin();   
             for (j=0; j < i; j++ )          
            v.arrList.GoToNext();
           // for (k=0; k < i; k++ ) 
            tmpArr.setArr(cur);
            v.arrList.AddAfter(tmpArr);
          //  v.arrList[i/5][(i%5)]=p; //DEAL????????
        }
return cin;
}


/*istream& operator>>(istream& cin, double *a)
{
double p;
for(int i=0;i<5;i++)
 {
        cout << "Введите элемент массива Arr № " << (i+1) << ": ";
        cin >> p; a[i]=p;     //v.arrList[i];
 }
 return cin;
}

istream &operator>>(istream& cin, CList1<Arr>& a)
{ Arr b; cout<<"here";
for(int i=0; i<a.GetLength();i++) 
{cout<<"here"; cin >> b; a[i]=b;}
return cin; }*/
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
{cout<<m[k]<<" ";} cout<<"\n";
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
}

int Check(CDynamic& dyn)
{
if(dyn.getList().IsEmpty()){return 0;}
else return -1;
}
