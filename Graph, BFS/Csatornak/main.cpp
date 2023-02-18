#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector< pair<int,int> > adj[20001];


void DijkstraAlgo(int startNode,int endNode,int n, vector<int> &dis){
    
    priority_queue< pair<int,int> > pq;
    dis[startNode] = 1000001;
    pq.push({dis[startNode],startNode});

    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        for(auto i:adj[node]){
            if(dis[i.first] < dis[node]){
                dis[i.first] = min(dis[node],i.second);
                pq.push({dis[i.first],i.first});
            }
        }
    }
}

void shortestPath(int startNode,int endNode,int n,vector<int> dis){
    vector<bool> visited(n+1,false);
    vector<int> path(n+1,0);
    queue<int> q;
    visited[endNode] = true;
    q.push(endNode);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i.first] && i.second >= dis[node]){
                q.push(i.first);
                visited[i.first] = true;
                path[i.first] = path[node] + 1;
            }
        }
    }
    cout<<dis[endNode]<<'\n'<<path[startNode];
}

void solve(int startNode,int endNode,int n){
    vector<int> dis(n+1,0);
    DijkstraAlgo(startNode,endNode,n,dis);
    shortestPath(startNode,endNode,n,dis);
}

int main()
{
    int n,m,startNode,endNode;
    cin>>n>>m>>startNode>>endNode;
    for(int i=1; i<=m; i++){
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }
    solve(startNode,endNode,n);
    return 0;
}