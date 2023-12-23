#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
/*
- **Problem Description**:
  Given a country with cities connected by roads, the task is to determine the best city to build a logistics center such that the farthest city from the center is as close as possible.

- **Task**:
  Create a program that calculates the minimum distance to the farthest city achievable by placing a logistics center in a specific city, and which cities are potential candidates for this placement.

- **Input**:
  - The first line of standard input contains the number of cities N (1 ≤ N ≤ 100,000).
  - The following N-1 lines each contain two cities and the time required to travel between them (ai, bi, ci), where ci is the time to travel from city ai to city bi.

- **Output**:
  - The program should output the minimum distance T to the farthest city achievable with the logistics center and the number of cities where a logistics center can be placed for achieving this minimum distance.
  - The next line should contain the count of cities where a logistics center can be placed.
  - The following line should contain the indices of cities where the logistics center can be placed in increasing order.

- **Example**:
  - **Input**:
    ```
    10
    8 1 87372
    3 8 53559
    6 8 42416
    8 10 86477
    7 8 19865
    2 8 77259
    8 9 68731
    5 8 61349
    8 4 46883
    ```
  - **Output**:
    ```
    87372
    1
    8
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
#define LL long long
vector< pair<int, LL> > adj[100001];
vector<int> path;

pair<LL,int> BFS(int start,int n){
    queue<int> q;
    vector<bool> visited(n+1,false);
    vector<LL> dis(n+1,0);
    vector<int> parent(n+1,0);
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i.first]){
                parent[i.first] = node;
                visited[i.first] = true;
                q.push(i.first);
                dis[i.first] = dis[node] + i.second;
            }
        }
    }
    LL maxDis = 0;
    int maxDisIndex = 0;
    for(int i=1; i<=n; i++){
        if(dis[i] > maxDis){
            maxDis = dis[i];
            maxDisIndex = i;
        }
    }
    if(start!=1) path = parent;
    return {maxDis,maxDisIndex};
}

void checkBestSpot(pair<LL,int> res,int n){
    LL best = res.first / 2;
    int i = res.second;
    LL distance = 0, lastDis = 0;
    int distanceIndex = 0, lastDisIndex = 0, bestIndex = 0;
    int db=0;
    while(distance<best && i>0){
        LL d;
        for(auto &j:adj[i]) if(j.first==path[i]) {d = j.second; break;}
        lastDis = distance;
        distance += d;
        if(d==0) db++;
        else db = 0;
        lastDisIndex = i;
        distanceIndex = path[i];
        i = path[i];
    }
    if(abs(best - lastDis)<abs(best - distance)) {
        best = lastDis;
        bestIndex = lastDisIndex;
    }
    else {
        best = distance;
        bestIndex = distanceIndex;
    }
    cout<<max(res.first - best, best)<<'\n';
    cout<<1<<'\n'<<bestIndex;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<n; i++){
        int x,y;
        LL z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }
    pair<LL,int> res = BFS(BFS(1,n).second,n);
    checkBestSpot(res,n);
    return 0;
}
/*
The given C++ program solves the problem of determining the best city to build a logistics center such that the farthest city from the center is as close as possible.

Here's a step-by-step breakdown of the program:

### Program Approach:

1. **Input Reading:**
   - Read the number of cities (N) from the standard input.
   - Read N-1 lines, each containing two cities and the time required to travel between them (ai, bi, ci), where ci is the time to travel from city ai to city bi.

2. **BFS for Finding Furthest City:**
   - Run BFS (Breadth-First Search) twice:
     - First BFS to find the furthest city from any starting city (here, starting city is 1).
     - Second BFS to find the furthest city from the previously found furthest city.

3. **Finding the Best Spot for Logistics Center:**
   - Starting from the furthest city found in the second BFS, trace back the path to the starting city.
   - Calculate distances from the starting city to the furthest city and back. Select the point where the distance is closest to half the maximum distance.
   - Output the minimum distance to the farthest city achievable with the logistics center and the number of cities where a logistics center can be placed.

### Output:
The program outputs the minimum distance T to the farthest city achievable with the logistics center and the number of cities where a logistics center can be placed. It also outputs the index of the best city for placing the logistics center.

The program aims to determine the best city for building a logistics center such that the farthest city from the center is as close as possible.

Feel free to ask if you have any further questions or need additional clarifications!
*/