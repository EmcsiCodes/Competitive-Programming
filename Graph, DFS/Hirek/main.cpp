#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;

vector<int> nodes;
set<int> subg[10001];
vector<int> adj[10001];
stack<int> s;
map<int, pair<int,int> > comp;

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
            if(low[i] <= low[node]){
                low[node] = low[i];
            }
        } else if(onStack[i]){
            low[node] = min(low[node],disc[i]);
        }
    }
    if(disc[node] == low[node]){
        int num = 0;
        while(s.top()!=node){
            num++;
            comp[s.top()].first = node;
            onStack[s.top()] = false;
            s.pop();
        }
        num++;
        comp[s.top()].second = num;
        comp[s.top()].first = node;
        nodes.push_back(node);
        onStack[s.top()] = false;
        s.pop();
    }
}

void makeSubGraphFromSCC(int n,vector<int> disc,vector<int> low,vector<bool> onStack,vector<int> &sum){
    for(int i=1; i<=n; i++){
        if(disc[i] == 0) SCC(i,disc,low,onStack);
    }
    for(int i=1; i<=n; i++){
        for(auto j:adj[i]){
            if(comp[i].first!=comp[j].first) subg[comp[i].first].insert(comp[j].first);
        }
    }
    for(auto i:nodes){
        sum[i] = comp[i].second;
    }    
}

void longestSubPath(int node,vector<bool>&visited,vector<int>&sum){
    visited[node] = true;
    for(auto i:subg[node]){
        if(!visited[i]){
            longestSubPath(i,visited,sum);
            sum[node] += sum[i];
        } else sum[node] += sum[i];
    }
}

void checkTakenPath(int node, vector<bool>&secVisited,vector<bool>&taken){
    secVisited[node] = true;
    taken[node] = true;
    for(auto i:subg[node]){
        if(!secVisited[i]){
            checkTakenPath(i,secVisited,taken);
        }
    }
}

int main()
{
    int n,k;
    cin>>n>>k;    
    vector<int> disc(n+1,0),low(n+1,0),sum(n+1,0);
    vector<bool> onStack(n+1,false), visited(n+1,false);
    for(int i=1; i<=n; i++){
        int x;
        while(cin>>x && x!=0){
            adj[i].push_back(x);
        }
    }
    makeSubGraphFromSCC(n,disc,low,onStack,sum);
    for(auto i:nodes){
        if(!visited[i]) longestSubPath(i,visited,sum);
    }
    int maxSum = 0;
    int maxSumIndex = 0;
    for(auto i:nodes){
        if(sum[i] > maxSum){
            maxSum = sum[i];
            maxSumIndex = i;
        }
    }
    if(k==1){
        cout<<maxSum<<'\n'<<maxSumIndex;
    } else {
        vector<bool> secVisited(n+1,false),taken(n+1,false);
        vector<int> secSum(n+1,0);
        checkTakenPath(maxSumIndex,secVisited,taken);
        for(auto i:nodes){
            if(!taken[i]) secSum[i] = comp[i].second;
            //cout<<i<<" "
        }
        for(auto i:nodes){
            if(!secVisited[i]) longestSubPath(i,secVisited,secSum);
        }
        int secMaxSum = 0;
        int secMaxSumIndex = 0;
        for(auto i:nodes){
            if(secSum[i] > secMaxSum){
                secMaxSum = secSum[i];
                secMaxSumIndex = i;
            }
        }
        cout<<maxSum + secMaxSum<<'\n'<<maxSumIndex<<" "<<secMaxSumIndex;
    }
    return 0;
}
/*
12 2
3 0
9 1 0
2 0
5 9 10 0
4 0
7 11 0
8 0
6 0
10 0
11 12 0
0
9 0
*/