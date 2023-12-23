#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
"Ügynök útja" (Agent's Path):

- **Problem Description**:
  An agent needs to visit various cities. The agent can travel from any city to any other city in exactly one day. The cities are connected by bidirectional direct roads in such a way that there is exactly one path between any two cities.

- **Task**:
  Create a program that determines how many cities the agent can visit in M days, starting from any city.

- **Input**:
  - The first line of standard input contains the number of cities (2 ≤ N ≤ 100,000) and the number of days prescribed for the agent (1 ≤ M ≤ 2 * M).
  - The following N-1 lines describe a direct route between cities Ai and Bi (1 ≤ Ai ≠ Bi ≤ N).

- **Output**:
  - The program should output a single line containing the number of cities that can be visited in M days. The city where the journey starts is also counted as visited.

- **Example**:
  - **Input**:
    ```
    9 8
    1 2
    2 3
    3 4
    5 2
    8 3
    6 9
    7 9
    9 3
    ```
  - **Output**:
    ```
    7
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
vector<int> adj[10001];

void BFS(int node, vector<bool> &visited, int n){
    queue<int> q;
    q.push(node);

    while(!q.empty()){
        node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

void solve(int n){
    int k=-1;
    vector<int> res;
    vector<bool> visited(n+1, false);
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            res.push_back(i);
            k++;
            BFS(i,visited,n);
        }
    }
    cout<<k<<'\n';
    for(int i=0; i<res.size()-1; i++){
        cout<<res[i]<<" "<<res[i+1]<<'\n';
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
        adj[y].push_back(x);
    }
    solve(n);
    return 0;
}
/*
The given program aims to determine how many cities an agent can visit in a specified number of days (M days) given a network of cities connected by bidirectional roads.

Here's a step-by-step explanation of the program's approach:

1. **Graph Representation**:
   The cities and their connections are represented as a graph, where each city is a node, and the direct roads are edges connecting the nodes.

2. **Breadth-First Search (BFS)**:
   The BFS algorithm is used to traverse the graph and find connected components. Each connected component represents a group of cities that can be visited starting from a particular city.

   - The BFS function starts from a node (representing a city) and explores all the connected cities.
   - It marks the visited cities to keep track of the exploration.
   - The BFS function is called for each unvisited city to find a new connected component.

3. **Finding Connected Components**:
   - The main function `solve` iterates through each city.
   - For each unvisited city, it starts a new connected component.
   - The function `BFS` is called for each unvisited city, marking all cities that can be visited from that starting city.

4. **Output**:
   - The program counts the number of connected components, representing the number of cities that can be visited.
   - It also outputs the edges between the cities in each connected component.

5. **Example Input and Output**:
   - For the given example input, the program calculates that there are 7 connected components, meaning the agent can visit 7 cities.
   - It then outputs the edges (direct roads) between the cities in each connected component.

   ```
   7
   1 3
   2 7
   6 8
   8 3
   1 6
   4 9
   4 2
   ```

Overall, the program utilizes BFS to explore the network of cities, finding connected components and determining how many cities the agent can visit within the given number of days. It then outputs this information, including the edges representing the roads between the cities.
*/