#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/*
- **Problem Description**:
  Binaryland consists of N cities connected by N-1 roads forming a binary tree, with city 1 as the capital. Due to an economic crisis, the president wants to impose road taxes on all the roads. Economic advisors have suggested N-1 tax amounts, one for each road.

- **Task**:
  Write a program that determines the maximum potential revenue that can be generated from the road taxes.

- **Input**:
  - The first line of standard input contains the number of cities in Binaryland, N (1 ≤ N ≤ 50,000).
  - The next N-1 lines each contain two integers a and b (1 ≤ a ≠ b ≤ N), representing a road between cities a and b, where a is closer to the capital.
  - The last line contains N-1 tax amounts Wi (1 ≤ Wi ≤ 10^9).

- **Output**:
  - The output should consist of the maximum revenue modulo 32609 on the first line.
  - The following lines should each contain three integers: u, v, and the tax amount corresponding to the road between cities u and v in a possible distribution that achieves the maximum revenue.

- **Example**:
  - **Input**:
    ```
    5
    1 2
    2 3
    1 4
    2 5
    5 6 3 1
    ```
  - **Output**:
    ```
    144
    5 2 5
    1 2 6
    2 3 3
    4 1 1
    ```

- **Constraints**:
  - Computation should be completed within 0.7 seconds.
  - Memory usage should not exceed 64 MiB.
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
        //cout<<freqEdge.top().frequency<<endl;
        totalPrice = (totalPrice%32609 + ((freqEdge.top().frequency%32609 * 2)%32609 * (*it)%32609)%32609)%32609;
        res.push_back({freqEdge.top().node1, freqEdge.top().node2, (*it)});
        it++;
        freqEdge.pop();
    }
    cout<<totalPrice%32609<<'\n';
    for(auto i:res) cout<<i.node1<<" "<<i.node2<<" "<<i.frequency<<'\n';
    return 0;
}
/*
The given program aims to determine the maximum potential revenue that can be generated from road taxes in Binaryland. It uses a priority queue to sort the edges based on a frequency calculated using a depth-first search (DFS) traversal.

Here's a step-by-step explanation of how the program works:

1. **Input Reading:**
   - Read the number of cities (N) from the standard input.
   - Read the N-1 lines describing the roads between cities.
   - Read the N-1 tax amounts for each road.

2. **Depth-First Search (DFS) and Frequency Calculation:**
   - Implement DFS to calculate the frequency for each edge based on the number of nodes in the subtree rooted at each edge.
   - Push the frequencies and corresponding edges into a priority queue.

3. **Sorting Tax Amounts:**
   - Sort the tax amounts in descending order.

4. **Calculating Maximum Revenue:**
   - Iterate through the priority queue, pop the edges, and calculate the revenue for each edge using the tax amounts and frequencies.
   - Accumulate the total revenue.

5. **Output:**
   - Output the maximum revenue modulo 32609.
   - Output each edge and its corresponding tax amount contributing to the maximum revenue.

### Output:
The program outputs the maximum revenue and the edges with their tax amounts contributing to this maximum revenue.

The program seems to be working correctly to calculate the maximum revenue and associated tax amounts. If you have any specific questions or concerns, feel free to ask!
*/