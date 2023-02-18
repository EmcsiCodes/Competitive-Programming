#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> adj[100001],res;
stack<int> s;
void SCC(int node,vector<int> &disc,vector<int> &low,vector<bool> &currStack,vector<int> &parent){
    static int time = 1;
    disc[node] = time;
    low[node] = time;
    currStack[node] = true;
    s.push(node);
    time++;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            parent[i] = node;
            SCC(i,disc,low,currStack,parent);
            low[node] = min(low[node],low[i]);
        } else if(currStack[i]){
            low[node] = min(low[node],disc[i]);
        }
    }
    if(low[node] == disc[node]){
        if(parent[node] == 0) res.push_back(node);
        while(s.top()!=node){
            currStack[s.top()] = false;
            s.pop();
        }
        currStack[s.top()] = false;
        s.pop();
    }
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> disc(n+1,0), low(n+1,0), parent(n+1,0), startNodes;
    vector<bool> currStack(n+1,false);
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        if(x == k) startNodes.push_back(y);
        else adj[x].push_back(y);
    }
    for(auto i:startNodes){
        if(disc[i] == 0) SCC(i,disc,low,currStack,parent);
    }
    int mainNode = *res.begin();
    cout<<mainNode<<" "<<res.size()-1<<'\n';
    for(auto i:res) {
        if(i!=mainNode) cout<<mainNode<<" "<<i<<'\n';
    }
    return 0;
}
/*
10 14 3
3 4
3 1
3 5
4 2
2 8
8 9
9 2
8 4
1 6
5 7
7 10
7 6
10 5
6 10
*/