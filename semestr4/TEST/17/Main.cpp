#include <iostream>
#include "CVektor.h"

using namespace std;


int main()
{
  try {
   cout << "test0. Input + output\n";
vector<CFabricVektor*> fabric;
vector<CVektor*> v;
   fabric.push_back(new CFabricVektor0);
   fabric.push_back(new CFabricVektor1);
   CVektor::Input("input.txt", v, fabric);
   cout<<"global Number = "<<v.size()<<endl;
   for(size_t i=0;(i<v.size());++i)  
   {
   v[i]->output("input.txt");
   }
    for(size_t i=0;(i<v.size());i++)  
   {
   delete v[i]; 
   }
   
    for(size_t i=0;(i<fabric.size());i++)  {delete fabric[i];}
  } catch(int err) {cout << "error=" <<err<<endl;} 
  
  try {
  cout << "test1. create vectors\n";
    int n;
    n=3;
    CVektor0 v1=CVektor0(n);
    CVektor0 v2=CVektor0(n);
    CVektor1 v3=CVektor1(n);
    CVektor1 v4=CVektor1(n);
    
    cout<< "SUCCESS\n";
  
    } catch(int err) {cout << "error=" <<err<<endl;}
    try {
  cout << "test2. CVektor0 and file\n";
    int i; char c[15]="out_test.txt";
    CVektor0 v1=CVektor0(3);
    v1.setPos(0,11); v1.setPos(1,22); v1.setPos(2,33);
    v1.setText(c);
    CVektor1 v2=CVektor1(3);
    v2.setPos(0,1111); v2.setPos(1,2222); v2.setPos(2,3333);
    v2.setText(c);
    i = v1.output("input.txt");
    if(i==0){cout<< "SUCCESS-0\n";}
    i = v2.output("input.txt");
    if(i==0){cout<< "SUCCESS-1\n";}
    else cout<< "Some error...\n";
    } catch(int err) {cout << "error=" <<err<<endl;}
    
    try {
    cout << "test3. operators +,-,*\n";
    int n=3;
    cout<<"For CVektor0:\n";
    CVektor0 v1(n), v2(n), sum(n), dif(n);
    v1.setPos(0,11); v1.setPos(1,22); v1.setPos(2,33);
    v2.setPos(0,1); v2.setPos(1,2); v2.setPos(2,3);

    cout << v1;
    cout << v2;
    
    sum=v1+v2;
    dif=v1-v2; 
    cout << "Сумма    = " << sum ;
    cout << "Разность = " << v1-v2 ;
    
    cout<<"For CVektor1:\n";
     CVektor1 v3(n), v4(n),sum1(n),dif1(n);
    v3.setPos(0,111); v3.setPos(1,222); v3.setPos(2,333);
    v4.setPos(0,1); v4.setPos(1,2); v4.setPos(2,3);

    
    sum1=v3+v4;
    cout << "Сумма    = " << sum1 ;
    dif1=v3-v4;
    cout << "Разность = " << v3-v4 ;
    } catch(int err) {cout << "error=" <<err<<endl;}
    
        return 0;
}