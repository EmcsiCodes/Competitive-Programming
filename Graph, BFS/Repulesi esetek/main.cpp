#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[100001];


bool isCyclic(int node,int &nodeNums,int n,vector<bool> &visited){
    int edgeNum = 0;
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()){
        node = q.front();
        q.pop();
        edgeNum += adj[node].size();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                nodeNums++;
            }
        }
    }
    edgeNum /= 2;

    if(edgeNum >= nodeNums){
        return true;
    }
    return false;
}

void solve(int n){
    vector<bool> visited(n+1,false);
    int res = 1;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            int nodeNum = 1;
            if(isCyclic(i,nodeNum,n,visited)){
                if(nodeNum!=2) res = (res * 2)%123456789;
            } else {
                res = (res * nodeNum)%123456789;
            }
        }
    }
    cout<<res;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    solve(n);
    return 0;
}
/*
9 8
1 5
1 5
3 2
2 4
6 7
7 8
6 8
9 8
*/