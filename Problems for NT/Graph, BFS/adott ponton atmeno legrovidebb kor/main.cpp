#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
/*
Given an undirected graph G=(V,E) and a point PV, the task is to find the length of the shortest cycle in the graph that passes through point P, and also provide such a cycle.

Input: The input consists of the number of points in the graph, N (1≤N≤10,000), the number of edges in the graph, M (1≤M≤200,000), and the index of point P (1≤P≤N). The following M lines each contain an edge of the graph represented by two integers u and v (1≤u≠v≤N).

Output: Output the length of the shortest cycle, K, and the K different point indices in the order that forms the shortest cycle in the graph when considering the edge from the last point to the first point as well. If there is no cycle that passes through point P in the graph, output -1.

Example:

Input:
8 10 2 3
1 3 2 5 3
3 6
3 2
2 4
2 5
6 7
6 8
1 8
5 3
7 4
OUtput:
4
2 5 3 6
Explanation:

For the given input, the shortest cycle that passes through point P=3 is [3, 6, 7, 3], and its length is 4.
*/
#define INF 1000000

int n, m, start;
vector<int> adj[10001];
queue<int> startNodes;
stack<int> s;

struct cycle {
    int d;
    int x;
    int y;
};

// Breadth-First Search (BFS) to find the shortest cycle
cycle BFS(int node, vector<int> &dis, vector<int> &parent) {
    queue<int> q;
    vector<bool> visited(n + 1, false);
    parent[node] = start;
    q.push(node);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto i : adj[node]) {
            if (dis[i] == 0 && i != start) {
                visited[i] = true;
                parent[i] = node;
                dis[i] = dis[node] + 1;
                q.push(i);
            } else if (parent[node] != i && !visited[i])
                return {dis[node] + dis[i] + 1, node, i};
        }
    }

    return {INF, 0, 0};
}

int main() {
    cin >> n >> m >> start;

    // Input edges and build adjacency list
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> dis(n + 1, 0), parent(n + 1, 0);

    // Initialize the BFS starting nodes and distances
    for (auto i : adj[start]) {
        startNodes.push(i);
        dis[i] = 1;
    }

    int minDis = INF, x, y;

    // Perform BFS to find the shortest cycle
    while (!startNodes.empty()) {
        cycle curr = BFS(startNodes.front(), dis, parent);
        if (curr.d < minDis) {
            minDis = curr.d;
            x = curr.x;
            y = curr.y;
        }
        startNodes.pop();
    }

    // Output the result
    if (minDis == INF) {
        cout << -1;
    } else {
        stack<int> s;
        while (y > 0) {
            s.push(y);
            y = parent[y];
        }

        cout << minDis << '\n';

        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }

        while (x > start) {
            cout << x << " ";
            x = parent[x];
        }
    }

    return 0;
}
/*
Approach Overview:
The approach is based on Breadth-First Search (BFS) to explore the graph from a specified starting vertex. The BFS algorithm is employed to traverse the graph and find the shortest cycle that passes through the given point P.

Detailed Algorithm:
Input Parsing:

Parse the input, including the number of points (n), the number of edges (m), and the index of point P (start), as well as the edges of the graph.
Build the Adjacency List:

Create an adjacency list to represent the undirected graph based on the given edges.
BFS to Find Shortest Cycle:

For each neighbor of the starting point P, perform BFS to find the shortest cycle that passes through P.
Initialize a BFS queue and a visited array to keep track of visited nodes during BFS.
Perform BFS starting from a neighbor of P. During the BFS traversal:
Keep track of the distance from the starting point P to the current node (dis array).
Keep track of the parent of each node in the traversal (parent array).
If a cycle is found, stop the BFS and return the cycle information.
Cycle Detection in BFS:

During BFS, if a node is encountered that has a distance greater than 0 (indicating a visited node) and is not the parent of the current node and is the same as the starting point, then a cycle is found.
Return the cycle information, including the length of the cycle (d), and the indices of the points forming the cycle (x and y).
Output the Result:

Output the length of the shortest cycle and the points forming the cycle, considering the edge from the last point to the first point as well.
If no cycle is found, output -1.
*/