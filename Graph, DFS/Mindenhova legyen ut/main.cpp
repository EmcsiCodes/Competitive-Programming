#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <unordered_map>
using namespace std;
/*
- **Problem Description**:
  Given a directed graph, calculate the minimum number of new edges needed in the graph to ensure that there exists a vertex r such that there is a path from r to every other vertex.

- **Task**:
  Create a program that calculates the minimum number of new edges and the vertex r that achieves the above condition.

- **Input**:
  - The first line of standard input contains the number of nodes N (1 ≤ N ≤ 10,000) and the number of edges M (1 ≤ M ≤ 200,000).
  - The following M lines each contain two endpoints of an edge (u, v), representing a directed edge from u to v.

- **Output**:
  - The program should output the smallest number K, which represents the minimum number of new edges required.
  - The next line should contain r, representing the vertex from which there should be paths to all other vertices.
  - The following K lines should each contain the two endpoints of a new edge to be added.

- **Example**:
  - **Input**:
    ```
    9 11
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
    ```
  - **Output**:
    ```
    2
    8
    8 1
    1 6
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
vector<int> adj[10001], nodes;
unordered_map<int,int> comp;
set<int> subg[10001];
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
        } else if(onStack[i]){
            low[node] = min(low[node],disc[i]);
        }
    }
    if(disc[node] == low[node]){
        while(s.top()!=node){
            comp[s.top()] = node;
            onStack[s.top()] = false;
            s.pop();
        }
        comp[s.top()] = node;
        nodes.push_back(node);
        onStack[s.top()] = false;
        s.pop();
    }
}

void makeSubGraph(int n){
    vector<int> disc(n+1,0), low(n+1,0);
    vector<bool> onStack(n+1,0);
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
    vector<int> inDegree(n+1,0);
    for(auto i:nodes){
        for(auto j:subg[i]){
            inDegree[j]++;
        }
    }
    vector<int> res;
    for(auto i:nodes){
        if(inDegree[i] == 0) res.push_back(i);
    }
    int start = *res.begin();
    cout<<res.size()-1<<'\n'<<start<<'\n';
    for(int i=1; i<res.size(); i++) cout<<start<<" "<<res[i]<<'\n';
    return 0;
}
/*
A program provided is designed to find the minimum number of new edges needed in a directed graph to ensure that there exists a set of vertices from which all other vertices are reachable.

Here's a step-by-step explanation of how the program works:

### Program Approach:

1. **Input Reading:**
   - Read the number of nodes (N) and the number of edges (M) from the standard input.
   - Read M lines, each containing two integers, representing a directed edge from u to v.

2. **Strongly Connected Components (SCC):**
   - Use the Kosaraju's algorithm to find the strongly connected components in the graph.
   - Store the components in a data structure `comp`, which maps each node to its component.

3. **Creating a Subgraph:**
   - Create a subgraph `subg` based on the strongly connected components.
   - For each node in the original graph, add an edge to the subgraph if it connects to a different component.

4. **Finding Potential Starting Points:**
   - Calculate the in-degrees of the nodes in the subgraph.
   - Identify nodes in the subgraph with an in-degree of 0. These nodes can be potential starting points to reach other components.

5. **Output:**
   - Select one of the potential starting points as the primary starting point (e.g., the first one).
   - Output the number of potential starting points minus one (the number of new edges needed).
   - Output the primary starting point.
   - Output new edges connecting the primary starting point to all other potential starting points.

### Output:
The program outputs the minimum number of new edges needed, the primary starting point, and the new edges connecting the primary starting point to all other potential starting points. This ensures that there exists a set of vertices from which all other vertices are reachable.

*/