#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
/*
- **Problem Name**: Villamosítás (Tramway)

- **Problem Description**:
  The mayor of Kukutyin has decided to introduce tram transportation in the city. The goal is to enable tram travel from any intersection to any other intersection directly or through transfers. The cost of building tram routes between intersections is known, and the mayor wants to achieve the tram network's construction with the minimum cost. The mayor also wants to know which road sections might be part of the solution with the lowest cost.

- **Task**:
  Write a program that determines the minimum overall cost and identifies the road sections that could be part of the tram route construction with the lowest cost.

- **Input**:
  - The first line contains the number of intersections N (2 ≤ N ≤ 10,000) and the number of road sections M (1 ≤ M ≤ 500,000).
  - The following M lines each contain two integers Ai, Bi (1 ≤ Ai ≠ Bi ≤ N) indicating an intersection pair, and the cost Ki (1 ≤ Ki ≤ 1000) for building the tram route on that section.

- **Output**:
  - The program should output the minimum overall cost for constructing the tram network.
  - The next line should contain U, the number of road sections that might be used in the tram network construction.
  - The following line should contain U integers in increasing order, representing the indices of the road sections in the input order that might be used in the tram network construction.

- **Example**:
  - **Input**:
    ```
    7 9
    1 2 1
    1 3 2
    2 5 2
    3 4 2
    5 4 2
    5 7 4
    7 4 3
    6 7 2
    3 6 4
    ```
  - **Output**:
    ```
    12
    7
    1 2 3 4 5 7 8
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
    bool operator()(nodes const& p1,nodes const& p2){
        return p1.d > p2.d;
    }
};
priority_queue<nodes,vector<nodes>,Compare> pq;
vector<int> parent(10001,0), s(10001,1);
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
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int x,y,z;
        cin>>x>>y>>z;
        pq.push({x,y,z,i});
    }
    for(int i=1; i<=n; i++) parent[i] = i;
    int num = 0, minCost = 0;
    set<int> res;
    while(!pq.empty()){
        nodes curr = pq.top();
        pq.pop();
        int root1 = find(curr.node1);
        int root2 = find(curr.node2);
        if(root1!=root2){
            minCost += curr.d;
            num++;
        }
        Unite(curr.node1,curr.node2);
        res.insert(curr.i);
        if(num == n-1){
            while(!pq.empty() && pq.top().d == curr.d){
                res.insert(pq.top().i);
                pq.pop();
            }
            break;
        }
    }
    cout<<minCost<<'\n'<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
The provided program addresses the problem of constructing a tram network in a city with intersections and associated costs for building tram routes between intersections. The goal is to minimize the overall cost for constructing the tram network while identifying the road sections that could be part of the solution with the lowest cost.

Here's a summary of the program's logic:

1. **Input Reading:**
   - Read the number of intersections (N) and the number of road sections (M).
   - Read the details of each road section, including the intersections it connects and the cost of building the tram route.

2. **Union-Find Data Structure:**
   - Initialize a Union-Find data structure to keep track of connected components (disjoint sets) and their sizes.
   - Each intersection is initially considered as a separate connected component.

3. **Minimum Overall Cost Calculation:**
   - Use a priority queue (min heap) to select the road sections with the least cost.
   - Merge connected components by adding the road sections to the tram network and calculating the minimum overall cost.

4. **Output:**
   - Output the minimum overall cost for constructing the tram network.
   - Output the number of road sections that might be used in the tram network construction.
   - Output the indices of the road sections that might be used in the tram network construction.

### Output:
The program outputs the minimum overall cost for constructing the tram network and the indices of road sections that might be used in the tram network construction.

The program appears to correctly solve the problem by minimizing the overall cost and identifying the road sections that contribute to the lowest cost.
*/