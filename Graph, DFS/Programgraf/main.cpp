#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> adj[10001];
stack<int> s;
int cycleNum = 0;
int splits = 0;
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
        } else if(onStack[i]){
            low[node] = min(low[node],disc[i]);
        }
    }
    if(low[node] == disc[node]){
        if(s.top()!=node) cycleNum++;
        else if(adj[node].size()>1) splits++;
        int db=0;
        while(s.top()!=node){
            //cout<<s.top()<<" ";
            onStack[s.top()] = false;
            s.pop();
        }
        //cout<<s.top()<<'\n';
        onStack[s.top()] = false;
        s.pop();
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> disc(n+1,0), low(n+1,0);
    vector<bool> onStack(n+1,false);
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    SCC(1,disc,low,onStack);
    cout<<cycleNum<<'\n';
    cout<<splits;
    return 0;
}
/*
16 20
3 16
1 2
1 3
2 4
4 5
5 2
5 7
7 8
8 5
7 9
9 10
9 11
10 12
10 13
11 14
11 15
12 16
13 16
14 16
15 16
*/