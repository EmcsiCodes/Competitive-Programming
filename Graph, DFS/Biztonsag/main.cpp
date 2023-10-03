#include <iostream>
#include <vector>
using namespace std;

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