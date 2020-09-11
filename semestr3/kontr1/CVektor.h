
/*
 * CVector.h
 * 8. Определить класс CVector для работы с вектором вещественных
 * чисел. Длина вектора задается с помощью оператора #define. В классе
 * должны быть определены необходимые конструкторы, операторы сло-
 * жения, вычитания, скалярного умножения.
 * В отдельном файле должен быть написан тест на данный класс.
 *      Created on: 08.09.2020
 *      Author: Anfisa
 */
 #pragma once
#include <iostream>
#include <math.h>
#include <string.h>
#define DIMENSION 2
using namespace std;
//--------------------------------------------------------------
//----------- Определение класса -------------------------------
//--------------------------------------------------------------
class CVektor
{
private:
    int n;                 //Размер вектора
    float ptrArr[DIMENSION];     //Указатель на массив элементов
public:
    CVektor (const CVektor&)= default;
    CVektor()         
    { 
        n = DIMENSION;
        memset (ptrArr, 'x', n);
       // ptrArr = float [DIMENSION];
    }
    CVektor(int num)
    {
        n = num;
        memset (ptrArr, 0, n);
       // ptrArr = float [num];
       // cout << "!!! Конструктор отработал !!!" << endl;
    }
    void GetVektor()        //Задать вектор
    {
        //cout << "Введите размерность вектора: "; cin >> n;
        for (int i=0; i < n; i++ )
        {
            cout << "Введите элемент вектора № " << i << ": ";
            cin >> *(ptrArr + i);
        }
    }
    void ShowVektor()       //Показать вектор
    {
    //cout << n << endl;
    if(n<=DIMENSION)
    {
        cout << "Вектор {";
        for (int i=0; i < n; i++)
        { 
         if(i<n-1)
            cout << *(ptrArr + i) << ", ";
         else //if(i == n-1)
            cout << *(ptrArr + i);
        }    
        cout << "}\n";
     }
     else
        cout << "Вектор имеет слишком большую размерность!\n";
    }
    CVektor& operator=(const CVektor& v)
    {
         n=v.n;
        for (int i=0; i < n; i++ )
            { (ptrArr[i]) = (v.ptrArr[i]); }
        return *this;
    }
    CVektor operator+(const CVektor &v) 
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
   
    //return r;
    }
    }
    CVektor operator-(const CVektor &v) 
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
    float operator *(const CVektor &v)
    {
      float r;
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

    friend float Skalar   (const CVektor& , const CVektor&);  //Склярное произведение
    friend CVektor Kommutativ(const CVektor& , const CVektor& );//Сложение векторов
    friend CVektor Netativ   (const CVektor& , const CVektor& );//Вычитание векторов
    friend int NReader();       
    friend ostream &operator <<(ostream &cout, const CVektor& v);  
    friend istream &operator >>(istream &cin, const CVektor& v);               
};  


int NReader();  
