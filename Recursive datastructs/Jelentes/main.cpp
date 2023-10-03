#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[10001];

void BFS(int start,int n){
    vector<int> dis(n+1,0);
    vector<bool> visited(n+1,false);
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                dis[i] = dis[node] + 1;
            }
        }
    }
    int maxDis = 0;
    int maxDisI = 0;
    for(int i=1; i<=n; i++){
        if(dis[i] > maxDis){
            maxDis = dis[i];
            maxDisI = i;
        }
    }
    cout<<maxDis<<'\n'<<maxDisI;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        int x;
        while(cin>>x && x!=0){
            adj[i].push_back(x);
            adj[x].push_back(i);
        }
    }
    BFS(1,n);
    return 0;
}
/*
9
3 2 0
8 0
4 5 7 0
0
0
0
6 0
9 0
0
*/