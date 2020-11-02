#include<iostream>
#include<fstream>
#include"CTree.h"
//#include"walloc.h"
using namespace std;
int main(){
	if(0){// Constructor and destructor check
		cout<<"\ntest1\n";
		CTree<int> l;
		l.Add("d", 4);
		l.Add("b", 2);
		l.Add("c", 3);
		l.Add("a", 1);

	}
	if(1){// Simple check
		cout<<"\ntest2\n";
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
	if(0){// Add check
		cout<<"\ntest3\n";
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
	if(0){// CNode operators < * check
		cout<<"\ntest4\n";
		CTree<int>::CNode a("c"),b("b");
		if(*a<*b)
			cout << "<";
		else
			cout << "!!";
		if(a<b)
			cout << "<";
		else
			cout << "!!";
	}
	if(0){// Next check
		cout<<"\ntest5\n";
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
	if(0){// iterator test
		cout<<"\ntest6\n";
		CTree<int> l;
		l.Add("d", 4); l.Add("b", 2); l.Add("a", 1); l.Add("c", 3);
		for(auto it=l.begin(); it!=l.end(); ++it){
			cout << *it << " ";
		}
		cout << endl;
	}
	if(1){// Find check
		cout<<"\ntest7\n";
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
		//for files
	}
	if(0){// Delete check
		cout<<"\ntest8\n";
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
		cout<<"\ntest9\n";
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
		cout<<"\ntest10\n";
		CTree<int> l;
		l.Add("d", 4); l.Add("b", 2); l.Add("a", 1); l.Add("c", 3);
		cout << l.GetLen() << endl;
	}
	if(1){// Merging check
		cout<<"\ntest11\n";
		CTree<int> l;
		l.Add("d", 4); l.Add("b", 2); l.Add("a", 1); l.Add("c", 3);
		CTree<int> q;
		q.Add("x", 24); q.Add("y", 25); q.Add("z", 26);
		CTree<int>::CNode n("g",10,NULL);
		for(auto it=q.begin(); it!=q.end(); ++it){
			cout << *it << " ";
		}
		cout << endl;

		q.MergingTree(l, n);

		for(auto it=q.begin(); it!=q.end(); ++it){
			cout << *it << " ";
		}
		cout << endl;
	}
	return 0;
}
