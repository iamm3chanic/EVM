/*
 * Main.cpp
 */
#include <iostream>
#include "CIntN.h"

using namespace std;

void parallel_test();

int main()
{
 parallel_test();
 return 0;
}

void parallel_test()
 {
 try {
   cout << "parallel test\n";
   CIntN::OMPTest("input.txt");   
  } catch(...) {cout << "error\n" <<endl;} 
 }
void test0()
 {
try {
   cout << "test0. Input + output\n";
vector<CFabricIntN*> fabric;
vector<CIntN*> v;
   fabric.push_back(new CFabricIntN0);
   fabric.push_back(new CFabricIntN1);
   CIntN::Input("input.txt", v, fabric);
   cout<<"global Number = "<<v.size()<<endl;
   for(size_t i=0;(i<v.size());++i)  
   {
   //v[i]->ShowIntN();
   v[i]->output();
   }
    for(size_t i=0;(i<v.size());i++)  
   {
   delete v[i]; //delete fabric[i];
   }
   //delete &f0; delete &f1;
    for(size_t i=0;(i<fabric.size());i++)  {delete fabric[i];}
  } catch(int err) {cout << "error=" <<err<<endl;} 
 }
 
 void test1()
 { 
  try {
  cout << "test1. create vectors\n";
    int n;
    n=3;
    CIntN0 v1=CIntN0(n);
    CIntN0 v2=CIntN0(n);
    CIntN1 v3=CIntN1(n);
    CIntN1 v4=CIntN1(n);
    
    cout<< "SUCCESS\n";
  
    } catch(int err) {cout << "error=" <<err<<endl;}
  }  
 
 void test2()
 {
    try {
  cout << "test2. CIntN0 and file\n";
    int i; char c[15]="out_test.txt";
    CIntN0 v1=CIntN0(3);
    v1.setPos(0,11); v1.setPos(1,22); v1.setPos(2,33);
    v1.setText(c);
    CIntN1 v2=CIntN1(3);
    v2.setPos(0,1111); v2.setPos(1,2222); v2.setPos(2,3333);
    v2.setText(c);
    i = v1.output();
    if(i==0){cout<< "SUCCESS-0\n";}
    i = v2.output();
    if(i==0){cout<< "SUCCESS-1\n";}
    else cout<< "Some error...\n";
    } catch(int err) {cout << "error=" <<err<<endl;}
 }
 
 void test3()
 {   
    try {
    cout << "test3. operators +,-,*\n";
    int n=3;
    //n = NReader();
    cout<<"For CIntN0:\n";
    CIntN0 v1(n), v2(n), sum(n), dif(n);
    v1.setPos(0,2); v1.setPos(1,7); v1.setPos(2,4);
    v2.setPos(0,1); v2.setPos(1,2); v2.setPos(2,3);

    cout << v1;
    cout << v2;
    
    sum=v1+v2;
    dif=v1-v2; // при cout << dif  выводит первый вектор!
    cout << "Сумма    = " << sum ;
    cout << "Разность = " << v1-v2 ;
    
    cout<<"For CIntN1:\n";
     CIntN1 v3(n), v4(n),sum1(n),dif1(n);
    v3.setPos(0,3); v3.setPos(1,5); v3.setPos(2,8);
    v4.setPos(0,1); v4.setPos(1,2); v4.setPos(2,3);

    cout << v3;
    cout << v4;
    
    sum1=v3+v4;
    cout << "Сумма    = " << sum1 ;//<<"\t = "<< v3+v4<<"\t = "<< v3+v4;
    dif1=v3-v4;
    cout << "Разность = " << v3-v4 ;//<<"\t = "<< v3-v4 ;

    } catch(int err) {cout << "error=" <<err<<endl;}
 }
