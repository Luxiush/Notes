/*
## 查找二维数组
### 题目：
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
### 解法
#### 解法1:
对每行进行二分查找
#### 解法2:
从左下角开始, 如果大于目标值就向上走, 小于则向右走. 
*/

#include <iostream>
#include <vector>

using namespace std;

bool BinSearch(int target, vector<int> arr){
	if(arr.empty()) return false;
	int s = arr.size();
	if(target<arr[0] || target>arr[s-1])
		return false;
	
	int l = 0;
	int u = s-1;
	int mid = 0;
	while(l<u){
		mid = (l+u)/2;
		if(target==arr[mid])
			return true;
		else if(target<arr[mid])
			u = mid;
		else 
			l = mid+1;
	}
	if(target==arr[l])
		return true;
	return false;
}

bool Find(int target, vector<vector<int> > array) {
	if(array.empty()) return false;
	for(int r=0; r<array.size(); ++r){
		if(BinSearch(target, array[r]))
			return true;
	}
	
	return false;
}

int main(){
	int target = 0;
	int size = 0;
	cin>> size;
	
	int temp;

	vector<int> arr1;
	for(int i=0; i<size; ++i){
		cin>> temp;
		arr1.push_back(temp);
	}
	vector<int> arr2;
	for(int i=0; i<size; ++i){
		cin>> temp;
		arr2.push_back(temp);
	}
	
	vector< vector<int> > array;
	array.push_back(arr1);
	array.push_back(arr2);
	
	while(cin>> target)
		cout<< Find(target, array)<< endl;
}