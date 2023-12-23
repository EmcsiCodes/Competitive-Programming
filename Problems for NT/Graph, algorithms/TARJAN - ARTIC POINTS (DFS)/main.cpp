#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1001];
vector<bool> articPoints(1001,false);

void DFS(int node,vector<int>&disc,vector<int>&low,vector<int>&parent){
    static int time = 1;
    disc[node] = time;
    low[node] = time;
    int childNum = 0;
    time++;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            childNum++;
            parent[i] = node;
            DFS(i,disc,low,parent);
            low[node] = min(low[node],low[i]);
            //case 1: if the node is the root node
            if(parent[node]==0 && childNum>1) articPoints[node] = true;
            //case 2: atleast 1 component will be separated
            if(parent[node]!=0 && low[i]>=disc[node]) articPoints[node] = true;
        } else if(parent[node]!=i) low[node] = min(low[node],disc[i]);
    }
}

void findArticulationPoints(int n){
    vector<int> disc(n+1,0), low(n+1,0), parent(n+1,0);
    for(int i=1; i<=n; i++){
        if(disc[i] == 0) DFS(i,disc,low,parent);
    }
    for(int i=1; i<=n; i++) if(articPoints[i]) cout<<i<<" ";
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
    findArticulationPoints(n);
    return 0;
}
/*
7 7
1 3
3 6
2 4
3 4
4 5
7 5
7 4
*/