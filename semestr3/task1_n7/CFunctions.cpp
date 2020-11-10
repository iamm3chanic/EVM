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
    //но мы не знаем GetN()!!!!!! Надо сначала засетать его.
      memcpy(v, array, GetN()*sizeof(double));
      memset(b, 1, GetN()*sizeof(bool));
      //cout<<b[0]<<b[1]<<b[2]<<endl;
      } 

void Arr::setB(bool*array)  {
    memcpy(b, array, GetN()*sizeof(bool));
}
      
void Arr::InputTo(int pos, double d)  {
    if(pos<n)
        v[pos-1]=d;
       }    
 
void Arr::DelPos(int pos) {
     if(pos>n){cout<<"Слишком большой номер!\n"; return;}
     if(pos<0){cout<<"Слишком маленький номер!\n"; return ;}
     v[pos]=0;
     }  

void Arr::CopyOnly(const Arr &a) {
       if(this!=&a)
	{SetZero();
    nreal=a.nreal;
  //SetN(a.n); 
   n=a.n;
	if(a.v)memcpy(v=new double[a.n],a.v, a.n*sizeof(double));
  if(a.b)memcpy(b=new bool[a.n],a.b, a.n*sizeof(bool));
  }
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
    setLength(y);
    cheatArr.SetN(y);
    cheatArr.setArr(t);
    delete[] t;
    //for list
    rewrite();
     /*Arr tmpArr=Arr(5); double cur[5]; bool cb[5];
    int i,j,k;
  memset(cur,0,5*sizeof(double));
  memset(cb,1,5*sizeof(bool));
  int m_tmp=getLength()/5;
  arrList.Clean();
  arrList.AddAfter(tmpArr); 
  for (i=0,k=0; i < m_tmp; i++ ) 
        {
           for (j=0; (j < 5) && (k<cheatArr.GetN()-(cheatArr.GetN()%5)); j++,k++ )
            {
               cur[j]= cheatArr.getArr()[k];
               //cout<<"i'm in huge part\n";
            } 
             for (j=0; j < i; j++ )          
            arrList.GoToNext();         
            tmpArr.SetN(5);
            tmpArr.setArr(cur);
            tmpArr.setB(cb);
            //cout<<tmpArr;
            arrList.AddAfter(tmpArr);
        }
        memset(cb,0,5*sizeof(bool));
   for (j=0; (j < (cheatArr.GetN()%5)); j++,k++ )
            {
               cur[j]= cheatArr.getArr()[k]; //cout<<j<<" "<<cur[j]<<"j!\n";
               cb[j]=1;
               //cout<<"i'm in small part\n";
            }
             for (j=0; j < i; j++ )          
            {arrList.GoToNext();}
            tmpArr.SetN(cheatArr.GetN()%5);
            tmpArr.setArr(cur);
            tmpArr.setB(cb);
            //cout<<tmpArr<<endl;
            arrList.AddAfter(tmpArr);*/
   }

double CDynamic::GetNumByIndex(int index) 
    {
    //for cheat
     if(index>n_real){cout<<"Слишком большой номер!\n"; return -1000;}
     if(index<0){cout<<"Слишком маленький номер!\n"; return -1001;}
     return cheatArr.getArr()[index];   
    //for list
    Arr a;
      for(int i=0;i<index/5;i++) {arrList.GoToNext();}
      
      a= arrList.GetCur();
      return a[index%5];
    }   
    
