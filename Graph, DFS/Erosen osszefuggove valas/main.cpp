#include <iostream>
#include <vector>
#include <stack>

using namespace std;
/*
Here's the summary of the problem "Erősen összefüggővé alakítás" (Converting to Strongly Connected):

- **Problem Description**:
  Given a directed graph G=(V, E) that is semi-connected, meaning there exists a path from any vertex p to q or from q to p. If G is not strongly connected, there exists a pair of vertices u and v such that adding the edge uv makes G strongly connected.

- **Task**:
  Create a program that calculates an edge uv, such that adding this edge makes G strongly connected.

- **Input**:
  - The first line of standard input contains the number of vertices N (1 ≤ N ≤ 10,000) and the number of edges M (1 ≤ M ≤ 200,000).
  - The following M lines each contain two integers p and q (1 ≤ p ≠ q ≤ N) representing a directed edge from p to q.

- **Output**:
  - The program should output a single line with a pair of integers u and v, representing the edge uv that, when added, makes the graph G strongly connected. If G is already strongly connected, output 0 0.

- **Example**:
  - **Input**:
    ```
    10 15
    2 3
    3 6
    6 2
    3 4
    4 2
    4 1
    1 5
    5 10
    10 1
    1 8
    5 7
    7 9
    9 7
    3 7
    8 10
    ```
  - **Output**:
    ```
    7 2
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
vector<int> adj[10001];
stack<int> s;
pair<int,int> res;
void SCC(int node,vector<int>&disc,vector<int>&low,vector<int>&inDegree,vector<int>&outDegree,vector<bool>&onStack){
    static int time = 1;
    disc[node] = time;
    low[node] = time;
    onStack[node] = true;
    s.push(node);
    time++;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            SCC(i,disc,low,inDegree,outDegree,onStack);
            if(low[i] <= low[node]){
                inDegree[i]--;
                outDegree[node]--;
                low[node] = low[i];
            }
        } else if(onStack[i]){
            low[node] = min(low[node],disc[i]);
            inDegree[i]--;
            outDegree[node]--;
        }
    }
    if(disc[node] == low[node]){
        int in = 0;
        int out = 0;
        while(s.top()!=node){
            in += inDegree[s.top()];
            out += outDegree[s.top()];
            onStack[s.top()] = false;
            s.pop();
        }
        in += inDegree[s.top()];
        out += outDegree[s.top()];
        onStack[s.top()] = false;
        s.pop();
        if(out == 0) res.first = node;
        if(in == 0) res.second = node;
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> disc(n+1,0), low(n+1,0), inDegree(n+1,0), outDegree(n+1,0);
    vector<bool> onStack(n+1,0);
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        inDegree[y]++;
        outDegree[x]++;
    }
    for(int i=1; i<=n; i++){
        if(disc[i] == 0) SCC(i,disc,low,inDegree,outDegree,onStack);
    }
    if(res.first == res.second) cout<<0<<" "<<0;
    else cout<<res.first<<" "<<res.second;
    return 0;
}
/*
The given program aims to find an edge (u, v) that, when added to a directed graph, makes the graph strongly connected. The program uses Kosaraju's Algorithm to achieve this.

### Approach:

1. **Input Reading:**
   - Read the number of nodes \(n\) and edges \(m\).
   - Initialize vectors to keep track of discovery time, low value, in-degree, out-degree, and whether a node is on the stack.

2. **Graph Construction and Degree Calculation:**
   - Read the edges from the input and construct the directed graph.
   - Calculate the in-degree and out-degree of each node.

3. **Strongly Connected Component (SCC) Algorithm - Kosaraju's Algorithm:**
   - Iterate through all nodes.
   - For each unvisited node:
     - Call the SCC function to find strongly connected components.

4. **SCC Function (Kosaraju's Algorithm):**
   - Use Kosaraju's Algorithm to find strongly connected components.
   - Traverse the graph in a depth-first search manner, assigning discovery times and low values to nodes.
   - Keep track of nodes in the current SCC using a stack.
   - When identifying a strongly connected component:
     - Calculate in-degree and out-degree sums for the component.
     - Update res.first if the in-degree sum is zero.
     - Update res.second if the out-degree sum is zero.

5. **Output:**
   - Print the results, i.e., the nodes corresponding to the start and end points of the additional edge required to make the graph strongly connected.

### Output:
The program outputs a pair of integers \(u\) and \(v\), representing the edge \(u \to v\) that, when added, makes the graph strongly connected. If the graph is already strongly connected, it outputs "0 0".

### Example:
For the provided input example:
- The program should output "7 2" as adding the edge from node 7 to node 2 will make the graph strongly connected.
*/