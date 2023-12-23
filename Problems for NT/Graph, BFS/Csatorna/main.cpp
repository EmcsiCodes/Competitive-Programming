#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
In a sewage channel network, a cleaning robot is developed.
The network consists of nodes and circular cross-section channel segments between them,
and the diameter of each segment is known. The robot can clean a pipe if its diameter is larger than the robot's size.
The robot can move in both directions in the channel.

Input: The first line of input contains the number of nodes (1≤N≤40,000),
the number of channel segments (1≤M≤400,000), the starting node number (1≤S≤N),
and the robot's size (1≤R≤100), separated by spaces. The following M lines each contain
two end points of a channel segment (1≤Ki≠Vi≤N) and its diameter (1≤Ai≤100).

Output: The first line of the standard output should indicate the number of channel segments that
can be cleaned starting from point S. The second line should indicate the minimum number of additional
starting points from which the robot can clean all the channels it fits into.
Example:

Input:
12 15 4 10
1 2 11
5 8 1
1 3 11
1 4 1
2 5 11
6 7 1
3 6 1
4 7 11
4 8 11
4 5 1
8 7 11
11 7 10
8 12 11
9 10 1
11 10 11
Output:
4
2
Explanation:

For the given input, the robot starting from point 4 can clean 4 channel segments. Additionally, it's required to start from 2 other points to clean all channels that the robot can fit into.


*/

vector<int> adj[40001];  // Adjacency list to represent the graph

// Breadth-First Search (BFS) to count the number of cleanable channels
void BFS(int startNode, int n, int &res, vector<bool> &visited) {
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // Count the number of channels that can be cleaned from this node
        for (auto i : adj[node]) {
            res++;
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    res /= 2;  // Since each channel is counted twice (bi-directional)
}

// Function to solve the problem
void solve(int startNode, int n) {
    vector<bool> visited(n + 1, false);
    int res = 0;
    BFS(startNode, n, res, visited);
    cout << res << '\n';

    int compNum = 0;
    for (int i = 1; i <= n; i++) {
        // Count the number of additional starting points from which the robot can clean all channels it fits into
        if (!visited[i] && adj[i].size() != 0) {
            BFS(i, n, res, visited);
            compNum++;
        }
    }
    cout << compNum;
}

int main() {
    int n, m, startNode, width;
    cin >> n >> m >> startNode >> width;

    // Build the adjacency list based on the provided channel segments
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (z > width) {
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    }

    // Solve the problem and output the results
    solve(startNode, n);

    return 0;
}
/*
Approach Overview:
The approach uses BFS (Breadth-First Search) to traverse the graph and count the cleanable channels starting from a given point. It then finds the minimum number of additional starting points from which the robot can clean all the channels it fits into.

Detailed Explanation:
Input Parsing:

Parse the input, including the number of nodes (n), the number of channel segments (m), the starting node number (startNode), and the robot's size (width).
Build the Adjacency List:

Create an adjacency list representation of the graph based on the provided channel segments. Only include segments that the robot can clean (diameter greater than the robot's size).
BFS to Count Cleanable Channels:

Perform a BFS traversal starting from the specified starting node.
For each traversed channel, increment the count of cleanable channels (res).
The BFS traversal ensures that we explore all channels that the robot can clean.
Output the Result - Cleanable Channels:

Output the count of channel segments that can be cleaned starting from the specified node (res).
Additional Starting Points:

Iterate through all nodes (1 to n).
For each unvisited node with at least one adjacent channel, perform BFS to count the channels that can be cleaned from this node.
Increment the count of additional starting points (compNum) where the robot can clean all channels it fits into.
Output the Result - Additional Starting Points:

Output the minimum number of additional starting points from which the robot can clean all the channels it fits into (compNum).
Overall Approach:
The program efficiently traverses the sewage channel network using BFS, counting the cleanable channels starting from a specified point and determining additional starting points for cleaning.
The BFS approach ensures that all reachable channels for cleaning are considered, providing a valid and optimal
solution to the problem.
*/
