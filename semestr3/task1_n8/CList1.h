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


class Arr;
class CTmpArr
{
Arr *v;int i; 
public:
CTmpArr(Arr *v,int i){this->v=v;this->i=i;} 
operator double();
CTmpArr &operator=(const double &b);
};
//==========================================
class Arr
{
private:
  int n,nreal;double *v; 
public:
  Arr(){SetZero();}
  Arr(int num) {n=num; nreal=0; v = new double[num]; memset(v,0, num*sizeof(double) );}
  Arr(const Arr&b){CopyOnly(b);}
  ~Arr(){Clean();}
  void SetN(int num) {Clean(); n=num; v = new double[num]; memset(v,0, num*sizeof(double) );}
  int GetN(){return n;}
  void InputTo(int pos, double d);
  Arr &operator=(const Arr&b){if(this!=&b){Clean();CopyOnly(b);}return *this;} 
  void Clean(){delete[] v; SetZero();} 
  void SetZero(){v=NULL;n=0;nreal=0;}
  void CopyOnly(const Arr &b);
  CTmpArr operator[](int i){CTmpArr t(this,i);return t;} 
 // double& operator[](int index) {return arr[index];}
  double* &getArr() {return v;}
  void setArr(double*array) ;
  
  friend ostream& operator<<(ostream& cout, Arr a);
  friend istream& operator>>(istream& cin, Arr& a);
  friend class CTmpArr;
};



 template<class T> class CListNode 
{
public:
CListNode<T> *next;
T v;
CListNode(){next=NULL;}
};



//==========================================
//template<class T> class CList1;
/*class CTmpList
{
CList1<Arr> *v;int i; 
public:
CTmpList(CList1<Arr> *v,int i){this->v=v;this->i=i;} 
//void Clean(){v->Clean();}
operator Arr();
CTmpList &operator=( Arr &b);
};*/
//==========================================





 template<class T> class CList1
{
CListNode<T> t,*cur; CListNode<Arr> a,*acur; 
public:

//CTmpList operator[](int i){CTmpList l(this,i);return l;} 
  
CList1(){cur=&t;}
CList1(int num){for(int i=0;i<num;i++){GoToNext();}; cur=&t;}
~CList1(){Clean();}
int IsEmpty(){return t.next==NULL;}
void Clean(){GoToBegin(); while(!IsEmpty())DelNext();}
int DelNext(){if(cur->next==NULL)return -1; CListNode<T> *save=cur->next; cur->next=cur->next->next; delete save; return 0;} 
void GoToBegin(){cur=&t;}
T& GetCur(){if(cur==&t)throw -1; return cur->v;}
//Arr& GetCur(){if(acur==&t)throw -1; return acur->v;}
void SetCur(Arr a){acur->v=a;}
int GetLength(){int r=0; GoToBegin(); for (r=0;(GoToNext()==0);r++) {}; return r;}

int GoToNext(){if(cur->next==NULL)return -1; cur=cur->next; return 0;}
void AddAfter(const T&x){CListNode<T> *p=new CListNode<T>; p->v=x; p->next=cur->next; cur->next=p; }
T& operator[](const int& i) { for (int r=0;r<i;r++) if(GoToNext()) throw -1;  return GetCur();}
//Arr& operator[](const int& i) { for (int r=0;r<i;r++) if(GoToNext()) throw -1;  return GetCur();}
void Show(){ CList1<Arr> a; for(int i=0; i<GetLength();i++) cout<<a[i]<<" ";}

template <class> friend ostream &operator<<(ostream& cout, CList1<T>& );
/*template <class> friend istream &operator>>(istream& , CList1<T>& );*/
friend istream &operator>>(istream& cin, CList1<Arr>& a);
friend class CTmpList;
};
template <class T> ostream &operator<<(ostream& cout, CList1<T>& t) {t.Show(); return cout;}
/*template <class T> istream &operator>>(istream& cin, CList1<T>& l) 
{ Arr a; 
for(int i=0; i<l.GetLength();i++) 
{cout<<"here"; cin >> a; l[i]=a;}
return cin; }*/

