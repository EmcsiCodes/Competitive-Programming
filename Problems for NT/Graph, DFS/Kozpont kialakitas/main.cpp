#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <unordered_map>
using namespace std;
/*
- **Problem Description**:
  In a computer network, nodes are connected by unidirectional transmission lines. The network is designed in such a way that each node has exactly two other nodes directly connected to it. The network operator has designated one node to be used as the central node. This means that data can be transmitted from this node to every other node in the network.

- **Task**:
  Write a program to calculate the minimum number of additional unidirectional direct lines that need to be built from the designated central node to ensure that data can be transmitted from this node to every other node.

- **Input**:
  - The first line of standard input contains the number of nodes N (1 ≤ N ≤ 10,000) and the number of the designated central node K (1 ≤ K ≤ N).
  - The following N lines each contain two integers u and v (1 ≤ u, v ≤ N, u ≠ v) representing a direct line connecting node i to nodes u and v.

- **Output**:
  - The program should output the number of new unidirectional direct lines to be constructed, M.
  - The next M lines should each contain two integers x and y, indicating new direct lines to be built between nodes x and y.

- **Example**:
  - **Input**:
    ```
    11 7
    3 4
    5 9
    4 7
    6 7
    7 2
    1 10
    9 10
    5 9
    10 11
    9 11
    9 10
    ```
  - **Output**:
    ```
    2
    7 1
    7 8
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
vector<int> adj[10001], nodes;
unordered_map<int,int> comp;
set<int> subg[10001];
stack<int> s;
void SCC(int node,vector<int>&disc,vector<int>&low,vector<bool>&onStack){
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
    if(disc[node] == low[node]){
        while(s.top()!=node){
            comp[s.top()] = node;
            onStack[s.top()] = false;
            s.pop();
        }
        comp[s.top()] = node;
        nodes.push_back(node);
        onStack[s.top()] = false;
        s.pop();
    }
}

void makeSubGraph(int n){
    vector<int> disc(n+1,0), low(n+1,0);
    vector<bool> onStack(n+1,0);
    for(int i=1; i<=n; i++){
        if(disc[i] == 0) SCC(i,disc,low,onStack);
    }
    for(int i=1; i<=n; i++){
        for(auto j:adj[i]){
            if(comp[i]!=comp[j]) subg[comp[i]].insert(comp[j]);
        }
    }
}

int main()
{
    int n,start;
    cin>>n>>start;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        adj[i].push_back(x);
        adj[i].push_back(y);
    }
    makeSubGraph(n);
    vector<int> inDegree(n+1,0);
    for(auto i:nodes){
        for(auto j:subg[i]){
            inDegree[j]++;
        }
    }
    vector<int> res;
    for(auto i:nodes){
        if(inDegree[i] == 0 && i!=start) res.push_back(i);
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<start<<" "<<i<<'\n';
    return 0;
}
/*
Let's break down the approach of the program step by step.

### Program Approach: Constructing Direct Lines in a Computer Network

1. **Input Reading**:
   - Read the number of nodes (N) and the designated central node (K) from the standard input.
   - Read N lines, each containing two integers u and v, representing direct lines connecting node i to nodes u and v.

2. **Finding Strongly Connected Components (SCCs)**:
   - Use Tarjan's algorithm to find SCCs in the given directed graph.
   - The `SCC` function implements Tarjan's algorithm for SCC detection.
   - Create a mapping of each node to their respective SCC.

3. **Constructing the Subgraph**:
   - For each SCC, create a node in the subgraph.
   - Construct edges in the subgraph based on the original connections between nodes.
   - The subgraph helps to represent the structure of the network.

4. **Counting Incoming Edges**:
   - Count the number of incoming edges for each SCC in the subgraph.
   - This indicates how many lines need to be constructed to ensure data transmission.

5. **Finding Additional Lines**:
   - Iterate through the SCCs and find the SCCs (representing nodes) with zero incoming edges.
   - Identify the SCCs where additional lines need to be constructed.

6. **Output**:
   - Print the number of new direct lines to be constructed (M).
   - Print the pairs of nodes (x, y) for each new direct line.

The approach involves using SCCs to identify the structure of the network and determine the number of lines needed for effective data transmission.
*/