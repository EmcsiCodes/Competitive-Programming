#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector<int> adj[201];

void BFS(int startNode,int time,int n,vector<int> &dis,vector<bool> visited, queue<int> q){    
    q.push(startNode);
    visited[startNode] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                dis[i] = dis[node] + time;
            }
        }
    }
}

void solve(int n,int startE,int startM,int timeE,int timeM){
    vector<int> disE(n+1,0), disM(n+1,0), path(n+1,0);
    vector<bool> visited(n+1,false);
    queue<int> q;
    BFS(startM,timeM,n,disM,visited,q);
    q.push(startE);
    visited[startE] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){ 
                disE[i] = disE[node] + timeE;
                if(disE[i] < disM[i]){
                   visited[i] = true;
                   q.push(i);
                   path[i] = node;
                }
            }
        }
    }
    int endNode = 0;
    for(int i=1; i<=n; i++){
        if(visited[i] && adj[i].size() == 0){
            endNode = i;
            break;
        }
    }
    if(endNode == 0){
        cout<<0;
        return;
    }
    stack<int> s;
    int i = endNode;
    while(i>0){
        s.push(i);
        i = path[i];
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<'\b';
}

int main()
{
    int n,m,startE,startM,timeE,timeM;
    cin>>n>>m>>startM>>startE>>timeM>>timeE;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    solve(n,startE,startM,timeE,timeM);
    return 0;
}
/*
10 14
1 8 1 2
1 2
1 4
2 3
4 3
2 5
3 6
3 7
4 7
6 9
7 6
8 7
8 9
9 10
6 5
*/