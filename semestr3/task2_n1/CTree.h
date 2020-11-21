#pragma once
#include<iostream>
#include<cstring>
using namespace std;

template<class T> class CTree{
public:
	class CNode{
		void Clean(){delete [] key; SetZero();}
		void SetZero(){par=left=right=NULL;}
	public:
		CNode *par, *left, *right;
		T v;
		const char *key;
		CNode(){SetZero();}
		CNode(const char *key, const T &v, typename CTree::CNode *par){this->key=new char[strlen(key)+1];memcpy(const_cast<char*>(this->key),key, strlen(key)+1); this->par=par; this->v=v; left=right=NULL;}
		CNode(const char *key){this->key=new char[strlen(key)+1];memcpy(const_cast<char*>(this->key),key, strlen(key)+1); SetZero();}
		~CNode(){Clean();}
		T &GetV(){return v;}
		const char* &GetKey(){return key;}
		bool operator<(const CNode &rhs)const;
		bool operator>(const CNode &rhs)const;
		bool operator==(const CNode &rhs)const;
		friend class CTree<T>;
		void Merging(typename CTree::CNode *v, typename CTree::CNode *rhs);
		void Merging2(typename CTree::CNode *v, typename CTree::CNode *rhs);
	};
	class iterator{
		typename CTree<T>::CNode *n; CTree<T> *t;
	public:

		iterator(typename CTree<T>::CNode *n, CTree<T> *t){this->n=n; this->t=t;}
		iterator(const iterator &b){this->n=b.n; this->t=b.t;}
		const T &operator*(){return n->v;}
		void operator++(){n=t->Next(n);}
		void operator++(int){n=t->Next(n);}
		bool operator==(const iterator &rhs){return n==rhs.n;}
		bool operator!=(const iterator &rhs){return n!=rhs.n;}
		friend class CTree<T>;
	};

	iterator begin(){return iterator(FindMin(),this);}
	iterator end(){return iterator(NULL,this);}

private:
	CNode *root; size_t len;
public:
	CTree(){root=NULL; len=0;}
	CTree(CTree &rhs, typename CTree<T>::CNode *v);
	~CTree(){Clean();}
	void Clean(){while(!Delete(root)); len=0;}

	bool IsEmpty(){return root==NULL;};
	bool IsLeft(typename CTree<T>::CNode *rhs){if(rhs!=NULL && rhs->par!=NULL && rhs->par->left==rhs)return true; return false;}
	bool IsRight(typename CTree<T>::CNode *rhs){if(rhs!=NULL && rhs->par!=NULL && rhs->par->right==rhs)return true; return false;}

	bool Delete(const char * rhs){typename CTree<T>::CNode *n=Find(rhs); if(n==NULL) return true; return Delete(n);}
	bool Delete(typename CTree<T>::CNode *rhs);
	bool Add(const char *key, const T &v);

	size_t GetLen(){return len;}

	void MergingTree(CTree &rhs);
	void MergingTree(CTree &rhs, typename CTree<T>::CNode *v);

	typename CTree<T>::CNode *Find(const char* rhs);
	typename CTree<T>::CNode *GetRoot(){return root;}
	typename CTree<T>::CNode *FindMin(){return FindMin(root);}
	typename CTree<T>::CNode *FindMax(){return FindMax(root);}
	typename CTree<T>::CNode *FindMin(typename CTree<T>::CNode *rhs);
	typename CTree<T>::CNode *FindMax(typename CTree<T>::CNode *rhs);

	typename CTree<T>::CNode *Next(typename CTree<T>::CNode *rhs);

};

template<class T> bool CTree<T>::CNode::operator<(const CNode &rhs)const{
	int i;
	for(i=0; key[i]!='\0' && rhs.key[i]!='\0'; i++){
		if(key[i]<rhs.key[i])
			return true;
		if(key[i]>rhs.key[i])
			return false;
	}
	if(key[i]!='\0')
		return false;
	return true;
}
template<class T> bool CTree<T>::CNode::operator>(const CNode &rhs)const{
	int i;
	for(i=0; key[i]!='\0' && rhs.key[i]!='\0'; i++){
		if(key[i]>rhs.key[i])
			return true;
		if(key[i]<rhs.key[i])
			return false;
	}
	if(key[i]!='\0')
		return true;
	return false;
}
template<class T> bool CTree<T>::CNode::operator==(const CNode &rhs)const{
	int i;
	for(i=0; key[i]!='\0' && rhs.key[i]!='\0'; i++){
		if(key[i]!=rhs.key[i])
			return false;
	}
	if(key[i]!='\0' || rhs.key[i]!='\0')
		return false;
	return true;
}

