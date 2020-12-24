/*
Написать функцию double Deg2N(double x,int n); умножающую число х типа double 
на множитель 2^n, использующую только сложение степени в представлении числа с числом n.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <math.h>

union LDC {
    double     ld;
    char   uc[sizeof(double)];
    char   cool[sizeof(double)][8];
};

void showDouble(double d);
double Deg2N(double d,int n);
void print_bin( union LDC ldc );

void showDouble(double d)
{
    int i =0;
    while (d*d > 100) //сравниваем квадрат(d), чтобы учесть отрицательные числа
    {
        d/= 10;
        i++;
    }
    printf("\nmantissa in 10ic sys= %f\n", d);
    printf("poriadok in 10ic sys= %d\n", i);
}
        
double Deg2N(double d,int n)
{
 int i =0; //double k;
    while (d*d > 4) 
    {d/= 2;i++;}
    printf("mantissa in 2ic sys= %f\nporiadok in 2ic sys= %d\n", d,i);
  i+=n;
  printf("i= %d\n", i);
  for(int j=0;j<i;j++) {d*=2; /*printf("d= %f\n", d);*/}
  //k=d;
 //adequate one
 //for(int i=0;i<n;i++) d*=2; 
 return d;
}

 
void print_bin( union LDC ldc )
{
    unsigned char c;
    long unsigned int i, j;
    printf("The number in bytes:\n");
        for ( i = 0; i < /*sizeof( ldc )*/8; ++i ) {
        c = ldc.uc[i];
        for ( j = 0; j < 8; ++j ) {
            printf("%d", (c & 1));
            c >>= 1;
        }
        printf(" ");
    }
    printf("\nThe number in bytes (for cool):\n");
        for ( i = 0; i < /*sizeof( ldc )*/8; ++i ) {
        for ( j = 0; j < 8; ++j ) {
            c = ldc.cool[i][j];
            printf("%d", (c & 1));
            c >>= 1;
        }
        printf(" ");
    }
    printf("\nMoving it:\n");
        //for ( i = 0; i < 5; ++i ) {ldc.uc[i] = ldc.uc[i+1];}
        //очень грубо!
        for ( j = 0; j < 8; ++j ) {
        for ( i = 0; i < 5; ++i ) {
         if(i<8-5) ldc.cool[j][i] = ldc.cool[j][i+1];
         else ldc.cool[j][8-i] = ldc.cool[j+1][i];
        }
        }
        for ( i = 0; i < /*sizeof( ldc )*/8; ++i ) {
        for ( j = 0; j < 8; ++j ) {
            c = ldc.cool[i][j];
            printf("%d", (c & 1));
            c >>= 1;
        }
        printf(" ");
    }
         /*for ( i = 0; i < 8; ++i ) {
        c = ldc.uc[i];
        for ( j = 0; j < 8; ++j ) {
            printf("%d", (c & 1));
            c >>= 1;
        }
        printf(" ");
    }*/
    printf("\n");
}

int main(void)
{ 
printf("size of double=%ld\n", sizeof(double));
  union LDC ldc;
    ldc.ld = 15.375;
    print_bin( ldc );
 

 double x=410.38; 
 showDouble(x);
 //Deg2N(x,5);
 printf("%f\n",Deg2N(x,5));
 return 0;
}

















