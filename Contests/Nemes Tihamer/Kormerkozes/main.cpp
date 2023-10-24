#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;

/*
- **Problem Description**:
  In a table tennis tournament, each participant played exactly once against every other participant, and there were no draws.

- **Task**:
  Write a program that outputs a listing of the players in a way that each player defeated the one immediately preceding them.

- **Input**:
  - The first line of standard input contains the number of players, N (1 ≤ N ≤ 100).
  - The following N*(N-1)/2 lines each contain a result, indicating that player Ai defeated player Bi (1 ≤ Ai ≠ Bi ≤ N).

- **Output**:
  - The program should output a listing of the players in a way that each player defeated the one immediately preceding them. There can be multiple valid solutions.

- **Example**:
  - **Input**:
    ```
    4
    1 2
    2 3
    2 4
    3 1
    4 1
    4 3
    ```
  - **Output**:
    ```
    3 2 1 4
    ```

- **Constraints**:
  - Time Limit: 0.2 seconds
  - Memory Limit: 32 MB
*/

vector<int> adj[101];
stack<int> s;
vector<int> res;
bool result = false;
vector<bool> visited(101,false);

void backtrack(int node,int n){
    if(!result){
        visited[node] = true;
        s.push(node);
        if(s.size() == n){
            while(!s.empty()){
                res.push_back(s.top());
                s.pop();
            }
            result = true;
            return;
        }
        for(auto i:adj[node]){
            if(!visited[i] && !result) backtrack(i,n);
        }
        s.pop();
        visited[node] = false;
    }
}

int main()
{
    int n,m;
    cin>>n;
    m = n * (n - 1) / 2;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    int i = 1;
    while(!result){
        backtrack(i,n);
        i++;
    }
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
This program is designed to determine a valid listing of players in a table tennis tournament based on the given match results, such that each player defeated the one immediately preceding them. It does this by modeling the matches as a directed graph and performing a depth-first search (DFS) to find the desired ordering.

Here's a step-by-step explanation of the approach:

1. **Reading Input**:
   - The program first reads the number of players, `n`, from the user.
   - It then calculates the total number of match results, `m`, which is `n*(n-1)/2` since each player plays against every other player once.

2. **Building the Graph**:
   - The program creates an adjacency list representation of a directed graph where each directed edge represents a match result. The edge is from the winner (`x`) to the loser (`y`).

3. **DFS and Backtracking**:
   - The program uses DFS to explore all possible valid orderings of players based on the match results.
   - It starts DFS from each player (`i` from 1 to `n`), trying to find a valid ordering where each player defeated the one preceding them.
   - The DFS uses backtracking to explore different paths and find the valid ordering.

4. **Backtracking Function** (`backtrack`):
   - This function is a standard DFS algorithm.
   - It keeps track of visited nodes using a boolean array (`visited`).
   - It uses a stack (`s`) to keep track of the current ordering of players being explored.
   - When a valid ordering is found (all players are visited), it stores the ordering in a result vector (`res`).

5. **Outputting Results**:
   - The program prints the valid ordering found in the result vector, which satisfies the given condition.

The key idea here is to use DFS and backtracking to explore all possible orderings and find the one that matches the required condition, where each player defeated the one immediately preceding them in the tournament. Multiple valid solutions may exist, and the program finds one such valid solution.
*/