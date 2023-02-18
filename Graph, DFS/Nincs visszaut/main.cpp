#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[100001];

void canReachFromStart(int node,vector<bool> &visited){
    visited[node] = true;
    for(auto i:adj[node]){
        if(!visited[i]){
            canReachFromStart(i,visited);
        }
    }
}

void canReachStart(int node,int start,vector<bool> visited,vector<bool> &visitedSec,vector<bool> &canReach){
    visitedSec[node] = true;
    if(node == start) return;
    //cout<<node<<"->";
    for(auto i:adj[node]){
        //cout<<i<<": ";
        if(!visitedSec[i] && visited[i]){
            canReachStart(i,start,visited,visitedSec,canReach);
            if(canReach[i]) canReach[node] = true;
        } else if(canReach[i]) canReach[node] = true;
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
    vector<bool> visited(n+1,false);
    vector<bool> visitedSec(n+1,false);
    vector<bool> canReach(n+1,false);

    canReachFromStart(start,visited);
    canReach[start] = true;
    for(int i=1; i<=n; i++){
        if(!visitedSec[i] && visited[i] && i!=start){
            canReachStart(i,start,visited,visitedSec,canReach);
        }
    }
    vector<int> res;
    for(int i=1; i<=n; i++){
        if(!canReach[i] && visited[i]) res.push_back(i);
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
}
/*
9 14 4
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
3 6
*/