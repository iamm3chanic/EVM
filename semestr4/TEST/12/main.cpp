#include <iostream>
#include <vector>

using namespace std;

class CVector{
protected:
    virtual int sum(int, int);

public:
    vector<int> cvector;

    CVector(){}
    CVector(int);
    CVector(const CVector&);
    virtual ~CVector(){}

   CVector& operator= (const CVector &v){
        cvector.clear();
        for (int it : v.cvector){
            cvector.push_back(it);
        }
        return *this;
    }

    CVector operator+ (const CVector &v){
        CVector tmp;
        for (size_t i = 0; i < cvector.size(); i++){
            tmp.cvector.push_back(sum(cvector[i], v.cvector[i]));
        }
        return tmp;
    }

};

CVector::CVector(int size): cvector(vector<int>(size)) {}

CVector::CVector(const CVector &v) {
    for (int it : v.cvector) {
        cvector.push_back(it);
    }
}

int CVector:: sum(int lhs, int rhs){
    return lhs+rhs;
}

class CVector1: public CVector{
private:
    int sum(int lhs, int rhs) override{
        return 2*(lhs+rhs);
    }

public:
    CVector1(){}
    CVector1(int size): CVector(size){}
    //CVector1(const CVector1&);
    CVector1(const CVector&);
    ~CVector1(){}

};

//CVector1::CVector1(const CVector1 &v) : CVector(v) {}

CVector1::CVector1(const CVector &v) : CVector(v) {}

int main(){

    CVector cv1, cv2;
    cv1.cvector.push_back(1);
    cv1.cvector.push_back(2);

    cv2.cvector.push_back(3);
    cv2.cvector.push_back(4);

    CVector1 cv3, cv4;
    cv3.cvector.push_back(1);
    cv3.cvector.push_back(2);

    cv4.cvector.push_back(3);
    cv4.cvector.push_back(4);

    cout<<"cv1: ";
    for (auto it : cv1.cvector){
        cout<<it<< ' ';
    }
    cout<<endl;

    cout<<"cv2: ";
    for (auto it : cv2.cvector){
        cout<<it<< ' ';
    }
    cout<<endl;

    cout<<"cv3: ";
    for (auto it : cv3.cvector){
        cout<<it<< ' ';
    }
    cout<<endl;

    cout<<"cv4: ";
    for (auto it : cv4.cvector){
        cout<<it<< ' ';
    }
    cout<<endl;

    //Тест на сложение векторов базового класса и оператор =
    cv1 = cv1 + cv2;
    cout<<"Test 1:\ncv1=cv1+cv2"<<endl;
    for (auto it : cv1.cvector){
        cout<<it<< ' ';
    }


    //Тест на сложение векторов дочернего класса и оператор =
    cv3 = cv3 + cv4;
    cout<<endl;
    cout<<"Test 2:\ncv3=cv3+cv4: "<<endl;
    for (auto it : cv3.cvector){
        cout<<it<< ' ';
    }

    //тест на оператор = (базового класса)
    cout<<endl;
    cv1 = cv2;
    cout<<"Test 3:\ncv1=cv2"<<endl;
    for (auto it : cv1.cvector){
        cout<<it<< ' ';
    }

    //тест конструктор копирования (дочернего класса)
    cout<<endl;
    CVector1 cv5(cv3);
    cout<<"Test 4:\ncv5(cv3)"<<endl;
    for (auto it : cv5.cvector){
        cout<<it<< ' ';
    }

	cout<<endl;
    CVector1 cv6(cv2);
    cout<<"Test 5:\ncv6(cv2)"<<endl;
    for (auto it : cv6.cvector){
        cout<<it<< ' ';
    }

    return 0;
}