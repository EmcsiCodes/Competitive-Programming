#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
In an animal zoo, there are known pathways between enclosures. The entrance is represented by point 0. Animals are identified by numbers between 1 and N. Paths are represented by pairs of animal numbers, indicating a pathway between their enclosures. Visitors want to reach certain animals through the shortest possible paths.

Input: The input consists of the number of animals in the zoo, N (1≤N≤1000), and the number of paths, M (1≤M≤400,000). The following M lines each describe a path, represented by two animal numbers (or the entrance) indicating the path between their enclosures (0≤A≠B≤N).

Output: Output N lines in total. The i-th line should contain the number of shortest paths from the entrance to the animal with index i. Since these numbers can be very large, output them modulo 100,000,000.

Example:

Input:
5 7
0 1
1 4
3 1
3 5
2 0
2 3
4 5
Output:
1
1
2
1
3
Explanation:

For the given input, there are 5 animals. The number of shortest paths from the entrance to each animal is as follows:

Animal 1: 0 shortest paths
Animal 2: 1 shortest path
Animal 3: 2 shortest paths
Animal 4: 0 shortest paths
Animal 5: 0 shortest paths
*/

vector<int> adj[1001];

// Function to perform Breadth-First Search (BFS) from the entrance to calculate the number of shortest paths to each animal
void BFS(int n) {
    vector<bool> visited(n + 1, false);
    vector<int> perm(n + 1, 0); // Store the number of shortest paths for each animal
    vector<int> dis(n + 1, 0);  // Store the distance from the entrance to each animal
    queue<int> q;

    // Start BFS from the entrance (node 0)
    visited[0] = true;
    perm[0] = 1;  // There's 1 way to reach the entrance (itself)
    q.push(0);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // Traverse the neighbors of the current node
        for (auto i : adj[node]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
                dis[i] = dis[node] + 1;
                perm[i] = (perm[node] + perm[i]) % 100000000; // Update the number of shortest paths
            } else if (dis[i] == dis[node] + 1) {
                perm[i] = (perm[node] + perm[i]) % 100000000; // If the shortest path is found again, add to the count
            }
        }
    }

    // Output the number of shortest paths for each animal
    for (int i = 1; i <= n; i++) {
        cout << perm[i] << '\n';
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    // Build the adjacency list based on the provided paths
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // Call the BFS function to calculate the number of shortest paths for each animal
    BFS(n);
    return 0;
}
/*
Explanation:

Input Parsing:

Parse the input, including the number of animals in the zoo (n) and the number of paths (m).
Parse the paths, which represent connections between animals and the entrance.
Build the Adjacency List:

Create an adjacency list to represent the connections between animals and the entrance.
BFS to Calculate Shortest Paths:

Perform a BFS traversal starting from the entrance (node 0) to calculate the number of shortest paths to each animal.
Track the number of shortest paths for each animal (perm) and their distance from the entrance (dis).
Update Shortest Paths:

Update the number of shortest paths for each animal while traversing the graph, ensuring the shortest paths are counted accurately.
Output the Result:

Output the number of shortest paths for each animal, considering the modulo operation as specified in the problem.
This program uses BFS to determine the number of shortest paths from the entrance to each animal in the zoo, ensuring efficiency and accuracy by leveraging appropriate data structures and traversal techniques.
*/