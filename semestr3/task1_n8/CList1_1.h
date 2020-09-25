#pragma once

using namespace std;
/*  L1 -список с текущим элементом
1.	Создать
2.	Уничтожить
3.	Очистить
4.	Пуст ли?

5.	Встать в начало (встать на фиктивный элемент)
6.	Получить значение текущего элемента
7.	Перейти к следующему элементу
8.	Уничтожить следующий элемент списка
9.	Вставить элемент после текущего

Реализация с фиктивным элементом Fict -> V0 -> VI ->... -> Vn
*/
class Arr
{
private:
  double arr[5];
public:
  double& operator[](int index) {return arr[index];}
  void setArr(double* array)  { //edit
  int i;
            for (i=0;i<5;i++)
            {arr[1]=array[1];}
            //???????
            }
  friend ostream& operator<<(ostream& cout, Arr& a);
  friend istream& operator>>(istream& cin, Arr& a);
};

 template<class T> class CListNode 
{
public:
CListNode<T> *next;
T v;
CListNode(){next=NULL;}
};
//==========================================
 template<class T> class CList1
{
CListNode<T> t,*cur; CListNode<Arr> a,*acur;
public:
CList1(){cur=&t;}
~CList1(){Clean();}
int IsEmpty(){return t.next==NULL;}
void Clean(){GoToBegin(); while(!IsEmpty())DelNext();}
int DelNext(){if(cur->next==NULL)return -1; CListNode<T> *save=cur->next; cur->next=cur->next->next; delete save; return 0;} 
void GoToBegin(){cur=&t;}
//T& GetCur(){if(cur==&t)throw -1; return cur->v;}
Arr& GetCur(){if(acur==&t)throw -1; return acur->v;}
int GetLength(){int r=0; GoToBegin(); for (r=0;(GoToNext()==0);r++) {}; return r;}
//T &x=value;
int GoToNext(){if(cur->next==NULL)return -1; cur=cur->next; return 0;}
void AddAfter(const T&x){CListNode<T> *p=new CListNode<T>; p->v=x; p->next=cur->next; cur->next=p; }
/*T& operator[](const int& i) { for (int r=0;r<i;r++) if(GoToNext()) throw -1;  return GetCur();}*/
Arr& operator[](const int& i) { for (int r=0;r<i;r++) if(GoToNext()) throw -1;  return GetCur();}
void Show(){ CList1<Arr> a; for(int i=0; i<GetLength();i++) cout<<a[i]<<" ";}

template <class> friend ostream &operator<<(ostream& cout, CList1<T>& );
template <class> friend istream &operator>>(istream& /*&cin*/, CList1<T>& );

};
template <class T> ostream &operator<<(ostream& cout, CList1<T>& t) {t.Show(); return cout;}
template <class T> istream &operator>>(istream& cin, CList1<T>& t) { return cin; }
