/* 
 * Main.cpp
 * 8. Определить класс CVector для работы с вектором вещественных
 * чисел. Длина вектора задается с помощью оператора #define. В классе
 * должны быть определены необходимые конструкторы, операторы сло-
 * жения, вычитания, скалярного умножения.
 * В отдельном файле должен быть написан тест на данный класс.
 *      Created on: 08.09.2020
 *      Author: iamm3chanic
 */
#include <iostream>
#include "CVektor.h"

using namespace std;
int main()
{
  /* try {
     cout << "test1\n";
    CVektor v1(DIMENSION), v2(DIMENSION), sum(DIMENSION), dif(DIMENSION); 
    v1.GetVektor();
    v2.GetVektor();
    cout << "Скалярное произведение: " << Skalar(v1, v2) << endl;
    v1.ShowVektor();
    v2.ShowVektor();
  
    Kommutativ(v1, v2);
    Netativ(v1, v2);

    } catch(int err) {cout << "error=" <<err<<endl;}
   try {
    cout << "test2\n";
    CVektor v1(DIMENSION), v2(DIMENSION), sum(), dif(); 
    v1.GetVektor();
    v2.GetVektor();
    cout << "Скалярное произведение: " << Skalar(v1, v2) << endl;
    v1.ShowVektor();
    v2.ShowVektor();
  
    Kommutativ(v1, v2);
    Netativ(v1, v2);

    } catch(int err) {cout << "error=" <<err<<endl;}
    try {
    cout << "test3\n";
    int n;
    n=NReader();
    CVektor v1(n), v2(n), sum(n), dif(n); 
    v1.GetVektor();
    v2.GetVektor();
    cout << "Скалярное произведение: " << Skalar(v1, v2) << endl;
    v1.ShowVektor();
    v2.ShowVektor();
  
    Kommutativ(v1, v2);
    Netativ(v1, v2);

    } catch(int err) {cout << "error=" <<err<<endl;}*/
    /*try {
    cout << "test4\n";
    int n1,n2;
    cout << "Вектор 1 - : ";
    n1=NReader();
    cout << "Вектор 2 - : ";
    n2=NReader();
    CVektor v1(n1), v2(n2); 
    cout << "Вектор 1 - : \n";
    v1.GetVektor();
    cout << "Вектор 2 - : \n"; 
    v2.GetVektor();            
   
    v1.ShowVektor();
    v2.ShowVektor();
  
    Kommutativ(v1, v2);
    Netativ(v1, v2);
    Skalar(v1, v2);
    
    } catch(int err) {cout << "error=" <<err<<endl;}*/
    /*try {
    cout << "test5\n";
    int n2;
    //cout << "Вектор 1 - : ";
    //n1=NReader();
    cout << "Вектор 2 - : ";
    n2=NReader();
    CVektor v1, v2(n2); 
    cout << "Вектор 1 - : \n";
   //  cout << v1.getN();
    v1.GetVektor();
    cout << "Вектор 2 - : \n";
    v2.GetVektor();
   
    v1.ShowVektor();
    v2.ShowVektor();
  
    Kommutativ(v1, v2);
    Netativ(v1, v2);
    Skalar(v1, v2);
    
    } catch(int err) {cout << "error=" <<err<<endl;}*/
    /*try {
    cout << "test6\n";
 
    //n2=NReader();
    CVektor v1, v2, w, u; 
    float sc;
    v1=CVektor();
    v2=CVektor();
    cout << "Вектор 1 - : \n";
   //  cout << v1.getN();
    v1.GetVektor();
    cout << "Вектор 2 - : \n";
    v2.GetVektor();
   
    v1.ShowVektor();
    v2.ShowVektor();
  
   // Kommutativ(v1, v2);
    w=(v1+v2);
    cout << "Сумма     = ";  
    w.ShowVektor();
    //Netativ(&v1, &v2);
    u=(v1-v2);
    cout << "Разность  = "; 
    u.ShowVektor(); 
    //Skalar(v1, v2);
    sc= (v1)*(v2);
    cout << "Скалярное произведение  = " << sc <<  endl;
  
    } catch(int err) {cout << "error=" <<err<<endl;}*/
    /* try {
    cout << "test7\n";
    int n2;
    //cout << "Вектор 1 - : ";
    //n1=NReader();
    cout << "Вектор 2 - : ";
    n2=NReader();
    CVektor v1, v2, w, u; 
    float sc;
    v1=CVektor();
    v2=CVektor(n2);
    cout << "Вектор 1 - : \n";
   //  cout << v1.getN();
    v1.GetVektor();
    cout << "Вектор 2 - : \n";
    v2.GetVektor();
   
    v1.ShowVektor();
    v2.ShowVektor();
  
   // Kommutativ(v1, v2);
    w=(v1+v2);
    cout << "Сумма     = ";  
    w.ShowVektor();
    //Netativ(&v1, &v2);
    u=(v1-v2);
    cout << "Разность  = "; 
    u.ShowVektor(); 
    //Skalar(v1, v2);
    sc= (v1)*(v2);
    cout << "Скалярное произведение  = " << sc <<  endl;
    
    } catch(int err) {cout << "error=" <<err<<endl;}*/
     try {
    cout << "test8\n";
    int n1,n2;    
    float sc;
    CVektor v1, v2, w, u; 
    
    cout << "Вектор 1 - : ";    
    n1=NReader();
    v1=CVektor(n1);
    cout << "Вектор 1 - : \n";
    v1.GetVektor();
    cout << "Вектор 2 - : ";   
    n2=NReader();
    v2=CVektor(n2);   
    cout << "Вектор 2 - : \n";
    v2.GetVektor();
   
    v1.ShowVektor();
    v2.ShowVektor();
  
    Kommutativ(v1, v2);
    w=(v1+v2);
    cout << "Сумма     = ";  
    w.ShowVektor();
    Netativ(v1, v2);
    u=(v1-v2);
    cout << "Разность  = "; 
    u.ShowVektor(); 
    Skalar(v1, v2);
    sc= (v1)*(v2);
   // cout << "Скалярное произведение  = " << (v1)*(v2) <<  endl;
    cout << "Скалярное произведение  = " << sc <<  endl;
    } catch(int err) {cout << "error=" <<err<<endl;}
     try {
    cout << "test9\n";
    int n1,n2;    
    float sc;
    CVektor v1, v2, w, u; 
    
    cout << "Вектор 1 - : ";
    n1=NReader();
    v1=CVektor(n1);
    cout << "Вектор 1 - : \n";
    v1.GetVektor();
    cout << "Вектор 2 - : ";   
    n2=NReader();
    v2=CVektor(n2);   
    cout << "Вектор 2 - : \n";
    v2.GetVektor();
   
    v1.ShowVektor();
    v2.ShowVektor();
  
   // Kommutativ(v1, v2);
    w=(v1+v2);
    cout << "Сумма     = ";  
    w.ShowVektor();
    //Netativ(v1, v2);
    u=(v1-v2);
    cout << "Разность  = "; 
    u.ShowVektor(); 
    //Skalar(v1, v2);
    sc= (v1)*(v2);
    cout << "Скалярное произведение  = " << sc <<  endl;
    return 0;
    } catch(int err) {cout << "error=" <<err<<endl;}
}
