#include<iostream>
#include"CTree.h"
using namespace std;
int main(){
	if(1){// Constructor and destructor check
		CTree<int> l;
		l.Add("d", 4);
		l.Add("b", 2);
		l.Add("c", 3);
		l.Add("a", 1);

	}
	if(1){// Simple check
		CTree<int> l;
		l.Add("d", 4);
		CTree<int>::CNode *n;
		n=l.FindMax();
		cout << n->GetV() << endl;
		l.Add("b", 2);
		n=l.FindMin();
		cout << n->GetV() << endl;
		l.Add("a", 1);
		n=l.FindMin();
		cout << n->GetV() << endl;
		l.Add("c", 3);
		n=l.FindMin();
		cout << n->GetV() << endl;

	}
	if(1){// Add check
		CTree<int> l;
		l.Add("d", 4); l.Add("b", 2); l.Add("a", 1); l.Add("c", 3); CTree<int>::CNode *n;
		n=l.GetRoot();
		cout << n->GetV() << endl;
		n=n->left;
		cout << n->GetV() << endl;
		n=n->left;
		cout << n->GetV() << endl;
		n=l.GetRoot();
		n=n->left;
		n=n->right;
		cout << n->GetV() << endl;
	}
	if(1){// CNode operators < * check
		CTree<int>::CNode a("c"),b("b");
		if(a<b)
			cout << "<";
		else
			cout << "!!";
		if(a<b)
			cout << "<";
		else
			cout << "!!";
	}
	if(1){// Next check
		CTree<int> l;
		l.Add("d", 4); l.Add("b", 2); l.Add("a", 1); l.Add("c", 3); CTree<int>::CNode *n;
		n=l.FindMin();
		cout << n->GetV() << endl;
		n=l.Next(n);
		if(n==NULL){
			cout << "NULL" << endl;
		}
		else
			cout << n->GetV() << endl;
	}
	if(1){// iterator test
		CTree<int> l;
		l.Add("d", 4); l.Add("b", 2); l.Add("a", 1); l.Add("c", 3);
		for(auto it=l.begin(); it!=l.end(); ++it){
			cout << *it << " ";
		}
		cout << endl;
	}
	if(1){// Find check
		CTree<int> l;
		l.Add("d", 4); l.Add("b", 2); l.Add("a", 1); l.Add("c", 3); CTree<int>::CNode *n;
		n=l.Find("a");
		cout << n->GetV() << endl;
		n=l.Find("b");
		cout << n->GetV() << endl;
		n=l.Find("c");
		cout << n->GetV() << endl;
		n=l.Find("d");
		cout << n->GetV() << endl;
	}
	if(1){// Delete check
		CTree<int> l;
		l.Add("d", 4); l.Add("b", 2); l.Add("a", 1); l.Add("c", 3); CTree<int>::CNode *n;
		for(auto it=l.begin(); it!=l.end(); ++it){
			cout << *it << " ";
		}
		cout << endl;
		cout << l.GetLen() << endl;
		n=l.FindMin();
		l.Delete(n);
		for(auto it=l.begin(); it!=l.end(); ++it){
			cout << *it << " ";
		}
		cout << endl;
		cout << l.GetLen() << endl;
	}
	if(1){//Find Delete check
		CTree<int> l;
		l.Add("d", 4); l.Add("b", 2); l.Add("a", 1); l.Add("c", 3);
		for(auto it=l.begin(); it!=l.end(); ++it){
			cout << *it << " ";
		}
		cout << endl;
		cout << l.GetLen() << endl;
		l.Delete("a");
		for(auto it=l.begin(); it!=l.end(); ++it){
			cout << *it << " ";
		}
		cout << endl;
		cout << l.GetLen() << endl;
	}
	if(1){// Length check
		CTree<int> l;
		l.Add("d", 4); l.Add("b", 2); l.Add("a", 1); l.Add("c", 3);
		cout << l.GetLen() << endl;
	}
	if(1){// Delete check
		CTree<int> q;
		q.Add("g", 10);
		q.Add("w", 23);q.Add("x", 24); q.Add("y", 25); q.Add("z", 26);
		q.Add("d", 4); q.Add("b", 2); q.Add("a", 1); q.Add("c", 3);
	}
	if(1){// Merging check 1

		CTree<int> q;
		q.Add("w", 23);q.Add("x", 24); q.Add("y", 25); q.Add("z", 26);
		CTree<int> l;
		l.Add("d", 4); l.Add("b", 2); l.Add("a", 1); l.Add("c", 3);
		CTree<int>::CNode* n=new typename CTree<int>::CNode("g",10,NULL);
		for(auto it=l.begin(); it!=l.end(); ++it){
			cout << *it << " ";
		}
		cout << endl;
		for(auto it=q.begin(); it!=q.end(); ++it){
			cout << *it << " ";
		}
		cout << endl;

		cout << "MergingTree"<< endl;

		l.MergingTree(q,n);

		for(auto it=l.begin(); it!=l.end(); ++it){
			cout << *it << " ";
		}
		cout << endl;
		for(auto it=q.begin(); it!=q.end(); ++it){
			cout << *it << " ";
		}
		cout << endl;
	}
	if(1){// Merging check 2

		CTree<int> q;
		q.Add("w", 23);q.Add("x", 24); q.Add("y", 25); q.Add("z", 26);
		CTree<int> l;
		l.Add("d", 4); l.Add("b", 2); l.Add("a", 1); l.Add("c", 3);
		for(auto it=l.begin(); it!=l.end(); ++it){
			cout << *it << " ";
		}
		cout << endl;
		for(auto it=q.begin(); it!=q.end(); ++it){
			cout << *it << " ";
		}
		cout << endl;

		cout << "MergingTree"<< endl;

		l.MergingTree(q);

		for(auto it=l.begin(); it!=l.end(); ++it){
			cout << *it << " ";
		}
		cout << endl;
		for(auto it=q.begin(); it!=q.end(); ++it){
			cout << *it << " ";
		}
		cout << endl;
	}
	if(1){// Spliting check
		CTree<int> q;
		q.Add("g",10);
		q.Add("w", 23);q.Add("x", 24); q.Add("y", 25); q.Add("z", 26);
		q.Add("d", 4); q.Add("b", 2); q.Add("a", 1); q.Add("c", 3);

		for(auto it=q.begin(); it!=q.end(); ++it){
			cout << *it << " ";
		}
		cout << endl;
		CTree<int>::CNode* n=new typename CTree<int>::CNode("b",2,NULL);

		CTree<int> s(q,n);
		for(auto it=s.begin(); it!=s.end(); ++it){
			cout << *it << " ";
		}
		cout << endl;
		for(auto it=q.begin(); it!=q.end(); ++it){
			cout << *it << " ";
		}
		cout << endl;
		delete n;
	}
	return 0;
}
