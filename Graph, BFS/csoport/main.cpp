#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector< pair<int,char> > adj[10001];

bool BFS(int startNode,int n,vector<bool> &visited, vector<int> &res){
    queue<int> q;
    q.push(startNode);
    res[startNode] = 0;
    visited[startNode] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            int check;
            if(i.second == 'F') check = res[node];
            else check = !res[node];            
            if(!visited[i.first]){
                q.push(i.first);
                visited[i.first] = true;
                res[i.first] = check;
            } else if(check != res[i.first]) return false;
        }
    }
    return true;
}

void solve(int n){
    vector<bool> visited(n+1,false);
    vector<int> res(n+1,-1);
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            if(!BFS(i,n,visited,res)){
                cout<<-1;
                return;
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(res[i] == 0){
            cout<<i<<" ";
        }
    }
    cout<<'\b'<<'\n';
    for(int i=1; i<=n; i++){
        if(res[i] == 1){
            cout<<i<<" ";
        }
    }
    cout<<'\b';
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back({y,'F'});
        adj[y].push_back({x,'F'});
    }
    for(int i=1; i<=k; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back({y,'E'});
        adj[y].push_back({x,'E'});
    }
    solve(n);
    return 0;
}
/*
11 7 4
1 2
3 4
5 6
9 10
10 11
11 9
7 8
2 3
6 9
8 4
7 11
*/