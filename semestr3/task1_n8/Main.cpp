/*
 * Main.cpp
 */
#include <iostream>
#include "CDynamic.h"

using namespace std;

void test1() 
{
try{
  cout << "\ntest1. Create arrays of fix dimensions\n";
   //int nreal;
   CDynamic dyn=CDynamic(3);
   //Arr a;
   //CDynamic dyn;
   cout << "Размер массива: 3." << endl;
    cin >> dyn;
    cout << dyn;
    } catch(int err) {cout << "error=" <<err<<endl;}
}
void test2()
{
try{
  cout << "\ntest2. Add arrays\n";
   int nreal;
  // CDynamic dyn=CDynamic(3);
   Arr a;
   CDynamic dyn;
   cout << "Введите размер массива: " ;
   cin >> nreal;
   dyn.setLength(nreal);
    cin >> dyn;
    cout << dyn;
   
   cout << "Введите размер массива Arr: " ;
    cin >> nreal;
    a.SetN(nreal);
    cin >> a;
    cout << a; //works super!
    } catch(int err) {cout << "error=" <<err<<endl;}
}
void test3()
{
try{
  cout << "\ntest3. Method InputTo(int k, double d)\nЗамена.\n";
  cout << "\nДля удобства нумерация с единицы!\n";
   int nreal,k; double d;
   CDynamic dyn;
   cout << "Введите размер массива: " ;
   cin >> nreal;
   dyn.setLength(nreal);
    cin >> dyn;
    cout << dyn;
    
     cout << "Введите место вставки эл-та: " ;
     cin >> k;
     cout << "Введите вставляемый элемент: " ;
     cin >> d;
     dyn.InputTo(k,d);
     cout << dyn;
    } catch(int err) {cout << "error=" <<err<<endl;}
}
void test4()
{
try{
  cout << "\ntest4. Method InputInto(int k, double d)\nДобавление.\n";
  cout << "\nДля удобства нумерация с единицы!\n";
   int nreal,k; double d;
   CDynamic dyn;
   cout << "Введите размер массива: " ;
   cin >> nreal;
   dyn.setLength(nreal);
    cin >> dyn;
    cout << dyn;
    
     cout << "Введите место вставки эл-та: " ;
     cin >> k;
     cout << "Введите вставляемый элемент: " ;
     cin >> d;
     dyn.InputInto(k,d);
     cout << dyn;
    } catch(int err) {cout << "error=" <<err<<endl;}
}
void test5()
{
try{
  cout << "\ntest5. SortUp\n";
  int nreal; 
   CDynamic dyn;
   cout << "Введите размер массива: " ;
   cin >> nreal;
   dyn.setLength(nreal);
    cin >> dyn;
    cout << dyn;
    SortUp(dyn);
    Check(dyn);

    } catch(int err) {cout << "error=" <<err<<endl;}
}
void test6()
{

}
void test7()
{
    try{
  cout << "\ntest7. AutoSet + Sort\n";
  char c;
  cout << "Press any key to continue . . .\n";
      cin>>c;
   CDynamic dyn;
   dyn.AutoSet();
   SortUp(dyn);
    } catch(int err) {cout << "error=" <<err<<endl;}
}
void test8()
{
 try{
  cout << "\ntest8. AutoSet + Sort + BinSearch\n";
   int left,right;
   CDynamic dyn;
   dyn.AutoSet();
   SortUp(dyn);
   cout<<"Введите нижнюю границу поиска: ";
   cin>>left;
   cout<<"Введите верхнюю границу поиска: ";
   cin>>right;
   BinSearch(dyn, left, right);
    } catch(int err) {cout << "error=" <<err<<endl;}
}
void test9()
{
try{
  cout << "\ntest9. GetNumByIndex(int index) \n";
  int n; double d;
   CDynamic dyn;
   dyn.AutoSet();
    cout << dyn;
    cout<<"Введите номер индекса: " ;
    cin >> n;
    d=dyn.GetNumByIndex(n);
    cout <<"\nНомер по индексу: "<<d<<endl;
    } catch(int err) {cout << "error=" <<err<<endl;}
}
void test10()
{
try{
  cout << "\ntest10. AddToEnd(double d) \n";
   double d;
   CDynamic dyn;
   dyn.AutoSet();
    cout << dyn;
    cout<<"Введите добавляемый элемент: " ;
    cin >> d;
    dyn.AddToEnd(d);
    cout << dyn;
    } catch(int err) {cout << "error=" <<err<<endl;}
}
void test11()
{
try{
  cout << "\ntest11. DelNumByIndex(int index) \n";
   int i;
   CDynamic dyn;
   dyn.AutoSet();
    cout << dyn;
    cout<<"Введите индекс удаляемого элемента: " ;
    cin >> i;
    dyn.DelNumByIndex(i);
    cout << dyn;
    } catch(int err) {cout << "error=" <<err<<endl;}
}
///////////////////////////////////////////
int main()
{ 
  int var;
 cout<<"Список тестов:\n";
 cout << "\ntest1. Create arrays of fix dimensions\n";
 cout << "\ntest2. Add arrays\n";
 cout << "\ntest3. Method InputTo(int k, double d)\nЗамена.\n";
 cout << "\ntest4. Method InputInto(int k, double d)\nДобавление.\n";
 cout << "\ntest5. SortUp\n";
 
 cout << "\ntest7. AutoSet + Sort\n";
 cout << "\ntest8. AutoSet + Sort + BinSearch\n";
 cout << "\ntest9. GetNumByIndex(int index) \n";
 cout << "\ntest10. AddToEnd(double d) \n";
 cout << "\ntest11. DelNumByIndex(int index) \n";
 cout << "\ntest12. Все сразу! \n";
 cout << "\ntest13. Выйти \n";
 cout<<"Введите номер теста:";
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
 case 9: test9(); break;
 case 10: test10(); break;
 case 11: test11(); break;
 case 12: test1();test2();test3();test4();test5();test6();test7();test8();test9();test10();test11(); break;
 case 13: break;
   default: break;
 }      
      
 return 0;
}
