#include <iostream>
#include <vector>
#include <queue>
#include <stack>
/*
"Számítógépes hálózat" (Computer Network):

In this problem, we are dealing with a computer network called ProtoNet, which initially consisted of separate networks, each using its unique protocol. These networks were interconnected, allowing communication between them. Each network still operates using its own protocol. The network hardware has been equipped with software that allows switching between different protocols when needed. The goal is to optimize network operations by determining the minimum number of protocol switches required to send a packet from one node to another and finding the path with the fewest switches.

- **Input**:
  - The input consists of:
    - The number of nodes (`N`).
    - The number of subnetworks (`M`).
    - For each subnetwork:
      - The node indices forming that subnetwork followed by a 0.
    - The number of direct transmission links between nodes (`K`).
    - For each link:
      - The indices of the two nodes forming the link (`X`, `Y`).
    - The source and destination node indices for which the transmission is being considered (`A`, `B`).

- **Output**:
  - The program needs to output:
    - The minimum number of protocol switches needed to send a packet from node `A` to node `B`.
    - A path from node `A` to node `B` that minimizes the number of protocol switches. If there is no path, output -1.

- **Example**:
  - **Input**:
    ```
    7 3
    1 3 5 0
    4 2 6 0
    7 0
    10
    1 2
    1 3
    1 4
    2 3
    2 5
    3 5
    3 6
    4 7
    5 6
    5 7
    1 7
    ```
  - **Output**:
    ```
    1
    1 3 5 7
    ```
  - **Explanation**: In the given network configuration and the specified transmission from node 1 to node 7, the optimal path that minimizes the number of protocol switches is 1 → 3 → 5 → 7, requiring only one switch.

- **Constraints**:
  - The constraints include limits on the number of nodes, subnetworks, and transmission links, ensuring feasible computation within a reasonable time.
*/
using namespace std;
#define INF 1000000
vector< pair<int,int> > adj[30001];

void DijkstraAlgo(int startNode,int endNode,int n){
    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;
    vector<int> dis(n+1,INF);
    vector<int> path(n+1,0);
    dis[startNode] = 0;
    pq.push({dis[startNode],startNode});
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        for(auto i:adj[node]){
            if(dis[i.first] > dis[node] + i.second){
                dis[i.first] = dis[node] + i.second;
                path[i.first] = node;
                pq.push({dis[i.first],i.first});
            }
        }
    }
    if(dis[endNode] == INF){
        cout<<-1;
        return;
    }
    stack<int> s;
    int i = endNode;
    while(i>0){
        s.push(i);
        i = path[i];
    }
    cout<<dis[endNode]<<'\n';
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<'\b';
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> nodes(n+1,0);
    for(int i=1; i<=m; i++){
        int x;
        while(cin>>x && x!=0){
            nodes[x] = i;
        }
    }
    int k; cin>>k;
    for(int i=1; i<=k; i++){
        int x,y,distance;
        cin>>x>>y;
        if(nodes[x]!=nodes[y]) distance = 1;
        else distance = 0;
        adj[x].push_back({y,distance});
        adj[y].push_back({x,distance});
    }
    int startNode, endNode;
    cin>>startNode>>endNode;
    DijkstraAlgo(startNode,endNode,n);
    return 0;
}
/*
Certainly! Let's dive into a more detailed and step-by-step explanation of the program's approach.

### 1. Graph Representation

The problem involves a network consisting of nodes and connections between them, each connection having a certain width (1 or 2) indicating the protocol used. The task is to find the shortest path considering these widths.

The program represents the network as a graph, where:
- Nodes are vertices in the graph.
- Connections (edges) between nodes are weighted based on the width of the connection (1 or 2).

### 2. Dijkstra's Algorithm

Dijkstra's algorithm is employed to find the shortest path in the graph, considering the weights on the edges (representing protocol switches). Here's a high-level overview of Dijkstra's algorithm:

- **Initialization**:
  - Start by initializing a priority queue (min-heap) to store nodes based on their distances from the source node.
  - Create a distance array to keep track of the shortest known distance from the source node to each node. Initialize all distances to infinity (or a very large value), except the distance from the source node (which is 0).

- **Exploration**:
  - While the priority queue is not empty:
    - Pop a node from the priority queue (the one with the smallest known distance).
    - For each neighboring node, update its distance if a shorter path is found from the current node.
    - Update the priority queue accordingly.

- **Termination**:
  - The distances array now holds the shortest distances from the source node to all other nodes.

### 3. Handling Protocols and Switches

In this problem, we're particularly interested in the weights of the edges (connections) which represent the need for protocol switches. The weights are determined based on whether the nodes are part of the same subnetwork or not.

- If two nodes are part of the same subnetwork, the edge weight is 0 (no protocol switch required).
- If they are part of different subnetworks, the edge weight is 1 (a protocol switch is required).

### 4. Finding the Minimum Switch Path

Using Dijkstra's algorithm with the customized edge weights (0 or 1), the program finds the shortest path that minimizes the number of protocol switches.

### 5. Output

The program outputs the minimum number of protocol switches needed and the path that achieves this minimum. The path represents the sequence of nodes from the source to the destination.

### 6. Example

For the provided example, the program uses Dijkstra's algorithm considering the edge weights (0 or 1) to determine the shortest path (minimizing protocol switches) from node 1 to node 7.

- The output provides the minimum number of switches required (1) and the path that achieves this (1 → 3 → 5 → 7).

By leveraging Dijkstra's algorithm with customized edge weights, the program efficiently calculates the optimal path that minimizes protocol switches, crucial for optimizing communication in the computer network.
*/