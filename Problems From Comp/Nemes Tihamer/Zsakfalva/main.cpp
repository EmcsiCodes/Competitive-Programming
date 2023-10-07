#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
**Problem Summary:**

Given a road network connecting villages in a county, identify the villages that act as dead-ends (only one road leading in or out) and from which, when starting, you can pass through the maximum number of villages where you can only continue on a single new road.

**Input:**

- Number of villages (N) and the number of roads (M).
- M lines, each containing the indices of two villages connected by a road.

**Output:**

- The length of the longest path that starts from a dead-end village and can only continue on new roads.
- The indices of the dead-end villages that allow for the longest such paths.

**Example:**

- **Input:**
  ```
  10 10
  1 2
  2 3
  3 4
  4 5
  5 6
  5 7
  3 7
  7 8
  8 9
  10 9
  ```

- **Output:**
  ```
  3
  10
  ```

In this case, starting from village 10, we can pass through the most villages where we only have a single new road to choose.


*/

vector<int> adj[50000];

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> degree(n+1,0);
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        degree[x]++;
        degree[y]++;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue< pair<int, pair<int,int> > > q;
    vector<bool> visited(n+1,false);
    for(int i=1; i<=n; i++){
        if(degree[i] == 1){
            q.push({i,{i,1}});
            visited[i] = true;
        }
    }
    if(q.empty()) {
        cout<<-1;
        return 0;
    }
    while(!q.empty()){
        pair<int, pair<int,int> > node = q.front();
        q.pop();
        for(auto i:adj[node.first]){
            if(!visited[i] && degree[i] <= 2){
                q.push({i,{node.second.first,node.second.second+1}});
                visited[i] = true;
            }
        }
        if(q.empty()) {
            cout<<node.second.second<<'\n'<<node.second.first;
        }
    }
    return 0;
}
/*
This program determines the length of the longest path that starts from a dead-end village and can only continue on new roads, as well as the indices of the dead-end villages that allow for these longest paths.

Let's break down the approach step by step:

### 1. Input Processing:

- Read the number of villages (`n`) and the number of roads (`m`).
- Create an adjacency list representation of the road network and keep track of the degrees of each village (how many roads connect to it).

### 2. Identify Dead-End Villages:

- Iterate through the roads, incrementing the degrees of the connected villages.
- Identify the dead-end villages (those with a degree of 1) and mark them as visited.

### 3. BFS to Find Longest Paths:

- Perform Breadth-First Search (BFS) starting from the dead-end villages.
- While traversing through the network, keep track of the maximum path length and the corresponding dead-end village.

### 4. Output the Result:

- Print the length of the longest path and the index of the dead-end village where the longest path was found.

### Example Walkthrough:

Let's use the provided example and follow the algorithm's steps:

- **Input:**
  ```
  10 10
  1 2
  2 3
  3 4
  4 5
  5 6
  5 7
  3 7
  7 8
  8 9
  10 9
  ```

- **Identify Dead-End Villages:**
  - Villages 1, 6, and 10 are dead-end villages as they have a degree of 1.

- **BFS to Find Longest Paths:**
  - Perform BFS starting from each dead-end village.
  - The longest path starts from village 10 and has a length of 3.

- **Output:**
  ```
  3
  10
  ```

This means that the longest path starting from a dead-end village is 3 units long, starting from village 10.

The program efficiently identifies the longest paths and the corresponding starting dead-end villages.
*/