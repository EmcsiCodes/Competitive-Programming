#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
/*
In a city, various points are connected by a canal network, and each canal has a certain width. A company wants to transport goods by ship from point A to point B using the widest possible ship. If there are multiple routes where a ship of the required width can travel, the company chooses the route with the fewest canals to pass through.

Input: The first line of input contains the number of points (2≤N≤20,000), the number of canals (2≤M≤100,000), and the node numbers A and B (1≤A≠B≤N). The following M lines each contain the two end points of a canal (1≤Xi≠Yi≤N) and its width (1≤Szi≤1,000,000).

Output: The first line of the standard output should indicate the width of the widest ship with which transportation from A to B is possible. The second line should indicate the minimum length of the route that can be covered using a ship of this width.

Example:

Input:
5 7 1 5
1 3 2
1 2 5
3 2 7
2 4 4
3 4 9
5 4 6
5 3 5
OUtput:
5
3
Explanation:

For the given input, the widest ship that can be used has a width of 5,
and the minimum length of the route using a ship of this width is 3.
*/
vector< pair<int,int> > adj[20001];


// Dijkstra's Algorithm to find the widest ship that can be used and the minimum length of the route
void DijkstraAlgo(int startNode, int endNode, int n, vector<int> &dis) {
    priority_queue<pair<int, int>> pq;
    dis[startNode] = 1000001;
    pq.push({dis[startNode], startNode});

    while (!pq.empty()) {
        int node = pq.top().second;
        pq.pop();
        for (auto i : adj[node]) {
            if (dis[i.first] < dis[node]) {
                dis[i.first] = min(dis[node], i.second);
                pq.push({dis[i.first], i.first});
            }
        }
    }
}

// Find the shortest path from startNode to endNode based on the widest ship
void shortestPath(int startNode, int endNode, int n, vector<int> dis) {
    vector<bool> visited(n + 1, false);
    vector<int> path(n + 1, 0);
    queue<int> q;
    visited[endNode] = true;
    q.push(endNode);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto i : adj[node]) {
            if (!visited[i.first] && i.second >= dis[node]) {
                q.push(i.first);
                visited[i.first] = true;
                path[i.first] = path[node] + 1;
            }
        }
    }

    cout << dis[endNode] << '\n' << path[startNode];
}

// Function to solve the problem
void solve(int startNode, int endNode, int n) {
    vector<int> dis(n + 1, 0);
    DijkstraAlgo(startNode, endNode, n, dis);
    shortestPath(startNode, endNode, n, dis);
}

int main() {
    int n, m, startNode, endNode;
    cin >> n >> m >> startNode >> endNode;

    // Build the adjacency list based on the provided canals
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }

    // Solve the problem and output the results
    solve(startNode, endNode, n);

    return 0;
}
/*
Approach Overview:
The approach involves using Dijkstra's algorithm to find the widest ship that can travel from point A to point B. After finding the widest ship, a breadth-first search (BFS) is performed to find the shortest path considering this widest ship.

Detailed Explanation:
Input Parsing:

Parse the input, including the number of points (n), the number of canals (m), the starting node number (startNode), and the ending node number (endNode).
Build the Adjacency List:

Create an adjacency list representation of the graph based on the provided canal connections and their widths.
Dijkstra's Algorithm: Finding the Widest Ship:

Use Dijkstra's algorithm to traverse the graph and find the widest ship that can be used for transportation from startNode to endNode.
During this traversal, we keep track of the maximum width (dis[i]) that can be accommodated at each node.
Shortest Path Calculation:

Use a breadth-first search (BFS) to traverse the graph and find the shortest path from startNode to endNode.
During this traversal, we only consider the canals where the width is greater than or equal to the width obtained from Dijkstra's algorithm.
We increment the path length (path[i]) for each node we visit.
Output the Result:

Output the widest ship that can be used (dis[endNode]), which represents the maximum width of the canals through which the ship can pass.
Output the minimum length of the route that can be covered using a ship of this width (path[startNode]).
Time Complexity Analysis:
The time complexity is mainly determined by Dijkstra's algorithm, which takes O((N + M) log N) time, where N is the number of nodes and M is the number of canal connections.
The BFS traversal for shortest path also takes O(N + M) time.
Overall, the time complexity of the solution is O((N + M) log N), where N is the number of nodes and M is the number of canal connections.
Overall Approach:
The program efficiently traverses the canal network using Dijkstra's algorithm to find the widest ship that can be used and then determines the minimum length of the route that can be covered using a ship of this width. The BFS approach ensures accurate shortest path calculation based on the widest ship,
providing a valid and optimal solution to the problem.
*/