/*
  CString.h
 Задание 1.18. Токенайзер текстовой строки.
Требуется разбить данную строку на токены по заданному набору символов-разделителей и обеспечить работу с этими
токенами. Наряду с исходной строкой, в реализации создается список, хранящий позиции и длины выделенных токенов.
Реализация класса должна поддерживать следующие возможности:
+инициализировать токенайзер данным набором символов-разделителей;
+разбить данную строку на токены;
+получить общее количество найденных токенов;
+возможность последовательного просмотра токенов (итератор);
+получение токена с заданным порядковым номером;
+возможность изменить набор символов-разделителей для данной строки.
Формальное определение интерфейса не задается и должно быть разработано студентом.
Тесты должны включать разбиение разнообразных строк по различным разделителям и проверку работы всех реализованных методов в различных корректных и некорректных ситуациях.
 *
 * Author: iamm3chanic
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
class CString
 {
   private:
    int n;             //Размер начальной строки
    int m;             //Количество токенов
    char* str;         //содержательная часть
    char* div;
    CToken* t;
    CList2<CToken> tokList;
   public:
    CString (const CString&v) {CopyOnly(v);}
    CString()      { SetZero(); }
    CString(int num)   { n = num; m=0; str=new char[num]; memset(str,0, num*sizeof(char) ); div=new char[1]; for(int i=0;i<num;i++)tokList.GoToNext();}
    ~CString()    { Clean(); }
    CString(CString&& r) {n=r.n;m=r.m; tokList.CopyOnly(r.tokList); /*memcpy...*/ r.SetZero(); } 	//move constructor
    
    int getM() {int i; for(i=0;tokList.GoToNext();i++){}m=i+1;return m; }                    
    int getLength() { return n; } 
    char* getStr() {return str;}
    //CToken& getCheat() { return cheatCToken; }
    void setLength(int length) { n=length; for(int i=0;i<m;i++)tokList.GoToNext(); if(str!=NULL)delete[] str; str = new char[length];}   
    void SetS(char* s/*, int len*/){if(str!=NULL) {delete[]str;} str=new char[n];
    /*memcpy(str,s,5);*/ strncpy(str,s,n);}
    void SetTok(CToken *y){t=y;}
    CList2<CToken> &getList() { return tokList; }
    
    void SetZero(){ tokList.SetZero(); str=NULL; div=NULL; n=0;m=0;}
    void Clean() {if(div!=NULL){delete [] div;}  if(str){delete[] str;} 
    tokList.Clean(); SetZero();}
    void CopyOnly(const CString &v);
    
    CToken getTokByIndex(int index);
    void AutoSet();
    CString& operator=(const CString& v);  
    
    friend class CToken;
    friend CToken initialize(CString &s, char* d);
    friend CToken initialize(CString &s, char* d,int n);
    friend CToken* divide(CString &s, char* d);
    friend int Check(CString& dyn);
    friend ostream &operator<<(ostream& cout, CString &v);
    friend istream &operator>>(istream& cin, CString &v );
    friend char* getString();
  };
  char* getString();
  CToken getTok();
  char **init_b(char **blocks);
  void clean(char **blocks);
