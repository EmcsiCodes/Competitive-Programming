#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
#define INF 1000000
vector< pair<int,int> > adj[20001];

void DijkstraAlgo(int startNode,int endNode,int n,vector<int> code){
    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;
    vector<int> dis(n+1,INF);
    vector<int> path(n+1,0);
    dis[startNode] = 0;
    pq.push({0,startNode});
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
    if(dis[endNode] == INF) {
        cout<<-1;
        return;
    }
    cout<<dis[endNode]<<" ";
    int i = endNode;
    stack<int> s;
    while(i>0){
        s.push(i);
        i = path[i];
    }
    cout<<s.size()<<'\n';
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<'\b';
}

void solve(int n){
    vector<int> code(n+1,0);
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        code[i] = x;
    }
    int startNode, endNode;
    cin>>startNode>>endNode;
    for(int i=1; i<=n; i++){
        for(auto &j:adj[i]){
            if(code[j.first]!=code[i]){
                j.second = 1;
            }
        }
    }
    DijkstraAlgo(startNode,endNode,n,code);
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        for(int j=1; j<=x; j++){
            int y;
            cin>>y;
            adj[i].push_back({y,0});
        }
    }
    solve(n);
    return 0;
}
/*
6
3 2 3 4
3 1 3 6
5 1 2 4 5 6
2 1 3
2 3 6
3 2 3 5
1
3
2
2
3
1
1 5
*/