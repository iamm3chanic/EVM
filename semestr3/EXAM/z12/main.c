/*
Написать программу на языке С, которая транспонирует изображение. Заголовок BMP-файла можно взять из файла bmp.h 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp.h"

//предопределили функции
BMPHEAD *Input(const char *sf);
int Output(const char *sf, BMPHEAD *h);
unsigned int ui(unsigned int c);
BMPHEAD *Edit(BMPHEAD *h);

//ввод
BMPHEAD *Input(const char *sf)
{
 FILE *f;
 BMPHEAD *h=NULL;
 int lb=102,j,ls; long unsigned int i;
 char c,*s=NULL;
 //метка lb
 lb=(int)(((char*)&(h->pal)) - ((char*)&(h->Signature)));
 printf("lb=%d (==54)\n", lb);
 f=fopen(sf,"rb"); if(f==NULL)return NULL;
 //мссив пикселей
 h=(BMPHEAD*)malloc(sizeof(*h));
 if(fread(h, 102,1,f)!=1)
 {free(h); return NULL;}
 printf("width=%ld; height=%ld\n",h->Width, h->Height);
 for(i=0;i<h->Ptr-102;i++) fread(&c,1,1,f);
 h->v=NULL;
 h->g=NULL;
 printf("BitsForPixel=%d \n", h->BitsPerPixel);
 //2 случая с разным количеством бит/пикс
 if(h->BitsPerPixel==24)
 {
 ls=h->SizeImage/h->Height;
 s=(char*)malloc(ls);
 h->v=(unsigned char(**)[4])malloc(h->Height*sizeof(void*)+h->Height+h->Width*4);
 h->v[0]=(unsigned char (*)[4])(h->v+h->Height);
 for(i=1;i<h->Height;i++)h->v[i]=h->v[i-1]+h->Width;
 for(i=0;i<h->Height;i++)
 {
  fread(s,1,ls,f);
  for(j=0;i<h->Width;j++){
  h->v[i][j][0]=s[j*3+2];
  h->v[i][j][1]=s[j*3+1];
  h->v[i][j][2]=s[j*3+0];}
 }
 }
 if(h->BitsPerPixel==32)
 {
 ls=h->SizeImage/h->Height;
 s=(char*)malloc(ls);
 h->v=(unsigned char(**)[4])malloc(h->Height*sizeof(void*)+h->Height+h->Width*4);
 h->v[0]=(unsigned char (*)[4])(h->v+h->Height);
 for(i=1;i<h->Height;i++)h->v[i]=h->v[i-1]+h->Width;
 for(i=0;i<h->Height;i++)
 {
  fread(s,1,ls,f);
  for(j=0;i<h->Width;j++){
  h->v[i][j][0]=s[j*4+2];
  h->v[i][j][1]=s[j*4+1];
  h->v[i][j][2]=s[j*4+0];}
 }
 }
 else{printf("Invalid value of BitsPerPixel...\n");}
 free(s);
 fclose(f);
 return h;
}

int Output(const char *sf, BMPHEAD *h)
{
 FILE *f;
 int lb=102,ls;  long unsigned int i,j;
 char c,*s=NULL;
 lb=(int)(((char*)&(h->pal)) - ((char*)&(h->Signature)));
 printf("lb=%d (==54)\n", lb);
 f=fopen(sf,"wb"); if(f==NULL)return -2;
 //h=(BMPHEAD*)malloc(sizeof(*h));
 if(fwrite(h, 102,1,f)!=1){/*free(h);*/ return -1;}
 for(i=0;i<h->Ptr-102;i++) fwrite(&c,1,1,f);
 ls=h->SizeImage/h->Height;
 s=(char*)malloc(ls);
 printf("BitsForPixel=%d \n", h->BitsPerPixel);
 if(h->BitsPerPixel==24)
 {
 for(i=0;i<h->Height;i++)
 {
  for(j=0;i<h->Width;j++){
  s[j*3+2]=h->v[i][j][0];
  s[j*3+1]=h->v[i][j][1];
  s[j*3+0]=h->v[i][j][2];}
  fwrite(s,1,ls,f);
 }
 }
 if(h->BitsPerPixel==32)
 {
 for(i=0;i<h->Height;i++)
 {
  for(j=0;i<h->Width;j++){
  s[j*4+2]=h->v[i][j][0];
  s[j*4+1]=h->v[i][j][1];
  s[j*4+0]=h->v[i][j][2];}
  fwrite(s,1,ls,f);
 }
 }
  if(h->BitsPerPixel==8) //grey
 {
 ls=h->SizeImage/h->Height;
 s=(char*)malloc(ls);
 for(i=0;i<h->Height;i++)
 {
  for(j=0;i<h->Width;j++){
  fwrite(s,1,ls,f);}
  /*h->g[i][j][0]=s[j*4+2];
  h->g[i][j][1]=s[j*4+1];
  h->g[i][j][2]=s[j*4+0];}*/
 }
 }
 else{printf("Invalid value of BitsPerPixel...\n");}
 free(s);
 fclose(f);
 return 0;
}

