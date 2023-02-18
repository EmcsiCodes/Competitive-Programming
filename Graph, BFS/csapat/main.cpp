#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[200001];
vector<int> nodes;

bool BFS(int node,int n,vector<bool> &visited){
    
    queue<int> q;
    q.push(node);

    while(!q.empty()){
        node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                if(nodes[i] == 0){
                    if(nodes[node] == 1) nodes[i] = 2;
                    else nodes[i] = 1;
                    q.push(i);
                    visited[i] = true;
                }
                else {
                    return false;
                }
            }
        }
    }
    return true;
}

void solve(int n){
    vector<bool> visited(n+1,false);
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            if(!BFS(i,n,visited)) {
                cout<<-1;
                return;
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(nodes[i] == 0 || nodes[i] == 1){
            cout<<i<<" ";
        }
    }
    cout<<'\b'<<'\n';
    for(int i=1; i<=n; i++){
        if(nodes[i] == 2){
            cout<<i<<" ";
        }
    }
    cout<<'\b';
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
    for(int i=1; i<=n; i++){
        nodes.push_back(0);
    }
    solve(n);
    return 0;
}
/*
9 8
1 3
3 9
9 4
5 4
2 6
7 8
3 5
9 6
*/