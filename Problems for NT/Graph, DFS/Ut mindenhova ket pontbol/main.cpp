#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <set>

using namespace std;
/*
- **Problem Description**:
  Given a directed graph G = (V, E), you are asked to find two points A and B in the graph such that for any point q in V, there is a path from either A to q or from B to q.

- **Task**:
  Write a program to determine two points A and B in the graph G satisfying the condition that for any point q, there is a path either from A to q or from B to q.

- **Input**:
  - The first line of standard input contains the number of nodes in the graph N (1 ≤ N ≤ 10,000) and the number of edges in the graph M (1 ≤ M ≤ 200,000).
  - The following M lines each contain two integers u and v, representing an edge from node u to node v in the graph (1 ≤ u, v ≤ N).

- **Output**:
  - The output should consist of a single line with two integers A and B separated by a space, representing the points satisfying the given condition.

- **Example**:
  - **Input**:
    ```
    9 12
    1 2
    2 3
    2 1
    3 4
    4 5
    5 3
    6 7
    7 6
    8 3
    8 9
    9 8
    5 7
    ```
  - **Output**:
    ```
    2 8
    ```

- **Constraints**:
  - The computation should be completed within 0.1 seconds.
  - The memory usage should not exceed 32 MB.
*/
set<int> subg[10001];
vector<int> nodes;
unordered_map<int,int> comp;
vector<int> adj[10001];
stack<int> s;
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
            low[node] = min(low[node],low[i]);
        } else if(onStack[i]) low[node] = min(low[node],disc[i]);
    }
    if(disc[node] == low[node]){
        while(s.top()!=node){
            comp[s.top()] = node;
            onStack[s.top()] = false;
            s.pop();
        }
        nodes.push_back(node);
        comp[s.top()] = node;
        onStack[s.top()] = false;
        s.pop();
    }
}

void makeSubGraph(int n){
    vector<int> disc(n+1,0), low(n+1,0);
    vector<bool> onStack(n+1,false);
    for(int i=1; i<=n; i++){
        if(disc[i] == 0) SCC(i,disc,low,onStack);
    }
    for(int i=1; i<=n; i++){
        for(auto j:adj[i]){
            if(comp[i]!=comp[j]) subg[comp[i]].insert(comp[j]);
        }
    }
}

void solve(int n){
    vector<int> inDegree(n+1,0);
    for(auto i:nodes){
        for(auto j:subg[i]){
            inDegree[j]++;
        }
    }
    for(auto i:nodes){
        if(inDegree[i] == 0)  cout<<i<<" ";
    }
    cout<<'\b';
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    makeSubGraph(n);
    solve(n);
    return 0;
}
/*
The given program aims to determine two points A and B in a directed graph such that for any point q, there is a path either from A to q or from B to q. The program uses Tarjan's algorithm to find strongly connected components (SCCs) and constructs a subgraph based on these components.

Here's a step-by-step explanation of how the program works:

1. **Input Reading:**
   - Read the number of nodes (N) and the number of edges (M) from the standard input.
   - Read the M lines describing the directed edges between nodes.

2. **Strongly Connected Components (SCCs):**
   - Implement Tarjan's algorithm to find SCCs in the directed graph.

3. **Create a Subgraph:**
   - Create a subgraph using the SCCs obtained, where each SCC is considered as a node in the subgraph.

4. **Identify Points A and B:**
   - For each SCC, find the nodes that have no incoming edges from other SCCs, i.e., nodes with in-degree 0 in the subgraph. These nodes correspond to points A and B.

5. **Output:**
   - Output the points A and B separated by a space.

### Output:
The program outputs two integers, A and B, representing the points satisfying the given condition.

The program seems to be working correctly to find the points A and B as required. If you have any specific questions or concerns, feel free to ask!
*/