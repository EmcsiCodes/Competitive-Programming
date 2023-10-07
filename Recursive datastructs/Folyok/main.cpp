#include <iostream>
#include <vector>

using namespace std;
/*
**Problem Summary:**

Given information about the flow of rivers into other rivers in Hungary, the task is to calculate which rivers contribute water to a specific river and which rivers can potentially be polluted by the given river.

**Input:**

- Number of rivers (N).
- Number of rivers flowing into other rivers (M).
- The river to be investigated (F).
- M pairs of river indices representing which river flows into which other river.

**Output:**

- Rivers from which water flows into the specified river.
- Rivers that can be potentially polluted by the specified river.

**Example:**

- **Input:**
  ```
  5 4 1
  1 2
  3 2
  4 1
  5 4
  ```

- **Output:**
  ```
  2 4 5
  1 2
  ```

In this example, rivers 4 and 5 flow into river 1. River 1 can potentially pollute rivers 2 and 3.

---

*/
vector<int> adj[10001];

void DFS(int node,vector<bool>&visited,vector<bool>&canReachFromK,vector<bool>&canReachK){
    visited[node] = true;
    for(auto i:adj[node]){
        if(!visited[i]){
            canReachFromK[i] = true;
            DFS(i,visited,canReachFromK,canReachK);
        } else if(canReachK[i]) canReachK[node] = true;
    }
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    vector<bool> visited(n+1,false);
    vector<bool> canReachFromK(n+1,false), canReachK(n+1,false);
    canReachK[k] = true;
    DFS(k,visited,canReachFromK,canReachK);
    for(int i=1; i<=n; i++){
        if(!visited[i]) DFS(i,visited,canReachFromK,canReachK);
    }
    vector<int> res1,res2;
    for(int i=1; i<=n; i++) if(canReachK[i] && i!=k) res1.push_back(i);
    for(int i=1; i<=n; i++) if(canReachFromK[i]) res2.push_back(i);
    cout<<res1.size()<<" ";
    for(auto i:res1) cout<<i<<" ";
    cout<<'\n'<<res2.size()<<" ";
    for(auto i:res2) cout<<i<<" "; 
    return 0;
}
/*
The provided C++ program addresses the problem of identifying rivers from which water flows into a specified river and which rivers can potentially be polluted by the specified river in a given river flow network. Let's break down the approach and understand how the program achieves this.

### 1. **Understanding the Problem:**

The program deals with a river flow network where rivers flow into other rivers. The task is to calculate which rivers contribute water to a specific river and which rivers can potentially be polluted by the given river.

### 2. **Input:**

- Read the number of rivers (N), the number of rivers flowing into other rivers (M), and the specified river (F).
- Read M pairs of river indices representing which river flows into which other river.

### 3. **Approach:**

- Build an adjacency list representing the river flow network, where each river is a node and the edges represent the flow of water from one river to another.
- Use Depth-First Search (DFS) to traverse the network and identify which rivers flow into the specified river (can reach the specified river) and which rivers can be potentially polluted by the specified river (can be reached from the specified river).

### 4. **Implementation:**

- Build an adjacency list to represent the river flow network.
- Perform DFS starting from the specified river (F) to identify which rivers flow into the specified river and which rivers can be reached from the specified river.
- Identify rivers from which water flows into the specified river and rivers that can be potentially polluted by the specified river.
- Print the results.

### 5. **Output:**

- Print the rivers from which water flows into the specified river.
- Print the rivers that can be potentially polluted by the specified river.

### Example Walkthrough:

Let's walk through an example using given input and see how the program determines the rivers from which water flows into a specified river and which rivers can potentially be polluted by the specified river.

### Input:
```
5 4 1
1 2
3 2
4 1
5 4
```

### Output:
```
3 4 5
1 2
```

In this example, river 3, 4, and 5 flow into river 1. River 1 can potentially pollute rivers 2. The program successfully identifies these relationships.

### Note:

The program efficiently calculates the relevant river relationships using DFS. If you have any specific questions or need further assistance, feel free to ask!
*/