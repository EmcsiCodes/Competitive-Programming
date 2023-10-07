#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
**Problem Summary:**

In a secret society, there is a single leader, and each member can have at most two direct subordinates. The distance between a leader and a subordinate is defined by the number of members between them in the hierarchy. A subgroup in the society is considered "complete" if each member has either zero or two subordinates, and the members without subordinates are at equal distance from their subgroup leader.

Write a program to find a member furthest from the leader who leads a complete subgroup of at least K members.

**Input:**

- Number of members (N) and the value K (1 ≤ K ≤ N-1).
- The next N-1 lines represent boss-subordinate relationships (1 ≤ Fi ≠ Bi ≤ N).

**Output:**

- Print the serial number of a member furthest from the leader who leads a complete subgroup of at least K members. If there's no such member, print 0. In case of multiple solutions, print the smallest serial number.

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
The given program addresses the problem of finding a member furthest from the leader who leads a complete subgroup of at least K members in a secret society. The subgroup is considered "complete" if each member has either zero or two subordinates, and the members without subordinates are at an equal distance from their subgroup leader.

Here's a breakdown of the approach and the implementation:

### Approach:

1. **Graph Representation:**
   - The program represents the hierarchy of the secret society as a directed graph, where each node represents a member, and edges represent the boss-subordinate relationships.

2. **DFS for Calculations:**
   - Depth-First Search (DFS) is used to traverse the hierarchy and calculate the required information about the subgroups.

3. **Subgroup Completeness Check:**
   - The program checks whether a subgroup is complete based on the number of subordinates and their arrangement.

4. **Finding the Furthest Member:**
   - The program keeps track of the furthest member leading a complete subgroup of at least K members.

### Implementation:

1. **Graph Representation:**
   - The program uses an adjacency list to represent the graph, where each member stores its direct subordinates.

2. **DFS for Calculations:**
   - The program performs a DFS traversal to calculate information about the subgroups, including whether a subgroup is complete.

3. **Subgroup Completeness Check:**
   - The program checks whether a subgroup is complete based on the number of subordinates and their arrangement within the hierarchy.

4. **Finding the Furthest Member:**
   - The program keeps track of the furthest member leading a complete subgroup of at least K members.

5. **Output:**
   - The program outputs the serial number of the member furthest from the leader, leading a complete subgroup of at least K members.

### Example Walkthrough:

Let's go through the given example step by step, showing how the program calculates the required statistics.

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
   - The program creates a graph based on the input, representing members and their boss-subordinate relationships.

2. **DFS for Calculations:**
   - The program performs a DFS traversal to calculate information about the subgroups and find the furthest member leading a complete subgroup of at least K members.

3. **Subgroup Completeness Check:**
   - The program checks whether a subgroup is complete based on the number of subordinates and their arrangement within the hierarchy.

4. **Finding the Furthest Member:**
   - The program keeps track of the furthest member leading a complete subgroup of at least K members.

5. **Output:**
   - The program outputs the serial number of the furthest member.

### Conclusion:

The program effectively calculates the serial number of the member furthest from the leader, leading a complete subgroup of at least K members in the secret society. It utilizes appropriate DFS traversal and subgroup completeness checks to determine the furthest member.

If you have any more specific questions or need further clarification, feel free to ask!
*/