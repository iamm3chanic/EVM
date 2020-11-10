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
 * +создать массив заданной начальной длины;
 * +добавить элемент в конец массива (удлиннить массив);
 * +вставить элемент так, чтобы он имел указанный индекс (удлиннить массив);
 * +получить указатель (или ссылку) элемента с заданным индексом для прямого доступа к значению;
 * +удалить элемент по указанному индексу (сократить массив);
 * +получить количество элементов в массиве;
 * +установить новую длину массива;
 * +искать заданное значение (с заданным допуском) в массиве;
 * +сортировать массив по возрастанию или убыванию.
 *
 *  Формальное определение интерфейса не задается и должно быть разработано студентом.
 * Тесты должны включать заполнение массива некоторыми значениями и проверку работы всех 
 * реализованных методов в
 * различных корректных и некорректных ситуациях.
 * В качестве метода сортировки используется алгоритм просеивания (модифицированный 
 * пузырек).
 *      Created on: 09.10.2020
 *      Author: iamm3chanic
 */
#pragma once
#include <iostream>
#include <math.h>
#include <string.h>
#include <cstdlib>
#include "CList2.h"
//#define FIVE_ 5
using namespace std;
//--------------------------------------------------------------
//----------- Определение класса -------------------------------
//--------------------------------------------------------------
class CDynamic
 {
   private:
    int n;             //Размер начального массива
    int m;             //Количество массивов всего
    int n_real;
    CList2<Arr> arrList;
    Arr cheatArr;
   public:
    CDynamic (const CDynamic&v) {CopyOnly(v);}
    CDynamic()      { SetZero(); }
    CDynamic(int num)   { m = num/5 +1; n_real=num; for(int i=0;i<m;i++)arrList.GoToNext(); cheatArr.SetN(num);}
    ~CDynamic()    { Clean(); }
    CDynamic(CDynamic&& r) {n=r.n;m=r.m;n_real=r.n_real; arrList.CopyOnly(r.arrList); cheatArr=r.cheatArr; r.SetZero(); } 	//move constructor
    
    int getM() { return m; }                    
    int getLength() { return n_real; } 
    Arr& getCheat() { return cheatArr; }
    void setLength(int length) { m = length/5 +1; n_real=length;
       for(int i=0;i<m;i++){arrList.GoToNext();}  cheatArr.SetN(length);}   
    
    CList2<Arr> &getList() { return arrList; }
    
    void SetZero(){ arrList.SetZero(); cheatArr.SetZero();  n=0;m=0;n_real=0;}
    void Clean() {arrList.Clean(); cheatArr.Clean(); SetZero();}
    void CopyOnly(const CDynamic &v);
    
    void rewrite();
    void SetCheat(double* a);
    void AddToEnd(double d);  
    void InputTo(int k, double d);
    void InputInto(int k, double d); 
    void SetDyn(CList2<Arr> l);
    void AutoSet();
    void DelNumByIndex(int index); 
    double GetNumByIndex(int index);  
    CDynamic& operator=(const CDynamic& v);  
    
    friend void SortUp(CDynamic& dyn);
    friend int BinSearch(CDynamic& dyn, int leftBound, int rightBound);
    friend int Check(CDynamic& dyn);
    friend ostream &operator<<(ostream& cout, CDynamic &v);
    friend istream &operator>>(istream& cin, CDynamic &v );
  };
  
