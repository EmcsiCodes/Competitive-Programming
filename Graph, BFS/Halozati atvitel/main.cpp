#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 100000
struct nodes{
    int node;
    int flow;
};
struct triple{
    int speed;
    int node;
    int h;
};
struct Compare {
    bool operator()(triple const& p1, triple const& p2)
    {
        return p1.speed < p2.speed;
    }
};
int n,m,k,start;
vector<nodes> adj[10001];

void DijkstraAlgo(vector<int> nodeSpeed){

    priority_queue<triple, vector<triple>, Compare> pq;
    nodeSpeed[start] = INF;
    pq.push({nodeSpeed[start],start,k});
    while(!pq.empty()){
        int node = pq.top().node;
        int h = pq.top().h;
        pq.pop();
        for(auto i:adj[node]){
            int currSpeed = min(nodeSpeed[node],i.flow);
            int currH = h - 1;
            if(currH >= 0){ 
                nodeSpeed[i.node] = max(currSpeed,nodeSpeed[i.node]); 
                pq.push({nodeSpeed[i.node],i.node,currH});
            }
        }
    }
    nodeSpeed[start] = 0;
    for(int i=1; i<=n; i++){
        cout<<nodeSpeed[i]<<'\n';
    }
}

int main()
{
    cin>>n>>m>>start>>k;
    vector<int> nodeSpeed(n+1,-1);
    for(int i=1; i<=m; i++){
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }
    DijkstraAlgo(nodeSpeed);
    return 0;
}
/*
6 7 1 2
1 2 2
1 5 4
1 3 2
1 4 3
5 4 1
5 3 4
3 6 1
*/