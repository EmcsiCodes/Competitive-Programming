#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
**Problem Summary:**

Given information about the flow of rivers into other rivers in Hungary, the task is to determine if two specific rivers meet and if yes, find the number of rivers they need to cross to reach the point of confluence.

**Input:**

- Number of rivers (N).
- Number of rivers flowing into other rivers (M).
- Two rivers to be investigated (X and Y).
- M pairs of river indices representing which river flows into which other river.

**Output:**

- "IGEN" if the two rivers meet, "NEM" if they do not.
- If they meet, the number of rivers they need to cross to reach the point of confluence.

**Example:**

- **Input:**
  ```
  6 4 6 5
  1 2
  3 4
  4 5
  3 6
  ```

- **Output:**
  ```
  IGEN
  1 2
  ```

In this example, rivers 6 and 5 meet at river 4, and they need to cross rivers 1 and 2 to reach the point of confluence.

---

If you have any specific questions or need further assistance with the implementation, feel free to ask!
*/
vector<int> adj[10001];

int main()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        adj[y].push_back(x);
    }
    queue<int> q;
    vector< pair<int,char> > dis(n+1,{0,'a'});
    vector<bool> visited(n+1,false);
    visited[a] = true;
    visited[b] = true;
    q.push(a);
    q.push(b);
    dis[a].second = 'a';
    dis[b].second = 'b';
    bool meet = false;
    pair<int,int> res;
    while(!q.empty() || !meet){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                dis[i].first = dis[node].first + 1;
                dis[i].second = dis[node].second;
            } else {
                meet = true;
                if(dis[i].second == 'a') res = {dis[i].first, dis[node].first + 1}; 
                else res = {dis[node].first + 1, dis[i].first};
                break;
            }
        }
    }
    if(!meet) cout<<"NEM";
    else {
        cout<<"IGEN"<<'\n';
        cout<<res.first<<" "<<res.second;
    }
    return 0;
}
/*
The provided C++ program addresses the problem of determining if two rivers meet and, if they do, finding the number of rivers they need to cross to reach the point of confluence in a given river flow network. Let's break down the approach and understand how the program achieves this.

### 1. **Understanding the Problem:**

The program deals with a river flow network where rivers flow into other rivers. The task is to determine if two specific rivers meet and, if yes, find the number of rivers they need to cross to reach the point of confluence.

### 2. **Input:**

- Read the number of rivers (N), the number of rivers flowing into other rivers (M), and the two rivers to be investigated (X and Y).
- Read M pairs of river indices representing which river flows into which other river.

### 3. **Approach:**

- Build an adjacency list representing the river flow network, where each river is a node and the edges represent the flow of water from one river to another.
- Use Breadth-First Search (BFS) to traverse the network and determine if the two specified rivers meet. Additionally, find the number of rivers they need to cross to reach the point of confluence.

### 4. **Implementation:**

- Build an adjacency list to represent the river flow network.
- Perform BFS starting from the two specified rivers (X and Y) to determine if they meet and find the number of rivers they need to cross.
- Print the result accordingly.

### 5. **Output:**

- Print "IGEN" if the two rivers meet and the number of rivers they need to cross to reach the point of confluence.
- Print "NEM" if the two rivers do not meet.

### Example Walkthrough:

Let's walk through an example using given input and see how the program determines if two rivers meet and the number of rivers they need to cross to reach the point of confluence.

### Input:
```
6 4 6 5
1 2
3 4
4 5
3 6
```

### Output:
```
IGEN
1 2
```

In this example, rivers 6 and 5 meet at river 4, and they need to cross rivers 1 and 2 to reach the point of confluence. The program successfully identifies these relationships.

### Note:

The program efficiently calculates the relevant river relationships using BFS. If you have any specific questions or need further assistance, feel free to ask!
*/