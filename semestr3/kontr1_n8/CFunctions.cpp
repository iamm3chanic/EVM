/*
 * CFunctions.cpp
 * 8 . Определить класс CVector для работы с вектором вещественных
 * исел. Длина вектора задается в конструкторе класса. В классе долж-
 * ны быть определены необходимые конструкторы, деструктор, операторы
 * присваивания, сложения, вычитания, скалярного умножения.
 * В отдельном файле должен быть написан тест на данный класс.
 *      Created on: 14.09.2020
 *      Author: iamm3chanic
 */
#include<iostream>
#include"CVektor.h"

//////////////////CLASS METHODS///////////////////////////
void CVektor::GetVektor()        //Задать вектор
    {
        //cout << "Введите размерность вектора: "; cin >> n;
        for (int i=0; i < n; i++ )
        {
            cout << "Введите элемент вектора № " << i << ": ";
            cin >> ptrArr[i];
        }
    }
void CVektor::ShowVektor()       //Показать вектор
    {
        cout << "Вектор {";
        for (int i=0; i < n; i++)
        {  
         if(i<n-1)
            cout << ptrArr[i] << ", ";
         else
            cout << ptrArr[i];
        }    
        cout << "}\n";
    }
CVektor& CVektor::operator=(const CVektor& v)
    {
         n=v.n;
        for (int i=0; i < n; i++ )
            { (ptrArr[i]) = (v.ptrArr[i]); }
        return *this;
    }
CVektor CVektor::operator+(const CVektor &v) 
    {
     CVektor r;
     if(n==v.n)
     {
     r.n=v.n;
     for (int i=0; i < r.n; i++ ) {
        r.ptrArr[i]= v.ptrArr[i]+ptrArr[i];
        }
     return r;
     }
    else 
    {
     cout << "Вектора должны быть одинаковой длины!\n"; 
     throw -1;
    }
    }
CVektor CVektor::operator-(const CVektor &v) 
    {
     CVektor r;
     if(n==v.n)
     {
     r.n=v.n;
     for (int i=0; i < r.n; i++ ) {
        r.ptrArr[i]= ptrArr[i]- v.ptrArr[i];
        }
     return r;
     }
    else 
    {
     cout << "Вектора должны быть одинаковой длины!\n"; 
     throw -1;
    }
    }
float CVektor::operator *(const CVektor &v)
    {
      float r=0;
     //n=v.n;
     if(n==v.n)
     {
     for (int i=0; i < v.n; i++ ) {
        r += v.ptrArr[i]*ptrArr[i];
        }
     return r;
     }
    else 
    {
     cout << "Вектора должны быть одинаковой длины!\n"; 
     throw -1;
    }
    }

//////////////////FRIEND FUNCTIONS////////////////////////
CVektor Kommutativ( CVektor& vector1, CVektor& vector2)
{
    CVektor temp;
    
    *(temp.ptrArr)=0;
    if(vector1.n == vector2.n)
    {
    temp.n=vector1.n;
    for (int i=0; i < vector1.n; i++ ) {
      (temp.ptrArr[i]) = ((vector1).getPtrArr()[i]) + (vector2.getPtrArr()[i]);
      }
      cout << "Сумма    - ";
     // cout << vector1->n << endl;
      temp.ShowVektor();
    return temp;
    }
    else 
    {
    throw -1;
   // cout << "Вектора должны быть одинаковой длины!\n";
   // return temp;
    }
}
CVektor Netativ( CVektor& vector1, CVektor& vector2)
{
    CVektor temp;
    
    *(temp.ptrArr)=0;
     if(vector1.getN() == vector2.getN())
    {
    temp.n=vector1.getN();
    for (int i=0; i < temp.n; i++ ) {
        (temp.ptrArr[i]) = vector1.getPtrArr()[i] - (vector2.getPtrArr()[i]);
        }
        cout << "Разность - ";
        temp.ShowVektor();
    return temp;
    }
    else 
    {
    throw -1;
   // cout << "Вектора должны быть одинаковой длины!\n";
   // return temp;
    }
}
float Skalar ( CVektor& vector1, CVektor& vector2)
{
    //static float temp;
    float temp;
    temp = 0;
    if(vector1.getN() == vector2.getN())
    {
    for (int i=0; i < (vector1).getN(); i++ ) {
        temp += (vector1.getPtrArr()[i]) * (vector2.getPtrArr()[i]);
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

ostream &operator<<(ostream& cout, CVektor &v) 
{
   cout << "Вектор {";
     for (int i=0; i < v.getN(); i++)
     { 
     if(i<v.getN()-1)
         cout << v.getPtrArr()[i]  << ", ";
     else //if(i == v.n-1)
         cout << v.getPtrArr()[i]; 
     }    
   cout << "}\n";

return cout;
}
istream &operator>>(istream& cin , CVektor &v) 
{
 for (int i=0; i < v.getN(); i++ )
        {
            cout << "Введите элемент вектора № " << i << ": ";
            cin >> v.ptrArr[i];
            
        }
return cin;
}
/*int NReader()
    {
      int n;
      cout << "Введите размерность: ";
      cin >> n;
      return n;
    } 
 */

