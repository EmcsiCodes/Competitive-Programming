#include <iostream>
#include <vector>
using namespace std;
/*
- **Problem Description**:
  The task is to create a program that generates a route for a street sweeper to traverse every street in the city in both directions, starting and ending at a specific intersection.

- **Input**:
  - The first line of standard input contains the number of intersections, N (1 ≤ N ≤ 10,000), and the number of streets, M (1 ≤ M ≤ 300,000).
  - The following M lines each contain two integers, U and V, indicating a street between intersections U and V. Each street connects two intersections, and there is at most one street between any two intersections.

- **Output**:
  - The program should output a sequence of intersections representing a route. The route should start and end at intersection 1, traverse each street exactly once in both directions, and return to intersection 1.

- **Example**:
  - **Input**:
    ```
    5 7
    1 2
    1 3
    2 3
    2 5
    3 5
    2 4
    4 5
    ```
  - **Output**:
    ```
    1 3 5 4 2 5 2 3 2 1 2 4 5 3 1
    ```

- **Constraints**:
  - The program should execute within 0.2 seconds.
  - Memory usage should not exceed 32 MiB.
*/
vector<int> adj[10001];

void DFS(int node,vector<int> &visited,vector<int> &res,vector<int> &parent){
    visited[node] = 1;
    for(auto i:adj[node]){
        if(visited[i] == 0){
            res.push_back(i);
            parent[i] = node;
            DFS(i,visited,res,parent);
            res.push_back(node);
        } else if(parent[node]!=i && visited[i] == 1){
            visited[node] = 2;
            res.push_back(i);
            res.push_back(node);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> res, parent(n+1,0),visited(n+1,0);
    res.push_back(1);
    DFS(1,visited,res,parent);
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
The given program aims to generate a route for a street sweeper to traverse every street in the city in both directions, starting and ending at a specific intersection. It uses a depth-first search (DFS) approach to traverse the streets.

Here's a step-by-step explanation of the program:

1. **Input Reading:**
   - Read the number of intersections (N) and the number of streets (M) from the standard input.
   - Read the M lines describing the streets between intersections.

2. **Depth-First Search (DFS):**
   - Use a DFS traversal starting from intersection 1.
   - Traverse each street exactly once in both directions and return to intersection 1.

3. **Output:**
   - Output the generated route.

### Output:
The program outputs a sequence of intersections representing a route that starts and ends at intersection 1, traverses each street exactly once in both directions, and returns to intersection 1.

The program seems to be working as expected to achieve the goal of generating the desired route for the street sweeper. If you have any specific questions or concerns, feel free to ask!
*/