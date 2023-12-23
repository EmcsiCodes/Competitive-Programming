#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
- **Problem Name**: Malmokból szállítás (Transportation from Mills)

- **Problem Description**:
  The Mill Industry Company operates in K mills, grinding and packaging flour. The flour needs to be transported to N cities, minimizing the total length of roads used for transportation.

- **Task**:
  Write a program that determines the total length of roads used for transportation and the direct routes from each city to another.

- **Input**:
  - The first line contains the number of cities N (1 ≤ N ≤ 10,000), the number of mills M (1 ≤ M ≤ N), and the number of direct road segments U (1 ≤ U ≤ 1,000,000).
  - The second line contains M distinct integers, representing the cities where mills are located (1 ≤ Milli ≤ N).
  - The next U lines contain two integers Ai and Bi, representing a direct road segment between cities Ai and Bi, and the length of the road (1 ≤ Ki ≤ 1000).

- **Output**:
  - The program should output the total length of roads used for transportation.
  - The next line should contain N integers representing the cities from which a truck directly goes to each city. For cities with a mill, the output should be 0.

- **Example**:
  - **Input**:
    ```
    7 2 9
    3 6
    1 4 10
    1 3 10
    2 3 10
    3 4 10
    3 5 30
    4 5 15
    5 6 10
    5 7 5
    6 7 30
    ```
  - **Output**:
    ```
    45
    3 3 0 3 6 0 5
    ```

- **Constraints**:
  - Time Limit: 0.8 seconds
  - Memory Limit: 64 MiB
  - In 30% of the tests, N ≤ 100.
*/
struct nodes{
    int node1;
    int node2;
    long long d;
};
struct Compare{
    bool operator()(nodes const& p1,nodes const& p2){
        return p1.d > p2.d;
    }
};
vector<int> s(10001,1), parent(10001,0);
vector<int> adj[10001], startNodes;
vector<bool> visited(10001,false);
priority_queue<nodes,vector<nodes>, Compare> pq;
int find(int a){
    int root = a;
    while(root!=parent[root]) root = parent[root];
    while(a!=root) {
        int next = parent[a];
        parent[a] = root;
        a = next;
    }
    return root;
}

void Union(int a,int b){
    int root1 = find(a);
    int root2 = find(b);
    if(s[root1]<s[root2]){
        parent[root1] = parent[root2];
        s[root2] += s[root1];
    } else {
        parent[root2] = parent[root1];
        s[root1] += s[root2];
    }
}

void BFS(int start){
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
                parent[i] = node;
            }
        }
    }
    parent[start] = 0;
}

int main()
{
    int n,k,m;
    cin>>n>>k>>m;
    for(int i=1; i<=k; i++){
        int x;
        cin>>x;
        s[x] = 25000;
        startNodes.push_back(x);
    }
    for(int i=1; i<=m; i++){
        int x,y;
        long long z;
        cin>>x>>y>>z;
        pq.push({x,y,z});
    }
    for(int i=1; i<=n; i++) parent[i] = i;
    long long minDis = 0;
    while(!pq.empty()){
        nodes curr = pq.top();
        int root1 = find(curr.node1);
        int root2 = find(curr.node2);
        pq.pop();
        if(root1!=root2 && !(s[root1]>=25000 && s[root2]>=25000)){
            Union(curr.node1,curr.node2);
            adj[curr.node1].push_back(curr.node2);
            adj[curr.node2].push_back(curr.node1);
            minDis += curr.d;
        }
    }
    cout<<minDis<<'\n';
    for(auto i:startNodes){
        BFS(i);
    }
    for(int i=1; i<=n; i++){
        cout<<parent[i]<<" ";
    }
    return 0;
}
/*
The provided program addresses the problem of minimizing the total length of roads used for transportation in a network of cities and mills. It also specifies the direct routes from each city to another using a priority queue (min heap) and a union-find data structure.

Here's a breakdown of the program:

1. **Input Reading:**
   - Read the number of cities (N), the number of cities containing a mill (K), and the number of direct road segments (U).
   - Read the cities where mills are located.
   - Read the details of direct road segments, including the starting city, destination city, and road length.

2. **Union-Find Data Structure:**
   - Initialize a Union-Find data structure to keep track of connected components (disjoint sets) and their sizes.
   - Each city is initially considered as a separate connected component.

3. **Minimum Distance Calculation:**
   - Use a priority queue (min heap) to select the shortest direct road segments.
   - Pop the shortest road from the priority queue, check if it connects different components, and merge the components if needed.
   - Track the total reinforced road length.

4. **Breadth-First Search (BFS):**
   - Perform BFS from each city that has a mill to determine the direct routes from the city to all other cities.
   - Store the parent of each city in the BFS tree.

5. **Output:**
   - Output the total length of the reinforced roads.
   - Output the direct routes from each city to another.

### Output:
The program outputs the total length of the reinforced roads and specifies the direct routes from each city to another.

The program appears to be correctly solving the problem by minimizing the total route length and specifying the direct routes from cities to mills.
*/