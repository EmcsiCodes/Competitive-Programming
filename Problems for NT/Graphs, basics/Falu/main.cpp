#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
/*
- **Problem Description**:
  Given a county with various villages and towns connected by roads, identify the following:
  A. Number of dead-end villages (villages with only one road leading in or out).
  B. The village with the most roads originating from neighboring places.
  C. The two non-neighbor villages that are closest to each other (if multiple, the one with the smallest number).

- **Input**:
  - The first line of standard input contains the number of settlements N (2 ≤ N ≤ 1000) and the number of roads M (1 ≤ M ≤ 10000).
  - The following M lines each contain three integers: the two endpoints of a road (representing a connection between two settlements) and the length of the road.

- **Output**:
  - The program should output the answers to questions A, B, and C in three separate lines.

- **Example**:
  - **Input**:
    ```
    6 7
    1 2 10
    2 3 15
    2 4 10
    2 5 5
    3 5 5
    4 5 15
    5 6 5
    ```
  - **Output**:
    ```
    2
    2
    2 6
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
// Structure to represent an edge between settlements
struct triple {
    int node1;
    int node2;
    int dis;
};

// Structure to store the result of the closest non-neighbor villages
triple res = {0, 0, 10000000};

// Adjacency list to represent the graph
vector<pair<int, int>> adj[1001];

// Breadth-First Search to find the closest non-neighbor villages
void BFS(int start, int n) {
    queue<int> q;
    vector<bool> visited(n + 1, false);
    vector<int> dis(n + 1, 0);
    q.push(start);
    visited[start] = true;
    int layer = 2;
    int backnode = start;
    while (!q.empty() && layer != 0) {
        int node = q.front();
        q.pop();
        for (auto i : adj[node]) {
            if (!visited[i.first]) {
                visited[i.first] = true;
                dis[i.first] = dis[node] + i.second;
                q.push(i.first);
                if (layer == 1 && dis[i.first] < res.dis) res = {start, i.first, dis[i.first]};
            }
        }
        if (q.back() != backnode) {
            backnode = q.back();
            layer--;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Input roads and build the graph
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }

    int deadEndCount = 0;
    int maxDegree = 0;
    int maxDegreeIndex = 0;

    // Find dead-end villages and village with the most roads
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1) {
            deadEndCount++;
        }
        if (adj[i].size() > maxDegree) {
            maxDegree = adj[i].size();
            maxDegreeIndex = i;
        }
    }

    cout << deadEndCount << '\n' << maxDegreeIndex << '\n';

    // Find the closest non-neighbor villages
    for (int i = 1; i <= n; i++) {
        BFS(i, n);
    }

    // Output the closest non-neighbor villages
    cout << res.node1 << " " << res.node2;

    return 0;
}
/*
### Road Settlements

#### Approach:
The problem is to analyze a county with various villages and towns connected by roads and answer specific questions regarding the settlements.

1. **Graph Representation**:
   - We model the problem as an undirected graph, where each settlement is a node, and roads connecting settlements are edges.

2. **Dead-End Villages**:
   - A dead-end village is a village with only one road leading in or out.
   - We traverse the graph and count nodes with only one neighbor.

3. **Village with Most Roads**:
   - We find the village with the highest degree (most roads originating from neighboring places) by examining the number of edges for each node.

4. **Closest Non-Neighbor Villages**:
   - To find the two non-neighbor villages that are closest to each other, we perform a BFS from each village and maintain the minimum distance and nodes for the closest pair.

The code first finds dead-end villages by counting nodes with only one neighbor,
then finds the village with the highest degree (most roads originating from neighboring places),
and finally computes the closest non-neighbor villages using BFS. The results are then outputted as per the given format.
*/