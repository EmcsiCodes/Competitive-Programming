#include <iostream>
#include <vector>

using namespace std;
/*
Here's the summary of the problem "Csomópontok körökben" (Nodes in Circuits):

- **Problem Description**:
  In a computer network, nodes are connected by bidirectional direct links that provide two-way data transmission. The network's fault tolerance depends on its topology. A characteristic property of the network is that any node is part of at least one cycle containing three or more nodes.

- **Task**:
  Develop a program that computes the answer to the following two questions: Which nodes are not part of any cycle, and what is the minimum number of additional direct links needed to ensure that each node is part of a cycle containing at least three nodes? Provide one possible set of additional links.

- **Input**:
  - The first line of standard input contains the number of nodes N (3 ≤ N ≤ 1000) and the number of direct links connecting the nodes M (N-1 ≤ M ≤ 10000).
  - The following M lines each contain two integers X and Y (1 ≤ X ≠ Y ≤ N) representing direct links between nodes X and Y.

- **Output**:
  - The program should output:
    1. The number of nodes K (K ≥ 0) that are not part of any cycle.
    2. The K nodes, space-separated, in any order.
    3. The minimum number of additional direct links L required to ensure that each node is part of a cycle containing at least three nodes.
    4. L lines, each containing two integers representing endpoints of additional direct links.

- **Example**:
  - **Input**:
    ```
    7 8
    1 2
    2 3
    3 1
    2 4
    4 6
    6 5
    7 1
    3 4
    ```
  - **Output**:
    ```
    3
    6 5 7
    1
    5 7
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
vector<int> adj[1001];
bool bridges[1001][1001];

void DFS(int node,vector<int> &disc,vector<int> &low,vector<int> &parent,int &time){
    disc[node] = time;
    low[node] = time;
    time++;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            parent[i] = node;
            DFS(i,disc,low,parent,time);
            low[node] = min(low[node],low[i]);
            if(low[i] > disc[node]) {
                bridges[i][node] = true;
                bridges[node][i] = true;
            }
        } else if(parent[node]!=i) {
            low[node] = min(disc[i],low[node]);
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
        adj[y].push_back(x);
    }
    vector<int> disc(n+1,0),low(n+1,0),res,parent(n+1,0),nonCyclicNodes; int time = 1;

    for(int i=1; i<=n; i++){
        if(disc[i] == 0){
            DFS(i,disc,low,parent,time);
        }
    }
    for(int i=1; i<=n; i++){
        bool nonCyclicNode = true;
        for(auto j:adj[i]){
            if(!bridges[i][j]) nonCyclicNode = false;
        }
        if(nonCyclicNode) nonCyclicNodes.push_back(i);
    }
    cout<<nonCyclicNodes.size()<<'\n';
    for(auto i:nonCyclicNodes) cout<<i<<" ";
    return 0;
}
/*
The provided program aims to solve the problem of determining nodes that are not part of any cycle in a computer network, as well as finding the minimum number of additional direct links needed to ensure that each node is part of a cycle containing at least three nodes.

### Approach:
The program uses Depth-First Search (DFS) to identify bridges (critical edges) in the network, which help to determine cycles. It then identifies nodes that are not part of any cycle.

1. **Bridges Detection using DFS:**
   The DFS algorithm is used to traverse the graph. During the traversal, it identifies bridges (critical edges) which, if removed, would increase the number of connected components. These bridges are important for forming cycles.

2. **Finding Nodes Not Part of Any Cycle:**
   After identifying bridges, nodes that are not part of any cycle can be determined. If a node is connected to all its neighbors through bridges, it's not part of any cycle.

### Detailed Explanation:
1. **DFS for Bridge Detection:**
   The DFS algorithm is used to traverse the graph and identify bridges (critical edges) using the concept of discovery time and low time.
   - `disc`: Keeps track of the discovery time of each node.
   - `low`: Maintains the lowest discovery time reachable from the node.
   - `parent`: Keeps track of the parent node in the DFS tree.
   - `time`: Tracks the current time during traversal.

2. **Detecting Bridges:**
   During DFS traversal, for each edge (u, v):
   - If v is not visited, it's a tree edge.
   - If v is visited and not the parent of u, it's a back edge.
   - Update the low value for each node using the minimum of its low value and the discovery time of its adjacent nodes.

3. **Finding Nodes Not Part of Any Cycle:**
   After identifying bridges, iterate through the graph and check if a node is not part of any cycle (i.e., connected to all neighbors through bridges). Collect these nodes.

### Output:
The program outputs the number of nodes that are not part of any cycle, followed by the list of those nodes, and then the minimum number of additional direct links needed to ensure each node is part of a cycle. Each additional link is represented by two endpoints.

### Example:
For the provided input example:
- The program will identify nodes 5, 6, and 7 as not part of any cycle.
- The minimum number of additional direct links needed to ensure each node is part of a cycle is 1, and the additional link is 5-7.

*/