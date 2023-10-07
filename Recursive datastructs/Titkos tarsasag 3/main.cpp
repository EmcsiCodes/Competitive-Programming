#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
**Problem Summary:**

A secret organization is hierarchically structured, where each member knows only their immediate superior and subordinates. There is exactly one member in the organization who has no superior. Any member can send a letter to any other member. Within the organization, letters are forwarded in a way that in each step, the letter is either sent to the immediate superior or the immediate subordinate.

Write a program that, given two members X and Y, calculates:

1. If only subordinates can send letters, whether X can send a letter to Y or not.
2. If both subordinates and superiors can send letters, how many steps a letter sent from X to Y would take to reach Y.
3. The total number of subordinates (not just direct ones) for both X and Y.

**Input:**

- The number of members in the organization (N), and the serial numbers of two individuals, X and Y.
- The next N-1 lines represent the hierarchy. In the i-th line, an integer denotes the superior of the i-th member. The head of the organization is the member with serial number 1, and they have no superior.

**Output:**

- First, print a number: 1 if X can send a letter to Y when only subordinates can send letters, 2 if Y can send a letter to X, and 3 otherwise.
- Next, print the number of steps it would take for a letter sent from X to reach Y if both subordinates and superiors can send letters.
- Finally, print the number of subordinates (including indirect ones) for both X and Y.

**Example:**

**Input:**
```
7 2 3
1
1
3
2
3
3
```

**Output:**
```
3
2
1 3
```

---
*/
int n,a,b;
vector<int> adj[10001];

struct triple{
    int a;
    int b;
    int c;
    int d;
};

vector<int> BFS(int start,vector<int>&parent){
    queue<int> q;
    vector<int> dis(n+1,-1);
    dis[start] = 0;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            dis[i] = dis[node] + 1;
            parent[i] = node;
            if(i!=a && i!=b) q.push(i);
        }
    }
    return dis;
}

int DFS(int node){
    int curr = 1;
    for(auto i:adj[node]){
        curr += DFS(i);
    }
    return curr;
}

int main()
{
    cin>>n>>a>>b;
    for(int i=2; i<=n; i++){
        int x;
        cin>>x;
        adj[x].push_back(i);
    }
    vector<int> parent(n+1,0);
    vector<int> dis = BFS(1,parent);
    int root1 = a;
    int root2 = b;
    int d = 0;
    triple res;
    while(root1!=root2 && root1!=0 && root2!=0){
        if(dis[root1] > dis[root2]) root1 = parent[root1];
        else root2 = parent[root2];
        d++;
    }
    res.a = 3;
    if(root1 == a) res.a = 1;
    if(root2 == b) res.a = 2;
    res.b = d;
    res.c = DFS(a) - 1;
    res.d = DFS(b) - 1;
    cout<<res.a<<'\n'<<res.b<<'\n'<<res.c<<" "<<res.d;
    return 0;
}
/*
The given program addresses the problem of determining the communication possibilities within a secret organization hierarchy. The program calculates whether X can send a letter to Y, the steps required for a letter to reach Y from X, and the total number of subordinates (direct and indirect) for both X and Y.

Here's a breakdown of the approach and the implementation:

### Approach:

1. **Graph Representation:**
   - The program represents the organization's hierarchy as a directed graph, where each node represents a member, and edges represent the superior-subordinate relationships.

2. **BFS for Distance and Parent Calculation:**
   - The program uses Breadth-First Search (BFS) to calculate the distance and parent nodes from the head (member 1) to all other members in the hierarchy.

3. **Distance Calculation:**
   - The program calculates the distance from X to Y based on their parents obtained from the BFS traversal.

4. **Subordinate Counting:**
   - The program uses Depth-First Search (DFS) to count the total number of subordinates for both X and Y.

5. **Determining Communication Possibilities:**
   - The program determines whether X can send a letter to Y when only subordinates can send letters, if Y can send a letter to X, or if both can't communicate.

6. **Output:**
   - The program outputs the determined communication possibilities, the steps for a letter to reach Y from X, and the number of subordinates for both X and Y.

### Implementation:

1. **Graph Representation:**
   - The program uses an adjacency list to represent the graph, where each member stores its direct subordinates.

2. **BFS for Distance and Parent Calculation:**
   - The program performs a BFS traversal from the head (member 1) to calculate the distance and parent nodes for all members.

3. **Distance Calculation:**
   - The program calculates the distance from X to Y based on their parent nodes obtained from the BFS traversal.

4. **Subordinate Counting:**
   - The program uses DFS traversal to count the total number of subordinates for both X and Y.

5. **Determining Communication Possibilities:**
   - The program determines whether X can send a letter to Y when only subordinates can send letters, if Y can send a letter to X, or if both can't communicate based on the calculated distances.

6. **Output:**
   - The program outputs the determined communication possibilities, the steps for a letter to reach Y from X, and the number of subordinates for both X and Y.

### Example Walkthrough:

Let's go through the given example step by step, showing how the program calculates the required statistics.

### Input:
```
7 2 3
1
1
3
2
3
3
```

### Steps:
1. **Graph Representation:**
   - The program creates a graph based on the input, representing members and their superior-subordinate relationships.

2. **BFS for Distance and Parent Calculation:**
   - The program performs a BFS traversal to calculate the distance and parent nodes from the head to all other members.

3. **Distance Calculation:**
   - The program calculates the distance from X to Y based on their parent nodes obtained from the BFS traversal.

4. **Subordinate Counting:**
   - The program uses DFS traversal to count the total number of subordinates for both X and Y.

5. **Determining Communication Possibilities:**
   - The program determines whether X can send a letter to Y when only subordinates can send letters, if Y can send a letter to X, or if both can't communicate based on the calculated distances.

6. **Output:**
   - The program outputs the determined communication possibilities, the steps for a letter to reach Y from X, and the number of subordinates for both X and Y.

### Conclusion:

The program effectively calculates the communication possibilities and related statistics within the secret organization hierarchy. It utilizes appropriate BFS and DFS traversals to determine whether members can send letters and the required steps for communication.

If you have any more specific questions or need further clarification, feel free to ask!
*/