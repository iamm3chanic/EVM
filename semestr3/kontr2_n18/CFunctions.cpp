#include "CString.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

CString CString::operator+(const CString&c)
{ 
 CString temp;
 temp.n=c.n+n;
 temp.s=new char[temp.n];
 memcpy( temp.s , s , n );
 memcpy( temp.s + n , c.s , c.n );
 return temp;
}
 
CStringTmp &CStringTmp::operator=(char c)
{
 if(i<0){throw -3;}
 if(i>=(*s).n)
  { 
   char *q=new char[i+1];
   memset(q,'*',i+1);
   memcpy(q,(*s).s,(*s).n);
   (*s).n=i+1;
   delete[] (*s).s;
   (*s).s=q;
  } 
 (*s).s[i]=c;
 return *this;
}

CStringTmp ::operator char()
{
 if (i<0) {throw -2;}
 if (i>=(*s).n) return 0;  
 return (*s).s[i];
}

///////////FRIEND FUNCTIONS

ostream &operator<<(ostream &cout, const CString &o){for (int i=0;i<o.n;i++) printf("%c",o.s[i]);;return cout;}

istream &operator>>(istream &cin, CString &o)
{
char *s; s=new char[5];
//string str;
for(int i=0;i<5;i++)
cin>>s[i];
memcpy(o.s,s,5*sizeof(char));
//o.SetS(str);
return cin;
}











