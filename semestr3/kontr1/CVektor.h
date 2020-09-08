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
#include <iostream>
#include <math.h>
#define DIMENSION 2
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
    CVektor()         
    {
        //n = 3;
        ptrArr = new float [DIMENSION];
    }
    CVektor(int num)
    {
        n = DIMENSION;
        ptrArr = new float [DIMENSION];
        cout << "!!! Конструктор отработал !!!" << endl;
    }
    ~CVektor()
    { delete [] ptrArr; cout << "!!! Деструктор отработал !!!" << endl;}
    void GetVektor()        //Задать вектор
    {
        //cout << "Введите размерность вектора: "; cin >> n;
        for (int i=0; i < n; i++ )
        {
            cout << "Введите элемент вектора № " << i << ": ";
            cin >> *(ptrArr + i);
        }
    }
    float ArrModul()        //Вычислить модуль
    {
        float modul = 0;
        for (int i=0; i < n; i++ )
            modul += *(ptrArr + i) *  *(ptrArr + i);
        return sqrt (modul);
    }
    void ShowVektor()       //Показать вектор
    {
        cout << "Вектор {";
        for (int i=0; i < DIMENSION; i++)
        { 
         if(i<DIMENSION-1)
            cout << *(ptrArr + i) << ", ";
         else
            cout << *(ptrArr + i);
        }    
        cout << "}\n";
 
    }
    CVektor operator= (CVektor v)
    {
        for (int i=0; i < n; i++ )
            *(ptrArr + i) = *(v.ptrArr + i);
        return *this;
    }

    friend float Skalar   (CVektor* , CVektor*);  //Склярное произведение
 
    friend CVektor Kommutativ(CVektor* , CVektor* );//Сложение векторов
    friend CVektor Netativ   (CVektor* , CVektor* );//ВЫчитание векторов
};

CVektor Kommutativ(CVektor* vector1, CVektor* vector2)
{
    CVektor temp;
    
    *(temp.ptrArr)=0;
    for (int i=0; i < vector1->n; i++ )
      *(temp.ptrArr + i) = *((vector1)->ptrArr + i) + *((vector2)->ptrArr + i);
      cout << "Сумма - ";
      temp.ShowVektor();
   
    //(temp.ptrArr[i]) = (vector1->ptrArr[i]) +  (vector2->ptrArr[i]);
    return temp;
}
CVektor Netativ(CVektor* vector1, CVektor* vector2)
{
    CVektor temp;
    
    *(temp.ptrArr)=0;
    for (int i=0; i < DIMENSION; i++ )
        *(temp.ptrArr + i) = *((vector1)->ptrArr + i) - *(vector2->ptrArr + i);
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
}


