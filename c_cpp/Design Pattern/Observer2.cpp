/*
## 设计模式之`观察者模式`v2
*/

#include <iostream>
#include <list>
using namespace std;

class Observer;

/*抽象目标, 定义接口, 不定义数据成员*/
class Subject{
public:
    virtual void RegisterObserver(Observer*) = 0;
    virtual void UnregistersterObserver(Observer*) = 0;
    virtual void NotifyObservers() = 0;

    // 提供给外部操作数据的接口
    virtual int func1() = 0;
    virtual int func2() = 0;
};

/*抽象观察者, 提供更新接口*/
class Observer{
public:
    virtual void OnSubjectUpdated(Subject*) = 0;
};

/*  */
class Observers{
public:
    void Attach(Observer* o){
        observers.push_back(o);
    }

    void Detach(Observer* o){
        observers.remove(o);
    }

    void Notify(Subject* sub){
        list<Observer*>::iterator iter = observers.begin();
        for(; iter != observers.end(); ++iter){
            (*iter)->OnSubjectUpdated(sub);
        }
    }

private:
    list<Observer*> observers;
};


/*观察者A*/
class ObserverA: public Observer{
public:
    ObserverA(int a): data_a(a){}
    void OnSubjectUpdated(Subject* sub){
        cout<< "ObserverA get Update. Get data through func1: "
            << sub->func1()<< endl;
    }

private:
    int data_a;
};

/*观察者B*/
class ObserverB: public Observer{
public:
    ObserverB(int b): data_b(b){}
    void OnSubjectUpdated(Subject* sub){
        cout<< "ObserverB get Update. Get data through func2: "
            << sub->func2()<< endl;
    }

private:
    int data_b;
};

/*具体目标*/
class SubjectA: public Subject{
public:
    SubjectA():data_1(111),data_2(222){}

    void RegisterObserver(Observer* o){
        observers.Attach(o);
    }
    void UnregistersterObserver(Observer* o){
        observers.Detach(o);
    }
    void NotifyObservers(){
        observers.Notify(this);
    }

    void DoSomething(){
        cout<< "SubjectA is doing something."<< endl;
    }

    int func1(){
        return data_1;
    }
    int func2(){
        return data_2;
    }

private:
    int data_1;
    int data_2;

    Observers observers;
};

/*main*/
int main(){
    cout<< "---Create Subject"<< endl;
    SubjectA *pSubject = new SubjectA;

    cout<< "---Create 2 Observers"<< endl;
    Observer *pObserverA = new ObserverA(1111);
    Observer *pObserverB = new ObserverB(2222);

    cout<< "---Attach Observers"<< endl;
    pSubject->RegisterObserver(pObserverA);
    pSubject->RegisterObserver(pObserverB);

    cout<< "---Notify Observer"<< endl;
    pSubject->DoSomething();
    pSubject->NotifyObservers();

    cout<< "---Detach ObserverA and Notify"<< endl;
    pSubject->UnregistersterObserver(pObserverA);
    pSubject->NotifyObservers();

    cout<< "---Done"<< endl;
    delete pSubject;
    delete pObserverA;
    delete pObserverB;

    return 0;
}
