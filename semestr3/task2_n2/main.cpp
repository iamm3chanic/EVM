/* In Windows please uncomment lines 7 and 568 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include<time.h>
//#include <windows.h>
#include <cmath>
int s = 0; int sr = 0;
using namespace std;
// структура для представления узлов дерева
struct node
{
	int key; //Значение узла
	unsigned int height; //Высота под текущим узлом
	node* left; //Указатель на левое поддерево
	node* right; //Указатель на правое поддерево
				 //Конструктор по умолчанию
	node(int k) { key = k; left = right = 0; height = 1; }
};

unsigned char height(node* p);
int bfactor(node* p);
void fixheight(node* p);
node* rotateright(node* p);
node* rotateleft(node* q);
node* balance(node* p);
node* insert(node* p, int k);
node* merge(node* l, node* r, int progress);
node* findmin(node* p);
node* findmax(node* p);
node* removemin(node* p);
node* remove(node* p, int k, int progress);

unsigned char height(node* p)
{
	return p ? p->height : 0;
}

int bfactor(node* p)
{
	return height(p->right) - height(p->left);
}

void fixheight(node* p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}

node* rotateright(node* p) // правый поворот вокруг p
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

node* rotateleft(node* q) // левый поворот вокруг q
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

node* balance(node* p) // балансировка узла p
{
	fixheight(p);
	if (bfactor(p) == 2)
	{
		if (bfactor(p->right) < 0)
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if (bfactor(p) == -2)
	{
		if (bfactor(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p; // балансировка не нужна
}

node* insert(node* p, int k) // вставка ключа k в дерево с корнем p
{
	if (!p) return new node(k);
	if (k < p->key)
		p->left = insert(p->left, k);
	else
		p->right = insert(p->right, k);
	return balance(p);
}

/*
len=len+rhs.len;
	rhs.len=0;
	CTree<int>::CNode *tmp=rhs.FindMin();
	CTree<int>::CNode *v = new typename CTree<T>::CNode(tmp->GetKey(),tmp->GetV(),NULL);
	rhs.Delete(tmp);
	root->Merging(v, rhs.root);
	root=v;
	rhs.root=NULL;

*/
// поиск узла с минимальным ключом в дереве p
node* findmin(node* p)
{
	return p->left ? findmin(p->left) : p;
}
// поиск узла с максимальным ключом в дереве p
node* findmax(node* p)
{
	return p->right ? findmax(p->right) : p;
}
// удаление узла с минимальным ключом из дерева p
node* removemin(node* p)
{
	if (p->left == 0)
		return p->right;
	p->left = removemin(p->left);
	return balance(p);
}
//#ifdef remove(const char*)
//#undef remove(const char*)
node* remove(node* p, int k, int progress) // удаление ключа k из дерева p
{
	if (!p) return 0;
	if (k < p->key)
		p->left = remove(p->left, k, progress);
	else if (k > p->key)
		p->right = remove(p->right, k, progress);
	else //  k == p->key 
	{
		if (progress == 2)
			cout << "33% выполнено" << endl;
		node* q = p->left;
		node* r = p->right;
		delete p;
		if (progress == 2)
		cout << "75% выполнено" << endl;
		if (!r) return q;
		node* min = findmin(r);
		min->right = removemin(r);
		min->left = q;
		return balance(min);
	}

	return balance(p);
}

//0 глубина - корень дерева
void printTreeToConsole(node* p, int deep) {
	if (deep<0)

	{
		deep++;  s = -1;
	}
	
	
		if (p->right !=NULL) {

			printTreeToConsole(p->right, deep + 1);
			if ((deep <= 2 && s == -1) || (s == 0)|| (( sr>0) &&(deep>=sr)))
			for (int i = 0; i < deep; i++)
				{cout << "      ";}
				if ((deep <= 2 && s == -1) || (s == 0) || ((sr > 0) && (deep >= sr)))
			cout << "  /" << endl;


		}
		//вывод отступов
			if ((deep <= 2 && s == -1) || (s == 0) || ((sr > 0) && (deep >= sr)))
		{
			for (int i = 0; i < deep; i++)
				cout << "      ";
			cout << p->key <<"(" <<deep<<  endl;

		}



		if (p->left ) {
			if ((deep <= 2 && s == -1) || (s == 0) || ((sr > 0) && (deep >= sr)))
				for (int i = 0; i < deep; i++)
					cout << "      ";
			if ((deep <= 2 && s == -1) || (s == 0) || ((sr > 0) && (deep >= sr)))
				cout << "  \\" << endl;

			printTreeToConsole(p->left, deep + 1);

		}
		
	
}

void printTreeToFile(node* p, int deep, ostream& file) {
	if (p->right ) {

		printTreeToFile(p->right, deep + 1, file);
		for (int i = 0; i < deep; i++)
			file << "      ";
		file << "  /" << endl;

	}
	//вывод отступов

	for (int i = 0; i < deep; i++)
		file << "      ";
	file << p->key << endl;


	if (p->left) {
		for (int i = 0; i < deep; i++)
			file << "      ";
		file << "  \\" << endl;

		printTreeToFile(p->left, deep + 1, file);
	}
}


