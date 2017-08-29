/*堆的实现*/
#include<iostream>

using namespace std;

class Heap{
public:
	const int MAX_SIZE;
	int size;
	int* heap;
	
	Heap(int* arr, int size);
	~Heap(){}
	
	int parentNode(int i){
		return i/2;
	}
	int leftChild(int i){
		return 2*i;
	}
	int rightChild(int i){
		return 2*i+1;
	}
	
	void maxHeapify(int i);
	void buildMax();
	void sortAsc();

};

Heap::Heap(int* arr, int size)
  :MAX_SIZE(10000){
	this->size = size;
	this->heap = arr;
}

//堆的维护
void Heap::maxHeapify(int i){
	int left = leftChild(i);
	int right = rightChild(i);
	int max = i;
	
	if(left<=size && heap[left]>heap[max]){
		max = left;
	}
	if(right<=size && heap[right]>heap[max]){
		max = right;
	}
	
	if(max != i){
		int temp = heap[i];
		heap[i] = heap[max];
		heap[max] = temp;
		
		maxHeapify(max);
	}
}

//自底向上构建最大堆
void Heap::buildMax(){
	for(int i=size/2; i>=1; i--){
		maxHeapify(i);
	}
}

//升序排序
void Heap::sortAsc(){
	int s = size;
	int temp = 0;
	for(int i=size; i>=2; i--){
		temp = heap[size];
		heap[size] = heap[1];
		heap[1] = temp;
		size --;
		
		maxHeapify(1);
	}
	size = s;
}



