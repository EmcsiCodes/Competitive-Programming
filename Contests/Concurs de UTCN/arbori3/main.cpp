#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <fstream>
using namespace std;

/*
The problem is to calculate the sum of distances for all possible traversals in a given tree.

**Problem Summary:**
Given a tree with n nodes and n-1 edges with specified lengths,
the task is to calculate the sum of distances for all permutations of nodes.

- The input consists of multiple test cases.
- For each test case, you are given the number of nodes (n) and the edges with their respective lengths.
- You need to find the sum of distances for all permutations of nodes in the tree.

A traversal in this context refers to moving from one node to another in the shortest path,
following the order of a permutation.

Your task is to determine the sum of distances for all permutations of nodes in the tree.

**Input:**
- The first line of each test case contains the number of nodes (n).
- The next n-1 lines contain three integers X, Y, and L separated by spaces,
representing an edge of length L between nodes X and Y.
- The file ends with a line containing a single 0.

**Output:**
- For each test case, print the sum of distances for all permutations of nodes, taken modulo 9999991.

**Constraints:**
- 2 ≤ n ≤ 10^5
- 1 ≤ L ≤ 10^6
- The number of tests does not exceed 20

**Example:**
*Input:*
```
3
1 2 1
1 3 2
0
```

*Output:*
```
24
```

In this example, we have a tree with 3 nodes and 2 edges.
The sum of distances for all permutations of nodes is 24.
*/

#define LL long long

struct edges{
    LL freq;
    int weight;
};

LL findFreq(int n,int node,vector<bool>&visited,vector< pair<int,int> > adj[],queue<edges>&q){
    visited[node] = true;
    LL currFreq = 1;
    for(auto i:adj[node]){
        if(!visited[i.first]){
            LL f = findFreq(n,i.first,visited,adj,q);
            q.push({(f * (n-f))%9999991,i.second});
            currFreq += f;
        }
    }
    return currFreq;
}

int main()
{
    ifstream in("arbori3.in");
    ofstream out("arbori3.out");
    int n;
    while(in>>n && n!=0){
        vector< pair<int,int> > adj[100001];
        queue<edges> q;
        LL c = 1;
        for(int i = 1; i < n; i++){
            c = (c * i)%9999991;
            int x,y,z;
            in>>x>>y>>z;
            adj[x].push_back({y,z});
            adj[y].push_back({x,z});
        }
        c = (c * 2)%9999991;
        int start = 0;
        for(int i=1; i<=n; i++){
            if(adj[i].size() == 1){
                start = i;
                break;
            }
        }
        vector<bool> visited(n+1,false);
        findFreq(n,start,visited,adj,q);
        LL res = 0;
        while(!q.empty()){
            res = (res + ((c * q.front().freq)%9999991 * q.front().weight)%9999991)%9999991;
            q.pop();
        }
        out<<res<<'\n';
    }
    return 0;
}
/*
1. **Tree Representation (Adjacency List):**
    The program starts by representing the given tree as an adjacency list.
    In this representation, each node contains a list of its adjacent nodes and the
    weights of the edges connecting them. This representation allows the program to
    efficiently traverse the tree and calculate distances.

2. **Breadth-First Search (BFS):**
    To find the frequencies of nodes in the tree, the program uses BFS.
    BFS is an efficient algorithm for traversing trees and graphs.
    It starts from a chosen node (in this case, an arbitrary node), explores all its neighbors,
    and then moves to their neighbors in a level-wise fashion.
    This traversal ensures that we visit all nodes in the tree and can compute their frequencies.

3. **Frequencies of Nodes:** 
    During the BFS traversal, the program maintains a count of the number of nodes visited
    so far (denoted as `currFreq`). For each node visited, it increments `currFreq`.
    This `currFreq` represents the number of nodes in the subtree rooted at the current node.
    When a node is visited, its frequency is calculated as `(currFreq * (n - currFreq)) % 9999991`,
    where `n` is the total number of nodes in the tree. This calculation is done to find
    the frequency of nodes on both sides of an edge.

4. **Contributions of Edges:**
    After finding the frequencies of nodes, the program calculates the contribution of
    each edge to the sum of distances for all permutations of nodes.
    The contribution of an edge is computed as the product of the frequency of nodes on one side
    of the edge and the weight of the edge. This calculation accounts for all possible permutations
    of nodes since it considers both directions of traversal along each edge.

5. **Final Result:**
    The program accumulates the contributions from all edges,
    applying modulo 9999991 to keep the result within bounds.
    This final result represents the sum of distances for all permutations of nodes in the tree.

6. **Efficiency:**
    The program efficiently calculates the result by using BFS to traverse the
    tree once and compute the frequencies of nodes.
    Then, it processes the edges to calculate contributions.
    This approach avoids the need for explicit enumeration of all permutations of nodes,
    which would be impractical for large trees.

In summary, this program works by efficiently traversing the tree,
calculating frequencies of nodes using BFS, and then considering the contributions of
each edge to compute the sum of distances for all permutations of nodes.
It leverages the properties of trees and BFS to achieve an efficient solution to the problem.
*/