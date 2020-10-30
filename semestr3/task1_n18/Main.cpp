/*
 * Main.cpp
 *
 * Author: iamm3chanic
 */
#include <iostream>
#include "CString.h"

using namespace std;

//extern ones:
char **blocks = init_b(blocks);
int BLOCK_FLAG = 0;
CToken* tok_global = new CToken[100];
int T_FLAG = 0;


void test1() 
{
try{
  cout << "\ntest1. Create strings of fix dimensions\n";
   //int nreal;
   CString str=CString(3);
   //CToken a;
   //CString str;
   cout << "Размер строки: 3." << endl;
   cout << "Введите CString: " ;
    cin >> str;
    cout << str;
    } catch(int err) {cout << "error=" <<err<<endl;}
}
void test2()
{
try{
  cout << "\ntest2. Create strings/tokens of any dimensions\n";
  // int nreal;
  // CString str=CString(3);
   CToken a;
  /* CString str;
   cout << "Введите  CString: " ;
    cin >> str;
    cout << str;*/
   //после ввода строки, в следующем вводе съедается первый символ !
   //BUG
   cout << "Введите CToken: " ;

    cin >> a;
    cout << a; 
    } catch(int err) {cout << "error=" <<err<<endl;}
}
void test3()
{
try{
  cout << "\ntest3. Initialize tokenizer\n";
  CString s; char* div;
  CToken t;
  cout << "Введите CString: " ;
    cin >> s;
    cout << s;
  cout<<"Введите division: ";
  div=getString();
  t=initialize(s,div);
  divide(s,div);
 // cout<<"one more way to divide, for test: \n";
 // divide(s,t.GetS());
    } catch(int err) {cout << "error=" <<err<<endl;}
}
void test4()
{
try{
  cout << "\ntest4. operator=\n";
   CString str,g;
   str.AutoSet();
   g=str;
  cout << g;
    } catch(...) {cout << "error" <<endl;}
}
void test5()
{
try{
  cout << "\ntest5. GetTokByIndex(int index) \n";
  CString s; char* div; int n;
  CToken t,*y,d;
  cout << "Введите CString: " ;
    cin >> s;
    cout << s;
  cout<<"Введите division: ";
  div=getString();
  t=initialize(s,div);
  divide(s,div);
  y=divide(s,div);
    cout<<"Введите номер индекса: " ;
    cin >> n;
    s.SetTok(y);
    d=s.getTokByIndex(n);
    } catch(int err) {cout << "error=" <<err<<endl;}
}
void test6()
{
try{
  cout << "\ntest6. getM - получить общее количество токенов\n";
   CString str;
   char *div;
   CToken t;
   int h;
   str.AutoSet();
    h=str.getM();
   cout<<"Общее количество токенов: "<<h<<endl;
   cout<<"Введите division: ";
  //div=getString();
  t=getTok();
  div=t.GetS();
  //t=initialize(str,div);
  divide(str,div);
   h=str.getM();
   cout<<"Общее количество токенов: "<<h<<endl;
    } catch(...) {cout << "error" <<endl;}
}
void test7()
{
    try{
  cout << "\ntest7. Change tokens\n";
  CString str;
   char *div;
   CToken t;
   str.AutoSet();  
   cout<<"Введите division: ";
  //div=getString();
  t=getTok();
  div=t.GetS();
  t=initialize(str,div);
  divide(str,div);
   cout<<"Now one more time!\n"<<str;
   cout<<"Введите division: ";
  //div=getString();
  t=getTok();
  div=t.GetS();
  t=initialize(str,div);
  divide(str,div);
    } catch(int err) {cout << "error=" <<err<<endl;}
}
void test8()
{
 try{
  cout << "\ntest8. Iterator watcher\n";
  CString str;
   char *div;
   CToken t;
   str.AutoSet();  
   cout<<"Введите division: ";
  //div=getString();
  t=getTok();
  div=t.GetS();
  t=initialize(str,div);
  divide(str,div);
  
  for(int i=0;str.getList().GoToNext();i++) {cout<<i<<". "<<str.getList().GetCur();}
 
    } catch(int err) {cout << "error=" <<err<<endl;}
}
void test9()
{
try{
  cout << "\ntest9. GetTokByIndex(int index) \n";
  int n; CToken d,t,*y;
  char *div;
   CString str;
   str.AutoSet();
    cout << str;
    cout<<"Введите division: ";
  t=getTok();
  div=t.GetS();
  d=initialize(str,div);
  y=divide(str,div);
    cout<<"Введите номер индекса: " ;
    cin >> n;
    str.SetTok(y);
    d=str.getTokByIndex(n);
   // cout <<"\nНомер по индексу: "<<d<<endl;
    } catch(int err) {cout << "error=" <<err<<endl;}
}
/////////////////no user input//////////////
void test10()
{
try{
  cout << "\n\ntest10. Create strings/tokens of fix dimensions\n";
   CString str=CString(3);
   CToken a(3);
   char c[3];
   memcpy(c,"abc",3);
   cout << "Размер строки: 3.\n Пустые:" << endl;
   cout<<str<<a;
   str.SetS(c);
   a.SetS(c);
   cout << "Непустые:" << endl;
    cout << str<<a;
    //delete[] c;
    } catch(int err) {cout << "error=" <<err<<endl;}
}
void test11()
{
try{
  cout << "\ntest11. Initialize tokenizer\n";
  CString s; 
  char div[3];//blocks[BLOCK_FLAG++];
  memcpy(div,"abc",3);
  CToken t;
  char c[13];
  memcpy(c,"abjcbeaeobcda",13);
  s.setLength(13);
  s.SetS(c);
  cout << s;
  cout<<"Division: ";
  for(int i=0;i<3;i++){cout<<div[i];}; cout<<endl;

  t=initialize(s,div,3);
  divide(s,div);
  //cout<<"one more way to divide, for test: \n";
  //divide(s,t.GetS());
  //delete[]c; //if(div!=NULL)delete[] div;
    } catch(int err) {cout << "error=" <<err<<endl;}
}
void test12()
{
try{
  cout << "\ntest12. operator=\n";
   CString str,g;
   str.AutoSet();
   g=str;
  cout << g;
    } catch(...) {cout << "error" <<endl;}
}
void test13()
{
try{
  cout << "\ntest13. GetTokByIndex(int index) \n";
  int n; CToken d,t,*y;
  char div[3];//blocks[BLOCK_FLAG++];
  memcpy(div,"abc",3);
  cout<<"Division: ";
  for(int i=0;i<3;i++){cout<<div[i];}; cout<<endl;
   CString str;
   str.AutoSet();
    cout << str;
    //cout<<"Введите division: ";
    t.SetS(div);
 // t=getTok();
 //div=t.GetS();
  d=initialize(str,div);
  divide(str,div);
  y=divide(str,div);
    //cout<<"Введите номер индекса: " ;
    //cin >> n;
    cout<<"Hомер индекса: 2\n" ;
    n=2;
    str.SetTok(y);
    d=str.getTokByIndex(n);
   // delete[] div;
    } catch(int err) {cout << "error=" <<err<<endl;}
  }  
