#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
The problem is about determining the number of points in the largest island in a given rectangular area on a photo depicting an oceanic archipelago. The islands are represented in green, and the ocean is represented in blue.

The input includes the number of rows and columns in the area (N and M), followed by a matrix representing the colors of each point (K for blue and Z for green).

The program needs to output the number of points in the largest recognizable island.

Example:
Input:
5 6
KKKKKK
KZKKKK
ZZKZZK
KKKZZK
KKKKKK
Output:
4

*/
vector<char> v[1001];
vector<bool> visited[1001];
int BFS(pair<int,int> node, int n,int m){
    queue< pair<int,int> > q;
    q.push(node);
    int res = 1;
    visited[node.first][node.second] = true;
    while(!q.empty()){
        node = q.front();
        q.pop();
        if(node.second<m-1 && v[node.first][node.second+1] == 'Z' && !visited[node.first][node.second+1]){
            visited[node.first][node.second+1] = true;
            q.push({node.first, node.second+1});
            res++;
        }
        if(node.first<n && v[node.first+1][node.second] == 'Z' && !visited[node.first+1][node.second]){
            visited[node.first+1][node.second] = true;
            q.push({node.first+1, node.second});
            res++;
        }
        if(node.second>0 && v[node.first][node.second - 1] == 'Z' && !visited[node.first][node.second - 1]){
            visited[node.first][node.second - 1] = true;
            q.push({node.first, node.second-1});
            res++;
        }
        if(node.first>1 && v[node.first - 1][node.second] == 'Z' && !visited[node.first - 1][node.second]){
            visited[node.first - 1][node.second] = true;
            q.push({node.first - 1, node.second});
            res++;
        }
    }
    return res;
}

void solve(int n, int m){
    int res = 0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && v[i][j] == 'Z'){
                res = max(res,BFS({i,j},n,m));
            }
        }

    }
    cout<<res;
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
This program aims to determine the number of points in the largest recognizable island in a given rectangular area depicting an oceanic archipelago.

Approach:
The program starts by reading the dimensions of the rectangular area (rows, columns) and constructs a matrix v to represent the colors of each point.
It then uses a Breadth-First Search (BFS) based approach to traverse the matrix and identify islands (represented by 'Z' in the input).
For each unvisited 'Z' (island), it initiates a BFS starting from that point to traverse the connected island and counts the points in the island.
The BFS function explores the neighboring points of a given island point, updating the count of points in the island and marking visited points to avoid duplication.
The solve function iterates through the matrix, identifies unvisited islands, and calls BFS for each unvisited island. It keeps track of the largest island found.
Finally, the program outputs the number of points in the largest recognizable island.
Explanation:
The matrix v represents the oceanic archipelago with 'K' representing ocean and 'Z' representing islands.
For each 'Z' encountered and not visited, a BFS is initiated to count the number of points in that island.
The BFS explores adjacent points in all four directions (up, down, left, right) from the current point and increments the count if the point is part of the island.
The solve function calls BFS for each unvisited 'Z' and keeps track of the largest island encountered.
The program follows this approach to find the largest island and output the number of points in it.
*/
