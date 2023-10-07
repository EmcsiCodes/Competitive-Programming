#include <iostream>
#include <vector>
#include <set>
using namespace std;
/*
- **Problem Name**: Barátok (Friends)

- **Problem Description**:
  In a class, there are N students. Friendships between pairs of students are known. Friendship is a transitive and symmetric relationship. If A is a friend of B and B is a friend of C, then A is also a friend of C.

- **Task**:
  Write a program to determine how many distinct friend groups exist in the class.

- **Input**:
  - The first line of the standard input contains the number of students N (2 ≤ N ≤ 10,000) and the number of known friendships M (0 ≤ M ≤ 100,000).
  - The next M lines each contain two numbers separated by a space, representing pairs of students known to be friends.

- **Output**:
  - The program should output the number of friend groups K.
  - Following that, it should output the students in each friend group in increasing order, separated by spaces.

- **Example**:
  - **Input**:
    ```
    9 6
    1 3
    3 5
    4 6
    7 9
    8 9
    1 7
    ```
  - **Output**:
    ```
    3
    1 3 5 7 8 9
    2
    4 6
    ```

- **Constraints**:
  - Time Limit: 0.1 seconds
  - Memory Limit: 32 MiB
*/
// Adjacency list to represent the graph
vector<int> adj[10001];
// Array to mark visited nodes during DFS
bool visited[10001] = {false};
// Array of sets to store the components
set<int> comp[10001];
// Variable to store the number of components
int comp_num = 0;

// Depth-First Search to find connected components
void DFS(int node, bool visited[]) {
    visited[node] = true;
    for (auto i : adj[node]) {
        if (!visited[i]) {
            comp[comp_num].insert(i);
            DFS(i, visited);
        }
    }
}

// Function to find and output the connected components
void components(int n) {
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            comp_num++;
            comp[comp_num].insert(i);
            DFS(i, visited);
        }
    }
    cout << comp_num << endl;
    for (int i = 1; i <= comp_num; i++) {
        for (auto j : comp[i]) {
            cout << j << " ";
        }
        cout << '\b' << '\n';
    }
    cout << '\b';
}

int main() {
    int n, m;
    cin >> n >> m;
    // Input friendships and build the graph
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    // Find and output the connected components
    components(n);
    return 0;
}
/*
### Friends

#### Approach:
The task is to determine the number of distinct friend groups in a class. We are given information about friendships between pairs of students, and we need to identify the different groups of friends.

1. **Graph Representation**:
   - We can model this problem as an undirected graph, where each student is a node, and friendships are edges between nodes.

2. **Connected Components**:
   - A connected component in this context is a group of students where each student is a friend of at least one other student in the group.

3. **Depth-First Search (DFS)**:
   - We can use Depth-First Search to traverse the graph and find the connected components.
   - Starting from a node, we perform DFS to explore all nodes reachable from it and add them to the same connected component.

4. **Outputting the Results**:
   - We count the number of connected components found by DFS.
   - For each component, we output the students (nodes) in that component in increasing order.
*/