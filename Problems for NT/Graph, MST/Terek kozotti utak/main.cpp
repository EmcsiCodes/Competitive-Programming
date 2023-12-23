#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
- **Problem Name**: Terek közötti utak (Paths Between Spaces)

- **Problem Description**:
  In a city, there are different spaces, some with existing roads and some without. Roads need to be built between some spaces, but there's a budget constraint. Some areas have already been designated as roads by the municipal council. Building new roads or modifying existing ones involves costs.

- **Task**:
  Write a program that determines which roads should be built or modified to connect all spaces with the least cost.

- **Input**:
  - The first line contains the number of spaces N (0 < N ≤ 20,000), the total possible roads M (0 < M ≤ 500,000), and the number of existing roads K (0 ≤ K ≤ M).
  - The next M lines contain three numbers each: I, J, and S (1 ≤ I ≠ J ≤ M, 0 < S ≤ 1000), indicating a road from space I to space J with a cost of S.
  - The last line contains K integers representing the indices of already built roads.

- **Output**:
  - The program should output the total cost of the operation (excluding the cost of already built roads).
  - The next line should contain U, the number of roads to be built or modified.
  - The following line should contain U integers representing the indices of roads to be built or modified.

- **Example**:
  - **Input**:
    ```
    6 9 2
    1 2 3
    5 6 3
    1 4 2
    1 6 1
    2 3 2
    2 5 8
    2 6 6
    3 4 7
    4 5 5
    1 2
    ```
  - **Output**:
    ```
    5
    3
    4 3 5
    ```

- **Constraints**:
  - Time Limit: 0.1 seconds
  - Memory Limit: 32 MiB
  - In 30% of the tests, N ≤ 100.
*/
struct nodes{
    int node1;
    int node2;
    int d;
    int i;
};
struct Compare{
    bool operator()(nodes const& p1, nodes const& p2){
        return p1.d > p2.d;
    }
};
vector<nodes> in;
vector<int> parent(20001,0), s(20001,1);
priority_queue<nodes,vector<nodes>,Compare> pq;

int find(int a){
    int root = a;
    while(root!=parent[root]) root = parent[root];
    while(a!=root){
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
        s[root2] += s[root1];
        parent[root1] = root2;
    } else {
        s[root1] += s[root2];
        parent[root2] = root1;
    }
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1; i<=m; i++){
        int x,y,z;
        cin>>x>>y>>z;
        in.push_back({x,y,z,i});
        pq.push({x,y,z,i});
    }
    for(int i=1; i<=n; i++) parent[i] = i;
    for(int i=1; i<=k; i++){
        int x;
        cin>>x;
        nodes curr = in[x-1];
        Unite(curr.node1,curr.node2);
    }
    int minCost = 0;
    vector<int> res;
    while(!pq.empty()){
        nodes curr = pq.top();
        pq.pop();
        int root1 = find(curr.node1);
        int root2 = find(curr.node2);
        if(root1!=root2){
            Unite(curr.node1,curr.node2);
            minCost += curr.d;
            res.push_back(curr.i);
        }
    }
    cout<<minCost<<'\n'<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
The provided program aims to solve the problem of determining which roads should be built or modified to connect all spaces with the least cost. It utilizes a priority queue (min heap) and a union-find data structure to achieve this.

Here's a breakdown of the program:

1. **Input Reading:**
   - Read the number of spaces (N), the total possible roads (M), and the number of existing roads (K).
   - Read the details of the roads, including the starting space, destination space, and the cost of the road.
   - Read the indices of already built roads.

2. **Union-Find Data Structure:**
   - Initialize a Union-Find data structure to keep track of connected components (disjoint sets) and their sizes.
   - Each space is initially considered as a separate connected component.

3. **Minimum Cost Calculation:**
   - Use a priority queue (min heap) to select the roads with the least cost.
   - Pop the roads from the priority queue, check if they connect different components, and merge the components if needed.
   - Track the total cost of the operation.

4. **Output:**
   - Output the total cost of the operation (excluding the cost of already built roads).
   - Output the number of roads to be built or modified.
   - Output the indices of roads to be built or modified.

### Output:
The program outputs the total cost of the operation, the number of roads to be built or modified, and the indices of roads to be built or modified.

The program seems to correctly address the problem by minimizing the total cost of building or modifying roads.
*/