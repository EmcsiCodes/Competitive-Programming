#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> adj[10001];
stack<int> s;
vector<int> res;
void findSCCs(int node,vector<int> &disc,vector<int> &low,vector<bool> &currStack,vector<int> &outDegree){
    static int time = 1;
    currStack[node] = true;
    disc[node] = time;
    low[node] = time;
    s.push(node);
    time++;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            findSCCs(i,disc,low,currStack,outDegree);
            if(low[i] <= low[node]){
                low[node] = low[i];
                outDegree[node]--;
            }
        } else if(currStack[i]){
            low[node] = min(low[node],disc[i]);
            outDegree[node]--;
        }
    }
    if(low[node] == disc[node]){
        int totalOut = 0;
        while(s.top()!=node){
            totalOut += outDegree[s.top()];
            currStack[s.top()] = false;
            s.pop();
        }
        totalOut += outDegree[s.top()];
        currStack[s.top()] = false;
        s.pop();
        if(totalOut == 0){
            res.push_back(node);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> disc(n+1,0), low(n+1,0), outDegree(n+1,0);
    vector<bool> currStack(n+1,false);
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        outDegree[x]++;
    }
    for(int i=1; i<=n; i++){
        if(disc[i] == 0) findSCCs(i,disc,low,currStack,outDegree);
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
9 12
1 2
2 3
2 1
1 6
3 4
4 5
5 3
6 7
7 6
8 3
8 9
9 8
*/