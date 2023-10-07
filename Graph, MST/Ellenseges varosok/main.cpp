#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
- **Problem Name**: Ellenséges városok (Hostile Cities)

- **Problem Description**:
  In the kingdom of Bergengócia, cities harbor animosity towards their neighboring cities. The king plans to upgrade existing dirt roads to expressways in a way that allows reaching any city from any other city via these expressways. However, due to animosity, the king wants to prevent citizens from reaching neighboring cities too quickly via the expressways. The goal is to design the road network so that cities connected by expressways are as far from each other as possible.

- **Task**:
  Write a program that calculates the minimum distance between two neighboring cities on the expressway network and specifies which roads need to be converted into expressways to achieve the maximum possible distance.

- **Input**:
  - The first line contains the number of cities, N (1 ≤ N ≤ 20,000), and the number of existing dirt roads, M (1 ≤ M ≤ 500,000).
  - The next M lines each contain three integers: the starting city, the ending city, and the length of the road (1 ≤ Ki ≠ Vi ≤ N, 1 ≤ lengthi ≤ 1000).

- **Output**:
  - The program should output the shortest path length on the expressway network.
  - The next line should contain exactly N-1 integers, indicating the road numbers (as per the input order) to be converted into expressways.

- **Example**:
  - **Input**:
    ```
    7 9
    2 1 2
    2 5 6
    1 3 3
    5 3 4
    3 4 4
    3 6 8
    3 7 2
    6 5 1
    6 7 5
    ```
  - **Output**:
    ```
    3
    6 2 9 4 5 3
    ```

- **Constraints**:
  - Time Limit: 0.5 seconds
  - Memory Limit: 32 MiB
  - In 30% of the tests, N ≤ 100.
*/
vector<int> parent(20001,0);
vector<int> s(20001,1);
struct edges{
    int node1;
    int node2;
    int d;
    int i;
};
struct Compare {
    bool operator()(edges const& p1, edges const& p2)
    {
        return p1.d < p2.d;
    }
};
priority_queue<edges, vector<edges>, Compare> pq;

int find(int a){
    int root = a;
    while(parent[root]!=root){
        root = parent[root];
    }
    while(a != root){
        int next = parent[a];
        parent[a] = root;
        a = next;
    }
    return root;
}

void Unite(int a,int b){
    int root1 = find(a);
    int root2 = find(b);
    if(s[root1]<s[root2]){
        parent[root1] = root2;
        s[root2] += s[root1];
    } else {
        parent[root2] = root1;
        s[root1] += s[root2];
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int x,y,z;
        cin>>x>>y>>z;
        pq.push({x,y,z,i});
    }
    for(int i=1; i<=n; i++) parent[i] = i;
    int minMax = 1000000;
    vector<int> res;
    while(!pq.empty()){
        edges curr = pq.top();
        pq.pop();
        if(find(curr.node1)!=find(curr.node2)){
            Unite(curr.node1,curr.node2);
            minMax = min(minMax,curr.d);
            res.push_back(curr.i);
        }
    }
    cout<<minMax<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
The provided program addresses the problem of designing a road network in a kingdom with animosity between cities. The goal is to minimize the shortest distance between neighboring cities on the expressway network while converting specific dirt roads into expressways.

Here's a breakdown of the program:

1. **Input Reading:**
   - Read the number of cities (N) and the number of existing dirt roads (M).
   - Read the details of existing dirt roads, including the starting city, ending city, and road length.

2. **Union-Find Data Structure:**
   - Initialize a Union-Find data structure to keep track of connected components (disjoint sets) and their sizes.
   - Each city is initially considered as a separate connected component.

3. **Minimum Distance Calculation:**
   - Use a priority queue (min heap) to select the next road to be considered.
   - Pop the shortest road from the priority queue, check if it connects different components, and merge the components if needed.
   - Track the minimum distance encountered.

4. **Output:**
   - Output the shortest possible distance between neighboring cities on the expressway network.
   - Output the road numbers (as per input order) that need to be converted into expressways.

### Output:
The program outputs the shortest possible distance between neighboring cities on the expressway network and specifies the roads to be converted into expressways to achieve this.

The program seems to be correctly solving the problem by minimizing the shortest distance between neighboring cities on the expressway network.
*/
