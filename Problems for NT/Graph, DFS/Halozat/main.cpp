#include <iostream>
#include <vector>

using namespace std;
/*
Here's the summary of the problem "Hálózat" (Network):

- **Problem Description**:
  A computer network is built from nodes and directed edges connecting certain pairs of nodes, allowing one-way data transmission. Given node A, data can be transmitted to another node B if there exists a sequence of nodes A=p1, p2, …, pk=B such that for every i (i=1,…,k-1), there is a direct edge from pi to pi+1.

- **Task**:
  Create a program that determines the nodes Q where data can be transmitted from a given node K, but from Q, data cannot be transmitted to K.

- **Input**:
  - The first line of standard input contains the number of nodes N (2 ≤ N ≤ 20,000), the number of direct edges M (1 ≤ M ≤ 200,000), and the designated node K (1 ≤ K ≤ N).
  - The following M lines each contain two integers U and V (1 ≤ U ≠ V ≤ N) representing a direct edge from U to V.

- **Output**:
  - The program should output the number of nodes Q where data can be transmitted from node K but not to K. The second line should contain these nodes in any order, separated by a space.

- **Example**:
  - **Input**:
    ```
    10 15 5
    4 5
    2 4
    4 1
    5 2
    5 6
    6 5
    6 2
    6 7
    1 3
    3 9
    1 9
    7 8
    8 9
    9 10
    8 10
    ```
  - **Output**:
    ```
    6
    1 7 3 8 9 10
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
vector<int> adj[20001];

void DFS(int node,int n,vector<bool> &visited,vector<bool> &valid){
    visited[node] = true;
    for(auto i:adj[node]){
        if(!visited[i]){
            DFS(i,n,visited,valid);
            if(!valid[i]) valid[node] = false;
        } else if(!valid[i]) valid[node] = false;
    }
}

int main()
{
    int n,m,startNode;
    cin>>n>>m>>startNode;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    vector<int> res;
    vector<bool> visited(n+1,false),valid(n+1,true);
    valid[startNode] = false;
    DFS(startNode,n,visited,valid);

    for(int i=1; i<=n; i++){
        if(valid[i] && visited[i]) res.push_back(i);
    }
    cout<<res.size()<<'\n';
    for(auto i:res)cout<<i<<" ";
    return 0;
}
/*
Certainly! Let's delve into a more detailed explanation of the approach for the "Network" problem.

### Approach:

1. **Input Reading:**
   - Read the number of nodes \( N \), the number of edges \( M \), and the designated node \( K \) from the input.
   - Create an adjacency list to represent the directed edges in the network.

2. **Graph Representation:**
   - Build a directed graph using the provided edges. Each edge \( (U, V) \) indicates a one-way path from node \( U \) to node \( V \).

3. **Depth-First Search (DFS):**
   - Perform a DFS traversal starting from the designated node \( K \). The objective is to explore the nodes that can be reached from node \( K \).
   - Initialize a boolean array `visited` to keep track of visited nodes during the DFS traversal.
   - Initialize a boolean array `valid` to determine if data can be transmitted from a node \( K \) to the current node during the DFS traversal.

4. **DFS Traversal:**
   - Start the DFS traversal from the designated node \( K \).
   - For each node encountered during the DFS:
     - Mark the current node as visited.
     - If the current node was reached through a valid path (i.e., from a node where data can be transmitted to \( K \)), mark it as valid.
     - Recur for unvisited neighbors.

5. **Identify Valid Nodes:**
   - After the DFS traversal, we have identified the nodes from which data can be transmitted from \( K \) (valid nodes), but data cannot be transmitted back to \( K \).

6. **Output:**
   - Print the count of valid nodes.
   - Print the valid nodes (node numbers) in any order, separated by a space.

### Output:
The program outputs the number of nodes from which data can be transmitted from node \( K \) but not back to \( K \), along with the list of these nodes.

### Example:
For the provided input example:
- The program outputs "6" as there are 6 nodes from which data can be transmitted from node 5 but not back to node 5.
- The nodes satisfying this condition are "1 7 3 8 9 10".
*/