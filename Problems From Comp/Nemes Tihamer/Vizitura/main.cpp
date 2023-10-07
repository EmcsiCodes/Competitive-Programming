#include <iostream>
#include <set>
#include <vector>
#include <queue>

using namespace std;

/*
**Problem Summary:**

Given the distances between adjacent riverbank settlements, you need to find the longest possible river tour. A river tour is a sequence of adjacent settlements where the river flows through, possibly against the flow direction.

**Input:**

- The number of settlements, N (1 ≤ N ≤ 100,000).
- N-1 lines, each containing two neighboring settlement indices and the distance between them.

**Output:**

- The length of the longest possible river tour.
- The possible starting and ending points of the longest river tour.

**Example:**

- **Input:**
  ```
  10
  2 1 3
  3 1 1
  6 4 2
  4 2 6
  7 5 1
  5 2 5
  8 7 9
  9 6 6
  10 2 8
  ```

- **Output:**
  ```
  29
  8 9
  ```

This means that the longest river tour has a length of 29 and it starts from settlement 8 and ends at settlement 9.


*/
vector< pair<int,int> > adj[100001];

pair<int,int> BFS(int start, int n){
    vector<bool> visited(n+1,false);
    vector<int> dis(n+1,0);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i.first]){
                visited[i.first]= true;
                q.push(i.first);
                dis[i.first] = dis[node] + i.second;
            }
        }
    }
    int maxDis = 0;
    int maxDisI = 0;
    for(int i=1; i<=n; i++){
        if(maxDis < dis[i]){
            maxDis = dis[i];
            maxDisI = i;
        }
    }
    return {maxDis, maxDisI};
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<n; i++){
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }
    pair<int,int> dis1 = BFS(1,n);
    //cout<<dis1.first<<" "<<dis1.second;
    pair<int,int> res = BFS(dis1.second,n);

    cout<<res.first<<'\n'<<dis1.second<<" "<<res.second;
    return 0;
}
/*
The provided program solves the problem of finding the longest possible river tour in a network of settlements connected by a river. Here's a breakdown of the approach and the implementation:

### Approach:

1. **Graph Representation:**
   - The program represents the network of settlements as a graph, where each settlement is a node, and the river connections are edges.

2. **BFS Traversal:**
   - The program performs two breadth-first search (BFS) traversals.
   - The first BFS traversal is used to find the farthest settlement from an arbitrary starting point (in this case, node 1).
   - The second BFS traversal starts from the settlement found in the first traversal and finds the farthest settlement from it.
   - The distance between the two farthest settlements found in the second traversal is the length of the longest possible river tour.
   - The starting and ending points of this longest river tour are the settlements found in the two traversals.

3. **Output:**
   - The program outputs the length of the longest possible river tour and the starting and ending points.

### Implementation:

1. **Graph Representation:**
   - The program uses an adjacency list to represent the graph of settlements and river connections.

2. **BFS Traversals:**
   - The program performs two BFS traversals to find the longest river tour.
   - The first BFS traversal starts from any arbitrary node (in this case, node 1) and finds the farthest settlement and its distance from the starting point.
   - The second BFS traversal starts from the farthest settlement found in the first traversal and finds the farthest settlement from it.

3. **Output:**
   - The program outputs the length of the longest possible river tour and the starting and ending points.

### Example Walkthrough:

Let's go through the given example step by step to determine the longest possible river tour.

### Input:
```
10
2 1 3
3 1 1
6 4 2
4 2 6
7 5 1
5 2 5
8 7 9
9 6 6
10 2 8
```

### Steps:
1. **Graph Representation:**
   - The program represents the network of settlements using an adjacency list.

2. **BFS Traversals:**
   - The program performs two BFS traversals to find the longest possible river tour.
   - The first traversal starts from node 1 and finds the farthest settlement.
   - The second traversal starts from the farthest settlement found in the first traversal and finds the ending point of the longest river tour.

3. **Output:**
   - The program outputs the length of the longest possible river tour and the starting and ending points.

### Conclusion:

The program effectively calculates the length of the longest possible river tour and identifies the starting and ending points for this tour, satisfying the given problem's requirements.

If you have any more specific questions or need further clarification, feel free to ask!
*/