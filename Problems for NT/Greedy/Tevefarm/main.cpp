#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
Here's a summary of the problem "Tevefarm" (Camel Farm):

- **Problem Description**:
  The country consists of cities connected by two-way roads, and there's exactly one path from any city to any other city. Each month, a fixed number of camels from each city are transported to the capital. The king wants to maximize the number of camels he receives, so he plans to include as many cities as possible in the National Camel Breeding Program. They aim to choose cities in such a way that when camels are taken from a selected city to the capital at the end of the month, they don't pass through another participating city.

- **Task**:
  Create a program that determines which cities should be included in the National Camel Breeding Program to maximize the number of camels the king receives each month.

- **Input**:
  - The first line of standard input contains the number of cities N (1 ≤ N ≤ 100,000). The capital is city number 1.
  - The second line contains the monthly number of camels bred in each city Ti (1 ≤ Ti ≤ 1,000,000,000).
  - The next N-1 lines contain the city number (Ai) from which the road leads to the i+1 city towards the capital (1 ≤ Ai ≤ i).

- **Output**:
  - The program should output the maximum number of camels the king can receive monthly.
  - The next line should contain the number of selected cities K.
  - The following line should contain K numbers representing the city numbers selected for the program.

- **Example**:
  - **Input**:
    ```
    8
    5 5 7 1 2 3 2 4
    1
    1
    2
    2
    2
    3
    3
    ```
  - **Output**:
    ```
    13
    4
    3 4 5 6
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
vector<int> adj[100001];
vector<int> teveNum, res;
vector<bool> city(100001,false);

int DFS(int node,vector<bool>&visited){
    visited[node] = true;
    int currSum = 0;
    for(auto i:adj[node]){
        if(!visited[i]){
            currSum += DFS(i,visited);
        }
    }
    if(teveNum[node]>=currSum) city[node] = true;
    return max(currSum,teveNum[node]);
}

void BFS(int start,int n){
    vector<bool> visited(n+1,false);
    queue<int> q;
    if(city[start]) {
        cout<<1<<'\n'<<1;
        return;
    }
    visited[start] = true;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(city[i]) {
                visited[i] = true;
                res.push_back(i);
            }
            else if(!visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    teveNum.push_back(0);
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        teveNum.push_back(x);
    }
    for(int i=2; i<=n; i++){
        int x;
        cin>>x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    vector<bool> visited(n+1,false);
    cout<<DFS(1,visited)<<'\n';
    BFS(1,n);
    cout<<res.size()<<'\n';
    for(auto i:res)cout<<i<<" ";
    return 0;
}
/*
The provided code efficiently solves the problem of determining which cities should be included in the National Camel Breeding Program to maximize the number of camels the king receives each month. Here's a step-by-step explanation of the code:

1. **Understanding the Problem**:
   - The program takes input for the number of cities, monthly number of camels bred in each city, and the roads connecting cities.
   - The goal is to maximize the number of camels the king receives each month by selecting cities for the breeding program.

2. **Approach**:
   - The program uses Depth-First Search (DFS) to calculate the maximum number of camels the king can receive each month.
   - It marks the cities based on camel breeding numbers and the road network.

3. **DFS for Calculating Maximum Camels**:
   - The program starts with DFS from the capital (city 1).
   - In DFS, it calculates the maximum camels that can be sent from each city.
   - It marks the cities that can be included in the breeding program based on camel breeding numbers.

4. **BFS for Selecting Cities**:
   - After DFS, it uses Breadth-First Search (BFS) to select cities for the breeding program.
   - It starts from the capital and traverses through the cities, selecting those marked in DFS.
   - The selected cities are added to the result list.

5. **Output**:
   - The program outputs the maximum number of camels the king can receive monthly.
   - It then outputs the number of selected cities and the city numbers selected for the program.

6. **Time Complexity**:
   - The time complexity of the algorithm is O(N) for DFS and O(N) for BFS, resulting in a total time complexity of O(N).

Overall, the program efficiently calculates the maximum number of camels the king can receive each month by selecting cities for the breeding program. It uses DFS and BFS to traverse the cities and optimize camel selection.
*/