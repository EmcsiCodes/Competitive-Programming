#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
/*
The problem is about planning a circular bus trip during a school trip. The goal is to choose a route that visits at least two cities apart from the starting city, and the route should pass through different cities. The constraint is to visit the least number of cities possible.

The input includes the number of cities (N), the number of bus routes (M), and the index of the starting city (K). The following M lines describe the bus routes between two cities.

The program needs to output the number of cities (L) visited during the circular route, and then provide the identifiers of these cities in the correct order.

Example:
Input:
8 10 2
1 2
2 3
2 4
3 5
5 6
6 2
6 3
3 7
7 8
4 8
Output:
3
2 3 6

*/
#define INF 1000000

int n,m,start;
vector<int> adj[10001];
queue<int> startNodes;
stack<int> s;
struct cycle{
    int d;
    int x;
    int y;
};
cycle BFS(int node,vector<int>&dis,vector<int>&parent){
    queue<int> q;
    vector<bool> visited(n+1,false);
    parent[node] = start;
    q.push(node);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(dis[i] == 0 && i!=start){
                visited[i] = true;
                parent[i] = node;
                dis[i] = dis[node] + 1;
                q.push(i);
            } else if(parent[node]!=i && !visited[i]) return {dis[node] + dis[i] + 1,node,i};
        }
    }
    return {INF,0,0};
}

int main()
{
    cin>>n>>m>>start;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> dis(n+1,0), parent(n+1,0);
    for(auto i:adj[start]) {
        startNodes.push(i);
        dis[i] = 1;
    }
    int minDis = INF, x, y;
    while(!startNodes.empty()) {
        cycle curr = BFS(startNodes.front(),dis,parent);
        if(curr.d < minDis){
            minDis = curr.d;
            x = curr.x;
            y = curr.y;
        }
        startNodes.pop();
    }
    if(minDis == INF){
        cout<<0;
    }
    else {
        stack<int> s;
        while(y>0){
            s.push(y);
            y = parent[y];
        }
        cout<<minDis<<'\n';
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
        while(x>start){
            cout<<x<<" ";
            x = parent[x];
        }
    }
    return 0;
}
/*
Problem Overview
The problem involves planning a circular bus trip during a school outing. The goal is to choose a route that visits at least two cities apart from the starting city, with the fewest possible visited cities.

Approach
The program uses Breadth-First Search (BFS) to explore the bus routes starting from the given city. The BFS is modified to look for cycles in the route. A cycle is considered a valid circular trip.

Input Reading:

Read the number of cities (n), the number of bus routes (m), and the index of the starting city (start).
Graph Representation:

Create an adjacency list to represent the bus routes between cities.
BFS Function - Finding Cycles:

Define a structure to store cycle information (distance, start node, end node).
Implement a BFS function to explore the graph, looking for cycles that start and end at different nodes. The function returns information about the shortest such cycle.
Main Logic:

Iterate through the neighboring cities of the starting city.
For each neighboring city, use BFS to find the shortest cycle starting from that city.
Track the shortest cycle encountered.
Output:

Print the number of cities in the shortest cycle and the cities in the cycle.
Detailed Explanation
Input Reading:

Read the number of cities (n), the number of bus routes (m), and the starting city (start).
Graph Representation:

Create an adjacency list (adj) to represent the bus routes between cities.
BFS Function - Finding Cycles:

The BFS function performs Breadth-First Search starting from a given node.
During BFS, it looks for cycles. A cycle is detected if we encounter a visited node (other than the starting node) while exploring neighbors.
If a cycle is found, the function returns information about the cycle, including its distance and endpoints.
Main Logic:

Iterate through the neighboring cities of the starting city (start).
For each neighboring city, use the BFS function to find the shortest cycle starting from that city.
Track the shortest cycle encountered so far.
Output:

Print the number of cities in the shortest cycle and the cities in the cycle.
Overall, the program aims to find a circular bus trip with the fewest visited cities, starting and ending at different cities, and follows the shortest path. The BFS algorithm is utilized to achieve this by looking for cycles efficiently.
*/