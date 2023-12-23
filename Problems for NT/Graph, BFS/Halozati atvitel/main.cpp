#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
The problem revolves around a computer network where there are various nodes connected by communication links. Each link has a specific transmission speed.

The goal is to determine the maximum achievable transmission speed from a designated central node to every other node in the network. However, there's a constraint: the transmission path from the central node to any other node should have at most H links.

The given input includes:

N: the number of nodes in the network (indexed from 1 to N).
M: the number of direct links between nodes.
K: the central node from which transmission speeds are calculated.
H: the maximum number of links in the transmission path.
Following that, M lines describe each direct link, including the source node, the destination node, and the transmission speed of the link.

The output should contain N lines. Each line represents the maximum achievable transmission speed from the central node (K) to the respective node, considering the constraint of at most H links in the transmission path. If there's no feasible transmission, -1 is used to denote it.

The provided example can be illustrated as follows:

There are 5 nodes (N = 5).
6 direct links (M = 6) between various nodes with their respective transmission speeds.
The central node is 1 (K = 1).
The maximum allowed links in the transmission path are 2 (H = 2).
The program needs to calculate and output the maximum achievable transmission speeds from node 1 to all other nodes considering the constraints mentioned above.
*/
#define INF 100000
struct nodes{
    int node;
    int flow;
};
struct triple{
    int speed;
    int node;
    int h;
};
struct Compare {
    bool operator()(triple const& p1, triple const& p2)
    {
        return p1.speed < p2.speed;
    }
};
int n,m,k,start;
vector<nodes> adj[10001];

void DijkstraAlgo(vector<int> nodeSpeed){

    priority_queue<triple, vector<triple>, Compare> pq;
    nodeSpeed[start] = INF;
    pq.push({nodeSpeed[start],start,k});
    while(!pq.empty()){
        int node = pq.top().node;
        int h = pq.top().h;
        pq.pop();
        for(auto i:adj[node]){
            int currSpeed = min(nodeSpeed[node],i.flow);
            int currH = h - 1;
            if(currH >= 0){ 
                nodeSpeed[i.node] = max(currSpeed,nodeSpeed[i.node]); 
                pq.push({nodeSpeed[i.node],i.node,currH});
            }
        }
    }
    nodeSpeed[start] = 0;
    for(int i=1; i<=n; i++){
        cout<<nodeSpeed[i]<<'\n';
    }
}

int main()
{
    cin>>n>>m>>start>>k;
    vector<int> nodeSpeed(n+1,-1);
    for(int i=1; i<=m; i++){
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }
    DijkstraAlgo(nodeSpeed);
    return 0;
}
/*
This program implements Dijkstra's algorithm with a modification to consider the maximum number of links in the transmission path (H). Let's break down the code and understand it step by step.

Struct Definitions:

nodes struct represents a node and its flow.
triple struct represents the speed, node, and remaining hops (h).
Priority Queue Comparison:

Compare struct is a custom comparison function for the priority queue, comparing based on speed.
Dijkstra's Algorithm:

The DijkstraAlgo function implements Dijkstra's algorithm with modifications for considering the maximum number of links (H) in the transmission path.
It uses a priority queue (pq) to select the node with the highest speed first.
For each node popped from the priority queue, it iterates through its neighbors and updates the maximum achievable speed based on the remaining hops (h).
Main Function:

Reads the input values: number of nodes (n), number of links (m), central node (start), and maximum links in the path (k).
Constructs the adjacency list with the given links and their speeds.
Calls DijkstraAlgo with the initial nodeSpeed vector and prints the maximum achievable speeds from the central node to all other nodes.
Output:

Prints the maximum achievable transmission speed from the central node to each node within the constraint of at most H links.
In summary, this program calculates the maximum achievable transmission speed from a central node to every other node in a network, considering the constraint of at most H links in the transmission path. It uses Dijkstra's algorithm and a custom comparison function for the priority queue to achieve this.
*/