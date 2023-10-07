#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
/*
**Problem Summary:**

Given a directed ordered tree, a node in the tree is considered an endpoint if at its level, there are no nodes to its left or right.

Write a program to determine the endpoints of a tree.

**Input:**

- The first line of the standard input contains the number of nodes in the tree (1 ≤ N ≤ 30,000).
- The next N lines list the immediate descendants of each node. In the i-th line, the immediate descendants of node i are listed from left to right. Each line is terminated with a 0.

**Output:**

- The first line of the standard output should contain the number (M) of endpoints in the input tree.
- The second line should list the endpoints, in any order.

**Example:**

**Input:**
```
9
2 3 4 0
5 6 0
7 0
0
0
0
9 8 0
0
0
```

**Output:**
```
7
1 2 5 4 7 9 8
```

---
*/
vector<int> adj[30001];

vector<int> BFS(int start,int n){
    vector<int> dis(n+1,0);
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int node =q.front();
        q.pop();
        for(auto i:adj[node]){
            q.push(i);
            dis[i] = dis[node] + 1;
        }
    }
    return dis;
}

int main()
{
    int n;
    cin>>n;
    set<int> sorr[30001];
    vector<int> indexes(n+1,0);
    int j = 1;
    for(int i=1; i<=n; i++){
        int x;
        while(cin>>x&& x!=0){
            adj[i].push_back(x);
            indexes[x] = j;
            j++;
        }
    }
    vector<int> dis = BFS(1,n);
    int maxx = 0;
    for(int i=1; i<=n; i++){
        sorr[dis[i]].insert(i);
        maxx = max(maxx,dis[i]);
    }
    set<int> res;
    for(int i=0; i<=maxx; i++){
        auto first = sorr[i].begin();
        auto last = sorr[i].rbegin();
        res.insert(*first);
        res.insert(*last);
    }
    cout<<res.size()<<'\n';
    for(auto i:res)cout<<i<<" ";
    return 0;
}
/*
The provided program correctly determines the endpoints of a tree using a breadth-first search (BFS) traversal on the directed ordered tree. Here's a breakdown of the approach and the implementation:

### Approach:

1. **Graph Representation:**
   - The program represents the directed ordered tree using an adjacency list.

2. **BFS Traversal:**
   - The program performs a breadth-first search (BFS) traversal starting from node 1 to determine the distances of all nodes from the root.
   - During traversal, it records the distances of each node from the root.

3. **Identifying Endpoints:**
   - The program stores the nodes in sets based on their distances from the root.
   - For each distance, it finds the first and last nodes at that distance, which represent the leftmost and rightmost nodes at that level.
   - The first node is added to the set of endpoints.

4. **Output:**
   - The program outputs the number of endpoints and the endpoint nodes in any order.

### Implementation:

1. **Graph Representation:**
   - The program uses an adjacency list to represent the directed ordered tree.

2. **BFS Traversal:**
   - The BFS traversal starts from node 1 and calculates the distances of nodes from the root.

3. **Identifying Endpoints:**
   - The program stores nodes in sets based on their distances from the root.
   - It finds the first and last nodes at each distance and adds them to the set of endpoints.

4. **Output:**
   - The program outputs the number of endpoints and the endpoint nodes.

### Example Walkthrough:

Let's go through the given example step by step to determine the endpoints.

### Input:
```
9
2 3 4 0
5 6 0
7 0
0
0
0
9 8 0
0
0
```

### Steps:
1. **Graph Representation:**
   - The program represents the directed ordered tree using an adjacency list.

2. **BFS Traversal:**
   - The BFS traversal calculates the distances of each node from the root (node 1).

3. **Identifying Endpoints:**
   - The program identifies endpoints by finding the first and last nodes at each distance from the root.

4. **Output:**
   - The program outputs the number of endpoints and the endpoint nodes.

### Conclusion:

The program effectively determines and outputs the number of endpoints and the endpoint nodes of the tree, satisfying the given problem's requirements.

If you have any more specific questions or need further clarification, feel free to ask!
*/