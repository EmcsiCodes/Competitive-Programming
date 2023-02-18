#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(int startNode,int n,vector<int> adj[],vector<int> &dis){
    vector<bool> visited(n+1,false);
    queue<int> q;
    visited[startNode] = true;
    q.push(startNode);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                dis[i] = dis[node] + 1;
            }
        }
    }
}

void solve(int n,int tomPos,int jerryPos,int k,vector<int> adj[]){
    vector<int> disForTom(n+1,0);
    BFS(tomPos,n,adj,disForTom);
}

int main()
{
    int testNum;
    cin>>testNum;
    for(int t=1; t<=testNum; t++){
        int n,tomPos,jerryPos,k;
        vector<int> adj[20001];
        cin>>n>>tomPos>>jerryPos>>k;
        for(int i=1; i<n; i++){
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    }
    return 0;
}