#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

/*
- **Problem Description**:
  A computer network contains direct bidirectional data transfer connections between certain pairs of computers. The network allows communication between any two computers, possibly through other computers. However, there might be critical connections between two computers such that if they fail, any computer cannot reach any other.

- **Task**:
  Create a program that determines two computers between which,
  when a direct connection is severed, the number of critical connections is minimized.

- **Input**:
  - The first line of standard input contains the number of computers N (2 ≤ N ≤ 10,000) and the number of connections M (1 ≤ M ≤ 100,000).
  - The following M lines each contain two computer numbers A and B (1 ≤ A ≠ B ≤ N), representing a connection between computers A and B.

- **Output**:
  - The program should output one line containing the numbers of two computers, such that when a direct connection between them is severed, the number of critical connections is minimized.

- **Example**:
  - **Input**:
    ```
    8 8
    1 2
    1 3
    2 4
    2 5
    6 3
    7 3
    8 5
    4 5
    ```
  - **Output**:
    ```
    7 8
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/

vector<int> adj[10001];
set< pair<int,int> > bridges;
void makeThreeFromBridges(int node,vector<int>&disc,vector<int>&low,vector<int>&parent){
    static int time = 1;
    disc[node] = time;
    low[node] = time;
    time++;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            parent[node] = i;
            makeThreeFromBridges(i,disc,low,parent);
            low[node] = min(low[node],low[i]);
            if(low[i] > disc[node]){
                bridges.insert({node,i});
                bridges.insert({i,node});
            }
        } else if(parent[i]!=node){
            low[node] = min(disc[i],low[node]);
        }
    }
}

int BFS(int start,int n){
    vector<bool> visited(n+1,false);
    vector<int> dis(n+1,0);
    visited[start] = true;
    queue<int> q;
    int p;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                if(bridges.find({i,node})!=bridges.end() || bridges.find({node,i})!=bridges.end()) p = 1;
                else p = 0;
                dis[i] = dis[node] + p;        
                visited[i] = true;
                q.push(i);
            }
        }
    }
    int maxDis = 0;
    int maxDisIndex = 0;
    for(int i=1; i<=n; i++){
        if(maxDis < dis[i]){
            maxDis = dis[i];
            maxDisIndex = i;
        }
    }
    return maxDisIndex;
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
    vector<int> disc(n+1,0), low(n+1,0), parent(n+1,0);
    makeThreeFromBridges(1,disc,low,parent);
    int res = BFS(1,n);
    cout<<res<<" "<<BFS(res,n);
    return 0;
}
/*
Let's break down the approach of the program step by step.

### Program Approach: Finding Critical Connections

1. **Input Reading**:
   - Read the number of computers (N) and the number of connections (M) from the standard input.
   - Read M lines, each containing two computer numbers A and B, representing a connection between computers A and B.

2. **Finding Bridges**:
   - Use Tarjan's algorithm to find the bridges in the given network.
   - The `makeThreeFromBridges` function identifies the bridges in the network using Tarjan's algorithm and stores them.

3. **Breadth-First Search (BFS)**:
   - Use BFS to determine the critical connections.
   - The `BFS` function performs a BFS traversal and calculates the number of critical connections for each computer.

4. **Output**:
   - Print two computers, such that when a direct connection between them is severed, the number of critical connections is minimized.

The approach involves using Tarjan's algorithm to find bridges and then performing BFS to determine the optimal computers for minimizing critical connections.

*/