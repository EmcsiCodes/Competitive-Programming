#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[10001];

void DFS(int node,int finish,vector<bool> &visited,vector<bool> &canFinish){
    if(node == finish){
        canFinish[node] = true;
        return;
    }
    visited[node] = true;
    for(auto i:adj[node]){
        if(!visited[i]){
            DFS(i,finish,visited,canFinish);
            if(canFinish[i]) canFinish[node] = true;
        } else if(canFinish[i]) canFinish[node] = true;
    }
}

void topSort(int start,int finish,int n,vector<bool> canFinish){
    vector<int> inDegree(n+1,0), IND(n+1,0),res;
    for(int i=1; i<=n; i++){
        for(auto j:adj[i]){
            if(canFinish[i] && canFinish[j]){
                inDegree[j]++;
                IND[j]++;
            }
        }
    }
    queue<int> q;
    q.push(start);
    int in = 0,out = 0;
    while(!q.empty() && !(q.size() == 1 && q.front() == finish)){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(canFinish[i]) {
                out++;
                inDegree[i]--;
            }
            if(inDegree[i] == 0 && canFinish[i]) {
                in += IND[i];
                q.push(i);
            }
        }
        if(q.size() == 1 && q.front()!=finish && in == out) res.push_back(q.front());
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
}

int main()
{
    int n,m,start,finish;
    cin>>n>>m>>start>>finish;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    vector<bool> visited(n+1,false), canFinish(n+1,false);
    DFS(start,finish,visited,canFinish);
    topSort(start,finish,n,canFinish);
    /*for(int i=1; i<=n; i++){
            cout<<i<<": "<<canFinish[i]<<endl;
    }*/
    return 0;
}
/*
13 15 1 8
1 3
3 9
1 4
1 5
4 2
5 6
6 7
6 13
7 8
9 11
9 10
10 5
11 12
12 6
8 2
*/