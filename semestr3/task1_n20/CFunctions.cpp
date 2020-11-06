/*
 * CFunctions.cpp
 * 
 * Author: iamm3chanic
 */

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>
#include <stdlib.h>
#include "CList2.h"
#include "CString.h"
using namespace std;
//////////////////CLASS METHODS///////////////////////////
       
////////////CString

CToken CString::getTokByIndex(int index)
    {
    //for cheat
     if(index>n){cout<<"Слишком большой номер!\n"; return -1000;}
     if(index<0){cout<<"Слишком маленький номер!\n"; return -1001;}
     else {
     tokList.GoToBegin();
     for(int i=0;i<index;i++){tokList.GoToNext();}
     /*cout<<tokList.GetCur()<<endl;*/return tokList.GetCur();
     }   
    }   
    

void CString::CopyOnly(const CString &v)    
    {
     CList2<CToken> tokList;
     if(this!=&v)
     //{memcpy(&tokList, &v.tokList, v.m*sizeof(CToken); 
    { SetZero(); //Clean();//
    n=v.n; m=v.m;
    if(v.str){str=new char[v.n]; strncpy(str,v.str,n);}
    if(v.all){all = new char*[100]; 
      for (int i=0; i<100; i++) {all[i] = new char[256];   strncpy(all[i],v.all[i],256);} }
     strList=(v.strList);
     tokList=(v.tokList);}
    }
   
void CString::fileRead(const char *fn)
{
    //CString s;
    setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
    char tmp[256];
    char **h=new char*[100];
    for (int i = 0; i < 100; i++) 
     {h[i] = new char [256]; memset(h[i],0,256);}
     FILE* in;
     in = fopen(fn, "r");
      delete[]str;
    size_t len = 0; //char t[100][256];

	for(int i=0;(fgets(tmp, 256, in) != NULL /* && ch != '\n'*/); i++){
		str=tmp;
		len=strlen(str);
                //s.str[len++]='\0';
		//getline(file, currline);
		memcpy(h[i], str, len);
		str=NULL; len=0;
	}
	//file.close();
	fclose(in);
        SetA(h);
   //char *eq=new char[4];   memcpy(eq," = ",3);
   char eq[]=" = ";
   char tm[100][256];  for(int i=0;(i<100);i++){memset(tm[i],0, 256*sizeof(char) );} 
   CToken par;
   int j;
   tokList.GoToBegin();
   //int flag=0;
   tokList.AddAfter(par);
 for(j=0;(j<100)&&(all[j]);j++) 
 {
   memcpy(tm[j], all[j] ,strlen(all[j]));
   if( strstr(tm[j],eq) )
   {  
    char *token, *last, *u, *key;
    printf ("Splitting string \"%s\" into tokens:\n", all[j]);
    token = strtok_r(all[j], " = ", &last);
    key=token;
    //printf("! %s\n! %s\n",key,token);
    while(token != NULL) {
        printf ("%s\n", token);
        u=token;
        token = strtok_r(NULL, " = ", &last);
       }
      par.SetKs(strlen(key)+1);
      par.SetN(strlen(u)+1);
      par.SetK(key);
      par.SetS(u);
      //cout<<par<<endl;  //here it works...
      tokList.AddAfter(par);
      //tokList.AddToPos(par,flag++);
      //cout<<tokList.GetCur()<<endl;  //here it doesn't... 
      //IMPROVED: tokList.AddAfter(par); (line 94)
      //tokList.GoToEnd();
      tokList.GoToNext();
      //flag++;
   }
   //delete[] eq;
  }
        
        
        for (int i = 0; i < 100; i++) { delete [] h[i];}
        delete [] h;
}

