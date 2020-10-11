#pragma once
#include<string.h>
#include<iostream>
using namespace std;

template<class T> class CList2Node{public: T v; CList2Node<T> *prev, *next; CList2Node(){prev=next=NULL;}};

template<class T> class CList2{
	CList2Node<T> *cur, *first, *last;
public:
	class iterator{
		CList2Node<T> *cur;
	public:
		iterator(){cur=NULL;}
		iterator(CList2Node<T> *cur){this->cur=cur;}
		bool operator!=(const iterator &rhs){return cur!=rhs.cur;}
		bool operator==(const iterator &rhs){return cur==rhs.cur;}
		void operator++(){if(cur)cur=cur->next;}
		void operator++(int){if(cur)cur=cur->next;}
		T operator*(){return cur->v;}
	};
		CList2(){SetZero();}
		CList2(const CList2 &rhs){SetZero();CopyOnly(rhs);}
		~CList2(){Clean();}

		void Clean(){GoToBegin(); while(DelCur()); SetZero();}
		void SetZero(){cur=first=last=NULL;}
		void CopyOnly(const CList2 &rhs){if(IsEmpty()){for(iterator it=rhs.first;it!=NULL;++it){GoToEnd();AddAfter(*it);}}}

		void GoToBegin(){cur=first;}
		void GoToEnd(){cur=last;}
		void GoToPos(int pos){if(pos<0||pos>GetLen())throw -1;GoToBegin();for(int i=0;i<pos;i++)GoToNext();}

		int GetLen(){iterator it=first;int i; for(i=0; it!=NULL; ++it) i++; return i;}
		int GetCurPos(){iterator it=first; int i=0;	while(it!=cur){++i;++it;}return i;}

		bool GoToNext(){if(IsEmpty())return false; if(cur->next==NULL) return false; cur=cur->next; return true;}
		bool GoToPrev(){if(IsEmpty())return false; if(cur->prev==NULL) return false; cur=cur->prev; return true;}

		bool IsEmpty()const{return cur==NULL;}

		void AddList(CList2 &rhs){last->next=rhs.first;last=rhs.last;}
		void AddAfter(const T&x);
		void AddBefore(const T&x);
		void AddToEnd(const T&x){CList2Node<T> *n=new CList2Node<T>(); n->v=x;n->prev=last;last->next=n;last=n;}
		void AddToPos(const T&x, int pos);

		void DelPos(int pos){CList2Node<T>* tmp=cur;GoToPos(pos);DelCur();cur=tmp;}
		bool DelCur();
		iterator begin(){return iterator(first);}
		iterator end(){return iterator(NULL);}

		void Sort();
	};

template<class T> void CList2<T>::Sort(){
	CList2Node<T>* tmp;
	cout << GetLen() << endl;
	for(int i=0; i<GetLen();i++){
		GoToBegin();
		tmp=cur;
		for(int j=0;j<GetLen()-i;j++){
			GoToNext();
			if(tmp->v<cur->v)
				tmp=cur;
		}
		cur=tmp;
		DelCur();
		AddToPos(tmp->v,GetLen()-i);
		cout << tmp->v << " ";
	}
	cout << GetLen() << endl;
}

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
class CString{
	int n; char *v;
public:
	CString(){SetZero();}
	CString(const char *rhs){CopyOnly(rhs);}
	CString(const CString &rhs){CopyOnly(rhs);}
	CString(CString &&rhs){n=rhs.n; v=rhs.v; rhs.SetZero();}
	~CString(){Clean();}

	CString &operator=(const CString &rhs){if(this!=&rhs){Clean();CopyOnly(rhs);} return *this;}
	CString &operator=(CString &&rhs){if(this!=&rhs){n=rhs.n; v=rhs.v; rhs.SetZero();} return *this;}
	CString &operator=(const char *rhs){Clean();CopyOnly(rhs); return *this;}

	void SetZero(){v=NULL; n=0;}
	void Clean(){delete[] v; SetZero();}
	void CopyOnly(const CString &b){if(this!=&b){v=new char[n=b.n]; memcpy(v,b.v,n);}}
	void CopyOnly(const char *b){v=new char[n=strlen(b)+1];strcpy(v,b);}
	operator const char*(){return v;}
};
