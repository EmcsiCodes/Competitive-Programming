#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,k;
vector<int> adj[100001];
int maxDepth = 0;
int res = 0;
int DFS(int node,vector<bool>&visited,vector<int>&mem,int currLayer){
    visited[node] = true;
    int nextLayer = currLayer;
    for(auto i:adj[node]){
        if(!visited[i]){
            nextLayer = max(DFS(i,visited,mem,currLayer+1), nextLayer);
            mem[node] += mem[i];
        }
    }
    int pow = nextLayer - currLayer + 1;
    int needed = 1;
    while(pow>0){
        needed = needed*2;
        pow--;
    }
    if(mem[node] == needed - 1 && mem[node]>=k && maxDepth < currLayer) {
        res = node;
        maxDepth = currLayer;
    }
    return nextLayer;
}

int main()
{
    cin>>n>>k;
    vector<int> mem(n+1,1);
    vector<bool> visited(n+1,false);
    for(int i=1; i<n; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    int currLayer = 0;
    DFS(1,visited,mem,currLayer);
    cout<<res;
    return 0;
}
/*
19 5
1 2
1 3
2 4
2 5
3 6
3 7
4 8
4 9
5 10
5 11
6 12
6 13
7 14
7 15
10 16
10 17
11 18
11 19
*/