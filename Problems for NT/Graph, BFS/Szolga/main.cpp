#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
To summarize the problem "Szolga" (Servant):

In this problem, we are given a computer network represented by nodes and their connections. Some nodes act as servers and we want to determine the optimal path for a request from each node to reach the servers with the minimum number of hops.

Input:

Number of nodes (N) and number of servers (K).
The indices of the servers.
Description of the network, detailing the direct neighbors for each node.
Output:

The minimum number of hops (M) to reach a server for each node.
The next node to forward the request to, in order to reach a server.
Example:

Input:
11 3
1 3 5
4 0
11 0
4 6 5 0
1 3 6 8 0
7 3 6 0
4 3 5 7 10 8 0
5 6 10 0
4 6 9 0
8 10 0
9 6 7 0
2 0
Output:
3
0 1
0 0
0 3
1 1
0 5
1 3
1 5
2 4
3 8
2 6
0 0
In this example, we have a network of 11 nodes and 3 servers. For each node, we calculate the minimum
hops required to reach a server and identify the next node to forward the request to.
*/
vector<int> adj[10001];
queue<int> q;

void BFS(int n,vector<bool> visited,vector<int> parent){
    vector<int> dis(n+1,0);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                dis[i] = dis[node] + 1;
                parent[i] = node;
            }
        }
    }
    int maxDis = 0;
    vector< pair<int,int > > res;
    for(int i=1; i<=n; i++){
        maxDis = max(maxDis,dis[i]);
        res.push_back({dis[i],parent[i]});
    }
    cout<<maxDis<<'\n';
    for(auto i:res){
        cout<<i.first<<" "<<i.second<<'\n';
    }
    cout<<'\b';
}

int main()
{
    int n,k,m;
    cin>>n>>k;
    vector<bool> visited(n+1,false);
    vector<int> parent(n+1,0);
    for(int i=1; i<=k; i++){
        int x; cin>>x;
        q.push(x);
        visited[x] = true;
        parent[x] = x;
    }
    for(int i=1; i<=n; i++){
        int x;
        while(cin>>x && x!=0){
            adj[i].push_back(x);
        }
    }
    BFS(n,visited,parent);
    return 0;
}
/*
The given code is an implementation of a breadth-first search (BFS) algorithm to find the minimum number of hops required for each node in a computer network to reach a server node. It also identifies the next node to forward the request to in order to reach a server.

Here's a more detailed explanation of how the code works:

Input Processing:

The code starts by reading the number of nodes (N) and the number of servers (K).
It reads the indices of the server nodes.
It constructs the network by reading the direct neighbors for each node.
Initialization:

It initializes several data structures:
adj[]: An array of vectors to represent the adjacency list of the network. Each node is associated with its neighbors.
q: A queue to store nodes for BFS traversal.
visited[]: A vector to keep track of visited nodes.
parent[]: A vector to store the parent node for each node during traversal.
BFS Traversal:

The code initiates BFS traversal from the server nodes (servers are pushed into the queue q).
It uses BFS to calculate the minimum number of hops required for each node to reach a server.
During traversal, it updates the visited, parent, and dis (distance) vectors.
Result Calculation:

After completing BFS traversal, the code calculates the maximum distance (maximum number of hops) from any node to a server and stores it in maxDis.
It also constructs a vector of pairs res, where each pair contains the distance and parent node for each node.
Finally, it outputs the following:
The maximum distance maxDis.
For each node, the minimum number of hops to reach a server and the next node to forward the request to in order to reach a server.
Output:

The code prints the maximum distance followed by a list of pairs, each containing the distance and the next node for each node in the network.
The output format follows the example given in the problem statement.
Termination:

The program returns 0 to indicate successful execution.
Overall, the code effectively computes the minimum hops required for each node to reach a server in a computer network and identifies the next node in the path. It performs BFS traversal to efficiently find these values.
*/