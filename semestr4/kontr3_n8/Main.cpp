/*
 * Main.cpp
 */
#include <iostream>
#include "CVektor.h"

using namespace std;


int main()
{
  try {
   cout << "test0. Input + output\n";
vector<CFabricVektor*> fabric;
vector<CVektor*> v;
   //HERE WERE LEAKAGE
   fabric.push_back(new CFabricVektor0);
   fabric.push_back(new CFabricVektor1);
   
   CVektor::Input("input.txt", v, fabric);
   CVektor::ParallelTest(v);
   cout<<"global Number = "<<v.size()<<endl;
   for(size_t i=0;(i<v.size());++i)  
   {
   // v[i]->output("input.txt");
    //v[i]->ShowVektor();
   }
    for(size_t i=0;(i<v.size());i++)  {delete v[i];}
    for(size_t i=0;(i<fabric.size());i++)  {delete fabric[i];}
   //delete &fabric;
  // delete[] glob_v;
  } catch(...) {cout << "error\n" <<endl;} 
  
 
        return 0;
}
