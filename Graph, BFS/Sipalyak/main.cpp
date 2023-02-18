#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[100001];
vector<int> startNode;
vector< pair<int,int> > endNode;

void BFS(int start,int n){
    vector<bool> visited(n+1,false);
    visited[start] = true;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
    for(auto &i:endNode){
        if(visited[i.first]){
            i.second++;
        }
    }
}

void solve(int n){
    for(auto i:startNode){
        BFS(i,n);
    }
    int mostVisitedEndNode = 0;
    int mostVisitedNum = 0;
    for(int i=0; i<endNode.size(); i++){
        if(endNode[i].second > mostVisitedNum){
            mostVisitedEndNode = endNode[i].first;
            mostVisitedNum = endNode[i].second;
        }
    }
    cout<<mostVisitedNum<<'\n'<<mostVisitedEndNode;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<bool> genStartNodes(n+1,true), genEndNodes(n+1,true);
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        genStartNodes[y] = false;
        genEndNodes[x] = false;
        adj[x].push_back(y);
    }
    for(int i=1; i<=n; i++){
        if(genStartNodes[i]){
            startNode.push_back(i);
        }
        if(genEndNodes[i]){
            endNode.push_back({i,0});
        }
    }
    solve(n);
    return 0;
}