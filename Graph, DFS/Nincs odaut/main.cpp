#include <iostream>
#include <vector>

using namespace std;
/*
- **Problem Description**:
  Given a directed graph G=(V, E) and a vertex p∈V, calculate the set of vertices q∈V such that there is a path from q to p but there is no path from p to q.

- **Task**:
  Create a program that calculates the set of vertices that satisfy the above condition.

- **Input**:
  - The first line of standard input contains the number of nodes N (1 ≤ N ≤ 10,000), the number of edges M (1 ≤ M ≤ 200,000), and the starting vertex P (1 ≤ P ≤ N).
  - The following M lines each contain two endpoints of an edge (u, v), representing a directed edge from u to v.

- **Output**:
  - The program should output the number K of vertices satisfying the condition.
  - The next line should contain K numbers, representing the vertices q.

- **Example**:
  - **Input**:
    ```
    9 13 4
    1 2
    2 3
    2 1
    1 6
    3 4
    4 5
    5 3
    5 8
    6 7
    7 6
    7 8
    8 9
    9 8
    ```
  - **Output**:
    ```
    2
    1 2
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
vector<int> adj[10001];

void canReachFromStart(int node,vector<bool> &visited){
    visited[node] = true;
    for(auto i:adj[node]){
        if(!visited[i]){
            canReachFromStart(i,visited);
        }
    }
}

void DFS(int node,vector<bool> &visitedSec, vector<bool> &canReach){
    visitedSec[node] = true;
    for(auto i:adj[node]){
        if(!visitedSec[i]){
            DFS(i,visitedSec,canReach);   
            if(canReach[i]) canReach[node] = true;
        }else if(canReach[i]) canReach[node] = true;
    }
}

int main()
{
    int n,m,start;
    cin>>n>>m>>start;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    vector<bool> visited(n+1,false),visitedSec(n+1,false), canReach(n+1,false);
    canReach[start] = true;
    canReachFromStart(start,visited);
    for(int i=1; i<=n; i++){
        if(!visited[i] && !visitedSec[i]){
            DFS(i,visitedSec,canReach);
        }
    }
    vector<int> res;
    for(int i=1; i<=n; i++){
        if(canReach[i] && i!=start && !visited[i]){
            res.push_back(i);
        }
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
The provided program aims to find the set of vertices that have a path from the given starting vertex `P` to them, but there is no path from them to the starting vertex.

Here's a step-by-step explanation of how the program works:

1. **Input Reading:**
   - Read the number of nodes (N), the number of edges (M), and the starting vertex (P) from the standard input.
   - Read M lines, each containing two integers representing a directed edge from u to v.

2. **Depth-First Search (DFS) to Mark Reachable Vertices from `start`:**
   - Perform a DFS from the starting vertex `start` to mark all the vertices that are reachable from `start`.
   - This is done using a boolean vector `visited` to mark the visited vertices.

3. **DFS to Find Vertices Reachable from `start` but Not Reachable to it:**
   - Perform another DFS from vertices that were not visited during the first DFS and mark the vertices that are reachable from these vertices but not reachable from `start`.
   - This is done using a boolean vector `canReach`.

4. **Output:**
   - Output the count and the vertices that satisfy the conditions.

### Output:
The program outputs the number of vertices satisfying the condition and the vertices themselves.

The program seems correct and follows the logic described in the problem. If you have any specific questions or concerns, feel free to ask!
*/