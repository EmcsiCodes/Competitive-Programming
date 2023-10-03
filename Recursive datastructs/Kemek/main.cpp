#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[20001];

int mostDistant(int start,int n){
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
                visited[i] = true;
                dis[i] = dis[node] + 1;
                q.push(i);
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
    return maxDisI;
}

int main()
{
    int n;
    cin>>n;
    vector<int> degree(n+1,0);
    for(int i=1; i<n; i++){
        int x,y;
        cin>>x>>y;
        adj[y].push_back(x);
        degree[x]++;
    }
    int start = 0;
    int maxDegree = 0;
    int maxDegreeI = 0;
    for(int i=1; i<=n; i++){
        if(degree[i] == 0) start = i;
        if(maxDegree < adj[i].size()){
            maxDegree = adj[i].size();
            maxDegreeI = i;
        }
    }
    cout<<start<<'\n'<<maxDegreeI<<'\n'<<mostDistant(start,n);
    return 0;
}
/*
6
2 1
3 1
6 3
5 4
4 2
*/