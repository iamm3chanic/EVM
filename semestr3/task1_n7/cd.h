/* Требуется реализовать динамический массив чисел (значений double) с возможностью сортировки и быстрого (бинарного) поиска. Идея реализации состоит в том, что сначала для хранения выделяется небольшой
   массив фиксированной длины, а по мере добавления элементов выделяются дополнительные такие же массивы, которые связываются в список.
 * 
 Реализация класса должна обеспечивать следующие возможности:
 * 
 * +создать массив заданной начальной длины;
 * +добавить элемент в конец массива (удлиннить массив);
 * +вставить элемент так, чтобы он имел указанный индекс (удлиннить массив);
 * +получить указатель (или ссылку) элемента с заданным индексом для прямого доступа к значению;
 * +удалить элемент по указанному индексу (сократить массив);
 * +получить количество элементов в массиве;
 * +установить новую длину массива;
 * +искать заданное значение (с заданным допуском) в массиве;
 * +сортировать массив по возрастанию или убыванию.
 *
 *  Формальное определение интерфейса не задается и должно быть разработано студентом.
 * Тесты должны включать заполнение массива некоторыми значениями и проверку работы всех 
 * реализованных методов в
 * различных корректных и некорректных ситуациях.
 * В качестве метода сортировки используется алгоритм просеивания (модифицированный 
*/ 


#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "cl.h"
#include <iostream>

using namespace std;

class CTmpNumb;
class Numb;
//class Mass;
//класс массива чисел фикс длины
class Numb
{
private:
 double *v; int N, Nfull;  
public:
 Numb(){Nfull=0; N=5; double *v=new double[N];memset(v,0,N*sizeof(double));} 
 Numb(int m){if(!(m<0)) Nfull=0; N=m; double *v=new double[N];memset(v,0,N*sizeof(double));}
 ~Numb(){Clean();}
 void Clean(){delete[] v; N=0; Nfull=0; v=NULL;}
 void CopyOnly(const Numb &b) {if(this!=&b){this->Nfull=b.Nfull;this->N=b.N;memcpy(v=new double[b.N], b.v, b.N*sizeof(double));}}
 int GetN(){return N;}
 int GetNfull(){return Nfull;}
 //double &operator[](int i){return v[i];}
 CTmpNumb operator[](int i){CTmpNumb t(this,i);return t;} 
 void PutToPos(int i, double a){v[i-1]=a;}  
 friend ostream& operator<<(ostream& cout, Numb a);
 friend class Mass;
 friend class CTmpNumb;
};


class CTmpNumb
{
private:
 Numb *v;int i; 
public:
 CTmpNumb(Numb *v,int i){this->v=v;this->i=i;} 
 operator double(){if(!(i<0)||!(i>v->N))return v[i];return 0;}
 CTmpNumb &operator=(const double &b)
 { 
  if(i>=0)
  {
   if(i>=v->GetN()) {int k=(i+1)*2; double *w=new double[k]; memset(w,0,sizeof(double)*k); memcpy(w,v->v,v->GetN()*sizeof(double)); delete[] v->v; v->v=w; v->GetN()=k;}
   if(v->GetNfull()<i+1) {v->GetNfull()=i+1;} v->v[i]=b;
  } 
   return *this;
 }
 friend class Numb;
};




 


class Mass
{
 int n, m, nfull; CList2 <Numb> NumbL2; 
public:
 Mass(){SetZero();}
 ~Mass(){Clean();} 
 void Clean() {NumbL2.Clean(); SetZero();}
 void SetZero(){NumbL2.SetZero(); nfull=0; n=0; m=0;}
 Mass(int num) {nfull=num; m=num/5+1; for(int i=0;i<m;i++)NumbL2.GoToNext();} 
 void AddToEnd(const double &x){nfull++; if((nfull+1)%5==0){m++; NumbL2.GoToEnd();NumbL2.AddAfter(Numb()); (NumbL2.cur->v[0])=x;}}
 int GetLen(){return nfull;}
 int GetSet(){return m;}
 int GetNum(int i){Numb a; for(int j=0;j<i/5;i++){NumbL2.GoToNext();} a=NumbL2.GetCur(); return a[i%5];}
 friend ostream& operator<<(ostream& cout, Mass &a);
 
};



inline ostream &operator<<(ostream &cout, Numb a){for(int i=0;i<a.GetN();i++){cout<<a[i]<<" ";} cout<<endl; return cout;} 
inline ostream &operator<<(ostream &cout, Mass &c){c.NumbL2.GoToBegin(); for(int i=0;i<c.GetSet();i++){cout<<c.NumbL2.GetCur()<<" "; c.NumbL2.GoToNext();}cout<<endl; return cout;}







