/*
 * CFunctions.cpp
 * 8 . Определить класс CVector для работы с вектором вещественных
 * исел. Длина вектора задается в конструкторе класса. В классе долж-
 * ны быть определены необходимые конструкторы, деструктор, операторы
 * присваивания, сложения, вычитания, скалярного умножения.
 * В отдельном файле должен быть написан тест на данный класс.
 *      Created on: 16.09.2020
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
        if(this!=&v) 
        {Clean(); CopyOnly(v);}
        return *this;
    }
/*CVektor& CVektor::operator=(const CVektor&& v)
    {
        if(this!=&&v) 
        {Clean(); CopyOnly(v);}
        return *this;
    }*/
CVektor CVektor::operator+(const CVektor &v) 
    {
     CVektor r;
    // r.SetZero();
     if(n==v.n)
     {
     //r.n=v.n;
     r=CVektor(v.n);
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
     //r.SetZero();
     if(n==v.n)
     {
     r=CVektor(v.n);
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
void CVektor::CopyOnly(const CVektor &v)
    {
     if(this!=&v)
     {memcpy(ptrArr=new float[n=v.n], v.ptrArr, v.n*sizeof(float)); }
    }
//////////////////FRIEND FUNCTIONS////////////////////////
CVektor Kommutativ(const CVektor& vector1, const CVektor& vector2)
{
    CVektor temp;
    temp.SetZero();
    //*(temp.ptrArr)=0;
    if(vector1.n == vector2.n)
    {
    //temp.setN(vector1.n);
    temp=CVektor(vector1.n);
    for (int i=0; i < vector1.n; i++ ) {
      (temp.ptrArr[i]) = (vector1.ptrArr[i]) + (vector2.ptrArr[i]);
      }
      cout << "Сумма    - ";
     // cout << vector1->n << endl;
      temp.ShowVektor();
    return temp;
    }
    else 
    {
    cout << "Вектора должны быть одинаковой длины!\n";
    throw -1;
    }
}
CVektor Netativ(const CVektor& vector1, const CVektor& vector2)
{
    CVektor temp;
    temp.SetZero();
    //*(temp.ptrArr)=0;
     if(vector1.n == vector2.n)
    {
    //temp.n=vector1.getN();
    temp=CVektor(vector1.n);
    for (int i=0; i < temp.n; i++ ) {
        *(temp.ptrArr+i) = (vector1.ptrArr[i]) - (vector2.ptrArr[i]);
        }
        cout << "Разность - ";
        temp.ShowVektor();
    return temp;
    }
    else 
    {
     cout << "Вектора должны быть одинаковой длины!\n";
    throw -1;
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
       // temp += (vector1.getPtrArr()[i]) * (vector2.getPtrArr()[i]);
       temp += (vector1.ptrArr[i]) * (vector2.ptrArr[i]);
        }
    cout << "Скалярное произведение: " << temp << endl;
    return temp;
    }
    else 
    {
    cout << "Вектора должны быть одинаковой длины!\n";
    throw -1;
    }
}

ostream &operator<<(ostream& cout, CVektor &v) 
{
   cout << "Вектор {";
     for (int i=0; i < v.getN(); i++)
     { 
     if(i<v.getN()-1)
 //        cout << v.getPtrArr()[i]  << ", ";
       cout << v.ptrArr[i]  << ", ";
     else //if(i == v.n-1)
 //        cout << v.getPtrArr()[i]; 
        cout << v.ptrArr[i] ;
     }    
   cout << "}\n";

return cout;
}
istream &operator>>(istream& cin , CVektor &v) 
{
 for (int i=0,p; i < v.getN(); i++ )
        {
            cout << "Введите элемент вектора № " << i << ": ";
            cin >> p;      //v.ptrArr[i];
            v.ptrArr[i]=p;
        }
return cin;
}

/*CVektor Netativ( CVektor& vector1, CVektor& vector2)
{
    CVektor temp;
    float arr[1]={0};
    //vector1.ShowVektor();
    temp.setPtrArr(arr);
     if(vector1.getN() == vector2.getN())
    {
    temp.setN(vector1.getN());
    for (int i=0; i < vector1.getN(); i++ ) {
        (temp.ptrArr[i]) = ((vector1).ptrArr[i]) - ((vector2).ptrArr[i]);
        //(arr[i]) = (vector1).getPtrArr()[i] - (vector2).getPtrArr()[i];
        //arr[i] = (vector1).ptrArr[i] - (vector2).ptrArr[i];
        //cout << arr[i] << endl;
        //temp.setPtrArr(arr);
        }
        //temp.setPtrArr(arr);
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
}*/
