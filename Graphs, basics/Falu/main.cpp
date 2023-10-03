#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

struct triple{
    int node1;
    int node2;
    int dis;
};

triple res = {0,0,10000000};
vector< pair<int,int> > adj[1001];

void BFS(int start,int n){
    queue<int> q;
    vector<bool> visited(n+1,false);
    vector<int> dis(n+1,0);
    q.push(start);
    visited[start] = true;
    int layer = 2;
    int backnode = start;
    while(!q.empty() && layer!=0){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i.first]){
                visited[i.first] = true;
                dis[i.first] = dis[node] + i.second;
                q.push(i.first);
                if(layer == 1 && dis[i.first]<res.dis) res = {start,i.first,dis[i.first]};
            }
        }
        if(q.back()!=backnode){
            backnode = q.back();
            layer--;
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }
    int zsakfalvakdb = 0;
    int maxDegree = 0;
    int maxDegreeIndex = 0;
    for(int i=1; i<=n; i++){
        if(adj[i].size() == 1) {
            zsakfalvakdb++;
        }
        if(adj[i].size()>maxDegree){
            maxDegree = adj[i].size();
            maxDegreeIndex = i;
        }
    }
    cout<<zsakfalvakdb<<'\n'<<maxDegreeIndex<<'\n';
    for(int i=1; i<=n; i++){
        BFS(i,n);
    }
    cout<<res.node1<<" "<<res.node2;
    return 0;
}
/*
6 7
1 2 10
2 3 15
2 4 10
2 5 5
3 5 5
4 5 15
5 6 5
*/