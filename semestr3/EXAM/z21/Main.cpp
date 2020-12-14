/*
 * Main.cpp
 На языке C++ написать собственную реализацию однонаправленного списка строк с фиктивным
 элементом (строки длиной не более 256 символов). Последовательно заполнить список словами 
 из файла http://lectures.stargeo.ru/tO.txt (слова разделяются пробелами, табуляциями и 
 переходами на следующую строчку). После считывания всех строк вывести все элементы списка 
 в файл ./t0.txt по одному слову в строке (таким образом, все слова из исходного файла 
 должны быть выведены в выходной файл).
 */
#include <iostream>
#include <fstream>
#include "CList2.h"

using namespace std;

///////////////////////////////////////////
int main()
{ 
MonoLinkedList<string> list1;
/*list1.insertFirst("st");
list1.insertFirst("fv");
list1.insertFirst("tb");
list1.insertFirst("aaaaa");
list1.insertFirst("q");*/
string c,c0,w,tmp;
bool inword=false;
string divs=" \t\r\n";
// string s=" "+s0+" ";
int start; //len=s.size(),
 ifstream fs("strings.txt", ios::in | ios::binary); 
   if(!fs) {cout<<"error in opening...\n";return 1;} //Если ошибка открытия файла, то завершаем программу	
     for(int r = 0;  (std::getline(fs, tmp)); r++) //Считываем строки в tmp
	{
	string tmps=" "+tmp+" "; //для разделения это удобно
	//Делим tmp в этом здоровом цикле и добавляем в очередь
	for (long unsigned int i=1; i<tmps.size(); i++) {
	 string c0 = tmps.substr(i-1,1);
	 string c = tmps.substr(i,1);
	 if (divs.find(c0)!=string::npos && divs.find(c)==string::npos) { 
		 inword=true; start=i; 
	 }
	 if (divs.find(c)!=string::npos) 
	      {
		 if (inword) 
		  {
			w = tmps.substr(start,i-start+1); //здесь есть очередная лексема w
			// cout << w << endl;
			list1.insertLast(w);
		  }
		 inword = false;
	      }
         }
		//queue1.push(tmp);
	}
	fs.close(); //Закрываем файл


list1.print();

/*if(list1.deleteAtPos( 2 ))
std::cout << "true" << std::endl;
else
std::cout << "false" << std::endl;

list1.print();*/
    return 0;
}
