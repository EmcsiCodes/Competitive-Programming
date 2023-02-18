#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector< pair<int,int> > adj[100001];


void BFS(int startNode,pair<int,int> &endNode,int n,vector<int> v){
    vector<bool> visited(n+1,false);
    vector<int> dis(n+1,0);
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i.first]){
                visited[i.first] = true;
                dis[i.first] = dis[node] + i.second;
                q.push(i.first);
            }
        }
    }
    int maxDis = 0;
    int maxDisIndex = 0;

    for(int i=1; i<v.size(); i++){
        if(maxDis < dis[v[i]]){
            maxDis = dis[v[i]];
            maxDisIndex = v[i];
        }
    }
    endNode = {maxDis, maxDisIndex};
}

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1; i<n; i++){
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }
    vector<int> v(k+1,0);
    for(int i=1; i<=k; i++){
        int x;
        cin>>x;
        v[i] = x;
    }
    pair<int,int> endNode = {0,0}, longestPath = {0,0};
    BFS(1,endNode,n,v);
    BFS(endNode.second,longestPath,n,v);
    cout<<endNode.second<<" - "<<longestPath.second<<": "<<longestPath.first;
    return 0;
}