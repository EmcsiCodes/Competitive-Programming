#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[20001];

void DFS(int node,int n,vector<bool> &visited,vector<bool> &valid){
    visited[node] = true;
    for(auto i:adj[node]){
        if(!visited[i]){
            DFS(i,n,visited,valid);
            if(!valid[i]) valid[node] = false;
        } else if(!valid[i]) valid[node] = false;
    }
}

int main()
{
    int n,m,startNode;
    cin>>n>>m>>startNode;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    vector<int> res;
    vector<bool> visited(n+1,false),valid(n+1,true);
    valid[startNode] = false;
    DFS(startNode,n,visited,valid);

    for(int i=1; i<=n; i++){
        if(valid[i] && visited[i]) res.push_back(i);
    }
    cout<<res.size()<<'\n';
    for(auto i:res)cout<<i<<" ";
    return 0;
}
/*
10 15 5
4 5
2 4
4 1
5 2
5 6
6 5
6 2
6 7
1 3
3 9
1 9
7 8
8 9
9 10
8 10
*/