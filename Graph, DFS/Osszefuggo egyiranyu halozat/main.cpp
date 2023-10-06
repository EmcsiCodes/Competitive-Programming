#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <set>
using namespace std;
/*
- **Problem Description**:
  In a computer network, nodes are connected by directed one-way data transmission lines. The network is designed in such a way that data can be transferred from any node (possibly through other nodes) to any other node. This property of the network is called connectivity. Due to a malfunction, two nodes directly connected by a line are now faulty, causing the network to become disconnected.

  The task is to find two nodes, between which a new line can be added, thus restoring connectivity in the network.

- **Input**:
  - The first line of standard input contains the number of nodes N (1 < N ≤ 4000) and the number of functioning lines M (1 < M ≤ 12,000).
  - The following M lines each contain two integers u and v (1 ≤ u ≠ v ≤ N), representing a functioning line connecting node u to node v.

- **Output**:
  - The program should output a pair of node numbers (u, v) representing the two nodes between which a new directed line should be added to restore network connectivity.

- **Example**:
  - **Input**:
    ```
    9 12
    5 6
    6 5
    2 1
    1 3
    3 2
    1 4
    4 2
    3 7
    7 8
    8 9
    9 7
    6 2
    ```
  - **Output**:
    ```
    8 5
    ```

- **Constraints**:
  - The computation should be completed within 0.1 seconds.
  - The memory usage should not exceed 32 MiB.
*/
vector<int> nodes;
unordered_map<int,int> comp;
set<int> subg[4001];
vector<int> adj[4001];
stack<int> s;
void SCC(int node,vector<int>&disc,vector<int>&low,vector<bool>&onStack){
    static int time = 1;
    disc[node] = time;
    low[node] = time;
    onStack[node] = true;
    s.push(node);
    time++;
    for(auto i:adj[node]){
        if(disc[i]==0){
            SCC(i,disc,low,onStack);
            low[node] = min(low[node],low[i]);
        } else if(onStack[i]) low[node] = min(low[node],disc[i]);
    }
    if(disc[node] == low[node]){
        while(s.top()!=node){
            comp[s.top()] = node;
            onStack[s.top()] = false;
            s.pop();
        }
        nodes.push_back(node);
        comp[s.top()] = node;
        onStack[s.top()] = false;
        s.pop();
    }
}

void makeSubGraph(int n){
    vector<int> disc(n+1,0),low(n+1,0);
    vector<bool> onStack(n+1,false);
    for(int i=1; i<=n; i++){
        if(disc[i] == 0) SCC(i,disc,low,onStack);
    }
    for(int i=1; i<=n; i++){
        for(auto j:adj[i]){
            if(comp[i]!=comp[j]) subg[comp[i]].insert(comp[j]);
        }
    }
}

void solve(int n){
    vector<int> inDegree(n+1,0), outDegree(n+1,0);
    for(auto i:nodes){
        for(auto j:subg[i]){
            inDegree[j]++;
            outDegree[i]++;
        }
    }
    int start,end;
    for(auto i:nodes){
        if(outDegree[i] == 0) start = i;
        if(inDegree[i] == 0) end = i;
    }
    cout<<start<<" "<<end;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    makeSubGraph(n);
    solve(n);
    return 0;
}
/*
The provided program addresses the problem of finding two nodes between which a new directed line should be added to restore network connectivity. It utilizes strong connectivity components (SCCs) to identify these nodes.

Here's a step-by-step explanation of how the program works:

1. **Input Reading:**
   - Read the number of nodes (N) and the number of functioning lines (M) from the standard input.
   - Read M lines, each containing two integers representing a functioning line connecting node u to node v.

2. **Strongly Connected Components (SCC):**
   - Utilize Kosaraju's algorithm to find SCCs in the directed graph.
   - During this process, record the nodes in each SCC.

3. **Identify the Nodes for Restoring Connectivity:**
   - Identify the SCCs that have only one outgoing edge and no incoming edge. These represent the SCCs that can be connected to the rest of the network.
   - Choose a node from each of these SCCs, and output the pair of nodes.

4. **Output:**
   - Output the pair of nodes chosen for restoring connectivity.

### Output:
The program outputs a pair of nodes (u, v) representing the two nodes between which a new directed line should be added to restore network connectivity.

The program appears to be correct and follows the logic described in the problem. If you have any specific questions or concerns, feel free to ask!
*/