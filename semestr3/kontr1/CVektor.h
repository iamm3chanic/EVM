/*
 * CVector.h
 * 8 . Определить класс CVector для работы с вектором вещественных
 * исел. Длина вектора задается в конструкторе класса. В классе долж-
 * ны быть определены необходимые конструкторы, деструктор, операторы
 * присваивания, сложения, вычитания, скалярного умножения.
 * В отдельном файле должен быть написан тест на данный класс.
 *      Created on: 14.09.2020
 *      Author: iamm3chanic
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
    CVektor()      { int n=3; ptrArr = new float[n];   }
    CVektor(int num)   { n = num;   ptrArr = new float [num];  }
    ~CVektor()    { delete [] ptrArr; }
    
    int getN() { return n; }                      //getter
    void setN(int dimension) { n = dimension; }   //setter
    float* getPtrArr() { return ptrArr; }
    void setPtrArr(CVektor v)  { for (int i=0; i < n; i++ ) {ptrArr[i] = v.getPtrArr()[i]; } } 
    void GetVektor();
    void ShowVektor();

    CVektor& operator=(const CVektor& v);
    CVektor operator+(const CVektor &v);
    CVektor operator-(const CVektor &v);
    float operator *(const CVektor &v);

    friend float Skalar   (CVektor& , CVektor&);  //Склярное произведение
 
    friend CVektor Kommutativ(CVektor& , CVektor& );//Сложение векторов
    friend CVektor Netativ   (CVektor& , CVektor& );//Вычитание векторов
    friend int NReader();
    friend ostream &operator<<(ostream& /*&cout*/, CVektor& );
    friend istream &operator>>(istream& /*&cin*/, CVektor& ); 
};


