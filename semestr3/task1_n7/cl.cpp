#include <stdio.h>
#include <stdlib.h>
#include "cl.h"
#include "cd.h"
using namespace std;

int main(void)
{
 int m=7,g=10;
 Mass l(m);
 for(int i=0;i<l.GetLen();i++){l.AddToEnd(g);}
 //cout<<l; 
 return 0;
}