#include <iostream>
#include <vector>
#include <set>
#include <fstream>
using namespace std;

int n;
vector<int> adj[1001];
vector<bool> finalc(n+1,false);   
vector<int> parent(n+1,0);

void findCyclicNodes(int node,vector<bool>&visited,vector<bool>&cyclic){
    visited[node] = true;
    for(auto i:adj[node]){
        if(!visited[i]){
            parent[i] = node;
            findCyclicNodes(i,visited,cyclic);
            if(cyclic[i]) {
                cyclic[node] = !cyclic[node];
                finalc[node] = true;
            }
        } else if(parent[node]!=i){
            cyclic[i] = true;
            cyclic[node] = true;
            finalc[node] = true;
        }
    }
}

int main()
{
    ifstream in("f.in");
    int m;
    in>>n>>m;
    for(int i=1; i<=m; i++){
        int x,y;
        in>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> cyclic(n+1,false);
    vector<bool> visited(n+1,false);
    for(int i=1; i<=n; i++){
        if(!visited[i]) findCyclicNodes(i,visited,cyclic);
    }
    set<int> res;
    for(int i=1; i<=n; i++){
        if(!finalc[i]) res.insert(i);
    }
    cout<<res.size()<<'\n';
    for(auto i:res)cout<<i<<" ";
    return 0;
}