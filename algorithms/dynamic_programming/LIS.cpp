/*
最长递增子序列（LIS）
	* 状态转移方程：
		令	
			Last[n]表示以a[n]结尾的LIS，
			LIS[n]表示a[0..n]的LIS，
		则
			Last[n] = max{Last[i]+1 | 0<=i<n and a[n]>a[i]}
			LIS[n] = max{Last[i] | 0<=i<=n}
	
	* 
		
*/
#include<memory.h>
#include<string.h>
#include<iostream>
#include<fstream>

using namespace std;

void LIS(const int* arr, int len, int* res){
	int LIS_pre[len];	//记录在以arr[i]结尾的LIS中在arr[i]的前一个元素
	int LIS_len[len];	//记录以arr[i]结尾的LIS的长度
	int max_len = 0;    //LIS_len中最大值对应的下标
	
	memset(LIS_pre, 0, len*sizeof(int));
	memset(LIS_len, 0, len*sizeof(int));

	for(int i=0; i<len; i++){
		LIS_pre[i] = i;
		LIS_len[i] = 1;
	}
	
	for(int i=0; i<len; i++){
		for(int j=0; j<i; j++){
			if(arr[i]>arr[j] && (LIS_len[j]+1)>LIS_len[i]){
				LIS_len[i] = LIS_len[j]+1;
				LIS_pre[i] = j;
			}
		}
		if(LIS_len[i]>LIS_len[max_len]) 
			max_len = i; 
	}
	
	int res_len = LIS_len[max_len];
	res[0] = res_len;
	int i;
	for(i=max_len; LIS_pre[i]!=i; i=LIS_pre[i]){
		res[res_len--] = arr[i];
	}
	res[res_len--] = arr[i];
	
	printf(" i,  arr, LIS_pre,LIS_len\n");
	for(int i=0; i<len; i++){
		printf("%2d,%4d,%6d,%8d\n",i,arr[i],LIS_pre[i],LIS_len[i]);
	}
	printf("\n");
}

int main(int argc, char* argv[]){
	if(argc != 2){
		printf("ERROR\n");
		return -1;
	}
	
	const int MAXLEN=100;
	int arr[MAXLEN];
	int res[MAXLEN];
	int len = 0;
	memset(arr, 0, sizeof(int)*MAXLEN);
	memset(res, 0, sizeof(int)*MAXLEN);
	
	fstream fin(argv[1],ios::in);
	while(fin>>arr[len]) len++;
	fin.close();
	
	LIS(arr, len, res);
	printf("\nres: ");
	for(int i=1; i<=res[0]; i++){
		printf("%3d", res[i]);
	}
	printf("\n");

	return 0;
}










