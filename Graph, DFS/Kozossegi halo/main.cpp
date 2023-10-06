#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <set>
using namespace std;
/*
- **Problem Description**:
  In a social network, each member has specified who they know. Some people confirm these connections, but not all connections are necessarily mutual. The task is to find a member in the social network who can directly or indirectly reach the fewest other members based on the specified connections.

- **Input**:
  - The first line of standard input contains the number of members in the network, N (1 ≤ N ≤ 10,000), and the number of known connections, M (1 ≤ M ≤ 500,000).
  - The following M lines each contain two integers A and B (1 ≤ A, B ≤ N, B ≠ A), representing a connection where member A knows member B.

- **Output**:
  - The program should output the minimum number of acquaintances, P, that a member has, along with the member's ID.

- **Example**:
  - **Input**:
    ```
    6 8
    1 2
    2 3
    3 2
    1 4
    2 5
    4 5
    5 6
    6 5
    ```
  - **Output**:
    ```
    1 5
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame. In 30% of the tests, N is at most 100.
*/
set<int> subg[10001];
vector< pair<int,int> > nodes;
unordered_map<int,int> comp;
vector<int> adj[10001];
stack<int> s;
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
        } else if(onStack[i]) low[node] = min(low[node],disc[i]);
    }
    if(disc[node] == low[node]){
        int num = 0;
        while(s.top()!=node){
            num++;
            comp[s.top()] = node;
            onStack[s.top()] = false;
            s.pop();
        }
        num++;
        nodes.push_back({node,num});
        comp[node] = node;
        onStack[node] = false;
        s.pop();
    }
}

void makeSubGraph(int n){
    vector<int> disc(n+1,0),low(n+1,0);
    vector<bool> onStack(n+1,false);
    for(int i=1; i<=n; i++){
        if(disc[i] == 0){
            SCC(i,disc,low,onStack);
        }
    }
    for(int i=1; i<=n; i++){
        for(auto j:adj[i]){
            if(comp[i]!=comp[j]) subg[comp[i]].insert(comp[j]);
        }
    }
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
    vector<int> outDegree(n+1,0);
    for(auto i:nodes){
        for(auto j:subg[i.first]){
            outDegree[i.first]++;
        }
    }
    int minContact = 10000000;
    int minContactInd = 0;
    for(auto i:nodes){
        if(outDegree[i.first] == 0 && i.second < minContact){
            minContact = i.second;
            minContactInd = i.first;
        }
    }
    cout<<minContact - 1<<" "<<minContactInd;
    return 0;
}
/*
### Program Approach: Finding a Member with Minimum Acquaintances in a Social Network

1. **Input Reading**:
   - Read the number of members (N) and known connections (M) from the standard input.
   - Read M pairs of integers representing connections between members.

2. **Finding Strongly Connected Components (SCCs)**:
   - Use Tarjan's algorithm to find SCCs in the given directed graph.
   - The `SCC` function implements Tarjan's algorithm for SCC detection.
   - Create a mapping of each member to their respective SCC.

3. **Constructing the Subgraph**:
   - For each SCC, create a node in the subgraph.
   - Construct edges in the subgraph based on the original connections between members.
   - The subgraph helps to represent the structure of the social network.

4. **Counting Outgoing Edges**:
   - Count the number of outgoing edges for each SCC in the subgraph.
   - This indicates how many acquaintances each member has.

5. **Finding the Minimum Acquaintances**:
   - Iterate through the SCCs and find the SCC (representing a member) with no outgoing edges.
   - Identify the SCC with the fewest acquaintances.

6. **Output**:
   - Print the minimum number of acquaintances a member has, along with the member's ID.

The approach involves leveraging SCCs to represent groups of members in the social network and counting outgoing edges to determine the number of acquaintances for each member. Finally, it identifies the member with the fewest acquaintances.

*/