//基于优先队列的Dijkstra算法

class Node{
public:
	int v;		//顶点编号
	int weight;	//权重/到原点的距离

	bool operator<(Node n){
		return weight>n.weight;
	}
};

//邻接链表表示图
class Graph{
	int v;		//顶点编号
	vector<vector<Node>> adj;	//邻接链表
//	vector<Node>* adj;
	
	void Dijkstra(int src);
}

void Graph::Dijkstra(int src, vector<Node>& res){
	priority_queue<Node> Q;
	int S[size];//为1表示到原点的最短路径已经找到
	memset(S, 0, sizeof(int)*size);
	
	Q.push(Node(src,0));
	Node temp;
	while(!Q.empty()){
		temp = Q.top();
		Q.pop(); 
		if(S[temp.v]==0){
			S[temp.v] = 1;
			res.push_back(temp);
			
			for(int i=0; i<size; ++i){
				if(S[adj[temp.v][i].v]==0){
					Q.push(Node(adj[temp.v][i].v, adj[temp.v][i].weight+temp.weight));
				}
			}
		}
	}
}

