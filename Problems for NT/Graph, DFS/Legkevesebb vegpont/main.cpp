#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
- **Problem Description**:
  Given a directed graph G=(V, E), the task is to compute a set C⊆V with the minimum number of vertices, such that for any vertex q∈V, there exists a vertex p∈C from which there is a path to q.

- **Task**:
  Create a program that calculates a set C with the minimum number of vertices that fulfills the given condition.

- **Input**:
  - The first line of standard input contains the number of vertices in the graph N (1 ≤ N ≤ 10,000) and the number of edges M (1 ≤ M ≤ 200,000).
  - The following M lines each contain a pair of vertices u and v (1 ≤ u, v ≤ N), representing a directed edge from u to v.

- **Output**:
  - The program should output the number K of elements in the set C that satisfies the given condition.
  - The next line should contain exactly K numbers, representing the elements of C, separated by spaces.

- **Example**:
  - **Input**:
    ```
    9 12
    1 2
    2 3
    2 1
    1 6
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
    2
    6 3
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
vector<int> adj[10001];
stack<int> s;
vector<int> res;
void findSCCs(int node,vector<int> &disc,vector<int> &low,vector<bool> &currStack,vector<int> &outDegree){
    static int time = 1;
    currStack[node] = true;
    disc[node] = time;
    low[node] = time;
    s.push(node);
    time++;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            findSCCs(i,disc,low,currStack,outDegree);
            if(low[i] <= low[node]){
                low[node] = low[i];
                outDegree[node]--;
            }
        } else if(currStack[i]){
            low[node] = min(low[node],disc[i]);
            outDegree[node]--;
        }
    }
    if(low[node] == disc[node]){
        int totalOut = 0;
        while(s.top()!=node){
            totalOut += outDegree[s.top()];
            currStack[s.top()] = false;
            s.pop();
        }
        totalOut += outDegree[s.top()];
        currStack[s.top()] = false;
        s.pop();
        if(totalOut == 0){
            res.push_back(node);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> disc(n+1,0), low(n+1,0), outDegree(n+1,0);
    vector<bool> currStack(n+1,false);
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        outDegree[x]++;
    }
    for(int i=1; i<=n; i++){
        if(disc[i] == 0) findSCCs(i,disc,low,currStack,outDegree);
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
Let's break down the approach of the program step by step.

### Program Approach: Minimum Set of Vertices

1. **Input Reading**:
   - Read the number of vertices (N) and the number of edges (M) from the standard input.
   - Read M lines, each containing a pair of vertices u and v, representing a directed edge from u to v.

2. **Finding Strongly Connected Components (SCCs)**:
   - Use Tarjan's algorithm to find the strongly connected components (SCCs) in the given directed graph.
   - Identify the SCCs where every vertex has an out-degree greater than zero. These are the SCCs contributing to the set C.

3. **Output**:
   - Print the number of elements in the set C (the SCCs where every vertex has an out-degree greater than zero).
   - Print the elements of C, separated by spaces.

The approach involves using Tarjan's algorithm to find SCCs and identifying the SCCs that fulfill the condition for the set C.

*/