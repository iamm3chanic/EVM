#include"CList.h"
bool CList2Node::operator<(const CList2Node &rhs) const{
	int i;
	for(i=0; v[i]!='\0' && rhs.v[i]!='\0'; i++){
		if(v[i]<rhs.v[i])
			return true;
		if(v[i]>rhs.v[i])
			return false;
	}
	if(v[i]!='\0')
		return false;
	return true;
}

void CList2::Sort(){
	int len=GetLen();
	GoToBegin();
	for(int i=0; i<len;i++){
		CList2Node *maxloc=first;
		GoToBegin();
		GoToNext();
		for(int j=1; j<len-i;j++){
			if(*maxloc<*cur)
				maxloc=cur;
			GoToNext();
		}
		//Ìîæíî îòñëåäèòü ðàáîòó àëãîðèòìà
		//cout << maxloc->v << "    ";
		//for(CList2::iterator it=begin(); it!=end(); ++it){cout <<*it<< " ";} cout << endl;
		GoToEnd();
		for(int j=0;j<i;j++)
			GoToPrev();
		const char *t=cur->v;
		cur->v=maxloc->v;
		maxloc->v=t;
	}
}
void CList2::AddToPos(const char* x, int pos){
	CList2Node* tmp=cur;
	GoToPos(pos);
	AddBefore(x);
	cur=tmp;

}

bool CList2::DelCur(){
	if(IsEmpty())
		return false;
	if(cur->prev)
		cur->prev->next=cur->next;
	else
		last=cur->next;
	if(cur->next)
		cur->next->prev=cur->prev;
	else
		first=cur->prev;
	CList2Node* r=cur;
	if(cur->prev)
		cur=cur->prev;
	else
		cur=cur->next;
	delete r;
	return true;
}

void CList2::AddAfter(const char* x){
	CList2Node *n=new CList2Node(); n->v=new char [strlen(x)+1];memcpy(const_cast<char *>(n->v),x,strlen(x)+1);
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

void CList2::AddBefore(const char* x){
	CList2Node *n=new CList2Node();  n->v=new char [strlen(x)+1];memcpy(const_cast<char *>(n->v),x,strlen(x)+1);
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
