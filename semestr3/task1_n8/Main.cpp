/*
 * Main.cpp
 *      Created on: 01.10.2020
 *      Author: queen
 */
#include <iostream>
#include "CDynamic.h"

using namespace std;

int main()
{
 /*try{
  cout << "\ntest1. Create arrays of fix dimensions\n";
   //int nreal;
   CDynamic dyn=CDynamic(3);
   //Arr a;
   //CDynamic dyn;
   cout << "Размер массива: 3." << endl;
    cin >> dyn;
    cout << dyn;
   

    } catch(int err) {cout << "error=" <<err<<endl;}
 try{
  cout << "\ntest2. Add arrays\n";
   int nreal;
  // CDynamic dyn=CDynamic(3);
   Arr a;
   CDynamic dyn;
   cout << "Введите размер массива: " ;
   cin >> nreal;
   dyn.setLength(nreal);
    cin >> dyn;
    cout << dyn;
   
   cout << "Введите размер массива Arr: " ;
    cin >> nreal;
    a.SetN(nreal);
    cin >> a;
    cout << a; //works super!
    } catch(int err) {cout << "error=" <<err<<endl;}
    
     try{
  cout << "\ntest3. Method InputTo(int k, double d)\n";
  cout << "\nДля удобства нумерация с единицы!\n";
   int nreal,k; double d;
   CDynamic dyn;
   cout << "Введите размер массива: " ;
   cin >> nreal;
   dyn.setLength(nreal);
    cin >> dyn;
    cout << dyn;
    
     cout << "Введите место вставки эл-та: " ;
     cin >> k;
     cout << "Введите вставляемый элемент: " ;
     cin >> d;
     dyn.InputTo(k,d);
     cout << dyn;
    } catch(int err) {cout << "error=" <<err<<endl;}
   try {
      cout << "\ntest4. Method AddArr(Arr a)\n";
   Arr a;
   int nreal,i; 
   CDynamic dyn;
   cout << "Введите размер массива: " ;
   cin >> nreal;
   dyn.setLength(nreal);
    cin >> dyn;
    cout << dyn;
    
     cout << "Ввод добавляемого массива. Введите длину: " ;
     cin >> i;
     a.SetN(i);
     cin >> a;
     cout << "this is added array: " << a << endl;
     dyn.AddArr(a);
     cout << dyn;
    } catch(int err) {cout << "error=" <<err<<endl;}
     
    try{
  cout << "\ntest5. SortUp\n";
  int nreal; 
   CDynamic dyn;
   cout << "Введите размер массива: " ;
   cin >> nreal;
   dyn.setLength(nreal);
    cin >> dyn;
    cout << dyn;
    SortUp(dyn);
    Check(dyn);

    } catch(int err) {cout << "error=" <<err<<endl;}
    try{
  cout << "\ntest7. AutoSet + Sort\n";
  
   CDynamic dyn;
   dyn.AutoSet();
   SortUp(dyn);
    } catch(int err) {cout << "error=" <<err<<endl;}*/
    try{
  cout << "\ntest8. AutoSet + Sort + BinSearch\n";
   int left,right;
   CDynamic dyn;
   dyn.AutoSet();
   SortUp(dyn);
   cout<<"Введите нижнюю границу поиска: ";
   cin>>left;
   cout<<"Введите верхнюю границу поиска: ";
   cin>>right;
   BinSearch(dyn, left, right);
    } catch(int err) {cout << "error=" <<err<<endl;}
            return 0;
}
