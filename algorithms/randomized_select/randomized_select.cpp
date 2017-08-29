/*第k小数（快排）*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<memory.h>
#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

//将数组随机划分成两段
int randomizeParition(int* arr, int p, int r){
	srand((int)time(0));
	int pivot = (rand()%(r-p+1))+p;//p<=pivot<=r
	int temp = 0;
	
	temp = arr[r];
	arr[r] = arr[pivot];
	arr[pivot] = temp;
	
	int i = p-1;
	int j = p;
	for(;j<r;j++){
		if(arr[j]<arr[r]){
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	
	i++;
	temp = arr[i];
	arr[i] = arr[r];
	arr[r] = temp;
	return i;
}

//返回第k小数的值
int randomizedSelect(int* arr, int p, int r, int k){
	if(p>=r) return arr[p];
	
	int q = randomizeParition(arr,p,r);
	int i = q-p+1;
	if(i==k) return arr[q];
	else if(i>k){
		return randomizedSelect(arr,p,q-1,k);
	}
	else{
		return randomizedSelect(arr,q+1,r,k-i);
	}
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
	
	fstream fout(argvs[2], ios::out);
	int min;
	for(int i=0; i<length; i++){
		min = randomizedSelect(arr,0,length-1,i+1);
		fout<< setw(5)<< min;
		if(i%20==19) fout<< endl;
		
		cout<< "i: "<< i<< endl;
		cout<< "min: "<< min<< endl;
		cout<< "arr: "<< endl;
		for(int i=0; i<length; i++)
			cout<<arr[i] <<" ";
		cout<< endl<< endl;
	}
	fout<< endl;
	fout.close();
	
	
	cout<< "Done."<< endl;
	return 0;	
}