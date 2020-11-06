/*
  CString.h
 Задание 1.20. Загрузка config-файла с предобработкой.
Пусть имеется конфигурационный файл, в котором комментарии задаются от 
символа # до конца строки, а содержательные строки имеют вид
 имя = значение
Имя параметра не содержит пробелов и знака =, значение - это оставшаяся 
часть строки после знака равенства, исключая пробельные символы в начале и конце. 
При этом, если в значении последующих строк встретится выражение $имя$, то его
следует заменить на значение. Например,
раr1 = асе  
раr2 = 123$раr1$456 заменяется на раr2 = 123асе456
Реализация класcа должна поддерживать следующие возможности:

+загрузка параметров из указанного config-файла;
+получение строк с диагностикой возможных ошибок при разборе входного файла;
+получение развернутой строки-значения, соответствующей имени параметра;
+объединение с множеством параметров, хранящихся в другом аналогичном классе.

Формальное определение интерфейса не задается и должно быть разработано студентом.
Тесты должны включать заполнение множества параметров из некоторых файлов и проверку работы всех реализованных
методов в различных корректных и некорректных ситуациях.
 *
 * Author: iamm3chanic
 */
#pragma once
#include <iostream>
#include <math.h>
#include <string.h>
#include <cstdlib>
#include "CList2.h"
using namespace std;
//--------------------------------------------------------------
//----------- Определение класса -------------------------------
//--------------------------------------------------------------
class CString
 {
   private:
    int m;             //Размер начальной строки
    int n;             //Количество строк
    char* str;         //содержательная часть
    char** all;
    CToken* t;
    CList2<CToken> tokList;
    CList2<CToken> strList; //ради удобства тот же тип, что и параметры
   public:
    CString (const CString&v) {CopyOnly(v);}
    CString()      { SetZero();  
    all=new char*[100]; for (int i=0; i<100; i++) {all[i] = new char [256];memset(all[i],0, sizeof(char)*256);} 
    str=new char[1];memset(str,0,sizeof(char) );}
    CString(int num)   { n = num; m=0; str=new char[num]; memset(str,0, num*sizeof(char) ); all = new char*[100]; for (int i = 0; i < 100; i++)  {all[i] = new char [256]; memset(all[i],0, 256*sizeof(char));}  for(int i=0;i<num;i++)tokList.GoToNext(); for(int i=0;i<num;i++)strList.GoToNext();}
    ~CString()    { Clean(); /*cout<<"\nDESTRUCT\n";*/}
    CString(CString&& r) {n=r.n;m=r.m; tokList.CopyOnly(r.tokList); strList.CopyOnly(r.strList); r.SetZero(); } 	//move constructor
    
    int getM() {int i;tokList.GoToBegin(); for(i=0;tokList.GoToNext();i++){}m=i+1;return m; }                    
    int getLength() { return n; } 
    char* getStr() {return str;}
    char** GetA() {return all;}
    void setLength(int length) { n=length; for(int i=0;i<m;i++)strList.GoToNext(); if(str!=NULL)delete[] str; str = new char[length];}   
    void SetS(char* s/*, int len*/)/*{if(str!=NULL)*/ {delete[]str; str=new char[n];
    /*memcpy(str,s,5);*/ strncpy(str,s,n);}
    void SetTok(CToken *y){t=y;}
    void SetA(char **a) {for (int i=0; i<100; i++) {if(a[i])memcpy(all[i],a[i],strlen(a[i]));}}
    CList2<CToken> &getList() { return tokList; }
    CList2<CToken> &getListS() { return strList; }
    void fileRead(const char *fn);
    void fileReadQ(const char *fn);
    void fileReadStrings(const char *fn);
    void initialize();
    void changeStrings(const char *fn);
    
    void SetZero(){ tokList.SetZero();strList.SetZero(); str=NULL; all=NULL; n=0;m=0;}
    void Clean() {for (int i=0; i<100; i++) 
    {/*if(all[i])*/delete [] all[i];}
     delete []all;  /*if(str)*/delete[] str; 
     strList.Clean();
    tokList.Clean(); SetZero();}
    void CopyOnly(const CString &v);
    
    CToken getTokByIndex(int index);
    void AutoSet();
    CString& operator=(const CString& v);  
    
    friend class CToken;
    friend ostream &operator<<(ostream& cout, CString &v);
    friend istream &operator>>(istream& cin, CString &v );
    friend char* getString();
    friend CString fileRead(const char *fn);
  };
  char* getString();
  CToken getTok();
  char **init_b(char **blocks);
  void clean(char **blocks);
  CString fileRead(const char *fn);
