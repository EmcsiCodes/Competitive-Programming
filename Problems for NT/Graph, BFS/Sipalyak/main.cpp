#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
The problem involves determining the destination that can be reached from the maximum number of starting points on a ski trail.

The input consists of the number of endpoints of the segments (N), the number of segments (M), and the endpoints of each segment.

The program should output the maximum number of starting points from which you can reach the same destination and the destination itself.

Example:
Input:
11 12
1 4
2 4
2 5
3 5
4 6
4 7
5 7
5 8
6 9
6 10
7 10
8 11
Output:
3
10
Constraints:

2 ≤ N ≤ 100,000
1 ≤ M ≤ 500,000
*/

vector<int> adj[100001];
vector<int> startNode;
vector< pair<int,int> > endNode;

void BFS(int start,int n){
    vector<bool> visited(n+1,false);
    visited[start] = true;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
    for(auto &i:endNode){
        if(visited[i.first]){
            i.second++;
        }
    }
}

void solve(int n){
    for(auto i:startNode){
        BFS(i,n);
    }
    int mostVisitedEndNode = 0;
    int mostVisitedNum = 0;
    for(int i=0; i<endNode.size(); i++){
        if(endNode[i].second > mostVisitedNum){
            mostVisitedEndNode = endNode[i].first;
            mostVisitedNum = endNode[i].second;
        }
    }
    cout<<mostVisitedNum<<'\n'<<mostVisitedEndNode;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<bool> genStartNodes(n+1,true), genEndNodes(n+1,true);
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        genStartNodes[y] = false;
        genEndNodes[x] = false;
        adj[x].push_back(y);
    }
    for(int i=1; i<=n; i++){
        if(genStartNodes[i]){
            startNode.push_back(i);
        }
        if(genEndNodes[i]){
            endNode.push_back({i,0});
        }
    }
    solve(n);
    return 0;
}
/*
This program aims to find the destination that can be reached from the maximum number of starting points on a ski trail.

Approach:
The program starts by reading the input, which includes the number of endpoints of the segments (N), the number of segments (M), and the endpoints of each segment.
It constructs a graph representation of the ski trail using adjacency lists, where each segment is represented as an edge from one endpoint to another.
It identifies the starting points and endpoints by maintaining arrays genStartNodes and genEndNodes.
For each starting point, the program performs a Breadth-First Search (BFS) to find all reachable endpoints. It increments the count of each reached endpoint.
After performing BFS from all starting points, it finds the endpoint that was reached by the maximum number of starting points.
Finally, it outputs the maximum number of starting points that can reach the same destination and the destination itself.
Explanation:
The program effectively utilizes BFS to traverse the ski trail from each starting point, counting the number of times each endpoint is reached.
It then identifies the endpoint that was reached by the maximum number of starting points, indicating the destination that can be reached by the most skiers.
This program successfully determines the maximum number of starting points that can reach the same destination on the ski trail and identifies that destination.
*/