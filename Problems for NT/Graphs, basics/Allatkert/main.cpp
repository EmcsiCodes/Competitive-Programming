#include <iostream>
#include <vector>
using namespace std;
/*
- **Problem Name**: Állatkert (Zoo)

- **Problem Description**:
  In a zoo, the paths that can be traversed are known. The entrance is at point 0. The animals are identified by their numbers between 1 and N (1 ≤ N ≤ 1000), and the paths are represented by pairs of animal numbers, indicating the paths between their enclosures.

- **Task**:
  Write a program that, given the knowledge of the zoo paths, determines the number of dead-end enclosures and identifies the animal with the most paths leading to it (if there are multiple, any can be provided).

- **Input**:
  - The first line of the standard input contains N and M (1 ≤ N ≤ 10,000, 1 ≤ M ≤ 200,000), separated by a space.
  - The following M lines each contain two integers representing the starting and ending points of the paths.

- **Output**:
  - The program should output, in a single line, the number of dead-end enclosures and the number of the animal with the most accessible paths.

- **Example**:
  - **Input**:
    ```
    5 7
    0 1
    1 4
    3 1
    3 5
    2 0
    2 3
    1 2
    ```
  - **Output**:
    ```
    2 1
    ```

- **Constraints**:
  - Time Limit: 0.1 seconds
  - Memory Limit: 32 MiB
  - In 30% of the tests, N, M ≤ 100.
*/
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[10001];
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int res = 0, index = 0, count = 0;
    for(int i=1; i<=n; i++){
        if(adj[i].size() > res){
            res = adj[i].size();
            index = i;
        }
        if(adj[i].size() == 1){
            count ++;
        }
    }
    cout<<count<<" "<<index;
    return 0;
}
/*
The provided program addresses the problem of determining the number of dead-end enclosures and identifying the animal with the most accessible paths in a zoo. The paths between enclosures are represented by pairs of animal numbers.

Here's a summary of the program's logic:

1. **Input Reading:**
   - Read the number of animals (N) and the number of paths (M).
   - Read the details of each path, represented by pairs of starting and ending points (animal numbers).

2. **Path Representation:**
   - Use an adjacency list to represent the paths between enclosures (animals).

3. **Counting Dead-End Enclosures and Finding Most Accessible Animal:**
   - Traverse each animal and count the number of paths (edges) connected to it.
   - Identify the animal with the most accessible paths (highest degree) and count the number of dead-end enclosures (degree 1).

4. **Output:**
   - Output the number of dead-end enclosures and the number of the animal with the most accessible paths.

### Output:
The program outputs the number of dead-end enclosures and the number of the animal with the most accessible paths.

The program appears to correctly solve the problem by determining the required information about the zoo's paths and enclosures.
*/