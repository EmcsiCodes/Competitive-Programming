#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[10001];

void BFS(int n){
    vector<bool> visited(n+1,false), res(n+1,true);
    vector<int> kidsNum[10001];
    queue<int> q;
    for(int i=1; i<=n; i++){
        //kidsNum[i] = 0;
        if(adj[i].size() == 1){
            q.push(i);
            visited[i] = true;
        }
    }

    while(!q.empty()){
        while(!q.empty()){
            int node = q.front();
            q.pop();
            int i = adj[node][0];
            if(!visited[i]){
                res[i] = false;
                visited[i] = true;
                q.push(i);
            }
        }
        
    }
}

int main()
{
    int n;
    for(int i=1; i<n; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    return 0;
}