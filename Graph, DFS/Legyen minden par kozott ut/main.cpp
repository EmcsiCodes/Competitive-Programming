#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <unordered_map>
using namespace std;

set<int> subg[10001];
vector<int> nodes;
unordered_map<int,int> comp;
vector<int> adj[10001];
stack<int> s;
void SCC(int node,vector<int>&disc,vector<int>&low,vector<bool>&onStack){
    static int time = 1;
    disc[node] = time;
    low[node] = time;
    onStack[node] = true;
    s.push(node);
    time++;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            SCC(i,disc,low,onStack);
            low[node] = min(low[node],low[i]);
        } else if(onStack[i]) low[node] = min(low[node],disc[i]);
    }
    if(low[node] == disc[node]){
        while(s.top()!=node){
            comp[s.top()] = node;
            onStack[s.top()] = false;
            s.pop();
        }
        nodes.push_back(node);
        comp[node] = node;
        onStack[node] = false;
        s.pop();
    }
}

void makeSubGraph(int n){
    vector<int> disc(n+1,0),low(n+1,0);
    vector<bool> onStack(n+1,false);
    for(int i=1; i<=n; i++){
        if(disc[i] == 0) SCC(i,disc,low,onStack);
    }
    for(int i=1; i<=n; i++){
        for(auto j:adj[i]){
            if(comp[i]!=comp[j]) subg[comp[i]].insert(comp[j]);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    makeSubGraph(n);
    vector<int> inDegree(n+1,0), outDegree(n+1,0);
    for(auto i:nodes){
        for(auto j:subg[i]){
            inDegree[j]++;
            outDegree[i]++;
        }
    }
    vector<int> inNull, outNull;
    for(auto i:nodes){
        if(inDegree[i] == 0) inNull.push_back(i);
        if(outDegree[i] == 0) outNull.push_back(i);
    }
    int minEdge = max(inNull.size(),outNull.size());
    cout<<minEdge<<'\n';
    int i = 0,j = 0;
    while(i<outNull.size() && j<inNull.size()){
        cout<<outNull[i]<<" "<<inNull[j]<<'\n';
        i++;
        j++;
    }
    while(i<outNull.size()){
        cout<<outNull[i]<<" "<<inNull[j-1]<<'\n';
        i++;
    }
    while(j<inNull.size()){
        cout<<outNull[i-1]<<" "<<inNull[j]<<'\n';
        j++;
    }
    return 0;
}
/*
8 9
1 6
1 4
4 5
5 4
2 5
3 8
5 7
7 8
8 7
*/