#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
/*
Here's the summary of the problem "Karavánok" (Caravans):

- **Problem Description**:
  In a desert, there are N oases connected by M caravan routes. Caravans may not travel between each pair of oases in both directions. A merchant wants to build a warehouse in a single oasis from where they can transport goods to all other oases.

- **Task**:
  Create a program that determines the oases from which goods can be transported to all other oases.

- **Input**:
  - The first line of standard input contains the number of oases N (1 ≤ N ≤ 5000) and the number of caravans M (1 ≤ M ≤ 100,000).
  - The following M lines contain pairs of oasis numbers, Ai and Bi (1 ≤ Ai ≠ Bi ≤ N), indicating that a caravan transports goods from oasis Ai to Bi.

- **Output**:
  - The first line of the output should contain the oasis numbers where the warehouse can be set up, in ascending order.
  - If there is no solution, output -1.

- **Example**:
  - **Input**:
    ```
    7 10
    2 6
    3 1
    3 2
    3 4
    6 3
    4 7
    7 5
    5 7
    5 4
    4 5
    ```
  - **Output**:
    ```
    2 3 6
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
vector<int> adj[5001];
stack<int> s;
vector<int> res;
int inNum = 0;

void SCC(int node,vector<int> &disc,vector<int> &low,vector<int> &inDegree,vector<bool> &onStack){
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
            low[node] = min(low[node],disc[i]);
            inDegree[i]--;
        }
    }
    if(low[node] == disc[node]){
        int in = 0;
        vector<int> p;
        while(s.top()!=node){
            p.push_back(s.top());
            in += inDegree[s.top()];
            onStack[s.top()] = false;
            s.pop();
        }
        p.push_back(s.top());
        in += inDegree[s.top()];
        onStack[s.top()] = false;
        s.pop();
        if(in == 0){
            inNum++;
            res = p;
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> disc(n+1,0), low(n+1,0), inDegree(n+1,0);
    vector<bool> onStack(n+1,false);
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        inDegree[y]++;
    }
    
    for(int i=1; i<=n; i++){
        if(disc[i] == 0){
            SCC(i,disc,low,inDegree,onStack);
        }
    }
    if(inNum > 1){
        cout<<-1;
    } else {
        sort(res.begin(),res.end());
        for(auto i:res) cout<<i<<" ";
    }
    return 0;
}
/*
Sure, let's discuss the approach in more detail for the "Caravans" problem.

### Approach:

1. **Graph Representation:**
   - Read the number of oases \(N\) and the number of caravan routes \(M\).
   - Create an adjacency list to represent the graph. For each caravan route, store the adjacent oases.

2. **Strongly Connected Components (SCC) using Tarjan's Algorithm:**
   - Apply Tarjan's algorithm to find strongly connected components (SCCs) in the graph.
   - During the traversal, maintain discovery times (`disc`), low-link values (`low`), and a stack to keep track of visited nodes.
   - When a SCC is identified (discovery time equals low-link value), check if it's a potential warehouse location.

3. **Check Potential Warehouse Locations:**
   - For each SCC, if its in-degree is zero, it's a potential warehouse location. Count them and store their vertices.

4. **Output the Result:**
   - If there's only one potential warehouse, output the sorted vertices of that SCC.
   - If there are multiple potential warehouses, output -1 indicating no solution.

### Detailed Steps:

1. **Tarjan's Algorithm for SCC:**
   - Start DFS from each vertex.
   - During DFS, maintain discovery times (`disc`), low-link values (`low`), and a stack to keep track of visited nodes.
   - When visiting a node, assign it a discovery time and a low-link value.
   - If a node is already visited (its discovery time is set), it's part of a SCC, update its low-link value accordingly.

2. **Checking Warehouse Locations:**
   - When an SCC is identified (discovery time equals low-link value), check its in-degree.
   - If the in-degree is zero, mark it as a potential warehouse location and store its vertices.

3. **Output:**
   - If there's only one potential warehouse (in-degree is zero), output the sorted vertices of that SCC.
   - If there are multiple potential warehouses, output -1 indicating no solution.

### Time Complexity:
- The Tarjan's algorithm for SCC detection takes \(O(N + M)\) time.
- Sorting the vertices takes \(O(N \log N)\) time.

### Space Complexity:
- The space complexity is \(O(N + M)\) to store the graph using an adjacency list and auxiliary data structures for Tarjan's algorithm.

This approach correctly identifies the potential warehouse locations and outputs the vertices of the SCC if there's only one such location.
*/