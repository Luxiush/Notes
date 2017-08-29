#include <iostream>
#include <memory.h>

using namespace std;

int main(){
	const int MAXSIZE = 20;
	int arr[MAXSIZE];
	memset(arr, -1, MAXSIZE*sizeof(int));
	
	for(int i=0; i<MAXSIZE; ++i){
		printf("%3d",arr[i]);
	}
	printf("\n");
}