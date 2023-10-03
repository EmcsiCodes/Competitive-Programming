#include <iostream>
#include <vector>

using namespace std;
/*
The problem involves finding routes in a network that can be traversed at least twice without following the same path.
This is determined by identifying "bridges" in the network.
A bridge is an edge whose removal increases the number of connected components in the graph.
*/
vector<int> adj[100001];

void findBridges(int node,int &time,vector<int> &disc,
vector<int> &low, vector<int> &parent,vector<bool> &valid){
    disc[node] = time;
    low[node] = time;
    time++;
    for(auto i:adj[node]){
        if(disc[i] == -1){ //if not visited
            parent[i] = node;
            findBridges(i,time,disc,low,parent,valid);
            //if we found a backedge for the next node, update current node
            low[node] = min(low[node],low[i]);
            //else we found a bridge
            if(low[i]>disc[node]){
                //a bridge masodik pontja false lesz, bejaraskor nem fog atmenni a bridgen
                valid[i] = false;
            }
        } else if(parent[node]!=i){ //if child to parent edge ignore
        //updates node reach time if backedge
            low[node] = min(disc[i],low[node]);
        }
    }
}

void DFS(int node,vector<bool> valid,vector<bool> &visited,vector<int> &res){
    visited[node] = true;
    for(auto i:adj[node]){
        if(!visited[i] && valid[i]){
            res.push_back(i);
            DFS(i,valid,visited,res);
        }
    }
}

int main()
{
    int n,m,startNode;
    cin>>n>>m>>startNode;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> res, disc(n+1,-1), low(n+1,-1), parent(n+1,-1);
    vector<bool> valid(n+1,true), visited(n+1,false);
    int time = 0;
    findBridges(startNode,time,disc,low,parent,valid);
    
    res.push_back(startNode);
    DFS(startNode,valid,visited,res);

    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*Problem Overview:
The problem involves finding routes in a network that can be traversed at least twice without following the same path. This is determined by identifying "bridges" in the network. A bridge is an edge whose removal increases the number of connected components in the graph.

Approach Overview:
The approach is based on finding bridges in the given graph, where a bridge is an edge that if removed, increases the number of connected components in the graph. After identifying the bridges, we perform a depth-first search (DFS) to find the valid routes.

Detailed Explanation:
Input Parsing:
Parse the input, including the number of nodes (n), the number of edges (m), and the starting node (startNode).
Build the Graph:
Create an adjacency list representation of the graph based on the provided edges.
Finding Bridges:
Use a modified Depth-First Search (DFS) to identify bridges in the graph. The algorithm finds bridges by calculating the disc and low values for each node.
disc (discovery time): The time at which a node was discovered during DFS.
low: The earliest visited node (the oldest) that can be reached from the subtree rooted with the current node. This is based on back edges in the DFS tree.
Whenever a back edge is found, update the low value of the current node. If a bridge is found, mark the second point of the bridge as invalid.
DFS to find Valid Routes:
Perform DFS traversal starting from the given startNode, visiting only valid nodes (nodes not marked as part of a bridge).
Output the Result:
Output the size of the valid routes and the nodes in the valid routes.
Time Complexity Analysis:
The time complexity of finding bridges in the graph is O(N + M), where N is the number of nodes and M is the number of edges.
The DFS traversal to find valid routes also has a time complexity of O(N + M).
Overall, the time complexity of the solution is O(N + M), which is efficient for the given input constraints.
Overall Approach:
The program efficiently identifies bridges in the graph and then performs a DFS traversal to find valid routes that can be traversed at least twice without following the same path. It outputs the size of the valid routes and the nodes in the valid routes.*/