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
    int n,start;
    cin>>n>>start;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        adj[i].push_back(x);
        adj[i].push_back(y);
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
        if(inDegree[i] == 0 && i!=start) res.push_back(i);
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<start<<" "<<i<<'\n';
    return 0;
}
/*
11 7
3 4
5 9
4 7
6 7
7 2
1 10
9 10
5 9
10 11
9 11
9 10
*/