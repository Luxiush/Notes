//归并排序
#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

#define INF (2147483647)

void merge(int* arr, int p, int q, int r){
	int n1 = q-p+1; //p<=i && i<=q
	int n2 = r-q;   //q+1<=i && i<=r
	
	int L1[n1+1];
	for(int i=0; i<n1; i++){
		L1[i] = arr[p+i];
	}
	L1[n1] = INF;
	
	int L2[n2+1];
	for(int i=0; i<n2; i++){
		L2[i] = arr[q+1+i];
	}
	L2[n2] = INF;
	
	int i=0, j=0;
	for(int k=p; k<=r; k++){
		if(L1[i]<L2[j]){
			arr[k] = L1[i++];
		}
		else{
			arr[k] = L2[j++];
		}
	}
}

void mergeSort(int* arr, int p, int r){//对arr的第p个到第r个元素归并排序
	if(p>=r) return;
	
	int q=(p+r)/2;
	mergeSort(arr, p,q);
	mergeSort(arr, q+1,r);
	merge(arr,p,q,r);
}

int main(int argc, char* argvs[]){
	if(argc <3){
		cout << "ERROR: need 2 arguements: input file and out put file." << endl;
	}
	
	int arr[1000];
	int length = 0;
	
	fstream fin(argvs[1], ios::in);
	fin >> length;
	for(int i=0; i<length; i++){
		fin >> arr[i];
	}
	fin.close();
	
	mergeSort(arr,0,length-1);
	
	fstream fout(argvs[2], ios::out);
	for(int i=0; i<length; i++){
		fout << setw(5) << arr[i];
		if(i%20==19) fout << endl;
	}
	fout << endl;
	fout.close();
	
	cout <<"Done."<<endl;
	
	return 0;
}