void CString::fileReadQ(const char *fn)
{
    //CString s;
    setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
    char tmp[256];
    char **h=new char*[100];
    for (int i = 0; i < 100; i++) 
     {h[i] = new char [256]; memset(h[i],0,256);}
     FILE* in;
     in = fopen(fn, "r");
      delete[]str;
    size_t len = 0; //char t[100][256];

	for(int i=0;(fgets(tmp, 256, in) != NULL /* && ch != '\n'*/); i++){
		str=tmp;
		len=strlen(str);
                //s.str[len++]='\0';
		//getline(file, currline);
		memcpy(h[i], str, len);
		str=NULL; len=0;
	}
	//file.close();
	fclose(in);
        SetA(h);
   //char *eq=new char[4];   memcpy(eq," = ",3);
   char eq[]=" = ";
   char tm[100][256];  for(int i=0;(i<100);i++){memset(tm[i],0, 256*sizeof(char) );} 
   CToken par;
   int j;
   tokList.GoToBegin();
   //int flag=0;
   tokList.AddAfter(par);
 for(j=0;(j<100)&&(all[j]);j++) 
 {
   memcpy(tm[j], all[j] ,strlen(all[j]));
   if( strstr(tm[j],eq) )
   {  
    char *token, *last, *u, *key;
   // printf ("Splitting string \"%s\" into tokens:\n", all[j]);
    token = strtok_r(all[j], " = ", &last);
    key=token;
    //printf("! %s\n! %s\n",key,token);
    while(token != NULL) {
     //   printf ("%s\n", token);
        u=token;
        token = strtok_r(NULL, " = ", &last);
       }
      par.SetKs(strlen(key)+1);
      par.SetN(strlen(u)+1);
      par.SetK(key);
      par.SetS(u);
      tokList.AddAfter(par);
      tokList.GoToNext();
   }
  }
               
        for (int i = 0; i < 100; i++) { delete [] h[i];}
        delete [] h;
}

void CString::fileReadStrings(const char *fn)
{
    //CString s;
    setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
    char tmp[256];
    char **h=new char*[100];
    for (int i = 0; i < 100; i++) 
     {h[i] = new char [256]; memset(h[i],0,256);}
     FILE* in;
     in = fopen(fn, "r");
      delete[]str;
    size_t len = 0; //char t[100][256];

	for(int i=0;(fgets(tmp, 256, in) != NULL ); i++){
		str=tmp;
		len=strlen(str);
		memcpy(h[i], str, len);
		str=NULL; len=0;
	}
	//file.close();
	fclose(in);
        SetA(h);
  // char tm[100][256];  for(int i=0;(i<100);i++){memset(tm[i],0, 256*sizeof(char) );} 
   CToken par;
   int j;
   strList.GoToBegin();
   //int flag=0;
   strList.AddAfter(par);
 for(j=0;(j<100)&&(all[j]);j++) 
 {
   //memcpy(tm[j], all[j] ,strlen(all[j]));
      par.SetN(strlen(all[j]));
      par.SetS(all[j]);
      strList.AddAfter(par);
      strList.GoToNext(); 
  }      
        for (int i = 0; i < 100; i++) { delete [] h[i];}
        delete [] h;
}

void CString::changeStrings(const char *fn)
{
    //CString s;
    setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
    char tmp[256], needle[1000]="", /**needle1=NULL,  beg, *end,*/ *mid=NULL,b[2]="$"; 
    char **h=new char*[100];
    for (int i = 0; i < 100; i++) 
     {h[i] = new char [256]; memset(h[i],0,256);}
     FILE* in;
     in = fopen(fn, "r");
      delete[]str;
    size_t len = 0; //char t[100][256];
    int i=0;
	for( i=0;(fgets(tmp, 256, in) != NULL ); i++){
		str=tmp;
		
		len=strlen(str);
		memcpy(h[i], str, len);
		str=NULL; len=0;
	}
	fclose(in);
	//changing...
	tokList.GoToBegin(); 
         for(;tokList.GoToNext();) {
         
         for(int k=0;k<i;k++) {
         
          strncpy(needle,b,strlen(b));
          strcat(needle, tokList.GetCur().GetK() );  //$i
          strcat(needle, b ); 
         
         // printf(" here is needle: %s\n",needle);
         
          size_t ssl = strlen(tokList.GetCur().GetK())+2;
          size_t rpl = strlen(tokList.GetCur().GetS());
          size_t l = rpl < ssl ? rpl : ssl;
         //проверка на сходство с параметрами
          mid = strstr(h[k], needle);
          if (mid)
          {memcpy(mid, tokList.GetCur().GetS(), l); cout<<"replacing...\n";}
         //strncpy(needle,"",1);
          memset(needle,0,1000);

         }
        // strcpy(needle,b);
	}
	
        SetA(h); //here is set all!
   CToken par;
   int j;
   strList.GoToBegin();
   //int flag=0;
   strList.AddAfter(par);
 for(j=0;(j<100)&&(all[j]);j++) 
 {
   //memcpy(tm[j], all[j] ,strlen(all[j]));
      par.SetN(strlen(all[j]));
      par.SetS(all[j]);
      strList.AddAfter(par);
      strList.GoToNext(); 
  }      
        for (int i = 0; i < 100; i++) { delete [] h[i];}
        delete [] h;
}



