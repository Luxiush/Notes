#include <iostream>

using namespace std;

// 具体的容器类, 基于数组
template <class _T>
class ContainerA{
public:
    // 内部迭代器类
    class Iterator{
    public: 
        bool operator!=(const Iterator& I){
            return index != I.index;
        }
        Iterator& operator=(const Iterator& I){
            index = I.index;
            outer = I.outer;
            return *this;
        }
        
        Iterator(ContainerA* o, _T* i):index(i),outer(o){}
        void operator++(){      // ++iter
            index += 1;
        }
        void operator++(int){   // iter++
            index += 1;
        }
        _T& operator*() const {
           return *index;
        }
    private:
        _T* index;
        ContainerA* outer;
    };
    
public: 
    ContainerA(){
        _MAX_SIZE = 1000;
        _data = new _T[_MAX_SIZE];
        _size = 0;
    }
    ~ContainerA(){
        delete [] _data;
        _data = 0;
    }
    Iterator begin(){
        return Iterator(this, _data);
    }
    Iterator end(){
        return Iterator(this, _data+_size);
    }
    
    void add(const _T& t){
        if(_size < _MAX_SIZE){
            _data[_size++] = t;
        }
    }

private: 
    _T* _data;
    int _size;
    int _MAX_SIZE;
};


// main
int main(){
    
    ContainerA<int> CA;
    CA.add(2);
    CA.add(5);
    CA.add(3);
    
    for(ContainerA<int>::Iterator iter = CA.begin(); iter != CA.end();++iter){
        cout<< *iter << "\t";
    }
    cout<< endl;
    
    return 0;
}
