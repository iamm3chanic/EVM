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
   glob_v= (CVektor::Input("input.txt"));
   //glob_v=(**glob_v).Input("input.txt");
   cout<<"global Number = "<<glob_n<<endl;
   for(size_t i=0;(i<glob_n)&&(*glob_v!=NULL);i++)  
   {
    //cout<<"OutFile = "<<(*glob_v[i]).getF()<<endl;
    cout<<"n = "<<(glob_v[i])->getN()<<"="<<(*glob_v[i]).getN()<<endl;
    //(glob_v[i])->ShowVektor();
    //(glob_v[i])->output("input.txt");
   }
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
    //n = NReader();
    cout<<"For CVektor0:\n";
    CVektor0 v1(n), v2(n), sum(n), dif(n);
    v1.setPos(0,11); v1.setPos(1,22); v1.setPos(2,33);
    v2.setPos(0,1); v2.setPos(1,2); v2.setPos(2,3);

    cout << v1;
    cout << v2;
    
    sum=v1+v2;
    dif=v1-v2; // при cout << dif  выводит первый вектор!
    cout << "Скалярное произведение = " << v1*v2 << endl;
    cout << "Сумма    = " << sum ;
    cout << "Разность = " << v1-v2 ;
    
    cout<<"For CVektor1:\n";
     CVektor1 v3(n), v4(n);
    v3.setPos(0,111); v3.setPos(1,222); v3.setPos(2,333);
    v4.setPos(0,1); v4.setPos(1,2); v4.setPos(2,3);

    cout << v1;
    cout << v2;
    
    cout << "Скалярное произведение = " << v3*v4 << endl;
    cout << "Сумма    = " << v3+v4 ;
    cout << "Разность = " << v3-v4 ;

    } catch(int err) {cout << "error=" <<err<<endl;}
    
        return 0;
}
