/*
 计数排序
 --- 对于每个输入元素x，确定小于x的元素个数，再根据这一信息直接把x输出到相应的位置上。
*/

#include<memory.h>
#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

/*in---输入数组， out---输出数组， k---数组元素的上界(in[i]<k)*/
void countingSort(int* in, int* out, int length, int k){
	int* temp = new int[k];
	int i;
	
	for(i=0; i<k; i++){
		temp[i] = 0;
	}	
	
	//统计数组每个元素出现的次数
	for(i=0; i<length; i++){
		temp[in[i]] += 1;
	}	
	
	//根据出现次数计算在输出数组中的位置
	for(i=1; i<k; i++){
		temp[i] += temp[i-1];
	}
	
	//为了保证稳定性，必须从后往前遍历输入数组
	for(i=length-1; i>=0; i--){
		out[temp[in[i]]-1] = in[i];
		temp[in[i]] -= 1;
	}
	
	delete[] temp;
}

int main(int argc, char* argvs[]){
	if(argc!=3){
		cout<< "Need 3 arguements."<< endl;
		return -1;
	}
	
	const int k = 21;
	const int MAX_SIZE = 10000;
	int arr[MAX_SIZE];
	int arr_out[MAX_SIZE];
	int length =0;
	memset(arr,0,MAX_SIZE*sizeof(int));
	memset(arr_out,0,MAX_SIZE*sizeof(int));
	
	fstream fin(argvs[1], ios::in);
	while(fin>> arr[length]){
		length++;
	}
	fin.close();
	
	countingSort(arr, arr_out, length, k);
	
	fstream fout(argvs[2], ios::out);
	for(int i=0; i<length; i++){
		fout<< setw(4)<< arr_out[i];
		if(i%20==19) fout<< endl;
	}
	fout<< endl;
	fout.close();
	
	cout<< "Done."<< endl;
	return 0;
}