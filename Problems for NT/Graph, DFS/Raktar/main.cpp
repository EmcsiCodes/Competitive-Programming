#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
- **Problem Description**:
  A company operates production units in N cities. These units are supplied with raw materials from a central warehouse located in city R. The task is to find cities (other than R) where raw materials can be transported through exactly one route from the central warehouse.

- **Task**:
  Create a program that determines the cities reachable from the central warehouse through exactly one route.

- **Input**:
  - The first line of standard input contains the number of cities N (1 ≤ N ≤ 10,000), the number of direct routes M (1 ≤ M ≤ 1,000,000), and the serial number of the central warehouse R (1 ≤ R ≤ N).
  - The following M lines each contain two serial numbers of cities directly connected by a route (1 ≤ U ≠ V ≤ N). It's guaranteed that there's at most one direct route between any two cities and that every city can be reached from the central warehouse.

- **Output**:
  - The program should output the number of cities K (other than R) that can be supplied through exactly one route from the central warehouse on the first line.
  - The second line should contain the serial numbers of the cities in any order.

- **Example**:
  - **Input**:
    ```
    11 12 3
    7 8
    3 1
    2 3
    3 4
    4 7
    7 11
    2 6
    1 5
    5 8
    5 9
    9 10
    5 10
    ```
  - **Output**:
    ```
    2
    2 6
    ```

- **Constraints**:
  - The computation should be completed within 0.1 seconds.
  - The memory usage should not exceed 32 MiB.
*/
vector<int> adj[10001];
vector<int> canReach;
void DFS(int node,vector<bool>&visited,vector<bool>&finishBack,vector<int>&parent,vector<bool>&res){
    visited[node] = true;
    for(auto i:adj[node]){
        if(!visited[i]){
            parent[node] = i;
            DFS(i,visited,finishBack,parent,res);
            if(!res[i] && !finishBack[node]){
                res[node] = false;
                return;
            }
            finishBack[node] = false;
        } else if(parent[i]!=node){
            finishBack[i] = true;
            res[node] = false;
            return;
        }
    }
}

void BFS(int start,int n,vector<bool>res){
    queue<int> q;
    vector<bool> visited(n+1,false);
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i] && res[i]){
                canReach.push_back(i);
                q.push(i);
                visited[i] = true;
            }
        }
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
        adj[y].push_back(x);
    }
    vector<bool> visited(n+1,false), finishBack(n+1,false), res(n+1,true);
    vector<int> parent(n+1,0);
    DFS(start,visited,finishBack,parent,res);
    BFS(start,n,res);
    cout<<canReach.size()<<'\n';
    for(auto i:canReach) cout<<i<<" ";
    return 0;
}
/*
The provided program aims to determine the cities reachable from the central warehouse through exactly one route. It uses Depth-First Search (DFS) and Breadth-First Search (BFS) to accomplish this task.

Here's a step-by-step explanation of how the program works:

1. **Input Reading:**
   - Read the number of cities (N), the number of direct routes (M), and the serial number of the central warehouse (R) from the standard input.
   - Read M lines, each containing two serial numbers of cities directly connected by a route.

2. **DFS to Identify Routes:**
   - Use DFS to traverse the graph and identify the routes from the central warehouse.
   - Mark cities that can be reached through exactly one route.

3. **BFS to Traverse the Reachable Cities:**
   - Use BFS to traverse the cities that can be reached through exactly one route from the central warehouse.

4. **Output:**
   - Output the number of cities and their serial numbers that can be supplied through exactly one route from the central warehouse.

### Output:
The program outputs the number of cities and the serial numbers of the cities that can be supplied through exactly one route from the central warehouse.

The program appears to be correctly identifying the cities that can be supplied through exactly one route from the central warehouse. If you have any specific questions or concerns, feel free to ask!
*/