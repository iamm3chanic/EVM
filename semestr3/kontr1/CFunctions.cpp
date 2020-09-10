#include<iostream>
#include"CVektor.h"


CVektor Kommutativ(const CVektor& vector1, const CVektor& vector2)
{
    CVektor temp;
    
    *(temp.ptrArr)=0;
    if(vector1.n == vector2.n)
    {
    temp.n=vector1.n;
    for (int i=0; i < vector1.n; i++ ) {
      (temp.ptrArr[i]) = ((vector1).ptrArr[i]) + ((vector2).ptrArr[i]);
      }
      cout << "Сумма    - ";
     // cout << vector1->n << endl;
      temp.ShowVektor();
    return temp;
    }
    else 
    {
    cout << "Вектора должны быть одинаковой длины!\n";
    return temp;
    }
}
CVektor Netativ(const CVektor& vector1, const CVektor& vector2)
{
    CVektor temp;
    
    *(temp.ptrArr)=0;
     if(vector1.n == vector2.n)
    {
    temp.n=vector1.n;
    for (int i=0; i < DIMENSION; i++ ) {
        *(temp.ptrArr + i) = *((vector1).ptrArr + i) - *(vector2.ptrArr + i);
        }
        cout << "Разность - ";
        temp.ShowVektor();
    return temp;
    }
    else 
    {
    cout << "Вектора должны быть одинаковой длины!\n";
    return temp;
    }
}
float Skalar (const CVektor& vector1, const CVektor& vector2)
{
    //static float temp;
    float temp;
    temp = 0;
    if(vector1.n == vector2.n)
    {
    for (int i=0; i < (vector1).n; i++ ) {
        temp += (vector1.ptrArr[i]) * (vector2.ptrArr[i]);
        }
    cout << "Скалярное произведение: " << temp << endl;
    return temp;
    }
    else 
    {
    throw -1;
    //cout << "Вектора должны быть одинаковой длины!\n";
   // return temp;
    }
}
ostream &operator <<(ostream &cout, const CVektor& v) 
{for(int i = 0; i<v.n; i++) cout<<v.ptrArr[i]; return cout;}
int NReader()
    {
      int n;
      cout << "Введите размерность: ";
      cin >> n;
      return n;
    } 
  

