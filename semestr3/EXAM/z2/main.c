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
 if(h->BitsPerPixel==8) //grey
 {
 ls=h->SizeImage/h->Height;
 s=(char*)malloc(ls);
 /*h->g=(unsigned char(**)[4])malloc(h->Height*sizeof(void*)+h->Height+h->Width*4);
 h->g[0]=(unsigned char (*)[4])(h->g+h->Height);
 for(i=1;i<h->Height;i++)h->g[i]=h->g[i-1]+h->Width;
 for(i=0;i<h->Height;i++)
 {
  fread(s,1,ls,f);
  for(j=0;i<h->Width;j++){
  h->g[i][j]=(int)(unsigned int)(unsigned char)d[j];}
  h->g[i][j][0]=s[j*4+2];
  h->g[i][j][1]=s[j*4+1];
  h->g[i][j][2]=s[j*4+0];}
 }*/
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

void Edit(BMPHEAD *h)
{
//заменяет все пиксели с красным цветом, имеющие синих соседей, на пиксели с зеленым цветом
int i,j,ls;
char c,*s=NULL;
if((h->BitsPerPixel==24)||(h->BitsPerPixel==32))
{
 ls=h->SizeImage/h->Height;
 s=(char*)malloc(ls);
for(i=1;i<h->Height-1;i++)
 {
  for(j=1;i<h->Width-1;j++){
  if((h->v[i][j][0]==1)&&(h->v[i][j][1]==0)&&(h->v[i][j][2]==0)          //it's red
    &&((h->v[i-1][j][0]==0)&&(h->v[i-1][j][1]==0)&&(h->v[i-1][j][2]==1)) //low neighbour blue
    &&((h->v[i+1][j][0]==0)&&(h->v[i+1][j][1]==0)&&(h->v[i+1][j][2]==1)) //high neighbour blue
    &&((h->v[i][j-1][0]==0)&&(h->v[i][j-1][1]==0)&&(h->v[i][j-1][2]==1)) //left neighbour blue
    &&((h->v[i][j+1][0]==0)&&(h->v[i][j+1][1]==0)&&(h->v[i][j+1][2]==1)) //right neighbour blue
    )
    h->v[i][j][0]==0;
    h->v[i][j][1]==1; //make green
    h->v[i][j][2]==0;
 }
 }
 free(s);
 }
  else{printf("Invalid value of BitsPerPixel...\n");}
}

unsigned int ui(unsigned int c) {return (unsigned int)c;}

int main(void)
{
 BMPHEAD *h;
 int i,j;
 h=Input("ball1.bmp");
 Edit(h);
 Output("lin2.bmp",h);
 /*//doing grey
 for(i=0;i<h->Height;i++)
 {
  for(j=0;i<h->Width;j++){
  h->v[i][j][0]=h->v[i][j][1]=h->v[i][j][2]=(unsigned char)
  ((ui(h->v[i][j][0])+ui(h->v[i][j][1])+ui(h->v[i][j][2]))/3);
  }
 }
 Output("lin3.bmp",h);*/
 /*//doing red
 for(i=0;i<h->Height;i++)
 {
  for(j=0;i<h->Width;j++){
  h->v[i][j][0]=((ui(h->v[i][j][0])+ui(h->v[i][j][1])+ui(h->v[i][j][2]))/3);
  h->v[i][j][1]=h->v[i][j][2]=0;
  }
 }
 Output("lin4.bmp",h);*/
 printf("done\n");
 free(h); h=NULL;
 return 0;
}
















