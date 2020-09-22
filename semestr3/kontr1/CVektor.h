/*
 * CVector.h
 * 8 . Определить класс CVector для работы с вектором вещественных
 * исел. Длина вектора задается в конструкторе класса. В классе долж-
 * ны быть определены необходимые конструкторы, деструктор, операторы
 * присваивания, сложения, вычитания, скалярного умножения.
 * В отдельном файле должен быть написан тест на данный класс.
 *      Created on: 16.09.2020
 *      Author: iamm3chanic
 */
#pragma once
#include <iostream>
#include <math.h>
#include <string.h>
#include <cstdlib>
using namespace std;
//--------------------------------------------------------------
//----------- Определение класса -------------------------------
//--------------------------------------------------------------
/*
DONE: const & in Kommutativ/Netativ; define Clear, SetZero, CopyOnly; changed operator =; dealed with uninitialized vars; dealed with mismatched free/delete [BY NOT USING SETN() AND REALLOC, IT'S TOO BAD]; did normal default constructor; all tests
*/
class CVektor
{
private:
    int n;                 //Размер вектора
    float *ptrArr;     //Указатель на массив элементов
public:
    CVektor (const CVektor&v) {CopyOnly(v);}
    CVektor()      { SetZero(); /*n=0; ptrArr = new float[n];*/ /*ptrArr = (float*)realloc(ptrArr, n*sizeof(float));*/ }
    CVektor(int num)   { n = num;   ptrArr = new float [num];  }
    ~CVektor()    { Clean(); }
    
    CVektor ( CVektor && ) = default; 	//move constructor
    //CVektor&  operator= ( CVektor&& );  //move assignment
    int getN() { return n; }                      //getter
    //void setN(int dimension) { n = dimension; ptrArr =(float*)realloc(ptrArr, n*sizeof(float));}   //setter
    float getPtrArr() { return *ptrArr; }
    void SetZero(){ptrArr=NULL;n=0;}
    void Clean() {delete [] ptrArr; SetZero();}
    void setPtrArr(float* arr)  { for (int i=0; i < n; i++ ) {ptrArr[i] = arr[i]; } } 
    void GetVektor();
    void ShowVektor();
    void CopyOnly(const CVektor &v);
    CVektor& operator=(const CVektor& v);
    CVektor operator+(const CVektor &v);
    CVektor operator-(const CVektor &v);
    float operator *(const CVektor &v);
    float &operator[](int i){if(i<0||i>n-1) throw -1; return (this->ptrArr)[i];}
//CVektor Netativ   (CVektor , CVektor );
    friend float Skalar   (CVektor& , CVektor&);  //Склярное произведение
 
    friend CVektor Kommutativ(const CVektor& , const CVektor& );//Сложение векторов
    friend CVektor Netativ   (const CVektor& , const CVektor& );//Вычитание векторов
    friend int NReader();
    friend ostream &operator<<(ostream& /*&cout*/, CVektor& );
    friend istream &operator>>(istream& /*&cin*/, CVektor& ); 
};


