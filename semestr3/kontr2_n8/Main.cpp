/*
 * Main.cpp
 * 8 . Определить класс CVector для работы с вектором вещественных
 * исел. Длина вектора задается в конструкторе класса. В классе долж-
 * ны быть определены необходимые конструкторы, деструктор, операторы
 * присваивания, сложения, вычитания, скалярного умножения.
 * В отдельном файле должен быть написан тест на данный класс.
 *      Created on: 16.09.2020
 *      Author: iamm3chanic
 */
#include <iostream>
#include "CVektor.h"

using namespace std;
int NReader()
    {
      int n;
      cout << "Введите размерность: ";
      cin >> n;
      return n;
    } 

int main()
{
 try {
  cout << "test1. all functions, fix dimension\n";
    int n;
    //CVektor v1, v2, sum, dif;
    n = NReader();
   //n=2;
   // cout << n << endl;
    CVektor v1=CVektor(n);
    CVektor v2=CVektor(n);
    CVektor sum=CVektor(n);
    CVektor dif=CVektor(n);
   // CVektor v1(n), v2(n), sum(n), dif(n);
    cout << "Вектор 1 : ";
    v1.GetVektor();
    cout << "Вектор 2 : ";
    v2.GetVektor();
 
    v1.ShowVektor();
    v2.ShowVektor();
  
    Skalar(v1, v2);
    Netativ(v1, v2);
    Kommutativ(v1, v2);

    } catch(int err) {cout << "error=" <<err<<endl;}
    try {
    cout << "test2. operators cin, cout\n";
    int n;
    //CVektor v1, v2, sum, dif;
    n = NReader();
    //v1.setN(n);
    //v2.setN(n);
    //sum.setN(n);
    //dif.setN(n);
    CVektor v1(n), v2(n), sum(n), dif(n);
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
    CVektor v1(n), v2(n), sum(n), dif(n);
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
    CVektor sum, dif;
    cout << "Вектор 1 : ";
    n1 = NReader();
    CVektor v1(n1);
    //v1.setN(n1);
    v1.GetVektor();
    
    cout << "Вектор 2 : ";
    n2 = NReader();
     CVektor v2(n2);
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
    CVektor sum, dif;
    cout << "Вектор 1 : ";
    n1 = NReader();
    CVektor v1(n1);
    cin >> v1;
    
    cout << "Вектор 2 : ";
    n2 = NReader();
    CVektor v2(n2);
    cin >> v2;
 
    cout << v1;
    cout << v2;
    
    sum=v1+v2;
    dif=v1-v2;
    cout << "Скалярное произведение = " << v1*v2 << endl;
    cout << "Сумма    = " << sum ;
    cout << "Разность = " << dif ;

    } catch(int err) {cout << "error=" <<err<<endl;}
        return 0;
}
