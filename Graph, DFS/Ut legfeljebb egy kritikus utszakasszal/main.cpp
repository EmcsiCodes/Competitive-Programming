#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 1000000
vector< pair<int,int> > adj[100001];

void DijkstraAlgo(int startNode,int n){
    vector<int> dis(n+1,INF);
    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;
    dis[startNode] = 0;
    pq.push({dis[startNode],startNode});
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        for(auto i:adj[node]){
            if(dis[i.first] > dis[node] + i.second){
                dis[i.first] = dis[node] + i.second;
                pq.push({dis[i.first],i.first});
            }
        }
    }
    vector<int> res;
    for(int i=1; i<=n; i++){
        if(dis[i]<=1) res.push_back(i);
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
}

int main()
{
    int n,m,k,startNode;
    cin>>n>>m>>k>>startNode;
    for(int i=1; i<=k; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back({y,1});
    }
    for(int i=1; i<=m-k; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back({y,0});
    }
    DijkstraAlgo(startNode,n);
    return 0;
}
/*
7 11 6 1
1 2
1 3
3 4
6 3
4 5
4 6
2 7
7 3
6 2
5 6
7 6
*/