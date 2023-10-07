#include <iostream>
#include <vector>
using namespace std;
/*
- **Problem Description**:
  Given roads and their lengths connecting villages and towns within a county, find the following:
  A. The length of the longest one-way road leading to a dead-end village (a village with only one road leading in or out, and there's no other way to continue).
  B. Villages with the highest number of roads originating from them (multiple if tied).
  C. The village that has the farthest neighbor (the neighbor with the longest distance).

- **Input**:
  - The first line of standard input contains the number of settlements N (2 ≤ N ≤ 1000) and the number of roads M (1 ≤ M ≤ 70000).
  - The following M lines each contain three integers: the two endpoints of a road (representing a connection between two settlements) and the length of the road.

- **Output**:
  - The program should output the answers to questions A, B, and C in three separate lines.

- **Example**:
  - **Input**:
    ```
    7 8
    1 2 10
    2 3 15
    2 4 10
    2 5 5
    3 5 5
    4 5 15
    5 6 5
    6 7 10
    ```
  - **Output**:
    ```
    15
    2 5
    1
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v[1001];  // Adjacency list to store the graph

    // Input roads and build the graph
    for (int i = 1; i <= m; i++) {
        int x, y, s;
        cin >> x >> y >> s;
        v[x].push_back({y, s});
        v[y].push_back({x, s});
    }

    int longestPath = 0;

    // Find the longest one-way road to a dead-end village
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        if (v[i].size() == 1) {
            sum = v[i][0].second;
            int j = v[i][0].first;
            int p = i;
            while (v[j].size() == 2) {
                if (v[j][0].first == p) {
                    sum += v[j][1].second;
                    j = v[j][1].first;
                } else {
                    sum += v[j][0].second;
                    j = v[j][0].first;
                }
                p = j;
            }
        }
        longestPath = max(longestPath, sum);
    }

    cout << longestPath << endl;

    int mostPaths = 0;

    // Find the villages with the most roads originating from them
    for (int i = 1; i <= n; i++) {
        int p = v[i].size();
        mostPaths = max(mostPaths, p);
    }

    for (int i = 1; i <= n; i++) {
        if (v[i].size() == mostPaths) {
            cout << i << " ";
        }
    }
    cout << '\b' << '\n';

    int maxmin = 0;
    int maxminIndex = 0;

    // Find the village with the farthest neighbor
    for (int i = 1; i <= n; i++) {
        int currMin = 1000000;
        for (auto j : v[i]) {
            currMin = min(currMin, j.second);
        }
        if (currMin > maxmin) {
            maxmin = currMin;
            maxminIndex = i;
        }
    }

    cout << maxminIndex << endl;

    return 0;
}
/*
### Road Analysis

#### Approach:
The problem involves analyzing roads and settlements within a county and deriving specific information based on the road networks.

1. **Graph Representation**:
   - We model the problem as an undirected graph, where each settlement is a node, and roads connecting settlements are edges.
   - Each edge holds information about its length.

2. **Longest One-Way Road to Dead-End Village**:
   - For each village that is a dead-end (has only one road leading in or out), we traverse the graph until we reach a non-dead-end or a cycle.
   - We calculate the total length for each such path and keep track of the longest one.

3. **Villages with Most Roads Originating From Them**:
   - We calculate the degree (number of roads originating from) for each village and find the maximum degree.
   - We then output the villages with this maximum degree.

4. **Village with Farthest Neighbor**:
   - For each village, we find the neighbor with the longest distance and output the village with this neighbor.

The code first determines the longest one-way road to a dead-end village,
villages with the most roads originating from them,
and the village with the farthest neighbor, as per the given problem.
*/