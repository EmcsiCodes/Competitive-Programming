#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[10001];

void BFS(int node, vector<bool> &visited, int n){
    queue<int> q;
    q.push(node);

    while(!q.empty()){
        node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

void solve(int n){
    int k=-1;
    vector<int> res;
    vector<bool> visited(n+1, false);
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            res.push_back(i);
            k++;
            BFS(i,visited,n);
        }
    }
    cout<<k<<'\n';
    for(int i=0; i<res.size()-1; i++){
        cout<<res[i]<<" "<<res[i+1]<<'\n';
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
    solve(n);
    return 0;
}
/*
9 10
1 3
2 7
6 8
8 3
1 6
4 9
4 2
4 7
7 9
2 9
*/