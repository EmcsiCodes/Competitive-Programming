#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[200001];
vector<int> futarok;

void BFS(int n,int k){
    vector<bool> visited(n+1,false);
    vector<int> dis(n+1,0);
    queue<int> q;
    for(auto i:futarok){
        q.push(i);
        visited[i] = true;
    }
    int node;
    while(!q.empty()){
        queue<int> p = q;
        /*while(!p.empty()){
            cout<<p.front()<<"("<<dis[p.front()]<<") ";
            p.pop();
        }
        cout<<'\n';*/
        node =  q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                dis[i] = dis[node] + 1;
                q.push(i);
            }
        }
    }
    vector<int> canNotReach;
    int longestPath = 0;
    for(int i=1; i<=n; i++){
        if(dis[i] > k) canNotReach.push_back(i);
        longestPath = max(longestPath,dis[i]);
    }
    if(longestPath % k != 0) longestPath = longestPath / k + 1;
    else longestPath = longestPath / k;

    for(auto i:canNotReach){
        cout<<i<<" ";
    }
    cout<<'\b'<<'\n';
    cout<<longestPath;
}

int main()
{
    int n,k,m,a;
    cin>>n>>k>>m;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin>>a;
    for(int i=1; i<=a; i++){
        int x;
        cin>>x;
        futarok.push_back(x);
    }
    BFS(n,k);
    return 0;
}
/*
8 2 9
1 2
1 3
2 4
3 4
2 5
4 6
5 6
2 7
7 8
2 1 7
*/