void CDynamic::DelNumByIndex(int index)
    {
    //for cheat
    if(index>n_real){cout<<"Слишком большой номер!\n"; return ;}
    if(index<0){cout<<"Слишком маленький номер!\n"; return ;}
    int y=getLength()-1;
    double *t=new double[getLength()-1];
    for(int i=0;i<index;i++)
    {t[i]=cheatArr.getArr()[i];}
    for(int i=index;i<y;i++)
    {t[i]=cheatArr.getArr()[i+1];}
    cheatArr.SetN(y);
    cheatArr.setArr(t);
    delete[] t;
    //for list
    rewrite();
      /*for(int i=0;i<index/5;i++) {arrList.GoToNext();}
      //a.SetN(5);
      //a.setArr( arrList.GetCur().getArr() );   //memcpy(a, arrList.GetCur(), sizeof(Arr));
      a= arrList.GetCur(); 
      a.DelPos(index%5);
      arrList.AddToPos(a,(index/5));
     Arr tmpArr=Arr(5); double cur[5]; bool cb[5];
    int i,j,k;
  memset(cur,0,5*sizeof(double));
  memset(cb,1,5*sizeof(bool));
  int m_tmp=getLength()/5;
  arrList.Clean();
  arrList.AddAfter(tmpArr); 
  for (i=0,k=0; i < m_tmp; i++ ) 
        {
           for (j=0; (j < 5) && (k<cheatArr.GetN()-(cheatArr.GetN()%5)); j++,k++ )
            {
               cur[j]= cheatArr.getArr()[k];
               //cout<<"i'm in huge part\n";
            } 
             for (j=0; j < i; j++ )          
            arrList.GoToNext();         
            tmpArr.SetN(5);
            tmpArr.setArr(cur);
            tmpArr.setB(cb);
            //cout<<tmpArr;
            arrList.AddAfter(tmpArr);
        }
        memset(cb,0,5*sizeof(bool));
   for (j=0; (j < (cheatArr.GetN()%5)); j++,k++ )
            {
               cur[j]= cheatArr.getArr()[k]; //cout<<j<<" "<<cur[j]<<"j!\n";
               cb[j]=1;
               //cout<<"i'm in small part\n";
            }
             for (j=0; j < i; j++ )          
            {arrList.GoToNext();}
            tmpArr.SetN(cheatArr.GetN()%5);
            tmpArr.setArr(cur);
            tmpArr.setB(cb);
            //cout<<tmpArr<<endl;
            arrList.AddAfter(tmpArr);*/
    }
void CDynamic::CopyOnly(const CDynamic &v)    
    {
     //CList2<Arr> arrList;
     if(this!=&v)
     //{memcpy(&arrList, &v.arrList, v.m*sizeof(Arr); 
      { Clean();
     n=v.n; m=v.m;n_real=v.n_real;
     arrList=(v.arrList);
     cheatArr=v.cheatArr;
      }
    }
   
void CDynamic::SetCheat(double* a)
    {
     cheatArr.setArr(a);
    }
    
void CDynamic::InputTo(int pos, double d)      
    {
      //for cheat
      if(pos>n_real){cout<<"Слишком большой номер!\n"; return ;}
      if(pos<0){cout<<"Слишком маленький номер!\n"; return ;}
      cheatArr[pos-1]=d;
      //for list
      rewrite();
      /*Arr a(5);
      for(int i=0;i<pos/5;i++) {arrList.GoToNext();}
      a.SetN(5);
      //a.setArr( arrList.GetCur().getArr() );   //memcpy(a, arrList.GetCur(), sizeof(Arr)); 
      a=arrList.GetCur();
      a.setB( arrList.GetCur().getB());
      a.InputTo(pos%5, d);
      cout<<a<<endl;
      //arrList.AddToPos(a,(pos/5));
      arrList.AddAfter(a);
      Arr tmpArr=Arr(5); double cur[5]; bool cb[5];
    int i,j,k;
  memset(cur,0,5*sizeof(double));
  memset(cb,1,5*sizeof(bool));
  int m_tmp=getLength()/5;
  arrList.Clean();
  arrList.AddAfter(tmpArr); 
  for (i=0,k=0; i < m_tmp; i++ ) 
        {
           for (j=0; (j < 5) && (k<cheatArr.GetN()-(cheatArr.GetN()%5)); j++,k++ )
            {
               cur[j]= cheatArr.getArr()[k];
               //cout<<"i'm in huge part\n";
            } 
             for (j=0; j < i; j++ )          
            arrList.GoToNext();         
            tmpArr.SetN(5);
            tmpArr.setArr(cur);
            tmpArr.setB(cb);
            //cout<<tmpArr;
            arrList.AddAfter(tmpArr);
        }
        memset(cb,0,5*sizeof(bool));
   for (j=0; (j < (cheatArr.GetN()%5)); j++,k++ )
            {
               cur[j]= cheatArr.getArr()[k]; //cout<<j<<" "<<cur[j]<<"j!\n";
               cb[j]=1;
               //cout<<"i'm in small part\n";
            }
             for (j=0; j < i; j++ )          
            {arrList.GoToNext();}
            tmpArr.SetN(cheatArr.GetN()%5);
            tmpArr.setArr(cur);
            tmpArr.setB(cb);
            //cout<<tmpArr<<endl;
            arrList.AddAfter(tmpArr);*/
  }
    
