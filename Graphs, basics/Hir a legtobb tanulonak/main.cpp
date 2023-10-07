#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
- **Problem Description**:
  Each student in a class knows the phone numbers of some of their classmates. You need to find the smallest numbered student from whom a piece of news, passed through the known phone numbers, will eventually reach the maximum number of students in the class.

- **Input**:
  - The first line of standard input contains the number of students N (1 ≤ N ≤ 250).
  - The following N lines each contain a list of integers representing the phone numbers known by each student. Each list is terminated by a zero (0). The integers are the student IDs.

- **Output**:
  - The program should output the ID of a student from whom the news will reach the maximum number of students.

- **Example**:
  - **Input**:
    ```
    5
    3 5 0
    3 4 0
    0
    2 3 0
    2 0
    ```
  - **Output**:
    ```
    1
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
vector<int> adj[251];  // Adjacency list to store the graph

int BFS(int node, int n) {
    int peopleVisited = 0;
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        node = q.front();
        q.pop();
        for (auto i : adj[node]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
                peopleVisited++;
            }
        }
    }
    return peopleVisited;
}

int main() {
    int n;
    cin >> n;

    // Input phone numbers and build the graph
    for (int i = 1; i <= n; i++) {
        int x;
        while (cin >> x && x != 0) {
            adj[i].push_back(x);
        }
    }

    pair<int, int> res = {0, 0};

    // Perform BFS from each student and find the one reaching the most students
    for (int i = 1; i <= n; i++) {
        int c = BFS(i, n);
        if (res.second < c) {
            res.first = i;
            res.second = c;
        }
    }

    cout << res.first;

    return 0;
}
/*
### News Spread Analysis

#### Approach:
The problem is about finding the smallest numbered student from whom a piece of news will eventually reach the maximum number of students in the class.

1. **Graph Representation**:
   - We model the problem as an undirected graph, where each student is a node, and phone numbers represent edges between students.

2. **Breadth-First Search (BFS)**:
   - We perform a BFS from each student to find the number of students who can receive the news when starting from that student.
   - We keep track of the maximum number of students reached and the corresponding student ID.

The code calculates the number of students reached starting
from each student and outputs the student ID from whom the news will reach the maximum number of students.
*/