#include<iostream>
#include"CClass.h"
using namespace std;

int main (void)
{
try {
cout <<"test1. declaration"<<endl;
CDist a, b, x(1,1), y(4,3), z(1,1);
Cpoint c,d, r(-2,1);
cout <<"вектор a="<<a<<endl;
cout <<"вектор x="<<x<<endl;
cout <<"точка c="<<c<<endl;
cout <<"точка r="<<r<<endl;
} catch (int err) {cout << "error=" <<err<<endl;}
try {
cout <<"test2. input/output"<<endl;
CDist a, b, x(1,1), y(4,3), z(1,1);
Cpoint c,d, r(-2,1);
cout<<"input Cpoint c"<<endl;
cin>>c;
cout<<"c="<<c<<endl;
cout<<"input CDist z"<<endl;
cin>>z;
cout<<"z="<<z<<endl;
} catch (int err) {cout << "error=" <<err<<endl;}
try {
cout <<"test3. summing"<<endl;
CDist a, b, x(1,1), y(4,3), z(1,1);
Cpoint c,d, r(-2,1);
cout<<"point+point"<<endl;
cout <<"вектор x="<<x<<endl;
cout <<"вектор y="<<y<<endl;
a=x+y;
cout <<"x+y=" <<a<<endl;
cout<<"input Cpoint c"<<endl;
cin>>c;
cout<<"c="<<c<<endl;
cout<<"input CDist z"<<endl;
cin>>z;
cout<<"z="<<z<<endl;
d=c;
cout<<"c=c+z (point+vector)"<<endl;
c=c+z; 
cout<<"c="<<c<<endl;

cout<<"c=z+c (vector+point)"<<endl;
d=z+d; 
cout<<"c="<<d<<endl;

} catch (int err) {cout << "error=" <<err<<endl;}
try {
cout <<"test4. minus, multiply, equal"<<endl;
CDist a, b, g,x(1,1), y(4,3), z(1,1);
Cpoint c,d, r(-2,1);
cout <<"вектор y="<<y<<endl;
b=5*y;
cout<<"5*y="<<b<<endl;
b=y*5;
cout<<"y*5="<<b<<endl;

cout<<"input Cpoint c"<<endl;
cin>>c;
cout<<"c="<<c<<endl;

cout<<"b=c-r (vector=point-point)\n"<<endl; // точка-точка = вектор
cout<<"g=r-c (vector=point-point)\n"<<"c="<<c<<" \nr="<<r<<endl; 
b=c-r;
g=r-c;
cout<<"b=c-r= " << b <<endl;
cout<<"g=r-c= " << g << endl;
} catch (int err) {cout << "error=" <<err<<endl;}
return 0;
}
