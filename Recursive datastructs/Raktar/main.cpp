#include <iostream>
#include <vector>

using namespace std;
int n,c,start;
vector<int> adj[1001];

int DFS(int node,vector<bool>&visited,vector<int>w){
    visited[node] = true;
    int curr = 0;
    for(auto i:adj[node]){
        if(!visited[i]){
            curr += DFS(i,visited,w);
        }
    }
    return min(c,curr + w[node]);
}

int main()
{
    cin>>n>>c>>start;
    vector<int> w(n+1,0);
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        w[i] = x;
    }
    for(int i=1; i<n; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> visited(n+1,false);
    visited[start] = true;
    int totalw = w[start];
    for(auto i:adj[start]){
        totalw += DFS(i,visited,w);
    }
    cout<<totalw;
    return 0;
}
/*
10 200 2
100 100 50 50 50 100 200 100 50 50
1 2
3 4
4 5
4 2
2 6
6 7
6 8
8 9
10 8
*/