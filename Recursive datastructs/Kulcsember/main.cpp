#include <iostream>
#include <vector>

using namespace std;

/*
**Problem Summary:**

In a gang, each member knows only their immediate superior and direct subordinates. A "key person" is a gang member whose arrest would split the gang into multiple subgroups such that the largest subgroup has the smallest possible size.

Write a program that determines a "key person" in the gang.

**Input:**

- The first line of the standard input contains the number of gang members (1 ≤ N ≤ 100,000).
- The next N-1 lines each contain the index of a superior and their subordinate (1 ≤ Fi ≠ Bi ≤ 100,000). The leader of the gang is indexed as 1. A gang member can have at most 10 direct subordinates.

**Output:**

- The first line of the standard output should contain the index of a "key person" and the size of the largest subgroup formed after their arrest. If there are multiple solutions, any of them can be chosen.

**Example:**

**Input:**
```
6
1 5
5 2
5 4
5 3
1 6
```

**Output:**
```
5 2
```

**Explanation:**
- Arresting member 5 would create three subgroups: {2, 3, 4}, {1}, and {5, 6}. The largest subgroup has 2 members.

---

**Note:**

The example provided is illustrative and does not represent the actual solution for the given input. The actual calculation for the "key person" needs to be based on the relationships provided in the input.
*/

int n;
vector<int> adj[100001];

int DFS(int node,vector<bool> &visited,vector<int>&res){
    visited[node] = true;
    int curr = 1;
    for(auto i:adj[node]){
        if(!visited[i]){
            int num = DFS(i,visited,res);
            res[node] = max(res[node], num);
            curr += num;
        }
    }
    res[node] = max(res[node], n - curr);
    return curr;
}

int main()
{
    
    cin>>n;
    for(int i=1; i<n; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> res(n+1,0);
    vector<bool> visited(n+1,false);
    int a = DFS(1,visited,res);
    int minSplit = n;
    int minSplitI = 0;
    for(int i=1; i<=n; i++){
        if(minSplit > res[i]){
            minSplit = res[i];
            minSplitI = i;
        }
    }
    cout<<minSplitI<<" "<<minSplit;
    return 0;
}
/*
The provided C++ program aims to determine a "key person" in a gang, which is a gang member whose arrest would split the gang into multiple subgroups such that the largest subgroup has the smallest possible size. Here's a detailed explanation of the code:

### Approach and Algorithm:

1. **Graph Representation:**
   - The gang's structure is represented as a tree, where each gang member (node) knows only their immediate superior (parent) and direct subordinates (children).
   - The graph is represented using an adjacency list.

2. **Depth-First Search (DFS) for Subgroup Size:**
   - The program performs a DFS traversal on the tree starting from the gang leader (node 1).
   - During the DFS traversal, it calculates the size of each subgroup that would be formed after the arrest of each gang member.

3. **Identifying the "Key Person":**
   - For each gang member, the program calculates the size of the largest subgroup formed after their arrest.
   - The "key person" is the gang member whose arrest results in the smallest size of the largest subgroup.

### Detailed Walkthrough of the Code:

1. **Data Structures:**
   - `vector<int> adj[100001]`: Represents the gang's structure as an adjacency list.
   - `vector<int> res(n+1,0)`: Stores the size of the largest subgroup after the arrest of each gang member.
   - `vector<bool> visited(n+1,false)`: Keeps track of visited nodes during DFS.

2. **DFS for Subgroup Size (`DFS` function):**
   - The `DFS` function calculates the size of each subgroup using DFS traversal.
   - It iterates through each gang member, calculating the size of the largest subgroup formed after their arrest.

3. **Main Function (`main`):**
   - Reads input, initializes data structures, and performs DFS to calculate subgroup sizes.
   - Identifies the "key person" based on the smallest size of the largest subgroup.
   - Outputs the "key person" and the size of the largest subgroup formed after their arrest.

### Example Walkthrough:

Let's walk through the given example and observe how the program calculates the "key person" and the size of the largest subgroup formed after their arrest.

### Input:
```
6
1 5
5 2
5 4
5 3
1 6
```

### Steps:
1. **Graph Representation:**
   - The graph is represented using an adjacency list. Each node corresponds to a gang member, and each edge corresponds to a superior-subordinate relationship.

2. **DFS for Subgroup Size:**
   - DFS is performed to calculate the size of the largest subgroup after each gang member's arrest.
   - The subgroup sizes are stored in the `res` vector.

3. **Identifying the "Key Person":**
   - The program identifies the "key person" by finding the gang member whose arrest results in the smallest size of the largest subgroup.

4. **Output (`cout` statements):**
   - The program outputs the "key person" and the size of the largest subgroup formed after their arrest.

### Conclusion:

The program effectively implements an algorithm to determine the "key person" in a gang based on the smallest size of the largest subgroup that would be formed after their arrest. It calculates the subgroup sizes using DFS traversal and identifies the optimal gang member to arrest.

If you have any more specific questions or need further clarification, feel free to ask!
*/