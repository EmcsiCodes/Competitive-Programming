#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

/*
The problem is about finding the shortest path with the fewest color changes on a map where each country is colored. A commando needs to travel from one country to another without being detected, so they need to wear a shirt with the same color as the country they are in.

In the input, you'll get the number of countries (N), followed by N lines describing the neighbors of each country. Each line begins with the number of neighbors (Ki), followed by Ki country codes representing the neighboring countries. Then, you have N lines with the color codes for each country, and finally, the starting and destination countries.

The goal is to find the shortest path with the minimum number of shirt color changes. The output should include the minimum number of shirt changes and the country codes for the optimal path. If there is no path, -1 should be outputted.

Here's an example:
Input:
6
3 2 3 4
3 1 3 6
5 1 2 4 5 6
2 1 3
2 3 6
3 2 3 5
1
3
2
2
3
1
5
Output:
2 3
1 3 5

*/

#define INF 1000000
vector< pair<int,int> > adj[20001];

void DijkstraAlgo(int startNode,int endNode,int n,vector<int> code){
    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;
    vector<int> dis(n+1,INF);
    vector<int> path(n+1,0);
    dis[startNode] = 0;
    pq.push({0,startNode});
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        for(auto i:adj[node]){
            if(dis[i.first] > dis[node] + i.second){
                path[i.first] = node;
                dis[i.first] = dis[node] + i.second;
                pq.push({dis[i.first],i.first});
            }
        }
    }
    if(dis[endNode] == INF) {
        cout<<-1;
        return;
    }
    cout<<dis[endNode]<<" ";
    int i = endNode;
    stack<int> s;
    while(i>0){
        s.push(i);
        i = path[i];
    }
    cout<<s.size()<<'\n';
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<'\b';
}

void solve(int n){
    vector<int> code(n+1,0);
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        code[i] = x;
    }
    int startNode, endNode;
    cin>>startNode>>endNode;
    for(int i=1; i<=n; i++){
        for(auto &j:adj[i]){
            if(code[j.first]!=code[i]){
                j.second = 1;
            }
        }
    }
    DijkstraAlgo(startNode,endNode,n,code);
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        for(int j=1; j<=x; j++){
            int y;
            cin>>y;
            adj[i].push_back({y,0});
        }
    }
    solve(n);
    return 0;
}
/*
This C++ program aims to find the shortest path with the fewest color changes between countries on a map. It uses Dijkstra's algorithm to achieve this. Let's go through the code and understand it step by step.

Function Definitions:

DijkstraAlgo performs Dijkstra's algorithm to find the shortest path with the fewest color changes.
solve processes the input and calls DijkstraAlgo to solve the problem.
Dijkstra's Algorithm:

It starts from the startNode and calculates the shortest path using a priority queue.
Uses an adjacency list adj to represent the graph.
If two countries have different colors, the edge between them has a weight of 1.
Main Function:

Reads input values: number of countries (N), the neighbors of each country, color codes for each country, and the starting and destination countries.
Constructs the adjacency list based on the given input.
Calls the solve function to find the shortest path with the fewest color changes.
Output:

Prints the minimum number of shirt changes and the country codes for the optimal path.
If there is no path, it prints -1.
In summary, this program finds the shortest path with the fewest color changes between countries on a map using Dijkstra's algorithm. It then prints the minimum number of shirt changes and the country codes for the optimal path. If no path exists, it prints -1.
*/