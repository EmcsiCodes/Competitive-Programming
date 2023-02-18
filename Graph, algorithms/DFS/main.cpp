#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1001];

void DFS(int node,int n,vector<bool> &visited){
    visited[node] = true;
    for(auto i:adj[node]){
        if(!visited[i]){
            cout<<i<<" ";
            DFS(i,n,visited);
        }
    }
}

void DFSforMultipleComp(int n){
    vector<bool> visited(n+1,false);
    for(int i=0; i<=n; i++){
        if(!visited[i]){
            cout<<i<<" ";
            DFS(i,n,visited);
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
    DFSforMultipleComp(n);
    return 0;
}
/*
12 28
0 1
0 9
1 0
1 8
2 3
3 2
3 4
3 5
3 7
4 3
5 3
5 6
6 7
6 5
7 8
7 3
7 6
7 10
7 11
8 7
8 1
8 9
9 0
9 8
10 7
10 11
11 10
11 7
*/