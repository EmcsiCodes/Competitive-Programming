#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[5001];

int DFS(int node,vector<bool>&visited){
    visited[node] = true;
    int curr = 0;
    for(auto i:adj[node]){
        if(!visited[i]){
            curr += DFS(i,visited);
        }
    }
    return curr + 1;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> inDegree(n+1,0), outDegree(n+1,0);
    vector<int> a,b;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        inDegree[y]++;
        outDegree[x]++;
    }
    for(int i=1; i<=n; i++){
        if(inDegree[i] == 0) a.push_back(i);
        if(outDegree[i] !=0 && inDegree[i] != 0) b.push_back(i);
    }
    vector<bool> visited(n+1,false);
    int maxWins = 0;
    int maxWinsI = 0;
    for(auto i:a){
        if(!visited[i]){
            int curr = DFS(i,visited);
            if(curr > maxWins){
                maxWins = curr;
                maxWinsI = i;
            }
        }
    }
    cout<<a.size()<<" "; for(auto i:a) cout<<i<<" ";
    cout<<'\n'<<b.size()<<" "; for(auto i:b) cout<<i<<" ";
    cout<<'\n'<<maxWinsI;
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