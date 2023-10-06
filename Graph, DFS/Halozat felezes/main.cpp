#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
Here's the summary of the problem "Hálózat felezés" (Network Halving):

- **Problem Description**:
  Given a network containing N nodes, with exactly one path between any two nodes,
  the network needs to be divided into two parts, A and B, each containing an equal number of nodes,
  through a series of cutting operations. Initially, the entire network belongs to part A.
  A cutting operation involves removing a direct edge between two nodes, U and V,
  in part A and connecting node V to a node in part B with a new direct edge.

- **Task**:
  Create a program that calculates the minimum number of cutting operations needed to create two parts, A and B, each containing an equal number of nodes.

- **Input**:
  - The first line of standard input contains the number of nodes N (1 ≤ N ≤ 4000, even number).
  - The following N-1 lines each contain the endpoints of a direct edge (1 ≤ Ai ≠ Bi ≤ N).

- **Output**:
  - The program should output the minimum number of cutting operations K needed to form two parts with an equal number of nodes.

- **Example**:
  - **Input**:
    ```
    6
    1 2
    1 3
    3 4
    3 5
    3 6
    ```
  - **Output**:
    ```
    2
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame. In 30% of the tests, N ≤ 100.
*/
/*
Logic Overview:
The program uses a breadth-first search (BFS) to traverse the network and calculate the distances
from the starting node to other nodes.
It aims to find the two nodes that, when cut, would create two subgraphs with an equal number of nodes.

Potential Issue:

The algorithm does not guarantee the optimal division into two parts with an equal number of nodes.
The current approach may not always produce the correct result for all network topologies.
*/


vector<int> adj[4001];
int maxDis = 0;
int maxDisIndex = 0;
int A = 0,B = 0, numA = 0,numB = 0;

void BFS(int start,int n){
    vector<bool> visited(n+1,false);
    vector<int> dis(n+1,0), path(n+1,0);
    queue<int> q;
    int num = 0;
    q.push(start);
    visited[start] = true;
    visited[A] = true;
    visited[B] = true;
    while(!q.empty()){
        num++;
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                dis[i] = dis[node] + 1;
                path[i] = node;
                if(dis[i] > maxDis){
                    maxDis = dis[i];
                    maxDisIndex = i;
                }
            }
        }
    }
    if(start != 1 && A==0){
        int mid = maxDis / 2;
        A = maxDisIndex;
        for(int i=1; i<mid; i++){
            A = path[A];
        }
        B = path[A];
    }
    if(start == A){
        numA = num;
    }
    if(start == B){
        numB = num;
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<n; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    BFS(1,n);
    BFS(maxDisIndex,n);
    BFS(A,n);
    BFS(B,n);
    cout<<abs(numA - numB);
    return 0;
}
/*

*/