#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
- **Problem Name**: Gyár (Factory)

- **Problem Description**:
  A company has factories in K cities producing goods that need to be delivered to N other cities. The transportation routes need reinforcement to accommodate heavy trucks. A factory and a road need to be designated for each city, ensuring the overall route length is minimized.

- **Task**:
  Write a program that determines which factory should supply each city, and the reinforced roads between them, to minimize the total route length.

- **Input**:
  - The first line contains the number of cities N (1 ≤ N ≤ 20,000), the number of cities containing a factory K (1 ≤ K ≤ N), and the number of roads between cities M (1 ≤ M ≤ 500,000).
  - The following M lines each contain three integers, indicating a road: the starting city, the destination city, and the road length (1 ≤ X, Y ≤ N, 1 ≤ H ≤ 1000).
  - The last line contains K distinct integers representing the cities containing a factory (1 ≤ Si ≤ N).

- **Output**:
  - The program should output the total length of the reinforced roads.
  - The next lines should contain pairs of integers representing the reinforced roads' endpoints, separated by a space.

- **Example**:
  - **Input**:
    ```
    6 2 7
    1 2 5
    1 3 3
    2 4 2
    3 4 4
    2 5 3
    2 6 8
    5 6 1
    1 6
    ```
  - **Output**:
    ```
    9
    5 2
    1 3
    2 4
    6 5
    ```

- **Constraints**:
  - Time Limit: 0.5 seconds
  - Memory Limit: 32 MiB
  - In 30% of the tests, N ≤ 100.
*/
struct nodes
{
    int node1;
    int node2;
    int d;
};
struct Compare
{
    bool operator()(nodes &p1, nodes &p2)
    {
        return p1.d > p2.d;
    }
};

vector<int> parent(20001, 0), s(20001, 1);
vector<bool> startNodes(20001, false);
priority_queue<nodes, vector<nodes>, Compare> pq;

int find(int a)
{
    int root = a;
    while (root != parent[root])
        root = parent[root];
    while (a != root)
    {
        int next = parent[a];
        parent[a] = root;
        a = next;
    }
    return root;
}

void Unite(int a, int b)
{
    int root1 = find(a);
    int root2 = find(b);
    if (s[root1] < s[root2])
    {
        parent[root1] = parent[root2];
        s[root2] += s[root1];
    }
    else
    {
        parent[root2] = parent[root1];
        s[root1] += s[root2];
    }
}

int main()
{
    int n, k, m;
    cin >> n >> k >> m;

    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        pq.push({x, y, z});
    }

    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        startNodes[x] = true;
        s[x] = 25000;
    }

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    int totalDis = 0;
    vector<pair<int, int>> res;
    while (!pq.empty())
    {
        nodes curr = pq.top();
        pq.pop();
        int root1 = find(curr.node1);
        int root2 = find(curr.node2);
        if (root1 != root2 && !(s[root1]>=25000 && s[root2]>=25000))
        {
            Unite(curr.node1, curr.node2);
            totalDis += curr.d;
            res.push_back({curr.node1, curr.node2});
        }
    }
    cout << totalDis << endl;
    for (auto i : res)
        cout << i.first << " " << i.second << endl;

    return 0;
}
/*
The provided program addresses the problem of determining which factory should supply each city and the reinforced roads between them to minimize the total route length in a transportation network. It uses a Union-Find data structure and a priority queue (min heap) to achieve this.

Here's a breakdown of the program:

1. **Input Reading:**
   - Read the number of cities (N), the number of cities containing a factory (K), and the number of roads between cities (M).
   - Read the details of roads, including the starting city, destination city, and road length.
   - Read the cities containing a factory.

2. **Union-Find Data Structure:**
   - Initialize a Union-Find data structure to keep track of connected components (disjoint sets) and their sizes.
   - Each city is initially considered as a separate connected component.

3. **Minimum Distance Calculation:**
   - Use a priority queue (min heap) to select the next road to be considered.
   - Pop the shortest road from the priority queue, check if it connects different components, and merge the components if needed.
   - Track the total reinforced road length.

4. **Output:**
   - Output the total length of the reinforced roads.
   - Output the pairs of cities representing the reinforced roads' endpoints.

### Output:
The program outputs the total length of the reinforced roads and specifies the pairs of cities representing the reinforced roads' endpoints.

The program appears to be correctly solving the problem by minimizing the total route length in the transportation network.
*/