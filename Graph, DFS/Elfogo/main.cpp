#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
Here's the summary of the problem "Elfogó" (The Catcher):

- **Problem Description**:
  The city police are planning to catch a fugitive who is constantly driving through the city streets. Each street is one-way, and at most one street connects any two intersections in one direction. There could be dead-end streets, meaning an intersection that does not have a one-way street leading out of it. The objective is to determine all the intersections where the fugitive must eventually appear if they are constantly moving.

- **Task**:
  Create a program that identifies all intersections where the fugitive must eventually appear, assuming continuous movement.

- **Input**:
  - The first line of standard input contains the number of intersections N (2 ≤ N ≤ 2000).
  - The second line contains the number of one-way streets M (1 ≤ M < N * N).
  - The following M lines describe the one-way streets, each line containing A and B representing a street from A to B (1 ≤ A, B ≤ N).

- **Output**:
  - The program should output a single line containing the identifiers of all intersections where the fugitive must eventually appear, separated by a space. If there are no such intersections, output a single 0.

- **Example**:
  - **Input**:
    ```
    6
    8
    1 2
    2 3
    3 4
    4 5
    1 6
    2 5
    6 3
    6 4
    ```
  - **Output**:
    ```
    6
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
vector<int> adj[2001];

void topSort(int n){
    vector<int> res, inDegree(n+1,0), outDegree(n+1,0);
    queue<int> q;
    for(int i=1; i<=n; i++){
        for(auto j:adj[i]){
            inDegree[j] ++;
            outDegree[i] ++;
        }
    }
    for(int i=1; i<=n; i++){
        if(inDegree[i] == 0){
            res.push_back(i);
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            inDegree[i]--;
            if(inDegree[i] == 0){
                q.push(i);
                res.push_back(i);
            }
        }
    }
    if(res.size()!=n){
        cout<<0;
        return;
    }
    for(int i=res.size()-1; i>=0; i--){
        if(outDegree[res[i]] == 0) cout<<res[i]<<" ";
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
    topSort(n);
    return 0;
}
/*
The given program attempts to solve the problem of identifying intersections where a fugitive must eventually appear, assuming continuous movement along one-way streets in a city.

### Approach:
The program uses a topological sorting algorithm to determine the order of traversal of intersections based on the one-way streets. However, the initial approach is flawed, and it mentions the correct approach (Kosaraju's algorithm) to solve the problem.

### Correct Approach (Kosaraju's Algorithm):
Kosaraju's algorithm is used to find all strongly connected components (SCCs) in the directed graph representing the city streets. SCCs are groups of intersections where you can reach any intersection from any other intersection within the group.

1. **Create the Graph:**
   Build a directed graph where the intersections are the nodes, and the one-way streets are directed edges.

2. **Find Strongly Connected Components (SCCs):**
   Apply Kosaraju's algorithm to find SCCs in the graph. Each SCC represents a group of intersections where you can move freely between any pair of intersections within the SCC.

3. **Identify the Final Answer:**
   - If an SCC has out-degree zero, it means it's a sink component, and the fugitive must eventually appear in all the intersections of this SCC.
   - Print the identifiers of intersections in sink SCCs.

### Output:
The program should output the identifiers of intersections where the fugitive must eventually appear, separated by a space. If there are no such intersections, it should output a single 0.

### Example:
For the provided input example:
- The program should output "6" as this is the only intersection where the fugitive must eventually appear.

If you have more programs or need further explanation, feel free to share!
*/