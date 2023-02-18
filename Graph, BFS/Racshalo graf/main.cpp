#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[4001];

pair<int,int> BFS(int startNode, int n){
    vector<bool> visited(n+1,false);
    vector<int> dis(n+1, 0);
    queue<int> q;
    q.push(startNode);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                dis[i] = dis[node] + 1;
                q.push(i);
            }
        }
    }
    int maxDis = 0;
    int maxDisInd = 0;
    for(int i=1; i<=n; i++){
        if(dis[i] > maxDis){
            maxDis = dis[i];
            maxDisInd = i;
        }
    }
    return {maxDis,maxDisInd};
}

void solve(int n,int k){
    for(int i=1; i<=k; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        pair<int,int> firstTrav = BFS(1,n);
        pair<int,int> secTrav = BFS(firstTrav.second,n);
        cout<<secTrav.first<<'\n';
    }
    cout<<'\b';
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int nodeNum = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(j<m){
                adj[nodeNum].push_back(nodeNum + 1);
            }
            if(i<n){
                adj[nodeNum].push_back(nodeNum + m);
            }
            if(j>1){
                adj[nodeNum].push_back(nodeNum - 1);
            }
            if(i>1){
                adj[nodeNum].push_back(nodeNum - m);
            }
            nodeNum++;
        }
    }
    solve(nodeNum,k);
    return 0;
}
/*
3 4 4
1 6
7 10
2 12
4 9
*/