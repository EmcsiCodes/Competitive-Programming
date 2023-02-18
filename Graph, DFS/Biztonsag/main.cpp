#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[100001];

void DFS(int node,vector<bool> &visited,vector<bool> &canReach){
    visited[node] = true;
    for(auto i:adj[node]){
        if(canReach[i]) canReach[node] = true;
        if(!visited[i]){
            DFS(i,visited,canReach);
        }
    }
}

int main()
{
    int n,m,startNode,endNode;
    cin>>n>>m>>startNode>>endNode;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> visited(n+1,false);
    vector<bool> canReach(n+1,false);
    canReach[endNode] = true;
    DFS(startNode,visited,canReach);
    vector<int> res;
    for(int i=1; i<=n; i++){
        if(canReach[i]) res.push_back(i);
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
    cout<<'\b';
    return 0;
}
/*
10 13
1 5
1 6
1 7
6 7
1 8
9 8
1 2
1 3
2 3
2 4
4 3
4 5
5 10
10 4
*/