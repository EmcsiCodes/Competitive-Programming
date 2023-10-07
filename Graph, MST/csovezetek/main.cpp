#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
/*
- **Problem Name**: Csővezeték (Pipeline)

- **Problem Description**:
  In a country, there are K locations where oil refineries are built to produce gasoline from crude oil. There are also N petrol stations where the gasoline needs to be transported through pipelines from any of the oil refineries. The challenge is to design the pipeline network to minimize the total length while adhering to certain rules.

- **Task**:
  Write a program to determine which points (either an oil refinery or a petrol station) should be connected by pipelines to minimize the total pipeline length.

- **Input**:
  - The first line contains the number of oil refineries, K (1 ≤ K ≤ 100), and the number of petrol stations, N (1 ≤ N ≤ 3000).
  - The next K lines contain the coordinates of the oil refineries.
  - The following N lines contain the coordinates of the petrol stations.

- **Output**:
  - The program should output the length of the minimal pipeline network.
  - The next lines should each contain two integers, indicating the endpoints (either oil refinery or petrol station) that should be connected by a pipeline.

- **Example**:
  - **Input**:
    ```
    2 4
    100 100
    0 100
    -100 100
    100 0
    40 40
    150 -50
    ```
  - **Output**:
    ```
    400
    2 3
    1 4
    2 5
    4 6
    ```

- **Constraints**:
  - Time Limit: 0.8 seconds
  - Memory Limit: 84 MiB
  - In 30% of the tests, N ≤ 100.
*/
map<int, pair<int,int> > mp;
vector<int> parent(3001,0);
vector<int> s(3001,1);
struct edges{
    int d;
    int node1;
    int node2;
};
struct Compare {
    bool operator()(edges const& p1, edges const& p2)
    {
        return p1.d > p2.d;
    }
};
priority_queue<edges, vector<edges>, Compare> paths;

int find(int a){
    int root = a;
    while(root!=parent[root]){
        root = parent[root];
    }
    while(a != root){
        int next = parent[a];
        parent[a] = root;
        a = next;
    }
    return root;
}

void Union(int a,int b){
    int root1 = find(a);
    int root2 = find(b);
    if(s[root1] < s[root2]){
        s[root2] += s[root1];
        parent[root1] = root2;
    } else {
        s[root1] += s[root2];
        parent[root2] = root1;
    }
}

int main()
{
    int k,n;
    cin>>k>>n;
    for(int i=1; i<=k; i++){
        int x,y;
        cin>>x>>y;
        mp[i] = {x,y};
        s[i] = 30000;
    }
    for(int i=k+1; i<=k+n; i++){
        int x,y;
        cin>>x>>y;
        mp[i] = {x,y};
    }
    for(auto i:mp){
        for(auto j:mp){
            if(i.first!=j.first){
                int d = abs(j.second.first - i.second.first) + abs(j.second.second - i.second.second);
                edges curr = {d,i.first,j.first};
                paths.push(curr);
            }
        }
    }
    for(int i=1; i<=n+k; i++){
        parent[i] = i;
    }
    int minDis = 0;
    vector< pair<int,int> > res;
    while(!paths.empty()){
        edges curr = paths.top();
        paths.pop();
        int root1 = find(curr.node1);
        int root2 = find(curr.node2);
        if(!(s[root1]>=30000 && s[root2]>=30000) && root1!=root2){
            Union(curr.node1,curr.node2);
            minDis += curr.d;
            res.push_back({curr.node1,curr.node2});
        }
    }
    cout<<minDis<<'\n';
    for(auto i:res) cout<<i.first<<" "<<i.second<<'\n';
    return 0;
}
/*
The given program aims to determine the pipeline network to minimize the total length of pipelines that connect oil refineries and petrol stations. It uses a greedy approach and a Union-Find data structure to achieve this.

Here's a step-by-step explanation of the program:

1. **Input Reading:**
   - Read the number of oil refineries (K) and the number of petrol stations (N) from the standard input.
   - Read the coordinates of the oil refineries and petrol stations.

2. **Union-Find Data Structure:**
   - Initialize a Union-Find data structure to keep track of connected components (disjoint sets) and their sizes.
   - Each oil refinery and petrol station is initially considered as a separate connected component.

3. **Calculating Pipeline Lengths:**
   - Calculate the distances between all pairs of oil refineries and petrol stations.
   - Push the distances along with the corresponding endpoints (oil refineries and petrol stations) into a priority queue (min heap).

4. **Greedy Approach:**
   - Use a greedy approach to connect the endpoints (oil refineries and petrol stations) while minimizing the total length of pipelines.
   - Pop the shortest distance from the priority queue and connect the endpoints if they are not already in the same connected component.
   - Update the total pipeline length and merge the connected components using Union-Find.

5. **Output:**
   - Output the total minimal pipeline length and the connections between endpoints.

### Output:
The program outputs the minimal total pipeline length and the connections between endpoints (either oil refinery or petrol station) that should be connected by a pipeline.

The program seems to be working as expected to achieve the goal of minimizing the total pipeline length while adhering to the rules.
*/