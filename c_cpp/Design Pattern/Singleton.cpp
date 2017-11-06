/*
## [设计模式之`单例模式]( http://www.jellythink.com/archives/82 )
* 将构造函数声明为私有
* 用一个私有的静态指针变量指向类的唯一实例, 并用一个公有静态方法获取该实例. 
*/

#include <iostream>
using namespace std;

/**
V1 将唯一的实例放在静态方法(GetInstance)的静态局部变量中, 这样就使得每次调用GetInstance时都返回同一个实例, 由于没有手动new也就不需要手动delete.
**/
class Singleton{
public:
    static Singleton* GetInstance(){
        static Singleton m_instance;
        return &m_instance;
    }
    
    int GetData(){ return m_data++; }
    
private:
    Singleton(){ 
        cout<< "Singleton"<< endl;
        m_data = 0;
    }
    
    ~Singleton(){
        cout<< "~Singleton"<< endl;
    }
    
    int m_data;
};


/**
V2 用内部类释放资源, 避免忘记释放资源的情况
**/
class Singleton2{
public:
    static Singleton2* GetInstance(){
        return m_instance;
    }
    
    int GetData(){ return m_data++; }

private:
    Singleton2(){ 
        cout<< "Singleton2"<< endl;
        m_data = 0;
    }
    ~Singleton2(){
        cout<< "~Singleton2"<< endl;
    }
    
    int m_data;
    static Singleton2* m_instance;
    
    class GC{
    public:
        ~GC(){      // 在这释放所有资源
            if(m_instance != NULL){
                cout<< "---Destroy all resources"<< endl;
                delete m_instance;
                m_instance = NULL;
                cout<< "---All resources destroied."<< endl;
            }
        }
    };
    static GC gc;   // 在程序结束时, 系统会自动析构静态存储区的所有全局变量和静态变量
};
//在进入主函数之前, 由主线程以单线程方式完成了初始化, 从而保证了线程安全性. 
Singleton2* Singleton2::m_instance = new Singleton2();
Singleton2::GC Singleton2::gc;


/**************/
int main(){
    cout<< "---Testing for V1"<< endl;
    Singleton* singleton = Singleton::GetInstance();
    cout<< singleton->GetData()<< endl;

    singleton = Singleton::GetInstance();
    cout<< singleton->GetData()<< endl;

    cout<< "---Testing for V2"<< endl;
    Singleton2* s = Singleton2::GetInstance();
    cout<< s->GetData()<< endl;

    s= Singleton2::GetInstance();
    cout<< s->GetData()<< endl;

    return 0;
}