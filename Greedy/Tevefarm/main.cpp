#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[100001];
vector<int> teveNum, res;
vector<bool> city(100001,false);

int DFS(int node,vector<bool>&visited){
    visited[node] = true;
    int currSum = 0;
    for(auto i:adj[node]){
        if(!visited[i]){
            currSum += DFS(i,visited);
        }
    }
    if(teveNum[node]>=currSum) city[node] = true;
    return max(currSum,teveNum[node]);
}

void BFS(int start,int n){
    vector<bool> visited(n+1,false);
    queue<int> q;
    if(city[start]) {
        cout<<1<<'\n'<<1;
        return;
    }
    visited[start] = true;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(city[i]) {
                visited[i] = true;
                res.push_back(i);
            }
            else if(!visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    teveNum.push_back(0);
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        teveNum.push_back(x);
    }
    for(int i=2; i<=n; i++){
        int x;
        cin>>x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    vector<bool> visited(n+1,false);
    cout<<DFS(1,visited)<<'\n';
    BFS(1,n);
    cout<<res.size()<<'\n';
    for(auto i:res)cout<<i<<" ";
    return 0;
}
/*
8
5 5 7 1 2 3 2 4
1
1
2
2
2
3
3
*/