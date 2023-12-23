#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
"Tom és Jerry 1" (Tom and Jerry 1):

In this problem, we are given a maze with nodes connected by paths of varying widths (1 or 2) that Tom the cat and Jerry the mouse navigate through. Jerry can move in both 1-width and 2-width paths, while Tom can only move in 2-width paths. The objective is for Jerry to reach a mouse hole without being caught by Tom.

- **Input**:
  - The input consists of:
    - The number of nodes (`N`).
    - The number of paths (`M`).
    - Tom's initial position (`T`).
    - The number of Jerry's attempts (`P`).
    - The position of the mouse hole (`E`).
    - For each of the `M` paths:
      - The indices of the two nodes it connects (`Ai`, `Bi`).
      - The width of the path (`Si`), either 1 or 2.
    - For each of Jerry's `P` attempts:
      - Jerry's starting position (`Ki`).

- **Output**:
  - For each of Jerry's attempts, the program needs to determine whether Jerry can reach the mouse hole without being caught by Tom. 
  - Output "IGEN" (YES) if Jerry can reach the mouse hole safely, or "NEM" (NO) if not.

- **Example**:
  - **Input**:
    ```
    9 11 6 3 1
    1 2 1
    1 3 1
    2 4 1
    3 4 2
    3 5 2
    4 7 1
    7 5 1
    5 6 2
    5 8 1
    7 9 1
    8 9 1
    7
    8
    9
    ```
  - **Output**:
    ```
    IGEN
    NEM
    IGEN
    ```
  - **Explanation**: In the given maze and starting positions for Jerry, he can reach the mouse hole without being caught by Tom in the first and third attempts, but not in the second attempt.

- **Constraints**:
  - The constraints include limits on the number of nodes, paths, and Jerry's attempts, ensuring feasible computation within a reasonable time.
*/
#define INF 10000000
int n,m,tomPos,k,endNode;
vector< pair<int,int> > adj[100001];

void BFSforTom(vector<int>&disForTom){
    vector<bool> visited(n+1,false);
    disForTom[tomPos] = 0;
    visited[tomPos] = true;
    queue<int> q;
    q.push(tomPos);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i.first] && i.second == 2){
                visited[i.first] = true;
                q.push(i.first);
                disForTom[i.first] = disForTom[node] + 1;
            }
        }
    }
}

void canReach(vector<int>&disForJerry,vector<int>&disForTom){
    disForJerry[endNode] = disForTom[endNode];
    queue<int> q;
    q.push(endNode);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(disForTom[i.first]!=INF && disForJerry[node]==INF) {
                disForJerry[i.first] = disForTom[i.first] - 1;
                q.push(i.first);
            }
            else if(disForJerry[i.first] < disForJerry[node] - 1){
                if(disForJerry[node] == INF) disForJerry[i.first] = INF;
                else disForJerry[i.first] = min(disForJerry[node] - 1, disForTom[i.first] - 1);
                q.push(i.first);
            }
        }
    }
}

int main()
{
    
    cin>>n>>m>>tomPos>>k>>endNode;
    for(int i=1; i<=m; i++){
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }    
    vector<int> disForTom(n+1,INF);
    vector<int> disForJerry(n+1,-1);
    BFSforTom(disForTom);
    canReach(disForJerry,disForTom);
    for(int i=1; i<=k; i++){
        int x;
        cin>>x;
        if(disForJerry[x]!=-1) cout<<"IGEN"<<'\n';
        else cout<<"NEM"<<'\n';
    }
    return 0;
}
/*
### Problem Overview
In this problem, we are dealing with a maze where Tom (the cat) and Jerry (the mouse) need to navigate. Jerry aims to reach a mouse hole without being caught by Tom.

### Graph Representation
The maze is represented as a graph where each node represents a position in the maze, and edges represent paths between the positions. Each edge has a width of either 1 or 2.

### BFS for Tom
1. **BFS to Calculate Distances for Tom (2-width paths only)**
   - First, the program performs a Breadth-First Search (BFS) from Tom's starting position, considering only the 2-width paths. This BFS calculates the shortest distances Tom can travel to each node using only 2-width paths.

### Jerry's Reachability
2. **Checking Jerry's Reachability**
   - Next, the program calculates whether Jerry can reach each node without being caught by Tom.
   - For each node:
     - If Tom can't reach the node, then Jerry can reach it.
     - If Tom can reach the node within one step and Jerry can also reach it within one step, then Jerry can't reach it (Tom can catch Jerry in one step).

### Output
3. **Output based on Jerry's Reachability**
   - Finally, for each of Jerry's attempts, the program outputs "IGEN" (YES) if Jerry can reach the mouse hole without being caught by Tom, or "NEM" (NO) if not.

### Example
Let's walk through the provided example:
- There are 13 nodes and 16 paths in the maze.
- Tom starts at position 6, and the mouse hole is at position 1.
- Jerry has 3 attempts starting at positions 7, 8, and 9.

The program calculates and outputs whether Jerry can reach the mouse hole safely for each attempt.

### Time Complexity
- The BFS for Tom takes O(M) time, where M is the number of edges (paths) in the maze.
- Checking Jerry's reachability also takes O(M) time.
- For each attempt, the output step takes O(1) time.
- So, the overall time complexity for the given problem is O(M).

This approach is efficient and ensures that Jerry can reach the mouse hole safely without being caught by Tom, considering the maze's structure and the path widths.
*/