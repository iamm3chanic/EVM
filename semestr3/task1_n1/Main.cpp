#include<iostream>
#include"CList.h"
#include"walloc.h"
using namespace std;
int main(){
	cout << "Ñîçäàäèì ñïèñîê èç 26 ýëåìåíòîâ" << endl;
	CList2 list1;
	const char  *q="sdad", *e="dewdew";
	list1.AddAfter(q);
	list1.AddAfter(e);
	for(CList2::iterator it=list1.begin(); it!=list1.end(); ++it){cout <<*it<< " ";} cout << endl;
	const char* m[26]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
	CList2 list;
	for(int i=0;i<26;i++){
		if(i%2==0){list.GoToEnd(); list.GoToPrev();}
		if(i%3==1){list.GoToNext();list.GoToPrev();}
		list.AddBefore(m[i]);}
	for(CList2::iterator it=list.begin(); it!=list.end(); ++it){cout <<*it<< " ";} cout << endl;
	//list.Sort();
	cout <<"=======" << endl;
	for(CList2::iterator it=list.begin(); it!=list.end(); ++it){cout <<*it<< " ";} cout << endl;
	cout << "Ïðîâåðèì åãî äëèíó" << endl;
	cout << list.GetLen() << endl;
	cout <<"=======" << endl;
	cout << "Óäàëèì 2 ýëåìåíò" << endl;
	list.DelPos(1);
	for(CList2::iterator it=list.begin(); it!=list.end(); ++it){cout <<*it<< " ";} cout << endl;
	cout <<"=======" << endl;
	cout << "Ïðîâåðèì åãî äëèíó" << endl;
	cout << list.GetLen() << endl;
	cout <<"=======" << endl;
	cout << "Äîáàâèì QQQQ íà 2 ïîçèöèþ" << endl;
	list.AddToPos("QQQQ", 1);
	for(CList2::iterator it=list.begin(); it!=list.end(); ++it){cout <<*it<< " ";} cout << endl;
	cout <<"=======" << endl;
	cout << "Äîáàâèì â êîíåö VvV" << endl;
	list.AddToEnd("VvV");
	for(CList2::iterator it=list.begin(); it!=list.end(); ++it){cout <<*it<< " ";} cout << endl;
	cout <<"=======" << endl;
	cout << "Óäàëèì ïðåäïîñëåäíèé ýëåìåíò" << endl;
	list.DelPos(25);
	for(CList2::iterator it=list.begin(); it!=list.end(); ++it){cout <<*it<< " ";} cout << endl;
	cout <<"=======" << endl;
	cout << "Îòñîðòèðóåì ñïèñîê" << endl;
	list.Sort();
	for(CList2::iterator it=list.begin(); it!=list.end(); ++it){cout <<*it<< " ";} cout << endl;
	cout <<"=======" << endl;
	cout << "Ñîçäàäèì åùå îäèí ñïèñîê ñïèñîê" << endl;
	const char* n[10]={"a","b","c","d","f","g","bb","ba","aa","ab"};
	CList2 list0;
	for(int i=0;i<10;i++){list0.AddAfter(n[i]);}
	for(CList2::iterator it=list0.begin(); it!=list0.end(); ++it){cout <<*it<< " ";} cout << endl;
	cout <<"=======" << endl;
	cout << "Îòñîðòèðóåì åãî" << endl;
	list0.Sort();
	for(CList2::iterator it=list0.begin(); it!=list0.end(); ++it){cout <<*it<< " ";} cout << endl;
	cout << "Ñîåäèíèì ñïèñêè" << endl;
	list.AddList(list0);
	for(CList2::iterator it=list.begin(); it!=list.end(); ++it){cout <<*it<< " ";} cout << endl;
	cout <<"=======" << endl;
	cout << "Îòñîðòèðóåì ïîëó÷åííûé" << endl;
	list.Sort();
	for(CList2::iterator it=list.begin(); it!=list.end(); ++it){cout <<*it<< " ";} cout << endl;
	cout << "Óäàëèì âòîðîé ñïèñîê" << endl;
	list0.Clean();
	for(CList2::iterator it=list0.begin(); it!=list0.end(); ++it){cout <<*it<< " ";} cout << endl;
	cout <<"=======" << endl;
	return 0;
}

void test(){

}
