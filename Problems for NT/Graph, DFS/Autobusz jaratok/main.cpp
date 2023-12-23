#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define INF 1000000
vector< pair<int,int> > adj[1001];

void DijkstraAlgo(int start,int end,int n){
    vector<int> dis(n+1,INF), path(n+1,0);
    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;
    pq.push({0,start});
    dis[start] = 0;
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        for(auto i:adj[node]){
            if(dis[i.first] > dis[node] + i.second){
                path[i.first] = node;
                dis[i.first] = dis[node] + i.second;
                pq.push({dis[i.first],i.first});
            }
        }
    }
    if(dis[end] == INF){
        cout<<0;
        return;
    }
    cout<<dis[end]<<'\n';
    stack<int> s;
    int i = end;
    while(i>0){
        s.push(i);
        i = path[i];
    }
    cout<<s.size()<<'\n';
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int x,y,z;
        cin>>x>>y>>z;
        z += 1000;
        adj[x].push_back({y,z});
    }
    int startNode,endNode;
    cin>>startNode>>endNode;
    DijkstraAlgo(startNode,endNode,n); //nem jo, bellman ford algo kell
    return 0;
}