void CDynamic::InputInto(int pos, double d)      
    {
    //for cheat
    if(pos>n_real){cout<<"Слишком большой номер!\n"; return ;}
    if(pos<0){cout<<"Слишком маленький номер!\n"; return ;}
     int y=getLength()+1;
    double *t=new double[getLength()+1];
    for(int i=0;i<pos-1;i++)
    {t[i]=cheatArr.getArr()[i];}
    t[pos-1]=d;
    for(int i=pos;i<y;i++)
    {t[i]=cheatArr.getArr()[i-1];}  
    setLength(y);
    //cheatArr.SetN(y);
    cheatArr.setArr(t);
    delete[] t;
     //for list 
    rewrite();
     /*Arr a;
      for(int i=0;i<pos/5;i++) {arrList.GoToNext();}
      a= arrList.GetCur();
      //a.SetN(5);
      //a.setArr( arrList.GetCur().getArr() );  
      //memcpy(&a, &arrList.GetCur(), 1); 
      
      a.InputTo(pos%5, d);
      arrList.AddToPos(a,(pos/5));
        Arr tmpArr=Arr(5); double cur[5]; bool cb[5];
    int i,j,k;
  memset(cur,0,5*sizeof(double));
  memset(cb,1,5*sizeof(bool));
  int m_tmp=getLength()/5;
  arrList.Clean();
  arrList.AddAfter(tmpArr); 
  for (i=0,k=0; i < m_tmp; i++ ) 
        {
           for (j=0; (j < 5) && (k<cheatArr.GetN()-(cheatArr.GetN()%5)); j++,k++ )
            {
               cur[j]= cheatArr.getArr()[k];
               //cout<<"i'm in huge part\n";
            } 
             for (j=0; j < i; j++ )          
            arrList.GoToNext();         
            tmpArr.SetN(5);
            tmpArr.setArr(cur);
            tmpArr.setB(cb);
            //cout<<tmpArr;
            arrList.AddAfter(tmpArr);
        }
        memset(cb,0,5*sizeof(bool));
   for (j=0; (j < (cheatArr.GetN()%5)); j++,k++ )
            {
               cur[j]= cheatArr.getArr()[k]; //cout<<j<<" "<<cur[j]<<"j!\n";
               cb[j]=1;
               //cout<<"i'm in small part\n";
            }
             for (j=0; j < i; j++ )          
            {arrList.GoToNext();}
            tmpArr.SetN(cheatArr.GetN()%5);
            tmpArr.setArr(cur);
            tmpArr.setB(cb);
            //cout<<tmpArr<<endl;
            arrList.AddAfter(tmpArr);*/
    }
    

    
CDynamic& CDynamic::operator=(const CDynamic& v)
    {
        if(this!=&v) 
        {Clean(); CopyOnly(v);}
        return *this;
    }

void CDynamic::rewrite() {
  Arr tmpArr=Arr(5); double cur[5]; bool cb[5];
    int i,j,k;
  memset(cur,0,5*sizeof(double));
  memset(cb,1,5*sizeof(bool));
  int m_tmp=getLength()/5;
  arrList.Clean();
  arrList.AddAfter(tmpArr); 
  for (i=0,k=0; i < m_tmp; i++ ) 
        {
           for (j=0; (j < 5) && (k<cheatArr.GetN()-(cheatArr.GetN()%5)); j++,k++ )
            {
               cur[j]= cheatArr.getArr()[k];
               //cout<<"i'm in huge part\n";
            } 
             for (j=0; j < i; j++ )          
            arrList.GoToNext();
 //v.arrList.AddAfter(tmpArr);          
            tmpArr.SetN(5);
            tmpArr.setArr(cur);
            tmpArr.setB(cb);
            //cout<<tmpArr;
            arrList.AddAfter(tmpArr);
        }
        memset(cb,0,5*sizeof(bool));
   for (j=0; (j < (cheatArr.GetN()%5)); j++,k++ )
            {
               cur[j]= cheatArr.getArr()[k]; //cout<<j<<" "<<cur[j]<<"j!\n";
               cb[j]=1;
               //cout<<"i'm in small part\n";
            }
             for (j=0; j < i; j++ )          
            {arrList.GoToNext();}
            tmpArr.SetN(cheatArr.GetN()%5);
            tmpArr.setArr(cur);
            tmpArr.setB(cb);
            //cout<<tmpArr<<endl;
            arrList.AddAfter(tmpArr);
          }

double rand_d(double b, double e){ return b + (rand() % static_cast<unsigned int>((e - b) * 1000)) / 1000.;  }
     
