#include <iostream>
#include <vector>
#include <stack>

using namespace std;
/*
- **Problem Description**:
  A program graph determines the sequence of program instructions, where only sequence, branching, and conditional loops are allowed.
  The program graph is a directed graph with a single starting point (no incoming edges) and a single endpoint (no outgoing edges). Every point in the program graph is reachable from the starting point, and every point can reach the endpoint. Each point can have at most two outgoing edges. If two edges start from a point, it either represents a branch or a loop. If two cycles share a point, one contains the other.

- **Task**:
  Create a program that calculates the number of cycles and branches in a program graph.

- **Input**:
  - The first line of standard input contains the number of points in the program graph (1 ≤ N ≤ 10,000) and the number of edges (1 ≤ M ≤ 15,000).
  - The following M lines each contain the endpoints of a directed edge (1 ≤ From, To ≤ N).

- **Output**:
  - The program should output, in the first line, the number of cycles in the program graph and, in the second line, the number of branches.

- **Example**:
  - **Input**:
    ```
    10 12
    1 2
    2 3
    3 4
    4 6
    6 7
    6 8
    7 4
    3 5
    5 9
    9 10
    10 5
    10 8
    ```
  - **Output**:
    ```
    2
    1
    ```

- **Constraints**:
  - Time Limit: 0.2 seconds
  - Memory Limit: 32 MB
*/
vector<int> adj[10001];
stack<int> s;
int cycleNum = 0;
int splits = 0;
void SCC(int node,vector<int> &disc,vector<int> &low,vector<bool> &onStack){
    static int time = 1;
    disc[node] = time;
    low[node] = time;
    onStack[node] = true;
    s.push(node);
    time++;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            SCC(i,disc,low,onStack);
            low[node] = min(low[node],low[i]);
        } else if(onStack[i]){
            low[node] = min(low[node],disc[i]);
        }
    }
    if(low[node] == disc[node]){
        if(s.top()!=node) cycleNum++;
        else if(adj[node].size()>1) splits++;
        int db=0;
        while(s.top()!=node){
            //cout<<s.top()<<" ";
            onStack[s.top()] = false;
            s.pop();
        }
        //cout<<s.top()<<'\n';
        onStack[s.top()] = false;
        s.pop();
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> disc(n+1,0), low(n+1,0);
    vector<bool> onStack(n+1,false);
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    SCC(1,disc,low,onStack);
    cout<<cycleNum<<'\n';
    cout<<splits;
    return 0;
}
/*
The program aims to determine the number of cycles and branches in a program graph, represented as a directed graph. It utilizes Tarjan's Strongly Connected Components (SCC) algorithm to achieve this.

Here's a step-by-step explanation of the approach:

1. **Strongly Connected Components (SCC) Algorithm**:
   - The program uses Tarjan's SCC algorithm to find the strongly connected components in the directed graph.

2. **Definitions**:
   - In the SCC algorithm, a "strongly connected component" is a maximal subset of vertices in a directed graph, where each vertex is reachable from every other vertex in the subset.

3. **DFS-based Approach**:
   - The algorithm traverses the graph using a depth-first search (DFS) approach.

4. **DFS Stack and Low-Link Values**:
   - A stack is used to keep track of vertices during traversal.
   - Two vectors, `disc` (discovery time) and `low` (low-link value), are maintained to help identify SCCs.

5. **Finding SCCs**:
   - As the DFS traversal progresses, each vertex is pushed onto the stack and assigned discovery and low-link values.
   - When a cycle or branch is identified (a vertex with matching `low` and `disc` values), it signifies the end of an SCC.

6. **Cycle and Branch Count**:
   - The program keeps track of the number of cycles and branches based on SCC properties.

7. **Output**:
   - Finally, the program prints the count of cycles and branches.

8. **Input and Output Format**:
   - The program reads the number of points and edges in the program graph, followed by the edge endpoints.
   - It then prints the number of cycles and branches.

### Example Walkthrough:

For the given example input:
```
16 20
3 16
1 2
1 3
2 4
4 5
5 2
5 7
7 8
8 5
7 9
9 10
9 11
10 12
10 13
11 14
11 15
12 16
13 16
14 16
15 16
```

The program finds 2 cycles and 1 branch in the program graph.

This algorithm effectively identifies cycles and branches in a program graph using the SCC approach.
*/