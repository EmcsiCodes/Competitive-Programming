#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
using namespace std;

/*
Problem Summary:
You are given a directed graph G with N vertices and M edges.
Your task is to find the size of the largest clique in the transitive closure of this graph, denoted as G*.

- The input consists of multiple test cases.
- For each test case, you are given the number of vertices (N) and edges (M) in the graph.
- The edges of the graph are provided as pairs of vertices.
- You need to find the size of the largest clique in the transitive closure of the graph G*.

A clique in a graph is a set of vertices where there is an edge between every pair
of vertices in the set. The transitive closure of a graph contains all the edges
that can be reached by following directed paths, including indirect connections.

Your task is to determine the largest group of vertices in G* such that there is a
directed path between every pair of vertices in this group.

Constraints:
- 3 ≤ N ≤ 10^4
- 3 ≤ M ≤ 10^6

Output:
For each test case, print the test number (starting from 1) followed by a colon and
the size of the largest clique in the transitive closure of the graph.

Example:
Input:
```
4 4
1 2 2 3 3 4 4 1
0
```

Output:
```
1:4
```

Explanation:
In the example, the graph forms a cycle with 4 vertices, so the largest clique
in the transitive closure contains all the vertices, resulting in a size of 4.
*/

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
/*
This C++ program solves the given problem of finding the size of the largest
clique in the transitive closure of a directed graph.

### Approach:

1. **Strongly Connected Components (SCC):**
   The first step is to find the strongly connected components (SCCs) of the given
   directed graph using Kosaraju's Algorithm. SCCs are subgraphs in which every pair
   of vertices is reachable from each other.

2. **Constructing Subgraph:**
   For each SCC, we construct a subgraph where the nodes are the SCCs, and an edge from
   SCC A to SCC B exists if there is an edge from any vertex in SCC A to any vertex in SCC B.

3. **Directed Acyclic Graph (DAG):**
   We convert the subgraph into a directed acyclic graph (DAG) by merging each SCC
   into a single node and removing duplicate edges.

4. **Topological Sorting and Longest Path:**
   Perform a topological sorting on the DAG and find the longest path for each node,
   representing the largest clique in the transitive closure.

5. **Output:**
   The size of the largest clique is the maximum value in the longest paths for each SCC.

### Explanation of the Code:

1. The `SCC` function implements Kosaraju's Algorithm to find SCCs in the graph.

2. The `makeSubGraph` function constructs the subgraph based on SCCs and calculates the in-degree of each SCC.

3. The main function reads the input, constructs the subgraph, calculates the longest paths,
and prints the size of the largest clique for each test case.

This program efficiently computes the largest clique size in the transitive closure of the
given graph by employing the concepts of SCCs and topological sorting.
*/