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
   fabric.push_back(new CFabricVector1);
   CVector::Input("input.txt", v, fabric);
   cout<<"global Number = "<<v.size()<<endl;
   for(size_t i=0;(i<v.size());++i)  
   {
   v[i]->ShowVector();
   v[i]->output();
   v[i]->Sort();
   }
   cout<<"\nSORTED ONES:\n";
   for(size_t i=0;(i<v.size());++i)  
   {
   v[i]->ShowVector();
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
    //CVector v1, v2, sum, dif;
    //n = NReader();
    n=3;
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
   
    cout << "test2. operators +,-,*\n";
    int n=3;
    
    cout<<"For CVector1:\n";
     CVector1 v3(n), v4(n),sum1(n),dif1(n);
    v3.setPos(0,111); v3.setPos(1,222); v3.setPos(2,333);
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
