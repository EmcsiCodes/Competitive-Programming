#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;
/*
**Problem Summary:**

In the country of Binaryland, there are N cities connected by N-1 roads forming a binary tree. The capital city is labeled as 1. Due to a crisis, the president wants to impose road taxes on all roads. Economic advisors have suggested N-1 tax amounts, which would be allocated to each road. You need to determine the maximum possible revenue that the country can generate from these taxes.

For each allocation of tax amounts to roads, consider N-1 travelers, one from each city other than the capital, traveling to every other city. The revenue for a tax allocation is the total tax collected from these travelers, where each traveler pays the tax corresponding to the road they travel on.

Write a program to calculate the maximum possible revenue.

**Input:**

- The first line of the standard input contains the number of cities in Binaryland (1 ≤ N ≤ 50,000).
- The next N-1 lines each contain two integers, representing the endpoints of a road (1 ≤ ai ≠ bi ≤ N, where ai is closer to the capital than bi).
- The last line contains N-1 integers representing the possible tax amounts for each road (1 ≤ Wi ≤ 10^9).

**Output:**

- The first line of the standard output should contain the remainder of the maximum revenue modulo 32609.
- The subsequent lines should contain three numbers each: the endpoints of a road and the tax amount for this road in an optimal tax allocation. Each road should be listed exactly once.

**Example:**

**Input:**
```
5
1 2
2 3
1 4
2 5
5 6 3 1
```

**Output:**
```
144
5 2 5
1 2 6
2 3 3
4 1 1
```

---

**Note:**

The example is illustrative and not the actual calculation for the given input. The calculation for maximum revenue needs to be done based on the tax allocations provided in the input.
*/
int n;
struct f{
    int node1;
    int node2;
    int frequency;
};

struct Compare{
    bool operator()(f const& p1, f const& p2){
        return p1.frequency < p2.frequency;
    }
};

vector<int> adj[50001];
priority_queue<f, vector<f>, Compare> freqEdge;

int DFS(int node,vector<bool>&visited){
    visited[node] = true;
    int freq = 1;
    for(auto i:adj[node]){
        if(!visited[i]){
            int curr = DFS(i,visited);
            freqEdge.push({node,i,(curr * (n - curr))});
            freq += curr;
        }
    }
    return freq;
}

int main()
{
    cin>>n;
    for(int i=1; i<n; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> prices;
    for(int i=1; i<n; i++){
        int x;
        cin>>x;
        prices.push_back(x);
    }
    int start = 0;
    int totalPrice = 0;
    for(int i=1; i<=n; i++){
        if(adj[i].size() == 1){
            start = i;
            break;
        }
    }
    vector<f> res;
    vector<bool> visited(n+1,false);
    DFS(start,visited);
    sort(prices.begin(),prices.end(), greater<int>());
    auto it = prices.begin();
    while(!freqEdge.empty()){
        totalPrice = (totalPrice%32609 + ((freqEdge.top().frequency%32609 * 2)%32609 * (*it)%32609)%32609)%32609;
        res.push_back({freqEdge.top().node1, freqEdge.top().node2, (*it)});
        it++;
        freqEdge.pop();
    }
    cout<<totalPrice%32609<<'\n';
    for(auto i:res) {
       cout<<i.node1<<" "<<i.node2<<" "<<i.frequency<<'\n';
    }
    return 0;
}
/*
Certainly! Let's dive into a more detailed explanation of the provided C++ program that calculates the maximum possible revenue generated from road taxes in the country of Binaryland.

### Approach and Algorithm:

1. **Graph Representation:**
   - The cities and roads are represented as a graph, where each city is a node, and each road is an edge. The graph is represented using an adjacency list.

2. **Depth-First Search (DFS) for Frequency Calculation:**
   - The program performs a DFS traversal on the graph starting from the capital city (node 1).
   - During the DFS traversal, it calculates the frequency of each road by counting the number of nodes reachable from each road.
   - These frequencies are used to prioritize the tax allocation on roads.

3. **Greedy Approach for Tax Allocation:**
   - The tax amounts for each road are sorted in descending order.
   - The program uses a priority queue (`freqEdge`) to prioritize edges based on their frequency.
   - The highest tax amounts are allocated to the edges with the highest frequencies first.

4. **Revenue Calculation:**
   - The program calculates the total revenue generated from the tax allocations.
   - The total revenue is calculated as the sum of taxes collected from each traveler on each road.

5. **Output:**
   - The program outputs the total revenue and the optimal tax allocations for each road.

### Detailed Walkthrough of the Code:

1. **Data Structures:**
   - `struct f`: Represents an edge with its starting and ending nodes (`node1`, `node2`) and its frequency (`frequency`).
   - `priority_queue<f, vector<f>, Compare>`: Priority queue to sort edges based on their frequency in descending order.

2. **DFS for Frequency Calculation (`DFS` function):**
   - The `DFS` function calculates the frequencies of each edge using DFS traversal.
   - It traverses the graph, calculating the frequency of each edge and updating the priority queue accordingly.

3. **Main Function (`main`):**
   - Reads input, initializes data structures, and calculates edge frequencies using DFS.
   - Sorts the tax amounts in descending order.
   - Iterates over edges in descending frequency order, allocating taxes based on sorted tax amounts.
   - Calculates the total revenue generated from tax allocations.

4. **Output (`cout` statements):**
   - Outputs the total revenue.
   - Outputs the optimal tax allocations for each road.

### Example Walkthrough:

Let's walk through the given example and observe how the program calculates the maximum revenue and tax allocations.

### Input:
```
5
1 2
2 3
1 4
2 5
5 6 3 1
```

### Steps:
1. **Graph Representation:**
   - The graph is represented using an adjacency list. Each node corresponds to a city, and each edge corresponds to a road.

2. **DFS and Frequency Calculation:**
   - DFS is performed to calculate the frequencies of each edge. These frequencies are used for tax allocation.

3. **Greedy Approach and Tax Allocation:**
   - The tax amounts for roads are sorted in descending order.
   - Taxes are allocated to edges based on their frequencies in descending order.

4. **Revenue Calculation:**
   - The total revenue is calculated by summing the taxes collected from each traveler on each road.

5. **Output:**
   - The program outputs the total revenue and the optimal tax allocations for each road.

### Conclusion:

The program effectively implements a greedy algorithm to calculate the maximum possible revenue generated from road taxes in the country of Binaryland. It prioritizes tax allocation to roads based on their frequencies, ensuring optimal revenue collection.

If you have any more specific questions or need further clarification, feel free to ask!
*/