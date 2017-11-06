#include <iostream>
#include <string>
using namespace std;

class Product{
public:
    string product_nam;
};
class ProductA: public Product{
public:
    ProductA(){ product_nam = "ProductA"; }
};
class ProductB: public Product{
public:
    ProductB(){ product_nam = "ProductB"; }
};

class Creator{
public:
    Product* CreateProduct(){ return DoCreateProduct(); }
protected:
    virtual Product* DoCreateProduct() = 0;
};
class CreatorA: public Creator{
protected:
    Product* DoCreateProduct(){ return new ProductA; }
};
class CreatorB: public Creator{
protected:
    Product* DoCreateProduct(){ return new ProductB; }
};

int main(){
    Product* pro = 0;
    Creator* creator = 0;
    
    creator = new CreatorA();
    pro = creator->CreateProduct();
    cout<< pro->product_nam<< endl;
    delete creator;
    delete pro;
    
    creator = new CreatorB();
    pro = creator->CreateProduct();
    cout<< pro->product_nam<< endl;
    delete creator;
    delete pro;

    return 0;
}