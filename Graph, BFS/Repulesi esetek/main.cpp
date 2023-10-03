#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
The problem is about finding the number of possible flight patterns given the cities and the lines between them.

The input consists of the number of cities (N), the number of lines (M), and M lines indicating the connections between cities.

The program should output the number of possible flight patterns modulo 123456789.

Example:
Input:
9 8
1 5
1 5
3 2
2 4
6 7
7 8
6 8
9 8
Output:
6
Explanation:
There are six possible flight patterns.

Constraints:

1 ≤ N ≤ 100,000
1 ≤ M ≤ N
*/
vector<int> adj[100001];


bool isCyclic(int node,int &nodeNums,int n,vector<bool> &visited){
    int edgeNum = 0;
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()){
        node = q.front();
        q.pop();
        edgeNum += adj[node].size();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                nodeNums++;
            }
        }
    }
    edgeNum /= 2;

    if(edgeNum >= nodeNums){
        return true;
    }
    return false;
}

void solve(int n){
    vector<bool> visited(n+1,false);
    int res = 1;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            int nodeNum = 1;
            if(isCyclic(i,nodeNum,n,visited)){
                if(nodeNum!=2) res = (res * 2)%123456789;
            } else {
                res = (res * nodeNum)%123456789;
            }
        }
    }
    cout<<res;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    solve(n);
    return 0;
}
/*
This program aims to find the number of possible flight patterns given the cities and the connections between them.

Approach:
The program starts by reading the input, which includes the number of cities (N), the number of lines (M), and the connections between cities.
It constructs a graph representation of the connections between cities.
It then checks for each unvisited city if it is part of a cyclic pattern or not using Breadth-First Search (BFS).
If a city is part of a cyclic pattern, it doubles the number of possible flight patterns (except for cycles of size 2), as each cyclic pattern allows for two flight directions.
If a city is not part of a cyclic pattern, it increments the number of possible flight patterns by the number of cities connected to it (including itself).
Finally, it outputs the total number of possible flight patterns modulo 123456789.
Explanation:
The program uses BFS to traverse through the graph, detecting cyclic patterns and calculating the number of possible flight patterns based on the presence of cycles and the connections between cities.
It then outputs the total number of possible flight patterns modulo 123456789.
This program effectively determines the number of possible flight patterns considering the cities and connections between them and provides the result modulo 123456789.
*/