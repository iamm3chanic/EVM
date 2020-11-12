/*
 * CFunctions.cpp
 6. Дано множество точек. Найти центр и радиус минимального круга, который содержит все эти точки.
 */
 //Additions: add autofree, static array to FindMaxD
#include<iostream>
#include<math.h>
#include "Classes.h"
using namespace std;

/////////////////CLASS METHODS///////////////////
void CDot::ShowDot()       //Показать вектор
    {
        cout << "Точка {";
        for (int i=0; i < 2; i++)
        { 
         if(i<1)
            cout << x << ", ";
         else 
            cout << y;
        }    
        cout << "}\n";
    }
CDot& CDot::operator=(const CDot& v)
    {
         x=v.x; y=v.y;
        return *this;
    }
/////////////////CLASS METHODS///////////////////
void CCircle::ShowCircle()       //Показать вектор
    {
        cout << "Круг {радиус: " << r <<", центр: " <<d.GetX()<<", " << d.GetY();         
        cout << "}\n";
    }
CCircle& CCircle::operator=(const CCircle& v)
    {
         r=v.r; d=v.d;
        return *this;
    }
    
////////////////FRIEND FUNCTIONS///////////////////

ostream &operator <<(ostream &cout, const CDot& v) 
{
 cout << "Точка {";
        for (int i=0; i < 2; i++)
        { 
         if(i<1)
            cout << v.x << ", ";
         else 
            cout << v.y;
        }    
        cout << "}\n";
return cout;
}
istream &operator >>(istream &cin ,  CDot &v) 
{
double x,y;
            cout << "Введите x: ";
            cin >> x; 
            cout << "Введите y: ";
            cin >> y;
            CDot b(x,y); v=b;
return cin;
}

ostream &operator <<(ostream &cout,  CCircle& v) 
{
 cout << "Круг {радиус: " << v.GetR() <<", центр: " <<v.GetD().GetX()<<", " << v.GetD().GetY();
 cout << "}\n";
return cout;
}
istream &operator >>(istream &cin , CCircle &v) 
{
double x,y,r;
            cout << "Введите x: ";
            cin >> x; 
            cout << "Введите y: ";
            cin >> y;
            cout << "Введите r: ";
            cin >> r;
             CCircle b(r,x,y); v=b;
return cin;
}

int NReader()
    {
      int n;
      cout << "Введите количество точек: ";
      cin >> n;
      return n;
    } 
  
bool IsInCircle(CDot d, CCircle c)
{
//(X - Xo)^2 +(Y - Yo)^2 <= R^2, Здесь (X, Y) - координаты точки.
//Если неравенство выполняется, то точка принадлежит кругу.
if((d.GetX()-c.GetD().GetX())*(d.GetX()-c.GetD().GetX()) +
(d.GetY()-c.GetD().GetY())*(d.GetY()-c.GetD().GetY()) <=
c.GetR()*c.GetR())
{return 1;}
else return 0;
}

void BuildCircle(CDot *d)
{
if(d==NULL) { cout<< "d1 is emply!";return;}
else 
{
size_t i=0;
//let's get n somehow... (sizeof(d)/sizeof(CDot)) is bad.
//for(i=0;d[i]!=NULL;i++){} //also bad
//for(CDot &dots : d) {i++;cout<<dots;}
//i=sizeof(*d); cout<<i<<endl;
//h=sizeof(d[0]); cout<<h<<endl;
 if(i==1) { CCircle c(0,d[0].GetX(),d[0].GetY()); cout<<c;}

}
}

double FindMax(CDot *d,int n)
{
if(d==NULL) { cout<< "Dot array is emply!"; throw -1;}
int i,j;//i1,j1;
double r,maxr;
double *x = new double[n];
double *y = new double[n];
 for(int k=0;k<n;k++){x[k]=d[k].GetX();y[k]=d[k].GetY();}
maxr=0;
for(i=0;i<n;i++)
   {
   for(j=i+1;j<n;j++)
      {
      r=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
      if(r>maxr){maxr=r;}
      }
   }
 delete[] x; delete[] y;
return maxr;
}

CDot* FindMaxD(CDot *d,int n)
{
if(d==NULL) { cout<< "Dot array is emply!"; throw -1;}
int i,j,i1,j1;
double r,maxr;
double *x = new double[n];
double *y = new double[n];
 for(int k=0;k<n;k++){x[k]=d[k].GetX();y[k]=d[k].GetY();}
maxr=0;
for(i=0;i<n;i++)
   {
   for(j=i+1;j<n;j++)
      {
      r=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
      if(r>maxr){maxr=r;i1=i;j1=j;}
      }
   }
 CDot *dd = new CDot[2];
 //CDot dd[2];
 dd[0].SetDot(x[i1], y[i1]);//d[0].SetX(x[i1]); d[0].SetY(y[i1]);
 dd[1].SetDot(x[j1], y[j1]);//d[1].SetX(x[j1]); d[1].SetY(y[j1]);
 delete[] x; delete[] y;
return dd;
}

