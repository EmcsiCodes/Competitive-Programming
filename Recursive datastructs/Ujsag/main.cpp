#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
**Problem Summary:**

A magazine distribution company transports newspapers by train to the respective addresses every day. Magazines are printed at a central location, loaded onto a train, and sent off. At railway junctions, they are transferred to trains heading in the appropriate directions. For each railway junction, we know from where they directly receive the magazine packages.

Write a program that, given two railway junctions A and B, determines:

1. How many more places the magazines from A will be further transported to.
2. How many times the magazines destined for A need to be transferred to another train.
3. How far, at most, the magazines destined for both A and B can be transported together.

**Input:**

- The first line of the standard input contains the number of railway junctions (N) and the serial numbers of two junctions, A and B, separated by a space.
- The next N-1 lines each contain two serial numbers, I and J, which mean that magazines are transported from junction J to junction I.

**Output:**

- In the standard output, print the answers to the first, second, and third questions in three lines, respectively.

**Example:**

**Input:**
```
9 1 3
1 5
2 4
3 4
5 6
7 6
4 5
9 8
8 1
```

**Output:**
```
2 {to 8 and 9}
1 {to 5}
5 {up to 5}
```

---
*/
int a,b;
vector<int> adj[1001];

vector<int> BFS(int start,int n,vector<int>&parent){
    vector<bool> visited(n+1,false);
    vector<int> dis(n+1,0);
    visited[start] = true;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                dis[i] = dis[node] + 1;
                parent[i] = node;
                if(i!=a && i!=b) q.push(i);
                visited[i] = true;
            }
        }
    }
    return dis;
}

int main()
{
    int n;
    cin>>n>>a>>b;
    vector<int> degree(n+1,0);
    vector<int> parent(n+1,0);
    for(int i=1; i<n; i++){
        int x,y;
        cin>>x>>y;
        adj[y].push_back(x);
        degree[x]++;
    }
    int start = 0;
    for(int i=1; i<=n; i++){
        if(degree[i] == 0){
            start = i;
            break;
        }
    }
    vector<int> res1 = BFS(a,n,parent);
    int resq = 0;
    for(int i=1; i<=n; i++){
        if(res1[i]!=0) resq++;
    }
    vector<int> res = BFS(start,n,parent);
    cout<<resq<<'\n'<<res[a] - 1<<'\n';
    while(a!=b){
        if(res[a]>res[b]) a = parent[a];
        else b = parent[b];
    }
    cout<<a;
    return 0;
}
/*
The provided program addresses the problem of determining various statistics related to the transportation of magazines between railway junctions. The program calculates how many more places the magazines from junction A will be further transported to, how many times the magazines destined for junction A need to be transferred to another train, and how far, at most, the magazines destined for both junctions A and B can be transported together.

Here's a breakdown of the approach and the implementation:

### Approach:

1. **Graph Representation:**
   - The program represents the railway junctions and their magazine transportation relationships as a directed graph, where each node represents a junction, and edges represent the transportation direction.

2. **BFS for Distance Calculation:**
   - The program uses Breadth-First Search (BFS) to calculate the distances (in terms of number of junctions) from junctions A and B to all other junctions.

3. **Statistics Calculation:**
   - The program calculates the required statistics based on the obtained distances from the BFS traversal.

4. **Output:**
   - The program outputs the calculated statistics in the required format.

### Implementation:

1. **Graph Representation:**
   - The program uses an adjacency list to represent the graph, where each junction stores its direct transport relationships.

2. **BFS for Distance Calculation:**
   - The program performs a BFS traversal from the starting junction (either A or B) to calculate the distances (in terms of number of junctions) to all other junctions.

3. **Statistics Calculation:**
   - The program calculates how many more places the magazines from junction A will be further transported to and how many times the magazines destined for junction A need to be transferred to another train based on the distances obtained from BFS.
   - It also calculates how far, at most, the magazines destined for both junctions A and B can be transported together.

4. **Output:**
   - The program outputs the calculated statistics in the required format.

### Example Walkthrough:

Let's go through the given example step by step, showing how the program calculates the required statistics.

### Input:
```
9 1 3
1 5
2 4
3 4
5 6
7 6
4 5
9 8
8 1
```

### Steps:
1. **Graph Representation:**
   - The program creates a graph based on the input, representing the railway junctions and their transportation relationships.

2. **BFS for Distance Calculation:**
   - The program performs BFS traversals from junctions A and B to calculate the distances (number of junctions) to all other junctions.

3. **Statistics Calculation:**
   - The program calculates how many more places the magazines from junction A will be further transported to, how many times the magazines destined for junction A need to be transferred, and how far, at most, the magazines destined for both junctions A and B can be transported together.

4. **Output:**
   - The program outputs the calculated statistics in the required format.

### Conclusion:

The program effectively calculates the transportation statistics for magazines between the specified railway junctions. It utilizes appropriate BFS traversal to determine distances and related statistics.

If you have any more specific questions or need further clarification, feel free to ask!
*/