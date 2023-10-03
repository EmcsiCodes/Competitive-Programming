#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[10001];

void DFS(int node,vector<bool>&visited,vector<bool>&canReachFromK,vector<bool>&canReachK){
    visited[node] = true;
    for(auto i:adj[node]){
        if(!visited[i]){
            canReachFromK[i] = true;
            DFS(i,visited,canReachFromK,canReachK);
        } else if(canReachK[i]) canReachK[node] = true;
    }
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    vector<bool> visited(n+1,false);
    vector<bool> canReachFromK(n+1,false), canReachK(n+1,false);
    canReachK[k] = true;
    DFS(k,visited,canReachFromK,canReachK);
    for(int i=1; i<=n; i++){
        if(!visited[i]) DFS(i,visited,canReachFromK,canReachK);
    }
    vector<int> res1,res2;
    for(int i=1; i<=n; i++) if(canReachK[i] && i!=k) res1.push_back(i);
    for(int i=1; i<=n; i++) if(canReachFromK[i]) res2.push_back(i);
    cout<<res1.size()<<" ";
    for(auto i:res1) cout<<i<<" ";
    cout<<'\n'<<res2.size()<<" ";
    for(auto i:res2) cout<<i<<" "; 
    return 0;
}
/*
5 4 1
1 2
3 2
4 1
5 4
*/