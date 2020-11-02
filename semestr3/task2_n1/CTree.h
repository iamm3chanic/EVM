#pragma once
#include<iostream>
#include<cstring>
//#include"walloc.h"
using namespace std;

template<class T> class CTree{
public:
	class CNode{
		void Clean(){if(key!=NULL)delete [] key; SetZero();}
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
		CNode* operator*(){return this;}
		friend class CTree<T>;
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
	~CTree(){Clean();}

	void Clean(){while(!Delete(root)); len=0;}

	bool IsEmpty(){return root==NULL;};
	bool IsLeft(typename CTree<T>::CNode *rhs){if(rhs!=NULL && rhs->par!=NULL && rhs->par->left==rhs)return true; return false;}

	bool Delete(const char * rhs){typename CTree<T>::CNode *n=Find(rhs); if(n==NULL) return true; return Delete(n);}
	bool Delete(typename CTree<T>::CNode *rhs);
	bool Add(const char *key, const T &v);

	size_t GetLen(){return len;}

	void MergingTree(const CTree &rhs, typename CTree<T>::CNode v);

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

template<class T> bool CTree<T>::Delete(typename CTree<T>::CNode *rhs){
	if(root==NULL) return true;
	len--;
	if(rhs->left==NULL && rhs->right==NULL){
		if(rhs->par==NULL){root=NULL;}
		else {if(IsLeft(rhs)) rhs->par->left=NULL; else rhs->par->right=NULL;}
		if(rhs){delete rhs;} return false;
	}
	if(rhs->left!=NULL && rhs->right==NULL){
		if(rhs->par==NULL){root=rhs->left; root->par=NULL;}
		else {if(IsLeft(rhs)){rhs->par->left=rhs->left;} else {rhs->par->right=rhs->left;} 
		rhs->left->par=rhs->par;}
		if(rhs){delete rhs;} return false;
	}
	if(rhs->left==NULL && rhs->right!=NULL){
		if(rhs->par==NULL){root=rhs->right; root->par=NULL;}
		else {if(IsLeft(rhs)){rhs->par->left=rhs->right;} else {rhs->par->right=rhs->right;} 
		/*if(rhs->left->par!=NULL)*/{rhs->right->par=rhs->par;}}
		if(rhs){delete rhs;} return false;
	}
	typename CTree<T>::CNode *right_min=FindMin(rhs->right);
	if(rhs->key){delete [] rhs->key;}
	rhs->key=new char[strlen(right_min->key)+1];memcpy(const_cast<char*>(rhs->key),right_min->key, strlen(right_min->key)+1);
	//rhs->key=right_min->key;
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

template<class T> void CTree<T>::MergingTree(const CTree &rhs, typename CTree<T>::CNode v){// t1 < v < t2 t2 ishodnoe
	Add(v.GetKey(),v.GetV());
	typename CTree<T>::CNode *n;
	n=FindMin();
	n->left=rhs.root->left;
	n->right=rhs.root->right;
	n->left->par=n;
	//n->right->par=n;
	rhs.root->left=NULL;
	rhs.root->right=NULL;
	 
	//Add(v.GetKey(),v.GetV());
	//Add(rhs.root->GetKey(),rhs.root->GetV());
	/*typename CTree<T>::CNode *n;
	n=FindMin();
	n->left=rhs.root->left;
	n->right=rhs.root->right;*/
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










