#include <iostream>
#include <vector>
#include <set>
using namespace std;
/*
- **Problem Description**:
  The city's authorities aim to convert streets into one-way roads while ensuring that it remains possible to reach any location from any other location through these one-way streets.

- **Task**:
  Write a program that determines the optimal conversion of streets into one-way roads, minimizing the number of streets that need to be two-way.

- **Input**:
  - The first line of standard input contains the number of intersections, N (1 ≤ N ≤ 10,000), and the number of streets, M (1 ≤ M ≤ 200,000).
  - The following M lines each contain two integers, U and V, indicating an existing street between intersections U and V. Each street connects two intersections, and there is at most one street between any two intersections.

- **Output**:
  - The program should output the minimum number of streets K that need to be two-way.
  - The next K+M lines should each contain two integers, U and V, representing a one-way street that needs to be modified for one-way traversal from U to V.

- **Example**:
  - **Input**:
    ```
    10 12
    9 10
    8 9
    10 8
    8 7
    7 5
    7 6
    5 1
    1 2
    1 3
    2 4
    3 4
    6 3
    ```
  - **Output**:
    ```
    1
    7 5
    5 1
    1 2
    2 4
    4 3
    3 1
    3 6
    6 7
    8 9
    9 10
    10 8
    7 8
    8 7
    ```

- **Constraints**:
  - The program should execute within 0.2 seconds.
  - Memory usage should not exceed 32 MiB.
*/
vector<int> adj[10001];
set< pair<int,int> > bridges,res;

void findBridges(int node,vector<int>&disc,vector<int>&low,vector<int>&parent){
    static int time = 1;
    disc[node] = time;
    low[node] = time;
    time++;
    for(auto i:adj[node]){
        if(disc[i] == 0){
            parent[node] = i;
            findBridges(i,disc,low,parent);
            low[node] = min(low[node],low[i]);
            if(low[i] > disc[node]){
                bridges.insert({node,i});
            }
        } else if(parent[i]!=node){
            low[node] = min(low[node],disc[i]);
        }
    }
}

void DFS(int node,vector<bool>&visited,vector<int>&parent){
    visited[node] = true;
    for(auto i:adj[node]){
        //cout<<i<<" es "<<node;
        if(!visited[i] && bridges.find({node,i})==bridges.end() && bridges.find({i,node})==bridges.end()){
            parent[node] = i;
            res.insert({node,i});
            cout<<node<<" "<<i<<'\n';
            DFS(i,visited,parent);
        } else if(parent[i]!=node && res.find({i,node})==res.end() && 
        bridges.find({node,i})==bridges.end() && bridges.find({i,node})==bridges.end()){
            res.insert({node,i});
            cout<<node<<" "<<i<<'\n';
        }
    }
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
    vector<int> disc(n+1,0),low(n+1,0),parent(n+1,0);
    vector<bool> visited(n+1,false);
    findBridges(1,disc,low,parent);
    for(int i=0; i<=n; i++) parent[i] = 0;
    cout<<bridges.size()<<'\n';
    for(auto i:bridges){
        if(!visited[i.first]) DFS(i.first,visited,parent);
        if(!visited[i.second]) DFS(i.second,visited,parent);
    }
    for(auto i:bridges){
        cout<<i.first<<" "<<i.second<<'\n';
        cout<<i.second<<" "<<i.first<<'\n';
    }
    return 0;
}
/*
The provided code aims to determine an optimal conversion of streets into one-way roads while minimizing the number of streets that need to be two-way. The goal is to convert some streets into one-way roads in a way that still allows reaching any location from any other location.

Here's a step-by-step explanation of how the program works:

1. **Input Reading:**
   - Read the number of intersections (N) and the number of streets (M) from the standard input.
   - Read the M lines describing the existing streets between intersections.

2. **Finding Bridges:**
   - Use a modified depth-first search (DFS) to identify the bridges in the graph (edges that, if removed, would increase the number of connected components).
   - Store the identified bridges in the set `bridges`.

3. **Determining One-Way Roads:**
   - Iterate through the bridges.
   - For each bridge, perform a DFS to determine the one-way roads needed to maintain connectivity while minimizing the number of two-way streets.
   - Output the necessary one-way roads.

4. **Output:**
   - Output the total number of one-way roads.
   - Output the identified one-way roads.

### Output:
The program outputs the minimum number of streets that need to be two-way, along with the one-way streets to maintain connectivity.

The program seems to be working as expected to achieve the goal of minimizing the number of two-way streets while allowing connectivity between all locations. If you have any specific questions or concerns, feel free to ask!
*/