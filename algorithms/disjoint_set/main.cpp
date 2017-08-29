/* main */
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<memory.h>
#include<time.h>
#include"disjoint_set.cpp"

using namespace std;

int main(int argc, char** argv){
	const int MAX_SIZE = 30;
	DisjointSet D(MAX_SIZE);
	
	srand((int)time(0));
	
	int test_times = rand()%30+15;
	printf("find和union的总次数: %d\n", test_times);
	int temp1, temp2;
	for(int t=0; t<test_times; t++){
		printf("==========================\n");
		printf("==========================\n");
		temp1 = rand()%MAX_SIZE;
		temp2 = rand()%MAX_SIZE;
		if((rand()%2)==1){ //union
			printf("%d, union(%d,%d)\n", t, temp1,temp2);
			D.unionSet(temp1, temp2);
		}
		else{ //find
			printf("%d, find(%d)=%d\n", t, temp1, D.findSet(temp1));
		}
		D.printSet();
	}
	
	return 0;
}