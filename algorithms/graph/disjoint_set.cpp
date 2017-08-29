/* disjoint set */
#include<stdio.h>
#include<memory.h>

class DisjointSet{
public:
	int max_size;
	int* rank;
	int* parent;
	
	DisjointSet(int size);
	~DisjointSet();
	
//	void makeSet(int x);
	int findSet(int x);
	void unionSet(int x, int y);
	
	void printSet();
};


DisjointSet::DisjointSet(int size){
	max_size = size;
	rank = new int[max_size];
	parent = new int[max_size];
	
	memset(rank, 0, max_size*sizeof(int));
	for(int i=0; i<size; i++){
		parent[i] = i;
	}
}
DisjointSet::~DisjointSet(){
	delete [] rank;
	delete [] parent;
}


int DisjointSet::findSet(int x){
	int p = x;
	while(parent[p] != p){
		p = parent[p];
	}
	int temp = x;
	while(parent[x] != p){
		temp = x;
		x = parent[x];
		parent[temp] = p;
	}
	return p;

/*	while(parent[x] != x){
		parent[x] = findSet(parent[x]);
	}
	return parent[x];
*/	
}


void DisjointSet::unionSet(int x, int y){
	int p_x = findSet(x);
	int p_y = findSet(y);
	
	if(rank[p_x]>rank[p_y]){
		parent[p_y] = p_x;
	}
	else {
		parent[p_x] = p_y;
		if(rank[p_x]==rank[p_y]){
			rank[p_y] += 1;
		}
	}
}

void DisjointSet::printSet(){
	printf("\n     i:");
	for(int i=0; i<max_size; i++)
		printf("%4d",i);
	printf("\nparent:");
	for(int i=0; i<max_size; i++)
		printf("%4d",parent[i]);
	printf("\n  rank:");
	for(int i=0; i<max_size; i++)
		printf("%4d",rank[i]);
	printf("\n");
}