void CDynamic::AutoSet()     
    {
    //for cheat
      SetZero();
     srand( time(0) ); // автоматическая рандомизация
     int ran=1 + rand() % 100;
     double *tmp=new double[ran];
      cout << "Random size = " << ran << endl;
      setLength(ran);
      for(int i=0;i<ran;i++) {tmp[i]=rand_d(-100, 100); }
      cheatArr.SetN(ran);
      SetCheat(tmp);
      cout << "Random array: " << endl;
      cout << getCheat();
     //for list 
    Arr tmpArr=Arr(5); double cur[5]; bool cb[5];
    int i,j,k;
  memset(cur,0,5*sizeof(double));
  memset(cb,1,5*sizeof(bool));
  int m_tmp=getLength()/5;
  arrList.Clean();
  arrList.AddAfter(tmpArr); 
  for (i=0,k=0; i < m_tmp; i++ ) 
        {
           for (j=0; (j < 5) && (k<cheatArr.GetN()-(cheatArr.GetN()%5)); j++,k++ )
            {
               cur[j]= cheatArr.getArr()[k];
               //cout<<"i'm in huge part\n";
            } 
             for (j=0; j < i; j++ )          
            arrList.GoToNext();
 //v.arrList.AddAfter(tmpArr);          
            tmpArr.SetN(5);
            tmpArr.setArr(cur);
            tmpArr.setB(cb);
            //cout<<tmpArr;
            arrList.AddAfter(tmpArr);
        }
        memset(cb,0,5*sizeof(bool));
   for (j=0; (j < (cheatArr.GetN()%5)); j++,k++ )
            {
               cur[j]= cheatArr.getArr()[k]; //cout<<j<<" "<<cur[j]<<"j!\n";
               cb[j]=1;
               //cout<<"i'm in small part\n";
            }
             for (j=0; j < i; j++ )          
            {arrList.GoToNext();}
            tmpArr.SetN(cheatArr.GetN()%5);
            tmpArr.setArr(cur);
            tmpArr.setB(cb);
            //cout<<tmpArr<<endl;
            arrList.AddAfter(tmpArr);
        delete [] tmp;  
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
	auto *x=cur;
	if(cur->prev) {cur->v.Clean();cur->prev->next=cur->next;} else first=cur->next;
	if(cur->next) {cur->v.Clean();cur->next->prev=cur->prev;} else last=cur->prev;
	if(cur->prev) {cur->v.Clean();cur=cur->prev;} else cur=cur->next;
	delete x;
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
for(int i=0;(i<a.GetN())&&(a.getB()[i]!=0);i++) //exist?
{cout<<a.getArr()[i]<<" ";} //cout<<endl; 
return cout;
} 

istream& operator>>(istream& cin, Arr& a)
{
double p;
for(int i=0;i<a.GetN();i++)
 {
        cout << "Введите элемент массива Arr № " << (i+1) << ": ";
        cin >> p; a[i]=p;   
        a.b[i]=1; 
       // cout << a.b[i]<<" "<<a.v[i]; 
 }
 return cin;
}

ostream &operator<<(ostream& cout, CDynamic &v) 
{
  v.arrList.GoToBegin();
   cout << "Массив {";
   cout<<v.arrList;
    /*for (int i=0; (i < v.getM()); i++)
    { 

     if(i<v.getM()-1)
      //cout << v.getCheat().getArr()[i] << ", "; // cout << v.getCheat()[i] ; 
      {cout<< v.getList().GetCur(); v.getList().GoToNext();}
     else 
      cout << v.getList().GetCur();
      
     }*/
   cout << "}\n";

return cout;
}

