#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

struct SPoint{SPoint(){l=-1;iback=-1;v=0;} double x,y,l;int iback,v;}; //l=длина кратч.пути, iback=номер пред.вершины в кратч.пути
struct SEdge{int i0,i1; double d; int operator()(int i){return i==i0?i1:i0;}}; //l=длина кратч.пути
struct SPointP{SPointP(int I=0,double L=0,int V=0){i=I;l=L;v=V;} int i;double l;int v;};
ifstream &operator>>(ifstream &f, SPoint &a){f>>a.x>>a.y; return f;}
ifstream &operator>>(ifstream &f, SEdge &a){f>>a.i0>>a.i1>>a.d; return f;}
bool operator<(const SPointP &a, const SPointP &b){return a.l>b.l;}
int main(void)
{
 vector<SPoint> p; vector<SEdge> e; vector<vector<int>> n;
 int i0=0,i1=11,j; double l; SPointP pt; priority_queue<SPointP> q;
 pt.i=0;
 {SPoint P;ifstream f("vertex.txt"); while(f>>P)p.push_back(P);} //ввод вектора вершин из файла c к-тами вершин в формате x y
 {SEdge E; ifstream f("edges.txt");  while(f>>E)e.push_back(E);} //ввод вектора ребер из файла с номерами вершин ребра и его длиной в формате i0 i1 d
 n.resize(p.size());
 for(size_t i=0;i<e.size();i++)//создание вектора векторов номеров ребер, инцидентных вершине
 {n[e[i].i0].push_back(i);n[e[i].i1].push_back(i);}
 //----
 for(pt.i=i0,p[i0].l=0.0,pt.l=0.0;pt.i!=i1;) //пока не дошли до конца…
 {
  for(vector<int>::iterator i=n[pt.i].begin(); i!=n[pt.i].end(); i++)//перебираем ребра, инцидентные текущей вершине и добавляем их в очередь
  {
   j=e[*i](pt.i); l=p[pt.i].l+e[*i].d;
   if(p[j].l<0||p[j].l>l)
   {p[j].iback=pt.i;p[j].l=l;q.push(SPointP(j,l,++p[j].v));}
  }
  do{if(q.empty())goto le;pt=q.top(); q.pop();}while(pt.v!=p[pt.i].v); //ищем первую рабочую вершину и записываем ее в текущую вершину
 }
 cout<<"l="<<pt.l<<endl;
 for(int k=i1;k>=0;k=p[k].iback){cout<<k<<" ";} cout<<endl; //номера вершин кратчайшего пути в обратном порядке
 getchar();return 0;
le:
 cout<<"can't find path"<<endl;//getchar();
 return 0;
}
