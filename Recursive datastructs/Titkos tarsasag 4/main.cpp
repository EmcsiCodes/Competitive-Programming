#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[10001];
struct res{
    int a,b;
    int c;
    int d;
};

int DFS(int node,vector<bool>&visited){
    visited[node] = true;
    int curr = 1;
    for(auto i:adj[node]){
        if(!visited[i]) curr += DFS(i,visited);
        else 
    }
    return curr;
}

void BFS(int start,int n){
    queue<int> q;
}

int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    int x; cin>>x;
    for(int i=2; i<=n; i++){
        int x;
        cin>>x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    res res;
    res.a = DFS(a);
    res.b = DFS(b);
    return 0;
}