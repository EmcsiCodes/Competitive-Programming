#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> adj[5001];
stack<int> s;
vector<int> res;
int inNum = 0;

void SCC(int node,vector<int> &disc,vector<int> &low,vector<int> &inDegree,vector<bool> &onStack){
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
            low[node] = min(low[node],disc[i]);
            inDegree[i]--;
        }
    }
    if(low[node] == disc[node]){
        int in = 0;
        vector<int> p;
        while(s.top()!=node){
            p.push_back(s.top());
            in += inDegree[s.top()];
            onStack[s.top()] = false;
            s.pop();
        }
        p.push_back(s.top());
        in += inDegree[s.top()];
        onStack[s.top()] = false;
        s.pop();
        if(in == 0){
            inNum++;
            res = p;
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> disc(n+1,0), low(n+1,0), inDegree(n+1,0);
    vector<bool> onStack(n+1,false);
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        inDegree[y]++;
    }
    
    for(int i=1; i<=n; i++){
        if(disc[i] == 0){
            SCC(i,disc,low,inDegree,onStack);
        }
    }
    if(inNum > 1){
        cout<<-1;
    } else {
        sort(res.begin(),res.end());
        for(auto i:res) cout<<i<<" ";
    }
    return 0;
}