#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
- **Problem Description**:
  A large company has N branches. There is a central warehouse from which all branches are supplied with raw materials. Certain branches are connected by one-way direct roads. The central warehouse must be closed, so a new central warehouse location needs to be found. To ensure the supply, new roads may need to be built. The goal is to minimize the number of new roads needed to establish the new central warehouse.

- **Task**:
  Write a program to calculate the minimum number of new one-way roads that need to be built to establish the new central warehouse.

- **Input**:
  - The first line of standard input contains the number of branches N (1 ≤ N ≤ 100,000), the number of direct roads M (1 ≤ M ≤ 1,000,000), and the location of the central warehouse K (1 ≤ K ≤ N).
  - The following M lines each contain two integers u and v (1 ≤ u ≠ v ≤ N) representing a direct one-way road from branch u to branch v.

- **Output**:
  - The program should output two integers: the first being the number of the branch where the new central warehouse will be located, and the second being the number of new one-way direct roads to be built, K.
  - The next K lines should each contain two integers representing new one-way roads to be built, specifying their starting and ending branches.

- **Example**:
  - **Input**:
    ```
    10 14 3
    3 4
    3 1
    3 5
    4 2
    2 8
    8 9
    9 2
    8 4
    1 6
    5 7
    7 10
    7 6
    10 5
    6 10
    ```
  - **Output**:
    ```
    4 1
    4 1
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
vector<int> adj[100001],res;
stack<int> s;
void SCC(int node,vector<int> &disc,vector<int> &low,vector<bool> &currStack,vector<int> &parent){
    static int time = 1;
    disc[node] = time;
    low[node] = time;
    currStack[node] = true;
    s.push(node);
    time++;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            parent[i] = node;
            SCC(i,disc,low,currStack,parent);
            low[node] = min(low[node],low[i]);
        } else if(currStack[i]){
            low[node] = min(low[node],disc[i]);
        }
    }
    if(low[node] == disc[node]){
        if(parent[node] == 0) res.push_back(node);
        while(s.top()!=node){
            currStack[s.top()] = false;
            s.pop();
        }
        currStack[s.top()] = false;
        s.pop();
    }
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> disc(n+1,0), low(n+1,0), parent(n+1,0), startNodes;
    vector<bool> currStack(n+1,false);
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        if(x == k) startNodes.push_back(y);
        else adj[x].push_back(y);
    }
    for(auto i:startNodes){
        if(disc[i] == 0) SCC(i,disc,low,currStack,parent);
    }
    int mainNode = *res.begin();
    cout<<mainNode<<" "<<res.size()-1<<'\n';
    for(auto i:res) {
        if(i!=mainNode) cout<<mainNode<<" "<<i<<'\n';
    }
    return 0;
}
/*
Let's break down the approach of the program step by step.

### Program Approach: Finding the New Central Warehouse Location and Roads

1. **Input Reading**:
   - Read the number of branches (N), the number of direct roads (M), and the location of the current central warehouse (K) from the standard input.
   - Read M lines, each containing two integers u and v, representing a direct one-way road from branch u to branch v.

2. **Finding Strongly Connected Components (SCCs)**:
   - Use Tarjan's algorithm to find SCCs in the given directed graph.
   - The `SCC` function implements Tarjan's algorithm for SCC detection.
   - Determine the SCCs that can be reached from the current central warehouse.

3. **Identifying the New Central Warehouse and Roads**:
   - The new central warehouse should be a node in an SCC that is not reachable from the current central warehouse.
   - Print the new central warehouse node and the number of new roads needed.
   - Print the new roads from the current central warehouse to nodes in the new SCCs.

4. **Output**:
   - Print the number of the branch where the new central warehouse will be located.
   - Print the number of new one-way direct roads to be built (K).
   - Print K lines, each containing two integers representing new one-way roads to be built, specifying their starting and ending branches.

The approach involves finding SCCs and determining the new central warehouse and the required roads to establish effective supply chains.
*/