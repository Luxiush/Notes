/*
	选择排序
*/
#include<memory.h>
#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

void selectSort(int* arr, int len){
	for(int cur=0; cur<len; cur++){
		int min = cur;//记录最小值的位置
		for(int i=min; i<len; i++){
			if(arr[i]<arr[min]){
				min = i;
			}
		}
		int temp = arr[min];
		arr[min] = arr[cur];
		arr[cur] = temp;
	}
}

int main(int argc, char* argv[]){
	if(argc!=3){
		cout << "need 2 arguements: input file and output file." << endl;
		return -1;
	}
	
	int buffer[1000];
	int length = 0;
	memset(buffer,0,sizeof(buffer));
	
	fstream file_in(argv[1],ios::in);
	file_in>>length;
	for(int i=0; i<length; i++){
		file_in>>buffer[i];
	}
	file_in.close();
	
	selectSort(buffer, length);
	
	fstream file_out(argv[2],ios::out);
	for(int i=0; i<length; i++){
		file_out<<setw(4)<<buffer[i];
		if(i%10==9) file_out<< endl;
	}
	file_out << endl;
	file_out.close();
	
	cout<< "Done!" <<endl;
	
	return 0;
}