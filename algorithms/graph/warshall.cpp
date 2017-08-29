/* warshall算法求所有点对的最短路径。
考虑图G的所有结点V={1,2,...,n}的一个子集V'={1,2,...,k}。
对于任意结点对u,v，考虑从u到v的所有中间结点都属于V'的路径，并假设p为其中权值最小的路径。
对于结点k：
	如果k不是p的中间结点，则p的所有结点都属于点集 V'-k={1,2,...,k-1}
	如果k是p的中间结点，则p可分解为 p1(u->k)和p2(k->v)，并且p1是所有中间结点都属于V'的u->k的最短路径，p2同理。

            / w(i,j)                                   k=0
d(k,i,j) = |
            \ min(d(k-1,i,k)+d(k-1,k,j), d(k-1,i,j))   k!=0
		   

*/
//图用邻接矩阵表示，INF表示不可达，size表示图的顶点数
void Graph::Warshall(int* D){
	//D初始化为w
	for(int i=0; i<size; ++i){
	for(int j-0; j<size; ++j){
		D[i*size+j] = w[i][j];
	}}
	
	for(int k=0; k<size; ++k){
		for(int i=0; i<size; ++i){
			for(int j=0; j<size; ++j){
				if(D[i*size+j]>D[i*size+k]+D[k*size+j]){
					D[i*size+j]>D[i*size+k]+D[k*size+j];
				}
			}
		}
	}
}