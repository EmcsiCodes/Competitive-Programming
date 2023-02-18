#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define INF 1000000

int n,m,start;
vector<int> adj[10001];
queue<int> startNodes;
stack<int> s;
struct cycle{
    int d;
    int x;
    int y;
};
cycle BFS(int node,vector<int>&dis,vector<int>&parent){
    queue<int> q;
    vector<bool> visited(n+1,false);
    parent[node] = start;
    q.push(node);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(dis[i] == 0 && i!=start){
                visited[i] = true;
                parent[i] = node;
                dis[i] = dis[node] + 1;
                q.push(i);
            } else if(parent[node]!=i && !visited[i]) return {dis[node] + dis[i] + 1,node,i};
        }
    }
    return {INF,0,0};
}

int main()
{
    cin>>n>>m>>start;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> dis(n+1,0), parent(n+1,0);
    for(auto i:adj[start]) {
        startNodes.push(i);
        dis[i] = 1;
    }
    int minDis = INF, x, y;
    while(!startNodes.empty()) {
        cycle curr = BFS(startNodes.front(),dis,parent);
        if(curr.d < minDis){
            minDis = curr.d;
            x = curr.x;
            y = curr.y;
        }
        startNodes.pop();
    }
    if(minDis == INF){
        cout<<0;
    }
    else {
        stack<int> s;
        while(y>0){
            s.push(y);
            y = parent[y];
        }
        cout<<minDis<<'\n';
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
        while(x>start){
            cout<<x<<" ";
            x = parent[x];
        }
    }
    return 0;
}
/*
8 10 2
1 2
2 3
2 4
3 5
5 6
6 2
6 3
3 7
7 8
4 8
*/