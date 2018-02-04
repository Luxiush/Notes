/**
## 最小的k个数
### 题目
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
### Solution:
基于小根堆
**/

#include <iostream>
#include <vector>

using namespace std;


class Heap{
public:
    Heap(vector<int> data){
        heap_size = data.size();
        for(int i=0; i<heap_size; ++i){
            heap.push_back(data[i]);
        }
        heap_build();
    }
    
    int pop(){
        if(heap_size==0){
            heap.clear();
            return -1;
        }
        int top = heap[0];
        
        swap(0, heap_size-1);
        --heap_size;
        heapify(0);
        
        return top;
    }
	
	void print(){
		for(int i=0; i<heap.size(); ++i){
			cout<< heap[i]<< " ";
		}
		cout<< endl;
	}
    
private:
    vector<int> heap;
    int heap_size;
    
    int left_index(int i){
        ++i;
        if(2*i>heap_size)
            return -1;
        return 2*i-1;
    }
    int right_index(int i){
        ++i;
        if(2*i+1>heap_size)
            return -1;
        return 2*i;
    }
    void swap(int i, int j){
        int tmp = heap[i];
        heap[i] = heap[j];
        heap[j] = tmp;
    }
    
    void heapify(int i){
        int min_index = i;
        int l = left_index(i);
        int r = right_index(i);
		if(l!=-1 && heap[l]<heap[min_index]){
			min_index = l;
		}
		if(r!=-1 && heap[r]<heap[min_index]){
			min_index = r;
		}
		if(min_index != i){
			swap(i, min_index);
			heapify(min_index);
		}
    }
    
    void heap_build(){
        for(int i=heap_size/2; i>=0; --i){
            heapify(i);
        }
    }
};

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
		if(k > input.size()) return res;
        Heap H(input);
        for(int i=0; i<k; ++i){
            res.push_back(H.pop());
        }
        
        return res;
    }

};


int main(){
	vector<int> input;
	int size = 0;
	cin>> size;
	int tmp = 0;
	for(int i=0; i<size; ++i){
		cin >> tmp;
		input.push_back(tmp);
	}

	Solution S;
	vector<int> res;
	res = S.GetLeastNumbers_Solution(input, 4);
	for(int i=0; i<res.size(); ++i){
		cout<< res[i]<< " ";
	}
	cout << endl;
	
	return 0;
}