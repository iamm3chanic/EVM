/*
 * CDynamic.h
 * Задание 1.8. Динамический массив чисел с возможностью сортировки.
 * 
 * Требуется реализовать динамический массив чисел (значений double) с возможностью 
 * сортировки и быстрого (бинарного)
 * поиска. Идея реализации состоит в том, что сначала для хранения выделяется небольшой
 *  массив фиксированной длины, а по
 * мере добавления элементов выделяются дополнительные такие же массивы, которые
 *  связываются в список.
 * 
 * Реализация класса должна обеспечивать следующие возможности:
 * 
 * создать массив заданной начальной длины;
 * добавить элемент в конец массива (удлиннить массив);
 * вставить элемент так, чтобы он имел указанный индекс (удлиннить массив);
 * получить указатель (или ссылку) элемента с заданным индексом для прямого доступа к значению;
 * удалить элемент по указанному индексу (сократить массив);
 * получить количество элементов в массиве;
 * установить новую длину массива;
 * искать заданное значение (с заданным допуском) в массиве;
 * сортировать массив по возрастанию или убыванию.
 *  Формальное определение интерфейса не задается и должно быть разработано студентом.
 * Тесты должны включать заполнение массива некоторыми значениями и проверку работы всех 
 * реализованных методов в
 * различных корректных и некорректных ситуациях.
 * В качестве метода сортировки используется алгоритм просеивания (модифицированный 
 * пузырек).
 *      Created on: 22.09.2020
 *      Author: queen
 */
#pragma once
#define FIVE 5
#include <iostream>
#include <math.h>
#include <string.h>
#include <cstdlib>
#include "CList1.h"
using namespace std;
//TODO create array, lenghten array
//--------------------------------------------------------------
//----------- Определение класса -------------------------------
//--------------------------------------------------------------

class CDynamic
 {
   private:
    int n=FIVE;                 //Размер начального массива
    int m=1;             //Количество массивов всего
    int n_real=0;
    CList1<Arr> arrList;
   public:
    CDynamic (const CDynamic&v) {CopyOnly(v);}
    CDynamic()      { SetZero(); }
    CDynamic(int num)   { m = num/5 +1; n_real=(m-1)*5+(num%5); arrList= CList1<Arr>(m);}
    ~CDynamic()    { /*Clean();*/ }

    CDynamic ( CDynamic && ) = default; 	//move constructor
    //CVektor&  operator= ( CVektor&& );  //move assignment
    
    int getM() { return m; }                      //getter
    void setLength(int length) { m = length/5 +1; /*arrList.Setlength(m);*/}   //setter
    //CList1<Arr> &getList() { return arrList; }
    CList1<Arr> &getList() { return arrList; }
    void SetZero(){arrList.Clean();n=0;m=0;}
    void Clean() {arrList.Clean(); SetZero();}
    void CopyOnly(const CDynamic &v);
    
    void AddArr(Arr a);
    void InputTo(int k, double d);
    void SetDyn(CList1<Arr> l);
    void GetDynamic();
    void ShowDynamic();
    CDynamic& operator=(const CDynamic& v);
    
    friend void SortUp(CDynamic& dyn);
    friend void SortDown(CDynamic& dyn);
    friend int Check(CDynamic& dyn);
    friend ostream &operator<<(ostream& /*&cout*/, CDynamic& );
    friend istream &operator>>(istream& /*&cin*/, CDynamic& );
  };
  
