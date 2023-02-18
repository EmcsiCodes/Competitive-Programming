#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> outNull;
vector<int> adj[100001];
stack<int> s;

void SCC(int node,vector<int> &disc,vector<int> &low,vector<bool> &currStack, vector<int> &outDegrees){
    static int time = 1;
    currStack[node] = true;
    disc[node] = time;
    low[node] = time;
    s.push(node);
    time++;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            SCC(i,disc,low,currStack,outDegrees);
            if(low[i] <= low[node]){
                low[node] = low[i];
                outDegrees[node]--;
            } 
        } else if(currStack[i]){
            low[node] = min(low[node],disc[i]);
            outDegrees[node]--;
        }
    }
    if(low[node] == disc[node]){
        int out = 0;
        while(s.top()!=node){
            out += outDegrees[s.top()];
            currStack[s.top()] = false;
            s.pop();
        }
        out += outDegrees[s.top()];
        currStack[s.top()] = false;
        s.pop();
        if(out == 0) {
            outNull.push_back(node);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> disc(n+1,0), low(n+1,0), outDegrees(n+1,0);
    vector<bool> currStack(n+1,false);
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        outDegrees[x]++;
    }
    for(int i=1; i<=n; i++){
        if(disc[i] == 0) {
            SCC(i,disc,low,currStack,outDegrees);
            
        }
    }
    cout<<outNull.size()-1<<'\n';
    cout<<*outNull.rbegin()<<'\n';
    for(int i=0; i<outNull.size()-1; i++){
        cout<<outNull[i]<<" "<<outNull[i+1]<<'\n';
    }
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