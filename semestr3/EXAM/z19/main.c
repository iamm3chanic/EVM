/*
Реализовать функцию расчета CRC-значения для строки, дополненной двумя нулевыми байтами. 
Занести в два последних нулевых байта найденное CRC-значение и проверить, что у полученной 
строки CRC-значение =0 .
LOOK FOR ANOTHER ONE: https://yadi.sk/d/6SvB70b01WrVHA
*/
#include <string.h>
#include <stdio.h>


unsigned short CRC16(char *s,int l);
unsigned short GetBit(char *s,int i);
int X=(1<<15)|(1<<2)|(1<<0);

unsigned short CRC16(char *s,int l)
{
 int i; unsigned short R; //R: s[0], s[1]
 for(R=(s[0]<<8)|s[1],i=0;i<l-16;i++)
  if(R&(1<<15))
   R=((R<<1)|GetBit(s,i+16))^X;
  else
   R=((R<<1)|GetBit(s,i+16));
 return R;
}


unsigned short GetBit(char *s,int i)
{
return s[i/8]&(1<<(7-(i%8)))?1:0;
}

int main(void)

{char str[256]="very secret hash string.int Find(int v){int i=Hash(v); for(list<int>::iterator j=m[i].begin();j!=m[i].end();j++)if(*j==v)return 1; return 0;}";

 int l=strlen(str)*8+16,l0=strlen(str); short int crc=0;

 str[l0]=0;str[l0+1]=0;//добавляем два нулевых байта

 crc=CRC16(str,l); printf("crc=%hd\n",crc);//считаем CRC

 str[l0+1]=(crc>>0);

 str[l0]=crc>>8;//записываем CRC в последние нулевые байты

 crc=CRC16(str,l); printf("check crc=%hd\n",crc);//убеждаемся, что CRC==0

return 0;

}
