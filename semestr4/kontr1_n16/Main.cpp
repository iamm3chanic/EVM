
#include <iostream>
#include "fun.h"

using namespace std;


int main()
{
  try {
   cout << "test_0\n";
   CVector **glob_v; size_t val=0;
   glob_v= (CVector::Input("t.txt",&val));

   cout<<"global Number = "<<val<<endl;
   for(size_t i=0;(i<val);i++)  
   {
    (glob_v[i])->output("t.txt");
    delete glob_v[i];
   }
   
   delete[] glob_v;
  } catch(int err) {cout << "error=" <<err<<endl;} 
  
  try {
  cout << "test_1\n";
    int n;
    
    n=3;
    CVector0 v1=CVector0(n);
    CVector0 v2=CVector0(n);
    CVector1 v3=CVector1(n);
    CVector1 v4=CVector1(n);
    
    cout<< "Passed\n";
  
  
    } catch(int err) {cout << "error=" <<err<<endl;}
    try {
  cout << "test_2\n";
    int i; char c[15]="out_test.txt";
    CVector0 v1=CVector0(3);
    v1.setPos(0,15); v1.setPos(1,27); v1.setPos(2,34);
    v1.setText(c);
    CVector1 v2=CVector1(3);
    v2.setPos(0,1234); v2.setPos(1,2345); v2.setPos(2,3456);
    v2.setText(c);
    i = v1.output("t.txt");
    if(i==0){cout<< "Passed-0\n";}
    i = v2.output("t.txt");
    if(i==0){cout<< "Passed-1\n";}
    else cout<< "Error\n";
    } catch(int err) {cout << "error=" <<err<<endl;}
    
    try {
    cout << "test_3\n";
    int n=3;
    
    cout<<"For CVector0:\n";
    CVector0 v1(n), v2(n), sum(n), dif(n);
    v1.setPos(0,15); v1.setPos(1,27); v1.setPos(2,34);
    v2.setPos(0,1); v2.setPos(1,3); v2.setPos(2,5);

    cout << v1;
    cout << v2;
    
    sum=v1+v2;
    dif=v1-v2; 
    cout << "Скалярное произведение = " << v1*v2 << endl;
    cout << "Сумма    = " << sum ;
    cout << "Разность = " << v1-v2 ;
    
    cout<<"For CVector1:\n";
     CVector1 v3(n), v4(n),sum1(n),dif1(n);
    v3.setPos(0,123); v3.setPos(1,234); v3.setPos(2,345);
    v4.setPos(0,1); v4.setPos(1,3); v4.setPos(2,5);

    cout << v3;
    cout << v4;
    cout << "Скалярное произведение = " << v3*v4 << endl;
    
    sum1=v3+v4;
    cout << "Сумма    = " << sum1 ;
    dif1=v3-v4;
    cout << "Разность = " << v3-v4 ;

    } catch(int err) {cout << "error=" <<err<<endl;}
    
        return 0;
}
