/*
 * Main.cpp
 * Тест можно проводить на разном количестве входных данных. 
 */
#include <iostream>
#include "CVector.h"

using namespace std;


int main()
{
  try {
   cout << "test0. Parallel Test\n";
   
   CVector::OMPTest("input2.txt");
   
  } catch(int err) {cout << "error=" <<err<<endl;} 
  
    
        return 0;
}