istream &operator>>(istream& cin , CDynamic &v) 
{
int i,j,k; double tmp[100]; double t;
   //for cheat
   //предполагается, что длину мы заранее задали
   for (i=0; i < v.getLength(); i++ ) 
        {
        cout << "Введите элемент списка № " << (i+1) << ": ";
         cin >> t;
         tmp[i]=t;
        }
        v.SetCheat(tmp);
    //for list
  Arr tmpArr=Arr(5); double cur[5]; bool cb[5];
  memset(cur,0,5*sizeof(double));
  memset(cb,1,5*sizeof(bool));
  int m_tmp=v.getLength()/5;
  v.arrList.Clean();
  v.arrList.AddAfter(tmpArr); 
  for (i=0,k=0; i < m_tmp; i++ ) 
        {
           for (j=0; (j < 5) && (k<v.cheatArr.GetN()-(v.cheatArr.GetN()%5)); j++,k++ )
            {
               cur[j]= v.cheatArr.getArr()[k];
               //cout<<"i'm in huge part\n";
            }
          /*for (;  (k<v.cheatArr.GetN()-(v.cheatArr.GetN()%5)); k++ )
            {
              for (j=0; (j < 4); j++)
               cur[j]= v.cheatArr.getArr()[k];
               //cout<<"i'm in huge part\n";
            }*/
            //cout << v.cheatArr.getArr()[1];  
             for (j=0; j < i; j++ )          
            v.arrList.GoToNext();
 //v.arrList.AddAfter(tmpArr);          
            tmpArr.SetN(5);
            tmpArr.setArr(cur);
            tmpArr.setB(cb);
            //cout<<tmpArr;
            v.arrList.AddAfter(tmpArr);
        }
        memset(cb,0,5*sizeof(bool));
   for (j=0; (j < (v.cheatArr.GetN()%5)); j++,k++ )
            {
               cur[j]= v.cheatArr.getArr()[k]; //cout<<j<<" "<<cur[j]<<"j!\n";
               cb[j]=1;
               //cout<<"i'm in small part\n";
            }
            //v.arrList.GoToBegin();   
//v.arrList.AddAfter(tmpArr);
             for (j=0; j < i; j++ )          
            {v.arrList.GoToNext();}
            tmpArr.SetN(v.cheatArr.GetN()%5);
            tmpArr.setArr(cur);
            tmpArr.setB(cb);
            //cout<<tmpArr<<endl;
            v.arrList.AddAfter(tmpArr);
            //cout<<v.arrList;
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
 cout<<"\n";
 /*for(int k=0;k<dyn.getLength();k++)
  {cout<<m[k]<<" ";} cout<<"\n";*/
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
{
dyn.getCheat().getArr()[k]=m[k];
cout<<m[k]<<" ";
} cout<<"\n";
cout<<"\nSorted!\n";
delete [] m;
}

int Check(CDynamic& dyn)
{
if(dyn.getList().IsEmpty()){cout<<"Список пуст!\n";return -2;}
else 
for (int i=0;i<dyn.getLength()-1;i++)
{if(dyn.getCheat()[i]>dyn.getCheat()[i+1]) {cout<<"Список не отсортирован!\n";return -1;}}
cout<<"Список отсортирован!\n";
return 0;
}

int BinSearch(CDynamic &v, int leftBound, int rightBound)
{ 
    int left = 0;
    int right = v.getLength();
    int mid = 0;
    //проверим на отсортированность
    if(Check(v)<0){return -2;}
    //проверим на плохие границы
    if((leftBound>v.getCheat()[right-1])||(rightBound<v.getCheat()[0])||(leftBound>rightBound)) {cout<<"bad bounds...\n";return -1;}
    //проверим на вырожденный простой случай
    if((leftBound>v.getCheat().getArr()[0])&&(rightBound>v.getCheat().getArr()[right-1])&&(leftBound<v.getCheat().getArr()[right-1]))
    {cout<<"\nFOUND!\nindex: "<<right-1<<"\nvalue: "<<v.getCheat().getArr()[right-1]<<endl;return right-1;} 
    if((leftBound<v.getCheat().getArr()[0])&&(rightBound<v.getCheat().getArr()[right-1])&&(rightBound>v.getCheat().getArr()[0]))
    {cout<<"\nFOUND!\nindex: "<<0<<"\nvalue: "<<v.getCheat().getArr()[0]<<endl;return 0;} 
    //бинарный поиск
    while (!(left >= right))
    {
        mid = left + (right - left) / 2;
//cout<<v.getCheat().getArr()[mid]<<endl;
        if ((v.getCheat().getArr()[mid] >= leftBound)&&(v.getCheat().getArr()[mid] <= rightBound))
            {cout<<"\nFOUND!\nindex: "<<mid<<"\nvalue: "<<v.getCheat().getArr()[mid]<<endl;return mid;}           
        if ((v.getCheat().getArr()[left] >= leftBound)&&(v.getCheat().getArr()[right-1] <= rightBound))
          //SUPER! 
          {right=left;}
        if (v.getCheat().getArr()[mid] > rightBound)
            right = mid;
        else //if (v.getCheat().getArr()[mid] < rightBound)
            left = mid+1;  
    }
    cout<<"not found...\n";
    return -(1 + left);
} 

