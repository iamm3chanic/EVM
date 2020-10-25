#pragma once
#include<iostream>
#include<cstring>

class CList2Node{
	void Clean(){delete [] v;SetZero();}
	void SetZero(){prev=next=NULL;v=NULL;}

public:
	const char *v; CList2Node *prev, *next;
	CList2Node(){SetZero();}
	CList2Node(const char *rhs){v=new char[strlen(rhs)+1]; memcpy(const_cast<char*>(v),rhs,strlen(rhs)+1);prev=next=NULL;}
	~CList2Node(){Clean();}
	bool operator<(const CList2Node &rhs)const;
};

class CList2{
	CList2Node *cur, *first, *last;
public:
	class iterator{
		CList2Node *cur;
	public:
		iterator(){cur=NULL;}
		iterator(CList2Node *cur){this->cur=cur;}
		bool operator!=(const iterator &rhs){return cur!=rhs.cur;}
		bool operator==(const iterator &rhs){return cur==rhs.cur;}
		CList2Node* operator++(){if(cur){return cur=cur->next;}throw -3;}
		CList2Node* operator++(int){if(cur){CList2Node *r=cur;cur=cur->next;return r;}throw -3;}
		const char* operator*(){return cur->v;}
	};
	iterator begin(){return iterator(first);}
	iterator end(){return iterator(NULL);}

	CList2(){SetZero();}
	CList2(const CList2 &rhs){SetZero();CopyOnly(rhs);}
	~CList2(){Clean();}

	CList2 &operator=(const CList2&b){if(this!=&b){Clean();CopyOnly(b);}return *this;}

	void Clean(){GoToBegin(); while(DelCur()); SetZero();}
	void SetZero(){cur=first=last=NULL;}
	void CopyOnly(const CList2 &rhs){if(!rhs.IsEmpty()){for(iterator it=rhs.first;it!=NULL;++it){GoToEnd();AddAfter(*it);}GoToEnd();}}
	void GoToBegin(){cur=first;}
	void GoToEnd(){cur=last;}
	void GoToPos(int pos){if(pos<0||pos>GetLen())throw -1;GoToBegin();for(int i=0;i<pos;i++)GoToNext();}
	bool GoToNext(){if(IsEmpty())return false; if(cur->next==NULL) return false; cur=cur->next; return true;}
	bool GoToPrev(){if(IsEmpty())return false; if(cur->prev==NULL) return false; cur=cur->prev; return true;}

	int GetLen(){iterator it=first;int i; for(i=0; it!=NULL; ++it) i++; return i;}
	int GetCurPos(){iterator it=first; int i=0;	while(it!=cur){++i;++it;}return i;}

	bool IsEmpty()const{return cur==NULL;}

	void AddList(const CList2 &rhs){CopyOnly(rhs);}
	void AddAfter(const char* x);
	void AddBefore(const char* x);
	void AddToEnd(const char* x){CList2Node *n=new CList2Node(); n->v=x;n->prev=last;last->next=n;last=n;}
	void AddToPos(const char* x, int pos);

	void DelPos(int pos){CList2Node* tmp=cur;GoToPos(pos);DelCur();cur=tmp;}
	bool DelCur();

	void Sort();
	};
