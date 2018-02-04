/**
## 包含min函数的栈
### 题目:
设计一个能够得到最小元素的栈
### 思路:
用一个栈保存数据, 同时再构建一个辅助栈用来保存当前栈中的最小元素. 
**/

#include <iostream>
#include <stack>

using namespace std;

class MinStack{
public:
	MinStack(){}
	
	void push(int val){
		if(!S_min.empty()){
			if(val < _min_value)
				_min_value = val;
		}
		else{
			_min_value = val;
		}
		S_data.push(val);
		S_min.push(val);
	}
	void pop(){
		S_data.pop();
		S_min.pop();
	}
	int top(){
		return S_data.top();
	}
	int min(){
		return S_min.top();
	}

private:
	stack<int> S_data;		// 数据栈, 保存正常数据
	stack<int> S_min;		// 辅助栈, 保存当前栈中的最小元剩余
	int _min_value;			// 记录栈当前的最小值
};


int main(){
	
	return 0;
}