#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[10001];

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> degree(n+1,0);
    for(int i=1; i<n; i++){
        int x,y;
        cin>>x>>y;
        adj[y].push_back(x);
        degree[x]++;
    }
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(degree[i] == 0){
            q.push(i);
        }
    }
    vector<int> dis(n+1,0);
    int res = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(dis[node] == k){
            dis[node] = 0;
            res++;
        }
        for(auto i:adj[node]){
            degree[i]--;
            dis[i] = max(dis[i], dis[node] + 1);
            if(degree[i] == 0){
                q.push(i);
            }
        }
    }
    cout<<res;
    return 0;
}
/*
12 2
1 2
2 3
2 4
4 5
4 7
7 6
7 8
1 9
9 10
10 11
7 12
*/