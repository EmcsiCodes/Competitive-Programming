#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
/*
**Problem Summary:**

Given a hierarchical organization of a gang, where each member knows only their immediate subordinates, find the largest subset of gang members in which no member knows any other member.

**Input:**

- Number of gang members (N).
- For each gang member (from 1 to N), the index of their immediate boss.

**Output:**

- The size of the largest subset where no member knows any other member.
- The indices of the members in this subset, in ascending order.

**Example:**

- **Input:**
  ```
  10
  1
  2
  2
  1
  3
  3
  4
  2
  5
  ```

- **Output:**
  ```
  6
  1 6 7 8 9 10
  ```

In this case, the largest subset where no member knows any other member has a size of 6, and the members are 1, 6, 7, 8, 9, and 10.
*/
vector<int> adj[100001];

int main()
{
    int n;
    cin>>n;
    vector<bool> canPick(n+1,true);
    vector<int> degree(n+1,0), parent(n+1,0);
    for(int i=2; i<=n; i++){
        int x;
        cin>>x;
        adj[x].push_back(i);
        parent[i] = x;
        degree[x]++;
    }
    set<int> res;
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(degree[i] == 0){
            q.push(i);
            res.insert(i);
            canPick[parent[i]] = false;
        }
    }
    while(!q.empty()){
        int next = parent[q.front()];
        degree[next]--;
        q.pop();
        if(degree[next] == 0){
            q.push(next);
            if(canPick[next]){
                res.insert(next);
                canPick[parent[next]] = false;
            }
        }
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
This program solves the problem of finding the largest subset of gang members in which no member knows any other member.

Let's break down the approach step by step:

### 1. Input Processing:

- Read the number of gang members (`n`).
- Create an adjacency list representation of the hierarchical organization.
- Track the degrees of each member (how many subordinates they have) and their immediate boss.

### 2. Identify Starting Members:

- Iterate through the gang members and identify those who have no subordinates (degree = 0).
- Add them to a queue for further processing.
- Initialize a set to store the largest subset of members where no member knows any other member.

### 3. Process the Hierarchy:

- Start BFS from the members with no subordinates.
- While traversing through the hierarchy, track the degrees of the bosses.
- If a boss has no more subordinates, mark them as a potential member of the largest subset.

### 4. Output the Result:

- Print the size of the largest subset and the indices of the members in this subset in ascending order.

### Example Walkthrough:

Let's use the provided example and follow the algorithm's steps:

- **Input:**
  ```
  10
  1
  2
  2
  1
  3
  3
  4
  2
  5
  ```

- **Identify Starting Members:**
  - Members 1 and 4 have no subordinates (degree = 0).

- **Process the Hierarchy (BFS):**
  - Start BFS from the identified starting members.
  - While traversing, track degrees and add potential subset members.

- **Output:**
  ```
  6
  1 6 7 8 9 10
  ```

This means that the largest subset where no member knows any other member has a size of 6, and the members are 1, 6, 7, 8, 9, and 10.

The program efficiently identifies this largest subset and outputs the required information.
*/