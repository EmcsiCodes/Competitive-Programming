#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
**Problem Summary:**

In a spy organization, each member can have at most 2 subordinates. Messages from members reach their direct subordinates within 1 day. The head of the organization is member 1.

Write a program that determines, starting from the head, on which day the majority of members receive the message.

**Input:**

- Number of members (N).
- N-1 lines describing the relationships (Ai, Bi), meaning member with serial number Ai is the direct subordinate of member with serial number Bi (1 ≤ Ai ≠ Bi ≤ N).

**Output:**

- The serial number of the day when the majority of members receive the message.

**Example:**

**Input:**
```
12
1 2
1 3
2 4
2 5
3 6
5 7
5 8
6 9
6 10
10 11
10 12
```

**Output:**
```
3
```

---
*/
vector<int> adj[10001];

void BFS(int start,int n){
    queue<int> q;
    vector<bool> visited(n+1,false);
    visited[start] = true;
    q.push(start);
    int backnode = q.back();
    int mostPeople = 0;
    int mostPeopleI = 0;
    int day = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }            
        if(backnode == node){
            backnode = q.back();
            day++;
            if(mostPeople < q.size()){
                mostPeople = q.size();
                mostPeopleI = day;
            }
            
        }
    }
    cout<<mostPeopleI;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<n; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    BFS(1,n);
    return 0;
}
/*
The provided program aims to determine on which day the majority of members in a spy organization receive a message. Members have at most 2 subordinates, and messages reach their direct subordinates within 1 day. The head of the organization is member 1.

Here's a more detailed explanation of the approach and implementation:

### Approach:

1. **Graph Representation:**
   - The members and their relationships can be represented as a directed graph, where nodes represent members, and directed edges indicate the superior-subordinate relationship.

2. **BFS for Message Distribution:**
   - We perform a breadth-first search (BFS) starting from the head (member 1) to simulate the distribution of messages.
   - Each day, the message is sent to the direct subordinates of members who have not received the message yet.
   - We keep track of the day and the number of members who have received the message each day.

3. **Output the Day with the Most Receivers:**
   - After BFS, we determine the day with the maximum number of members who have received the message, which corresponds to the majority of members.

### Implementation:

1. **Graph Representation:**
   - The program uses an adjacency list to represent the directed graph, where each member (node) stores its immediate subordinates (outgoing edges).

2. **BFS for Message Distribution:**
   - Starting from the head (member 1), BFS traversal is performed to simulate the distribution of messages each day.
   - The queue is used to keep track of the members who have received the message on a given day.
   - We increment the day each time we finish distributing messages for a day and keep track of the day with the maximum number of receivers.

3. **Output:**
   - The program outputs the serial number of the day when the majority of members receive the message.

### Example Walkthrough:

Let's go through the given example step by step, showing how the program calculates the required information.

### Input:
```
12
1 2
1 3
2 4
2 5
3 6
5 7
5 8
6 9
6 10
10 11
10 12
```

### Steps:
1. **Graph Representation:**
   - We create a directed graph based on the input where edges represent the superior-subordinate relationship.

2. **BFS for Message Distribution:**
   - Starting from the head (member 1), BFS traversal simulates message distribution, considering at most 2 subordinates for each member.
   - We keep track of the number of members who have received the message on each day.

3. **Output:**
   - The output is the serial number of the day when the majority of members receive the message.

### Conclusion:

The program effectively determines the day when the majority of members receive the message, considering the hierarchical relationships and message distribution rules. It utilizes BFS traversal to simulate message distribution and determine the output.

*/