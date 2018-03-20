#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <iostream>
#include <stack>

using namespace std;

const int INF = 0x7fffffff;
const int MAX_EDGE_NUM = 50005;
const int MAX_VERTEX_NUM = 20002;

struct Edge{
    int u;
    int v;
};

int edgeNum = 0;
int vertexNum = 0;
Edge edges[MAX_EDGE_NUM];
int dfn[MAX_VERTEX_NUM];        // 初始化为-1;
int low[MAX_VERTEX_NUM];

int distinctLow[MAX_VERTEX_NUM]; // 为1时表示在缩点后的图中, 初始化为0
int in[MAX_VERTEX_NUM];          // 统计各点入度
int out[MAX_VERTEX_NUM];         // 统计各点出度

int _rec_depth;

void Init(){
    _rec_depth = 0;
    memset(edges, 0, sizeof(edges));
    memset(dfn, -1, sizeof(dfn));

    for(int i=0; i<vertexNum; i++){
        low[i] = INF;
    }

    memset(distinctLow, 0, sizeof(distinctLow));
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));

}

void _DFS(int root){
    // static int _rec_depth = 0;
    // printf("root:%d, _rec_depth:%d, dfn:%d, low:%d\n", root, _rec_depth, dfn[root], low[root]);
    if(dfn[root] != -1) return;
    dfn[root] = _rec_depth;
    low[root] = _rec_depth;
    _rec_depth += 1;

    for(int i=0; i<edgeNum; i++){
        if(edges[i].u == root){
            int next = edges[i].v;
            if(dfn[next]==-1){
                _DFS(next);
                low[root] = min(low[root], low[next]);
            }
            else{
                low[root] = min(low[root], dfn[next]);
            }
        }
    }
    
    // printf("---_rec_depth:%d, root:%d, dfn:%d, low:%d\n", _rec_depth, root, dfn[root], low[root]);
}

void DFS(Edge*edges){
    for(int i=0; i<vertexNum; i++){
        if(dfn[i]==-1) _DFS(i);
    }
}

int main(){
    int testCases;
    scanf("%d", &testCases);
    while(testCases--){
        // printf("\n\n===================TestCase:%d\n", testCases);
        scanf("%d %d", &vertexNum, &edgeNum);
        Init();
        // printf("vertexNum: %d, edgeNum: %d\n", vertexNum, edgeNum);
        for(int i=0; i<edgeNum; i++){
            scanf("%d %d", &edges[i].u, &edges[i].v);

            // 输入的节点下标从1开始, 改成从0开始
            edges[i].u -= 1;
            edges[i].v -= 1;
            // printf("edge: %d=>%d\n", edges[i].u, edges[i].v);
        }

        DFS(edges);

        // printf("======dfn: \n");
        // for(int i=0; i<vertexNum; i++){
        //     printf("%d\t", dfn[i]);
        // }
        // printf("\n");

        // printf("======low: \n");
        // for(int i=0; i<vertexNum; i++){
        //     printf("%d\t", low[i]);
        // }
        // printf("\n");

        // 统计缩点后的节点数
        int lowNum = 0;
        for(int i=0; i<vertexNum; i++){
            if(!distinctLow[low[i]]){
                distinctLow[low[i]] = 1;
                lowNum ++;
            }
        }   
        // printf("lowNum:%d\n", lowNum);

        if(lowNum==1) {
            printf("0\n");
            continue;
        }

        // 统计各个节点的出度和入度
        for(int i=0; i<edgeNum; i++){
            int u = edges[i].u;
            int v = edges[i].v;

            if(low[u] != low[v]){
                in[low[v]] ++;
                out[low[u]] ++;
            }
        }

        int inNum = 0;      // 入度为0的点数
        int outNum = 0;     // 出度为0的点数
        for(int i=0; i<vertexNum; i++){
            if(!distinctLow[i]) continue;

            if(!in[i]) inNum ++;
            if(!out[i]) outNum ++;
        }

        printf("%d\n", (inNum>outNum? inNum: outNum));
    }

    return 0;
}
