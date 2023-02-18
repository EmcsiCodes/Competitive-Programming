#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[10001];

void canReachFromStart(int node,vector<bool> &visited){
    visited[node] = true;
    for(auto i:adj[node]){
        if(!visited[i]){
            canReachFromStart(i,visited);
        }
    }
}

void DFS(int node,vector<bool> &visitedSec, vector<bool> &canReach){
    visitedSec[node] = true;
    for(auto i:adj[node]){
        if(!visitedSec[i]){
            DFS(i,visitedSec,canReach);   
            if(canReach[i]) canReach[node] = true;
        }else if(canReach[i]) canReach[node] = true;
    }
}

int main()
{
    int n,m,start;
    cin>>n>>m>>start;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    vector<bool> visited(n+1,false),visitedSec(n+1,false), canReach(n+1,false);
    canReach[start] = true;
    canReachFromStart(start,visited);
    for(int i=1; i<=n; i++){
        if(!visited[i] && !visitedSec[i]){
            DFS(i,visitedSec,canReach);
        }
    }
    vector<int> res;
    for(int i=1; i<=n; i++){
        if(canReach[i] && i!=start && !visited[i]){
            res.push_back(i);
        }
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
9 13 4
1 2
2 3
2 1
1 6
3 4
4 5
5 3
5 8
6 7
7 6
7 8
8 9
9 8
*/