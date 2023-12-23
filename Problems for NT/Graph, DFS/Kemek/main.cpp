#include <iostream>
#include <vector>

using namespace std;
/*
Here's the summary of the problem "Kémek" (Spies):

- **Problem Description**:
  There is a spy organization with N members, and it is known who among the members know each other personally. The task is to find the member who, when arrested, would result in the maximum number of separate groups in the organization where members cannot communicate with each other due to lack of personal acquaintance.

- **Task**:
  Create a program that determines the member who, when arrested, leads to the maximum number of separate groups where members cannot communicate due to lack of personal acquaintance.

- **Input**:
  - The first line of standard input contains the number of members N (3 ≤ N ≤ 10,000) and the number of acquaintances M (2 ≤ M ≤ 100,000).
  - The following M lines contain pairs of member numbers, Ai and Bi (1 ≤ Ai ≠ Bi ≤ N), indicating that members Ai and Bi know each other.

- **Output**:
  - The output should contain a single line with the number of the member to be arrested.

- **Example**:
  - **Input**:
    ```
    7 7
    1 3
    3 6
    2 4
    3 4
    4 5
    7 5
    7 4
    ```
  - **Output**:
    ```
    3
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
vector<int> degree(10001,0);
vector<int> adj[10001];
void DFS(int node,vector<int>&disc,vector<int>&low,vector<int>&parent,vector<bool>&articPoints){
    static int time = 1;
    disc[node] = time;
    low[node] = time;
    time++;
    int child = 0;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            child++;
            parent[i] = node;
            DFS(i,disc,low,parent,articPoints);
            low[node] = min(low[node],low[i]);
            if(parent[node]==0 && child>1) articPoints[node] = true;
            if(parent[node]!=0 && low[i]>=disc[node]) {
                //degree[node]--;
                articPoints[node] = true;
            }
        } else if(parent[node]!=i) {
            low[node] = min(low[node],disc[i]);
            degree[i]--;
            //cout<<node<<":"<<i<<" ";
        }
    }
}

void findArticPoints(int n,vector<bool>&articPoints){
    vector<int> disc(n+1,0),parent(n+1,0),low(n+1,0);
    for(int i=1; i<=n; i++){
        if(disc[i] == 0) DFS(i,disc,low,parent,articPoints);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<bool> articPoints(n+1,false);
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        degree[x]++;
        degree[y]++;
    }
    //for(int i=1; i<=n; i++) cout<<i<<":"<<degree[i]<<" ";
    //cout<<endl;
    findArticPoints(n,articPoints);
    bool noRes = true;
    int maxSeparation = 0;
    int maxSeparationIndex = 0;
    //cout<<endl;
    for(int i=1; i<=n; i++){
        //cout<<i<<":"<<degree[i]<<" ";
        if(articPoints[i] && maxSeparation < degree[i]){
            noRes = false;
            maxSeparation = degree[i];
            maxSeparationIndex = i;
        }
    }
    if(noRes) cout<<0;
    else cout<<maxSeparationIndex;
    return 0;
}
/*
The code implements a solution to find the member who, when arrested, leads to the maximum number of separate groups in the spy organization where members cannot communicate with each other due to lack of personal acquaintance.

### Approach:

1. **Graph Representation:**
   - Read the number of members \(N\) and the number of acquaintances \(M\).
   - Create an adjacency list to represent the graph. For each acquaintance, store the edges between members.

2. **Articulation Points:**
   - Use depth-first search (DFS) to find articulation points in the graph. An articulation point is a vertex that, if removed, increases the number of connected components in the graph.

3. **DFS for Articulation Points:**
   - Perform a DFS traversal to find articulation points.
   - Maintain discovery times (`disc`), low-link values (`low`), and parent information.
   - If a vertex is an articulation point, update the maximum separation and the corresponding index.

4. **Output the Result:**
   - Output the index of the articulation point that leads to the maximum separation.

### Time Complexity:
- Constructing the graph takes \(O(M)\) time.
- Finding articulation points using DFS takes \(O(N + M)\) time.

### Space Complexity:
- The space complexity is \(O(N + M)\) to store the graph using an adjacency list and auxiliary data structures.

The approach correctly identifies the member to be arrested based on the maximum number of separate groups.
*/