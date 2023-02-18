#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[10001];
vector<int> canReach;
void DFS(int node,vector<bool>&visited,vector<bool>&finishBack,vector<int>&parent,vector<bool>&res){
    visited[node] = true;
    for(auto i:adj[node]){
        if(!visited[i]){
            parent[node] = i;
            DFS(i,visited,finishBack,parent,res);
            if(!res[i] && !finishBack[node]){
                res[node] = false;
                return;
            }
            finishBack[node] = false;
        } else if(parent[i]!=node){
            finishBack[i] = true;
            res[node] = false;
            return;
        }
    }
}

void BFS(int start,int n,vector<bool>res){
    queue<int> q;
    vector<bool> visited(n+1,false);
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i] && res[i]){
                canReach.push_back(i);
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    int n,m,start;
    cin>>n>>m>>start;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> visited(n+1,false), finishBack(n+1,false), res(n+1,true);
    vector<int> parent(n+1,0);
    DFS(start,visited,finishBack,parent,res);
    BFS(start,n,res);
    cout<<canReach.size()<<'\n';
    for(auto i:canReach) cout<<i<<" ";
    return 0;
}
/*
11 12 3
7 8
3 1
2 3
3 4
4 7
7 11
2 6
1 5
5 8
5 9
9 10
5 10
*/