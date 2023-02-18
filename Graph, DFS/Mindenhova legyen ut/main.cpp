#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <unordered_map>
using namespace std;

vector<int> adj[10001], nodes;
unordered_map<int,int> comp;
set<int> subg[10001];
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
        } else if(onStack[i]){
            low[node] = min(low[node],disc[i]);
        }
    }
    if(disc[node] == low[node]){
        while(s.top()!=node){
            comp[s.top()] = node;
            onStack[s.top()] = false;
            s.pop();
        }
        comp[s.top()] = node;
        nodes.push_back(node);
        onStack[s.top()] = false;
        s.pop();
    }
}

void makeSubGraph(int n){
    vector<int> disc(n+1,0), low(n+1,0);
    vector<bool> onStack(n+1,0);
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
    vector<int> inDegree(n+1,0);
    for(auto i:nodes){
        for(auto j:subg[i]){
            inDegree[j]++;
        }
    }
    vector<int> res;
    for(auto i:nodes){
        if(inDegree[i] == 0) res.push_back(i);
    }
    int start = *res.begin();
    cout<<res.size()-1<<'\n'<<start<<'\n';
    for(int i=1; i<res.size(); i++) cout<<start<<" "<<res[i]<<'\n';
    return 0;
}
/*
9 11
1 2
2 3
2 1
3 4
4 5
5 3
6 7
7 6
8 3
8 9
9 8
*/