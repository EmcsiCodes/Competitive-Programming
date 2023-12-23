#include <iostream>
#include <vector>

using namespace std;
/*
Here's the summary of the problem "Kaktuszgráf" (Cactus Graph):

- **Problem Description**:
  A cactus graph is a graph in which each edge belongs to at most one cycle, or in other words: any two cycles have at most one common vertex. The task is to calculate the length of the longest cycle in a cactus graph.

- **Task**:
  Create a program that calculates the length of the longest cycle in a cactus graph.

- **Input**:
  - The first line of standard input contains the number of vertices in the graph N (3 ≤ N ≤ 1000) and the number of edges M (1 ≤ M ≤ 10,000).
  - The following M lines describe each edge by providing the indices of its endpoints, Ai and Bi (1 ≤ Ai ≠ Bi ≤ N).

- **Output**:
  - The first line of the output should contain the length of the longest cycle.

- **Example**:
  - **Input**:
    ```
    13 15
    1 3
    1 4
    2 3
    3 5
    4 5
    4 12
    12 13
    13 4
    5 7
    7 6
    7 11
    6 8
    11 10
    10 9
    8 9
    ```
  - **Output**:
    ```
    6
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
vector<int> adj[1001];
int maxLength = 0;
void DFS(int node,vector<int> &disc,int time){
    disc[node] = time;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            DFS(i,disc,time+1);
        } else maxLength = max(disc[node] - disc[i] + 1,maxLength);
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
    vector<int> disc(n+1,0);
    for(int i=1; i<=n; i++){
        if(disc[i] == 0) DFS(i,disc,1);
    }
    cout<<maxLength;
    return 0;
}
/*

### Approach:

1. **Graph Representation:**
   - Read the number of vertices \(N\) and the number of edges \(M\).
   - Create an adjacency list to represent the graph. For each edge, store the adjacent vertices.

2. **Cycle Detection Using DFS:**
   - Perform a Depth-First Search (DFS) starting from each vertex to identify cycles.
   - During DFS, maintain an array to mark visited vertices.
   - If you encounter a visited vertex (other than the parent in the DFS tree), you've found a back edge, indicating a cycle.

3. **Cycle Length Calculation:**
   - For each back edge, calculate the length of the cycle using the difference in discovery times.
   - Update a variable to keep track of the maximum cycle length encountered.

4. **Output the Result:**
   - Print the maximum cycle length found.

### Detailed Steps:

1. **DFS for Cycle Detection:**
   - Start DFS from each vertex in the graph.
   - During DFS, mark the current vertex as visited and recursively visit its neighbors.
   - If you encounter an already visited vertex (other than the parent), you've found a back edge, indicating a cycle.
   
2. **Cycle Length Calculation:**
   - To calculate the length of the cycle, use the difference in discovery times of the vertices involved in the back edge.
   - Update a variable to keep track of the maximum cycle length encountered.

3. **Output:**
   - Print the maximum cycle length found, which is the solution to the problem.

### Time Complexity:
- The DFS traversal takes \(O(N + M)\) time, where \(N\) is the number of vertices and \(M\) is the number of edges.

### Space Complexity:
- The space complexity is \(O(N + M)\) to store the graph using an adjacency list.

This approach correctly identifies cycles and calculates the length of the longest cycle in a cactus graph.

*/