#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
- **Problem Description**:
  Given a directed graph G=(V, E), the task is to calculate the set of vertices that belong to at least one cycle in the graph.

- **Input**:
  - The first line of standard input contains the number of vertices N (1 ≤ N ≤ 10,000) and the number of edges M (1 ≤ M ≤ 200,000).
  - The next M lines each contain a pair of integers u and v, representing a directed edge u → v in the graph (1 ≤ u, v ≤ N).

- **Output**:
  - The program should output the number of vertices K in the resulting set C.
  - The next line should contain K numbers, representing the elements of set C, separated by spaces (in any order).

- **Example**:
  - **Input**:
    ```
    7 10
    1 2
    2 3
    2 1
    3 4
    3 5
    4 6
    6 4
    5 7
    7 6
    4 7
    ```
  - **Output**:
    ```
    5
    1 2 7 6 4
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
vector<int> adj[10001];
vector<int> res;
stack<int> s;

void findSCCs(int node,vector<int> &disc,vector<int> &low,vector<bool> &currStack){
    static int time = 1;
    disc[node] = time;
    low[node] = time;
    currStack[node] = true;
    s.push(node);
    time++;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            findSCCs(i,disc,low,currStack);
            low[node] = min(low[i],low[node]);
        } else if(currStack[i]){
            low[node] = min(low[node],disc[i]);
        }
    }
    if(low[node] == disc[node]){
        bool partOfCycle = false;
        if(s.top() != node){
            partOfCycle = true;
        }
        while(s.top()!=node){
            if(partOfCycle) res.push_back(s.top());
            currStack[s.top()] = false;
            s.pop();
        }
        if(partOfCycle) res.push_back(s.top());
        currStack[s.top()] = false;
        s.pop();
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> disc(n+1,0), low(n+1,0);
    vector<bool> currStack(n+1,false);
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    for(int i=1; i<=n; i++){
        if(disc[i] == 0) findSCCs(i,disc,low,currStack);
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
The problem "Finding Vertices in Cycles" requires identifying the set of vertices that belong to at least one cycle in a given directed graph.

The provided C++ code correctly addresses this problem. Here's a summary of the approach and the code:

1. **Input Reading**:
   - The program reads the number of vertices (N) and edges (M), followed by M pairs of integers representing directed edges.

2. **Depth-First Search (DFS) for Strongly Connected Components (SCCs)**:
   - The code uses DFS to find strongly connected components (SCCs) in the given directed graph. SCCs are sets of vertices in which there is a directed path between every pair of vertices.
   - The `findSCCs` function implements the DFS to find SCCs and identify vertices belonging to cycles.

3. **Output**:
   - The program outputs the number of vertices (K) in the resulting set of vertices that are part of at least one cycle.
   - It then prints the K vertices in the set.

4. **Example**:
   - For the given example input, the output correctly identifies the vertices (1, 2, 4, 6, 7) that are part of cycles.

The code is efficient and correctly solves the problem of finding vertices in cycles within the directed graph.

*/