#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
- **Problem Description**:
  A large company provides supplies from the central point S to its various branches. Some sections of the road network are critical. Your task is to find the cities that can be reached from the central point using at most one critical section.

- **Task**:
  Write a program that calculates the cities that can be reached from the central point using at most one critical section.

- **Input**:
  - The first line of standard input contains four integers separated by spaces: N (the number of nodes, N ≤ 100,000), M (the number of direct edges, 1 ≤ M ≤ 1,000,000), K (the number of critical sections, K ≤ 1,000), and S (the serial number of the central point, 1 ≤ S ≤ N).
  - The next M lines describe the direct road segments between cities. The first K lines represent critical sections. Each line contains two integers p and q, indicating a direct road between cities p and q, where traveling from p to q is possible.

- **Output**:
  - The first line of the output should contain the number of cities that can be reached from the central point using at most one critical section.
  - The second line should contain the serial numbers of these cities separated by spaces, including the central point S.

- **Example**:
  - **Input**:
    ```
    7 11 6 1
    1 2
    1 3
    3 4
    6 3
    4 5
    4 1
    2 7
    7 3
    6 2
    5 6
    7 6
    ```
  - **Output**:
    ```
    5
    1 2 3 6 7
    ```

- **Constraints**:
  - The computation should be completed within 0.1 seconds.
  - The memory usage should not exceed 32 MB.
*/
#define INF 1000000
vector< pair<int,int> > adj[100001];

void DijkstraAlgo(int startNode,int n){
    vector<int> dis(n+1,INF);
    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;
    dis[startNode] = 0;
    pq.push({dis[startNode],startNode});
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        for(auto i:adj[node]){
            if(dis[i.first] > dis[node] + i.second){
                dis[i.first] = dis[node] + i.second;
                pq.push({dis[i.first],i.first});
            }
        }
    }
    vector<int> res;
    for(int i=1; i<=n; i++){
        if(dis[i]<=1) res.push_back(i);
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
}

int main()
{
    int n,m,k,startNode;
    cin>>n>>m>>k>>startNode;
    for(int i=1; i<=k; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back({y,1});
    }
    for(int i=1; i<=m-k; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back({y,0});
    }
    DijkstraAlgo(startNode,n);
    return 0;
}
/*
The given program aims to find cities that can be reached from the central point using at most one critical section in a road network. The program uses Dijkstra's algorithm to calculate the shortest paths and identify cities that can be reached within one or fewer critical sections.

Here's a step-by-step explanation of how the program works:

1. **Input Reading:**
   - Read the number of nodes (N), the number of direct edges (M), the number of critical sections (K), and the serial number of the central point (S) from the standard input.
   - Read the M lines describing the direct road segments between cities, with the first K lines representing critical sections.

2. **Dijkstra's Algorithm:**
   - Implement Dijkstra's algorithm to find the shortest paths from the central point (S) to all other cities.

3. **Find Reachable Cities:**
   - Determine the cities that can be reached from the central point using at most one critical section based on the shortest paths calculated by Dijkstra's algorithm.

4. **Output:**
   - Output the number of cities that can be reached using at most one critical section and their serial numbers.

### Output:
The program outputs the number of cities that can be reached from the central point using at most one critical section, followed by the serial numbers of these cities.

The program seems to be working correctly to find the reachable cities within the specified conditions. If you have any specific questions or concerns, feel free to ask!
*/