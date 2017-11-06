/*
## [设计模式之`原型模式`]( http://www.cnblogs.com/jiese/p/3164428.html )
* 提供一个通过已经存在对象创建新对象的接口`Clone`, 在c++中通过拷贝构造函数实现

*/

#include <iostream>

using namespace std;

class Prototype{
public: 
    virtual Prototype* Clone() const = 0;
    virtual ~Prototype(){
        cout<< "Protoype destructor"<< endl;
    }
    virtual void GetData(){
        cout<< "Prototype data: "<< this->data<< endl;
    }
protected:
    Prototype(){
        cout<< "Prototype constructor"<< endl;
        this->data = 1111;
    }
    
    int data;
};

class CroncreteA: public Prototype{
public:
    CroncreteA(){
        cout<< "CroncreteA constructor"<< endl;
    }
    CroncreteA(const CroncreteA& A){
        cout<< "CroncreteA copy constructor"<< endl;
        this->data = A.data;
    }
    ~CroncreteA(){
        cout<< "CroncreteA destructor"<< endl;
    }
    Prototype* Clone() const{
        cout<< "CroncreteA Clone"<< endl;
        return new CroncreteA(*this);
    }
    
    void GetData(){
        cout<< "CroncreteA data: "<< this->data<< endl;
    }
};

int main(){
    cout<< "---p1"<< endl;
    Prototype* p1 = new CroncreteA();
    p1->GetData();
    cout<< "---p2"<< endl;
    Prototype* p2 = p1->Clone();
    p2->GetData();
    
    cout<< "---delete"<< endl;
    delete p1;
    delete p2;
    
    return 0;
}