#include <iostream>
#include <vector>

using namespace std;

/*
**Problem Summary:**

A company is planning to build a warehouse in one of the towns. The towns are connected by roads, and the amount of goods that can be transported on each road per day is known. The production capacity of goods for each town is also known. The goal is to determine the size of the warehouse needed in order to handle the maximum possible amount of goods transported from the production towns to the warehouse in one day.

**Input:**

- Number of towns (N), maximum quantity of goods that can be transported on each road per day (M), and the town where the warehouse will be built (R).
- N integers representing the production capacity of goods for each town.
- N-1 pairs of integers, each representing a road between two towns.

**Output:**

- The maximum warehouse size that can handle the transportation of goods from production towns to the warehouse in one day.

**Example:**

**Input:**
```
10 200 2
100 100 50 50 50 100 200 100 50 50
1 2
3 4
4 5
4 2
2 6
6 7
6 8
8 9
10 8
```

**Output:**
```
550
```

---
*/

int n,c,start;
vector<int> adj[1001];

int DFS(int node,vector<bool>&visited,vector<int>w){
    visited[node] = true;
    int curr = 0;
    for(auto i:adj[node]){
        if(!visited[i]){
            curr += DFS(i,visited,w);
        }
    }
    return min(c,curr + w[node]);
}

int main()
{
    cin>>n>>c>>start;
    vector<int> w(n+1,0);
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        w[i] = x;
    }
    for(int i=1; i<n; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> visited(n+1,false);
    visited[start] = true;
    int totalw = w[start];
    for(auto i:adj[start]){
        totalw += DFS(i,visited,w);
    }
    cout<<totalw;
    return 0;
}
/*
The provided program tackles the problem of determining the maximum warehouse size needed to handle the transportation of goods from production towns to a warehouse in one day. The program utilizes depth-first search (DFS) to traverse the town network, compute the amount of goods that can be transported to the warehouse, and then calculate the required warehouse size.

Here's a more detailed explanation of the approach and the implementation:

### Approach:

1. **Graph Representation:**
   - The program models the towns and roads as a graph, where each town is a node and each road is a weighted edge.

2. **DFS to Calculate Transported Goods:**
   - The program performs DFS starting from the warehouse town, calculating the amount of goods that can be transported from production towns to the warehouse.

3. **Warehouse Size Calculation:**
   - The maximum warehouse size needed is determined based on the calculated transported goods and the maximum transport capacity of each road.

### Implementation:

1. **Graph Representation:**
   - The program uses an adjacency list to represent the graph, where each town stores the roads connecting to it.

2. **DFS to Calculate Transported Goods:**
   - The program performs DFS starting from the warehouse town, calculating the amount of goods that can be transported. It keeps track of the goods transported at each node and ensures it does not exceed the transport capacity of roads.

3. **Warehouse Size Calculation:**
   - The maximum warehouse size is computed by adding the production capacity of the warehouse town and the transported goods from the production towns, ensuring it does not exceed the maximum transport capacity.

4. **Output:**
   - The program outputs the maximum warehouse size needed.

### Example Walkthrough:

Let's go through the given example step by step, showing how the program calculates the maximum warehouse size.

### Input:
```
10 200 2
100 100 50 50 50 100 200 100 50 50
1 2
3 4
4 5
4 2
2 6
6 7
6 8
8 9
10 8
```

### Steps:
1. **Graph Representation:**
   - We create a graph based on the input where nodes represent towns and edges represent roads.

2. **DFS to Calculate Transported Goods:**
   - The program performs DFS to calculate the transported goods from production towns to the warehouse.

3. **Warehouse Size Calculation:**
   - The program computes the maximum warehouse size needed based on the transported goods and the maximum transport capacity.

4. **Output:**
   - The program outputs the maximum warehouse size needed.

### Conclusion:

The program effectively determines the maximum warehouse size required to handle the transportation of goods from production towns to the warehouse in one day. It uses DFS traversal and appropriate calculations based on the transport capacities to compute the required warehouse size.

If you have any more specific questions or need further clarification, feel free to ask!
*/