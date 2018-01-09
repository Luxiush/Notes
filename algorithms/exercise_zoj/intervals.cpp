/*
## ZOJ 1508 Intervals
### 题目
> 有一个序列，题目用n个整数组合 [ai，bi，ci]来描述它，[ai，bi，ci]表示在该序列中处于[ai，bi]这个区间的整数至少有ci个。如果存在这样的序列，请求出满足题目要求的最短的序列长度是多少。如果不存在则输出 -1。

### 思路
<https://wenku.baidu.com/view/0162ad40ed630b1c59eeb5f2.html>
- 差分约束系统建图, 然后用`Bellman Ford`算法求最短路径. 

### 参考代码
<http://www.cnblogs.com/GO-NO-1/p/3440954.html>

*/

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

//const int INF = 0x7ffffff;
const int MAX_SIZE = 50005;

struct edge{
	int u, v, w;
};

bool bellman_ford(edge* edges, int* dist, int num_e, int num_v){
	bool flag;
	for (int v = 0; v < num_v; ++v){
		flag = false;
		for (int e = 0; e < num_e; ++e){
			if (dist[edges[e].v] > dist[edges[e].u] + edges[e].w){
				dist[edges[e].v] = dist[edges[e].u] + edges[e].w;
				flag = true;
			}
		}
		if (!flag) break;
	}
	
	for ( int e = 0; e < num_e; ++e){
		if (dist[edges[e].v] > dist[edges[e].u] + edges[e].w){
			return false;
		}
	}
	
	return true;
}

edge g_edges[3*MAX_SIZE];
int g_dist[MAX_SIZE];

int main(){
	int num_e = 0;
	int num_v = 0;
	
	int u, v, w;
	while (cin >> num_e){
		for (int i = 0; i < num_e; ++i){
			cin >> u >> v >> w;
			// map(v, u-1) = -w
			g_edges[i].u = v;
			g_edges[i].v = u-1;
			g_edges[i].w = -w;
			
			num_v = num_v < v ? v : num_v;
			num_v = num_v < u ? u : num_v;
		}
		
		for (int i = 0; i <= num_v; ++i){
			g_dist[i] = 0;
			
			// map(i, i+1) = 1
			g_edges[num_e].u = i;
			g_edges[num_e].v = i+1;
			g_edges[num_e].w = 1;
			num_e += 1;
			
			// map(i+1, 1) = 0
			g_edges[num_e].u = i+1;
			g_edges[num_e].v = i;
			g_edges[num_e].w = 0;
			num_e += 1;
		}		
		
		if (!bellman_ford(g_edges, g_dist, num_e, num_v)){
			cout << -1 << endl;
		}
		else{
			cout << -g_dist[0] << endl;
		}
		/*
		cout << "----" << endl;
		for (int i = 0; i <= num_v; ++i){
			cout << g_dist[i] << "\t";
		}
		cout << "\n===" << endl;
		*/
	}
	
	return 0;
}

