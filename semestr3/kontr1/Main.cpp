/* main.cpp */
#include <iostream>
#include "CVektor.h"

using namespace std;
int main()
{
 try {
    CVektor v1(DIMENSION), v2(DIMENSION), sum(DIMENSION), dif(DIMENSION);
    v1.GetVektor();
    v2.GetVektor();
 
    cout << "Скалярное произведение: " << Skalar(&v1, &v2) << endl;
    v1.ShowVektor();
    v2.ShowVektor();
  
    Kommutativ(&v1, &v2);
    Netativ(&v1, &v2);

    return 0;
    } catch(int err) {cout << "error=" <<err<<endl;}
}
