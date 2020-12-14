/*На языке C++ написать собственную реализацию очереди строк (строки длиной не более 256
  символов, количество элементов в очереди не более 20). Последовательно заполнять очередь
  словами из файла http://lectures.stargeo.ru/tO.txt (слова разделяются пробелами, 
  табуляциями и переходами на следующую строчку) и при заполнении очереди выводить все 
  элементы очереди в файл ./t0.txt по одному слову в строке (таким образом, все слова из 
  исходного файла должны быть выведены в выходной файл).*/
#include <iostream>
#include <fstream>
using namespace std;

#ifndef QUEUE_H
#define QUEUE_H
#define MIN_CAPACITY 2
template<class T>
class Queue{
private:
    T *q;
    int _size,_capacity;
public:
    void pop();
    void push(T);
    T &front();
    T &back();
    Queue();
    ~Queue();
    Queue(int);
    int size();
    int capacity();
    void reserve(int);
    bool empty();
    void out();
};

template<class T>
int Queue<T>::size(){
    return _size;
}
template<class T>
int Queue<T>::capacity(){
    return _capacity;
}
template<class T>
void Queue<T>::pop(){
    if(_size>=1)
        q++,_size--;
}
template<class T>
void Queue<T>::push(T aux){
    if(_size<_capacity)
        q[_size++]=aux;
    else
        reserve(_size),push(aux);
}
template<class T>
void Queue<T>::reserve(int size){
    T *aux;
    aux=new T[_capacity+size+1];
    _capacity+=size;
    for(int i=0;i<_size;i++)
        aux[i]=q[i];
    delete[]q;
    q=aux;
}
template<class T>
T & Queue<T>::front(){
    return q[0];
}
template<class T>
T & Queue<T>::back(){
    return q[_size-1];
}
template<class T>
Queue<T>::Queue(){
    _size=0;
    _capacity=MIN_CAPACITY;
    q=new T[MIN_CAPACITY+1];
}
template<class T>
Queue<T>::~Queue(){
    if(q)delete[] q;
}
template<class T>
Queue<T>::Queue(int x){
    _size=0;
    _capacity=x;
    q=new T[x+1];
}
template<class T>
bool Queue<T>::empty(){
    return _size==0;
}
template<class T>
void Queue<T>::out() {
  for(int i=0;i<_size;i++)
    cout<<" \n"<<q[i];
}
#endif 

int main() {

Queue<string> queue1;
string tmp;
string s0 = "  I'm  a\ttext  from   \nsome  words.   ";
string c,c0,w;
bool inword=false;
string divs=" \t\r\n";
 string s=" "+s0+" ";
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
			queue1.push(w);
		  }
		 inword = false;
	      }
         }
		//queue1.push(tmp);
	}
	fs.close(); //Закрываем файл
  queue1.out();
  cout<<endl;
  
 /*for (int i=1; i<len; i++) {
	 string c0 = s.substr(i-1,1);
	 string c = s.substr(i,1);
	 if (divs.find(c0)!=string::npos && divs.find(c)==string::npos) { 
		 inword=true; start=i; 
	 }
	 if (divs.find(c)!=string::npos) {
		 if (inword) {
			 w = s.substr(start,i-start+1); //здесь есть очередная лексема w
			 cout << w << endl;
		 }
		 inword = false;
	 }
 }*/
//const char ch = '\n';
	
	
   /* queue1.push ( "aaa" ) ; queue1.push ( "bba" ) ; queue1.push ( "cxz" ) ; 
  cout<<"Изначальная очередь ";
  queue1.out();
  cout<<endl;
  cout<<"введите еще элемент: ";
  cin>>i;
  queue1.push(i);
  cout<<"теперь очередь имеет следующий вид"<<endl;
  queue1.out();
  cout<<endl<<"Размер очереди:"<<endl;
  cout<<queue1.size();
  cout<<endl <<"последний элемент:"<< endl;
  cout<<queue1.back();
  cout<<endl<<"первый элемент"<<endl;
  cout<<queue1.front();
  cout<<endl <<"удаление элемента";
  queue1.pop();
  cout<<endl <<"текущие данные";
  queue1.out();
  cout<<endl <<"еще одно добавление элемента";
  queue1.push(i);
  queue1.out();
  cout<<endl;*/
  /*Queue<int> queue1;
  int i;
  for (i= 1 ; i <= 5 ; i++ )
    queue1.push ( i ) ;
  cout<<"Изначальная очередь ";
  queue1.out();
  cout<<endl;
  cout<<"введите еще элемент: ";
  cin>>i;
  queue1.push(i);
  cout<<"теперь очередь имеет следующий вид"<<endl;
  queue1.out();
  cout<<endl<<"Размер очереди:"<<endl;
  cout<<queue1.size();
  cout<<endl <<"последний элемент:"<< endl;
  cout<<queue1.back();
  cout<<endl<<"первый элемент"<<endl;
  cout<<queue1.front();
  cout<<endl <<"удаление элемента";
  queue1.pop();
  cout<<endl <<"текущие данные";
  queue1.out();
  cout<<endl <<"еще одно добавление элемента";
  queue1.push(i);
  queue1.out();
  cout<<endl;*/
  return 0;
}
