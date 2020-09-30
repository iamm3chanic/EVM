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
     cheatArr=v.cheatArr;
     //cout << "arr[i]=" << cheatArr[0]<<  endl;
    }
void CDynamic::SetCheat(double *a)
    {
     //cheatArr.setN(a.length);
     cheatArr.setArr(a);
     // cout << cheatArr[1] <<"  in setcheat\n";
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

////////////CTmpList ПЕРЕДЕЛАТЬ!!!!!!!!!!!!!!!!!!!!!!!!!!!!CListNode<T> t,*cur
/*CTmpList::operator Arr()
{if(i>=0&&i<n)return v->GetCur();return NULL;}

CTmpList &CTmpList::operator=( Arr &v)
{
int n=v.GetN();
//Arr a; 
//a.setArr(b.getArr());
//a[0]=b.v[0];
if(i>=0)
{
if(i>=n)
{int n2=n+5; Arr *w=new Arr[n2]; memset(w,0,sizeof(Arr)*n2)
double array[]={1,2,3,4,5};
w->setArr(array); 
memcpy(w,v.getArr(), v.GetN()*sizeof(Arr));
//////////Clean();  ///////////////
}
//if(v->nreal<i+1) {v->nreal=i+1;} v->v[i]=b;
}//
return *this;
}*/
//////////////////FRIEND FUNCTIONS////////////////////////
ostream& operator<<(ostream& cout, Arr& a)
{for(int i=0;i<5;i++){cout<<a[i]<<" ";} cout<<endl; return cout;} 


istream& operator>>(istream& cin, Arr& a)
{
double p;
for(int i=0;i<5;i++)
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
      // cout << v.getCheat()[i]  << ", ";
      cout << v.getCheat()->getArr()[i] << ", ";
     else //if(i==v.getLength()-1)
      cout << v.getCheat()->getArr()[i] ; //[i]?
     }
    /* for (int i=0; i < v.getM(); i++)
     { 
     if(i<v.getM())
       cout << v.getList()  << ", ";
     else 
        cout << v.getList() ; //[i]?
     }    */
   cout << "}\n";

return cout;
}
istream &operator>>(istream& cin , CDynamic &v) 
{
int i; double tmp[100]; double t;
   for (i=0; i < v.getLength(); i++ ) 
        {
        cout << "Введите элемент списка № " << (i+1) << ": ";
         cin >> t;
         tmp[i]=t;
        }
        v.SetCheat(tmp);
        //cout << tmp[0] <<"  in cin dyn\n";
        //cout << v.getCheat().getArr()[1] << "  in cin dyn\n";
/*int i,j;
double input; double tmp[5];
Arr tmpArr=Arr();

 for (i=0; i < v.getM(); i++ ) 
        {
        
        //cin >> v.arrList;
           for (j=0; j < 5; j++ )
            {cout << "Введите элемент списка № " << (i+1) << " массива  №" << (j+1) <<": ";
            cin >> input; 
            tmp[j]=input;}
            v.arrList.GoToBegin();   
             for (j=0; j < i; j++ )          
            v.arrList.GoToNext();
           // for (k=0; k < i; k++ ) 
            tmpArr.setArr(tmp);
            v.arrList.AddAfter(tmpArr);
          //  v.arrList[i/5][(i%5)]=p; //DEAL????????
        }*/
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
}*/

istream &operator>>(istream& cin, CList1<Arr>& a)
{ Arr b; cout<<"here";
for(int i=0; i<a.GetLength();i++) 
{cout<<"here"; cin >> b; a[i]=b;}
return cin; }
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
