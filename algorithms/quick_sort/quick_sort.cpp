/*
快速排序
*/
#include<stdlib.h>
#include<time.h>
#include<memory.h>
#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

int partition(int* arr, int p, int r){
	int pivot = arr[r];
	int temp = 0;
	int i = p-1;//i指向当前小于pivot的最后一个元素
	for(int j=p; j<r; j++){//j指向当前不小于pivot的第一个元素
		if(arr[j]<pivot){
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	
	temp = arr[i+1];
	arr[i+1] = arr[r];
	arr[r] = temp;
	
	return i+1;	
}

void quickSort(int* arr, int p, int r){
	if(p>=r) return ;
	int q = partition(arr, p, r);
	quickSort(arr,p,q-1);
	quickSort(arr,q+1,r);
}

int main(int argc, char* argvs[]){
	if(argc!=3){
		cout<< "Need 2 arguements."<< endl;
		return -1;
	}
	const int MAX_SIZE = 10000;
	
	int arr[MAX_SIZE];
	int length = 0;
	memset(arr,0, MAX_SIZE*sizeof(int));
	
	fstream fin(argvs[1], ios::in);
	while(fin>> arr[length]){
		length ++;
	}
	fin.close();
	
	quickSort(arr,0,length-1);
	
	fstream fout(argvs[2], ios::out);
	fout<< length<< endl;
	for(int i=0; i<length; i++){
		fout<< setw(5)<< arr[i];
		if(i%20==19) fout<< endl;
	}
	fout<< endl;
	fout.close();
	
	cout<< "Done."<< endl;
	return 0;
}
