/*
 * CFunctions.cpp

 */

#include<iostream>
#include<string.h>
#include "CList1.h"
#include "CDynamic.h"
using namespace std;
//////////////////CLASS METHODS///////////////////////////

/////CDynamic
void CDynamic::AddArr(Arr a)        
    {
     double arr[]={1,2,3};
     a.setArr(arr); //for test
    }
void CDynamic::CopyOnly(const CDynamic &v)    
    {
     CList1<Arr> arrList;
     if(this!=&v)
     //{memcpy(&arrList, &v.arrList, v.m*sizeof(double)); 
     arrList=v.arrList;
    }
void CDynamic::InputTo(int pos, double d)      
    {
      pos=0;d=0;
      pos++; d++;
       /* cout << "Вектор {";
        for (int i=0; i < n; i++)
        {  
         if(i<n-1)
            cout << arrList[i] << ", ";
         else
            cout << arrList[i];
        }    
        cout << "}\n";*/
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
{int n2=(v->n+1)*2; double *w=new double[n2]; memset(w,0,sizeof(double)*n2); 
memcpy(w,v->v,v->n*sizeof(double)); 
delete[] v->v; v->v=w; v->n=n2;
}
if(v->nreal<i+1) {v->nreal=i+1;} v->v[i]=b;
}
return *this;
}

////////////CTmpList ПЕРЕДЕЛАТЬ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
CTmpList::operator double()
{if(i>=0&&i<v->n)return v->v[i];return 0;}

CTmpList &CTmpList::operator=(const double &b)
{
if(i>=0)
{
if(i>=v->n)
{int n2=(v->n+1)*2; double *w=new double[n2]; memset(w,0,sizeof(double)*n2); 
memcpy(w,v->v,v->n*sizeof(double)); 
delete[] v->v; v->v=w; v->n=n2;
}
if(v->nreal<i+1) {v->nreal=i+1;} v->v[i]=b;
}
return *this;
}
//////////////////FRIEND FUNCTIONS////////////////////////

ostream &operator<<(ostream& cout, CDynamic &v) 
{
   cout << "Массив {";
     for (int i=0; i < v.getM()*5; i++)
     { 
     if(i<v.getM()*5-1)
       cout << v.getList()  << ", ";
     else 
        cout << v.getList() ; //[i]?
     }    
   cout << "}\n";

return cout;
}
istream &operator>>(istream& cin , CDynamic &v) 
{
 for (int i=0,p; i < v.getM()*5; i++ ) 
        {
            cout << "Введите элемент массива № " << (i+1) << ": ";
            cin >> p;      //v.arrList[i];
            //cout<<v.arrList[i/5]<<endl;
            v.arrList[i/5][(i%5)]=p;
        }
return cin;
}

ostream& operator<<(ostream& cout, Arr& a)
{for(int i=0;i<5;i++){cout<<a[i]<<" ";} cout<<endl; return cout;} 


istream& operator>>(istream& cin, Arr& a)
{
double p;
for(int i=0;i<5;i++)
 {
        cout << "Введите элемент массива Arr № " << (i+1) << ": ";
        cin >> p; a[i]=p;     //v.arrList[i];
 }
 return cin;
}
/*void SortUp(CDynamic& dyn)
{
if(dyn.getList().IsEmpty())){cout << "empty list\n"}

}
void SortDown(CDynamic& dyn)
{
if(dyn.getList().IsEmpty()){cout << "empty list\n"}

}
int Check(CDynamic& dyn)
{
if(dyn.getList().IsEmpty()){return 0;}
else return -1;
}*/
