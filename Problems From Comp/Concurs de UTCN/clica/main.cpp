#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
using namespace std;

void SCC(int node,vector<int> &disc,vector<int>&low, vector<bool>&onStack,
vector<int>adj[], stack<int>&s, int comp[], vector<int> &nodes,vector<int>&compNum){
    static int time = 1;
    disc[node] = time;
    low[node] = time;
    onStack[node] = true;
    s.push(node);
    time++;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            SCC(i,disc,low,onStack,adj,s,comp,nodes,compNum);
            low[node] = min(low[i],low[node]);
        } else if(onStack[i]) low[node] = min(low[node],disc[i]);
    }
    if(disc[node] == low[node]){
        int num = 0;
        while(s.top()!=node){
            comp[s.top()] = node;
            onStack[s.top()] = false;
            s.pop();
            num++;
        }
        comp[node] = node;
        onStack[node] = false;
        num++;
        nodes.push_back(node);
        compNum[node] = num;
        s.pop();
    }
}

void makeSubGraph(int n,vector<int> adj[],vector<int> &nodes,set<int> subg[],vector<int>&compNum){
    vector<int> disc(n+1,0), low(n+1,0);
    vector<bool> onStack(n+1,false);
    int comp[10001];
    stack<int> s;

    for(int i=1; i<=n; i++){
        if(disc[i] == 0) SCC(i,disc,low,onStack,adj,s,comp,nodes,compNum);
    }
    for(int i=1; i<=n; i++){
        for(auto j:adj[i]){
            if(comp[i]!=comp[j]) subg[comp[i]].insert(comp[j]);
        }
    }
}

int main()
{
    ifstream in("clica.in");
    ofstream out("clica.out");
    int n;
    int testNum = 1;
    while(in>>n && n!=0){
        int m;
        in>>m;
        vector<int> adj[10001];
        for(int i=1; i<=m; i++){
            int x, y;
            in>>x>>y;
            adj[x].push_back(y);
        }    
        vector<int> nodes;
        set<int> subg[10001];
        vector<int> compNum(n+1,0);
        makeSubGraph(n,adj,nodes,subg,compNum);
        vector<int> inDegree(n+1,0);
        for(auto i:nodes){
            for(auto j:subg[i]) inDegree[j]++;
        }
        queue<int> q;
        vector<int> res(n+1,0);
        int maxx = 0;
        for(auto i:nodes) {
            maxx = max(maxx, compNum[i]);
            if(inDegree[i] == 0) {
                res[i] = compNum[i];
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto i:subg[node]){
                inDegree[i]--;
                res[i] = max(res[i],res[node] + compNum[i]);
                if(inDegree[i] == 0) {
                    q.push(i);
                    maxx = max(maxx, res[i]);
                }
            }
        }
        out<<testNum<<':'<<maxx<<'\n';
        testNum++;
    }
    return 0;
}