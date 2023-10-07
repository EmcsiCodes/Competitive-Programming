#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

/*
**Problem Summary:**

Given a royal family's family tree, you need to find the farthest descendants from the common ancestor. The family members are descended from a single common ancestor, and the descendants are at various levels of generations away from this ancestor.

**Input:**

- The number of family members, N (1 ≤ N ≤ 1,000,000).
- N-1 lines, each containing the father's index for each family member.

**Output:**

- The number of farthest descendants and their distance from the common ancestor.
- The indices of the farthest descendants in ascending order.

**Example:**

- **Input:**
  ```
  10
  1
  2
  1
  4
  5
  5
  1
  8
  9
  ```

- **Output:**
  ```
  3 3
  6 7 10
  ```

This means that there are 3 farthest descendants with a distance of 3 from the common ancestor, and their indices are 6, 7, and 10.


*/

int n;
vector<int> a[1000001];
vector<int> solve;
int maxx = 0;

void dfs(int node, int length)
{
    if (length > maxx)
    {
        solve.clear();
        maxx = length;
        solve.push_back(node);
    }
    else if (length == maxx)
    {
        solve.push_back(node);
    }

    for (int adj : a[node])
    {
        dfs(adj, length + 1);
    }
}
int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x].push_back(i);
    }
    dfs(1, 0);
    sort(solve.begin(), solve.end());
    cout << solve.size() << " " << maxx << endl;
    for (int i : solve)
        cout << i << " ";
    return 0;
}
/*
This program finds the farthest descendants from a common ancestor in a family tree.

Here's a detailed explanation of the approach:

1. **Input Processing**:
   - Reads the number of family members `N`.
   - Reads `N-1` lines, each containing the father's index for each family member. It stores this information in an adjacency list representation of the family tree.

2. **DFS Traversal** (`dfs` function):
   - Performs a depth-first search (DFS) traversal starting from the common ancestor (index 1).
   - Keeps track of the maximum distance from the common ancestor (`maxx`).
   - Stores the farthest descendants in the `solve` vector.
   - If a descendant is found with a distance greater than `maxx`, it clears the `solve` vector and updates `maxx`.
   - If a descendant is found with a distance equal to `maxx`, it appends the index to the `solve` vector.

3. **Output**:
   - Prints the number of farthest descendants and their distance from the common ancestor.
   - Prints the indices of the farthest descendants in ascending order.

4. **Main Function**:
   - Calls the `dfs` function to perform DFS traversal and find the farthest descendants.
   - Sorts the `solve` vector in ascending order.
   - Prints the required output.

### Example Walkthrough:

Let's take the provided example:

- **Input**:
  ```
  11
  1
  2
  1
  4
  5
  5
  1
  8
  9
  10
  ```

- **Algorithm Execution** (`dfs` function):
  - It performs a DFS traversal starting from the common ancestor (index 1) and calculates the distances from the common ancestor to each descendant.
  - It keeps track of the maximum distance (`maxx`) and stores the farthest descendants in the `solve` vector.

- **Output**:
  ```
  3 3
  6 7 10
  ```

This means that there are 3 farthest descendants with a distance of 3 from the common ancestor, and their indices are 6, 7, and 10.
*/