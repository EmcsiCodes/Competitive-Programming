#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <set>
using namespace std;

vector<int> nodes;
unordered_map<int,int> comp;
set<int> subg[4001];
vector<int> adj[4001];
stack<int> s;
void SCC(int node,vector<int>&disc,vector<int>&low,vector<bool>&onStack){
    static int time = 1;
    disc[node] = time;
    low[node] = time;
    onStack[node] = true;
    s.push(node);
    time++;
    for(auto i:adj[node]){
        if(disc[i]==0){
            SCC(i,disc,low,onStack);
            low[node] = min(low[node],low[i]);
        } else if(onStack[i]) low[node] = min(low[node],disc[i]);
    }
    if(disc[node] == low[node]){
        while(s.top()!=node){
            comp[s.top()] = node;
            onStack[s.top()] = false;
            s.pop();
        }
        nodes.push_back(node);
        comp[s.top()] = node;
        onStack[s.top()] = false;
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

void solve(int n){
    vector<int> inDegree(n+1,0), outDegree(n+1,0);
    for(auto i:nodes){
        for(auto j:subg[i]){
            inDegree[j]++;
            outDegree[i]++;
        }
    }
    int start,end;
    for(auto i:nodes){
        if(outDegree[i] == 0) start = i;
        if(inDegree[i] == 0) end = i;
    }
    cout<<start<<" "<<end;
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
    solve(n);
    return 0;
}
/*
9 12
5 6
6 5
2 1
1 3
3 2
1 4
4 2
3 7
7 8
8 9
9 7
6 2
*/