BMPHEAD *Edit(BMPHEAD *h)
{
//TODO: add header for *b
//создаем такую же стпуктуру по размеру
 int lb=102,ls,t;  long unsigned int i,j;
 char *s=NULL;
 lb=(int)(((char*)&(h->pal)) - ((char*)&(h->Signature)));
 lb=lb;
BMPHEAD *b;
b=(BMPHEAD*)malloc(sizeof(*b));
b->Width=h->Width; b->Height=h->Height;
 printf("width=%ld; height=%ld\n",b->Width, b->Height);
 //for(i=0;i<b->Ptr-102;i++) fread(&c,1,1,f);
 b->v=NULL;
 b->g=NULL;
 printf("BitsForPixel for second Image=%d \n", b->BitsPerPixel);
if(h->BitsPerPixel==24)
 {
 ls=(b->SizeImage*b->Height*b->Width)/(b->Height);
 s=(char*)malloc(ls);
 b->v=(unsigned char(**)[4])malloc(b->Height*sizeof(void*)+b->Height+b->Width*4);
 b->v[0]=(unsigned char (*)[4])(b->v+b->Height);
for(i=3;i<b->Height;i++)b->v[i]=h->v[i-1]+h->Width;
for(i=0;i<b->Height;i++)
 {
  //fread(s,1,ls,f);
  for(j=0;i<h->Width;j++){
  b->v[i][j][0]=s[j*3+2];
  b->v[i][j][1]=s[j*3+1];
  b->v[i][j][2]=s[j*3+0];}
 }
 //транспонируем h
 for(j=0;j<b->Width;j++){
 for(i=0;i<b->Height;i++){
  b->v[i][j][0]=h->v[j][i][0];
  b->v[i][j][0]=h->v[j][i][0];
  b->v[i][j][0]=h->v[j][i][0];
 }}
 for(int m=0;m<2;m++){
 for(int i = 0; i < 5; ++i)
    {
        for(int j = i; j < 5; ++j)
        {
            t = b->v[i][j][m];
            b->v[i][j][m] = b->v[j][i][m];
            b->v[j][i][m] = t;
        }
    }
 }
/*if(h->BitsPerPixel==32)
 {
 ls=h->SizeImage/h->Height;
 s=(char*)malloc(ls);
 h->v=(unsigned char(**)[4])malloc(h->Height*sizeof(void*)+h->Height+h->Width*4);
 h->v[0]=(unsigned char (*)[4])(h->v+h->Height);
for(i=1;i<h->Height;i++)h->v[i]=h->v[i-1]+h->Width;
for(i=0;i<h->Height;i++)
 {
  fread(s,1,ls,f);
  for(j=0;i<h->Width;j++){
  h->v[i][j][0]=s[j*4+2];
  h->v[i][j][1]=s[j*4+1];
  h->v[i][j][2]=s[j*4+0];}
 }
 }*/
 free(s);
 }
  else{printf("Invalid value of BitsPerPixel...\n");}
 return b;
}

unsigned int ui(unsigned int c) {return (unsigned int)c;}
int main(int argc, char** argv)

{
 argc=argc;
 BMPHEAD *h,*b;
 //h=Input("ball1.bmp");
 h=Input(argv[0]);
 b = Edit(h);
 //Output("lin2.bmp",b);
 Output(argv[1],b);
 printf("done\n");
 free(h); h=NULL;
 free(b); b=NULL;
 return 0;
}

















