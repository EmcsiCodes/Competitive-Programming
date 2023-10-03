#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector< pair<int,int> > adj[100001];

pair<int,int> BFS(int start, int n){
    vector<bool> visited(n+1,false);
    vector<int> dis(n+1,0);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i.first]){
                visited[i.first]= true;
                q.push(i.first);
                dis[i.first] = dis[node] + i.second;
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
    return {maxDis, maxDisI};
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<n; i++){
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }
    pair<int,int> dis1 = BFS(1,n);
    //cout<<dis1.first<<" "<<dis1.second;
    pair<int,int> res = BFS(dis1.second,n);

    cout<<res.first<<'\n'<<dis1.second<<" "<<res.second;
    return 0;
}
/*
10
2 1 3
3 1 1
6 4 2
4 2 6
7 5 1
5 2 5
8 7 9
9 6 6
10 2 8
*/