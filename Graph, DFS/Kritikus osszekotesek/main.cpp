#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<int> adj[10001];
set< pair<int,int> > bridges;
void makeThreeFromBridges(int node,vector<int>&disc,vector<int>&low,vector<int>&parent){
    static int time = 1;
    disc[node] = time;
    low[node] = time;
    time++;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            parent[node] = i;
            makeThreeFromBridges(i,disc,low,parent);
            low[node] = min(low[node],low[i]);
            if(low[i] > disc[node]){
                bridges.insert({node,i});
                bridges.insert({i,node});
            }
        } else if(parent[i]!=node){
            low[node] = min(disc[i],low[node]);
        }
    }
}

int BFS(int start,int n){
    vector<bool> visited(n+1,false);
    vector<int> dis(n+1,0);
    visited[start] = true;
    queue<int> q;
    int p;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                if(bridges.find({i,node})!=bridges.end() || bridges.find({node,i})!=bridges.end()) p = 1;
                else p = 0;
                dis[i] = dis[node] + p;        
                visited[i] = true;
                q.push(i);
            }
        }
    }
    int maxDis = 0;
    int maxDisIndex = 0;
    for(int i=1; i<=n; i++){
        if(maxDis < dis[i]){
            maxDis = dis[i];
            maxDisIndex = i;
        }
    }
    return maxDisIndex;
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
    vector<int> disc(n+1,0), low(n+1,0), parent(n+1,0);
    makeThreeFromBridges(1,disc,low,parent);
    int res = BFS(1,n);
    cout<<res<<" "<<BFS(res,n);
    return 0;
}
/*
8 8
1 2
1 3
2 4
2 5
6 3
7 3
8 5
4 5
*/