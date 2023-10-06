#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <unordered_map>
using namespace std;
/*
- **Problem Description**:
  Given a directed graph G=(V, E), the task is to compute the minimum number of new edges needed to be added to the graph so that there is a path between any two vertices.

- **Task**:
  Create a program that calculates the minimum number of new edges needed and outputs the new edges.

- **Input**:
  - The first line of standard input contains the number of vertices in the graph N (1 ≤ N ≤ 10,000) and the number of edges M (1 ≤ M ≤ 100,000).
  - The following M lines each contain a pair of vertices representing an existing edge in the graph.

- **Output**:
  - The program should output the number K of new edges that need to be added.
  - The next K lines should each contain two integers representing the endpoints of a new edge.

- **Example**:
  - **Input**:
    ```
    8 9
    1 6
    1 4
    4 5
    5 4
    2 5
    3 8
    5 7
    7 8
    8 7
    ```
  - **Output**:
    ```
    3
    6 2
    8 3
    3 1
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
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
    if(low[node] == disc[node]){
        while(s.top()!=node){
            comp[s.top()] = node;
            onStack[s.top()] = false;
            s.pop();
        }
        nodes.push_back(node);
        comp[node] = node;
        onStack[node] = false;
        s.pop();
    }
}

void makeSubGraph(int n){
    vector<int> disc(n+1,0),low(n+1,0);
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
    vector<int> inDegree(n+1,0), outDegree(n+1,0);
    for(auto i:nodes){
        for(auto j:subg[i]){
            inDegree[j]++;
            outDegree[i]++;
        }
    }
    vector<int> inNull, outNull;
    for(auto i:nodes){
        if(inDegree[i] == 0) inNull.push_back(i);
        if(outDegree[i] == 0) outNull.push_back(i);
    }
    int minEdge = max(inNull.size(),outNull.size());
    cout<<minEdge<<'\n';
    int i = 0,j = 0;
    while(i<outNull.size() && j<inNull.size()){
        cout<<outNull[i]<<" "<<inNull[j]<<'\n';
        i++;
        j++;
    }
    while(i<outNull.size()){
        cout<<outNull[i]<<" "<<inNull[j-1]<<'\n';
        i++;
    }
    while(j<inNull.size()){
        cout<<outNull[i-1]<<" "<<inNull[j]<<'\n';
        j++;
    }
    return 0;
}
/*
The given C++ program solves the problem of finding the minimum number of new edges needed to ensure that there is a path between any two vertices in a directed graph. It also outputs the new edges that need to be added.

Here's a step-by-step breakdown of the program:

### Program Approach:

1. **Input Reading:**
   - Read the number of vertices (N) and the number of edges (M) from the standard input.
   - Read M lines, each containing a pair of vertices representing an existing edge in the graph.

2. **Finding Strongly Connected Components (SCCs):**
   - Use Tarjan's algorithm to find the strongly connected components (SCCs) in the given directed graph.
   - Create a subgraph of SCCs, where each SCC is represented by a single node.

3. **Calculating In-Degrees and Out-Degrees:**
   - Calculate the in-degree and out-degree of each SCC in the subgraph.

4. **Identifying In-Degree and Out-Degree Null SCCs:**
   - Identify SCCs with in-degree zero (inNull) and SCCs with out-degree zero (outNull).

5. **Output Generation:**
   - Calculate the minimum number of new edges needed to connect all SCCs (minEdge), which is the maximum of the sizes of inNull and outNull.
   - Output the number of new edges needed (minEdge).
   - Output the new edges that need to be added. For each new edge, connect a node from outNull to a node in inNull.

### Output:
The program outputs the number of new edges (K) and K lines, each containing two integers representing the endpoints of a new edge.

The program aims to minimize the number of new edges needed to ensure there is a path between any two vertices in the directed graph.

*/