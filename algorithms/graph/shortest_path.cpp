#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

const int MAX_SIZE = 300;


void Dijkstra(int adj[][MAX_SIZE], int p_no, int src, int dest, vector<int>& dist2src, vector<int>& pre){
	vector<int> visited(p_no,0);
	// vector<int> found(adj.size(), 0);
	
	int next_src = src;
	int dist = 0;
	while(visited[src]==0){
		visited[src] = 1;
		for(int i=0; i<p_no; ++i){
			if(adj[src][i] == -1)
				continue;
			dist = dist2src[src] + adj[src][i];
			if(dist2src[i] == -1 || dist2src[i]>dist){
				dist2src[i] = dist;
				pre[i] = src;
			}
			
			if(visited[i] == 0){
				if(visited[next_src] == 1)
					next_src = i;
				else{
					if(dist2src[i]!=-1 && dist2src[i] < dist2src[next_src]){
						next_src = i;
					}
				}
			}
		}
		src = next_src;
	}
}



int main(){
	int point_no = 0;
	int edge_no = 0;
	int goods_no = 0;
	
	int adj[MAX_SIZE][MAX_SIZE] ;
	for(int i=0; i<MAX_SIZE; ++i){
		for(int j=0; j<MAX_SIZE; ++j){
			adj[i][j] = -1;
		}
	}
	
	int src = 0;
	int dest = 0;
	
	cin >> point_no >> edge_no >> goods_no;
	point_no += 1;
	
	vector<int> dist2src(point_no, -1);
	vector<int> pre(point_no, 0);
	for(int i=0; i<point_no; ++i){
		pre[i] = i;
	}
	vector<int> goods(point_no, 0);
	
	for(int i=0; i<edge_no; ++i){
		int x,y,w;
		cin>> x>> y>> w;
		adj[x][y] = w;
		adj[y][x] = w;
	}
	for(int i=1; i<=goods_no; ++i){
		int index, pos;
		cin>> index>> pos;
		goods[pos] += 1;
	}
	
	cin>> src>> dest;
	dist2src[src] = 0;
	Dijkstra(adj, point_no, src, dest, dist2src, pre);
	
	if(dist2src[dest] == -1){
		cout<< "-1"<< endl;
	}
	else{
		int sum=0;
		int p = 0;
		for(p=dest; pre[p] !=p; p=pre[p]){
			sum += goods[p];
		}
		sum += goods[p];
		cout << dist2src[dest] << " " << sum << endl;
	}
	
	
	cout<< endl;
	for(int i=0; i<dist2src.size(); ++i){
		cout<< dist2src[i]<< " ";
	}
	cout<< endl;
	
	for(int i=0; i<pre.size(); ++i){
		cout<< pre[i]<< " ";
	}
	cout<< endl;
	
	
	return 0;
}