/*生成一个随机数组*/

#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

int main(){
	const int MAX_SIZE = 500;
	const int RANGE_MAX = 1000000;
	
	fstream fout("input.txt", ios::out);
	
	srand((int)time(0));
	int length = rand()%MAX_SIZE;
	cout << "length: "<< length<< endl;
	
	for(int i=0; i<length; i++){
		fout<< setw(10)<< ((int)rand())%RANGE_MAX;
		if(i%15==14) fout<< endl;
	}
	fout<< endl;
	fout.close();
	
	cout<< "Done."<< endl;
	
	return 0;
}