/*На языке C++ написать собственную ссылочную реализацию двунаправленного списка строк (строки длиной не более 256 символов). Последовательно заполнить список словами из файла
http://lectures.stargeo.ru/tO.txt (слова разделяются пробелами, табуляциями и переходами на следующую строчку). После считывания всех строк вывести в обратном порядке все элементы списка в файл ./t0.txt по одному слову в строке (таким образом, все слова из исходного файла должны быть выведены в выходной файл, но в обратном порядке).
*/


#include <iostream>
#include <string>
#include <stack>
using namespace std;
 
struct Elem
{
   string data; // данные
   Elem * next, * prev;
};
 
class List
{
private:
   // Голова, хвост
   Elem * Head, * Tail;
   // Количество элементов
   int Count;
   // stacks
   stack<string> s1, s2;
 
public:
 
   // Конструктор
   List();
   // Конструктор копирования
   List(const List&);
   // Деструктор
   ~List();
 
   // Получить количество
   int GetCount();
   // Получить элемент списка
   Elem* GetElem(int);  //реализовано пока только без стеков!!!
 
   // Удалить весь список
   void Clean();
   void SetZero();
   // Удаление элемента, если параметр не указывается,
   // то функция его запрашивает
   void Del(int pos = 0); //реализовано пока только без стеков!!!
   // Вставка элемента, если параметр не указывается,
   // то функция его запрашивает
   void Insert(int pos = 0); //реализовано пока только без стеков!!!
 
   // Добавление в конец списка
   void AddTail(string n);
 
   // Добавление в начало списка
   void AddHead(string n);
 
   // Печать списка
   void Print();	
   // Печать определенного элемента
   void Print(int pos); //реализовано пока только без стеков!!!
 
   List& operator = (const List&);
   // сложение двух списков (дописывание)
   List operator + (const List&);
 
   // сравнение по элементам
   /*bool operator == (const List&);
   bool operator != (const List&);
   bool operator <= (const List&);
   bool operator >= (const List&);
   bool operator < (const List&);
   bool operator > (const List&);*/
 
   // переворачивание списка
   List operator - ();
};
 
List::List()
{
   // Изначально список пуст
   Head = Tail = NULL;
   Count = 0;
}

void List::SetZero()
{
   Head = Tail = NULL;
   Count = 0;
}
 
List::List(const List & L)
{
   Head = Tail = NULL;
   Count = L.Count;
 
   // Голова списка, из которого копируем
   Elem *temp = L.Head;
   // Пока не конец списка
   while(temp != 0)
   {
      AddTail(temp->data);
      temp = temp->next;
   }
}
 
List::~List()
{
   // Удаляем все элементы
   Clean();
}
 
void List::AddHead(string n)
{
   // новый элемент
   Elem * temp = new Elem;
   s1.push(n);  
   // Предыдущего нет
   temp->prev = 0;
   // Заполняем данные
   temp->data = n;
   // Следующий - бывшая голова
   temp->next = Head;
 
   // Если элементы есть?
   if(Head != 0)
      Head->prev = temp;
 
   // Если элемент первый, то он одновременно и голова и хвост
   if(Count == 0)
      Head = Tail = temp;
   else
      // иначе новый элемент - головной
      Head = temp;
 
   Count++;
}
 
void List::AddTail(string n)
{
   // Создаем новый элемент
   Elem * temp = new Elem;
   s2.push(n);
   // Следующего нет
   temp->next = 0;
   // Заполняем данные
   temp->data = n;
   // Предыдущий - бывший хвост
   temp->prev = Tail;
 
   // Если элементы есть?
   if(Tail != 0)
      Tail->next = temp;
 
   // Если элемент первый, то он одновременно и голова и хвост
   if(Count == 0)
      Head = Tail = temp;
   else
      // иначе новый элемент - хвостовой
   Tail = temp;			
   Count++;
}
 
