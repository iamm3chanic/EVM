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
  cout << "\ntest1. Read from file & parse\n";
   CString str;
   cout<<str;
   str.fileRead("config.txt");
    cout << str;
    } catch(int err) {cout << "error=" <<err<<endl;}
}
void test2()
{
try{
  cout << "\ntest2. Read from file & get strings\n";
   CString str;
  // cout<<str;
   str.fileReadStrings("config.txt");
    cout << "Text of file:\n";
    for(int i=0;i<100;i++){if(str.GetA()[i])printf("%s", str.GetA()[i]);}
    } catch(int err) {cout << "error=" <<err<<endl;}
}
void test3() 
{
try{
  cout << "\ntest3. Get value by key\n";
   CString str;
   str.fileRead("config.txt");
    //cout << str;
    str.getList().GoToBegin();
    for (int i=0; str.getList().GoToNext(); i++)
    { 
     cout << i+1 <<") ";    
     cout << str.getList().GetCur();   
     }
   cout << "\n";
   str.getList().GoToBegin();
   for (int i=0; str.getList().GoToNext(); i++)
    { 
     cout << i+1 <<") ";    
     printf("key is '%s'",str.getList().GetCur().GetK()); //for test
     cout << "; value is "<<str.getList().GetCur().GetS();   
     }
   cout << "\n";
    } catch(int err) {cout << "error=" <<err<<endl;}
}
void test4()
{
try{
  cout << "\ntest4. operator=\n";
   CString str,g;
   str.fileRead("config.txt");
   g=str;
   for(int i=0;i<100;i++){if(g.GetA()[i])printf("%s", g.GetA()[i]);}

  //cout << g;
    } catch(...) {cout << "error" <<endl;}
}
void test5()
{
try{
  cout << "\ntest5. Get value by index\n";
   CString str;
   str.fileRead("config.txt");
   str.getList().GoToBegin();
   for (int i=0; str.getList().GetLen(); i++) {   
     cout<<str.getTokByIndex(i);  
     }
   cout << "\n";
    } catch(...) {cout << "error" <<endl;}
}
void test6() {
try{
  cout << "\ntest6. Quiet read from file & parse\n";
   CString str;
   str.fileReadQ("config.txt");
    cout << str;
    } catch(int err) {cout << "error=" <<err<<endl;}
}

void test7()
{
try{
  cout << "\ntest7. Read from file & change strings\n";
   CString str;
  // cout<<str;
   str.fileRead("config.txt");
   cout<<"CHANGING\n\n";
   str.changeStrings("config.txt");
    cout << "\nText of file:\n";
    for(int i=0;i<100;i++){if(str.GetA()[i])printf("%s", str.GetA()[i]);}
    } catch(int err) {cout << "error=" <<err<<endl;}
}
/////////////////no user input//////////////




//////////////////////////////////////////
int main()
{ 
 cout<<"Список тестов:\n";
 cout << "\ntest1. Read from file & parse";
 cout << "\ntest2. Read from file & get strings";
 cout << "\ntest3. Get value by key";
 cout << "\ntest4. operator=";
 cout << "\ntest5. Get value by index ";
 cout << "\ntest6. Quiet read from file & parse";
 cout << "\ntest7. Read from file & change strings";
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
 case 12: test1();test2();test3();test4();test5();test6();test7(); break;
 case 13: break;
   default: break;
 }    
 //test6();test1();test2();test3();test4();test7();
 clean(blocks);  
 delete [] tok_global;
 return 0;
}
