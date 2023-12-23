#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[201];

vector<int> BFS(int node,int n){
    vector<int> dis(n+1,0);
    vector<bool> visited(n+1, false);
    queue<int> q;
    q.push(node);
    visited[node] = 0;

    while(!q.empty()){
        node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                dis[i] = dis[node] + 1;
            }
        }
    }
    return dis;
}

void solve(int n,int P,int Z){
    vector<int> res1 = BFS(P,n), res2 = BFS(Z,n);
    vector<char> res(n+1,'0');
    for(int i=1; i<=n; i++){
        if(i == P){
            res[i] = 'P'; 
        }
        if(i == Z){
            res[i] = 'Z'; 
        }
        if(res1[i] == res2[i] && (i!=P && i!=Z)){
            res[i] = 'F';
        }
        if(res1[i]<res2[i]){
            res[i] = 'P'; 
        }
        if(res2[i]<res1[i]){
            res[i] = 'Z';
        }
    }
    for(int i=1; i<=n; i++){
        cout<<res[i]<<" ";
    }
    cout<<'\b';
}

int main()
{
    int n,m,P,Z;
    cin>>n>>m>>P>>Z;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    solve(n,P,Z);
    return 0;
}
/*
8 9 8 1
1 3
8 4
8 2
1 4
8 5
6 1
5 6
6 7
2 3
*/