void List::Insert(int pos)
{
   // если параметр отсутствует или равен 0, то запрашиваем его
   if(pos == 0)
   {
      cout << "Input position: ";
      cin >> pos;
   }
 
  // Позиция от 1 до Count?
   if(pos < 1 || pos > Count + 1)
   {
      // Неверная позиция
      cout << "Incorrect position !!!\n";
      return;
   }
 
   // Если вставка в конец списка
   if(pos == Count + 1)
   {
      // Вставляемые данные
      string data;
      cout << "Input new string: ";
      cin >> data;
      // Добавление в конец списка
      AddTail(data);
      return;
   }
   else if(pos == 1)
   {
      // Вставляемые данные
      string data;
      cout << "Input new string: ";
      cin >> data;
      // Добавление в начало списка
      AddHead(data);
      return;
   }
 
   // Счетчик
   int i = 1;
 
   // Отсчитываем от головы n - 1 элементов
   Elem * Ins = Head;
 
   while(i < pos)
   {
      // Доходим до элемента, 
      // перед которым вставляемся
      Ins = Ins->next;
      i++;
   }
 
   // Доходим до элемента, 
   // который предшествует
   Elem * PrevIns = Ins->prev;
 
   // Создаем новый элемент
   Elem * temp = new Elem;
 
   // Вводим данные
   cout << "Input new number: ";
   cin >> temp->data;
 
   // настройка связей
   if(PrevIns != 0 && Count != 1)
      PrevIns->next = temp;
 
   temp->next = Ins;
   temp->prev = PrevIns;
   Ins->prev = temp;
 
   Count++;
}
 
void List::Del(int pos)
{
   // если параметр отсутствует или равен 0, то запрашиваем его
   if(pos == 0)
   {
       cout << "Input position: ";
       cin >> pos;
   }
   // Позиция от 1 до Count?
   if(pos < 1 || pos > Count)
   {
      // Неверная позиция
      cout << "Incorrect position !!!\n";
      return;
   }
 
   // Счетчик
   int i = 1;
 
   Elem * Del = Head;
 
   while(i < pos)
   {
      // Доходим до элемента, 
      // который удаляется
      Del = Del->next;
      i++;
   }
 
   // Доходим до элемента, 
   // который предшествует удаляемому
   Elem * PrevDel = Del->prev;
   // Доходим до элемента, который следует за удаляемым
   Elem * AfterDel = Del->next;
 
   // Если удаляем не голову
   if(PrevDel != 0 && Count != 1)
      PrevDel->next = AfterDel;
   // Если удаляем не хвост
    if(AfterDel != 0 && Count != 1)
      AfterDel->prev = PrevDel;
 
   // Удаляются крайние?
   if(pos == 1)
       Head = AfterDel;
   if(pos == Count)
       Tail = PrevDel;
 
   // Удаление элемента
   delete Del;
 
   Count--;
}
 
void List::Print(int pos)
{
   // Позиция от 1 до Count?
   if(pos < 1 || pos > Count)
   {
      // Неверная позиция
      cout << "Incorrect position !!!\n";
      return;
   }
 
   Elem * temp;
 
   // Определяем с какой стороны 
   // быстрее двигаться
   if(pos <= Count / 2)
   {
      // Отсчет с головы
      temp = Head;
      int i = 1;
 
      while(i < pos)
      {
         // Двигаемся до нужного элемента
         temp = temp->next;
         i++;
      }
   }
   else
   {
       // Отсчет с хвоста
      temp = Tail;
      int i = 1;
 
      while(i <= Count - pos)
      {
         // Двигаемся до нужного элемента
         temp = temp->prev;
         i++;
      }
   }
   // Вывод элемента
   cout << pos << " element: ";
   cout << temp->data << endl;
}
 
