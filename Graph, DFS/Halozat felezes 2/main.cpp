#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, treeSize, nodesNeeded;
vector<int> adj[4001];
vector<int> stopAtCuts(4001,false);
struct tree{
    int subTreeSize;
    int firstNode;
    int secondNode;
};

bool comp(tree &a, tree &b){
    if(a.subTreeSize<b.subTreeSize) return true;
    return true;
}
void DFS(int node,int lastNode,vector<bool> &visited,vector<tree> &cuts,vector<int> &temp){
    visited[node] = true;
    for(auto i:adj[node]){
        if(!visited[i] && !stopAtCuts[i]){
            DFS(i,node,visited,cuts,temp);
            temp[node] += temp[i];
            //cout<<node<<"->"<<i<<": "<<temp[node]<<","<<temp[i]<<'\n';
        }
    }
    if(temp[node] > nodesNeeded) cuts.push_back({temp[node], lastNode, node});
    else cuts.push_back({treeSize - temp[node], node, lastNode});
}

int minimumCut(int start,int num,int n){    
    vector<bool> visited(n+1,false);
    vector<tree> cuts;
    vector<int> temp(n+1,1); 
    DFS(start,0,visited,cuts,temp);
    cuts.pop_back();
    sort(cuts.begin(),cuts.end());
    int pos = upper_bound(cuts.begin(),cuts.end(), nodesNeeded) - cuts.begin() + 1;
    nodesNeeded -= cuts[pos].subTreeSize;
    stopAtCuts[cuts[pos].secondNode] = true;
    start = cuts[pos].firstNode;
    if(nodesNeeded <= 0) return num;
    else minimumCut(start,num+1,n);
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
    treeSize = n;
    nodesNeeded = n / 2;
    cout<<minimumCut(1,1,n);
    return 0;
}
/*
12
1 2
2 3
4 1
4 5
7 1
7 12
7 11
7 9
7 6
6 8
6 10
*/