/*
 * CList2.h
 * L2 список и класс CToken
 *
 * Author: iamm3chanic
*/
#pragma once
using namespace std;
/////////////////////////////
class CToken;
class CTmpCToken
{
CToken *v;int i; 
public:
CTmpCToken(CToken *v,int i){this->v=v;this->i=i;} 
operator char();
CTmpCToken &operator=(/*const*/ char b);
};
//==========================================
class CToken
{
private:
  int size, pos,k_size;
  char *key;
  char *s; //value
public:
  CToken(){SetZero();}
  CToken(int num) {size=num; pos=0; k_size=0; s = new char[num]; memset(s,0, num*sizeof(char) );}
  CToken(const CToken&b){CopyOnly(b);}
  ~CToken(){Clean();}
  void SetN(int num) {delete[] s; s=NULL; size=num; s = new char[num]; memset(s,0, num*sizeof(char) );}
  int GetN(){return size;}
  int GetKs(){return k_size;}
  int GetPos(){return pos;}
  void InputTo(int where, char d);
  CToken &operator=(const CToken&b){if(this!=&b){Clean();CopyOnly(b);}return *this;} 
  
  void Clean(){delete[] s; delete[]key; SetZero();}
  void SetZero(){s=NULL;key=NULL;size=0;pos=0;k_size=0;}
  void CopyOnly(const CToken&o){/*pos=o.pos;*/size=o.size;s=new char[size];memcpy(s,o.s,size);k_size=o.k_size;key=new char[k_size];memcpy(key,o.key,k_size);}
  
  void SetKs(int m){delete[] key; key=NULL; k_size=m; key=new char[m]; memset(key,0, m*sizeof(char) );}
  void SetP(int p){pos=p;}
  void SetK(char* str){if(key!=NULL){delete[]key;} key= new char[k_size]; strncpy(key,str,k_size);}
  void SetS(char* str){if(s!=NULL){delete[]s;} s= new char[size]; strncpy(s,str,size);}
 operator const char*()const{return s;} 
  CToken(const char*o){size=strlen(o);s=new char[size];memcpy(s,o,size);} 
  void print()const {for (int i=0;i<size;i++) printf("%c",s[i]);} 
  char *GetS(){return s;}
  char *GetK(){return key;}
  CTmpCToken operator[](int i){if (i<0){throw -1;} return CTmpCToken(this,i);} 
 
 friend ostream &operator<<(ostream &cout, CToken &a); 
 friend istream &operator>>(istream &cin, CToken &a);
 friend class CTmpCToken; 
};



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
                T& GetCur(){/*if(cur==&cur)throw -1;*/ return cur->v;}
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
		
		CList2 &operator=(const CList2&b){if(this!=&b){Clean();CopyOnly(b);}return *this;} 

	};

//global variables needed
extern char **blocks ;
extern int BLOCK_FLAG;
extern CToken* tok_global;
extern int T_FLAG;
