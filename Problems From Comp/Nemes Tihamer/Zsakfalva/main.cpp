#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[50000];

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> degree(n+1,0);
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        degree[x]++;
        degree[y]++;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue< pair<int, pair<int,int> > > q;
    vector<bool> visited(n+1,false);
    for(int i=1; i<=n; i++){
        if(degree[i] == 1){
            q.push({i,{i,1}});
            visited[i] = true;
        }
    }
    if(q.empty()) {
        cout<<-1;
        return 0;
    }
    while(!q.empty()){
        pair<int, pair<int,int> > node = q.front();
        q.pop();
        for(auto i:adj[node.first]){
            if(!visited[i] && degree[i] <= 2){
                q.push({i,{node.second.first,node.second.second+1}});
                visited[i] = true;
            }
        }
        if(q.empty()) {
            cout<<node.second.second<<'\n'<<node.second.first;
        }
    }
    return 0;
}