void test14()
{
try{
  cout << "\ntest14. getM - получить общее количество токенов\n";
   CString str;
   char div[3];
   memcpy(div,"abc",3);
   cout<<"Division: ";
  for(int i=0;i<3;i++){cout<<div[i];}; cout<<endl;
   CToken t;
   int h;
   str.AutoSet();
    h=str.getM();
   cout<<"Общее количество токенов: "<<h<<endl;
   //cout<<"Введите division: ";
  //div=getString();
  t.SetS(div);
  //t=initialize(str,div);
  divide(str,div);
   h=str.getM();
   cout<<"Общее количество токенов: "<<h<<endl;
    } catch(...) {cout << "error" <<endl;}
}
void test15()
{
    try{
  cout << "\ntest15. Change tokens\n";
  CString str;
   char div[3],div1[3];
   //div= new char[3]; div1= new char[3];
   memcpy(div,"abc",3);memcpy(div1,"tre",3);
   CToken t;
   str.AutoSet();  
   t.SetS(div);
 cout<<"Division1: ";
  for(int i=0;i<3;i++){cout<<div[i];}; cout<<endl;
  t=initialize(str,div);
  divide(str,div);
   cout<<"\nNow one more time!\n"<<str;
   t.SetS(div1);
   cout<<"Division2: ";
  for(int i=0;i<3;i++){cout<<div1[i];}; cout<<endl;
  t=initialize(str,div1);
  divide(str,div1);
    } catch(int err) {cout << "error=" <<err<<endl;}
}
void test16()
{
 try{
  cout << "\ntest16. Iterator watcher\n";
  CString str;
   char div[3];
   memcpy(div,"abc",3);
   cout<<"Division: ";
  for(int i=0;i<3;i++){cout<<div[i];}; cout<<endl;
   CToken t;
   str.AutoSet();
   t.SetN(3);  
   t.SetS(div);
  
  t=initialize(str,div);
  divide(str,div);
  
  for(int i=0;str.getList().GoToNext();i++) {cout<<i<<". "<<str.getList().GetCur();}
 
    } catch(int err) {cout << "error=" <<err<<endl;}
}
//////////////////////////////////////////
int main()
{ 
 cout<<"Список тестов:\n";
 cout << "\ntest1. Create strings of fix dimensions";
 cout << "\ntest2. Create tokens of any dimensions";
 cout << "\ntest3. Initialize tokenizer";
 cout << "\ntest4. AutoSet + operator=";
 cout << "\ntest5. GetTokByIndex(int index) ";
 cout << "\ntest6. Get quantity of tokens";
 cout << "\ntest7. Change tokens";
 cout << "\ntest8. Iterator-watcher";
 cout << "\ntest9. GetTokByIndex(int index) + Autoset"; 
 cout << "\ntest12. Все сразу \n";
 cout << "\ntest13. Выйти \n";
 cout<<"Введите номер теста:";
 int var;
 cin>> var;
 switch (var) {
 case 1: test1(); break;
 case 2: test2(); break;
 case 3: test3(); break;
 case 4: test4(); break;
 case 5: test5(); break;
 case 6: test6(); break;
 case 7: test7(); break;
 case 8: test8(); break;
 case 12: test1();test2();test3();test4();test5();test6();test7();test8();test9();test10(); break;
 case 13: break;
   default: break;
 }    
 test1();test2();test3();test4();test5();test6();test7();test8();test9();
 test10();test11();test12();test13();test14();test15();test16();
 clean(blocks);  
 delete [] tok_global;
 return 0;
}
