#pragma once
using namespace std;
/*
L2 список
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

		//void Sort();
	};


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

