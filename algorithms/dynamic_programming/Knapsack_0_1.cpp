/** 0-1背包问题
 * http://blog.csdn.net/mu399/article/details/7722810
 * 子结构：
		对于一个给定物品i，比较选择i形成的子问题的最优解与
		不选择i形成的最优解，选二者中的最优。
		
 * 转移方程：
		n			商品总件数
		w[i]		商品i的重量
		v[i]		商品i的价格
		c			背包容量
		m[i,j]		前i件([0,i])商品放入容量为j的背包中获得的最大价值
	m[i,j] = max{m[i-1,j-w[i]]+v[i], m[i-1,j]}
					选i			  , 不选i

 * 递归版伪代码
	knap_rec(i,j){
		if(i==0){
			if(w[i]<=j) return v[i];
			else return 0;
		}
		return max(knap_rec(i-1, j-w[i])+v[i],knap_rec(i-1,j));
	}
	Knap(n,c){
		return knap_rec(n,c);
	}

 * 带备忘递归版
	knap_mem_rec(i,j, m){
		if(i==0){
			if(w[i]<=j) return v[i];
			else return 0;
		}
		
		if(m[i,j] == 0) 
			m[i,j] = max(knap_mem_rec(i-1, j-w[i], m)+v[i], knap_mem_rec(i-1,j, m));
		
		return m[i,j];
	}
	
	Knap(n,c){
		set m to 0;
		return knap_mem_rec(n,c, m);
	}
*/
/* 自底向上，非递归版*/
#include<memory.h>
#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

int Knap(int n, int c, int* w, int* v){
	int m[n][c+1];
	int i,j;
	memset(m, 0, n*(c+1)*sizeof(int));
	
	int temp = 0;
	for(j=c; j>=w[0]; --j)
		m[0][j] = v[0];
	for(i=1; i<n; ++i){
		for(j=1; j<=c; ++j){
			if(j-w[i]>=0)
				m[i][j] = m[i-1][j-w[i]]+v[i];
			
			if(m[i][j]<m[i-1][j]) 
				m[i][j] = m[i-1][j];
		}
	}
	
	printf("商品选择方案: ");
	for(i=n-1, j=c; i>=0; --i){
		if(m[i][j] != m[i-1][j]){
			printf("%5d", i);
			j -= w[i];
		} 
	}
	printf("\n");
	
	printf("m:\n");
	for(i=0; i<n; ++i){
		for(j=0; j<=c; ++j){
			printf("%5d", m[i][j]);
		}
		printf("\n");
	}
	
	return m[n-1][c];
}

int main(int argc, char** argv){
	if(argc != 2){
		printf("Not enough arguments.\n");
		return -1;
	}
	
	const int MAX_SIZE = 100;
	int w[MAX_SIZE];
	int v[MAX_SIZE];
	int n, c;
	
	fstream fin(argv[1], ios::in);
	fin>> n>> c;
	for(int i=0; i<n; ++i)
		fin>> w[i];
	for(int i=0; i<n; ++i)
		fin>> v[i];
	fin.close();
	
	cout<< "最大价值: "<< Knap(n, c, w, v)<< endl;
	
	return 0;
}
