template<class T> void CTree<T>::CNode::Merging(typename CTree::CNode *v, typename CTree::CNode *rhs){
	if(par!=NULL){
		if(par->left!=NULL && par->left==rhs)
			par->left=NULL;
		else if(par->right!=NULL && par->right==rhs)
			par->right=NULL;
	}
	par=v;
	v->left=this;
	if(rhs!=NULL){
		if(rhs->par!=NULL){
			if(rhs->par->left!=NULL && rhs->par->left==rhs)
				rhs->par->left=NULL;
			else if(rhs->par->right!=NULL && rhs->par->right==rhs)
				rhs->par->right=NULL;
		}
		rhs->par=v;
		v->right=rhs;
	}
	else{
		v->right=NULL;
	}
}
template<class T> void CTree<T>::CNode::Merging2(typename CTree::CNode *v, typename CTree::CNode *rhs){
	if(par!=NULL){
		if(par->left!=NULL && par->left==rhs)
			par->left=NULL;
		else if(par->right!=NULL && par->right==rhs)
			par->right=NULL;
	}
	par=v;
	v->right=this;
	if(rhs!=NULL){
		if(rhs!=NULL && rhs->par!=NULL){
			if(rhs->par->left!=NULL && rhs->par->left==rhs)
				rhs->par->left=NULL;
			else if(rhs->par->right!=NULL && rhs->par->right==rhs)
				rhs->par->right=NULL;
		}
		rhs->par=v;
		v->left=rhs;
	}
	else{
		v->left=NULL;
	}
}
template<class T> CTree<T>::CTree(CTree &rhs, typename CTree<T>::CNode *v){
	root=NULL,
	len=0; rhs.len=0;
	CTree<int>::CNode *tmp=rhs.Find(v->GetKey()), *tmp1;
	if(tmp->par!=NULL){
		if(IsRight(tmp)){
			if(tmp->left!=NULL){
				tmp->left->Merging2(tmp->par,tmp->par->left);
				root=tmp->par;
			}
			else{
				root=tmp->par;
				tmp->par->right=NULL;
			}
			if(tmp->right!=NULL){
				rhs.root=tmp->right;
				rhs.root->par=NULL;
			}
			else
				rhs.root=NULL;
		}
		if(IsLeft(tmp)){
			if(tmp->right!=NULL){
				tmp->right->Merging(tmp->par,tmp->par->right);
				rhs.root=tmp->par;
			}
			else{
				rhs.root=tmp->par;
				tmp->par->left=NULL;
			}
			if(tmp->left!=NULL){
				root=tmp->left;
				root->par=NULL;
			}
			else
				root=NULL;
		}
		//delete [] tmp->key;
		//rhs.Delete(tmp);
		tmp1=tmp->par;
		delete tmp;
		for(;tmp1->par!=NULL;tmp1=tmp1->par){
			if(IsLeft(tmp1)){
				if(rhs.root==NULL) {
					if(tmp1->right!=NULL)
						rhs.root=tmp1->right;
					else
						rhs.root=tmp1->par;
				}
				else if(rhs.root==tmp1) rhs.root=tmp1->par;
				else{
					rhs.root->Merging(tmp1->par, tmp1->par->right);
					rhs.root=tmp1->par;
				}
			}
			if(IsRight(tmp1)){
				if(root==NULL) {
					if(tmp1->left!=NULL)
						root=tmp1->left;
					else
						root=tmp1->par;
				}
				else if(root==tmp1) root=tmp1->par;

				else{
					root->Merging2(tmp1->par, tmp1->par->left);
					root=tmp1->par;
				}
			}
		}
		if(rhs.root==NULL){
			rhs.root=tmp1->par;
		}
	}

	else{
		root=rhs.root->left;
		rhs.root=rhs.root->right;
		root->par=NULL;
		rhs.root->par=NULL;
		delete tmp;
	}
	for(auto it=begin(); it!=end(); ++it){len++;}
	for(auto it=rhs.begin(); it!=rhs.end(); ++it){rhs.len++;}
}

