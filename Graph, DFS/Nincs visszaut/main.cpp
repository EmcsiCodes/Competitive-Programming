#include <iostream>
#include <vector>

using namespace std;
/*
- **Problem Description**:
  Given a directed graph G=(V, E) and a starting vertex p in V, the task is to find all vertices q in V such that there exists a path from p to q, but there is no path from q to p.

- **Input**:
  - The first line of standard input contains the number of vertices in the graph N (1 ≤ N ≤ 100,000), the number of edges M (1 ≤ M ≤ 1,000,000), and the starting vertex P (1 ≤ P ≤ N).
  - The following M lines each contain two integers u and v (1 ≤ u ≠ v ≤ N), representing an edge from vertex u to vertex v.

- **Output**:
  - The program should output the number of vertices K satisfying the mentioned condition.
  - The next line should list these K vertices separated by a space.

- **Example**:
  - **Input**:
    ```
    9 14 4
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
    3 6
    ```
  - **Output**:
    ```
    4
    6 7 9 8
    ```

- **Constraints**:
  - The computation should be completed within 0.1 seconds.
  - The memory usage should not exceed 32 MiB.
*/
vector<int> adj[100001];

void canReachFromStart(int node,vector<bool> &visited){
    visited[node] = true;
    for(auto i:adj[node]){
        if(!visited[i]){
            canReachFromStart(i,visited);
        }
    }
}

void canReachStart(int node,int start,vector<bool> visited,vector<bool> &visitedSec,vector<bool> &canReach){
    visitedSec[node] = true;
    if(node == start) return;
    //cout<<node<<"->";
    for(auto i:adj[node]){
        //cout<<i<<": ";
        if(!visitedSec[i] && visited[i]){
            canReachStart(i,start,visited,visitedSec,canReach);
            if(canReach[i]) canReach[node] = true;
        } else if(canReach[i]) canReach[node] = true;
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
    vector<bool> visited(n+1,false);
    vector<bool> visitedSec(n+1,false);
    vector<bool> canReach(n+1,false);

    canReachFromStart(start,visited);
    canReach[start] = true;
    for(int i=1; i<=n; i++){
        if(!visitedSec[i] && visited[i] && i!=start){
            canReachStart(i,start,visited,visitedSec,canReach);
        }
    }
    vector<int> res;
    for(int i=1; i<=n; i++){
        if(!canReach[i] && visited[i]) res.push_back(i);
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
}
/*
The provided program aims to find vertices q in a directed graph such that there exists a path from a given starting vertex p to q, but there is no path from q to p.

Here's a step-by-step explanation of how the program works:

1. **Input Reading:**
   - Read the number of vertices (N), the number of edges (M), and the starting vertex (P) from the standard input.
   - Read M lines, each containing two integers representing a directed edge from u to v.

2. **DFS to Mark Vertices Reachable from `start`:**
   - Perform a DFS from the starting vertex `start` to mark all the vertices that are reachable from `start`.
   - This is done using a boolean vector `visited`.

3. **DFS to Find Vertices Reachable from `start` but Not Reachable to it:**
   - Perform another DFS from vertices that were not visited during the first DFS and mark the vertices that are reachable from these vertices but not reachable from `start`.
   - This is done using a boolean vector `canReach`.

4. **Output:**
   - Output the count and the vertices that satisfy the conditions.

### Output:
The program outputs the number of vertices satisfying the condition and the vertices themselves.

The program seems correct and follows the logic described in the problem. If you have any specific questions or concerns, feel free to ask!
*/