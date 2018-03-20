/**
## hdu2767 Proving Equivalences
### 题目大意
给一个有向图, 最少求还需要添加几条边才能变成强连通图

### 思路
- tajarn算法缩点, 然后求入度为0的点数和出度为0的点数, 最后结果为二者最大值(因为要保证加边后没有入度为0和出度为0的点).



<https://www.cnblogs.com/hxer/p/5186202.html>
<http://blog.csdn.net/u013486414/article/details/46712469>

**/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <map>
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const double pi= acos(-1.0);
const double esp=1e-6;
const int maxn=21010;
int head[maxn],dfn[maxn],low[maxn],belong[maxn],stak[maxn],instack[maxn];
int in[maxn],out[maxn];
int incnt,outcnt;
int cnt,_index,top,ans;
struct node {
    int u, v, next;
} edge[maxn*3];
void add(int u, int v) {
    edge[cnt].v=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void Init() {
    memset(head,-1,sizeof(head));
    memset(dfn,0,sizeof(dfn));
    memset(instack,0,sizeof(instack));
    cnt=_index=top=ans=0;
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    incnt=outcnt=0;
}
void tarjan(int u) {
    dfn[u]=low[u]=++_index;
    stak[++top]=u;
    instack[u]=1;
    for(int i=head[u]; i!=-1; i=edge[i].next) {
        int v=edge[i].v;
        if(!dfn[v]) {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        } else if(instack[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]) {
        ans++;
        while(1) {
            int v=stak[top--];
            instack[v]=0;
            belong[v]=ans;
            if(u==v) break;
        }
    }
}
int main() {
    int T, n, m,i, j;
    int u,v;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        Init();
        while(m--) {
            scanf("%d%d",&u,&v);
            add(u,v);
        }
        for(i=1; i<=n; i++) {
            if(!dfn[i])
                tarjan(i);
        }

        printf("======dfn: \n");
        for(int i=1; i<=n; i++){
            printf("%d\t", dfn[i]);
        }
        printf("\n");

        printf("======low: \n");
        for(int i=1; i<=n; i++){
            printf("%d\t", low[i]);
        }
        printf("\n");

        if(ans==1) {
            printf("0\n");
            continue ;
        }
        for(i=1; i<=n; i++) {
            for(j=head[i]; j!=-1; j=edge[j].next) {
                int v=edge[j].v;
                if(belong[v]!=belong[i]) {
                    in[belong[v]]++;
                    out[belong[i]]++;
                }
            }
        }
        for(i=1; i<=ans; i++) {
            if(!in[i])
                incnt++;
            if(!out[i])
                outcnt++;
        }
        printf("%d\n",max(incnt,outcnt));
    }
    return 0;
}
