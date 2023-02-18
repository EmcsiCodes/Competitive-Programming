#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> adj[10001];
set< pair<int,int> > bridges,res;

void findBridges(int node,vector<int>&disc,vector<int>&low,vector<int>&parent){
    static int time = 1;
    disc[node] = time;
    low[node] = time;
    time++;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            parent[node] = i;
            findBridges(i,disc,low,parent);
            low[node] = min(low[node],low[i]);
            if(low[i] > disc[node]){
                bridges.insert({node,i});
            }
        } else if(parent[i]!=node){
            low[node] = min(low[node],disc[i]);
        }
    }
}

void DFS(int node,vector<bool>&visited,vector<int>&parent){
    visited[node] = true;
    for(auto i:adj[node]){
        //cout<<i<<" es "<<node;
        if(!visited[i] && bridges.find({node,i})==bridges.end() && bridges.find({i,node})==bridges.end()){
            parent[node] = i;
            res.insert({node,i});
            cout<<node<<" "<<i<<'\n';
            DFS(i,visited,parent);
        } else if(parent[i]!=node && res.find({i,node})==res.end() && 
        bridges.find({node,i})==bridges.end() && bridges.find({i,node})==bridges.end()){
            res.insert({node,i});
            cout<<node<<" "<<i<<'\n';
        }
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
    vector<int> disc(n+1,0),low(n+1,0),parent(n+1,0);
    vector<bool> visited(n+1,false);
    findBridges(1,disc,low,parent);
    for(int i=0; i<=n; i++) parent[i] = 0;
    cout<<bridges.size()<<'\n';
    for(auto i:bridges){
        if(!visited[i.first]) DFS(i.first,visited,parent);
        if(!visited[i.second]) DFS(i.second,visited,parent);
    }
    for(auto i:bridges){
        cout<<i.first<<" "<<i.second<<'\n';
        cout<<i.second<<" "<<i.first<<'\n';
    }
    return 0;
}
/*
10 12
9 10
8 9
10 8
8 7
7 5
7 6
5 1
1 2
1 3
2 4
3 4
6 3
*/