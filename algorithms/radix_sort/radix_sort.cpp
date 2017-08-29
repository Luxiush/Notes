/*基于计数排序的基数排序*/

#include<memory.h>
#include<iostream>
#include<fstream>
#include<iomanip>
#include"counting_sort.cpp"

using namespace std;

void radixSort(int* in, int length){
	const int BASE = 255;
	int* byte = new int[length];
	int* buffer = new int[length];
	int digit;
	int i;
	
	for(digit = 0; digit<4; digit++){//一个int 4个bytes
		for(i=0; i<length; i++){
			byte[i] = (in[i]&(BASE<<(digit*8)))>>(digit*8); //取出in[i]的第digit个字节
		}
		countingSort(in,byte,buffer,length,BASE+1);
		int* temp = buffer;
		buffer = in;
		in = temp;
	}
	
	delete[] byte;
	delete[] buffer;
}

int main(int argc, char* argvs[]){
	if(argc != 3){
		cout<< "Need 2 arguements."<< endl;
		return -1;
	}
	
	const int MAX_SIZE = 10000;
	int arr[MAX_SIZE];
	memset(arr, 0, MAX_SIZE*sizeof(int));
	int length = 0;
	
	fstream fin(argvs[1], ios::in);
	while(fin>> arr[length]){
		length++;
	}
	fin.close();
	
	radixSort(arr, length);
	
	fstream fout(argvs[2], ios::out);
	for(int i=0; i<length; i++){
		fout<< setw(10)<< arr[i];
		if(i%15==14) fout<< endl;
	}
	fout<< endl;
	fout.close();
	
	cout<< "Done."<< endl;
	
	return 0;
}