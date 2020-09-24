/*
 * CFunctions.cpp

 */

#include<iostream>
#include<string.h>
#include "CList1.h"
#include "CDynamic.h"
using namespace std;
//////////////////CLASS METHODS///////////////////////////
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

ostream& operator<<(ostream& cout, Arr& a){for(int i=0;i<5;i++){cout<<a[i]<<" ";}return cout;} 
istream& operator>>(istream& cin, Arr& a){a[0]=0;return cin;}
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
