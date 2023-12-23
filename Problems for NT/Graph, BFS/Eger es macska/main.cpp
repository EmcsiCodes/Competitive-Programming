#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
/*
Given a directed graph and the starting points for a cat and a mouse, as well as the time taken for each to traverse an edge, the goal is to find a path for the mouse that guarantees it reaches a mousehole before or at the same time as the cat, regardless of the cat's path.

Input: The first line contains the number of points (1≤N≤200) and the number of edges (1≤M≤10,000). The second line contains the starting points for the cat and mouse (1≤A≠B≤N), and the time for the cat and mouse to traverse an edge (1≤IM,IE≤100). The following M lines contain the starting and ending points for each edge (1≤K≠V≤N).

Output: Print the indices of the path the mouse can take to reach a mousehole safely. If no such path exists, output 0.

Example:

Input:
1 8 1 2
1 2
1 4
2 3
4 3
2 5
3 6
3 7
4 7
6 9
7 6
8 7
8 9
9 10
6 5

Output:
8 9 10
Explanation:

The mouse can take the path 8 → 9 → 10 to reach a mousehole before or at the same time as the cat, regardless of the cat's path.
*/
vector<int> adj[201];

// Function to perform BFS traversal for both cat and mouse
void BFS(int startNode, int time, int n, vector<int>& dis, vector<bool> visited, queue<int> q) {
    q.push(startNode);
    visited[startNode] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto i : adj[node]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
                dis[i] = dis[node] + time;
            }
        }
    }
}

// Function to solve the problem and find a safe path for the mouse
void solve(int n, int startE, int startM, int timeE, int timeM) {
    vector<int> disE(n + 1, 0), disM(n + 1, 0), path(n + 1, 0);
    vector<bool> visited(n + 1, false);
    queue<int> q;
    
    // Calculate time for the mouse to reach each node
    BFS(startM, timeM, n, disM, visited, q);

    q.push(startE);
    visited[startE] = true;
    
    // Calculate time for the cat to reach each node
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto i : adj[node]) {
            if (!visited[i]) {
                disE[i] = disE[node] + timeE;
                if (disE[i] < disM[i]) {
                    visited[i] = true;
                    q.push(i);
                    path[i] = node;
                }
            }
        }
    }

    // Find a node that represents a mousehole
    int endNode = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i] && adj[i].size() == 0) {
            endNode = i;
            break;
        }
    }

    if (endNode == 0) {
        cout << 0; // No safe path exists
        return;
    }

    // Construct and output the safe path for the mouse
    stack<int> s;
    int i = endNode;
    while (i > 0) {
        s.push(i);
        i = path[i];
    }
    
    cout << s.size() << '\n';
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

int main() {
    int n, m, startE, startM, timeE, timeM;
    cin >> n >> m >> startM >> startE >> timeM >> timeE;
    
    // Build the directed graph
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    // Solve the problem and find the safe path for the mouse
    solve(n, startE, startM, timeE, timeM);
    
    return 0;
}
/*
Problem Overview:
The problem involves finding a safe path for a mouse to reach a mousehole before or at the same time as the cat, regardless of the cat's path. The graph is directed, and each edge has a time taken for the cat and mouse to traverse it.

Approach Overview:
The approach is based on a modified breadth-first search (BFS) to explore the graph for both the cat and the mouse simultaneously. We calculate the time taken for both the cat and the mouse to reach each node and determine a safe path for the mouse.

Detailed Explanation:
Input Parsing:

Parse the input, including the number of nodes (n), the number of edges (m), the starting points for the cat and mouse (startE and startM), and the time for the cat and mouse to traverse an edge (timeE and timeM).
Build the Graph:

Create an adjacency list representation of the graph based on the provided edges.
BFS to Calculate Time for Cat and Mouse:

Perform BFS for both the cat and the mouse simultaneously.
For the mouse, calculate the time to reach each node considering the mouse's traversal time.
For the cat, calculate the time to reach each node considering the cat's traversal time.
Finding a Safe Path for the Mouse:

Compare the time taken by the cat and the mouse to reach each node.
If the mouse can reach a node before or at the same time as the cat, consider this node in the safe path for the mouse.
Output the Result:

Output the safe path for the mouse, which guarantees that the mouse reaches a mousehole before or at the same time as the cat, regardless of the cat's path.
Time Complexity Analysis:
The time complexity of the BFS traversal is O(N + M), where N is the number of nodes and M is the number of edges.
Overall, the time complexity of the solution is O(N + M), which is efficient for the given input constraints.
Overall Approach:
The program efficiently calculates the time taken by both the cat and the mouse to reach each node using a modified BFS. It then determines a safe path for the mouse based on the calculated times and outputs this path.
*/