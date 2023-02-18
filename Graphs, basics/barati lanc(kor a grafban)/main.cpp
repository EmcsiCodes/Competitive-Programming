#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map< pair<int,int>, bool > edges;
vector<int> adj[1001];
bool visited[1001] = {false};
vector<int> path;

bool isSafe(int node){
    if(!edges[{node, *path.rbegin()}]) return false;
    for(auto i:path){
        if(i==node) return false;
    }
    return true;
}

void DFSforCycle(int node, bool visited[], int n){
    if(path.size() == n){
        if(edges[{1,*path.rbegin()}]) 
        {
            for(auto i:path){
                cout<<i<<" ";
            }
            cout<<'\b';
            return;
        }
    }
    for(int i=1; i<=n; i++){
        if(!visited[i] && isSafe(i)){
            path.push_back(i);
            visited[i] = true;
            DFSforCycle(i,visited,n);
            visited[i] = false;
            path.pop_back();
        }
    }
}

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        int x;
        for(int j=0; j<x; j++){
            int y;
            cin>>y;
            adj[i].push_back(y);
            edges[{i,y}] = true;
            edges[{y,i}] = true;
        }
    }
    DFSforCycle(1,visited,n);
    return 0;
}
/*
5 3
3 3 4 5
3 4 3 5
4 1 2 4 5
3 1 3 2
3 1 2 3
*/