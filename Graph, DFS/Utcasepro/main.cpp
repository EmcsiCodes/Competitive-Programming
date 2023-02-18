#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[10001];

void DFS(int node,vector<int> &visited,vector<int> &res,vector<int> &parent){
    visited[node] = 1;
    for(auto i:adj[node]){
        if(visited[i] == 0){
            res.push_back(i);
            parent[i] = node;
            DFS(i,visited,res,parent);
            res.push_back(node);
        } else if(parent[node]!=i && visited[i] == 1){
            visited[node] = 2;
            res.push_back(i);
            res.push_back(node);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> res, parent(n+1,0),visited(n+1,0);
    res.push_back(1);
    DFS(1,visited,res,parent);
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
8 11
1 2
1 3
2 3
2 5
3 5
2 4
4 5
2 6
6 7
6 8
7 8
*/