#include <iostream>
#include <vector>
using namespace std;

bool visited[51] = {false};
vector<int> adj[51], comp[51];
int comp_num = 0;

void lonelyThiefs(int n){
    int t = 0;
    for(int i=1; i<=n; i++){
        if(adj[i].empty()) cout<<i<<" ";
    }
    cout<<'\b'<<'\n';
}

void DFS(int v, bool visited[]){
    visited[v] = true;
    for(auto i:adj[v]){
        if(!visited[i]){
            comp[comp_num].push_back(i);
            DFS(i,visited);
        }
    }
}

void components(int n){
    for(int i=1; i<=n; i++){
        if(!visited[i]) {
            comp_num++;
            comp[comp_num].push_back(i);
            DFS(i,visited);
        }
    }
    int count = 0;
    for(auto i:comp){
        if(i.size()>1) count++;
    }
    cout<<count<<'\n';
}
int main()
{
    int n,x,y;
    cin>>n;
    while(cin>>x>>y && x!=0 && y!=0){
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    lonelyThiefs(n);
    components(n);
    
    return 0;
}
/*
7
1 2
1 4
3 1
5 6
2 3
1 2
0 0
*/