/*
 * Main.cpp
 */
#include <iostream>
#include "CVector.h"

using namespace std;


int main()
{
  try {
   cout << "test0. Input + output\n";
vector<CFabricVector*> fabric;
vector<CVector*> v;
   fabric.push_back(new CFabricVector0);
   fabric.push_back(new CFabricVector1);
   CVector::Input("input.txt", v, fabric);
   cout<<"global Number = "<<v.size()<<endl;
   for(size_t i=0;(i<v.size());++i)  
   {
   //v[i]->ShowVector();
   v[i]->output();
   }
    for(size_t i=0;(i<v.size());i++)  
   {
   delete v[i]; //delete fabric[i];
   }
   //delete &f0; delete &f1;
    for(size_t i=0;(i<fabric.size());i++)  {delete fabric[i];}
  } catch(int err) {cout << "error=" <<err<<endl;} 
  
  try {
  cout << "test1. create vectors\n";
    int n;
    n=3;
    CVector0 v1=CVector0(n);
    CVector0 v2=CVector0(n);
    CVector1 v3=CVector1(n);
    CVector1 v4=CVector1(n);
    
    cout<< "SUCCESS\n";
   /* cout << "Вектор 1 : ";
    v1.GetVector();
    cout << "Вектор 2 : ";
    v2.GetVector();
 
    v1.ShowVector();
    v2.ShowVector();*/
  
    } catch(int err) {cout << "error=" <<err<<endl;}
    try {
  cout << "test2. CVector0 and file\n";
    int i; char c[15]="out_test.txt";
    CVector0 v1=CVector0(3);
    v1.setPos(0,11); v1.setPos(1,22); v1.setPos(2,33);
    v1.setText(c);
    CVector1 v2=CVector1(3);
    v2.setPos(0,1111); v2.setPos(1,2222); v2.setPos(2,3333);
    v2.setText(c);
    i = v1.output();
    if(i==0){cout<< "SUCCESS-0\n";}
    i = v2.output();
    if(i==0){cout<< "SUCCESS-1\n";}
    else cout<< "Some error...\n";
    } catch(int err) {cout << "error=" <<err<<endl;}
    
    try {
    cout << "test3. operators +,-,*\n";
    int n=3;
    //n = NReader();
    cout<<"For CVector0:\n";
    CVector0 v1(n), v2(n), sum(n), dif(n);
    v1.setPos(0,11); v1.setPos(1,22); v1.setPos(2,33);
    v2.setPos(0,1); v2.setPos(1,2); v2.setPos(2,3);

    cout << v1;
    cout << v2;
    
    sum=v1+v2;
    dif=v1-v2; // при cout << dif  выводит первый вектор!
    cout << "Скалярное произведение = " << v1*v2 << endl;
    cout << "Сумма    = " << sum ;
    cout << "Разность = " << v1-v2 ;
    
    cout<<"For CVector1:\n";
     CVector1 v3(n), v4(n),sum1(n),dif1(n);
    v3.setPos(0,100); v3.setPos(1,200); v3.setPos(2,300);
    v4.setPos(0,1); v4.setPos(1,2); v4.setPos(2,3);

    cout << v3;
    cout << v4;
    cout << "Скалярное произведение = " << v3*v4 << endl;
    
    sum1=v3+v4;
    cout << "Сумма    = " << sum1 ;//<<"\t = "<< v3+v4<<"\t = "<< v3+v4;
    dif1=v3-v4;
    cout << "Разность = " << v3-v4 ;//<<"\t = "<< v3-v4 ;

    } catch(int err) {cout << "error=" <<err<<endl;}
    
        return 0;
}
