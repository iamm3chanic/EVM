/*18. Определить класс CString для работы со строками, длина ко-
торых хранится в самом классе (т.е. строки произвольных симовлов).
В классе должны быть определены необходимые конструкторы, опера-
торы присваивания, сложения (слияния строк), присваивания обычной
строки переменной типа CString.
В отдельном файле должен быть написан тест на данный класс.*/

#include <stdio.h>
#include <iostream>
#include <string.h>
#include "CString.h" 
using namespace std;
int main (void)
{
try
 {
 cout<<"\ntest1. cout\n";
 CString a("abc"),c,b("123");
 char x='r'; 
 cout<<"a="<<a<<endl;
 cout<<"b="<<b<<endl;
 c=a+b;
 cout<<"c=a+b= "<<c<<endl;
 cout<<"char x='"<<x<<"'"<<endl;
 x=a[2];
 cout<<"char x=a[2]="<<x<<endl;
 a[10]='v';
 cout<<"a=(after a[10]='v')= "<<a<<endl;

 }catch(int err){printf("error \n");}
 /*try
 {
 cout<<"\ntest2. cin\n";
 CString a("abc"),c,X,b("123");
 char x='r'; 
 cout<<"Введите строку Х: ";
 cin>>X;
 cout<<"X="<<X<<endl;

 }catch(int err){printf("error \n");}*/
  return 0;
}
