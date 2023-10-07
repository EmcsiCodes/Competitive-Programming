#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
**Problem Summary:**

A large company operates a factory in each of N cities. Each factory has a warehouse for storing products. If a factory produces more products than its warehouse capacity, the excess needs to be transported to another warehouse. The transportation is done by trucks, and each truck can carry at most K products. Due to traffic restrictions, each city can directly send trucks to only one other specified city.

There is a central city with a central warehouse, and every other city can reach this central city directly. The goal is to calculate the minimum number of trucks needed to transport all products and determine the warehouse size needed in the central city to accommodate all products.

Write a program to calculate these values.

**Input:**

- Number of cities (N) and truck capacity (K).
- The next line contains N integers separated by spaces, representing the number of products produced in each city. Each value is at most 2000.
- The next line contains N integers separated by spaces, representing the maximum number of products that can be stored in the warehouse of each city. Each value is at most 3000.
- The next line contains N integers, each indicating the city number to which trucks can be directly sent from the corresponding city. A 0 indicates the central city.

**Output:**

- The first line should contain the minimum number of trucks needed.
- The second line should contain the warehouse size needed in the central city.

**Example:**

**Input:**
```
9 10
8 3 2 20 11 7 4 9 5
5 7 4 10 6 4 4 5 3
2 3 0 3 3 2 4 4 6
```

**Output:**
```
5
21
```

---
*/
vector<int> adj[1001];

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> w(n+1,0), cap(n+1,0), degree(n+1,0), truckCap(n+1,0), truckNum(n+1,0);
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        w[i] = x;
    }
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        cap[i] = x;
    }
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        adj[i].push_back(x);
        degree[x]++;
    }
    queue<int> q;
    int totaltrucks = 0;
    for(int i=1; i<=n; i++){
        if(degree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int newTrucks = 0;
        int node = q.front();
        q.pop();
        int next = adj[node][0];
        int weight = w[node] - cap[node];
        if(weight > 0){
            if(truckCap[node]<weight) newTrucks = weight%k <= truckCap[node] ? weight/k : weight/k + 1;
            truckCap[node] = truckCap[node] + newTrucks * k - weight;
            totaltrucks += newTrucks;
            truckNum[node] += newTrucks;
        } else {
            if(truckNum[node] * k - truckCap[node] + w[node] <= cap[node]) truckCap[node] = truckNum[node] * k;
            else truckCap[node] += (cap[node] - w[node]);
        }
        truckCap[next] += truckCap[node];
        truckNum[next] += truckNum[node];
        degree[next]--;
        if(degree[next] == 0 && next!=0) q.push(next);
        else if(degree[next] == 0){
            cout<<truckNum[node]<<'\n'<<truckNum[node] * k - truckCap[node];
        }
    }
    return 0;
}
/*
The given program addresses the problem of efficiently transporting products from factories to warehouses in different cities. It calculates the minimum number of trucks needed for transportation and determines the warehouse size required in the central city to accommodate all products.

Here's a breakdown of the approach and the implementation:

### Approach:

1. **Graph Representation:**
   - The program models the cities and their relationships as a directed graph, where nodes represent cities and edges represent the direct transportation connections.

2. **Truck Capacity and Warehouse Management:**
   - The program manages the truck capacity and warehouse size to ensure efficient transportation and product storage.

3. **BFS for Calculation:**
   - Breadth-First Search (BFS) is used to traverse the graph and calculate the minimum number of trucks needed and the required warehouse size.

### Implementation:

1. **Graph Representation:**
   - The program uses an adjacency list to represent the graph, where each city stores its direct transportation connection.

2. **Truck Capacity and Warehouse Management:**
   - The program keeps track of truck capacities and warehouse sizes for each city based on the products produced and stored.

3. **BFS for Calculation:**
   - The program performs BFS to calculate the minimum number of trucks needed and the warehouse size required.

4. **Output:**
   - The program outputs the calculated minimum number of trucks needed and the warehouse size required in the central city.

### Example Walkthrough:

Let's go through the given example step by step, showing how the program calculates the required statistics.

### Input:
```
9 10
8 3 2 20 11 7 4 9 5
5 7 4 10 6 4 4 5 3
2 3 0 3 3 2 4 4 6
```

### Steps:
1. **Graph Representation:**
   - The program creates a graph based on the input, representing cities and their direct transportation connections.

2. **Truck Capacity and Warehouse Management:**
   - The program calculates the required truck capacity and manages warehouse sizes based on product production and storage.

3. **BFS for Calculation:**
   - The program uses BFS to traverse the graph and calculate the minimum number of trucks needed and the warehouse size required in the central city.

4. **Output:**
   - The program outputs the calculated minimum number of trucks needed and the warehouse size required in the central city.

### Conclusion:

The program effectively calculates the minimum number of trucks needed for efficient product transportation and determines the warehouse size required in the central city to accommodate all products. It utilizes appropriate calculations and graph traversal (BFS) to determine the necessary statistics.

If you have any more specific questions or need further clarification, feel free to ask!
*/