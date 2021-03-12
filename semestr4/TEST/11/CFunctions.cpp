/*
 * CFunctions.cpp
 */
 
#include"CVektor.h"
#include <set>
//using namespace std;
//////////////////CLASS METHODS///////////////////////////
//////CVektor
void CVektor::CopyOnly(const CVektor &v)
    {
     if(this!=&v)
     {ptrArr=v.ptrArr; n=v.n; }
    }
void CVektor::DeleteSame()
    {
//    set<int> s(ptrArr.begin(),ptrArr.end());
//unsigned size = ptrArr.size();
//for( unsigned i = 0; i < size; ++i ) s.insert( ptrArr[i] );
//ptrArr.assign( s.begin(), s.end() );
//ptrArr.erase(unique(ptrArr.begin(), ptrArr.end()), ptrArr.end());
     for (size_t m = 0; m < n; m++) {                 // для всего массива
        //cout << ptrArr[m] << endl;
        for (size_t i = 0; i < n; i++) {           // для хвоста
            if (cmp(m,i)<0) {
            	if(cmp(ptrArr[m] , ptrArr[i])==0)  // если равны
                {
                for (size_t k = i; k < n - 1; k++) { // сдвинуть
                    ptrArr[k] = ptrArr[k + 1];
                }
                n--;
                }
            }
        }
    }
     /*bool var;
    vector<int> temp_massive;
    size_t index = 0;
    for(size_t i = 0; i < n; i++) {
        int temp_el = ptrArr[i];
        var = true;
        for(size_t s = i; (s < n) && var; s++) {
            if(cmp(temp_el,ptrArr[s])==0) var = false;
            else if(s == n-1) {
                temp_massive[index] = ptrArr[i];
                index++;
            }
        }
    }
    for(size_t i = 0; i < index; i++) {
        ptrArr[i] = temp_massive[i];
    }*/
    }
void CVektor::DeleteOne(int det)
    {    
    for(size_t i = 0 ; i < n; i++){
    if(cmp(ptrArr[i],det)==0){
    n = n - 1;
    for (size_t j = i ; j < n ; j ++ )
    ptrArr[ j ] = ptrArr [ j + 1 ];
    }
    }
    }
void CVektor::GetVektor()        //Задать вектор
    {
        //cout << "Введите размерность вектора: "; cin >> n;
        for (size_t i=0; i < n; i++ )
        {
            cout << "Введите элемент вектора № " << i << ": ";
            cin >> ptrArr[i];
        }
    }
void CVektor::ShowVektor()       //Показать вектор
    {
        cout << "Вектор {";
        for (size_t i=0; i < n; i++)
        {  
         if(i<n-1)
            cout << ptrArr[i] << ", ";
         else
            cout << ptrArr[i];
        }    
        cout << "}\n";
    }
 
CVektor& CVektor::operator=(const CVektor& v)
    {
        if(this!=&v) 
        {//if(ptrArr!=NULL) //delete [] ptrArr;
         CopyOnly(v);}
        return *this;
    }
/*CVektor& CVektor::operator=( CVektor0 &b)
{ 
if(this!=&b )
{memcpy(ptrArr,b.getPtrArr(),b.getN()*sizeof(int)); n=b.getN();} 
return *this;
}*/
/*static */
int CVektor::Input(const char *fn, vector<CVektor*> &v, vector<CFabricVektor*> &fabric)
{
 ifstream f(fn); string str;
 while(getline(f,str))
 {
 //cout<<str<<endl;
  stringstream ss(str); istream_iterator<string> it(ss);
  //it=ss;
  if(it!=istream_iterator<string>())
  {
    CVektor *w=fabric[0]->Create();
    size_t i; char s[15]={0}; //++it;// size_t n=0;
    //b=(*it)[0]-'0';
    //++it;
    strcpy(s,it->c_str());
    //ss >> s;
    ++it;
      //cout<<"s="<<s<<endl;
    (*w).setText(s);
    for(i=0;/*i<n &&*/ it!=istream_iterator<string>();++it,i++) 
     {
      (*w).setPos(i,atof(it->c_str()));  
      //(*w)[i]=atof(it->c_str());
      //cout<<"setting w<"<<i<<">="<<*it<<endl;
      //cout<<*w;
     }
     //cout<<"vec="<<*w;
    v.push_back(w);
  }
 }
return 0;
}
  
/////CVektor1
int CVektor1::output()
{
  // char mystring[100];
 
   //if (f == NULL) perror("Ошибка открытия файла");
   //else
  
  std::ofstream foutput;
   if (!foutput) {
    cout << "File error - can't open to write data!";
    cin.sync(); cin.get(); throw -1;
   }
  
   foutput.open(OutFile, ios::out | ios::app);
   {
       foutput<<"{";
       for(size_t i=0;i<n;i++){foutput<<" "<<ptrArr[i];} 
       foutput<<" }\n";
        // cout<<*this;
         //foutput<<this;
  
          
    foutput.close();
  }
return 0;
}
    
    
    
