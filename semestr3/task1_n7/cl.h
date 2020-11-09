#pragma once
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//список L2
template<class T> class CList2Node{public: T v; CList2Node<T> *prev, *next; CList2Node(){prev=next=NULL;}};

template<class T> class CList2
{                
 CList2Node<T> *cur, *first, *last;
public:
 class iterator{
  CList2Node<T> *cur;
 public: 
  iterator(){cur=NULL;}
  iterator(CList2Node<T> *cur){this->cur=cur;}
  int operator!=(const iterator &b){return cur!=b.cur;}
  int operator==(const iterator &b){return cur==b.cur;}
  void operator++(){if(cur)cur=cur->next;}
  void operator++(int){if(cur)cur=cur->next;}
  T operator*(){return cur->v;}
 };
 CList2(){SetZero();}
 CList2(const CList2&b){CopyOnly(b);}
 ~CList2(){Clean();}
 void Clean(){GoToBegin(); while(DelCur()); SetZero();}
 void SetZero(){cur=first=last=NULL;}
 void CopyOnly(const CList2&b){T x; if(b.IsEmpty==0){b.GoToBegin();do{b.GetCur(x);GoToEnd();AddAfter(x);}while(b.GoToNext()==0);}}
 void GoToBegin(){cur=first;}
 void GoToEnd(){cur=last;}
 void AddAfter(const T&x);
 void AddBefore(const T&x);
 int GetCur(T&x){if(IsEmpty())return -1;x=cur->v;return 0;}
 int IsEmpty(){return cur==NULL;}
 int GoToNext(){if(IsEmpty())return -1; if(cur->next==NULL) return -2; cur=cur->next; return 0;}
 int GoToPrev(){if(IsEmpty())return -1; if(cur->prev==NULL) return -2; cur=cur->prev; return 0;}
 int DelCur();
 T& GetCur(){ return cur->v;}
 iterator begin(){return iterator(first);}
 iterator end(){return iterator(NULL);}	
 CList2 &operator=(const CList2&b){if(this!=&b){Clean();CopyOnly(b);}return *this;}
 friend class Mass; 
};

template<class T> void CList2<T>::AddAfter(const T &x)
{
 CList2Node<T> *n=new CList2Node<T>(); n->v=x;
 if(IsEmpty()){cur=first=last=n;}
 else
 {
  n->next=cur->next; n->prev=cur; cur->next=n;
  if(n->next) n->next->prev=n; else last=n;
 }
}

template<class T> void CList2<T>::AddBefore(const T &x)
{
 CList2Node<T> *n=new CList2Node<T>(); n->v=x;
 if(IsEmpty()){cur=first=last=n;}
 else
 {
  n->prev=cur->prev; n->next=cur; cur->prev=n;
  if(n->prev) n->prev->next=n; else first=n;
 }
}  

template<class T> int CList2<T>::DelCur()
{
 if(IsEmpty()) return -1;
 if(cur->prev) cur->prev->next=cur->next; else first=cur->next;
 if(cur->next) cur->next->prev=cur->prev; else last=cur->prev;
 if(cur->prev) cur=cur->prev; else cur=cur->next;
 return 0;
}


