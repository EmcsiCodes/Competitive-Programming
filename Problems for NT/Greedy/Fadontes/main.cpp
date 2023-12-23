#include <iostream>
#include <vector>

using namespace std;
/*
Here's a summary of the problem "Tree Falling":

- **Problem Description**:
  Trees are planted in a row in a forest. Each tree has a known height and the distance from the leftmost tree. When a tree is cut down, it falls toward its right neighbor, potentially causing a chain reaction of falling trees. The goal is to determine the minimum number of trees to be cut down to ensure all trees fall.

- **Input**:
  - The first line of standard input contains the number of trees, N (1 ≤ N ≤ 1000).
  - The following N lines each contain a tree's distance from the leftmost tree (T) and its height (M).

- **Output**:
  - The first line should display the minimum number of trees to be cut down.
  - The second line should contain the number of the tree that, when cut down, would cause the maximum number of trees to fall.

- **Example**:
  - **Input**:
    ```
    5
    0 6
    3 1
    5 2
    8 1
    15 10
    ```
  - **Output**:
    ```
    3
    1
    ```

- **Constraints**:
  - Time Limit: 0.1 seconds
  - Memory Limit: 32 MB
*/
struct in{
    int dis;
    int h;
};

int main()
{
    int n;
    cin>>n;
    vector<in> v;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    int i=0;
    int mostTree = 0;
    int mostTreeI = 0;
    int minCut = 0;
    while(i<v.size()){
        int maxDis = v[i].h + v[i].dis;
        int fallenTree = 0, currI = i + 1;
        while(i<v.size() && maxDis>v[i].dis){
            maxDis = max(maxDis, v[i].h + v[i].dis);
            fallenTree++;
            i++;
        }
        if(fallenTree > mostTree){
            mostTree = fallenTree;
            mostTreeI = currI;
        }
        minCut++;
    }
    cout<<minCut<<'\n'<<mostTreeI;
    return 0;
}
/*
### Program: "Tree Falling"

1. **Understanding the Problem**:
   - The problem involves determining the minimum number of trees to be cut down in a row of trees to ensure that all trees fall by cutting down the appropriate tree.

2. **Approach**:
   - Iterate through the trees in the given order.
   - For each tree, calculate the maximum distance it can reach after falling.
   - Keep track of the maximum number of trees that can be knocked down with a single cut.
   - Track the tree number that achieves the maximum fallen trees.
   - Output the minimum number of trees to be cut down and the tree number that achieves the maximum fallen trees.

3. **Algorithm**:
   - Read input values for the number of trees, N.
   - Create a vector to store tree information (distance, height).
   - Iterate through the trees:
     - Calculate the maximum distance the tree can reach after falling.
     - Update the maximum fallen trees and the corresponding tree number.
   - Output the minimum number of trees to be cut down and the tree number that achieves the maximum fallen trees.

4. **Explanation**:
   - We iterate through the trees and calculate the maximum distance each tree can reach after falling.
   - We keep track of the maximum number of trees that can be knocked down with a single cut and the tree number that achieves this.
   - We output the minimum number of trees to be cut down and the tree number that achieves the maximum fallen trees.

5. **Time Complexity**:
   - Iterating through the trees: O(N)
   - Total: O(N)

This approach determines the minimum number of trees to be cut down to ensure all trees fall by analyzing the reach of each tree after falling and identifying the tree that achieves the maximum fallen trees.
*/