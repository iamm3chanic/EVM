#include<iostream>
#include<exception>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"class.h"
//#include"walloc.h"
using namespace std;

void Test(){
	CComplexVector **m;
	ComplexNumber *cn;
	int count, type, lg, l, im, re,k1,k2,k3; FILE *f;
	char str[512], FileName[512], *ss,*sss,*s4,*cnum,sign,i1;
	//read and input
	f=fopen("in.txt", "r");
	fgets(str,512,f);
	sscanf(str,"%d",&count);
	m=new CComplexVector*[count];
	for(int j=0; j<count && fgets(str,512,f)!=NULL; j++){
		sscanf(str,"%d%n",&type,&l); ss=str+l;while(isspace(*ss))ss++; sss=ss;
		for(lg=0;*ss;lg++,ss++){if(!isalnum(*ss) && *ss!='.' && *ss!='_') break;}
		strncpy(FileName,sss,lg);
		s4=ss;
		for(lg=0;*s4;s4++){if(isspace(*s4))lg++;while(isspace(*s4))s4++;}
		cn=new ComplexNumber[lg];
		cnum=ss;
		for(int i=0; i<lg; i++){
			while(isspace(*cnum))cnum++;
			if(sscanf(cnum,"%d%n",&re,&k1)==1){
				cnum=cnum+k1;
				if(isspace(*cnum) || *cnum=='\0'){
					cn[i].SetRe(re);
				}
				else if(*cnum=='i'){
					cnum=cnum+1;
					cn[i].SetIm(re);
					continue;
				}
				else{
					if(sscanf(cnum,"%d%n",&im,&k2)==1){
						cnum=cnum+k2;
						if(sscanf(cnum,"%c%n",&i1,&k3)==1 && i1=='i'){
							cnum=cnum+k3;
							cn[i].SetRe(re);
							cn[i].SetIm(im);
						}
					}
					else if(sscanf(cnum,"%c%n",&sign,&k2)==1){
						cnum=cnum+1;
						cn[i].SetRe(re);
						if(sign=='+'){
							if(sscanf(cnum,"%c%n",&i1,&k2)==1){
								cnum=cnum+1;
								if(i1=='i'){
									cn[i].SetIm(1);
								}
							}
						}
						else if(sign=='-'){
							if(sscanf(cnum,"%c%n",&i1,&k2)==1){
								cnum=cnum+1;
								if(i1=='i'){
									cn[i].SetIm(-1);
								}
							}
						}
					}
				}
			}
			else if(sscanf(cnum,"%c%n",&sign,&k2)==1){
				cnum=cnum+1;
				if(sign=='-'){
					if(sscanf(cnum,"%c%n",&i1,&k3)==1){
						cnum=cnum+1;
						if(i1=='i'){
							cn[i].SetRe(0);
							cn[i].SetIm(-1);
						}	
					}
				}
				else if(sign=='i'){
					cn[i].SetRe(0);	
					cn[i].SetIm(1);
				}
			}
		}
		m[j]=CComplexVector::create(type,cn,lg);
		m[j]->show(FileName);
		delete[] cn;		
	}
	for(int j=0;j<count;j++){delete m[j];}
	delete [] m; m=NULL; 
	fclose(f);
	}	

int main() {
	try{
		Test();
	}catch(...){
		cout << "some error" << endl;
	}
	return 0;
}

