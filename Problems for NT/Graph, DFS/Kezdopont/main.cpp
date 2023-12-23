#include <iostream>
#include <vector>
#include <stack>

using namespace std;
/*
Here's a summary of the problem "Kezdőpont" (Starting Point):

- **Problem Description**:
  The task involves a computer network with nodes connected by one-way data transmission lines. The operators of the network want to expand it in a way that there is at least one node from which every other node is reachable. The goal is to determine the minimum number of new direct connections needed to achieve this.

- **Input**:
  - The first line of standard input contains the number of nodes N (1 ≤ N ≤ 500) and the number of existing direct connections M (1 ≤ M ≤ 20,000).
  - The following M lines each contain two integers u and v (1 ≤ u ≠ v ≤ N), indicating a direct connection between nodes u and v.

- **Output**:
  - The program should output the node R from which every other node is reachable after the expansion.
  - The next line should contain the number of new direct connections C that need to be established.
  - The following C lines should each contain two integers p and q, indicating a new direct connection from node p to q.

- **Example**:
  - **Input**:
    ```
    11 12
    3 2
    4 3
    1 3
    2 6
    2 4
    6 10
    6 11
    2 11
    5 7
    5 8
    5 4
    7 8
    ```
  - **Output**:
    ```
    9
    2
    9 1
    1 5
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame. The time limit is 0.01 seconds, and the memory limit is 32 MiB.
*/
vector<int> adj[501],res;
stack<int> s;

void SCC(int node, vector<int> &disc,vector<int>&low,vector<int>&inDegree,vector<bool>&onStack){
    static int time = 1;
    disc[node] = time;
    low[node] = time;
    onStack[node] = true;
    s.push(node);
    time++;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            SCC(i,disc,low,inDegree,onStack);
            if(low[i] <= low[node]){
                low[node] = low[i];
                inDegree[i]--;
            }
        } else if(onStack[i]){
            low[node] = min(low[node], disc[i]);
            inDegree[i]--;
        }
    }
    if(low[node] == disc[node]){
        int in = 0;
        while(s.top()!=node){
            in += inDegree[s.top()];
            onStack[s.top()] = false;
            s.pop();
        }
        in += inDegree[s.top()];
        onStack[s.top()] = false;
        s.pop();
        if(in == 0){
            res.push_back(node);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> disc(n+1,0),low(n+1,0),inDegree(n+1,0);
    vector<bool> onStack(n+1,false);
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        inDegree[y]++;
    }
    for(int i=1; i<=n; i++){
        if(disc[i] == 0) SCC(i,disc,low,inDegree,onStack);
    }
    cout<<*res.begin()<<'\n';
    cout<<res.size() - 1<<'\n';
    for(int i=0; i<res.size() - 1; i++){
        cout<<res[i]<<" "<<res[i+1]<<'\n';
    }
    return 0;
}
/*
The provided code is a solution to the "Starting Point" problem, where the task is to expand a computer network in a way that there is at least one node from which every other node is reachable, and determine the minimum number of new direct connections needed to achieve this.

### Approach:

1. **Graph Representation:**
   - Read the number of nodes \(N\) and the number of existing direct connections \(M\).
   - Create an adjacency list to represent the graph. For each existing direct connection, store the edges between nodes.

2. **Strongly Connected Components (SCC):**
   - Use Tarjan's algorithm to find strongly connected components in the graph.
   - Identify the SCCs that have no incoming edges from other SCCs. These SCCs will be the starting points from which every other node is reachable.

3. **Output Result:**
   - Output the starting node from each SCC without incoming edges from other SCCs.
   - Output the number of new direct connections (\(C\)) needed, which is equal to the number of SCCs minus one.
   - For each SCC, output a new direct connection from the ending node of one SCC to the starting node of the next SCC.

### Time Complexity:
- Constructing the graph takes \(O(M)\) time.
- Finding strongly connected components (SCCs) using Tarjan's algorithm takes \(O(N + M)\) time.

### Space Complexity:
- The space complexity is \(O(N + M)\) to store the graph using an adjacency list and auxiliary data structures.

The approach correctly identifies the starting point and the new direct connections needed to make every other node reachable.

*/