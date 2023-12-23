#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
- **Problem Description**:
  A cycling race track has checkpoints connected by one-way road segments. The track is designed such that if a cyclist skips a checkpoint, they cannot return to it. The organizers have designated the start and finish points. They want to determine the checkpoints where if a racer does not pass, they cannot reach the finish from the start. These checkpoints are referred to as critical points.

- **Task**:
  Create a program that calculates the critical points of the race track.

- **Input**:
  - The first line of standard input contains the number of checkpoints N (1 ≤ N ≤ 10,000), the number of direct road segments M (1 ≤ M ≤ 100,000), and the start A and finish B checkpoint numbers (1 ≤ A ≠ B ≤ N).
  - The following M lines each contain two checkpoint numbers u and v (1 ≤ u ≠ v ≤ N), representing a direct road segment from checkpoint u to v.

- **Output**:
  - The program should output two lines. The first line should contain the number of critical points K.
  - The second line should contain the critical points, separated by spaces, in any order.

- **Example**:
  - **Input**:
    ```
    13 15 1 8
    1 3
    3 9
    1 4
    1 5
    4 2
    5 6
    6 7
    6 13
    7 8
    9 11
    9 10
    10 5
    11 12
    12 6
    8 2
    ```
  - **Output**:
    ```
    2
    7 6
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
vector<int> adj[10001];

void DFS(int node,int finish,vector<bool> &visited,vector<bool> &canFinish){
    if(node == finish){
        canFinish[node] = true;
        return;
    }
    visited[node] = true;
    for(auto i:adj[node]){
        if(!visited[i]){
            DFS(i,finish,visited,canFinish);
            if(canFinish[i]) canFinish[node] = true;
        } else if(canFinish[i]) canFinish[node] = true;
    }
}

void topSort(int start,int finish,int n,vector<bool> canFinish){
    vector<int> inDegree(n+1,0), IND(n+1,0),res;
    for(int i=1; i<=n; i++){
        for(auto j:adj[i]){
            if(canFinish[i] && canFinish[j]){
                inDegree[j]++;
                IND[j]++;
            }
        }
    }
    queue<int> q;
    q.push(start);
    int in = 0,out = 0;
    while(!q.empty() && !(q.size() == 1 && q.front() == finish)){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(canFinish[i]) {
                out++;
                inDegree[i]--;
            }
            if(inDegree[i] == 0 && canFinish[i]) {
                in += IND[i];
                q.push(i);
            }
        }
        if(q.size() == 1 && q.front()!=finish && in == out) res.push_back(q.front());
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
}

int main()
{
    int n,m,start,finish;
    cin>>n>>m>>start>>finish;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    vector<bool> visited(n+1,false), canFinish(n+1,false);
    DFS(start,finish,visited,canFinish);
    topSort(start,finish,n,canFinish);
    /*for(int i=1; i<=n; i++){
            cout<<i<<": "<<canFinish[i]<<endl;
    }*/
    return 0;
}
/*
Let's break down the approach of the program step by step.

### Program Approach: Finding Critical Checkpoints

1. **Input Reading**:
   - Read the number of checkpoints (N), the number of direct road segments (M), the start checkpoint (A), and the finish checkpoint (B) from the standard input.
   - Read M lines, each containing two checkpoint numbers u and v, representing a direct road segment from checkpoint u to v.

2. **Depth-First Search (DFS)**:
   - Use DFS to mark checkpoints that can be reached from the finish checkpoint (B).
   - The `DFS` function marks checkpoints that can be reached from the finish checkpoint.

3. **Topological Sort and Critical Checkpoints**:
   - Use a topological sort to determine critical checkpoints. A checkpoint is critical if it has an incoming road from another critical checkpoint.
   - The `topSort` function performs a topological sort and identifies critical checkpoints based on their in-degrees and connectivity.

4. **Output**:
   - Print the number of critical points (K).
   - Print the critical points, separated by spaces, in any order.

The approach involves using DFS to identify reachable checkpoints from the finish checkpoint and then using a topological sort to determine critical checkpoints.

*/