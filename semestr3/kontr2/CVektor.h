/*
 * CVector.h
 * 8 . Определить класс CVector для работы с вектором вещественных
 * исел. Длина вектора задается в конструкторе класса. В классе долж-
 * ны быть определены необходимые конструкторы, деструктор, операторы
 * присваивания, сложения, вычитания, скалярного умножения.
 * В отдельном файле должен быть написан тест на данный класс.
 *      Created on: 11.09.2020
 *      Author: Anfisa
 */
 #pragma once
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
//--------------------------------------------------------------
//----------- Определение класса -------------------------------
//--------------------------------------------------------------
class CVektor
{
private:
    int n;                 //Размер вектора
    float* ptrArr;     //Указатель на массив элементов
public:
    CVektor (const CVektor&)= default;
    CVektor()         
    {
        int n=3;
        ptrArr = new float[n];
       // cout << "!!! Конструктор отработал !!!" << endl;
    }
    CVektor(int num)
    {
        n = num;
        ptrArr = new float [num];
        //cout << "!!! Конструктор отработал !!!" << endl;
    }
    ~CVektor()
    { delete [] ptrArr; /*cout << "!!! Деструктор отработал !!!" << endl;*/}
    
    int getN() { return n; }                      //getter
    void setN(int dimension) { n = dimension; }   //setter
    float* getPtrArr() { return ptrArr; }
    void setPtrArr(CVektor v) 
    {  for (int i=0; i < n; i++ )
        {
            //cout << "Введите элемент вектора № " << i << ": ";
            ptrArr[i] = v.getPtrArr()[i];
        } 
     }
  //  void setPtrArr(float *input) {for (int i=0;i<input.length;i++) ptrArr[i]=input[i];}
    void GetVektor()        //Задать вектор
    {
        //cout << "Введите размерность вектора: "; cin >> n;
        for (int i=0; i < n; i++ )
        {
            cout << "Введите элемент вектора № " << i << ": ";
            cin >> ptrArr[i];
        }
    }
    void ShowVektor()       //Показать вектор
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
   /* CVektor operator= (CVektor v)
    {
        for (int i=0; i < n; i++ )
            *(ptrArr + i) = *(v.ptrArr + i);
        return *this;
    }*/

    friend float Skalar   (CVektor& , CVektor&);  //Склярное произведение
 
    friend CVektor Kommutativ(CVektor& , CVektor& );//Сложение векторов
    friend CVektor Netativ   (CVektor& , CVektor& );//Вычитание векторов
 //   friend CVektor Kommutativ(CVektor* , CVektor* );//Сложение векторов
 //   friend CVektor Netativ   (CVektor* , CVektor* );//ВЫчитание векторов
    friend int NReader();
    friend ostream &operator<<(ostream& /*&cout*/, CVektor& );
    friend istream &operator>>(istream& /*&cin*/, CVektor& ); 
};

/*
CVektor Kommutativ(CVektor* vector1, CVektor* vector2)
{
    CVektor temp;
    
    *(temp.ptrArr)=0;
    temp.n = vector1->n;
    for (int i=0; i < vector1->n; i++ )
      *(temp.ptrArr + i) = *((vector1)->ptrArr + i) + *((vector2)->ptrArr + i);
      cout << "Сумма - ";
      temp.ShowVektor();
   
    return temp;
}
CVektor Netativ(CVektor* vector1, CVektor* vector2)
{
    CVektor temp;
    
    *(temp.ptrArr)=0;
    temp.n = vector1->n;
    for (int i=0; i < vector1->n; i++ )
        *(temp.ptrArr + i) = *((vector1)->ptrArr + i) - *((vector2)->ptrArr + i);
       
        cout << "Разность - ";
        temp.ShowVektor();
    return temp;
}
float Skalar (CVektor* vector1, CVektor* vector2)
{
    static float temp;
    temp = 0;
    for (int i=0; i < (*vector1).n; i++ )
        temp += *(vector1->ptrArr + i) * *(vector2->ptrArr + i);
    return temp;
}*/

