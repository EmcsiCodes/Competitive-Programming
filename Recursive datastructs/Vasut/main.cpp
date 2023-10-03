#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[10001];

int BFS(int start,int n,vector<bool>valid,vector<bool>&visited){
    queue<int> q;
    int num = 0;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                num++;
                if(valid[i]) q.push(i);
            } else if(!valid[i]) num++;
        }
    }
    return num;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<n; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> valid(n+1,true), visited(n+1,false);
    for(int i=1; i<=n; i++){
        if(adj[i].size()>2) valid[i] = false;
    }
    int res = 1;
    for(int i=1; i<=n; i++){
        if(!visited[i] && valid[i]) res = max(res, BFS(i,n,valid,visited));
    }
    cout<<res;
    return 0;
}
/*
12
1 2
1 3
2 4
2 5
1 9
3 6
5 7
7 8
8 10
8 11
10 12
*/