void inputTreeArray(  int n, int* treeArray, int input) {
	int c;
	ifstream file;
	switch (input) {
	case 1:
		cout << "Введите " << n << " элементов.";
		cout << endl;
		for (int i = 0; i < n; i++) {
			cin >> c;
			treeArray[i] = c;
		}
		break;
	case 2:
		file.open("input.txt");
		if (file) {
			for (int i = 0; i < n; i++) {
				file >> c;
				treeArray[i] = c;
			}
			file.close();
		}
		break;
	case 3:
	
		srand(time(0));
		cout << "Доступные для удаления элементы :" << endl;
		
		for (int i = 0; i < n; i++) {
			treeArray[i] = rand();
		}
		break;
	default:
		cout << "Ошибка";
	}
}
//Вывод меню на консоль
void menu( int& removable, int& output, int& progress) {



	cout << "Введите удаляемый элемент: ";
	cin >> removable;
	cout << endl;

	cout << "Укажите способ вывода результата: 1  - в файл, 2 - на экран, 3 - без вывода. Ваш выбор: ";
	cin >> output;
	cout << endl;

	cout << "Укажите способ отслеживания результата: 1 - с измерением времени выполнения процедуры, 2 - с выводом процента выполнения процедуры и шкалы прогресса. Ваш выбор:";
	cin >> progress;
	cout << endl;
	cout << endl << endl << endl;
}

void menu2(int& output, int& progress) {

	cout << "Укажите способ вывода результата: 1  - в файл, 2 - на экран, 3 - без вывода. Ваш выбор: ";
	cin >> output;
	cout << endl;

	cout << "Укажите способ отслеживания результата: 1 - с измерением времени выполнения процедуры, 2 - с выводом процента выполнения процедуры и шкалы прогресса. Ваш выбор:";
	cin >> progress;
	cout << endl;
	cout << endl << endl << endl;
}




//Вызов удаления в зависимости от способа вывода прогресса
void removeDisplay(node* tree, int removable, int progress) {
	if (progress == 1) {
		unsigned int start = clock();
		cout << "START: " << (double)start;
		tree = remove(tree, removable, progress);
		unsigned int end = clock();
		cout << " END: " << (double) end << endl;
		double f = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "Время выполнения удаления: " << f << " c";
		cout << endl << endl;
	}
	else
	{
		tree = remove(tree, removable, progress);
		cout << "100% выполнено" << endl;
	}

}

void mergeDisplay(node* l, node* r, int progress) {
	if (progress == 1) {
		unsigned int start = clock();
		cout << "START: " << (double)start;
		l = merge(l, r, progress);
		unsigned int end = clock();
		cout << " END: " << (double) end << endl;
		double f = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "Время выполнения слияния: " << f << " c";
		cout << endl << endl;
	}
	else
	{
		l = merge(l, r, progress);
		cout << "100% выполнено" << endl;
	}
	printTreeToConsole(l, 0);

}

void print(int count,int output, node* tree) {
	ofstream file;


		switch (output)
		{
		case 1: 
		        if (!file) {
 			   cout << "File error - can't open to write data!";
  			   cin.sync(); cin.get(); throw -1;
 			   }
			file.open("output.txt");
			//if (file) {
				printTreeToFile(tree, 0, file);
				file.close();
				break;
			//}
		case 2:
			if (count <= 100)
			printTreeToConsole(tree, 0);
			else {
				sr = (int)log2(count) - 2;
				printTreeToConsole(tree, -1);
				s = 0;
			}
			break;
		case 3:
			break;
		}
	
}



node* merge(node* l, node* r, int progress) // слияние деревьев l,r
{
  if (!l ) return r;
  if (!r ) return l;
   int lh=height(l);
   int rh=height(r);
   //int count=0;
   //node*l2=l;
   if(lh>=rh)
   {
       int Div=findmin(r)->key;
	  r=remove(r,Div,1);
	  //printTreeToConsole(r, 0);
	  node* r1=r;
	  node* l1=l;
	  int lh1=height(l1);
          int rh1=height(r1);
	  cout << endl;
	  cout << endl;
	  //printTreeToConsole(l1, 0);
	  //cout << endl;
	  
	  do
	  {
	   if(lh1-rh1==0 || lh1-rh1==1)
	   {
	   	 node* tmp1=l1->left;
	   	 l1->left=NULL;
	   	 node* tmp2=l1->right;
	   	 int tmp=l1->key;
	   	 l1->key=Div;
	   	 l1->right=r;
	   	 //l1->left->left=tmp1;
	   	 l1->left=tmp1;
	   	l1->left->right=tmp2;
	   	l1->left->key=tmp;
	   //while(count!=0) {l2=l2->right;count++;}
	  // if(count==0) {l2->right=l1; l=l2;}
	   
	        break;
	   }
	   if (progress == 2)cout<<"+1 iteration of while..."<<endl;
	   if (progress == 2)cout<<"50% выполнено" << endl;
	   //l=l->right; 
	   l1=l1->right; lh1--;
	  } while(l1->right!=NULL);
	   if (progress == 2)cout<<"80% выполнено" << endl;
	return balance(l1);
   }
   else
   {
       int Div=findmax(l)->key;
	  l=remove(l,Div,1);
	  //printTreeToConsole(r, 0);
	  node* r1=r;
	  node* l1=l;
	  int lh1=height(l1);
          int rh1=height(r1);
	  cout << endl;
	  cout << endl;
	  //printTreeToConsole(l1, 0);
	  //cout << endl;
	  
	  do
	  {
	   if(lh1-rh1==0 || lh1-rh1==-1)
	   {
	   	 node* tmp1=r1->right;
	   	 r1->right=NULL;
	   	 node* tmp2=r1->left;
	   	 int tmp=r1->key;
	   	 r1->key=Div;
	   	 r1->left=l;
	   	 r1->right=tmp1;
	   	r1->right->left=tmp2;
	   	r1->right->key=tmp;
	   break;}
	   if (progress == 2)cout<<"+1 iteration of while..."<<endl;
	   if (progress == 2)cout<<"50% выполнено" << endl;
	   //l=l->right; 
	   r1=r1->left; rh1--;
	  } while(r1->left!=NULL);
	   if (progress == 2)cout<<"80% выполнено" << endl;
	return balance(r1);
	  
   }
}

