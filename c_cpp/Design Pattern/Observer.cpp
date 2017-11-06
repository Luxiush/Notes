/*
## 设计模式之`观察者模式`
*/

#include <iostream>
#include <list>
using namespace std;

/*抽象观察者, 提供更新接口*/
class Observer{
public: 
    virtual void Update(int) = 0;
};

/*抽象目标, 提供注册,删除和通知观察者对象的接口*/
class Subject{
public:
    virtual void Attach(Observer*) = 0;
    virtual void Detach(Observer*) = 0;
    virtual void Notify() = 0;
};

/*观察者A*/
class ObserverA: public Observer{
public:
    ObserverA(Subject* pSubject): m_pSubject(pSubject){}
    void Update(int val){
        cout<< "ObserverA get Update. New State: "<< val<< endl;
    }

private:
    Subject* m_pSubject;
};

/*观察者B*/
class ObserverB: public Observer{
public:
    ObserverB(Subject* pSubject): m_pSubject(pSubject){}
    void Update(int val){
        cout<< "ObserverB get Update. New State: "<< val<< endl;
    }

private:
    Subject* m_pSubject;
};

/*具体目标*/
class SubjectA: public Subject{
public:
    void Attach(Observer* pObserver){
        m_ObserverList.push_back(pObserver);
    }
    void Detach(Observer* pObserver){
        m_ObserverList.remove(pObserver);
    }
    void Notify(){
         std::list<Observer *>::iterator it = m_ObserverList.begin();
         while (it != m_ObserverList.end())
         {
              (*it)->Update(m_iState);
              ++it;
         }
    }
    
    void SetState(int stat){
        m_iState = stat;
    }
    
private:
    list<Observer*> m_ObserverList;
    int m_iState;
};

/*main*/
int main(){
    cout<< "---Create Subject"<< endl;
    SubjectA *pSubject = new SubjectA;
    
    cout<< "---Create 2 Observers"<< endl;
    Observer *pObserverA = new ObserverA(pSubject);
    Observer *pObserverB = new ObserverB(pSubject);
    
    cout<< "---Attach Observers"<< endl;
    pSubject->Attach(pObserverA);
    pSubject->Attach(pObserverB);
    
    cout<< "---Notify Observer"<< endl;
    pSubject->SetState(2);
    pSubject->Notify();
    
    cout<< "---Detach ObserverA and Notify"<< endl;
    pSubject->Detach(pObserverA);
    pSubject->Notify();
    
    cout<< "---Done"<< endl;
    delete pSubject;
    delete pObserverA;
    delete pObserverB;
    
    return 0;
}