CString& CString::operator=(const CString& v)
    {
        if(this!=&v) 
        {Clean(); CopyOnly(v);}
        return *this;
    }

char rand_d(){char c = char('a' + rand() % ('z' - 'a'));
    return c; }
     
void CString::AutoSet()     
    {
     srand( time(0) ); // автоматическая рандомизация
     int ran=1 + rand() % 50;
     char *tmp=new char[ran];
      cout << "Random size = " << ran << endl;
      setLength(ran);
      for(int i=0;i<ran;i++) {tmp[i]=rand_d();}
      //printf("%s\n",tmp);
      SetS(tmp);

      cout << "Random string: " << endl;
      for (int i=0; i < getLength(); i++)cout << tmp[i];
     cout<<endl;
     //for list 
     int m_tmp=getM();
      CToken tmpCToken; char *cur; int j,i;
  
  tokList.Clean();
  for (i=0; i < m_tmp; i++ ) 
        {
           
            tokList.GoToBegin();   
             for (j=0; j < i; j++ )          
            tokList.GoToNext();
           
            //strcpy(cur,tmp);//
            cur=tmp;
            tmpCToken.SetS(cur);
            tokList.AddAfter(tmpCToken);
        }  
        delete [] tmp;  
    } 
////////////CList2
template<class T> void CList2<T>::AddToPos(const T&x, int pos){
	CList2Node<T>* tmp=cur;
	GoToPos(pos);
	AddBefore(x);
	cur=tmp;

}
template<class T> bool CList2<T>::DelCur(){
	if(IsEmpty()) return false;
	auto *x=cur;
	if(cur->prev) {cur->v.Clean();cur->prev->next=cur->next;} else first=cur->next;
	if(cur->next) {cur->v.Clean();cur->next->prev=cur->prev;} else last=cur->prev;
	if(cur->prev) {cur->v.Clean();cur=cur->prev;} else cur=cur->next;
	delete x;
	return true;
}

template<class T> void CList2<T>::AddAfter(const T &x){
	CList2Node<T> *n=new CList2Node<T>(); n->v=x;
	if(IsEmpty()){cur=first=last=n;}
	else{
		n->next=cur->next;
		n->prev=cur;
		cur->next=n;
		if(n->next)
			n->next->prev=n;
		else last=n;
	}
}

template<class T> void CList2<T>::AddBefore(const T &x){
	CList2Node<T> *n=new CList2Node<T>(); n->v=x;
	if(IsEmpty()){cur=first=last=n;}
	else{
		n->prev=cur->prev;
		n->next=cur;
		cur->prev=n;
		if(n->prev)
			n->prev->next=n;
		else first=n;
	}
}   
////////////CTmpCToken
CTmpCToken::operator char()
{
if (i<0) {throw -2;}
 if (i>=(*v).size) return 0;  
 return (*v).s[i];
}

CTmpCToken &CTmpCToken::operator=(/*const*/ char b)
{
if(i<0){throw -3;}
 if(i>=(*v).size)
  { 
   char *q=new char[i+1];
   memset(q,'*',i+1);
   memcpy(q,(*v).s,(*v).size);
   (*v).size=i+1;
   delete[] (*v).s;
   (*v).s=q;
  } 
 (*v).s[i]=b;
 return *this;
}

