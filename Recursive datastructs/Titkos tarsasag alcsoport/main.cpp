#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
**Problem Summary:**

A secret society has only one leader, and each member of the society can have at most two direct subordinates. The distance between a boss and a subordinate is defined by the number of members between them in the hierarchy. We consider a subgroup of the society to be complete if each member in it has either zero or two subordinates, and members without subordinates are at equal distance from the leader of the subgroup.

Write a program that finds the member farthest from the leader who leads a complete subgroup with at least K members.

**Input:**

- The first line of the standard input contains the number of members (N) and the value of K (1 ≤ K ≤ N-1).
- The next N-1 lines describe the boss-subordinate relationship, each containing two integers, F and B, where F is the boss's serial number and B is the subordinate's serial number (1 ≤ F ≠ B ≤ N).

**Output:**

- Print the serial number of the member farthest from the leader who leads a complete subgroup with at least K members. If no such member exists, print 0. If there are multiple solutions, print the smallest serial number.

**Example:**

**Input:**
```
19 5
1 2
1 3
2 4
2 5
3 6
3 7
4 8
4 9
5 10
5 11
6 12
6 13
7 14
7 15
10 16
10 17
11 18
11 19
```

**Output:**
```
5
```

---
*/

int n,k;
vector<int> adj[100001];
int maxDepth = 0;
int res = 0;
int DFS(int node,vector<bool>&visited,vector<int>&mem,int currLayer){
    visited[node] = true;
    int nextLayer = currLayer;
    for(auto i:adj[node]){
        if(!visited[i]){
            nextLayer = max(DFS(i,visited,mem,currLayer+1), nextLayer);
            mem[node] += mem[i];
        }
    }
    int pow = nextLayer - currLayer + 1;
    int needed = 1;
    while(pow>0){
        needed = needed*2;
        pow--;
    }
    if(mem[node] == needed - 1 && mem[node]>=k && maxDepth < currLayer) {
        res = node;
        maxDepth = currLayer;
    }
    return nextLayer;
}

int main()
{
    cin>>n>>k;
    vector<int> mem(n+1,1);
    vector<bool> visited(n+1,false);
    for(int i=1; i<n; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    int currLayer = 0;
    DFS(1,visited,mem,currLayer);
    cout<<res;
    return 0;
}
/*
The provided program solves the problem of finding the member farthest from the leader who leads a complete subgroup with at least K members in a secret society. The algorithm uses depth-first search (DFS) to traverse the hierarchy of the society and identify the desired member.

Here's a breakdown of the approach and the implementation:

### Approach:

1. **Graph Representation:**
   - The program represents the hierarchy of the secret society as a graph. Each member is a node in the graph, and boss-subordinate relationships are represented as edges.

2. **DFS Traversal:**
   - The program performs a depth-first search (DFS) traversal starting from the leader (node 1).
   - During the traversal, it calculates and maintains two important pieces of information:
     - `mem[node]`: The number of subordinates (direct and indirect) of each member.
     - `maxDepth`: The maximum depth (distance from the leader) reached in the hierarchy while traversing.
   - It also checks if a subgroup is complete based on the number of subordinates.

3. **Output:**
   - The program outputs the serial number of the member who leads a complete subgroup with at least K members and is farthest from the leader.
   - If no such member exists, it prints 0.

### Implementation:

1. **Graph Representation:**
   - The program uses an adjacency list to represent the hierarchy as a graph.

2. **DFS Traversal:**
   - The DFS traversal starts from the leader (node 1) and calculates `mem` and `maxDepth` values.
   - It checks if a subgroup is complete based on the number of subordinates.

3. **Output:**
   - The program outputs the serial number of the desired member.

### Example Walkthrough:

Let's go through the given example step by step, showing how the program finds the member farthest from the leader who leads a complete subgroup with at least 5 members.

### Input:
```
19 5
1 2
1 3
2 4
2 5
3 6
3 7
4 8
4 9
5 10
5 11
6 12
6 13
7 14
7 15
10 16
10 17
11 18
11 19
```

### Steps:
1. **Graph Representation:**
   - The program represents the hierarchy of the secret society as a graph.

2. **DFS Traversal:**
   - The DFS traversal starts from the leader (node 1) and calculates `mem` and `maxDepth` values while identifying complete subgroups.

3. **Output:**
   - The program outputs the serial number of the member who leads a complete subgroup with at least 5 members and is farthest from the leader, which is 5 in this case.

### Conclusion:

The program effectively identifies and outputs the desired member's serial number, satisfying the conditions of leading a complete subgroup with at least 5 members and being farthest from the leader.

If you have any more specific questions or need further clarification, feel free to ask!
*/