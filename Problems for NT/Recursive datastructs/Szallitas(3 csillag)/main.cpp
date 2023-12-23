#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
/*
**Problem Summary:**

A company operates production facilities in N cities and transports the weekly production to the central warehouse using K trucks. Due to constraints, each city (except the central warehouse) can have exactly one truck traveling directly to another city. The company can only employ K trucks, and each truck starts from its originating city and travels all the way to the central warehouse. The capacity of each truck is such that it can safely pick up the products produced in the cities it visits during its journey.

Write a program that determines the maximum number of cities from which products can be transported to the central warehouse using K trucks.

**Input:**

- The first line of the standard input contains the number of cities (1 ≤ N ≤ 20,000) and the number of trucks (1 ≤ K ≤ N).
- The second line contains N integers. The i-th integer represents the index of the city to which a truck can directly travel from the i-th city (A1 = 0, 1 ≤ Ai ≤ N). The first number in the line is 0, indicating that no truck can travel from there.

**Output:**

- The first line of the standard output should contain the maximum number of cities from which the products can be transported to the central warehouse using K trucks.
- The second line should contain exactly K city indices, representing the cities from which the trucks will start their journeys. The order is not important.

**Example:**

**Input:**
```
12 3
0 1 1 1 2 2 3 4 4 4 7 7
```

**Output:**
```
7
5 11 8
```

---
*/
vector<int> adj[20001];
multiset< pair<int,int> > maxRoute[20001], res;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> degree(n+1,0);
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        adj[i].push_back(x);
        degree[x]++;
    }
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(degree[i] == 0) {
            q.push(i);
            maxRoute[i].insert({0,i});
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        int next = adj[node][0];
        degree[next]--;
        auto currBest = maxRoute[node].end();
        currBest--;
        maxRoute[next].insert({currBest->first + 1, currBest->second});
        if(maxRoute[node].size()>1){
            for(auto it = maxRoute[node].begin(); it!=currBest; it++){
                res.insert(*it);
            }
        }
        if(degree[next] == 0) {
            q.push(next);
            if(next == 0) {
                res.insert({maxRoute[next].rbegin()->first - 1,maxRoute[next].rbegin()->second});
                q.pop();
            }
        }
    }
    int total = 0;
    vector<int> start;
    for(auto it = res.rbegin(); it!=res.rend() && k!=0; it++){
        total += it->first;
        start.push_back(it->second);
        k--;
    }
    cout<<total<<'\n';
    for(auto i:start) cout<<i<<" ";
    return 0;
}
/*
The provided program calculates the maximum number of cities from which products can be transported to the central warehouse using a specified number of trucks. It also determines the starting cities for these trucks. Here's a breakdown of the approach and the implementation:

### Approach:

1. **Graph Representation:**
   - The program represents the cities and the truck routes between them as a directed graph.

2. **Traversal and Truck Routes:**
   - The program traverses the graph to determine the maximum number of cities that can send products to the central warehouse using a specified number of trucks.
   - It calculates the optimal starting cities for these trucks.

3. **Output:**
   - The program outputs the maximum number of cities that can send products and the corresponding starting cities for the trucks.

### Implementation:

1. **Graph Representation:**
   - The program uses an adjacency list to represent the graph, where each city is a node and the truck route is a directed edge.

2. **Traversal and Truck Routes:**
   - The program starts by identifying the cities that have no outgoing truck routes.
   - It then iteratively traverses the graph to find the optimal truck routes and the maximum number of cities that can send products to the central warehouse.

3. **Output:**
   - The program outputs the maximum number of cities that can send products and the corresponding starting cities for the trucks.

### Example Walkthrough:

Let's go through the given example step by step to determine the maximum number of cities and the starting cities for the trucks.

### Input:
```
12 3
0 1 1 1 2 2 3 4 4 4 7 7
```

### Steps:
1. **Graph Representation:**
   - The program uses an adjacency list to represent the graph, where each city is a node and the truck route is a directed edge.

2. **Traversal and Truck Routes:**
   - The program traverses the graph iteratively to find the optimal truck routes and the maximum number of cities that can send products to the central warehouse.

3. **Output:**
   - The program outputs the maximum number of cities that can send products and the corresponding starting cities for the trucks.

### Conclusion:

The program effectively calculates the maximum number of cities from which products can be transported to the central warehouse using a specified number of trucks. It also determines the starting cities for these trucks, satisfying the problem's requirements.

If you have any more specific questions or need further clarification, feel free to ask!
*/