void Autotest()
{
 cout<<"START AUTOTEST"<<endl;
 int count=5, count2=4;
 node* tree=0; node* rtree=0; node* ntree=0;
  for ( int i = 0; i < count; i++)
  { tree = insert(tree, i+1); }
  for ( int i = 0; i < count2; i++)
  { rtree = insert(rtree, (i+1)*20); }
  cout<<"tree1"<<endl;
 printTreeToConsole(tree, 0);
  cout<<"tree2"<<endl;
 printTreeToConsole(rtree, 0);
 
 unsigned int start = clock();
		cout << "START: " << (double)start << endl;
		ntree = merge(tree, rtree, 1);
		unsigned int end = clock();
		cout << " END: " << (double) end << endl;
		double f = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "Время выполнения слияния: " << f << " c";
		cout << endl << endl;
 cout<<"Итоговое дерево:"<<endl;
 printTreeToConsole(ntree, 0);
}

int main()
 {
	setlocale(LC_ALL, "Russian");

   Autotest();


	int count1, count2, *treeArray ;
	int output, input, progress, to; //removable
	node* tree=0; node* rtree=0;

	cout << "Введите количество элементов в дереве 1: ";
	cin >> count1;
	cout << endl;
	 treeArray = new  int[count1];
	 cout << "Укажите способ ввода последовательности чисел для дерева:" <<endl<< "1 - с клавиатуры, 2 - из файла, 3 - случайная последовательность. Ваш выбор: ";
	 cin >> input;
	 inputTreeArray(count1, treeArray, input);
	 cout << endl;

	 for ( int i = 0; i < count1; i++)
		 tree = insert(tree, treeArray[i]);
         delete[] treeArray;
		 
	cout << "Введите количество элементов в дереве 2: ";
	cin >> count2;
	cout << endl;
	 treeArray = new  int[count2];
	 cout << "Укажите способ ввода последовательности чисел для дерева:" <<endl<< "1 - с клавиатуры, 2 - из файла, 3 - случайная последовательность. Ваш выбор: ";
	 cin >> input;
	 inputTreeArray(count2, treeArray, input);
	 cout << endl;

	
	 for ( int i = 0; i < count2; i++)
		 rtree = insert(rtree, treeArray[i]);
	delete[] treeArray;
	
	 if (input == 3)
	 {
		 cout << "Укажите способ вывода произвольной последовательности последовательности чисел для дерева:" << endl;
		 cout<<"1 - все дерево" <<endl <<" 2 - 3 верхних уровня"<< endl<<" 3 -  нижних уровней"<<endl <<"4- нижних уровней левого дерева"<<endl<<"5-  нижних уровней правого дерева "<<endl<<" . Ваш выбор: ";
		 cin >> to;
		 cout << endl;

		 switch (to)
		 {
		 case 1:

			 printTreeToConsole(tree, 0);
			 break;
		 case 2:

			 printTreeToConsole(tree, -1);
			 sr = 0;
			 s = 0;
			 break;
		 case 3:
			 sr = (int)log2(count1+count2-1) - 2;
			 printTreeToConsole(tree,0);
			 sr = 0;
			 break;
		 case 4:
			 sr = (int)log2(count1+count2-1) - 2; s = 1;
			  printTreeToConsole(tree->left , 0);
			  sr = 0; s = 0;
			  break;
		 case 5:
			 sr = (int)log2(count1+count2-1) - 2; s = 1;
			
			 printTreeToConsole(tree->left, 0);
			 sr = 0; s = 0;
			 break;
		 }

	 }
	//menu( removable, output, progress);
	menu2(output, progress);

	//removeDisplay(tree, removable, progress);
	mergeDisplay(tree, rtree, progress);
	//print(count1+count2-1,output, merge(tree, rtree, progress));

	//system("pause");
	return 0;
}
