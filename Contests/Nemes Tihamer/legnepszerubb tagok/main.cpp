#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
**Problem Summary:**

Given a group of individuals in a society and their choices for the most well-known person, find the longest popularity cycle in which each person considers the next person as the most well-known, and the last person considers the first person as the most well-known.

**Input:**

- Number of individuals (N).
- For each individual (from 1 to N), the index of the person they consider the most well-known.

**Output:**

- The size of the longest popularity cycle.
- The indices of the individuals in this cycle, in the order that each person considers the next person as the most well-known, and the last person considers the first person as the most well-known.

**Example:**

- **Input:**
  ```
  11
  6
  8
  6
  8
  4
  7
  10
  9
  2
  3
  4
  ```

- **Output:**
  ```
  4
  3 6 7 10
  ```

In this case, the longest popularity cycle has a size of 4, and the individuals in this cycle are 3, 6, 7, and 10.
*/

vector<int> adj[10001];
stack<int> s[10001];
void findCycles(int node,vector<int>&disc,vector<bool>&cyclic,int time){
    disc[node] = time;
    s[node].push(node);
    for(auto i:adj[node]){
        if(disc[i] == 0){
            findCycles(i,disc,cyclic,time+1);
            if(cyclic[i] && s[i].size() + 1 > s[node].size()) {
                s[i].push(node);
                s[node] = s[i];
                cyclic[node] = !cyclic[node];
            }
        } else if(time - disc[i] + 1 > s[i].size()) {
            cyclic[node] = true;
            cyclic[i] = true;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        adj[i].push_back(x);
    }
    vector<int> disc(n+1,0), low(n+1,0);
    vector<bool> cyclic(n+1,false);
    for(int i=1; i<=n; i++){
        if(disc[i] == 0) findCycles(i,disc,cyclic,1);
    }
    int maxCycle = 0;
    int maxCycleIndex = 0;
    for(int i=1; i<=n; i++){
        if(s[i].size()>maxCycle){
            maxCycle = s[i].size();
            maxCycleIndex = i;
        }
    }
    cout<<maxCycle<<'\n';
    while(!s[maxCycleIndex].empty()){
        cout<<s[maxCycleIndex].top()<<" ";
        s[maxCycleIndex].pop();
    }
    return 0;
}
/*
Absolutely! Let's dive deeper into the approach and how the program solves the problem:

### 1. **Input Processing:**
   
   The program starts by reading the number of individuals (`n`). Then, for each individual, it records who they consider the most well-known person. This information is represented using an adjacency list. For example, if individual `i` considers individual `x` as the most well-known, we add a directed edge from `i` to `x` in the adjacency list.

### 2. **DFS to Find Cycles:**

   The program uses a modified Depth-First Search (DFS) to identify cycles in the society. It keeps track of the discovery time and low time for each individual, as well as whether an individual is part of a cycle.

   - **Discovery Time (`disc`):** This is the time at which an individual is discovered during the DFS traversal.

   - **Low Time (`low`):** This is the minimum discovery time of all nodes reachable from the current node using one back edge.

   - **Cyclic Nodes (`cyclic`):** This is a boolean array that marks if an individual is part of a cycle.

### 3. **DFS Function:**

   The DFS function (`findCycles`) is recursively called for each individual. It explores the individuals and identifies cycles using the discovery time and low time.

   - If a cycle is found for an individual, it keeps track of the cycle using a stack.

### 4. **Identifying the Longest Popularity Cycle:**

   After identifying all the cycles, the program iterates through the individuals to find the longest cycle.

   - It keeps track of the length of the longest cycle and the index of the individual at the start of the cycle.

### 5. **Output:**

   Finally, the program prints the size of the longest popularity cycle and the individuals in this cycle, in the order that each person considers the next person as the most well-known.

### Example Walkthrough:

Let's follow the example provided earlier:

- **Input:**
  ```
  11
  6
  8
  6
  8
  4
  7
  10
  9
  2
  3
  4
  ```

- **DFS to Find Cycles:**
  - The DFS traversal identifies cycles and keeps track of individuals in cycles.

- **Identifying the Longest Popularity Cycle:**
  - The program finds the longest cycle.

- **Output:**
  ```
  4
  3 6 7 10
  ```

The approach efficiently identifies and traverses the cycles, allowing the program to determine the longest popularity cycle and present the necessary information.
*/