#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <set>
using namespace std;

set<int> subg[10001];
vector< pair<int,int> > nodes;
unordered_map<int,int> comp;
vector<int> adj[10001];
stack<int> s;
void SCC(int node,vector<int> &disc,vector<int> &low,vector<bool> &onStack){
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
    if(disc[node] == low[node]){
        int num = 0;
        while(s.top()!=node){
            num++;
            comp[s.top()] = node;
            onStack[s.top()] = false;
            s.pop();
        }
        num++;
        nodes.push_back({node,num});
        comp[node] = node;
        onStack[node] = false;
        s.pop();
    }
}

void makeSubGraph(int n){
    vector<int> disc(n+1,0),low(n+1,0);
    vector<bool> onStack(n+1,false);
    for(int i=1; i<=n; i++){
        if(disc[i] == 0){
            SCC(i,disc,low,onStack);
        }
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
    vector<int> outDegree(n+1,0);
    for(auto i:nodes){
        for(auto j:subg[i.first]){
            outDegree[i.first]++;
        }
    }
    int minContact = 10000000;
    int minContactInd = 0;
    for(auto i:nodes){
        if(outDegree[i.first] == 0 && i.second < minContact){
            minContact = i.second;
            minContactInd = i.first;
        }
    }
    cout<<minContact - 1<<" "<<minContactInd;
    return 0;
}
/*
6 8
1 2
2 3
3 2
1 4
2 5
4 5
5 6
6 5
*/