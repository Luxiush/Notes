/*
## [设计模式之`修饰模式`]( https://zh.wikipedia.org/wiki/%E4%BF%AE%E9%A5%B0%E6%A8%A1%E5%BC%8F )
* 用一个修饰类包裹原来的类, 将原来的对象作为修饰类构造函数的参数. 
* 修饰类必须和原来的类有相同的接口. 

*/

#include <iostream>

using namespace std;

// 抽象类, 定义接口
class Component{
public:
    virtual ~Component(){ cout<< "~Component"<< endl; }
    virtual void Operation() = 0;
protected:
    Component(){cout<< "Component"<< endl;}
};

class ConcretComponent: public Component{
public:
    ConcretComponent(){ cout<< "ConcretComponent"<< endl; }
    ~ConcretComponent(){ cout<< "~ConcretComponent"<< endl; }
    void Operation(){ cout<< "Basic ConcretComponent Operation"<< endl; }
};

// 抽象修饰类 与 原来的类有相同的接口
class Decorator: public Component{
public: 
    Decorator(Component* com){ 
        cout<< "Decorator"<< endl; 
        this->_com = com; 
    }
    virtual ~Decorator(){ 
        cout<< "~Decorator"<< endl;
        delete this->_com;
        this->_com = 0;
    }
    virtual void Operation() = 0;

protected:
    Component* _com;
};

// 具体修饰类A
class ConcretDecoratorA: public Decorator{
public:
    ConcretDecoratorA(Component* com):Decorator(com){
        cout<< "ConcretDecoratorA"<< endl;
    }
    ~ConcretDecoratorA(){cout<< "~ConcretDecoratorA"<< endl;}
    void Operation(){
        cout<< "Extra Operation A"<< endl;
        this->_com->Operation();
    }
};

// 具体修饰类B
class ConcretDecoratorB: public Decorator{
public:
    ConcretDecoratorB(Component* com):Decorator(com){
        cout<< "ConcretDecoratorB"<< endl;
    }
    ~ConcretDecoratorB(){cout<< "~ConcretDecoratorB"<< endl;}
    void Operation(){
        cout<< "Extra Operation B"<< endl;
        this->_com->Operation();
    }
};

int main(){
    
    cout<< "---Create ConcretComponent---"<< endl;
    Component* pCom = new ConcretComponent();
    
    cout<< "---Add Decorator A---"<< endl;
    pCom = new ConcretDecoratorA(pCom);
    
    cout<< "---Add Decorator B---"<< endl;
    pCom = new ConcretDecoratorB(pCom);
    
    cout<< "---Operation---"<< endl;
    pCom->Operation();
    
    cout<< "---Done---"<< endl;
    delete pCom;
    
    return 0;
}