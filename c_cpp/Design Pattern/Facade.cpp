/*
## 设计模式之外观模式
* 将子系统的复杂逻辑进行封装, 对外提供一个简单的接口.
*/

#include <iostream>

using namespace std;

/* 子系统 */
class CPU{
public:
    void freeze(){ cout<< "CPU freeze"<< endl; }
    void jump(){ cout<< "CPU jump"<< endl; }
    void execute(){ cout<< "CPU execute"<< endl; }
};
class Memory{
public:
    void load(){ cout<< "Memory load"<< endl; }
};
class HardDrive{
public:
    void * read(){ cout<< "HardDrive read"<< endl; }
};

/* Facade */
class Computer{
public:
    void start(){
        cout<< "Computer initialing"<< endl;
        cpu.freeze();
        mem.load();
        cpu.jump();
        cpu.execute();
        cout<< "Computer started"<< endl;
    }

private:
    CPU cpu;
    Memory mem;
    HardDrive hd;
};

/* 客户端类 */
class User{
public:
    void use(){
        cout<< "Use using..."<< endl;
        C.start();
    }

private:
    Computer C;
};


int main(){
    User U;
    U.use();
    
    return 0;
}