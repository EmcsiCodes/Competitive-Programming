#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
using namespace std;

vector<int> adj[10001];
stack<int> s,res;

void findSCC(int node,vector<int> &disc,vector<int> &low,vector<bool> &onStack){
    static int startNode = node;
    static int time = 1;
    disc[node] = time;
    low[node] = time;
    s.push(node);
    onStack[node] = true;
    time++;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            findSCC(i,disc,low,onStack);
            low[node] = min(low[i],low[node]);
        }
        else if(onStack[i]){
            //found backedge on current component
            low[node] = min(disc[i],low[node]);
        }
    }
    if(low[node] == disc[node]){
        stack<int> garbage = s;
        while(s.top() != node){
            if(s.top() == startNode) res = garbage;
            onStack[s.top()] = false;
            s.pop();
        }
        if(s.top() == startNode) res = garbage;
        onStack[s.top()] = false;
        s.pop();
    }
}

void BFS(int startNode,int n,int t){
    queue<int> q;
    vector<bool> visited(n+1,false);
    visited[startNode] = true;
    vector<int> distance(n+1,0);
    q.push(startNode);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                distance[i] = distance[node] + 1;
            }
        }
    }
    set<int> ans;
    while(!res.empty()){
        if(distance[res.top()] <= t && res.top()!=startNode){
            ans.insert(res.top());
        }
        res.pop();
    }
    if(ans.size() == 0) {
        cout<<0;
        return;
    }
    cout<<ans.size()<<'\n';
    for(auto i:ans) cout<<i<<" ";
}

int main()
{
    int n,m,startNode,t;
    cin>>n>>m>>startNode>>t;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    t++;
    vector<int> disc(n+1,0), low(n+1,0);
    vector<bool> onStack(n+1,false);
    findSCC(startNode,disc,low,onStack);
    BFS(startNode,n,t);
    return 0;
}
/*
10 14 3 2
2 3
1 3
3 4
3 5
1 5
4 6
6 2
6 7
7 9
9 10
5 8
8 10
5 4
5 7
*/