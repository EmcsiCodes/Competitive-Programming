#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1001];
bool bridges[1001][1001];

void DFS(int node,vector<int> &disc,vector<int> &low,vector<int> &parent,int &time){
    disc[node] = time;
    low[node] = time;
    time++;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            parent[i] = node;
            DFS(i,disc,low,parent,time);
            low[node] = min(low[node],low[i]);
            if(low[i] > disc[node]) {
                bridges[i][node] = true;
                bridges[node][i] = true;
            }
        } else if(parent[node]!=i) {
            low[node] = min(disc[i],low[node]);
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
    vector<int> disc(n+1,0),low(n+1,0),res,parent(n+1,0),nonCyclicNodes; int time = 1;

    for(int i=1; i<=n; i++){
        if(disc[i] == 0){
            DFS(i,disc,low,parent,time);
        }
    }
    for(int i=1; i<=n; i++){
        bool nonCyclicNode = true;
        for(auto j:adj[i]){
            if(!bridges[i][j]) nonCyclicNode = false;
        }
        if(nonCyclicNode) nonCyclicNodes.push_back(i);
    }
    cout<<nonCyclicNodes.size()<<'\n';
    for(auto i:nonCyclicNodes) cout<<i<<" ";
    return 0;
}
/*
4 4
1 2
2 3
3 4
2 4
*/
/*
7 8
1 2
2 3
3 1
2 4
4 6
6 5
7 1
3 4
*/