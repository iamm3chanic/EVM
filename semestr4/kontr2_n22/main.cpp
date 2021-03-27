#include "CVector.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>


void AutoTest() {
    vector<double>a(1);
    vector<double>b(1);
    a[0] = 0;
    b[0] = 1;
    CVectorHori A(a, 1);
    CVectorHori B(b, 1);
    CVectorHori C;
    C = A + B;
    if (!(C.Vector()[0] > 1)&&!(C.Vector()[0] < 1)) {
        printf("Autotest passed.\n");
    }
    else {
        printf("Autotest failed.\n");
    }
}

int main() {
    try {
        CVectorHori a;
        CVectorVert c,b;
        a[1] = 3;
        b[1] = 2;
        c = a + b;
        c.print();
        AutoTest();
        ifstream fin("data.txt");
        if (!fin.is_open()) {
            cout << "Error! Cannot open\n";
            return 1;
        }
        string str;
        string s;
        int m;
        double d;
        int n = 0;
        while (!fin.eof())
        {
            getline(fin,str);
            n++;
        }
        fin.seekg(0, ios_base::beg);
        fin.close();
        fin.open("data.txt");
        if (!fin.is_open()) {
            cout << "Error! Cannot open\n";
            return 1;
        }
        vector <CVector*> arr(n);
        map<string, Fabric*> factory;
        factory["Hori"] = new FabricHori;
        factory["Vert"] = new FabricVert;
        for (auto i = arr.begin(); i !=arr.end(); ++i) {
            fin >> s;
            *i = create(s, factory);
            fin >> s;
            (*i)->SetFileName(s);
            fin >> m;
            (*i)->Setn(m);
            for (int j = 0; j < m; ++j) {
                fin >> d;
                (*(*i))[j] = d;
            }
        }
        for (auto i = arr.begin(); i != arr.end(); ++i) {
            (*i)->output((*i)->GetFileName());
        }
        fin.close();
        delete factory["Hori"]; delete factory["Vert"];
        //for(int i=0;(i<(int)factory.size());i++)  {delete factory[i];}
        for (auto i = arr.begin(); i != arr.end(); ++i) { delete (*i);}
        return 0;
    }
    catch (int err) { printf("error=%d\n", err); }
}
