#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[10001];

void BFS(int node, vector<bool> visited, int n){
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

void solve(){}

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

    return 0;
}
