/*
Написать программу на языке С, которая в изображении, заданном в файле http://lectures.stargeo.ru/l.bmp (изображение с палитрой) заменяет все пиксели с красным цветом, имеющие синих соседей, на пиксели с зеленым цветом. Предполагается, что указанные цвета в палитре есть. Результат вывести в файл ./l.bmp. Заголовок BMP-файла можно взять из файла http://lectures.stargeo.ru/header/bmp.h 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp.h"

BMPHEAD *Input(const char *sf)
{
 FILE *f;
 BMPHEAD *h=NULL;
 int lb=102,i,j,ls;
 char c,*s=NULL;
 lb=(int)(((char*)&(h->pal)) - ((char*)&(h->Signature)));
 printf("lb=%d (==54)\n", lb);
 f=fopen(sf,"rb"); if(f==NULL)return NULL;
 h=(BMPHEAD*)malloc(sizeof(*h));
 if(fread(h, 102,1,f)!=1)
 {free(h); return NULL;}
 printf("width=%d; height=%d\n",h->Width, h->Height);
 for(i=0;i<h->Ptr-102;i++) fread(&c,1,1,f);
 h->v=NULL;
 h->g=NULL;
 printf("BitsForPixel=%d \n", h->BitsPerPixel);
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
 int lb=102,i,j,ls;
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
 int lb=102,i,j,ls;
 char *s=NULL;
 lb=(int)(((char*)&(h->pal)) - ((char*)&(h->Signature)));
BMPHEAD *b;
b=(BMPHEAD*)malloc(sizeof(*b));
b->Width=h->Width+2; b->Height=h->Height+2;
 printf("width=%d; height=%d\n",b->Width, b->Height);
 //for(i=0;i<b->Ptr-102;i++) fread(&c,1,1,f);
 b->v=NULL;
 b->g=NULL;
 printf("BitsForPixel for second Image=%d \n", b->BitsPerPixel);
if(h->BitsPerPixel==24)
 {
 ls=(b->SizeImage+2*b->Height+2*b->Width+4)/(b->Height);
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
 //рамочка:
 for(i=0;i<b->Height;i++){
  b->v[i][0][0]=0;b->v[i][0][1]=0;b->v[i][0][2]=0;
  b->v[i][1][0]=0;b->v[i][1][1]=0;b->v[i][1][2]=0;
  b->v[i][2][0]=0;b->v[i][2][1]=0;b->v[i][2][2]=0;
 }
 for(j=0;j<b->Width;j++){
  b->v[0][j][0]=0;b->v[0][j][1]=0;b->v[0][j][2]=0;
  b->v[1][j][0]=0;b->v[1][j][1]=0;b->v[1][j][2]=0;
  b->v[2][j][0]=0;b->v[2][j][1]=0;b->v[2][j][2]=0;
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

int main(void)
{
 BMPHEAD *h,*b;
 int i,j;
 h=Input("ball1.bmp");
 b = Edit(h);
 Output("lin2.bmp",b);

 printf("done\n");
 free(h); h=NULL;
 free(b); b=NULL;
 return 0;
}

















