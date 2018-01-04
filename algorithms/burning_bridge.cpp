/*
## ZOJ Problem - 2588 Burning Bridges 
### 题目 
tarjan算法求割边 

### 思路
[Tarjan]( http://blog.csdn.net/h992109898/article/details/51318135 )
dfn[]数组记录DFS访问的次序, 祖先一定大于子女, (可以理解为将DFS树进行拓扑排序后每个点的序号)
low[]数组记录某点可以直接或间接访问的最上层的顶点. 为min(本身的dfn[], 能通过当前节点返回其祖先或其祖先之上的节点的dfn[], 他子女的low[]), 这样就能记录整条路径有没有回路了(如果子节点的low值小于根节点的dfn值则说明有回路). 

### Ref
<https://www.cnblogs.com/jifahu/p/5506329.html>
<http://blog.csdn.net/h992109898/article/details/51325904>
*/

#include <iostream>  
#include <cstdio>  
#include <queue>  
#include <cstring>  
#include <cmath>  
#include <algorithm>  
#include <vector>  
  
using namespace std;  
  
const int MAX_N = 10005;
const int INF = 0x3f3f3f3f;  
  
struct Edge  
{  
    int u, v, id;  
    bool isRepeat;  
};  
  
vector <Edge> edges[MAX_N];  
vector <Edge> res;  
int edgeNum, nodeNum, head[MAX_N],  
    low[MAX_N], dfn[MAX_N];  
bool visited[MAX_N];  
  
void init()  
{  
    int i;  
    memset(visited, 0, sizeof(visited));  
    for(i = 0; i < MAX_N; i++)  
        edges[i].clear();  
    res.clear();  
}  
  
void addEdge(int u, int v, int id)  
{  
    int i;  
    Edge tmp;  
    tmp.u = u, tmp.v = v, tmp.id = id;  
    tmp.isRepeat = false;  
    //判重边  
    for(i = 0; i < edges[u].size(); i++)  
        if(v == edges[u][i].v){  
            edges[u][i].isRepeat = true;  
            return;  
        }  
    edges[u].push_back(tmp);  
}  
  
void dfs(int pre, int u, int depth)  
{  
    visited[u] = true;  
    low[u] = dfn[u] = depth;  
    int i, v;  
    for(i = 0; i < edges[u].size(); i++){  
        v = edges[u][i].v;  
        if(!visited[v]){  
            dfs(u, v, depth + 1);  
            low[u] = min(low[u], low[v]);  
            if(low[v] > dfn[u] && !edges[u][i].isRepeat){  
                res.push_back(edges[u][i]);  
            }  
        }  
        else if(v != pre)  
            low[u] = min(low[u], dfn[v]);  
    }  
}  
  
bool cmp(Edge a, Edge b)  
{  
    return a.id < b.id;  
}  
  
int main()  
{  
    //freopen("in.txt", "r", stdin);  
  
    int test, u, v, i;  
  
    scanf("%d", &test);  
  
    while(test--){  
        init();  
        scanf("%d%d", &nodeNum, &edgeNum);  
  
        for(i = 0; i < edgeNum; i++){  
            scanf("%d%d", &u, &v);  
            addEdge(u, v, i + 1);  
            addEdge(v, u, i + 1);  
        }  
  
        dfs(1, 1, 1);  
  
        int num = res.size();  
        sort(res.begin(), res.end(), cmp);  
        printf("%d\n", num);  
  
        if(num){  
            printf("%d", res[0].id);  
            for(i = 1; i < num; i++)  
                printf(" %d", res[i].id);  
            printf("\n");  
        }  
        if(test)  
            printf("\n");  
    }  
  
    return 0;  
}  
