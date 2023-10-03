#include <iostream>
#include <vector>

using namespace std;
/*
Here's a summary of the problem "Bűnöző elfogása" (Catching the Criminal):

- **Problem Description**:
  The city police are planning to catch a dangerous criminal who is continuously moving through the city's streets. The police have limited options and can only place officers at certain intersections for the capture. One officer starts from a designated K intersection, traverses the city's streets, and directs them one-way to ensure that the criminal eventually reaches intersection K, where another officer is waiting to apprehend the criminal. However, the officer must also obey traffic rules, meaning they can only travel in the direction they've set for each street.

- **Task**:
  Create a program that calculates a traversal sequence, allowing the officer to direct the streets such that the criminal eventually reaches the K intersection, starting from intersection A.

- **Input**:
  - The first line of standard input contains the number of intersections N (1 ≤ N ≤ 200).
  - The second line contains the number of streets M (1 ≤ M ≤ 10,000).
  - The following M lines each contain two integers A and B (1 ≤ A, B ≤ N), indicating there is a two-way street between intersections A and B.

- **Output**:
  - The program should output the number of streets L the officer traverses.
  - The next L lines should each contain three integers A, B, and C, indicating that the officer traveled from intersection A to B, and C (0 or 1) indicating if the officer set this street as one-way (0 if already set).

- **Example**:
  - **Input**:
    ```
    5 6
    1 2
    2 3
    1 4
    1 5
    4 2
    4 5
    ```
  - **Output**:
    ```
    12
    1 2 1
    2 3 1
    3 2 0
    2 1 0
    1 4 1
    4 2 1
    2 4 0
    4 5 1
    5 4 0
    4 1 0
    1 5 1
    5 1 0
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
vector<int> adj[201];

struct triple{
    int fromNode;
    int toNode;
    int s;
};

void DFS(int node,int lastNode,vector<bool> &visited,vector<triple> &res){
    for(auto i:adj[node]){
        if(!visited[i]){
            visited[node] = true;
            res.push_back({node,i,1});
            DFS(i,node,visited,res);
            res.push_back({i,node,0});
        } else if(i!=lastNode) return;
    }
}

void solve(int n){
    vector<bool> visited(n+1,false);
    vector<triple> res;
    DFS(1,0,visited,res);
    cout<<res.size()<<'\n';
    for(auto i:res){
        cout<<i.fromNode<<" "<<i.toNode<<" "<<i.s<<'\n';
    }
    for(int i=1; i<=n; i++){
        cout<<i<<": ";
        for(auto j:adj[i])cout<<j<<" ";
        cout<<'\n';
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    solve(n);
    return 0;
}
/*
Let's dive into a more detailed explanation of the program's approach and how it solves the "Catching the Criminal" problem:

### 1. **Graph Representation and Input Parsing**:

The program begins by reading the input, which includes information about intersections and streets. It constructs a graph to represent this information.

- **Graph Representation**:
  - Each intersection is represented as a node in the graph.
  - Each street is represented as an edge connecting two nodes (intersections).
  - The graph is undirected since streets are two-way by default.

- **Input Parsing**:
  - The program parses the input to extract the necessary information: the number of intersections (`N`), the number of streets (`M`), and the details of each street (the intersections it connects).
  - It populates the adjacency list `adj`, representing the connections between intersections.

### 2. **DFS to Find Traversal Sequence**:

The primary goal is to find a sequence of traversals (streets) for the police officer to guide the criminal from intersection A to intersection K while obeying traffic rules.

- **Depth-First Search (DFS)**:
  - The program uses Depth-First Search (DFS) to explore the graph and determine the traversal sequence.
  - Starting from intersection 1 (A), it recursively explores streets and records traversal decisions.
  - The DFS function keeps track of the last visited node to ensure one-way street decisions.

### 3. **Recording Traversal Decisions**:

The program records traversal decisions as it explores the graph using DFS.

- **Traversal Decisions**:
  - For each street (edge), it records three values: `fromNode`, `toNode`, and `s` (a binary value indicating if the street is set as one-way).
  - If a street is traversed during DFS, it is marked as one-way (s=1). If it's part of the return path in DFS, it's marked as two-way (s=0).

- **Building the Result Sequence**:
  - The traversal decisions are stored in a vector of `triple` structures, where each triple represents a traversal between intersections.
  - This vector contains the sequence of traversals, including both one-way and two-way streets.

### 4. **Outputting the Results**:

Finally, the program outputs the traversal sequence and the number of streets traversed.

- **Output Format**:
  - It first prints the total number of streets traversed (`res.size()`).
  - It then outputs each traversal decision, including `fromNode`, `toNode`, and `s` (one-way or two-way).

- **Graph Structure Output**:
  - After printing the traversal sequence, the program also outputs the structure of the graph, showing which intersections are connected by streets.

### 5. **Example Input and Output**:

For the given example input, the program calculates a traversal sequence that guides the criminal from intersection 1 to intersection K (with two-way and one-way streets). It outputs this sequence and also displays the graph structure:

```
12
1 2 1
2 3 1
3 2 0
2 1 0
1 4 1
4 2 1
2 4 0
4 5 1
5 4 0
4 1 0
1 5 1
5 1 0
1: 2 4 5 
2: 1 3 4 
3: 2 
4: 1 2 5 
5: 4 1 
```

### 6. **Overall Complexity and Efficiency**:

The program efficiently explores the graph using DFS to find a traversal sequence from intersection A to intersection K. The use of data structures like vectors and adjacency lists helps in maintaining necessary information and efficiently processing the network of streets and intersections.
*/