#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
using namespace std;
/*
Here's the summary of the problem "Hálózat kitüntetett csomóponttal" (Network with a Designated Node):

- **Problem Description**:
  A communication network consists of nodes and direct one-way links between pairs of nodes. A node U is said to be reachable from node V if communication can be established from U to V, possibly through intermediate nodes. The network has a designated node K. The operators want to know which nodes, different from K, can be reached from K with at most T intermediate nodes, and from which K can be reached.

- **Task**:
  Create a program that calculates the nodes that can be reached from K through at most T intermediate nodes, and from which K can be reached.

- **Input**:
  - The first line of standard input contains the number of nodes N (2 ≤ N ≤ 10,000), the number of direct links M (2 ≤ M ≤ 300,000), the index of the designated node K (1 ≤ K ≤ N), and the specified distance T (0 ≤ T < N).
  - The following M lines each contain two integers U and V, indicating there is a direct link from node U to node V (1 ≤ U ≠ V ≤ N).

- **Output**:
  - The program should output the number of nodes that can be reached from K with at most T intermediate nodes, and from which K can be reached.
  - The next line should contain the indices of these nodes, separated by spaces, in ascending order.

- **Example**:
  - **Input**:
    ```
    10 14 3 2
    2 3
    1 3
    3 4
    3 5
    1 5
    4 6
    6 2
    6 7
    7 9
    9 10
    5 8
    8 10
    5 4
    5 7
    ```
  - **Output**:
    ```
    4
    2 4 5 6
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
vector<int> adj[10001];
stack<int> s,res;

void findSCC(int node,vector<int> &disc,vector<int> &low,vector<bool> &onStack){
    static int startNode = node;
    static int time = 1;
    disc[node] = time;
    low[node] = time;
    s.push(node);
    onStack[node] = true;
    time++;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            findSCC(i,disc,low,onStack);
            low[node] = min(low[i],low[node]);
        }
        else if(onStack[i]){
            //found backedge on current component
            low[node] = min(disc[i],low[node]);
        }
    }
    if(low[node] == disc[node]){
        stack<int> garbage = s;
        while(s.top() != node){
            if(s.top() == startNode) res = garbage;
            onStack[s.top()] = false;
            s.pop();
        }
        if(s.top() == startNode) res = garbage;
        onStack[s.top()] = false;
        s.pop();
    }
}

void BFS(int startNode,int n,int t){
    queue<int> q;
    vector<bool> visited(n+1,false);
    visited[startNode] = true;
    vector<int> distance(n+1,0);
    q.push(startNode);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                distance[i] = distance[node] + 1;
            }
        }
    }
    set<int> ans;
    while(!res.empty()){
        if(distance[res.top()] <= t && res.top()!=startNode){
            ans.insert(res.top());
        }
        res.pop();
    }
    if(ans.size() == 0) {
        cout<<0;
        return;
    }
    cout<<ans.size()<<'\n';
    for(auto i:ans) cout<<i<<" ";
}

int main()
{
    int n,m,startNode,t;
    cin>>n>>m>>startNode>>t;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    t++;
    vector<int> disc(n+1,0), low(n+1,0);
    vector<bool> onStack(n+1,false);
    findSCC(startNode,disc,low,onStack);
    BFS(startNode,n,t);
    return 0;
}
/*
The given C++ program aims to solve the "Network with a Designated Node" problem. Let's break down the approach into smaller steps for a comprehensive understanding.

### Approach:

1. **Input Reading:**
   - Read the number of nodes \( N \), the number of edges \( M \), the designated node \( K \), and the specified distance \( T \) from the input.
   - Create an adjacency list to represent the directed edges in the network.

2. **Graph Representation:**
   - Build a directed graph using the provided edges. Each edge \( (U, V) \) indicates a one-way path from node \( U \) to node \( V \).

3. **Strongly Connected Components (SCC):**
   - Use Tarjan's algorithm to find the strongly connected components (SCCs) in the graph. This identifies groups of nodes that are mutually reachable within the SCC.

4. **DFS for SCC:**
   - Implement a Depth-First Search (DFS) to find the SCCs and identify the nodes that can be reached from \( K \) with at most \( T \) intermediate nodes.

5. **BFS to Calculate Reachability:**
   - Perform a Breadth-First Search (BFS) from the designated node \( K \) to calculate the distances to other nodes.
   - Iterate through the SCCs and find the nodes that can be reached from \( K \) within \( T \) steps.

6. **Output:**
   - Print the number of nodes that can be reached from \( K \) within \( T \) steps, excluding \( K \).
   - Print the indices of these nodes in ascending order.

### Output:
The program outputs the count of nodes that can be reached from \( K \) with at most \( T \) intermediate nodes, and the indices of these nodes.

### Example:
For the provided input example:
- The program outputs "4" as there are 4 nodes that can be reached from node 3 (designated node) with at most 2 intermediate nodes.
- The nodes satisfying this condition are "2 4 5 6".
*/