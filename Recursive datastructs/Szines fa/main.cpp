#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
**Problem Summary:**

You are given a tree with N nodes rooted at node 1. Design a program that determines the maximum number of colors that can be assigned to the nodes of the tree in such a way that for each node, all colors are present either among its ancestors or descendants (including itself). Also, provide a possible coloring for the nodes.

**Input:**

- The first line of the standard input contains the number of nodes in the tree (2 ≤ N ≤ 200,000).
- The second line contains N-1 numbers, where the i-th number is the immediate parent of node i+1 (1 ≤ Si ≤ N, Si ≠ i).

**Output:**

- The first line of the standard output should contain the maximum number of colors that can be used to color the nodes in the tree such that each node has all colors among its ancestors or descendants (including itself).
- The second line should contain the color assigned to each node in a possible coloring.

**Example:**

**Input:**
```
5
1 2 1 3
```

**Output:**
```
2
2 1 1 1 1
```

**Explanation:**
- We can use 2 colors. For example, color 1 and color 2. The color of node 1 doesn't matter as it has no parent.

---

**Note:**

The example provided is illustrative and does not represent the actual solution for the given input. The actual calculation for the maximum number of colors and the coloring needs to be based on the tree structure provided in the input.
*/
vector<int> adj[200001];

int main()
{
    int n;
    cin>>n;
    vector<int> outdegree(n+1,0);
    for(int i=2; i<=n; i++){
        int x;
        cin>>x;
        adj[x].push_back(i);
        outdegree[x]++;
    }
    queue<int> q;
    q.push(1);
    vector<int> dis(n+1,1); 
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            dis[i] = dis[node] + 1;
            q.push(i);
        }
    }
    int minColor = 1000000;
    for(int i=1; i<=n; i++){
        if(outdegree[i] == 0) minColor = min(minColor, dis[i]);
    }
    cout<<minColor<<'\n';
    vector<int> color(n+1,0);
    q.push(1);
    color[1] = minColor;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            color[i] = color[node] == 1 ? 1 : color[node] - 1;
            q.push(i);
        }
    }
    for(int i=1; i<=n; i++) cout<<color[i]<<" ";
    return 0;
}
/*
The provided C++ program aims to determine the maximum number of colors that can be assigned to the nodes of a tree while satisfying the specified conditions. Here's a detailed explanation of the code:

### Approach and Algorithm:

1. **Tree Representation:**
   - The input tree is represented using an adjacency list, where each node contains a list of its children.

2. **Color Assignment:**
   - The algorithm assigns colors to the nodes in a way that each node has all colors among its ancestors or descendants (including itself).
   - The color assignment process ensures that the color of a node is different from the colors of its ancestors.
   - The minimum color needed for a node is determined based on its depth in the tree.

3. **BFS for Color Assignment:**
   - A BFS traversal is performed to assign colors to the nodes while ensuring the color constraints.
   - The minimum color needed for each node is determined based on its depth in the tree.

4. **Output:**
   - The program outputs the maximum number of colors that can be used and the color assigned to each node in a possible coloring.

### Detailed Walkthrough of the Code:

1. **Data Structures:**
   - `vector<int> adj[200001]`: Represents the tree's structure as an adjacency list.
   - `vector<int> outdegree(n+1,0)`: Stores the outdegree (number of children) for each node.
   - `vector<int> dis(n+1,1)`: Stores the depth (distance from root) for each node.
   - `vector<int> color(n+1,0)`: Stores the color assigned to each node.

2. **BFS for Color Assignment:**
   - The program uses a BFS traversal to determine the minimum color needed for each node based on its depth (distance from the root).
   - After determining the minimum color for each node, it assigns colors accordingly using BFS.

3. **Main Function (`main`):**
   - Reads input, initializes data structures, and performs BFS for color assignment.
   - Outputs the maximum number of colors and the color assigned to each node.

### Example Walkthrough:

Let's walk through the given example and observe how the program calculates the maximum number of colors and the color assignment for each node.

### Input:
```
5
1 2 1 3
```

### Steps:
1. **Tree Representation:**
   - The input tree is represented using an adjacency list. Each node corresponds to a gang member, and each edge corresponds to a superior-subordinate relationship.

2. **BFS for Color Assignment:**
   - BFS is performed to calculate the minimum color needed for each node based on its depth (distance from the root).
   - Colors are assigned accordingly, ensuring that each node has all colors among its ancestors or descendants.

3. **Output (`cout` statements):**
   - The program outputs the maximum number of colors and the color assigned to each node.

### Conclusion:

The program effectively implements an algorithm to determine the maximum number of colors that can be assigned to the nodes of a tree while satisfying the specified conditions. It calculates the minimum color needed for each node based on its depth and assigns colors accordingly, ensuring the required constraints are met.

If you have any more specific questions or need further clarification, feel free to ask!
*/