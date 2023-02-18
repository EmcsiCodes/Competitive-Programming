#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> adj[10001];
stack<int> s;

void SCC(int node,vector<int> &disc,vector<int> &low,vector<bool> &currStack){
    static int time = 1;
    disc[node] = time;
    low[node] = time;
    currStack[node] = true;
    s.push(node);
    time++;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            SCC(i,disc,low,currStack);
            low[node] = min(low[i],low[node]);
        } else if(currStack[i]){
            low[node] = min(low[node],disc[i]);
        }
    }
    if(low[node] == disc[node]){
        cout<<"SCC: ";
        while(s.top()!=node){
            cout<<s.top()<<" ";
            currStack[s.top()] = false;
            s.pop();
        }
        cout<<s.top()<<'\n';
        currStack[s.top()] = false;
        s.pop();
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> disc(n+1,0), low(n+1,0);
    vector<bool> currStack(n+1,false);
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    for(int i=1; i<=n; i++){
        if(disc[i] == 0) SCC(i,disc,low,currStack);
    }
    return 0;
}
/*
7 10
1 2
2 3
2 1
3 4
3 5
4 6
6 4
5 7
7 6
4 7
*/
/*
5
7 6 4 2 1
*/