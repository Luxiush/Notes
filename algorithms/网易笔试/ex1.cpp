#include <iostream>

using namespace std;

int main(){
    const MAX_CITY = 50;
    int parent[MAX_CITY];
    int visited[MAX_CITY];
    memset(parent, 0, MAX_CITY*sizeof(int))
    memset(visited, 0, MAX_CITY*sizeof(int))
        
    int city_num = 0;
    int steps = 0;
    
    cin >> city_num;
    cin >> steps;
    
    int next = 0;
    for(int i=0; i<city_num-1; ++i){
        cin >> parent[i];
        if(parent[i]==0){
            next = i+1;
        }
    }
    
    int max_city_num = 1;
    visited[0] = 1;
    while(steps && next>0){
        if(visited[next] == 0){
            max_city_num += 1;
            visited[next] = 1;
            next =
        }
    }
    
    
    
    return 0;
}