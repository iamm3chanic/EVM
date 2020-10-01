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
/* try{
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
    } catch(int err) {cout << "error=" <<err<<endl;}*/
    
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
    //CList1<float[5]> list;
   /* CDynamic v1=CDynamic(n);
    CDynamic v2=CDynamic(n);
    CDynamic sum=CDynamic(n);
    CDynamic dif=CDynamic(n);
   // CDynamic v1(n), v2(n), sum(n), dif(n);
    cout << "Вектор 1 : ";
    v1.GetVektor();
    cout << "Вектор 2 : ";
    v2.GetVektor();
   */

    
    /*try {
    cout << "test2. operators cin, cout\n";
    int n;
    //CDynamic v1, v2, sum, dif;
    n = NReader();
    //v1.setN(n);
    //v2.setN(n);
    //sum.setN(n);
    //dif.setN(n);
    CDynamic v1(n), v2(n), sum(n), dif(n);
    cout << "Вектор 1 : ";
    //v1.GetVektor();
    cin >> v1;
    cout << "Вектор 2 : ";
    //v2.GetVektor();
    cin >> v2;
 
    //v1.ShowVektor();
    cout << v1;
    //v2.ShowVektor();
    cout << v2;
  
    Skalar(v1, v2);
    Kommutativ(v1, v2);
    Netativ(v1, v2);

    } catch(int err) {cout << "error=" <<err<<endl;}
    try {
    cout << "test3. operators +,-,*\n";
    int n;
    n = NReader();
   //n=2;
   // cout << n << endl;
    //v1.setN(n);
    //v2.setN(n);
    //sum.setN(n);
    //dif.setN(n);
    CDynamic v1(n), v2(n), sum(n), dif(n);
    cout << "Вектор 1 : ";
    cin >> v1;
    cout << "Вектор 2 : ";
    cin >> v2;
 
    cout << v1;
    cout << v2;
    
    sum=v1+v2;
    dif=v1-v2;
    cout << "Скалярное произведение = " << v1*v2 << endl;
    cout << "Сумма    = " << sum ;
    cout << "Разность = " << dif ;

    } catch(int err) {cout << "error=" <<err<<endl;}
    try {
    cout << "test4. functions&operators in different dimensions\n";
    int n1,n2;
    CDynamic sum, dif;
    cout << "Вектор 1 : ";
    n1 = NReader();
    CDynamic v1(n1);
    //v1.setN(n1);
    v1.GetVektor();
    
    cout << "Вектор 2 : ";
    n2 = NReader();
     CDynamic v2(n2);
   // v2.setN(n2);
    cin >> v2;
   // sum.setN(n1);
   // dif.setN(n1);
 
    cout << v1;
    v2.ShowVektor();
    
    sum=v1+v2;
    dif=v1-v2;
    cout << "Скалярное произведение = " << v1*v2 << endl;
    cout << "Сумма    = " << sum ;
    cout << "Разность = " << dif ;
    Skalar(v1, v2);
    Kommutativ(v1, v2);
    Netativ(v1, v2);
    } catch(int err) {cout << "error=" <<err<<endl;}
    try {
    cout << "test5. operators in different dimensions\n";
    int n1,n2;
    CDynamic sum, dif;
    cout << "Вектор 1 : ";
    n1 = NReader();
    CDynamic v1(n1);
    cin >> v1;
    
    cout << "Вектор 2 : ";
    n2 = NReader();
    CDynamic v2(n2);
    cin >> v2;
 
    cout << v1;
    cout << v2;
    
    sum=v1+v2;
    dif=v1-v2;
    cout << "Скалярное произведение = " << v1*v2 << endl;
    cout << "Сумма    = " << sum ;
    cout << "Разность = " << dif ;

    } catch(int err) {cout << "error=" <<err<<endl;}*/
        return 0;
}
