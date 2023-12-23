#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
Problem: Given a rectangular grid representing an image with blue (ocean) and green (island) cells, determine the count of distinct islands in the image.

Input:

Dimensions of the grid: Rows (N) and Columns (M).
Grid representation: N rows of M characters, where 'K' represents blue (ocean) and 'Z' represents green (island).
Output: Return the count of distinct islands within the grid.

Definitions:

Island: A connected group of adjacent green cells (sharing an edge, not diagonal).
Connected Cells: Cells that are vertically or horizontally adjacent.
Approach:

Traverse the grid and upon encountering an unmarked green cell ('Z'), initiate a traversal to mark all connected green cells, counting them as one island.
Repeat the traversal for each unmarked green cell to identify all islands.
Algorithm Steps:

Initialize an island counter.
Iterate through each cell in the grid.
If an unmarked green cell is encountered, perform DFS to mark and count all connected green cells as one island.
Repeat the process for all unmarked green cells to count all distinct islands.
Example:

Given a grid representation, identify and count the islands using the defined approach. Return the count of islands found.
This problem revolves around identifying islands (connected groups of green cells) in an image grid and determining their count using a depth-first search or a similar traversal technique. The goal is to accurately count the number of islands within the given grid.
*/
vector<char> v[1001];
vector<bool> visited[1001];

void BFS(pair<int,int> node,int n,int m){
    queue< pair<int,int> > q;
    visited[node.first][node.second] = true;
    q.push(node);
    while(!q.empty()){
        node = q.front();
        q.pop();
        if(node.first >= 2 && v[node.first-1][node.second] == 'Z' && !visited[node.first-1][node.second]){
            visited[node.first - 1][node.second] = true;
            q.push({node.first-1, node.second});
        }
        if(node.first >= 2 && node.second>0 && v[node.first-1][node.second-1] == 'Z' && !visited[node.first-1][node.second - 1]){
            visited[node.first - 1][node.second - 1] = true;
            q.push({node.first - 1, node.second - 1});
        }
        if(node.first >= 2 && node.second<m-1 && v[node.first-1][node.second + 1] == 'Z' && !visited[node.first-1][node.second+ 1]){
            visited[node.first - 1][node.second + 1] = true;
            q.push({node.first - 1, node.second + 1});
        }
        if(node.second>0 && v[node.first][node.second-1] == 'Z' && !visited[node.first][node.second-1]){
            visited[node.first][node.second - 1] = true;
            q.push({node.first, node.second - 1});
        }
        if(node.second<m-1 && v[node.first][node.second+1] == 'Z' && !visited[node.first][node.second+1]){
            visited[node.first][node.second+1] = true;
            q.push({node.first, node.second+1});
        }
        if(node.first<n && node.second>0 && v[node.first + 1][node.second - 1] == 'Z' && !visited[node.first + 1][node.second-1]){
            visited[node.first + 1][node.second - 1] = true;
            q.push({node.first + 1, node.second - 1});
        }
        if(node.first<n && node.second<m-1 && v[node.first + 1][node.second+1] == 'Z' && !visited[node.first + 1][node.second+1]){
            visited[node.first + 1][node.second+1] = true;
            q.push({node.first + 1, node.second+1});
        }
        if(node.first<n && v[node.first + 1][node.second] == 'Z' && !visited[node.first + 1][node.second]){
            visited[node.first + 1][node.second] = true;
            q.push({node.first + 1, node.second});
        }
    }
}

void solve(int n,int m){
    int comp = 0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && v[i][j] == 'Z'){
                comp++;
                BFS({i,j},n,m);
            }
        }
    }
    cout<<comp;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            char x;
            cin>>x;
            v[i].push_back(x);
            visited[i].push_back(false);
        }
    }
    solve(n,m);
    return 0;
}
/*
The given code solves the problem of identifying and counting the number of distinct islands in a rectangular grid, where green cells ('Z') represent islands and blue cells ('K') represent the ocean.

Approach:
The code utilizes Breadth-First Search (BFS) to traverse the grid and count distinct islands.
It iterates through each cell in the grid. If it encounters an unmarked green cell ('Z'), it initiates a BFS to mark all connected green cells as one island.
The BFS explores vertically and horizontally adjacent cells, marking them as visited.
For each unmarked green cell, it repeats the BFS to count all distinct islands.
The total count of islands is then output.
Explanation:
The code successfully counts the distinct islands by using BFS to traverse and mark connected green cells, effectively identifying each island.
Overall, this program effectively counts the number of distinct islands in the provided grid based on the defined approach.
*/