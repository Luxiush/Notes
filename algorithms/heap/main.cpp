#include<iostream>
#include<fstream>
#include<iomanip>
#include"heap.cpp"

using namespace std;

int main(int argc, char* argvs[]){
	if(argc != 3){
		cout<< "Need 2 arguements: input file and output file."<< endl;
		return -1;
	}
	
	int arr[10000];
	int size = 1;
	fstream fin(argvs[1], ios::in);
	while(fin>> arr[size]){
		size++;
	}
	size --;
	fin.close();
	
	Heap H(arr, size);
	
	fstream fout(argvs[2], ios::out);
	H.buildMax();
	fout<< "建堆后："<< endl;
	for(int i=1; i<=H.size; i++){
		fout<< setw(5)<< H.heap[i];
		if(i%20==0) fout<< endl;
	}
	fout<< endl;
	
	H.sortAsc();
	fout<< "升序排列后："<< endl;
	for(int i=1; i<=H.size; i++){
		fout<< setw(5)<< H.heap[i];
		if(i%20==0) fout<< endl;
	}
	fout<< endl;	
	
	fout.close();
	cout<< "Done."<< endl;
	return 0;
}