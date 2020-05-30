#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "fun.h"

int main(void)
{
 int err=0;
 char word[512];
 err=search("data.dat", word);
 if(err==0) printf("'%s'", word);
 return err;
}