void List::Print()
{
   // Если в списке присутствуют элементы, то пробегаем по нему
   // и печатаем элементы, начиная с головного
   stack <string> s3,s4;
   if(Count != 0)
   {
     // Elem * temp = Head;
      cout << "( ";
      /*while(temp->next != 0)
      {
          cout << temp->data << ", ";
          temp = temp->next;
      }
 
      cout << temp->data << " )\n";*/ 
      while(!s1.empty())
      {cout << s1.top()<<", ";
      s4.push(s1.top());
      s1.pop();}
      while(!s2.empty())
      {//cout << s2.top()<<", ";
       s3.push(s2.top());  //чтоб не забыть нужное, забьем в s3
       s2.pop();
      }
      while(!s3.empty())
      {cout << s3.top()<<", ";
       s2.push(s3.top());  //это все ради правильного порядка. забьем обратно в s2
       s3.pop();
      }
      cout << " )\n";
   }
   //вернем как было
    while(!s3.empty())
      {//cout << s2.top()<<", ";
       s2.push(s3.top());  //чтоб не забыть нужное, забьем в s3
       s3.pop();
      }
    while(!s4.empty())
      {//cout << s1.top()<<", ";
      s1.push(s4.top());
      s4.pop();}
}
 
void List::Clean()
{
   // Пока остаются элементы, удаляем по одному с головы
   while(Count != 0)
      Del(1); 
   while(!s1.empty()){s1.pop();} 
   while(!s2.empty()){s2.pop();} //почистили стеки//почистили стеки
}
 
int List::GetCount()
{
    return Count;
}
 
Elem * List::GetElem(int pos)
{
   Elem *temp = Head;
 
   // Позиция от 1 до Count?
   if(pos < 1 || pos > Count)
   {
      // Неверная позиция
      cout << "Incorrect position !!!\n";
      return 0;
   }
 
   int i = 1;
   // Ищем нужный нам элемент
   while(i < pos && temp != 0)
   {
      temp = temp->next;
      i++;
   }
 
   if(temp == 0)
      return 0;
   else
      return temp;
}
 
List & List::operator = (const List & L)
{
    // Проверка присваивания элемента "самому себе"
    if(this == &L)
       return *this;
 
   // удаление старого списка
   this->~List(); // DelAll();
 
   Elem * temp = L.Head;
 
   // Копируем элементы
   while(temp != 0)
   {
      AddTail(temp->data);
      temp = temp->next;
   }
 
   return *this;
}
 
// переворот
List List::operator - ()
{
   List Result;
 
   Elem * temp = Head;
   // Копируем элементы списка, начиная с головного,
   // в свой путем добавления элементов в голову,
   // таким образом временный список Result будет содержать
   // элементы в обратном порядке
   while(temp != 0)
   {
       Result.AddHead(temp->data);
       temp = temp->next;
   }
   return Result;
}
 
// Тестовый пример
int main(void)
{
   List L;
 
   const int n = 10;
   //int a[n] = {0,1,2,3,4,5,6,7,8,9};
   string a[n] = {"a","b","cc","ddd","e","f","gg","hh","i","jjj"};
   for(int i = 0; i < n; i++)
         L.AddTail(a[i]);
 
   // Распечатка списка
   cout << "List L:\n";
   L.Print();
 
   // Складываем два списка (первый в перевернутом состоянии)
   cout << "List Inverse:\n";
   List Sum = -L;
   // Распечатка списка
   Sum.Print();
   L.Clean();
   cout<<"\nPASSED AUTOTEST\n\n";
     FILE *f = fopen("t.txt" , "r");
   char mystring [10][100];
 
   if (f == NULL) perror("Ошибка открытия файла");
   else
   {
     for(int i=0;i<10;i++)
     if ( fgets(mystring[i], 100, f) != NULL ) // считать символы из файла
       L.AddTail(mystring[i]);
     List Sum = -L;
   // Распечатка списка
    Sum.Print();       
       //puts(mystring[i]);  // вывод на экран
     fclose (f);
   }
}


