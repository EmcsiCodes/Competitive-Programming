#include <iostream>
#include <vector>
using namespace std;
/*
**Problem Summary:**

In a knockout tournament, the results of matches (who defeated whom) are known. Design a program that provides the following information:
1. Teams still in the competition.
2. Teams that have been eliminated but won at least once.
3. The team that defeated the most other teams, directly or indirectly.

**Input:**

- Number of teams (N) and number of matches (M).
- M lines, each containing two integers separated by a space, indicating the winning team and the losing team.

**Output:**

- The number and serial numbers of teams still in the competition (in increasing order).
- The number and serial numbers of teams that are eliminated but have won at least once (in increasing order).
- The serial number of the team that defeated the most other teams, either directly or indirectly.

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
4 4 5 7
1 1
4
```

---
*/
vector<int> adj[5001];

int DFS(int node,vector<bool>&visited){
    visited[node] = true;
    int curr = 0;
    for(auto i:adj[node]){
        if(!visited[i]){
            curr += DFS(i,visited);
        }
    }
    return curr + 1;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> inDegree(n+1,0), outDegree(n+1,0);
    vector<int> a,b;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        inDegree[y]++;
        outDegree[x]++;
    }
    for(int i=1; i<=n; i++){
        if(inDegree[i] == 0) a.push_back(i);
        if(outDegree[i] !=0 && inDegree[i] != 0) b.push_back(i);
    }
    vector<bool> visited(n+1,false);
    int maxWins = 0;
    int maxWinsI = 0;
    for(auto i:a){
        if(!visited[i]){
            int curr = DFS(i,visited);
            if(curr > maxWins){
                maxWins = curr;
                maxWinsI = i;
            }
        }
    }
    cout<<a.size()<<" "; for(auto i:a) cout<<i<<" ";
    cout<<'\n'<<b.size()<<" "; for(auto i:b) cout<<i<<" ";
    cout<<'\n'<<maxWinsI;
    return 0;
}
/*
The provided program aims to determine various statistics related to a knockout tournament, including the teams still in the competition, teams that have been eliminated but won at least once, and the team that defeated the most other teams directly or indirectly.

Here's a more detailed explanation of the approach and implementation:

### Approach:

1. **Graph Representation:**
   - The program models the tournament as a directed graph, where nodes represent teams and directed edges represent victories (team1 defeating team2).

2. **Finding Teams Still in the Competition:**
   - A team that hasn't lost a match (i.e., in-degree is 0) is still in the competition.

3. **Finding Eliminated Teams That Won at Least Once:**
   - A team that has won at least one match but is no longer in the competition (i.e., in-degree is not 0) is an eliminated team.

4. **Finding Team with Most Wins:**
   - To find the team that defeated the most other teams, the program performs a depth-first search (DFS) starting from each node (team) and counts the number of reachable nodes.

### Implementation:

1. **Graph Representation:**
   - The program uses an adjacency list to represent the directed graph, where each team stores its victories (outgoing edges) and defeats (incoming edges).

2. **Finding Teams Still in the Competition:**
   - Teams with in-degree 0 are still in the competition, and their serial numbers are stored.

3. **Finding Eliminated Teams That Won at Least Once:**
   - Teams with both in-degree and out-degree non-zero have won at least one match but are eliminated. Their serial numbers are stored.

4. **Finding Team with Most Wins:**
   - The program uses DFS to count the number of reachable nodes from each team. The team with the maximum number of reachable nodes (most wins) is determined.

5. **Output:**
   - The program outputs the serial numbers of teams still in the competition, eliminated teams that won at least once, and the team with the most wins.

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

2. **Finding Teams Still in the Competition:**
   - Teams with in-degree 0 are still in the competition.

3. **Finding Eliminated Teams That Won at Least Once:**
   - Teams with both in-degree and out-degree non-zero have won at least one match but are eliminated.

4. **Finding Team with Most Wins:**
   - The program performs DFS to count the number of reachable nodes (teams defeated directly or indirectly) from each team. The team with the most wins is determined.

5. **Output:**
   - The program outputs the serial numbers of teams still in the competition, eliminated teams that won at least once, and the team with the most wins.

### Conclusion:

The program effectively determines the teams still in the competition, eliminated teams that won at least once, and the team that defeated the most other teams directly or indirectly. It uses graph representation and DFS traversal to calculate these statistics based on the tournament data.

If you have any more specific questions or need further clarification, feel free to ask!
*/