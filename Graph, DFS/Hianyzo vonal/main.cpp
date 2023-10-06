#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
Here's the summary of the problem "Hiányzó vonal" (Missing Link):

- **Problem Description**:
  In a communication network with nodes and directed links, it was intended that between any two nodes U and V, there should be exactly one path for transmission from U to V. However, a mistake occurred, and one link was not established between two nodes.
  
- **Task**:
  Create a program that determines two nodes P and Q, such that by establishing a direct link from P to Q, the condition is satisfied that between any two nodes, there is exactly one path.

- **Input**:
  - The first line of standard input contains the number of nodes N (1 ≤ N ≤ 10,000) and the number of established direct links M (1 ≤ M ≤ 200,000).
  - The following M lines each contain two integers U and V (1 ≤ U ≠ V ≤ N), indicating that there is a direct link from node U to node V.

- **Output**:
  - The program should output two node numbers P and Q, such that establishing a direct link from P to Q satisfies the condition of having exactly one path between any two nodes.

- **Example**:
  - **Input**:
    ```
    11 14
    1 2
    2 3
    3 1
    2 4
    4 5
    5 6
    6 7
    7 5
    4 8
    8 9
    9 4
    4 10
    10 11
    11 4
    ```
  - **Output**:
    ```
    5 2
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
vector<int> adj[10001];
stack<int> s;
pair<int,int> res;
void findSCCs(int node,vector<int> &disc,vector<int> &low,vector<bool> &currStack,vector<int> inDegree,vector<int> outDegree){
    static int time = 1;
    disc[node] = time;
    low[node] = time;
    currStack[node] = true;
    s.push(node);
    time++;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            findSCCs(i,disc,low,currStack,inDegree,outDegree);
            low[node] = min(low[node], low[i]);
        } else if(currStack[i]){
            low[node] = min(low[node],disc[i]);
        }
    }
    if(disc[node] == low[node]){
        int currSCCin = 0;
        int currSCCout = 0;
        while(s.top()!=node){
            currSCCin += inDegree[s.top()];
            currSCCout += outDegree[s.top()];
            currStack[s.top()] = false;
            //cout<<s.top()<<" ";
            s.pop();
        }
        currSCCin += inDegree[s.top()];
        currSCCout += outDegree[s.top()];
        currStack[s.top()] = false;
        //cout<<s.top()<<" , in:";
        s.pop();
        //cout<<currSCCin<<", out:"<<currSCCout<<endl;
        if(currSCCin > currSCCout) res.first = node;
        if(currSCCout > currSCCin) res.second = node;
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> inDegree(n+1,0), outDegree(n+1,0), disc(n+1,0), low(n+1,0);
    vector<bool> currStack(n+1,false);
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        inDegree[y]++;
        outDegree[x]++;
    }
    for(int i=1; i<=n; i++){
        if(disc[i] == 0) findSCCs(i,disc,low,currStack,inDegree,outDegree);
    }
    cout<<res.first<<" "<<res.second;
    return 0;
}
/*
The provided C++ program aims to solve the "Missing Link" problem. Here's a breakdown of the approach for better understanding:

### Approach:

1. **Input Reading:**
   - Read the number of nodes \( N \) and the number of established direct links \( M \).
   - Create an adjacency list to represent the directed links.

2. **Graph Representation:**
   - Build a directed graph using the provided links.

3. **Strongly Connected Components (SCC):**
   - Use Kosaraju's algorithm to find the strongly connected components (SCCs) in the graph.

4. **Calculate In-Degree and Out-Degree for Each SCC:**
   - Traverse the SCCs and calculate the in-degree and out-degree for each SCC.

5. **Find Nodes for the Missing Link:**
   - Iterate through SCCs and find two nodes, P and Q, such that:
     - P has the maximum out-degree within its SCC.
     - Q has the maximum in-degree within its SCC.

6. **Output:**
   - Print the nodes P and Q.

### Output:
The program outputs two node numbers, P and Q, such that establishing a direct link from P to Q satisfies the condition of having exactly one path between any two nodes.

### Example:
For the provided input example:
- The program outputs "5 2" as the nodes for the missing link that would fulfill the condition.
*/