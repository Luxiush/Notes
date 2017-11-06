/*
## [设计模式之`桥接模式`]( https://zh.wikipedia.org/wiki/%E6%A9%8B%E6%8E%A5%E6%A8%A1%E5%BC%8F )
* 将`对象`与`具体行为`分离, 单独分装
*/

#include <iostream>

using namespace std;

class DrawApi{
public:
    DrawApi(){ cout<< "DrawApi"<< endl; }
    virtual ~DrawApi(){ cout<< "~DrawApi"<< endl; }
    virtual void Draw() = 0;
};

class DrawCircle: public DrawApi{
public:
    DrawCircle(){ cout<< "DrawCircle"<< endl; }
    ~DrawCircle(){ cout<< "~DrawCircle"<< endl; }
    void Draw(){ cout<< "Draw Circle"<< endl; }
};

class DrawRectangle: public DrawApi{
public:
    DrawRectangle(){ cout<< "DrawRectangle"<< endl; }
    ~DrawRectangle(){ cout<< "~DrawRectangle"<< endl; }
    void Draw(){ cout<< "Draw Rectangle"<< endl; }
};

/****/
class Shape{
public:
    Shape(DrawApi* da){
        cout<< "Shape"<< endl;
        this->da = da;
    }
    virtual ~Shape(){ 
        cout<< "~Shape"<< endl;
        delete this->da;
        this->da = 0;
    }
    
    virtual void Draw() = 0;

protected:
    DrawApi* da;
};

class Circle: public Shape{
public:
    Circle(DrawApi* da):Shape(da){ cout<< "Circle"<< endl; }
    ~Circle(){ cout<< "~Circle"<< endl; }
    
    void Draw(){
        cout<< "Circle::Draw"<< endl;
        this->da->Draw();
    }
};

class Rectangle: public Shape{
public:
    Rectangle(DrawApi* da):Shape(da){ cout<< "Rectangle"<< endl; }
    ~Rectangle(){ cout<< "~Rectangle"<< endl; }
    
    void Draw(){
        cout<< "Rectangle::Draw"<< endl;
        this->da->Draw();
    }
};


int main(){
    
    Shape* ps = 0;
    
    cout<< "---Circle---"<< endl;
    ps = new Circle(new DrawCircle());
    ps->Draw();
    delete ps;
    
    cout<< "---Rectangle---"<< endl;
    ps = new Rectangle(new DrawRectangle());
    ps->Draw();
    delete ps;
    
    ps = 0;
    cout<< "Done"<< endl;
    
    return 0;
}