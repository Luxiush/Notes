#include <iostream>
#include <fstream>
#include <iomanip>
#include <memory.h>
#include <vector>
#include "graph.cpp"

using namespace std;

//		#define DFS_			
//		#define BFS_ 		
//		#define KRUSKAL_		
//		#define PRIM_		
//		#define SCC_		
		#define DIJKSTRA_

int main(int argc, char** argv){
	if(argc != 2){
		cout<< "Not enough arguements."<< endl;
		return -1;
	}
	
	const int MAX_SIZE = 100;
	int size = 0;
	int g[MAX_SIZE*MAX_SIZE];
	memset(g, 	 0, MAX_SIZE*MAX_SIZE*sizeof(int));
	
	cout<< "Reading input from "<< argv[1]<< endl; 
	fstream fin(argv[1], ios::in);
	fin >> size;
	for(int i=0; i<size; ++i){
	for(int j=0; j<size; ++j){
		fin>> g[i*size+j];
	}}
	
	Graph G(g, size);
	cout<< "Initial complete."<< endl;
/****/	
	int topo[MAX_SIZE];
	memset(topo, 0, MAX_SIZE*sizeof(int));
#ifdef DFS_	
	cout<< "DFS: "<< endl;
	G.DFS(6,topo);
	for(int i=0; i>=0; i=topo[i]){
		printf("%5d",i);
	}
	printf("\n");
#endif
#ifdef BFS_	
	cout<< "\nBFS: "<< endl;
	G.BFS(0,topo);
	for(int i=0; i>=0; i=topo[i]){
		printf("%5d",i);
	}	
	printf("\n");
#endif	
/****/		
	vector<Edge> mst;
	vector<Edge>::iterator iter;
#ifdef KRUSKAL_
	cout<< "\nKruskal: "<< endl;
	mst = G.MST_Kruskal();
	for(iter=mst.begin(); iter!=mst.end(); iter++){
		printf("(%d, %d, %d)  ",iter->u, iter->v, iter->weight);
	}
	printf("\n");
#endif
#ifdef PRIM_
	cout<< "\nPrim: "<< endl;
	mst.clear();
	mst = G.MST_Prim();
	for(iter=mst.begin(); iter!=mst.end(); iter++){
		printf("(%d, %d, %d)  ",iter->u, iter->v, iter->weight);
	}
	printf("\n");	
#endif	
/****/	
	int scc[MAX_SIZE];
	memset(scc,  0, MAX_SIZE*sizeof(int));
#ifdef SCC_	
	cout<< "SCC_Kosaraju: "<< endl;
	G.SCC_Kosaraju(scc);
	for(int i=0; i<size; ++i){
		printf("%5d", scc[i]);
	}
	printf("\n");	
#endif


#ifdef DIJKSTRA_
	int dist[MAX_SIZE];
	int pre[MAX_SIZE];
	memset(dist, 0, MAX_SIZE*sizeof(int));
	memset(pre, 0, MAX_SIZE*sizeof(int));

	cout<< "Dijkstra: "<< endl;
	G.Dijkstra(0, dist, pre);
	
	cout<< "res: "<< endl;
	for(int i=0; i<size; ++i){
		printf("%5d", dist[i]);
	}
	printf("\n");
	
#endif

	return 0;
}
















