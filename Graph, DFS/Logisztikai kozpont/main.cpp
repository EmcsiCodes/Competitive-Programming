#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define LL long long
vector< pair<int, LL> > adj[100001];
vector<int> path;

pair<LL,int> BFS(int start,int n){
    queue<int> q;
    vector<bool> visited(n+1,false);
    vector<LL> dis(n+1,0);
    vector<int> parent(n+1,0);
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i.first]){
                parent[i.first] = node;
                visited[i.first] = true;
                q.push(i.first);
                dis[i.first] = dis[node] + i.second;
            }
        }
    }
    LL maxDis = 0;
    int maxDisIndex = 0;
    for(int i=1; i<=n; i++){
        if(dis[i] > maxDis){
            maxDis = dis[i];
            maxDisIndex = i;
        }
    }
    if(start!=1) path = parent;
    return {maxDis,maxDisIndex};
}

void checkBestSpot(pair<LL,int> res,int n){
    LL best = res.first / 2;
    int i = res.second;
    LL distance = 0, lastDis = 0;
    int distanceIndex = 0, lastDisIndex = 0, bestIndex = 0;
    int db=0;
    while(distance<best && i>0){
        LL d;
        for(auto &j:adj[i]) if(j.first==path[i]) {d = j.second; break;}
        lastDis = distance;
        distance += d;
        if(d==0) db++;
        else db = 0;
        lastDisIndex = i;
        distanceIndex = path[i];
        i = path[i];
    }
    if(abs(best - lastDis)<abs(best - distance)) {
        best = lastDis;
        bestIndex = lastDisIndex;
    }
    else {
        best = distance;
        bestIndex = distanceIndex;
    }
    cout<<max(res.first - best, best)<<'\n';
    cout<<1<<'\n'<<bestIndex;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<n; i++){
        int x,y;
        LL z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }
    pair<LL,int> res = BFS(BFS(1,n).second,n);
    checkBestSpot(res,n);
    return 0;
}
/*
10
8 1 87
3 8 53
6 8 42
8 10 86
7 8 19
2 8 77
8 9 68
5 8 61
8 4 46
*/