template<class T> bool CTree<T>::Delete(typename CTree<T>::CNode *rhs){
	if(root==NULL) return true;
	len--;
	if(rhs->left==NULL && rhs->right==NULL){
		if(rhs->par==NULL){
			root=NULL;
		}
		else {
			if(IsLeft(rhs))
				rhs->par->left=NULL;
			else
				rhs->par->right=NULL;
		}
		delete rhs; return false;
	}
	if(rhs->left!=NULL && rhs->right==NULL){
		if(rhs->par==NULL){
			root=rhs->left;
			root->par=NULL;
		}
		else {
			if(IsLeft(rhs)){
				rhs->par->left=rhs->left;
			}
			else {
				rhs->par->right=rhs->left;
			}
			rhs->left->par=rhs->par;
		}
		delete rhs; return false;
	}
	if(rhs->left==NULL && rhs->right!=NULL){
		if(rhs->par==NULL){root=rhs->right; root->par=NULL;}
		else {
			if(IsLeft(rhs)){
				rhs->par->left=rhs->right;
			}
			else {
				rhs->par->right=rhs->right;
			}
			rhs->right->par=rhs->par;
		}
		delete rhs; return false;
	}
	typename CTree<T>::CNode *right_min=FindMin(rhs->right);
	delete [] rhs->key;
	rhs->key=new char[strlen(right_min->key)+1];memcpy(const_cast<char*>(rhs->key),right_min->key, strlen(right_min->key)+1);
	rhs->v=right_min->v; Delete(right_min);
	return false;
}

template<class T> bool CTree<T>::Add(const char *key, const T &v){
	len++;
	if(root==NULL){root = new typename CTree<T>::CNode(key,v,NULL); return true;}
	typename CTree<T>::CNode *n, str(key);
	for(n=root;n!=NULL;){
		typename CTree<T>::CNode tmp(n->GetKey());
		if(tmp==str) return false;
		else if(str<tmp){if(n->left==NULL){n->left = new typename CTree<T>::CNode(key,v,n); return true;} else n=n->left;}
		else {if(n->right==NULL){n->right = new typename CTree<T>::CNode(key,v,n); return true;} else n=n->right;}
	}
	return true;
}

template<class T> void CTree<T>::MergingTree(CTree &rhs, typename CTree<T>::CNode *v){
	len=len+rhs.len;
	rhs.len=0;
	root->Merging(v, rhs.root);
	root=v;
	rhs.root=NULL;
}
template<class T> void CTree<T>::MergingTree(CTree &rhs){
	len=len+rhs.len;
	rhs.len=0;
	CTree<int>::CNode *tmp=rhs.FindMin();
	CTree<int>::CNode *v = new typename CTree<T>::CNode(tmp->GetKey(),tmp->GetV(),NULL);
	rhs.Delete(tmp);
	root->Merging(v, rhs.root);
	root=v;
	rhs.root=NULL;

}

template<class T> typename CTree<T>::CNode *CTree<T>::Find(const char* rhs){
	if(root==NULL) return NULL;
	typename CTree<T>::CNode *n, str(rhs);
	for(n=root;n!=NULL;){
		typename CTree<T>::CNode tmp(n->GetKey());
		if(tmp==str) return n;
		if(str<tmp) n=n->left;
		else n=n->right;
	}
	return NULL;
}
template<class T> typename CTree<T>::CNode *CTree<T>::FindMax(typename CTree<T>::CNode *root){
	if(root==NULL) return NULL;
	while(root->right!=NULL) root=root->right;
	return root;
}
template<class T> typename CTree<T>::CNode *CTree<T>::FindMin(typename CTree<T>::CNode *root){
	if(root==NULL) return NULL;
	while(root->left!=NULL) root=root->left;
	return root;
}
template<class T> typename CTree<T>::CNode *CTree<T>::Next(typename CTree<T>::CNode *n){
	if(n==NULL)return NULL;
	if(n->right!=NULL) return FindMin(n->right);
	for(;n->par!=NULL;n=n->par){
		if(IsLeft(n))
			return n->par;
	}
	return NULL;
}
