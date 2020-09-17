/* 6. Определить классы CPoint для работы с целочисленными точка-
ми на плоскости и CDist для работы с расстоянием между точками. В
классе должны быть определены необходимые конструкторы, операто-
ры сложения (CPoint и CDist, возвращающий CPoint, а также CDist и
CPoint, возвращающий CPoint), вычитания (CPoint из CPoint, возвра-
щающий CDist).
В отдельном файле должен быть написан тест на данный класс. */
#pragma once
#include<string.h>
using namespace std;
class CDist;
//////////////////////////////////////
class Cpoint
{ int a,b;
public:
Cpoint(int a=0, int b=0) {this->a=a;this->b=b;}; //объявление пустой точки
Cpoint &operator=(const int &a){this->a=a; this->b=b; return *this;} // присваение точке 
friend ostream &operator<<(ostream &cout, Cpoint &a); //чтобы узаконить вывод
friend istream &operator>>(istream &cin, Cpoint &a); //чтобы узаконить ввод
friend Cpoint operator+(const Cpoint &a, const CDist &b); // чтобы реализовать точка+вектор=точка
friend Cpoint operator+(const CDist &b,const Cpoint &a ); // чтобы реализовать вектор+точка=точка
friend CDist operator-(const Cpoint &b,const Cpoint &a ); // чтобы реализовать точка=точка=вектор
friend ostream &operator<<(ostream &cout , Cpoint &a) ;
friend istream &operator>>(istream &cin ,Cpoint &a) ;
};
////////////////////////////////////
class CDist
{ int a,b;
public:
CDist(int a=0, int b=0) {this->a=a;this->b=b;}; //объявление пустого вектора
CDist &operator=(const int &a){this->a=a;this->b=b; return *this;} //присвоение вектору вектора
CDist operator+(const CDist &x){CDist r; r.a=a+x.a; r.b=b+x.b; return r;} // сложение вида вектор + вектор
//CDist operator+(const int &x){CDist r; r.a=x+a; r.b=b; return r;} //сложение вида вектор+число
CDist operator*(const int &x){CDist r; r.a=x*a; r.b=b*x; return r;} // умножение вида вектор*число
friend ostream &operator<<(ostream &cout, CDist &a); //чтобы узаконить вывод
friend istream &operator>>(istream &cin, CDist &a); //чтобы узаконить ввод
//friend CDist operator+(const int &a, const CDist &b); // чтобы реализовать число+ вектор
friend CDist operator*(const int &a, const CDist &b); //чтобы реализовать число*вектор
friend Cpoint operator+(const Cpoint &a, const CDist &b); // чтобы реализовать ветор+точка=точка
friend Cpoint operator+(const CDist &b,const Cpoint &a ); // чтобы реализовать вектор+точка=точка
friend CDist operator-(const Cpoint &b,const Cpoint &a ); // чтобы реализовать точка=точка=вектор
friend ostream &operator<<(ostream &cout , CDist &a) ;
friend istream &operator>>(istream &cin , CDist &a) ;

};
/////////////////////////////////////
//CDist operator+(const int &a ,const CDist &b){CDist r; r.a=b.a + a ; r.b=b.b; return r;} // реализация число+вектор
CDist operator*(const int &a ,const CDist &b){CDist r; r.a=a*b.a ; r.b=a*b.b; return r;} // реализация число*вектор
Cpoint operator+(const Cpoint &a ,const CDist &b){Cpoint r; r.a=b.a + a.a ; r.b=b.b+a.b; return r;} // реализация точка+вектор=точка
Cpoint operator+(const CDist &b,const Cpoint &a ){Cpoint r; r.a=b.a + a.a ; r.b=b.b+a.b; return r;} // реализация ветор+точка=точка
CDist operator-(const Cpoint &a ,const Cpoint &b){CDist r; r.a=a.a-b.a ; r.b=a.b-b.b; return r;} // реализация точка-точка=вектор

ostream &operator<<(ostream &cout , CDist &a) //описываем вывод
{ cout<<"("<<a.a<<","<<a.b<<")"; return cout; }
istream &operator>>(istream &cin , CDist &a) //описываем ввод
{ cin >>a.a>>a.b; return cin; }

ostream &operator<<(ostream &cout , Cpoint &a) //описываем вывод
{ cout<<"("<<a.a<<","<<a.b<<")"; return cout; }
istream &operator>>(istream &cin , Cpoint &a) //описываем ввод
{ cin >>a.a>>a.b; return cin; }
