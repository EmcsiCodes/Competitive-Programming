#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
**Problem Summary:**

A company has factories in different cities across the country, and they produce components in these factories. Weekly production is transported to the central warehouse using trucks. Due to traffic restrictions, each city can directly send trucks to exactly one other city. The company plans the shipments so that a truck is sent from any city that cannot be reached from another city, but no trucks are sent from the other cities. Each truck can pick up as many components as needed, provided it is not full.

The task is to determine the minimum truck capacity needed to transport all components, assuming all trucks have the same capacity.

**Input:**

- Number of cities (N).
- N-1 lines, each containing two integers separated by a space. The first integer indicates the destination city for the trucks from the i-th city, and the second integer is the number of components produced in the i-th city. The first city (city 1) is the central warehouse.

**Output:**

- The minimum truck capacity required to transport all components.

**Example:**

- **Input:**
  ```
  8
  1 3
  1 3
  1 4
  2 5
  3 6
  3 6
  4 9
  ```

- **Output:**
  ```
  13
  ```

In this example, the minimum truck capacity required is 13.
*/

vector<int> adj[1001];

int main()
{
    int n;
    cin>>n;
    vector<int> degree(n+1,0);
    vector<int> w(n+1,0);
    vector<int> trucks(n+1,0);
    if(n == 1){
        cout<<0;
        return 0;
    }
    for(int i=2; i<=n; i++){
        int x,y;
        cin>>x>>y;
        adj[i].push_back(x);
        w[i] = y;
        degree[x]++;
    }
    int ucap = 0;
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(degree[i] == 0) {
            q.push(i);
            ucap = max(ucap,w[i]);
            trucks[i]++;
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        int i = adj[node][0];
        degree[i]--;
        trucks[i] += trucks[node];
        w[i] += w[node];
        if(degree[i] == 0){
            int capAt = w[i]%trucks[i]==0 ? w[i]/trucks[i] : w[i]/trucks[i] + 1;
            ucap = max(ucap,capAt);
            if(adj[i][0]!=1) q.push(i);
        }
    }
    cout<<ucap;
    return 0;
}
/*
Sure, let's dive deeper into the approach and implementation details of the program.

### Approach:

1. **Graph Representation:**
   - Each city is a node in the graph.
   - There's a directed edge from city i to city j if trucks from city i can go directly to city j.
   - The first city is the central warehouse (node 1).

2. **Truck Transport:**
   - Trucks pick up components in a city and transport them to another city directly connected to it.
   - We want to find the minimum truck capacity needed such that all components can be transported efficiently.

3. **BFS Traversal:**
   - We use BFS starting from the central warehouse (city 1).
   - BFS helps traverse through cities in a breadth-first manner, starting from the central warehouse.

4. **Calculate Truck Capacity:**
   - During BFS traversal, we calculate the minimum truck capacity required for each city.
   - This calculation is based on the number of components produced and the number of trucks from the previous city.

### Implementation:

1. **Graph Representation:**
   - We use an adjacency list to represent the directed graph.
   - Each node (city) stores its outgoing edges (connections to other cities).

2. **BFS Traversal:**
   - We start BFS from the central warehouse (node 1).
   - While traversing, we calculate the truck capacity for each city based on components produced and trucks from the previous city.

3. **Minimum Truck Capacity:**
   - We calculate the minimum truck capacity needed by considering the components produced in the current city and the number of trucks.
   - We maximize the capacity needed among all cities.

4. **Output:**
   - The output is the calculated minimum truck capacity needed to transport all components efficiently.

### Example Walkthrough:

Let's go through the given example step by step, showing how the BFS traversal calculates the minimum truck capacity.

### Input:
```
8
1 3
1 3
1 4
2 5
3 6
3 6
4 9
```

### Steps:
1. **Graph Representation:**
   - We create a directed graph based on the input where edges represent the movement of trucks.

2. **BFS Traversal:**
   - We start BFS from the central warehouse (city 1).
   - Traverse the cities in a breadth-first manner.

3. **Calculate Truck Capacity:**
   - During traversal, we calculate the truck capacity based on components produced and the number of trucks.

4. **Minimum Truck Capacity:**
   - We find the maximum truck capacity needed among all cities.

5. **Output:**
   - The output is the calculated minimum truck capacity.

### Conclusion:

The program efficiently calculates the minimum truck capacity needed to transport all components based on the given input. It follows a structured approach, representing the cities as a graph and using BFS traversal to determine the required truck capacity.

If you have any more specific questions or need further clarification, feel free to ask!
*/