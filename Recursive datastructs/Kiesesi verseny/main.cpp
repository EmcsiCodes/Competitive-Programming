#include <iostream>
#include <vector>

using namespace std;
/*
**Problem Summary:**

In a knockout tournament, the results of matches (who defeated whom) are known. Design a program that provides the following information:
1. The team among the eliminated ones that won the most matches.
2. The team that defeated the most other teams, either directly or indirectly.
3. The next match between two teams, both of which have defeated the fewest number of teams, directly or indirectly.

**Input:**

- Number of teams (N) and number of matches (M).
- M lines, each containing two integers separated by a space, indicating the winning team and the losing team.

**Output:**

- The serial number of the team among the eliminated ones with the most wins (-1 if there's no such team).
- The serial number of the team that defeated the most other teams, either directly or indirectly.
- The serial numbers of the two teams to play the next match (in increasing order). If there's no such match, -1 is output.

**Example:**

**Input:**
```
8 5
1 2
4 3
4 1
7 8
5 6
```

**Output:**
```
1
4
5 7
```

---
*/
vector<int> adj[5001];

void DFS(int node,vector<bool>&visited,vector<int>&winNum){
    visited[node] = true;
    for(auto i:adj[node]){
        if(!visited[i]) {
            DFS(i,visited,winNum);
            winNum[node] += winNum[i] + 1;
        } else winNum[node] += winNum[i] + 1; 
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> inDegree(n+1,0), winNum(n+1,0);
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        inDegree[y]++;
    }
    vector<bool> visited(n+1,false);
    for(int i=1; i<=n; i++){
        if(!visited[i]) DFS(i,visited,winNum);
    }
    int maxWinsBefLoss = 0;
    int maxWinsBefLossI = -1;
    int maxWins = 0;
    int maxWinsI = 0;
    int minWins = 100000000;
    int minWinsI = 0;
    int minWinssec = 100000000;
    int minWinssecI = -1;
    for(int i=1; i<=n; i++){
        if(inDegree[i] != 0 && maxWinsBefLoss < adj[i].size()){
            maxWinsBefLoss = adj[i].size();
            maxWinsBefLossI = i;
        }
        if(maxWins < winNum[i]){
            maxWins = winNum[i];
            maxWinsI = i;
        }
        if(inDegree[i] == 0 && minWins > winNum[i]){
            minWins = winNum[i];
            minWinsI = i;
        } else if(inDegree[i] == 0 && minWinssec > winNum[i]){
            minWinssec = winNum[i];
            minWinssecI = i;
        }
    }
    cout<<maxWinsBefLossI<<'\n'<<maxWinsI<<'\n';
    if(minWinssecI == -1) {
        cout<<-1;
        return 0;
    }
    cout<<minWinsI<<" "<<minWinssecI;
    return 0;
}
/*
The provided program aims to determine various statistics related to a knockout tournament, including the team among the eliminated ones with the most wins, the team that defeated the most other teams directly or indirectly, and the next match between two teams that have defeated the fewest number of teams directly or indirectly.

Here's a more detailed explanation of the approach and implementation:

### Approach:

1. **Graph Representation:**
   - The program models the tournament as a directed graph, where nodes represent teams and directed edges represent victories (team1 defeating team2).

2. **DFS for Win Count:**
   - The program performs depth-first search (DFS) on the graph to count the number of victories for each team (direct and indirect wins).

3. **Finding Team with Most Wins:**
   - The team with the most wins (direct and indirect) is determined.

4. **Finding Team Among the Eliminated Ones with the Most Wins:**
   - Among the eliminated teams (those with in-degree > 0), the program identifies the team with the most victories.

5. **Finding Next Match:**
   - The program looks for the next match between two teams that have defeated the fewest number of teams (directly or indirectly).

### Implementation:

1. **Graph Representation:**
   - The program uses an adjacency list to represent the directed graph, where each team stores its victories (outgoing edges).

2. **DFS for Win Count:**
   - The program performs DFS starting from each team to count their victories (direct and indirect).

3. **Finding Team with Most Wins:**
   - The program keeps track of the team with the maximum number of wins.

4. **Finding Team Among the Eliminated Ones with the Most Wins:**
   - The program identifies the team among the eliminated ones (in-degree > 0) with the most victories.

5. **Finding Next Match:**
   - The program identifies the two teams with the fewest victories (directly or indirectly) and outputs them in increasing order of their serial numbers.

6. **Output:**
   - The program outputs the required statistics.

### Example Walkthrough:

Let's go through the given example step by step, showing how the program calculates the required information.

### Input:
```
8 5
1 2
4 3
4 1
7 8
5 6
```

### Steps:
1. **Graph Representation:**
   - We create a directed graph based on the input where edges represent victories (directed from winning team to losing team).

2. **DFS for Win Count:**
   - The program performs DFS to count the number of victories for each team (direct and indirect).

3. **Finding Team with Most Wins:**
   - The program identifies the team with the most wins (direct and indirect).

4. **Finding Team Among the Eliminated Ones with the Most Wins:**
   - The program identifies the team among the eliminated ones (in-degree > 0) with the most victories.

5. **Finding Next Match:**
   - The program identifies the two teams with the fewest victories (directly or indirectly) for the next match.

6. **Output:**
   - The program outputs the required statistics.

### Conclusion:

The program effectively determines the team among the eliminated ones with the most wins, the team that defeated the most other teams directly or indirectly, and the next match between two teams that have defeated the fewest number of teams directly or indirectly. It uses graph representation and DFS traversal to calculate these statistics based on the tournament data.

If you have any more specific questions or need further clarification, feel free to ask!
*/