double sqr(double n)
{
 return n*n;
}

void BuildCircle(CDot *d, int n)
{
if(d==NULL) { cout<< "Dot array is emply!";return;}
else 
{
 if(n==1) //нулевая
 { CCircle c(0,d[0].GetX(),d[0].GetY()); cout<<c;}
 if(n==2) //по диаметру
 { 
   double r=sqrt( sqr(d[0].GetX()-d[1].GetX()) + sqr(d[0].GetY()-d[1].GetY()) );
   CCircle c(r/2, (d[0].GetX()+d[1].GetX())/2, (d[0].GetY()+d[1].GetY())/2 ); cout<<c;}
 }
 if(n>2)//по кратчайшему диаметру, или строим описанную
 {
  //findmax
  int flag=0;
  double diam=FindMax(d,n);
  CDot *dd = FindMaxD(d,n);
  CCircle c0(diam/2, (dd[0].GetX()+dd[1].GetX())/2, (dd[0].GetY()+dd[1].GetY())/2);   //BuildCircle1(dd,2);  //без рекурсии быстрее!
  delete [] dd;
  //checking
  for(int i=0;i<n;i++){if(IsInCircle(d[i],c0))flag++;}
 if(flag==n) 
  {cout<<c0;}
 else{
  double sx=0,sy=0,mx=0;
  //найдем координаты центра тяжести множества точек
  for (int i=0;i<n;i++) {  sx=sx+d[i].GetX(); sy=sy+d[i].GetY();}
  //cout <<sx<<" "<<sy<<endl;
  sx=sx/n;
  sy=sy/n;
  //cout <<sx<<" "<<sy<<endl;
  mx=(sqr(sx-d[0].GetX()) + sqr(sy-d[0].GetY()));
  //найдем наиболее удаленную точку от центра
 for (int i=1;i<n;i++) {
   if ((sqr(sx-d[i].GetX())+sqr(sy-d[i].GetY()))>mx) 
   { mx = (sqr(sx-d[i].GetX())+sqr(sy-d[i].GetY()));}
 }
 mx=sqrt(mx);
 CCircle c(mx, sx, sy); cout<<c;
 }}
}

CCircle BuildCircle1(CDot *d, int n)
{
if(d==NULL) { /*CCircle e;*/cout<< "Dot array is emply!\n";throw -1;}
else 
{
 if(n==1) //нулевая
 { CCircle c(0,d[0].GetX(),d[0].GetY()); cout<<c; return c;}
 else if(n==2) //по диаметру
 { 
   double r=sqrt( sqr(d[0].GetX()-d[1].GetX()) + sqr(d[0].GetY()-d[1].GetY()) );
   CCircle c(r/2, (d[0].GetX()+d[1].GetX())/2, (d[0].GetY()+d[1].GetY())/2 ); cout<<c; return c;}
 else //if(n>2)   //по кратчайшему диаметру, или строим описанную
 { 
 //findmax
  int flag=0;
  double diam=FindMax(d,n);
  CDot *dd = FindMaxD(d,n);
  CCircle c0(diam/2, (dd[0].GetX()+dd[1].GetX())/2, (dd[0].GetY()+dd[1].GetY())/2);   //BuildCircle1(dd,2);  //без рекурсии быстрее!
  delete [] dd;
  //checking
  for(int i=0;i<n;i++){if(IsInCircle(d[i],c0))flag++;}
 if(flag==n) 
  {cout<<c0; return c0;}
 else{
  double sx=0,sy=0,mx=0;
  //найдем координаты центра тяжести множества точек
  for (int i=0;i<n;i++) {  sx=sx+d[i].GetX(); sy=sy+d[i].GetY();}
  //cout <<sx<<" "<<sy<<endl;
  sx=sx/n;
  sy=sy/n;
  //cout <<sx<<" "<<sy<<endl;
  mx=(sqr(sx-d[0].GetX()) + sqr(sy-d[0].GetY()));
  //найдем наиболее удаленную точку от центра
 for (int i=1;i<n;i++) {
   if ((sqr(sx-d[i].GetX())+sqr(sy-d[i].GetY()))>mx) 
   { mx = (sqr(sx-d[i].GetX())+sqr(sy-d[i].GetY()));}
 }
 mx=sqrt(mx);
 CCircle c(mx, sx, sy); cout<<c;
   return c;
 }
}}
}







