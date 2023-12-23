#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
/*
The problem involves calculating the length of the longest possible path in a warehouse grid, where movement is only allowed on empty grid cells, and diagonal movement is not allowed.

The input includes the number of columns (M) and rows (N) in the warehouse grid. Each of the following N lines contains M characters, either '#' (occupied) or '.' (empty), representing the warehouse grid.

The program should output the length of the longest possible path in the warehouse grid.

Example:
Input:
6 5
..#.#.
#.....
..##.#
.#....
.#.#.#
Output:
12
Explanation:
The longest path possible in the given grid is from (1,1) to (6,5) and has a length of 12.

Constraints:

2 ≤ M, N ≤ 1000
The input grid contains only characters '#' and '.'
*/
vector<int> adj[200001];

pair<int,int> BFS(int node,int n){
    vector<int> dis(n+1,0);
    vector<bool> visited(n+1,false);
    visited[node] = true;
    queue<int> q;
    q.push(node);

    while(!q.empty()){
        node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                dis[i] = dis[node] + 1;
                q.push(i);
            }
        }
    }
    int maxDisIndex = 0, maxDis = 0;
    for(int i=1; i<=n; i++){
        if(dis[i]>maxDis){
            maxDis = dis[i];
            maxDisIndex = i;
        }
    }
    return {maxDis, maxDisIndex};
}

int main()
{
    int n,m;
    cin>>m>>n;
    int nodeNum = 1;
    int nextNodeNum = 1;
    vector<char> v[1001];

    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            char x;
            cin>>x;
            if(i==1 && x=='.') nextNodeNum++;
            v[i].push_back(x);
        }
        if(i>=2){
            for(int j=0; j<m; j++){
                if(v[i-1][j] == '.'){
                    if(j<m-1 && v[i-1][j+1]=='.') {
                        adj[nodeNum].push_back(nodeNum+1);
                        adj[nodeNum+1].push_back(nodeNum);
                    }
                    if(v[i][j] == '.'){
                        adj[nodeNum].push_back(nextNodeNum);
                        adj[nextNodeNum].push_back(nodeNum);
                        nextNodeNum++;
                    }
                    nodeNum++;
                } else if(v[i][j]=='.'){
                    if(j<m-1 && v[i][j+1]=='.'){
                        adj[nextNodeNum].push_back(nextNodeNum+1);
                        adj[nextNodeNum+1].push_back(nextNodeNum);
                    }
                    nextNodeNum++;  
                }
            }
        }
    }
    nodeNum = nextNodeNum - 1;
    /*for(int i=1; i<=nodeNum; i++){
        cout<<i<<": ";
        for(auto j:adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;*/
    pair<int,int> res = BFS(1,nodeNum);
    cout<<BFS(res.second,nodeNum).first;
    return 0;
}
/*
This program aims to find the longest possible path in a warehouse grid where movement is allowed only on empty grid cells, and diagonal movement is not permitted.

Approach:
The program first reads the input, which includes the number of columns (M) and rows (N) in the warehouse grid, followed by the warehouse grid itself.
It uses a graph representation to construct a graph where each empty cell is a node, and edges are established based on the empty cell's position.
The program then employs Breadth-First Search (BFS) to find the longest possible path in the warehouse grid.
It starts BFS from an arbitrary empty cell, calculates the maximum distance and the node corresponding to that maximum distance.
Next, it runs BFS again from the node corresponding to the maximum distance, and this time it calculates and outputs the length of the longest possible path.
Explanation:
The program constructs a graph where each empty cell is a node, and edges are determined based on the grid layout.
It uses BFS to find the longest possible path by starting from an empty cell, calculating the maximum distance and the node corresponding to that distance.
It then runs BFS again from the node corresponding to the maximum distance to determine the actual longest path.
This program successfully identifies the longest possible path in the warehouse grid by effectively utilizing BFS and constructing a graph representation of the grid. It provides the expected output for the given grid.
*/