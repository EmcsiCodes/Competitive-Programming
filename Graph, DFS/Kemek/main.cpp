#include <iostream>
#include <vector>

using namespace std;
vector<int> degree(10001,0);
vector<int> adj[10001];
void DFS(int node,vector<int>&disc,vector<int>&low,vector<int>&parent,vector<bool>&articPoints){
    static int time = 1;
    disc[node] = time;
    low[node] = time;
    time++;
    int child = 0;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            child++;
            parent[i] = node;
            DFS(i,disc,low,parent,articPoints);
            low[node] = min(low[node],low[i]);
            if(parent[node]==0 && child>1) articPoints[node] = true;
            if(parent[node]!=0 && low[i]>=disc[node]) {
                //degree[node]--;
                articPoints[node] = true;
            }
        } else if(parent[node]!=i) {
            low[node] = min(low[node],disc[i]);
            degree[i]--;
            //cout<<node<<":"<<i<<" ";
        }
    }
}

void findArticPoints(int n,vector<bool>&articPoints){
    vector<int> disc(n+1,0),parent(n+1,0),low(n+1,0);
    for(int i=1; i<=n; i++){
        if(disc[i] == 0) DFS(i,disc,low,parent,articPoints);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<bool> articPoints(n+1,false);
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        degree[x]++;
        degree[y]++;
    }
    //for(int i=1; i<=n; i++) cout<<i<<":"<<degree[i]<<" ";
    //cout<<endl;
    findArticPoints(n,articPoints);
    bool noRes = true;
    int maxSeparation = 0;
    int maxSeparationIndex = 0;
    //cout<<endl;
    for(int i=1; i<=n; i++){
        //cout<<i<<":"<<degree[i]<<" ";
        if(articPoints[i] && maxSeparation < degree[i]){
            noRes = false;
            maxSeparation = degree[i];
            maxSeparationIndex = i;
        }
    }
    if(noRes) cout<<0;
    else cout<<maxSeparationIndex;
    return 0;
}
/*
8 9
1 3
3 6
2 4
3 4
4 5
7 5
7 4
2 8
8 4
*/