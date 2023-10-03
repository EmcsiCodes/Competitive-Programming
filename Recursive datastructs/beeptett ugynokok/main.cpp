#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[10001];

int BFS(int start,vector<bool> visited){
    visited[start] = true;
    queue<int> q;
    q.push(start);
    int c = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                c++;
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return c;
}

int main()
{
    int n;
    cin>>n;
    vector<int> inDegree(n+1,0);
    for(int i=1; i<n; i++){
        int x,y;
        cin>>x>>y;
        adj[y].push_back(x);
        inDegree[y]++;
    }
    int start = 0;
    for(int i=1; i<=n; i++){
        if(inDegree[i] == 0) {
            start = i;
            cout<<i<<" ";
           // break;
        }
    }
    vector<bool> visited(n+1,false);
    visited[start] = true;
    if(adj[start].size() == 1) {
        cout<<adj[start][0];
        return 0;
    }
    else if(BFS(adj[start][0],visited) > BFS(adj[start][1],visited)) cout<<adj[start][0];
    else cout<<adj[start][1];
    return 0;
}