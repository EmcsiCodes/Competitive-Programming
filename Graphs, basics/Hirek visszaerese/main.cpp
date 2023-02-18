#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<int> cycles;
void DFS(int node,vector<int> visited,int adj[]){
    visited[node] += 1;
    int i = adj[node];
    if(visited[i]<=1){
        DFS(i,visited,adj);
    } else {
        for(int j=1; j<=visited.size(); j++){
            if(visited[j]>=2){
                cycles.insert(j);
            }
        }
        return;
    }
}

void findCycles(int n,int adj[]){
    vector<int> visited(n+1,0);
    for(int i=1; i<=n; i++){
        if(visited[i]==0){
            DFS(i,visited,adj);
        }
    }
    cout<<cycles.size()<<endl;
    for(auto i:cycles){
        cout<<i<<" ";
    }
    cout<<'\b';
}

int main()
{
    int n;
    cin>>n;
    int adj[100002];
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        adj[i]=x;
    }
    //findCycles(n);
    return 0;
}
/*
11
8 1 1 11 6 7 5 9 10 8 4
*/