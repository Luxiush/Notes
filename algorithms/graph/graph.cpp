#include<memory.h>
#include<queue>
#include<stack>
#include <vector>
#include "disjoint_set.cpp"

using namespace std;


class Edge{
public:
	int u;
	int v;
	int weight;
	
	Edge(const Edge& E){
		this->u = E.u;
		this->v = E.v;
		this->weight = E.weight;
	}
	
	Edge(int u, int v, int w){
		this->u = u;
		this->v = v;
		weight = w;
	}
	
	Edge& operator=(const Edge E){
		this->u = E.u;
		this->v = E.v;
		this->weight = E.weight;
		
		return *this;
	}

	bool operator<(const Edge& E) const{
		 return this->weight > E.weight;
	}
	
};
/*
class Point{
public:
	int* dist;	//到原点的距离
	int num;	//节点编号
	int pi;		//前驱结点
	
	Point(int num, int dist, int pi){
		this->num = num;
		this->dist = dist;
		this->pi = pi;
	}
	
	Point(const Point& P){
		this->num = P.num;
		this->dist = P.dist;
		this->pi = P.pi;
	}
	
	Point& operator=(const Point P){
		this->num = P.num;
		this->dist = P.dist;
		this->pi = P.pi;
	}
	bool operator<(const Point P) const{
		return this->dist < P.dist;
	}
};
*/
class Graph{
public:
	int size;
	int* p;//指向图的邻接矩阵
	
	vector<Edge> mst;
	
	Graph(int* p, int size);
	~Graph(){}
	
	void BFS(int src, int* visited);				// 广搜				
	void DFS(int src, int* visited);				// 深搜
	
	vector<Edge>& MST_Kruskal();					// 最小生成树
	vector<Edge>& MST_Prim(int src=0);
	
	void SCC_Kosaraju(int* res);					// 强连通分量Kosaraju算法
	
	void Dijkstra(int src, int* dist, int* pre);	//最短路径

private:
	const static int INF = 0x7f000000;

	int w(int i, int j){ //返回p[i][j] (weight)
		return p[i*size+j];
	}
	int w_rev(int i, int j){ //反向图
		return p[j*size+i];
	}
};


void printArr(int* arr, int len){
	for(int i=0; i<len; ++i){
		printf("%5d ",arr[i]);
	}
	printf("\n");
}


Graph::Graph(int* p, int size){
	this->p = p;
	this->size = size;
}

void Graph::BFS(int src, int* visited){
	const int MARK = -2;
	const int UNVISIT = -1;	
	
	int pre = src; 
	memset(visited, UNVISIT, size*sizeof(int));
	int temp;

	queue<int> Q;
	Q.push(src); 
	visited[src] = MARK;
	while(!Q.empty()){
		temp = Q.front(); Q.pop();
		visited[pre] = temp;
		pre = temp;		
		printf("%5d",temp);
		for(int i=0; i<size; ++i){
			if(w(temp,i) != 0 && visited[i] == UNVISIT){
				Q.push(i);
				visited[i] = MARK;
			}
		}
	}
	printf("\n");
}

void Graph::DFS(int src, int* visited){
	//visited记录BFS和DFS对结点的访问顺序：visited[i] 记录结点i的后继结点
	const int MARK = -2;
	const int UNVISIT = -1;	
	
	int pre = src; 
	memset(visited, UNVISIT, size*sizeof(int));
	int temp;
	
	stack<int> S;
	S.push(src);
	visited[src] = MARK;
	while(!S.empty()){
		temp = S.top(); S.pop();
		visited[pre] = temp;
		pre = temp;
		printf("%5d", temp);
		for(int i=size-1; i>=0; --i){
			if(w(temp,i) != 0 && visited[i] == UNVISIT){
				S.push(i);
				visited[i] = MARK;
			}
		}
	}
	printf("\n");
}


//每次选择权值最小的边
vector<Edge>& Graph::MST_Kruskal(){
	priority_queue<Edge> PQ;
	for(int i=0; i<size; ++i){
	for(int j=0; j<size; ++j){
		if(w(i,j) != 0){
			PQ.push(Edge(i,j,w(i,j)));
		}
	}}
	
	Edge temp(0,0,0);
	DisjointSet DS(size);
	
	mst.clear();
	while(!PQ.empty()){
		temp = PQ.top();
		PQ.pop();
		if(DS.findSet(temp.u) != DS.findSet(temp.v)){
			DS.unionSet(temp.u, temp.v);
			mst.push_back(Edge(temp));
		}
	}
	
	return mst;
}

vector<Edge>& Graph::MST_Prim(int src){
	priority_queue<Edge> PQ;
	DisjointSet DS(size);
	Edge temp(0,0,0);
	
	mst.clear();
	for(int i=0; i<size; ++i){
		if(w(src,i) != 0){
			PQ.push(Edge(src,i,w(src,i)));
		}
	}
	while(!PQ.empty()){
		temp = PQ.top(); PQ.pop();
		if(DS.findSet(temp.u) != DS.findSet(temp.v)){
			DS.unionSet(temp.u, temp.v);
			mst.push_back(Edge(temp));
			for(int i=0; i<size; ++i){
				if(w(temp.v, i) != 0){
					PQ.push(Edge(temp.v,i,w(temp.v,i)));
				}
			}
		}
	}
	
	return mst;
}


/**
 * 先DFS反向图得到一个伪拓扑序列
 * 再按得到的伪拓扑序列DFS原图
**/
void Graph::SCC_Kosaraju(int* scc){  
	//scc 记录第i个结点所属于的连通分量
	int DFS_src = 0;
	int scc_num = 1;
	memset(scc, 0, size*sizeof(int));
	int scc_topo[size];
	
	int visited[size];
	memset(visited, 0, size*sizeof(int));
	int temp = 0;
	
	stack<int> S;
	S.push(DFS_src);
	visited[DFS_src] = 1;
	while(!S.empty()){
		temp = S.top(); S.pop();
		
		DFS(temp, scc_topo);
		for(int i=temp; scc_topo[i]>=0; i=scc_topo[i]){
			if(scc[i]==0){
				scc[i] = scc_num;
			}
		}
		++scc_num;
		
		for(int i=size-1; i>=0; --i){
//			printf("w_rev(%d,%d)=%d\n",temp, i, w_rev(temp,i));
			if(w_rev(temp,i)!=0 && visited[i] == 0){
				S.push(i);
				visited[i] = 1;
			}
		}
	}
}

/*邻接矩阵表示，-1表示不可达*/
void Graph::Dijkstra(int src, int* dist, int* pre){
	int S[size];
	
	for(int i=0; i<size; ++i){
		S[i] = 0;
		dist[i] = (w(src,i)==-1)? INF: w(src,i);
		pre[i]  = (w(src,i)==-1)? -1: src;
	}
	S[src] = 1;
	dist[src] = 0;
	
	int min;
	for(int j=1; j<size; ++j){
		//在未找到最短距离的点中找离src最近的点
		min = -1;
		for(int i=0; i<size; ++i){
			if(S[i]==0&&(min==-1||dist[min]>dist[i])){
				min = i;
			}
		}
		S[min] = 1;
		
		//更新其他点到src的距离
		for(int i=0; i<size; ++i){
			if(!S[i] && w(min,i)!=-1){
				if(dist[i]>dist[min]+w(min,i)){
					dist[i] = dist[min]+w(min,i);
					pre[i] = min;
				}
			}			
		}
		
		cout<< "j: "<< j<< endl;
		cout<< "min: "<< min<< endl;
		printArr(S, size);
		printArr(dist, size);
		printArr(pre, size);
		cout<< endl;
	}
}

















