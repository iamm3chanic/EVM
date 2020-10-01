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
 * вставить элемент так, чтобы он имел указанный индекс (удлиннить массив);
 * получить указатель (или ссылку) элемента с заданным индексом для прямого доступа к значению;
 * удалить элемент по указанному индексу (сократить массив);
 * получить количество элементов в массиве;
 * +установить новую длину массива;
 * искать заданное значение (с заданным допуском) в массиве;
 * +сортировать массив по возрастанию или убыванию.
 *  Формальное определение интерфейса не задается и должно быть разработано студентом.
 * Тесты должны включать заполнение массива некоторыми значениями и проверку работы всех 
 * реализованных методов в
 * различных корректных и некорректных ситуациях.
 * В качестве метода сортировки используется алгоритм просеивания (модифицированный 
 * пузырек).
 *      Created on: 01.10.2020
 *      Author: queen
 */
#pragma once
#include <iostream>
#include <math.h>
#include <string.h>
#include <cstdlib>
#include "CList1.h"
#define FIVE_ 5
using namespace std;
//TODO create array, setlength, lenghten array, sort
//--------------------------------------------------------------
//----------- Определение класса -------------------------------
//--------------------------------------------------------------
/*
Реализация.
Для небольших массивов <5 и сортировки использовать чит. При записи записывать и в чит и в лист*/
class CDynamic
 {
   private:
    int n;                 //Размер начального массива
    int m;             //Количество массивов всего
    int n_real;
    CList1<Arr> arrList;
    Arr cheatArr;
   public:
    CDynamic (const CDynamic&v) {CopyOnly(v);}
    CDynamic()      { SetZero(); }
    CDynamic(int num)   { m = num/5 +1; n_real=num;/*n_real=(m-1)*5+(num%5); arrList= CList1<Arr>(m);*/ for(int i=0;i<m;i++)arrList.GoToNext(); cheatArr.SetN(num);}
    ~CDynamic()    { Clean(); }

    CDynamic ( CDynamic && ) = default; 	//move constructor
    //CDynamic&  operator= ( CVektor&& );  //move assignment
    
    int getM() { return m; }                    
    int getLength() { return n_real; } 
   // Arr* getCheat() { return &cheatArr; } //why pointer?..
    Arr &getCheat() { return cheatArr; }
    void setLength(int length) { m = length/5 +1; n_real=length; for(int i=0;i<m;i++)arrList.GoToNext();  cheatArr.SetN(length);}   //setter
    //CList1<Arr> &getList() { return arrList; }
    CList1<Arr> &getList() { return arrList; }
    
    void SetZero(){ cheatArr.SetZero();  n=0;m=0;}
    void Clean() {/*arrList.Clean(); cheatArr.Clean();*/ SetZero();}
    void CopyOnly(const CDynamic &v);
    
    void SetCheat(double* a);
    void AddArr(Arr a);
    void InputTo(int k, double d);
    void InputInto(int k, double d);
    void InputAfter(int k, double d);
    void SetDyn(CList1<Arr> l);
    void GetDynamic();
    void ShowDynamic();
    CDynamic& operator=(const CDynamic& v);
    
    friend void SortUp(CDynamic& dyn);
    //friend void SortDown(CDynamic& dyn);
    friend int Check(CDynamic& dyn);
    friend ostream &operator<<(ostream& cout, CDynamic &v);
    friend istream &operator>>(istream& /*&cin*/, CDynamic& );
  };
  
