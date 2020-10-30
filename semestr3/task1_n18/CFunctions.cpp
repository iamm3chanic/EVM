/*
 * CFunctions.cpp
 * 
 * Author: iamm3chanic
 */

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <ctime>
#include <cstdlib>
#include "CList2.h"
#include "CString.h"
using namespace std;
//////////////////CLASS METHODS///////////////////////////

///////////////CToken
/*void CToken::setCToken(char*array)  { 
    //но мы не знаем GetN()!!!!!! Надо сначала засетать его.
      memcpy(v, array, GetN()*sizeof(char));
      } */
      
void CToken::InputTo(int pos, char d)  {
        s[pos-1]=d;
       }    
  
/*void CToken::CopyOnly(const CToken &b) {
       if(this!=&b)
	{SetZero(); nreal=b.nreal;n=b.n;
	memcpy(v=new double[b.n],b.v, b.n*sizeof(double));}
       } */
         
////////////CString

CToken CString::getTokByIndex(int index)
    {
    //for cheat
     if(index>n){cout<<"Слишком большой номер!\n"; return -1000;}
     if(index<0){cout<<"Слишком маленький номер!\n"; return -1001;}
     if(t==NULL){return -1002;}
     else {
     tokList.GoToBegin();
     for(int i=0;i<index;i++){tokList.GoToNext();}
     cout<<tokList.GetCur()<<endl;return tokList.GetCur();
     }   
    //for list
    /*CToken a;
      for(int i=0;i<index/5;i++) {tokList.GoToNext();}
      
      a= tokList.GetCur();
      return a[index%5];*/
      return tokList.GetCur();
    }   
    

void CString::CopyOnly(const CString &v)    
    {
     CList2<CToken> tokList;
     if(this!=&v)
     //{memcpy(&tokList, &v.tokList, v.m*sizeof(CToken); 
    { Clean();
    n=v.n; m=v.m;
    if(v.str){str=new char[v.n]; strncpy(str,v.str,n);}
    if(v.div){div=new char[v.m]; strncpy(div,v.div,n);}
    //if(v.str!=NULL)memcpy(str, v.str,n); 
    //strncpy(str, v.str,n); 
    //if(v.div!=NULL)strcpy(div, v.div);
     tokList=(v.tokList);}
    }
   

CString& CString::operator=(const CString& v)
    {
        if(this!=&v) 
        {SetZero(); CopyOnly(v);}
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
     //printf("%s\n",getStr());
     //for (int i=0; i < getLength(); i++) { printf("%c",getStr()[i]);  }
     cout<<endl;
     //for list 
      CToken tmpCToken; char *cur; int j,i;
  int m_tmp=getM();
  tokList.Clean();
  for (i=0; i < m_tmp; i++ ) 
        {
           
            tokList.GoToBegin();   
             for (j=0; j < i; j++ )          
            tokList.GoToNext();
           
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
//printf("%c",a.GetS()[0]);
for (int i=0;i<a.GetN();++i) {cout<<a.GetS()[i];/*printf("%c",a.GetS()[i]);*/}cout<<endl; return cout;
} 

istream& operator>>(istream& cin, CToken& a)
{

 a=getTok();
 return cin;
}

ostream &operator<<(ostream& cout, CString &v) 
{
   cout << "Строка {";
    for (int i=0; i < v.getLength(); i++)
    { 
      //printf("%c",v.getStr()[i]);   
      cout << v.getStr()[i] ;       
     }
   cout << "}\n";

return cout;
}

istream &operator>>(istream &cin, CString &v)
{
//char *s; 
CToken t;
//int n = sizeof(s);
t=getTok();
//memcpy(s,t.GetS(),t.GetN());
v.setLength(t.GetN());
v.SetS(t.GetS());
return cin;
}

CToken initialize(CString &s, char* d) 
{
CToken t; int size=0;
//t.SetN(sizeof(d)); //let's be accurate here 
//char *x;
//strcpy(x,d);
cout<<d[0]<<d[1]<<d[2];
//for(size=0;(d[size]);size++){}
size=strlen(d);
//cout<<size;
t.SetN(size);
t.SetS(d);
//cout<<sizeof(d)<<endl;
delete[]s.div;
//s.div=strdup(d);
s.div=new char[size]; strncpy(s.div,d,size);
//s.tokList.GoToBegin();
//s.tokList.AddAfter(t);
//s.tokList.AddToEnd(t);
return t;
}

CToken initialize(CString &s, char* d, int n)
{
CToken t; 
t.SetN(n);
t.SetS(d);
//cout<<sizeof(d)<<endl;
delete[]s.div;
s.div=new char[n]; strncpy(s.div,d,n);
//s.setLength[n];
return t;
} 

CToken* divide(CString &s, char* d) 
{
CToken* t; 
char *c_,*ss; char **strings;
int i,j; int sizes[100];
//c=new char[256];
//sizes = new int[100];

strings = new char*[100];
for(int k=0;k<100;k++){strings[k]=new char[256];}
//for(int k=0;k<100;k++){strings[k]=blocks[BLOCK_FLAG++];}
ss=(char*)malloc(sizeof(char)*(s.getLength()+1));
for(int k=0;k<s.getLength();k++){ss[k]=s.getStr()[k];}
ss[s.getLength()]='\0';
//c_=strtok(s.getStr(),d);
c_=strtok(ss,d);
//strcpy(c,strtok(s.getStr(),d));
 for (i=0;c_!= NULL;i++)
  {
    printf ("%s\n",c_);
    
    sizes[i]=strlen(c_);
    //strings[i]=c; //need memcpy 
    //memcpy(strings[i],c,sizes[i]);
    strncpy(strings[i],c_,strlen(c_));
    c_ = strtok (NULL, d);
   // printf("c='%s'\n",c_);
  }
/*  for (int wordCnt=0; c_!= NULL;wordCnt++)
{
    if(wordCnt == 0)token = strtok(buffer, "\r\n");
    else c_ = strtok(NULL, "\r\n");

    wordCnt++;
}*/
free(ss);
CToken tag;
//memset(tok_global, 0, 100);
for(int k=0;k<100;k++){tok_global[k]=tag;}
t=tok_global;
s.tokList.GoToBegin();
for(j=0;j<i;j++)
{/*t[j]=tok_global[j];*/ t[j].SetN(sizes[j]); t[j].SetS(strings[j]); t[j].SetP(j);s.tokList.AddAfter(t[j]);}
//t->SetN(10);
//t->SetS(c);//!!!need setn

//s.tokList.AddAfter(t);
//s.tokList.AddToEnd(t);
//delete[] sizes; //delete[] c;
for(int k=0;k<100;k++){/*if(strings[k]!=NULL)*/delete[] strings[k];}
delete [] strings;
return t;
}
////////////////OTHER////////////////////
char *getString(){
    //size_t size = 10;
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
    //str=(char*)realloc(NULL, sizeof(char)*size);
    str=blocks[BLOCK_FLAG++];
    
    if(!str)return tok;
    //printf("Input something:\n");
    //ch=fgetc(stdin);
   // while(/*EOF!=*/getchar()!= '\n'){
   
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