/////////OPERATORS///////////////
/*CVektor& operator+(const CVektor &lhs, const CVektor &rhs)
{
 if(lhs.getN()==rhs.getN())
     {
     //const CVektor& w=rhs; 
     const CVektor& u=lhs; 
     //const CVektor& tmpl=lhs; const CVektor& tmpr=rhs;
     CVektor& l=const_cast<CVektor&>(u);//=const_cast<CVektor&>(w);
     //CVektor& r=const_cast<CVektor&>(tmpr);
     CVektor& res=l;//CVektor& res(lhs.getN());
     for (size_t i=0; i < lhs.getN(); i++ ) {
        (res).setPos(i, (lhs).getPtrArr()[i]+(rhs).getPtrArr()[i]);
        //r[i]=lhs[i]+rhs[i];
        }
     return (res);
     }
    else 
    {
     cout << "Вектора должны быть одинаковой длины!\n"; 
     throw -1;
    }
}
//поменять? это не похоже на правду... мняются исходники либо отбрасывается квалификатор...
CVektor& operator-(const CVektor &lhs, const CVektor &rhs) 
{
 if(lhs.getN()==rhs.getN())
     {
     const CVektor& tmpl=lhs; const CVektor& tmpr=rhs;
     CVektor& l=const_cast<CVektor&>(tmpl);//=const_cast<CVektor&>(w);
     CVektor& r=const_cast<CVektor&>(tmpr);
     CVektor& res=r;
     for (size_t i=0; i < lhs.getN(); i++ ) {
        (res)[i]= (l).getPtrArr()[i]+(r).getPtrArr()[i];
        }
     return (res);
     }
    else 
    {
     cout << "Вектора должны быть одинаковой длины!\n"; 
     throw -1;
    }
} */

CVektor1 operator+(const CVektor1&a,const CVektor1&b)
{          
 if(a.getN()!=b.getN())
  {
     cout << "Вектора должны быть одинаковой длины!\n"; 
     throw -1;
  } 	
 CVektor1 w(a.getPtrArr(),a.getN());
 for(size_t i=0;i<w.getN();i++)
  w.setPos(i,a.getPtrArr()[i]+b.getPtrArr()[i]);
 return w;
}

CVektor1 operator-(const CVektor1&a,const CVektor1&b)
{
 if(a.getN()!=b.getN())
  {
     cout << "Вектора должны быть одинаковой длины!\n"; 
     throw -1;
  }   	
 CVektor1 w(a.getPtrArr(),a.getN());
 for(size_t i=0;i<w.getN();i++)
  w.setPos(i,a.getPtrArr()[i]-b.getPtrArr()[i]);
 return w;
}

int CVektor::operator *(const CVektor &v)
    {
      int r=0;
     //n=v.n;
     if(n==v.n)
     {
     for (size_t i=0; i < v.n; i++ ) {
        r += v.ptrArr[i]*ptrArr[i];
        }
     return r;
     }
    else 
    {
     cout << "Вектора должны быть одинаковой длины!\n"; 
     throw -1;
    }
    }

//////////////////FRIEND FUNCTIONS////////////////////////

ostream &operator<<(ostream& cout, CVektor &v) 
{
   cout << "Вектор {";
     for (size_t i=0; i < v.n; i++)
     { 
     if(i<v.getN()-1)
 //        cout << v.getPtrArr()[i]  << ", ";
       cout << v.ptrArr[i]  << ", ";
     else //if(i == v.n-1)
 //        cout << v.getPtrArr()[i]; 
        cout << v.ptrArr[i] ;
     }    
   cout << "}\n";

return cout;
}
ostream &operator<<(ostream& cout, CVektor1 v) 
{
   cout << "Вектор {";
     for (size_t i=0; i < v.n; i++)
     { 
     if(i<v.getN()-1)
 //        cout << v.getPtrArr()[i]  << ", ";
       cout << v.ptrArr[i]  << ", ";
     else //if(i == v.n-1)
 //        cout << v.getPtrArr()[i]; 
        cout << v.ptrArr[i] ;
     }    
   cout << "}\n";

return cout;
}

istream &operator>>(istream& cin , CVektor &v) 
{
 for (size_t i=0,p; i < v.getN(); i++ )
        {
            cout << "Введите элемент вектора № " << i << ": ";
            cin >> p;      //v.ptrArr[i];
            v.ptrArr[i]=p;
        }
return cin;
}


