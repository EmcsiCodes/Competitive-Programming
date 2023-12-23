#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
- **Problem Description**:
  A program graph defines the order of instructions in a program, where only sequence, branching, and conditional loops are allowed. The program graph is a directed graph with a single start point (with no incoming edges) and a single endpoint (with no outgoing edges). Each point in the program graph is reachable from the starting point, and every point can reach the endpoint. Each point can have at most two outgoing edges. If there are two edges, they represent either branching or looping. If two loops have a common point, one contains the other.

- **Task**:
  Create a program that determines the number of cycles and branches in a program graph.

- **Input**:
  - The first line of standard input contains the number of points in the program graph N (1 ≤ N ≤ 10,000) and the number of edges M (1 ≤ M ≤ 15,000).
  - The following M lines each contain two endpoints of a directed edge (1 ≤ From, To ≤ N).

- **Output**:
  - The program should output the number of cycles in the program graph on the first line and the number of branches on the second line.

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
  - The computation should be completed within 0.2 seconds.
  - The memory usage should not exceed 32 MiB.
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
The provided program addresses the problem of determining the number of cycles and branches in a program graph. It uses Tarjan's algorithm for finding strongly connected components (SCCs) to identify cycles and branches.

Here's a step-by-step explanation of how the program works:

1. **Input Reading:**
   - Read the number of points in the program graph (N) and the number of edges (M) from the standard input.
   - Read M lines, each containing two integers representing a directed edge from one point to another.

2. **Strongly Connected Components (SCC):**
   - Utilize Tarjan's algorithm to find SCCs in the directed graph.
   - During this process, count the number of cycles and branches based on the SCCs.

3. **Identify Cycles and Branches:**
   - A cycle is identified by an SCC that is not a single-node SCC.
   - A branch is identified by a single-node SCC that has more than one outgoing edge.

4. **Output:**
   - Output the number of cycles and branches identified.

### Output:
The program outputs the number of cycles and the number of branches in the program graph.

The program seems to be correctly identifying the cycles and branches in the program graph based on SCCs. If you have any specific questions or concerns, feel free to ask!
*/