#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector< pair<int,int> > adj[1001];

void DijkstraAlgo(int startNode,int n){
    vector<int> dis(n+1,INT_MAX);
    priority_queue< pair<int,int>, vector< pair<int,int> > , greater< pair<int,int> > > pq;
    pq.push({0,startNode});
    dis[startNode] = 0;

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

    cout<<"Minimum distances from startNode to all the nodes are:"<<endl;
    for(int i=1; i<=n; i++){
        cout<<i<<": "<<dis[i]<<'\n';
    }
}

int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }
    int startNode;
    cout<<"StartNode:";
    cin>>startNode;
    DijkstraAlgo(startNode,n);
    return 0;
}
/*
5 9
1 2 10
1 3 3
2 3 1
3 2 4
2 4 2
3 5 2
3 4 8
4 5 7
5 4 9
*/