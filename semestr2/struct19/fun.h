#ifndef __FUN_H__
#define __FUN_H__
#include "str.h"
int input1(const char *fn, SStudent ***s, int *n);
int output1(const char *fn, SStudent **s, int n);
void output2(SStudent **s, int m);
void sort(SStudent **s, int n);
void edit(SStudent **s,SStudent ***neww, int n, int *m);
#endif
