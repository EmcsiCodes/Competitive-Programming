#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[1001];

void BFS(int n){
    vector<bool> visited(n+1,false);
    vector<int> perm(n+1,0);
    vector<int> layer(n+1,0);
    queue<int> q;
    visited[0] = true;
    q.push(0);
    while(!q.empty()){
        int node = q.front();
        int currLayer = layer[node] + 1;
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
                layer[i] = currLayer;
                perm[i] = (perm[i] + 1)%100000000;
            }
            else if(layer[i] == currLayer){
                perm[i] = (perm[i] + perm[node])%100000000;
            }  
        }
    }
    for(int i=1; i<=n; i++){
        cout<<perm[i]<<'\n';
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
    BFS(n);
    return 0;
}
/*
5 7
0 1
1 4
3 1
3 5
2 0
2 3
4 5
*/