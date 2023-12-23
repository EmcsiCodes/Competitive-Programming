#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
"Tiltott városok 3" (Forbidden Cities 3):

In this problem, Adam and Eve reside in different cities and want to meet each other. However, certain cities are off-limits for Adam and Eve. The goal is to determine the city where they can meet the soonest, assuming that traveling between any two cities takes the same amount of time.

- **Input**:
  - The input consists of:
    - The number of cities (`N`), each identified by a unique number.
    - The number of direct roads between cities (`M`).
    - The city where Adam resides (`A`).
    - The city where Eve resides (`E`).
    - Pairs of cities representing direct roads between them.
    - Adam's forbidden cities count (`TA`) and their corresponding indices.
    - Eve's forbidden cities count (`TE`) and their corresponding indices.

- **Output**:
  - The program needs to determine the city where Adam and Eve can meet the soonest while considering the off-limits cities.
  - The output should provide the city number where they should meet in the minimum amount of time.
  - If multiple cities meet this criterion, the lowest numbered city should be selected.
  - If no such city exists that satisfies the criteria, the output should be 0.

- **Example**:
  - **Input**:
    ```
    5 6 1 4
    1 2
    1 3
    5 3
    5 2
    2 4
    4 5
    2 5 2
    1 2
    ```
  - **Output**:
    ```
    3
    ```
  - **Explanation**: The city numbered 1 is the optimal meeting point for Adam and Eve, requiring the least amount of time to travel.

- **Constraints**:
  - The constraints include a limit on the number of cities and direct roads, as well as specifications for forbidden cities, ensuring a feasible computation within reasonable time and memory limits. In a majority of the cases, the number of cities is less than or equal to 100.
*/

vector<int> adj[1001], adjA[1001], adjE[1001];

vector<int> BFS(int start,int n, vector<int> adj[]){
    vector<bool> visited(n+1,false);
    vector<int> dis(n+1,0);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                dis[i] = dis[node] + 1;
            }
        }
    }
    return dis;
}

int main()
{
    int n,m,A,E;
    cin>>n>>m>>A>>E;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int tiltottA, tiltottE;
    vector<bool> canA(n+1, true), canE(n+1, true);
    cin>>tiltottA;
    for(int i=1; i<=tiltottA; i++){
        int x;
        cin>>x;
        canA[x] = false;
    }
    cin>>tiltottE;
    for(int i=1; i<=tiltottE; i++){
        int x;
        cin>>x;
        canE[x] = false;
    }
    for(int i=1; i<=n; i++){
        for(auto j:adj[i]){
            if(canA[i] && canA[j]){
                adjA[i].push_back(j);
            }
            if(canE[i] && canE[j]){
                adjE[i].push_back(j);
            }
        }
    }

    vector<int> disForA = BFS(A,n,adjA);
    vector<int> disForE = BFS(E,n,adjE);
    vector<int> res(n+1);

    for(int i=1; i<=n; i++){

        if(disForA[i] == 0 && i!=A) {
            res[i] = 0;
        }
        else if(disForE[i] == 0 && i!=E) {
            res[i] = 0;
        }
        else res[i] = max(disForA[i],disForE[i]);

    }

    int minDisAll = 2000000;
    int index = 0;

    for(int i=1; i<=n; i++){
        if(res[i] < minDisAll && res[i]!=0){
            minDisAll = res[i];
            index = i;
        }
    }
    if(minDisAll == 2000000) cout<<0;
    else cout<<index;
    return 0;
}
/*
The provided code solves the "Tiltott városok 3" (Forbidden Cities 3) problem, where Adam and Eve want to meet each other in the soonest possible time while considering certain off-limits cities. Let's break down the code and understand the approach:

1. **Input:**
   - Read the number of cities (`N`), the number of direct roads between cities (`M`), the city where Adam resides (`A`), and the city where Eve resides (`E`).
   - Read the pairs of cities representing direct roads between them.
   - Read the count and indices of forbidden cities for Adam (`tiltottA`) and Eve (`tiltottE`).

2. **Graph Representation:**
   - Create adjacency lists (`adjA` and `adjE`) for Adam and Eve, respectively, considering the forbidden cities.

3. **BFS for Adam and Eve:**
   - Perform BFS for Adam and Eve separately, considering only the allowed (non-forbidden) cities.
   - Calculate the shortest distances from Adam (`disForA`) and Eve (`disForE`) to all other cities.

4. **Total Steps Calculation:**
   - Calculate the maximum of the distances from Adam and Eve to each city, considering the sum of their distances to that city.

5. **Optimal Meeting Point:**
   - Find the city with the minimum maximum distance (soonest meeting point) as the optimal meeting point for Adam and Eve.
   - If multiple cities have the same minimum maximum distance, choose the lowest numbered city.
   - Output the index of the optimal meeting point.

6. **Example:**
   - Given the input with cities, roads, forbidden cities for Adam and Eve, the code calculates the soonest meeting point.

The approach efficiently handles finding the optimal meeting point for Adam and Eve while avoiding forbidden cities and minimizing the total time required for their meeting. The output is the index of the optimal meeting city.
*/