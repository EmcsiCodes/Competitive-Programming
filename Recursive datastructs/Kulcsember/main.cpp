#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> adj[100001];

pair<int,int> BFS(int start,int n){
    vector<bool> visited(n+1,0);
    vector<int> dis(n+1,0);
    queue<int> q;
    q.push(start);
    visited[start] = true;
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
    }
    int maxDis = 0;
    int maxDisI = 0;
    for(int i=1; i<=n; i++){
        if(maxDis < dis[i]){
            maxDis = dis[i];
            maxDisI = i;
        }
    }
    return {maxDisI, maxDis};
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
    pair<int,int> res = BFS(BFS(1,n).first,n);
    //meg parent visszajaras a mid megkeresesere
    // -> min max csoport = res.second/2 + res.second%2
    return 0;
}
