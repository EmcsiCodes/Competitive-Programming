#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1001];

//void DFS()

int main()
{
    int n,m,start,end;
    cin>>n>>m>>start>>end;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> visited(n+1,false);
    vector<int> parent(n+1,0);
    //DFS(start,end,visited,parent);
    return 0;
}