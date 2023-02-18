#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[10001];
queue<int> q;

void BFS(int n,vector<bool> visited,vector<int> parent){
    vector<int> dis(n+1,0);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                dis[i] = dis[node] + 1;
                parent[i] = node;
            }
        }
    }
    int maxDis = 0;
    vector< pair<int,int > > res;
    for(int i=1; i<=n; i++){
        maxDis = max(maxDis,dis[i]);
        res.push_back({dis[i],parent[i]});
    }
    cout<<maxDis<<'\n';
    for(auto i:res){
        cout<<i.first<<" "<<i.second<<'\n';
    }
    cout<<'\b';
}

int main()
{
    int n,k,m;
    cin>>n>>k;
    vector<bool> visited(n+1,false);
    vector<int> parent(n+1,0);
    for(int i=1; i<=k; i++){
        int x; cin>>x;
        q.push(x);
        visited[x] = true;
        parent[x] = x;
    }
    for(int i=1; i<=n; i++){
        int x;
        while(cin>>x && x!=0){
            adj[i].push_back(x);
        }
    }
    BFS(n,visited,parent);
    return 0;
}
/*
11 3
1 3 5
4 0
11 0
4 6 5 0
1 3 6 8 0
7 3 6 0
4 3 5 7 10 8 0
5 6 10 0
4 6 9 0
8 10 0
9 6 7 0
2 0
*/