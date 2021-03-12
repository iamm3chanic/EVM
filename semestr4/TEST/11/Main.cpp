/*
 * Main.cpp
 */
#include <iostream>
#include "CVektor.h"

using namespace std;


int main()
{
  try {
   cout << "test0. Input + output\n";
vector<CFabricVektor*> fabric;
vector<CVektor*> v;
   fabric.push_back(new CFabricVektor1);
   CVektor::Input("input.txt", v, fabric);
   cout<<"global Number = "<<v.size()<<endl;
   for(size_t i=0;(i<v.size());++i)  
   {
   v[i]->ShowVektor();
   v[i]->output();
   v[i]->DeleteSame();
   }
   cout<<"\nDELETING SAME ONES:\n";
   for(size_t i=0;(i<v.size());++i)  
   {
   v[i]->ShowVektor();
   }
    for(size_t i=0;(i<v.size());i++)  
   {
   delete v[i]; //delete fabric[i];
   }
   //delete &f0; delete &f1;
    for(size_t i=0;(i<fabric.size());i++)  {delete fabric[i];}
   //delete &fabric;
  // delete[] glob_v;
  } catch(int err) {cout << "error=" <<err<<endl;} 
  
  try {
  cout << "test1. create vectors\n";
    int n;
    //CVektor v1, v2, sum, dif;
    //n = NReader();
    n=3;
    CVektor1 v3=CVektor1(n);
    CVektor1 v4=CVektor1(n);
    
    cout<< "SUCCESS\n";
  
    } catch(int err) {cout << "error=" <<err<<endl;}
    try {
  cout << "test2. CVektor1 and file\n";
    int i; char c[15]="out_test.txt";

    CVektor1 v2=CVektor1(3);
    v2.setPos(0,1111); v2.setPos(1,2222); v2.setPos(2,3333);
    v2.setText(c);
    i = v2.output();
    if(i==0){cout<< "SUCCESS-1\n";}
    else cout<< "Some error...\n";
    } catch(int err) {cout << "error=" <<err<<endl;}
    
    try {
    cout << "test3. operators +,-,*\n";
    int n=3;
    
    cout<<"For CVektor1:\n";
     CVektor1 v3(n), v4(n),sum1(n),dif1(n);
    v3.setPos(0,111); v3.setPos(1,222); v3.setPos(2,333);
    v4.setPos(0,1); v4.setPos(1,2); v4.setPos(2,3);

    cout << v3;
    cout << v4;
    cout << "Скалярное произведение = " << v3*v4 << endl;
    
    //sum1=v3+v4;
    cout << "Сумма    = " << v3+v4 ;//<<"\t = "<< v3+v4<<"\t = "<< v3+v4;
    //dif1=v3-v4;
    cout << "Разность = " << v3-v4 ;//<<"\t = "<< v3-v4 ;

    } catch(int err) {cout << "error=" <<err<<endl;}
    
        return 0;
}
