#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> adj[10001];
stack<int> s;
pair<int,int> res;
void SCC(int node,vector<int>&disc,vector<int>&low,vector<int>&inDegree,vector<int>&outDegree,vector<bool>&onStack){
    static int time = 1;
    disc[node] = time;
    low[node] = time;
    onStack[node] = true;
    s.push(node);
    time++;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            SCC(i,disc,low,inDegree,outDegree,onStack);
            if(low[i] <= low[node]){
                inDegree[i]--;
                outDegree[node]--;
                low[node] = low[i];
            }
        } else if(onStack[i]){
            low[node] = min(low[node],disc[i]);
            inDegree[i]--;
            outDegree[node]--;
        }
    }
    if(disc[node] == low[node]){
        int in = 0;
        int out = 0;
        while(s.top()!=node){
            in += inDegree[s.top()];
            out += outDegree[s.top()];
            onStack[s.top()] = false;
            s.pop();
        }
        in += inDegree[s.top()];
        out += outDegree[s.top()];
        onStack[s.top()] = false;
        s.pop();
        if(out == 0) res.first = node;
        if(in == 0) res.second = node;
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> disc(n+1,0), low(n+1,0), inDegree(n+1,0), outDegree(n+1,0);
    vector<bool> onStack(n+1,0);
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        inDegree[y]++;
        outDegree[x]++;
    }
    for(int i=1; i<=n; i++){
        if(disc[i] == 0) SCC(i,disc,low,inDegree,outDegree,onStack);
    }
    if(res.first == res.second) cout<<0<<" "<<0;
    else cout<<res.first<<" "<<res.second;
    return 0;
}
/*
10 15
2 3
3 6
6 2
3 4
4 2
4 1
1 5
5 10
10 1
1 8
5 7
7 9
9 7
3 7
8 10
*/