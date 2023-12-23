#include <iostream>
#include <vector>
#include <stack>
#include <set>
#define N 100001
using namespace std;

/*
- **Problem Description**:
  Adam lives in a city where a grand festival is taking place. The city has various intersections, and each intersection has some attraction for the festival. Adam wants to walk from intersection A (where he lives) to intersection B, passing through as many attractions as possible.

- **Task**:
  Write a program to determine the maximum number of attractions Adam can visit on his walk from intersection A to intersection B.

- **Input**:
  - The first line of standard input contains the number of intersections N (2 ≤ N ≤ 100,000), the number of streets M (2 ≤ M ≤ 500,000), and the serial numbers of intersections A and B (1 ≤ A, B ≤ N).
  - The next M lines each contain two serial numbers of intersections U and V (1 ≤ U ≠ V ≤ N), indicating a one-way street from U to V.

- **Output**:
  - The program should output the maximum number of intersections Adam can visit during his walk, including both intersections A and B.

- **Example**:
  - **Input**:
    ```
    10 15 2 6
    1 2
    2 3
    3 1
    2 4
    1 10
    3 8
    9 5
    3 5
    5 6
    6 7
    7 5
    3 9
    10 7
    8 9
    9 8
    ```
  - **Output**:
    ```
    8
    ```

- **Constraints**:
  - The computation should be completed within 0.2 seconds.
  - The memory usage should not exceed 32 MB.
  - In 30% of the tests, N ≤ 100.
*/

int n, m, kezd, veg;
vector<int> a[N];
vector<int> disc(N, -1), low(N, -1), parent(N, -1);
vector<bool> stackMember(N, false);
stack<int> st;
int t = 0;
int compIndex = 0;
vector<int> comp[N];
vector<int> color(N);
int ans = 0;
int endNode;
int startNode;

void tarjan(int node)
{
    low[node] = disc[node] = t;
    t++;
    st.push(node);
    stackMember[node] = true;

    for (int adj : a[node])
    {
        if (disc[adj] == -1)
        {
            tarjan(adj);

            low[node] = min(low[node], low[adj]);
        }
        else if (stackMember[adj])
        {
            low[node] = min(low[node], disc[adj]);
        }
    }

    int w = 0;
    if (low[node] == disc[node])
    {
        while (st.top() != node)
        {
            w = st.top();
            stackMember[w] = false;
            comp[compIndex].push_back(w);
            color[w] = compIndex;
            st.pop();
        }
        w = st.top();
        comp[compIndex].push_back(w);
        color[w] = compIndex;
        stackMember[w] = false;
        st.pop();
        compIndex++;
    }
}

void solve()
{
    vector<int> g[compIndex];
    vector<int> gSize(compIndex);

    for (int i = 0; i < compIndex; i++)
    {
        vector<bool> used(compIndex, false);
        for (int j : comp[i])
        {
            if (j == veg)
            {
                endNode = i;
            }
            if (j == kezd)
            {
                startNode = i;
            }
            for (int adj : a[j])
            {
                if (color[adj] != color[j] and !used[color[adj]])
                {
                    g[i].push_back(color[adj]);
                    used[color[adj]] = true;
                }
            }
            gSize[i]++;
        }
    }
    vector<int> dist = gSize;
    set<pair<int, int>> q;
    pair<int, int> s = {gSize[startNode], startNode};
    q.insert(s);



    while (!q.empty())
    {
        s = *q.rbegin();
        q.erase(s);
        int node = s.second;
        int distance = dist[node];
        for (int adj : g[node])
        {
            // cout<<adj<<" ";
            if (gSize[adj] + distance > dist[adj])
            {
                dist[adj] = gSize[adj] + distance;
                q.insert({dist[adj], adj});
            }
        }
        // cout<<endl;
    }
    ans = dist[endNode];
}

int main()
{
    cin >> n >> m >> kezd >> veg;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }
    tarjan(kezd);
    solve();
    cout << ans << endl;
    return 0;
}
/*
The given program aims to determine the maximum number of attractions Adam can visit on his walk from intersection A to intersection B. It utilizes Tarjan's algorithm to find strongly connected components and then calculates the maximum number of intersections Adam can visit.

Here's a step-by-step explanation of how the program works:

1. **Input Reading:**
   - Read the number of intersections (N), the number of streets (M), and the serial numbers of intersections A and B from the standard input.
   - Read M lines, each containing two serial numbers of intersections indicating a one-way street.

2. **Tarjan's Algorithm for SCC:**
   - Use Tarjan's algorithm to find strongly connected components (SCC) in the graph, represented by the `comp` vector.
   - Determine the start node's SCC (`startNode`) and the end node's SCC (`endNode`).

3. **Graph Transformation:**
   - Transform the graph to represent SCCs as nodes and edges between SCCs.

4. **Shortest Path in SCC Graph:**
   - Use a modified Dijkstra's algorithm to find the maximum number of attractions Adam can visit, considering each SCC as a node and edges between SCCs as attractions.

5. **Output:**
   - Output the maximum number of intersections Adam can visit during his walk.

### Output:
The program outputs the maximum number of intersections Adam can visit on his walk from intersection A to intersection B.

The program seems to be working correctly to determine the maximum number of attractions Adam can visit. If you have any specific questions or concerns, feel free to ask!
*/