/**
## ZOJ 2095 Divisor Summation

### 题目
- 求x的所有因子(x本身除外)之和. 

### 思路
- 由于已经给出了取值范围, 直接打表即可.
**/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

const int MAX_N = 500000;

int g_table[MAX_N];

int main(){
	// memset(g_table, 0, MAX_N*sizeof(int));
	for (int n = 1; n <= MAX_N/2; ++n){
		g_table[n] = 0;
	}
	for (int n = 1; n <= MAX_N/2; ++n){
		for (int i = 2; n*i <= MAX_N; ++i){
			g_table[n*i] += n;
		}
	}
/*
	for (int i = 0; i < 100; ++i){
		printf("%03d ", g_table[i]);
		if (i%10 == 9) printf("\n");
	}
*/
	int t, n;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		printf("%d\n", g_table[n]);
	}

	return 0;
}
