/*
 * Main.cpp
 * 8. Определить класс CVector для работы с вектором вещественных
 * чисел. Длина вектора задается в конструкторе класса. В классе
 * должны быть определены необходимые конструкторы, деструктор, операторы сло-
 * жения, вычитания, скалярного умножения.
 * Написать функцию и конструктор сохранения переменной данного
 * типа в файл и загрузки из файла.
 * В отдельном файле должен быть написан тест на данный класс.
 *      Created on: 14.02.2021
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
CVektor **glob_v; size_t glob_n;

int main()
{
  try {
   cout << "test0. Input + output\n";
   glob_v= CVektor::Input("input.txt");
   for(size_t i=0;i<glob_n;i++)  (*glob_v[i]).output("output.txt");
   //cout<<(*glob_v[i]);//(*glob_v[i]).ShowVektor();
   delete[] glob_v;
  } catch(int err) {cout << "error=" <<err<<endl;} 
  
  try {
  cout << "test1. create vectors\n";
    int n;
    //CVektor v1, v2, sum, dif;
    //n = NReader();
    n=3;
    CVektor0 v1=CVektor0(n);
    CVektor0 v2=CVektor0(n);
    CVektor1 v3=CVektor1(n);
    CVektor1 v4=CVektor1(n);
    
    cout<< "SUCCESS\n";
   /* cout << "Вектор 1 : ";
    v1.GetVektor();
    cout << "Вектор 2 : ";
    v2.GetVektor();
 
    v1.ShowVektor();
    v2.ShowVektor();*/
  
    } catch(int err) {cout << "error=" <<err<<endl;}
    try {
  cout << "test2. CVektor0 and file\n";
    int i;
    CVektor0 v1;
    for(int k=0;k<2;k++)
    i = v1.output("input.txt");
    if(i==0){cout<< "SUCCESS\n";}
    else cout<< "Some error...\n";
    } catch(int err) {cout << "error=" <<err<<endl;}
    /*try {
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
    try {
  cout << "test6. operator []\n";
    int n;
    
    n = NReader();
   //n=2;
   // cout << n << endl;
    CVektor v1=CVektor(n);
    
    cout << "Вектор 1 : ";
    v1.GetVektor();
   
    v1.ShowVektor();
    cout << "Первая координата: " << v1[0] << endl;

    } catch(int err) {cout << "error=" <<err<<endl;}*/
        return 0;
}
