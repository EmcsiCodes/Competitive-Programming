#include <iostream>
#include <vector>
using namespace std;
/*
"Biztonság" (Security):

- **Problem Description**:
  The security service is preparing for a visit by a particularly protected guest. They know that the guest will visit a building at intersection A and another building at intersection B within the city. However, for security reasons, they only decide on the route at the last moment, making sure not to pass through any intersection more than once.

- **Task**:
  Create a program that, given the city's road network, determines all the intersections the guest can pass through when traveling from A to B.

- **Input**:
  - The first line of standard input contains the number of intersections N (1 ≤ N ≤ 100,000) and the number of streets M (1 ≤ M ≤ 500,000).
  - The second line contains the intersection numbers A and B (1 ≤ A ≠ B ≤ N).
  - The next M lines describe each street, with two integers representing the intersection numbers U and V, indicating a direct path from intersection U to intersection V without passing through any other intersection in both directions (1 ≤ U ≠ V ≤ N).

- **Output**:
  - The program should output the number of intersections through which the guest can pass when traveling from A to B.
  - The second line should list the intersections, separated by spaces, in any order.

- **Example**:
  - **Input**:
    ```
    10 13
    1 5
    1 6
    1 7
    6 7
    1 8
    9 8
    1 2
    1 3
    2 3
    2 4
    4 3
    4 5
    5 10
    10 4
    ```
  - **Output**:
    ```
    4
    3 4 10 2
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
vector<int> adj[100001];

// Depth-First Search (DFS) to mark nodes that can be reached from the endNode
void DFS(int node, vector<bool> &visited, vector<bool> &canReach) {
    visited[node] = true;
    for (auto i : adj[node]) {
        if (canReach[i]) canReach[node] = true;
        if (!visited[i]) {
            DFS(i, visited, canReach);
        }
    }
}

int main() {
    int n, m, startNode, endNode;
    cin >> n >> m >> startNode >> endNode;

    // Build the adjacency list based on the provided edges
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<bool> visited(n + 1, false);
    vector<bool> canReach(n + 1, false);
    canReach[endNode] = true; // The endNode can always be reached

    // Start DFS from the startNode to mark nodes that can be reached from endNode
    DFS(startNode, visited, canReach);

    // Collect the nodes that can be reached from endNode
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        if (canReach[i]) res.push_back(i);
    }

    // Output the result
    cout << res.size() << '\n';
    for (auto i : res) cout << i << " ";
    cout << '\b'; // Remove the last space

    return 0;
}
/*
Input Parsing:

Parse the input, including the number of nodes (n), the number of edges (m), the starting node (startNode), and the ending node (endNode).
Parse the edges to create an adjacency list representation of the graph.
Build the Adjacency List:

Create an adjacency list based on the provided edges, representing the connections between nodes.
DFS to Mark Reachable Nodes:

Perform a DFS traversal starting from the startNode.
During traversal, mark nodes that can be reached from the endNode by updating the canReach array.
Collect Reachable Nodes:

Collect the nodes that can be reached from the endNode by examining the canReach array.
Output the Result:

Output the count of nodes that can be reached and the node indices, separated by spaces.
Remove the last space by using '\b'.
This program uses DFS to find nodes that can be reached from a given end node in an undirected graph. It then outputs the count and indices of these nodes, providing an accurate solution to the problem.
*/