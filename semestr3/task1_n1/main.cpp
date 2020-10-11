#include<iostream>
#include<exception>
#include"List.h"
using namespace std;
int main(){
	CList2<CString> List1;
	CString a1="11111", a2="22222", a3="33333", a4="2fdfs";
	List1.GoToEnd();
	List1.AddAfter(a1);
	List1.GoToEnd();
	List1.AddAfter(a2);
	List1.GoToEnd();
	List1.AddAfter(a3);
	List1.GoToBegin();
	CString b;
	for(CList2<CString>::iterator it=List1.begin(); it!=List1.end(); ++it){cout <<*it<< endl;}
	CList2<CString> List2(List1);
	for(CList2<CString>::iterator it=List2.begin(); it!=List2.end(); ++it){cout <<*it<< endl;}
	cout << List2.GetLen()<< endl;
	cout <<"-----------"<< endl;
	List2.AddList(List1);
	for(CList2<CString>::iterator it=List2.begin(); it!=List2.end(); ++it){cout <<*it<< endl;}
	cout << List2.GetLen()<< endl;
	cout <<"-----------"<< endl;
	List2.GoToBegin();
	List2.AddToEnd(a4);
	for(CList2<CString>::iterator it=List2.begin(); it!=List2.end(); ++it){cout <<*it<< endl;}
	cout << List2.GetLen()<< endl;
	cout <<"-----------"<< endl;
	List2.GoToBegin();
	cout << List2.GetCurPos()<< endl;
	List2.GoToNext();
	List2.GoToNext();
	List2.GoToNext();
	cout << List2.GetCurPos()<< endl;
	cout <<"-----------"<< endl;
	List2.AddToPos(a4,1);
	for(CList2<CString>::iterator it=List2.begin(); it!=List2.end(); ++it){cout <<*it<< endl;}
	cout <<"-----------"<< endl;
	List2.DelPos(1);
	for(CList2<CString>::iterator it=List2.begin(); it!=List2.end(); ++it){cout <<*it<< endl;}
	cout <<"-----------"<< endl;
	List2.GoToBegin();
	List2.GoToNext();
	List2.GoToNext();
	cout << List2.GetCurPos()<< endl;
	List2.AddToPos(a4, 5);
	cout << List2.GetCurPos()<< endl;
	cout <<"-----------"<< endl;
	for(CList2<CString>::iterator it=List2.begin(); it!=List2.end(); ++it){cout <<*it<< endl;}
	cout <<"-----------"<< endl;
	List2.Sort();
	for(CList2<CString>::iterator it=List2.begin(); it!=List2.end(); ++it){cout <<*it<< endl;}
	return 0;
}
