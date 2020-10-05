/*
 * CFunctions.cpp

 */
#include<iostream>
#include<string.h>
#include <ctime>
#include <cstdlib>
#include "CList2.h"
#include "CDynamic.h"
using namespace std;
//////////////////CLASS METHODS///////////////////////////

///////////////Arr
void Arr::setArr(double*array)  { 
    //но мы не знаем GetN()!!!!!!
      memcpy(v, array, GetN()*sizeof(double));
      } 
      
void Arr::InputTo(int pos, double d)  {
        v[pos-1]=d;
       }    
       
void Arr::CopyOnly(const Arr &b) {
       if(this!=&b)
	{SetZero();nreal=b.nreal;n=b.n;
	memcpy(v=new double[n],b.v, b.n*sizeof(double));}
       } 
         
////////////CDynamic

void CDynamic::AddToEnd(double d)
   {
   //for cheat
   int y=getLength()+1;
    double *t=new double[getLength()+1];
    for(int i=0;i<getLength();i++)
    {t[i]=cheatArr.getArr()[i];}
    //t[getLength()]=d;
    t[y-1]=d;
    cheatArr.SetN(y);
    cheatArr.setArr(t);
    //for list
    /*Arr a;
      arrList.GoToEnd();
      //a= arrList.GetCur();
      a.setArr( arrList.GetCur().getArr() );  
     // memcpy(&a, &arrList.GetCur(), sizeof(Arr)); 
      if (a.GetN()<5) a.InputTo(4,d);
      else {Arr b; b[0]=d; arrList.CList2<Arr>::AddToEnd(b);}*/
   }

double CDynamic::GetNumByIndex(int index) 
    {
     return cheatArr.getArr()[index];   
    }   
    
void CDynamic::DelNumByIndex(int index)
    {
    int y=getLength()-1;
    double *t=new double[getLength()-1];
    for(int i=0;i<index;i++)
    {t[i]=cheatArr.getArr()[i];}
    for(int i=index;i<y;i++)
    {t[i]=cheatArr.getArr()[i+1];}
    //t[getLength()]=d;
    cheatArr.SetN(y);
    cheatArr.setArr(t);
    }
void CDynamic::CopyOnly(const CDynamic &v)    
    {
     CList2<Arr> arrList;
     if(this!=&v)
     //{memcpy(&arrList, &v.arrList, v.m*sizeof(Arr); 
     //arrList=CList2<Arr>::CopyOnly(v.arrList);
     cheatArr=v.cheatArr;
    }
   
void CDynamic::SetCheat(double* a)
    {
     cheatArr.setArr(a);
    }
    
void CDynamic::InputTo(int pos, double d)      
    {
      //for cheat
      //for(int i=pos;i<n_real;i++) {cheatArr[i]=cheatArr[i+1];}
      cheatArr[pos-1]=d;
      //for list
      Arr a;
      for(int i=0;i<pos/5;i++) {arrList.GoToNext();}
      a.SetN(5);
      a.setArr( arrList.GetCur().getArr() );   //memcpy(a, arrList.GetCur(), sizeof(Arr)); 
      a.InputTo(pos%5, d);
      arrList.AddToPos(a,(pos/5));
    }
    
void CDynamic::InputInto(int pos, double d)      
    {
     int y=getLength()+1;
    double *t=new double[getLength()+1];
    for(int i=0;i<pos-1;i++)
    {t[i]=cheatArr.getArr()[i];}
    t[pos-1]=d;
    for(int i=pos;i<y-1;i++)
    {t[i]=cheatArr.getArr()[i-1];}
   //cout<<t[y-1]<<"hre";   
    cheatArr.SetN(y+1);
    cheatArr.setArr(t);
      //for(int i=pos;i<n_real;i++) {cheatArr[i]=cheatArr[i-1];}
      //cheatArr[pos-1]=d;
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
////////////CList2
template<class T> void CList2<T>::AddToPos(const T&x, int pos){
	CList2Node<T>* tmp=cur;
	GoToPos(pos);
	AddBefore(x);
	cur=tmp;

}
template<class T> bool CList2<T>::DelCur(){
	if(IsEmpty()) return false;
	if(cur->prev) cur->prev->next=cur->next; else first=cur->next;
	if(cur->next) cur->next->prev=cur->prev; else last=cur->prev;
	if(cur->prev) cur=cur->prev; else cur=cur->next;
	return true;
}

template<class T> void CList2<T>::AddAfter(const T &x){
	CList2Node<T> *n=new CList2Node<T>(); n->v=x;
	if(IsEmpty()){cur=first=last=n;}
	else{
		n->next=cur->next;
		n->prev=cur;
		cur->next=n;
		if(n->next)
			n->next->prev=n;
		else last=n;
	}
}

template<class T> void CList2<T>::AddBefore(const T &x){
	CList2Node<T> *n=new CList2Node<T>(); n->v=x;
	if(IsEmpty()){cur=first=last=n;}
	else{
		n->prev=cur->prev;
		n->next=cur;
		cur->prev=n;
		if(n->prev)
			n->prev->next=n;
		else first=n;
	}
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

