#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[201];

struct triple{
    int fromNode;
    int toNode;
    int s;
};

void DFS(int node,int lastNode,vector<bool> &visited,vector<triple> &res){
    for(auto i:adj[node]){
        if(!visited[i]){
            visited[node] = true;
            res.push_back({node,i,1});
            DFS(i,node,visited,res);
            res.push_back({i,node,0});
        } else if(i!=lastNode) return;
    }
}

void solve(int n){
    vector<bool> visited(n+1,false);
    vector<triple> res;
    DFS(1,0,visited,res);
    cout<<res.size()<<'\n';
    for(auto i:res){
        cout<<i.fromNode<<" "<<i.toNode<<" "<<i.s<<'\n';
    }
    for(int i=1; i<=n; i++){
        cout<<i<<": ";
        for(auto j:adj[i])cout<<j<<" ";
        cout<<'\n';
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    solve(n);
    return 0;
}
/*
9 13
8 9
8 7
7 9
4 9
7 2
1 2
2 3
3 4
2 4
1 4
1 6
6 5
4 5
*/