/*
## [设计模式之访问者模式]( http://www.jb51.net/article/55999.htm )
* 在不破坏类的前提下, 为类增加新操作

* 访问者容易变动, 但是元素类不能所以变动, 一旦具体元素类发生改变则所有的访问者都要发生改变. 
*/

#include <iostream>
#include <list>

using namespace std;

class Element;


// Visitor
class Visitor{
public:
    virtual ~Visitor(){}
    virtual void VisitA(Element* elm) = 0;   // 针对 ElementA 的访问方法
    virtual void VisitB(Element* elm) = 0;   // 针对 ElementB 的访问方法
protected:
    Visitor(){}
};


// Element
class Element{
public:
    virtual ~Element(){}
    virtual void Accept(Visitor* v) = 0;
    
protected:
    Element(){}
};
class ElementA: public Element{
public:
    int _data_a;
    
    ElementA(){ _data_a = 111; }
    ~ElementA(){}
    
    void Accept(Visitor* v){
        v->VisitA(this);    // 只接受针对自己的访问方法
    }
};
class ElementB: public Element{
public:
    int _data_b;
    
    ElementB(){ _data_b = 222; }
    ~ElementB(){}
    
    void Accept(Visitor* v){
        v->VisitB(this);     // 只接受针对自己的访问方法
    }
};


class VisitorA: public Visitor{
public:
    void VisitA(Element* elm){
        cout<< "VisitorA get data from ElementA: "<< ((ElementA*)elm)->_data_a<< endl;
    }
    void VisitB(Element* elm){
        cout<< "VisitA is visiting ElementB"<< endl;
    }
};
class VisitorB: public Visitor{
public:
    void VisitA(Element* elm){
          cout<< "VisitB is visiting ElementA"<< endl;
    }
    void VisitB(Element* elm){
        cout<< "VisitorB get data from ElementB: "<< ((ElementB*)elm)->_data_b<< endl;
    }
};


// 对象结构
class ObjectStructure{
public:
    void Attach(Element* e){
        L.push_back(e);
    }
    void Detach(Element* e){
        L.remove(e);
    }
    void Accept(Visitor* v){
        for(list<Element*>::iterator it=L.begin(); it!=L.end(); ++it){
            (*it)->Accept(v);
        }
    }
    
    ~ObjectStructure(){
        for(list<Element*>::iterator it=L.begin(); it!=L.end(); ++it){
            delete *it;
        }
    }

private:
    list<Element*> L;
};


int main(){
    cout<< "---Initialing"<< endl;
    ObjectStructure O;
    O.Attach(new ElementA());
    O.Attach(new ElementB());
    
    Visitor* v = 0;
    
    cout<< "---VisitorA"<< endl;
    v = new VisitorA();
    O.Accept(v);
    delete v;
    
    cout<< "---VisitorB"<< endl;
    v = new VisitorB();
    O.Accept(v);
    delete v;
    
    cout<< "Done"<< endl;
    
    return 0;
}