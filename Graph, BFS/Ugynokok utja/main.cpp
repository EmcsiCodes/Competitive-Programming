#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[100001];

pair<int,int> BFS(int startNode,int n){
    vector<bool> visited(n+1,false);
    vector<int> dis(n+1,1);
    queue<int> q;
    int lastNode;
    q.push(startNode);
    visited[startNode] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                dis[i] = dis[node] + 1;
            }
        }
        if(q.empty()) lastNode = node; 
    }
   return {dis[lastNode], lastNode};
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<n; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int res = BFS(BFS(1,n).second,n).first;
    if(res >= m + 1) cout<<m + 1;
    else cout<<res + (m - res + 1)/2;
    return 0;
}
/*
9 8
1 2
2 3
3 4
5 2
8 3
6 9
7 9
9 3
*/