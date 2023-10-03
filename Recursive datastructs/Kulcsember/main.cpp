#include <iostream>
#include <vector>

using namespace std;
int n;
vector<int> adj[100001];

int DFS(int node,vector<bool> &visited,vector<int>&res){
    visited[node] = true;
    int curr = 1;
    for(auto i:adj[node]){
        if(!visited[i]){
            int num = DFS(i,visited,res);
            res[node] = max(res[node], num);
            curr += num;
        }
    }
    res[node] = max(res[node], n - curr);
    return curr;
}

int main()
{
    
    cin>>n;
    for(int i=1; i<n; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> res(n+1,0);
    vector<bool> visited(n+1,false);
    int a = DFS(1,visited,res);
    int minSplit = n;
    int minSplitI = 0;
    for(int i=1; i<=n; i++){
        if(minSplit > res[i]){
            minSplit = res[i];
            minSplitI = i;
        }
    }
    cout<<minSplitI<<" "<<minSplit;
    return 0;
}