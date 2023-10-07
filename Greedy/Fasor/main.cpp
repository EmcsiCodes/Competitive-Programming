#include <iostream>
#include <vector>

using namespace std;
/*
Here's a summary of the problem "Tree Line":

- **Problem Description**:
  In the Hundred Acre Wood, there is a row of N trees, and each pair of adjacent trees is 1 pagometer apart. Owl is happy when sitting on top of a tree and cannot see a taller tree nearby. Owl's vision is limited to K pagometers, meaning it can only see trees within that range.

- **Task**:
  Create a program that determines the first tree in the row where Owl can sit happily, considering its limited vision.

- **Input**:
  - The first line of standard input contains the number of trees, N (1 ≤ N ≤ 200,000), and Owl's vision range K (1 ≤ K ≤ 200,000).
  - The second line contains the heights of the trees, given in the order of the trees (1 ≤ Hi ≤ 1,000,000).

- **Output**:
  - The program should output the number of the first suitable tree where Owl can sit happily.
  - If no such tree exists, it should output -1.

- **Example**:
  - **Input**:
    ```
    10 3
    6 2 1 8 4 8 7 12 9 3
    ```
  - **Output**:
    ```
    4
    ```

- **Constraints**:
  - Time Limit: 0.2 seconds
  - Memory Limit: 32 MB
  - 50% of the points are for cases where N ≤ 10,000 and K ≤ 100.
*/
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int maxx = 0, curr = 0, i = 0;
    while(i<v.size() && curr<k){
        if(v[i]>maxx){
            curr = 0;
            maxx = v[i];
        } else curr++;
        i++;
    }
    cout<<i - curr;
}
/*
### Program: "Tree Line"

1. **Understanding the Problem**:
   - The problem involves finding the first tree in a row where an owl can sit happily, given its limited vision range.
   - Owl is happy when it cannot see a taller tree within its vision range.

2. **Approach**:
   - Iterate through the trees while keeping track of the current vision range.
   - If the current tree is taller than the previous tallest tree, reset the vision range and update the tallest tree.
   - If the current tree is not taller, decrease the vision range.
   - If the vision range reaches zero, it means the owl can sit happily on the current tree.
   - Output the number of this tree.

3. **Algorithm**:
   - Read input values for the number of trees, N, and Owl's vision range, K.
   - Create a vector to store the heights of the trees.
   - Iterate through the trees:
     - If the current tree is taller than the previous tallest tree:
       - Update the tallest tree.
       - Reset the vision range.
     - If the vision range is not zero, decrease it.
     - If the vision range reaches zero, the owl can sit happily on this tree. Output its number.
   - If no suitable tree is found, output -1.

4. **Explanation**:
   - We iterate through the trees, keeping track of the vision range based on the previous tallest tree.
   - When we find a tree taller than the previous tallest tree, we reset the vision range and update the tallest tree.
   - If the vision range reaches zero, the owl can sit happily on this tree.
   - We output the number of this tree.

5. **Time Complexity**:
   - Iterating through the trees: O(N)
   - Total: O(N)

This approach finds the first tree where the owl can sit happily within its limited vision range, satisfying the problem requirements.
*/