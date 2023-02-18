#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[40001];


void BFS(int startNode,int n,int &res, vector<bool> &visited){
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            res++;
            if(!visited[i]){
                visited[i] = true;    
                q.push(i);
            }
        }
    }
    res /= 2;
}

void solve(int startNode, int n){
    vector<bool> visited(n+1,false);
    int res = 0;
    BFS(startNode,n,res,visited);
    cout<<res<<'\n';
    int compNum = 0;
    for(int i=1; i<=n; i++){
        if(!visited[i] && adj[i].size()!=0){
            BFS(i,n,res,visited);
            compNum++;
        }
    }   
    cout<<compNum;
}

int main()
{
    int n,m,startNode,width;
    cin>>n>>m>>startNode>>width;
    for(int i=1; i<=m; i++){
        int x,y,z;
        cin>>x>>y>>z;
        if(z>width){
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    }
    solve(startNode,n);
    return 0;
}
/*
12 15 4 10
1 2 11
5 8 1
1 3 11
1 4 1
2 5 11
6 7 1
3 6 1
4 7 11
4 8 11
4 5 1
8 7 11
11 7 10
8 12 11
9 10 1
11 10 11
*/