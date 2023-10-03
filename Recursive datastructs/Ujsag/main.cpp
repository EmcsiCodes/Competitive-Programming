#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int a,b;
vector<int> adj[1001];

vector<int> BFS(int start,int n,vector<int>&parent){
    vector<bool> visited(n+1,false);
    vector<int> dis(n+1,0);
    visited[start] = true;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                dis[i] = dis[node] + 1;
                parent[i] = node;
                if(i!=a && i!=b) q.push(i);
                visited[i] = true;
            }
        }
    }
    return dis;
}

int main()
{
    int n;
    cin>>n>>a>>b;
    vector<int> degree(n+1,0);
    vector<int> parent(n+1,0);
    for(int i=1; i<n; i++){
        int x,y;
        cin>>x>>y;
        adj[y].push_back(x);
        degree[x]++;
    }
    int start = 0;
    for(int i=1; i<=n; i++){
        if(degree[i] == 0){
            start = i;
            break;
        }
    }
    vector<int> res1 = BFS(a,n,parent);
    int resq = 0;
    for(int i=1; i<=n; i++){
        if(res1[i]!=0) resq++;
    }
    vector<int> res = BFS(start,n,parent);
    cout<<resq<<'\n'<<res[a] - 1<<'\n';
    while(a!=b){
        if(res[a]>res[b]) a = parent[a];
        else b = parent[b];
    }
    cout<<a;
    return 0;
}
/*
9 1 3
1 5
2 4
3 4
5 6
7 6
4 5
9 8
8 1
*/