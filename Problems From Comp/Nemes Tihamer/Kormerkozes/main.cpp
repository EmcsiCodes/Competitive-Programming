#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;


vector<int> adj[101];
/*
set<int> subg[101];
stack<int> s;
vector<int> nodes;
int comp[101];
int start;
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
            onStack[node] = false;
            s.pop();
        }
        nodes.push_back(node);
        comp[node] = node;
        onStack[node] = false;
        s.pop();
    }
}

void makeSubGraph(int n){
    vector<int> disc(n+1,0), low(n+1,0);
    vector<bool> onStack(n+1,false);
    for(int i=1; i<=n; i++){
        if(disc[i] == 0) SCC(i,disc,low,onStack);
    }
    vector<int> inDegree(n+1,0);
    for(auto i:nodes){
        for(auto j:adj[i]){
            if(comp[i]!=comp[i]) {
                subg[comp[i]].insert(comp[j]);
                inDegree[comp[j]]++;
            }
        }
    }
    for(auto i:nodes) if(inDegree[i] == 0) {
        start = i;
        break;
    }
}
*/

stack<int> s;
vector<int> res;
bool result = false;
vector<bool> visited(101,false);

void backtrack(int node,int n){
    if(!result){
        visited[node] = true;
        s.push(node);
        if(s.size() == n){
            while(!s.empty()){
                res.push_back(s.top());
                s.pop();
            }
            result = true;
            return;
        }
        for(auto i:adj[node]){
            if(!visited[i] && !result) backtrack(i,n);
        }
        s.pop();
        visited[node] = false;
    }
}

int main()
{
    int n,m;
    cin>>n;
    m = n * (n - 1) / 2;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    //makeSubGraph(n); ->smekkerebbik megoldas, nem tudom ha mukodik de still fasza
    int i = 1;
    while(!result){
        backtrack(i,n);
        i++;
    }
    for(auto i:res) cout<<i<<" ";
    return 0;
}