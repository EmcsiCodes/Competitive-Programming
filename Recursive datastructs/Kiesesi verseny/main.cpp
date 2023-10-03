#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[5001];

void DFS(int node,vector<bool>&visited,vector<int>&winNum){
    visited[node] = true;
    for(auto i:adj[node]){
        if(!visited[i]) {
            DFS(i,visited,winNum);
            winNum[node] += winNum[i] + 1;
        } else winNum[node] += winNum[i] + 1; 
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> inDegree(n+1,0), winNum(n+1,0);
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        inDegree[y]++;
    }
    vector<bool> visited(n+1,false);
    for(int i=1; i<=n; i++){
        if(!visited[i]) DFS(i,visited,winNum);
    }
    int maxWinsBefLoss = 0;
    int maxWinsBefLossI = -1;
    int maxWins = 0;
    int maxWinsI = 0;
    int minWins = 100000000;
    int minWinsI = 0;
    int minWinssec = 100000000;
    int minWinssecI = -1;
    for(int i=1; i<=n; i++){
        if(inDegree[i] != 0 && maxWinsBefLoss < adj[i].size()){
            maxWinsBefLoss = adj[i].size();
            maxWinsBefLossI = i;
        }
        if(maxWins < winNum[i]){
            maxWins = winNum[i];
            maxWinsI = i;
        }
        if(inDegree[i] == 0 && minWins > winNum[i]){
            minWins = winNum[i];
            minWinsI = i;
        } else if(inDegree[i] == 0 && minWinssec > winNum[i]){
            minWinssec = winNum[i];
            minWinssecI = i;
        }
    }
    cout<<maxWinsBefLossI<<'\n'<<maxWinsI<<'\n';
    if(minWinssecI == -1) {
        cout<<-1;
        return 0;
    }
    cout<<minWinsI<<" "<<minWinssecI;
    return 0;
}
/*
8 5
1 2
4 3
4 1
7 8
5 6
*/