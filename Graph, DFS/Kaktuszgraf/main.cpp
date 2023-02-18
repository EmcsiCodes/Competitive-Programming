#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1001];
int maxLength = 0;
void DFS(int node,vector<int> &disc,int time){
    disc[node] = time;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            DFS(i,disc,time+1);
        } else maxLength = max(disc[node] - disc[i] + 1,maxLength);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> disc(n+1,0);
    for(int i=1; i<=n; i++){
        if(disc[i] == 0) DFS(i,disc,1);
    }
    cout<<maxLength;
    return 0;
}