/*
 最大子数组
 问题背景：股票的低价买进，高价卖出，实现收益最大化
 问题描述：给定一段时间内股票的价格变化，求一段日期，使得从第一天到最后一天的股票价格净变化值最大。
 思路：从每日价格变化的角度考察输入，而非每日价格的角度
     ---第i天的价格变化定义为第i天和第i-1天的价格差。
 分治法求解：
   寻找数组A[low..high]的最大子数组A[i..j]，
   将A[low..high]划分为两个子数组A[low..mid]和A[mid+1..high]
   A[i..j]所处的位置有三种情况：
     * low<=i<=j<=mid 
	 * mid<i<=j<=high
	 * low<=i<=mid<j<=high 
*/

#include<memory.h>
#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

#define NINF (-2100000000)

//求跨越中点的最大子数组的边界及子数组的和
void maxCrossSubarray(int* arr, int low, int mid, int high, int& cross_low, int& cross_high, int& cross_sum){
	int left_sum = NINF;
	int sum = 0;
	for(int i=mid; i>=low; i--){
		sum += arr[i];
		if(sum>left_sum){
			left_sum = sum;
			cross_low = i;
		}
	}
	
	int right_sum = NINF;
	sum = 0;
	for(int j=mid+1; j<=high; j++){
		sum += arr[j];
		if(sum>right_sum){
			right_sum = sum; 
			cross_high = j;
		}
	}
	cross_sum = left_sum + right_sum;
}

void maxSubarray(int* arr, int low, int high, int& sub_low, int& sub_high, int& sub_sum){
	if(low==high){
		sub_low = low; sub_high = high; sub_sum = arr[low];
		return ;
	}
	
	int mid = (low+high)/2;
	
	int left_low, left_high, left_sum;
	maxSubarray(arr, low, mid,  left_low, left_high, left_sum);
	
	int right_low, right_high, right_sum;
	maxSubarray(arr, mid+1,high,  right_low, right_high, right_sum);
	
	int cross_low, cross_high, cross_sum;
	maxCrossSubarray(arr, low, mid, high,  cross_low, cross_high, cross_sum);
	
	if(left_sum>=right_sum && left_sum>=cross_sum){
		sub_low = left_low; sub_high = left_high; sub_sum = left_sum;
	}
	else if(right_sum>=left_sum && right_sum>=cross_sum){
		sub_low = right_low; sub_high = right_high; sub_sum = right_sum;
	}
	else{
		sub_low = cross_low; sub_high = cross_high; sub_sum = cross_sum;
	}
	return ;
}

int main(int argc, char* argvs[]){
	const int MAX_LENGTH = 100001;
	if(argc != 3){
		cout << "Need 2 arguements: input file and output file." << endl;
		return -1;
	}
	
	int length = 0;
	int arr[MAX_LENGTH];//每日的股票价格数组
	int dif[MAX_LENGTH];//价格差值数组
	
	memset(arr, 0, MAX_LENGTH*sizeof(int));
	memset(dif, 0, MAX_LENGTH*sizeof(int));
	
	fstream fin(argvs[1], ios::in);
	fin>>length;
	for(int i=0; i<length; i++){
		fin>>arr[i];
	}
	fin.close();
	for(int i=1; i<length; i++){
		dif[i] = arr[i]-arr[i-1];
	}
	
	int sub_low = 0;
	int sub_high = 0; 
	int sub_sum = 0;
	maxSubarray(dif,1,length-1, sub_low,sub_high,sub_sum);
	
	fstream fout(argvs[2], ios::out);
	fout<<"sub_low: "<<sub_low<<endl;
	fout<<"sub_high: "<<sub_high<<endl;
	fout<<"sub_sum: "<<sub_sum<< endl;
	fout<<"sub_arr: "<< endl;
	for(int i=sub_low; i<=sub_high; i++){
		fout<<setw(5)<<dif[i];
		if((i-sub_low)%20==19) fout<< endl;
	}
	fout<< endl;
	fout.close();
	cout<< "Done."<< endl; 
	
	return 0;
}



