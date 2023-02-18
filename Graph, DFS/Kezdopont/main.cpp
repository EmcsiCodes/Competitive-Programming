#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> adj[501],res;
stack<int> s;

void SCC(int node, vector<int> &disc,vector<int>&low,vector<int>&inDegree,vector<bool>&onStack){
    static int time = 1;
    disc[node] = time;
    low[node] = time;
    onStack[node] = true;
    s.push(node);
    time++;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            SCC(i,disc,low,inDegree,onStack);
            if(low[i] <= low[node]){
                low[node] = low[i];
                inDegree[i]--;
            }
        } else if(onStack[i]){
            low[node] = min(low[node], disc[i]);
            inDegree[i]--;
        }
    }
    if(low[node] == disc[node]){
        int in = 0;
        while(s.top()!=node){
            in += inDegree[s.top()];
            onStack[s.top()] = false;
            s.pop();
        }
        in += inDegree[s.top()];
        onStack[s.top()] = false;
        s.pop();
        if(in == 0){
            res.push_back(node);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> disc(n+1,0),low(n+1,0),inDegree(n+1,0);
    vector<bool> onStack(n+1,false);
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        inDegree[y]++;
    }
    for(int i=1; i<=n; i++){
        if(disc[i] == 0) SCC(i,disc,low,inDegree,onStack);
    }
    cout<<*res.begin()<<'\n';
    cout<<res.size() - 1<<'\n';
    for(int i=0; i<res.size() - 1; i++){
        cout<<res[i]<<" "<<res[i+1]<<'\n';
    }
    return 0;
}
/*
11 12
3 2
4 3
1 3
2 6
2 4
6 10
6 11
2 11
5 7
5 8
5 4
7 8
*/