//////////////////FRIEND FUNCTIONS////////////////////////
ostream& operator<<(ostream& cout, CToken& a)
{
cout<<"key: ";
for (int i=0;i<a.GetKs();++i) {cout<<a.GetK()[i];}cout<<endl;
cout<<"value: ";
for (int i=0;i<a.GetN();++i) {cout<<a.GetS()[i];}cout<<endl; return cout;
} 

istream& operator>>(istream& cin, CToken& a)
{

 a=getTok();
 return cin;
}

ostream &operator<<(ostream& cout, CString &v) 
{
   cout << "Файл:\n";
   for(int i=0;i<100;i++) {for(int j=0;j<255;j++) {if(v.GetA()[i][j])cout<<v.GetA()[i][j];}}
   cout << "Параметры :\n";
   v.tokList.GoToBegin();
   //cout << v.tokList.GetCur(); 
    for (int i=0; v.tokList.GoToNext(); i++)
    { 
     cout << i+1 <<") ";    
     cout << v.tokList.GetCur();   
     }
   cout << "\n";

return cout;
}

istream &operator>>(istream &cin, CString &v)
{
//char **all=new char*[100];
for (int i=0; i<100; i++) 
    {if(v.all[i])delete [] v.all[i];}
     delete []v.all;
     v.all=new char*[100];
for (int i = 0; i < 100; i++) 
      { v.all[i] = new char [256];
      memset(v.all[i],0, 256*sizeof(char) ); }
//v.SetA(v.all);
CToken t;

t=getTok();
//memcpy(s,t.GetS(),t.GetN());
v.setLength(t.GetN());
v.SetS(t.GetS());
return cin;
}
 

CToken initialize(CString &s, char* d) 
{
CToken t; int size=0;
size=strlen(d);
//cout<<size;
t.SetN(size);
t.SetS(d);
delete[]s.getStr();
//s.div=strdup(d);
char *st=new char[size]; strncpy(st,d,size); 
s.SetS(st);
s.getList().GoToBegin();
//s.tokList.AddAfter(t);
s.getList().AddToEnd(t);
return t;
}

////////////////OTHER////////////////////
char *getString(){
    char *str;
    int ch;
    size_t len = 0;
    str=blocks[BLOCK_FLAG++];
    if(!str)return str;
    while(EOF!=(ch=fgetc(stdin)) && ch != '\n'){
        str[len++]=ch;
        if(len==256){
            strcat(str, blocks[BLOCK_FLAG++]);
            if(!str)return str;
        }
    }
    str[len++]='\0';
    
    return str;
}

CToken getTok(){
    CToken tok;
   // size_t size = 5;
    char *str;
    int ch;
    size_t len = 0;
    str=blocks[BLOCK_FLAG++];
    
    if(!str)return tok;
   
   for( ch=fgetc(stdin);(EOF!=(ch=fgetc(stdin)))&&(ch!='\n');/*fflush(stdin)*/){
        str[len++]=ch;
        if(len==256){
            strcat(str, blocks[BLOCK_FLAG++]);
            if(!str)return tok;
        }
        //if(ch=='\n')break;
    }
    //gets(str);
    str[len++]='\0';
    //str=(char*)realloc(str, sizeof(char)*len);
    tok.SetN(len);
    tok.SetS(str);
   // cout<<tok.GetS()[0]<<endl;
    //free(str);
    return tok;
   
}

char **init_b(char **blocks){
    /*blocks = (char**) malloc(sizeof(char*)*100);
for (int i=0; i<100; i++)
  {blocks[i] = (char*) malloc(sizeof(char)*256);}*/
  blocks = new char*[100]; 
for (int i = 0; i < 100; i++) 
  {blocks[i] = new char [256];}
return blocks;
}


void clean(char **blocks) {
/*for (int i=0; i<100; i++)
  {if(blocks [i])free (blocks [i]);} 
free ( blocks);*/
for (int i = 0; i < 100; i++) {
  delete []blocks[i];
}
delete []blocks;
}
