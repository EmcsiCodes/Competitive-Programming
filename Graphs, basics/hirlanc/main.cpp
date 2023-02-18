#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector< pair<int,string> > adj[201];
map<int,bool> visited;

void BFS(int node){
    visited[node] = true;
    for(auto i:adj[node]){
        if(!visited[i.first]){
            //adj[i].second
        }
    }
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back({y,NULL});
    }
    for(int i=1; i<=k; i++){
        int x;
        string s;
        cin>>x>>s;
        for(auto j:adj[x]){
            j.second = s;
        }
        visited[x] = false;
    }
    return 0;
}