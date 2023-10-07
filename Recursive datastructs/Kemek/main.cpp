#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
**Problem Summary:**

In an organization with N members, each member can have multiple direct subordinates, and the immediate superior of each member is known. One member, without any superior, is the head.

Write a program to determine:
1. Who is the head of the organization?
2. Who has the most direct subordinates?
3. Who is the "farthest" from the head?

**Input:**

- Number of members (N).
- N-1 lines, each containing two integers: the serial number of a member and the serial number of their immediate superior.

**Output:**

- The serial number of the head.
- The serial number of the member with the most direct subordinates.
- The serial number of the member "farthest" from the head.

**Example:**

**Input:**
```
6
2 1
3 1
6 3
5 4
4 2
```

**Output:**
```
1
1
5
```

---
*/
vector<int> adj[20001];

int mostDistant(int start,int n){
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
                visited[i] = true;
                dis[i] = dis[node] + 1;
                q.push(i);
            }
        }
    }
    int maxDis = 0;
    int maxDisI = 0;
    for(int i=1; i<=n; i++){
        if(maxDis < dis[i]){
            maxDis = dis[i];
            maxDisI = i;
        }
    }
    return maxDisI;
}

int main()
{
    int n;
    cin>>n;
    vector<int> degree(n+1,0);
    for(int i=1; i<n; i++){
        int x,y;
        cin>>x>>y;
        adj[y].push_back(x);
        degree[x]++;
    }
    int start = 0;
    int maxDegree = 0;
    int maxDegreeI = 0;
    for(int i=1; i<=n; i++){
        if(degree[i] == 0) start = i;
        if(maxDegree < adj[i].size()){
            maxDegree = adj[i].size();
            maxDegreeI = i;
        }
    }
    cout<<start<<'\n'<<maxDegreeI<<'\n'<<mostDistant(start,n);
    return 0;
}
/*
The provided program aims to determine three key pieces of information within an organization based on the hierarchical relationships between members:

1. The head of the organization (the member without any superior).
2. The member with the most direct subordinates.
3. The member "farthest" from the head in terms of hierarchical distance.

Here's a more detailed explanation of the approach and implementation:

### Approach:

1. **Graph Representation:**
   - The members and their hierarchical relationships can be represented as a directed graph, where nodes represent members, and directed edges indicate the superior-subordinate relationship.

2. **Calculating the Head:**
   - The head of the organization is the member without any superior, which means they have an in-degree of 0.

3. **Finding the Member with the Most Direct Subordinates:**
   - We calculate the in-degree for each member, which represents the number of direct subordinates they have.
   - The member with the highest in-degree has the most direct subordinates.

4. **Calculating the "Farthest" Member:**
   - We calculate the furthest member from the head in terms of hierarchical distance using a breadth-first search (BFS) starting from the head.
   - The member with the maximum distance from the head in the BFS traversal is considered the "farthest" member.

### Implementation:

1. **Graph Representation:**
   - The program uses an adjacency list to represent the directed graph, where each member (node) stores its immediate subordinates (outgoing edges).

2. **Head Calculation:**
   - The head is identified by finding the member with an in-degree of 0 (no superior).

3. **Most Direct Subordinates:**
   - In-degree for each member is calculated, and the member with the highest in-degree is considered to have the most direct subordinates.

4. **Farthest Member:**
   - BFS traversal is performed starting from the head to find the "farthest" member based on hierarchical distance.

5. **Output:**
   - The program outputs the serial numbers of the head, the member with the most direct subordinates, and the "farthest" member from the head.

### Example Walkthrough:

Let's go through the given example step by step, showing how the program calculates the required information.

### Input:
```
6
2 1
3 1
6 3
5 4
4 2
```

### Steps:
1. **Graph Representation:**
   - We create a directed graph based on the input where edges represent the superior-subordinate relationship.

2. **Head Calculation:**
   - The head is identified by finding the member with an in-degree of 0 (in this case, it's member 1).

3. **Most Direct Subordinates:**
   - We calculate in-degrees for each member and identify the member with the highest in-degree (in this case, it's member 1).

4. **Farthest Member:**
   - BFS traversal is performed starting from the head (member 1), and the member farthest from the head is found (in this case, it's member 5).

5. **Output:**
   - The output is the serial numbers of the head (1), the member with the most direct subordinates (1), and the "farthest" member from the head (5).

### Conclusion:

The program effectively determines the head of the organization, the member with the most direct subordinates, and the "farthest" member from the head based on the given hierarchical relationships. It utilizes a graph representation and BFS traversal to calculate the required information.

If you have any more specific questions or need further clarification, feel free to ask!
*/