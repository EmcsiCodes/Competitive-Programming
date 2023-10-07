#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
**Problem Summary:**

Bergengócia's railway network ensures a unique path from any city to another. Trains depart from the capital (city 1) and travel to a city where the railway ends. The length of a train route between two cities is the number of railway stations between them plus one.

Write a program that determines the longest direct train route without any branching in the railway network.

**Input:**

- The first line contains the number of cities (N) in the railway network (2 ≤ N ≤ 10,000).
- The next N-1 lines describe the railway sections, where each line contains two integers A and B (1 ≤ A ≠ B ≤ N), indicating a direct railway connection from city A to city B.

**Output:**

- Print the length of the longest direct train route without any branching.

**Example:**

**Input:**
```
11
1 2
1 3
2 4
2 5
1 9
3 6
5 7
7 8
8 10
8 11
```

**Output:**
```
3
```

---
*/
vector<int> adj[10001];

int BFS(int start,int n,vector<bool>valid,vector<bool>&visited){
    queue<int> q;
    int num = 0;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                num++;
                if(valid[i]) q.push(i);
            } else if(!valid[i]) num++;
        }
    }
    return num;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<n; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> valid(n+1,true), visited(n+1,false);
    for(int i=1; i<=n; i++){
        if(adj[i].size()>2) valid[i] = false;
    }
    int res = 1;
    for(int i=1; i<=n; i++){
        if(!visited[i] && valid[i]) res = max(res, BFS(i,n,valid,visited));
    }
    cout<<res;
    return 0;
}
/*
The provided program solves the problem of determining the longest direct train route without any branching in the railway network of Bergengócia. The algorithm uses a breadth-first search (BFS) approach to traverse the railway network and calculate the longest direct train route.

Here's a breakdown of the approach and the implementation:

### Approach:

1. **Graph Representation:**
   - The program represents the railway network as a graph, where each city is a node, and direct railway connections are represented as edges.

2. **BFS and Validity Check:**
   - The program performs a BFS traversal, starting from each city, to determine the longest direct train route without any branching.
   - During the BFS traversal, the program checks the validity of each city based on the number of direct connections. If a city has more than two direct connections, it's considered invalid.

3. **Output:**
   - The program outputs the length of the longest direct train route without any branching.

### Implementation:

1. **Graph Representation:**
   - The program uses an adjacency list to represent the graph, where each city stores its direct railway connections.

2. **BFS and Validity Check:**
   - The program performs BFS traversal from each city to calculate the longest direct train route without branching.
   - During the BFS traversal, it also checks the validity of cities based on the number of direct connections.

3. **Output:**
   - The program outputs the length of the longest direct train route without any branching.

### Example Walkthrough:

Let's go through the given example step by step, showing how the program calculates the longest direct train route without any branching.

### Input:
```
11
1 2
1 3
2 4
2 5
1 9
3 6
5 7
7 8
8 10
8 11
```

### Steps:
1. **Graph Representation:**
   - The program represents the railway network as a graph using an adjacency list.

2. **BFS and Validity Check:**
   - The program performs BFS traversal from each city, calculating the longest direct train route without branching and checking city validity based on direct connections.

3. **Output:**
   - The program outputs the length of the longest direct train route without any branching.

### Conclusion:

The program effectively calculates the longest direct train route without any branching in the given railway network of Bergengócia.

If you have any more specific questions or need further clarification, feel free to ask!
*/