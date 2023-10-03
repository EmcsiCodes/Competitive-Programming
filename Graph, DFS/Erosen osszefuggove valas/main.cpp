#include <iostream>
#include <vector>
#include <stack>

using namespace std;
//Make all the graph strongly connected with one new edge
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
Input Reading:

Read the number of nodes n and edges m.
Initialize vectors to keep track of discovery time, low value, in-degree, out-degree, and whether a node is on the stack.
Graph Construction and Degree Calculation:

Read the edges from the input and construct the directed graph.
Calculate the in-degree and out-degree of each node.
Strongly Connected Component (SCC) Algorithm - Kosaraju's Algorithm:

Iterate through all nodes.
For each unvisited node:
Call the SCC function to find strongly connected components.
SCC Function (Kosaraju's Algorithm):

Use Kosaraju's Algorithm to find strongly connected components.
Traverse the graph in a depth-first search manner, assigning discovery times and low values to nodes.
Keep track of nodes in the current SCC using a stack.
When identifying a strongly connected component:
Calculate in-degree and out-degree sums for the component.
Update res.first if the in-degree sum is zero.
Update res.second if the out-degree sum is zero.
Output:

Print the results, i.e., the nodes corresponding to the start and end points of the additional edge required to make the graph strongly connected.
This algorithm employs Kosaraju's Algorithm to find strongly connected components in a directed graph and determine the nodes necessary to make the entire graph strongly connected by adding one new edge.
*/