#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
/*
**Problem Summary:**

In a pipe network, there are valves at the ends of each pipe. Initially, all valves are closed, except for some at the ends where water needs to be obtained.

Write a program that determines which valves need to be opened to obtain water through specific valves.

**Input:**

- The first line of the standard input contains the number of valves (2 ≤ N ≤ 100,000).
- The next N-1 lines list the starting and ending nodes of each pipe (1 ≤ Start < End ≤ N).
- The following line contains the number of valves (Cs) from which water needs to flow, followed by Cs valve numbers (1 ≤ Csapi ≤ N).

**Output:**

- The first line of the standard output should contain the number of additional valves that need to be opened to ensure water flows precisely through the valves specified in the input.
- The second line should list these valve numbers in ascending order.

**Example:**

**Input:**
```
14
1 2
1 3
1 4
2 5
2 6
3 14
3 7
7 10
7 11
4 8
4 9
8 12
8 13
3 12 13 14
```

**Output:**
```
4
1 3 4 8
```

---
*/
vector<int> adj[100001];

vector<int> BFS(int start, int n) {
    vector<int> parent(n + 1, 0);
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto i : adj[node]) {
            if (!visited[i]) {
                visited[i] = true;
                parent[i] = node;
                q.push(i);
            }
        }
    }
    return parent;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int m;
    cin >> m;
    queue<int> q;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        q.push(x);
    }
    vector<int> parent = BFS(1, n);
    set<int> res;
    while (!q.empty()) {
        int root = q.front();
        q.pop();
        if (parent[root] != 0) {
            root = parent[root];
            res.insert(root);
            q.push(root);
        }
    }
    cout << res.size() << '\n';
    for (auto i : res) cout << i << " ";
    return 0;
}
/*
The provided program is intended to determine the additional valves that need to be opened to ensure water flows precisely through specified valves in a pipe network. Here's a breakdown of the approach and the implementation:

### Approach:

1. **Graph Representation:**
   - The program represents the pipe network as an undirected graph, where each valve is a node, and the pipes are edges.

2. **BFS Traversal:**
   - The program performs a breadth-first search (BFS) traversal starting from an arbitrary node (in this case, node 1) to identify the additional valves that need to be opened to ensure water flows precisely through specified valves.

3. **Output:**
   - The program outputs the number of additional valves that need to be opened and the valve numbers in ascending order.

### Implementation:

1. **Graph Representation:**
   - The program uses an adjacency list to represent the graph of valves and pipes.

2. **BFS Traversal:**
   - The program performs a BFS traversal starting from node 1 to traverse the pipe network.
   - During the traversal, it identifies the additional valves that need to be opened based on the specified valve numbers.

3. **Output:**
   - The program outputs the number of additional valves that need to be opened and the valve numbers in ascending order.

### Example Walkthrough:

Let's go through the given example step by step to determine the additional valves that need to be opened to ensure water flows precisely through the specified valves.

### Input:
```
14
1 2
1 3
1 4
2 5
2 6
3 14
3 7
7 10
7 11
4 8
4 9
8 12
8 13
3 12 13 14
```

### Steps:
1. **Graph Representation:**
   - The program represents the pipe network using an adjacency list.

2. **BFS Traversal:**
   - The program performs a BFS traversal starting from node 1.
   - During the traversal, it identifies the additional valves that need to be opened to ensure water flows through the specified valves.

3. **Output:**
   - The program outputs the number of additional valves that need to be opened and the valve numbers in ascending order.

### Conclusion:

The program effectively calculates the additional valves that need to be opened to ensure water flows precisely through the specified valves in the pipe network, satisfying the given problem's requirements.

If you have any more specific questions or need further clarification, feel free to ask!
*/