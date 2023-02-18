#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[1001];

void BFS(int startNode,int n,vector<bool> &visited){
    queue<int> q;
    q.push(startNode);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
 //h tobb komponense van a grafnak, vegezze el a BFS-t minden kompra
void BFSforAllComponents(int n){
    vector<bool> visited(n+1,false);
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            visited[i] = true;
            BFS(i,n,visited);
        }
    }
}

int main()
{
    //barmilyen graf beolvasas
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
