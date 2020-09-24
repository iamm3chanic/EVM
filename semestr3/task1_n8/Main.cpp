/*
 * Main.cpp
 *      Created on: 16.09.2020
 *      Author: iamm3chanic
 */
#include <iostream>
#include "CDynamic.h"

using namespace std;

int main()
{
 
  cout << "\ntest1. Add arrays\n";
   // int n,m;
   CDynamic dyn=CDynamic(3);
    cin >> dyn;
    cout << dyn;
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
