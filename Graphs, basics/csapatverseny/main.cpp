#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> adj[501];
bool visited[501] = {false};

void DFS(int node,bool visited[],unordered_map<int,bool> cycle){

    cycle[node] = true;
    visited[node] = true;
    for(auto i:adj[node]){    
        if(cycle[i] == true){
            cout<<i<<endl;
            return;
        }
        if(!visited[i]){
            DFS(i,visited,cycle);
        }
    }
}

void beatThemselfs(int n){
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            unordered_map<int,bool> cycle;
            DFS(i,visited,cycle);
        }
    }
}

void beatAndBeaten(int n,unordered_map< pair<int,int>, bool > edges){
    for(int i=1; i<=n; i++){
        for(auto j:adj[i]){
            /*if(edges[{i,j}]==true && edges[{j,i}]==true){
                cout<<i<<" "<<j<<endl;
                return;
            }*/ 
        }
    }
}

void notBeaten(int n){
    unordered_map<int,bool> beat;
    for(int i=1; i<=n; i++){
        for(auto j:adj[i]){
            beat[j] = true;
        }
    }
    for(auto i:beat){
        if(i.second == false && !adj[i.first].empty()) cout<<i.first<<" ";
    }
    cout<<endl;
}

int main()
{
    int n,m;
    cin>>n>>m;
    unordered_map<pair<int,int>, bool> edges;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
       // edges[{x,y}] = true;
    }
    for(int i=1; i<=n; i++){
        cout<<i<<": ";
        for(auto j:adj[i]) cout<<j<<" ";
        cout<<endl;
    }
    //beatAndBeaten(n,edges);
    notBeaten(n);
    beatThemselfs(n);
    return 0;
}
/*
6 7
1 2
1 3
3 1
2 4
4 1
5 2
5 3

*/