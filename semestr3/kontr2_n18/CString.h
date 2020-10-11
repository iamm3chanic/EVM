#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
class CString;

class CStringTmp
{
 int i;
 CString *s;
 public:
 CStringTmp (CString *s,int i){this->s=s;this->i=i;} 
 CStringTmp &operator=(char c);
 operator char();
};

class CString
{
 int n; char *s;
 public:
 CString(){SetZero();}
 ~CString(){Clean();}
 CString(const CString&o){CopyOnly(o);}
 CString operator+(const CString&o);
 CString &operator=(const CString&o){if (this!=&o){Clean();CopyOnly(o);} return *this;}
 void Clean(){delete[] s; SetZero();}
 void SetZero(){s=NULL;n=0;}
 void CopyOnly(const CString&o){n=o.n;s=new char[n];memcpy(s,o.s,n);}
 void SetS(string str){for(long unsigned int i=0;i<str.length();i++) s[i]=str.at(i);}
 operator const char*()const{return s;} 
 CString(const char*o){n=strlen(o);s=new char[n];memcpy(s,o,n);} // CString= *char
 void print()const {for (int i=0;i<n;i++) printf("%c",s[i]);} 
 int length()const{return n;}
 char *str(){return s;}
 CStringTmp operator[](int i){if (i<0){throw -1;} return CStringTmp(this,i);} 
 
 friend ostream &operator<<(ostream &cout,const CString&o); 
 friend istream &operator>>(istream &cin, CString &o);
 friend class CStringTmp; 
};
/*
ostream &operator<<(ostream &cout, const CString &o){o.print();return cout;} ;
CString CString::operator+(const CString&o);
CStringTmp ::operator char();
CStringTmp &CStringTmp::operator=(char c); */

