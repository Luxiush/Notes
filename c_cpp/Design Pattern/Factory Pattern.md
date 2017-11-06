## [设计模式之工厂模式(Factory Pattern)]( http://blog.csdn.net/wuzhekai1985/article/details/6660462 )

* 将类(产品)的实例化进行封装. 
* 工厂模式属于`创建型`模式, 大致可分为: 简单工厂模式, 工厂方法模式, 抽象工厂模式 三类. 


---
### 简单工厂模式 
* 在工厂类中做判断, 根据不同参数生产不同产品. 
* 当新增产品时, 需要修改工厂类. 

#### 示例代码:
有一家生产处理器的厂家, 只有一个工厂, 能够根据客户的需求生产A,B两种型号的处理器.
```c++
class SingleCore{
public:
    virtual void Show() = 0;
};
class SingleCoreA: public SingleCore{
public:
    void Show(){ cout<< "SingleCore A"<< endl; }
};
class SingleCoreB: public SingleCore{
public:
    void Show(){ cout<< "SingleCore B"<< endl; }
};

class Factory{
public:
    SingleCore* CreateSingleCore(char ctype){
        if(ctype == 'A') return new SingleCoreA();
        else if(ctype == 'B') return new SingleCoreB();
        else return 0;
    }
};

int main(){
    Factory fac();
    
    SingleCore* single_core = fac.CreateSingleCore('A');
    single_core->Show();
    delete single_core;
    
    single_core = fac.CreateSingleCore('B');
    single_core->Show();
    delete single_core;
    single_core = 0;

    return 0;
}
```


---
### 工厂方法模式 
* 定义一个用于创建对象(产品)的接口, 让子类(工厂类)决定实例化哪一个类(产品类). 
* 每增加一种产品就需要相应地增加一个工厂, 会导致很多工厂类的定义. 

#### 示例代码
生产处理器的厂家为A,B两种型号的处理器各开设一个工厂,每个工厂专门生产一种型号. 客户根据自己的需要选择工厂.
```c++
class SingleCore{
public:
    virtual void Show() = 0;
};
class SingleCoreA: public SingleCore{
public:
    void Show(){ cout<< "SingleCore A"<< endl; }
};
class SingleCoreB: public SingleCore{
public:
    void Show(){ cout<< "SingleCore B"<< endl; }
};

class Factory{
public:
    virtual SingleCore* CreateSingleCore() = 0;
};
class FactoryA: public Factory{
public:
    SingleCoreA* CreateSingleCore(){ return new SingleCoreA(); }
};
class FactoryB: public Factory{
public:
    SingleCoreB* CreateSingleCore(){ return new SingleCoreB(); }
};

int main(){
    SingleCore* single_core = 0;
    Factory* fac = 0;
    
    fac = new FactoryA();
    single_core = fac->CreateSingleCore();
    single_core->Show();
    delete single_core;
    
    fac = new FactoryB();
    single_core = fac->CreateSingleCore();
    single_core->Show();
    delete single_core;

    return 0;
}
```


---
### 抽象工厂模式 

* 在抽象工厂中提供一个创建一系列相关或相互依赖对象的接口，而无需指定它们具体的类

* 在产品族中扩展新的产品很困难, 需要修改抽象工厂的接口

#### 实例代码
处理器厂家又新增了一种多核处理器, 同样有A,B两种型号. 开设两个工厂, 每个工厂专门生产一种型号的单核和多核处理器. 
```c++
class SingleCore{
public:
    virtual void Show() = 0;
};
class SingleCoreA: public SingleCore{
public:
    void Show(){ cout<< "SingleCore A"<< endl;}
};
class SingleCoreB: public SingleCore{
public:
    void Show(){ cout<< "SingleCore B"<< endl;}
};

class MultiCore{
public:
    virtual void Show() = 0;
};
class MultiCoreA: public MultiCore{
public:
    void Show(){ cout<< "MultiCore A"<< endl;}
};
class MultiCoreB: public MultiCore{
public:
    void Show(){ cout<< "MultiCore B"<< endl;}
};

class Factory{
public:
    virtual SingleCore* CreateSingleCore() = 0;
    virtual MultiCore* CreateMultiCore() = 0;
};
class FactoryA: public Factory{
public:
    SingleCore* CreateSingleCore(){ return new SingleCoreA(); }
    MultiCore* CreateMultiCore(){ return new MultiCoreA(); }
};
class FactoryB: public Factory{
public:
    SingleCore* CreateSingleCore(){ return new SingleCoreB(); }
    MultiCore* CreateMultiCore(){ return new MultiCoreB(); }
};

int main(){
    Factory* fac = 0;
    SingleCore* single_core = 0;
    MultiCore* multi_core = 0;
    
    fac = new FactoryA();
    single_core = fac->CreateSingleCore();
    multi_core = fac->CreateMultiCore();
    single_core->Show();
    multi_core->Show();
    
    fac = new FactoryB();
    single_core = fac->CreateSingleCore();
    multi_core = fac->CreateMultiCore();
    single_core->Show();
    multi_core->Show();

    return 0;
}
```





