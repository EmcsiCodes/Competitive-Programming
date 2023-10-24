#include <iostream>

using namespace std;

/*
- **Problem Description**:
  In a computer network, we know the transmission speed between individual computers, which can be different in each direction and even unidirectional. We want to forward messages as quickly as possible between any two computers. We want to use a central server as the computer from which all other computers can be accessed as quickly as possible. The transmission speed of a route is the smallest transmission speed between neighboring computers on that route.

- **Task**:
  Create a program that determines the central computer.

- **Input**:
  - The first line of standard input contains the number of computers in the network (1 ≤ N ≤ 100) and the number of connections (1 ≤ K ≤ 10,000).
  - The next K lines describe individual connections: the indices of the two computers (1 ≤ Ai ≠ Bi ≤ N) and the transmission speed from A to B (1 ≤ Si ≤ 100,000).

- **Output**:
  - The program should output the index of a possible central server in the first line. If there are multiple solutions, output the one with the smallest index.

- **Example**:
  - **Input**:
    ```
    5 11
    1 3 5
    3 1 8
    1 2 1
    2 1 1
    3 2 1
    3 5 3
    5 3 8
    2 5 5
    5 2 8
    2 4 6
    4 2 8
    ```
  - **Output**:
    ```
    5
    ```

- **Constraints**:
  - Time Limit: 0.2 seconds
  - Memory Limit: 32 MB
*/

#define INF 1000000;
int spath[101][101];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            spath[i][j] = 0;
        }
    }
    for(int i=1; i<=m; i++){
        int x,y,z;
        cin>>x>>y>>z;
        spath[x][y] = z;
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i == j) continue;
                spath[i][j] = max(spath[i][j], min(spath[i][k], spath[k][j]));
            }
        }
    }
    pair<int,int> res = {0,0};
    for(int i=1; i<=n; i++){
        int curr = INF;
        for(int j=1; j<=n; j++){
            if( i == j ) continue;
            curr = min(spath[i][j],curr);
        }
        if(curr>res.first){
            res.first = curr;
            res.second = i;
        }
    }
    cout<<res.second;
    return 0;
}
/*
Absolutely, let's delve deeper into the algorithm and its rationale.

### Floyd-Warshall Algorithm for All Pairs Shortest Path

The Floyd-Warshall algorithm is a dynamic programming approach to solve the All Pairs Shortest Path (APSP) problem. In the context of this problem, it helps find the shortest transmission path between any two computers by considering all possible intermediate computers.

#### How It Works:

1. **Initialization**:
   - We start by initializing a 2D matrix `spath` to represent the transmission speeds between any two computers.
   - Initially, `spath[i][j]` is set to the direct transmission speed from computer i to computer j, or INF (a very large value) if there is no direct connection.

2. **Dynamic Programming Iteration**:
   - We iterate through all possible intermediate nodes (computers) and consider whether using a particular intermediate node would yield a shorter transmission path.
   - For each pair of computers `i` and `j`, we consider all possible intermediate nodes `k`.
   - We update `spath[i][j]` to the minimum of its current value and the sum of transmission speeds through `k`:
     - `spath[i][j] = min(spath[i][j], spath[i][k] + spath[k][j])`

#### Why Floyd-Warshall for This Problem:

- The Floyd-Warshall algorithm is used because it's efficient for finding the shortest paths between all pairs of nodes, which is what we need in this problem.
- Since we want to determine the central computer based on the smallest transmission speed to all other computers, this algorithm helps calculate the shortest transmission path between each pair of computers.

### Finding the Central Computer

After applying the Floyd-Warshall algorithm to compute the minimum transmission speeds between all pairs of computers, we need to find the central computer based on the maximum minimum transmission speed.

1. **Calculating Maximum Minimum Transmission Speed**:
   - For each computer (node), we calculate the maximum minimum transmission speed to all other nodes. This is the minimum transmission speed to any reachable node.
   - Essentially, for each node `i`, we find `max(min(spath[i][j]))` where `j` ranges over all nodes.

2. **Selecting the Central Computer**:
   - We select the computer with the highest maximum minimum transmission speed. This indicates the computer from which messages can be forwarded to other computers with the least delay.

#### Why This Identifies the Central Computer:

- By finding the computer with the highest maximum minimum transmission speed, we identify the computer from which messages can be sent to all other computers with the least delay.
- The central computer is the one that provides the most efficient communication to all other computers in the network.

The output of the program is the index of this central computer, which is the solution to the problem.

### Example Walkthrough:

In the provided example, we followed these steps, and the highest maximum minimum transmission speed was achieved from Computer 5 to others. Hence, Computer 5 is identified as the central computer.
*/