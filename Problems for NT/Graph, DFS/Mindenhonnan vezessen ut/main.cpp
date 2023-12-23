#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
- **Problem Description**:
  Given a directed graph, calculate the minimum number of new edges needed in the graph to ensure that there exists a set of R vertices such that there is a path from every vertex to at least one vertex in R.

- **Task**:
  Create a program that calculates the minimum number of new edges and the set of R vertices that achieves the above condition.

- **Input**:
  - The first line of standard input contains the number of nodes N (1 ≤ N ≤ 100,000) and the number of edges M (1 ≤ M ≤ 200,000).
  - The following M lines each contain two endpoints of an edge (u, v), representing a directed edge from u to v.

- **Output**:
  - The program should output the smallest number K, which represents the minimum number of new edges required.
  - The next line should contain the count R, representing the number of vertices in the set R.
  - The following K lines should each contain the two endpoints of a new edge to be added.

- **Example**:
  - **Input**:
    ```
    9 11
    1 2
    2 3
    2 1
    3 4
    4 5
    5 3
    6 7
    7 6
    8 3
    8 9
    9 8
    ```
  - **Output**:
    ```
    1
    7
    3 7
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
vector<int> outNull;
vector<int> adj[100001];
stack<int> s;

void SCC(int node,vector<int> &disc,vector<int> &low,vector<bool> &currStack, vector<int> &outDegrees){
    static int time = 1;
    currStack[node] = true;
    disc[node] = time;
    low[node] = time;
    s.push(node);
    time++;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            SCC(i,disc,low,currStack,outDegrees);
            if(low[i] <= low[node]){
                low[node] = low[i];
                outDegrees[node]--;
            } 
        } else if(currStack[i]){
            low[node] = min(low[node],disc[i]);
            outDegrees[node]--;
        }
    }
    if(low[node] == disc[node]){
        int out = 0;
        while(s.top()!=node){
            out += outDegrees[s.top()];
            currStack[s.top()] = false;
            s.pop();
        }
        out += outDegrees[s.top()];
        currStack[s.top()] = false;
        s.pop();
        if(out == 0) {
            outNull.push_back(node);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> disc(n+1,0), low(n+1,0), outDegrees(n+1,0);
    vector<bool> currStack(n+1,false);
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        outDegrees[x]++;
    }
    for(int i=1; i<=n; i++){
        if(disc[i] == 0) {
            SCC(i,disc,low,currStack,outDegrees);
            
        }
    }
    cout<<outNull.size()-1<<'\n';
    cout<<*outNull.rbegin()<<'\n';
    for(int i=0; i<outNull.size()-1; i++){
        cout<<outNull[i]<<" "<<outNull[i+1]<<'\n';
    }
    return 0;
}
/*
The given C++ program solves the problem of calculating the minimum number of new edges needed in a directed graph to ensure that there exists a set of R vertices such that there is a path from every vertex to at least one vertex in R.

Here's a step-by-step breakdown of the program:

### Program Approach:

1. **Input Reading:**
   - Read the number of nodes (N) and the number of edges (M) from the standard input.
   - Read M lines, each containing two endpoints of an edge (u, v), representing a directed edge from u to v.

2. **Strongly Connected Components (SCC):**
   - Use the Kosaraju's algorithm to find the strongly connected components in the graph.

3. **Finding the Best Spot for New Edges:**
   - For each strongly connected component, if it doesn't have any outgoing edges (out-degree = 0), add a new edge from this component to the component with the highest out-degree among all such components.
   - Output the smallest number K, which represents the minimum number of new edges required.
   - Output the count R, representing the number of vertices in the set R.
   - Output the endpoints of the new edges to be added.

### Output:
The program outputs the smallest number K, which represents the minimum number of new edges required. It then outputs the count R, representing the number of vertices in the set R. Finally, it outputs the endpoints of the new edges to be added.

The program aims to determine the minimum number of new edges needed in the graph to ensure that there exists a set of R vertices such that there is a path from every vertex to at least one vertex in R.
*/