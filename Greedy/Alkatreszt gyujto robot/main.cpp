#include <iostream>
#include <vector>
#include <set>

using namespace std;
/*
- **Problem Description**:
  In an automated manufacturing plant, machines are arranged in a grid within a large workshop. Robots collect the components produced by the machines at the end of a shift. The robots move on a grid-shaped path above the machines. They start at the top left corner of the grid and need to transport the components to the bottom right corner. Robots can only move right or down.

  Given the floor plan of the workshop, where 0 denotes an empty space and 1 denotes a machine, create a program that calculates the minimum number of robots needed to collect all the components, assuming each robot can transport any number of components.

- **Input**:
  - The first line of standard input contains two integers, M and N, separated by a single space (1 ≤ M, N ≤ 100). M is the number of rows, and N is the number of columns.
  - The next M lines each contain N numbers, 0 or 1, separated by spaces, representing the workshop's floor plan.

- **Output**:
  - The program should output a single number, the minimum number of robots required to collect all the components.

- **Example**:
  - **Input**:
    ```
    10 12
    0 1 1 1 0 0 1 0 1 0 0 0
    0 1 0 0 0 1 0 0 0 0 0 0
    0 0 0 1 0 0 0 0 1 0 0 0
    1 0 0 0 0 1 0 0 0 0 0 0
    0 0 0 1 0 0 0 0 0 0 0 0
    0 1 0 0 1 0 0 0 0 0 0 0
    1 0 0 0 0 1 1 1 1 0 0 0
    1 1 1 1 1 1 0 0 0 1 0 0
    1 0 0 0 0 0 0 0 0 1 0 0
    1 0 0 0 0 0 0 0 0 1 0 0
    ```
  - **Output**:
    ```
    5
    ```

- **Constraints**:
  - The values ensure the computation can be performed within a reasonable time frame.
*/
vector<int> adj[101];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int x;
            cin>>x;
            if(x == 1) adj[j].push_back(i);
        }
    }
    vector<int> lis;
    for(int i=1; i<=m; i++){
        for(auto j:adj[i]) lis.push_back(j);
    }
    set<int> s;
    int res = 0;
    s.insert(lis[0]);
    for(int i=1; i<lis.size(); i++){
        auto it = s.lower_bound(lis[i]);
        if(it == s.begin()){
            s.insert(lis[i]);
        } else if(*it != lis[i]){
            it--;
            s.erase(it);
            s.insert(lis[i]);
        }
    }
    cout<<s.size();
    return 0;
}
/*
Sure, let's discuss the use of the Longest Increasing Subsequence (LIS) method to solve the problems where it's applicable. The LIS method is a common algorithmic technique used for finding the longest subsequence (not necessarily contiguous) in an array or sequence that is in increasing order.

### Longest Increasing Subsequence (LIS) Method

#### Overview:
- LIS is a dynamic programming-based approach.
- It helps find the longest subsequence in a given array/sequence where elements are in increasing order.
- It's a versatile algorithm and is used in various problem-solving scenarios.

#### Steps to Use LIS Method for Problem Solving:

1. **Identify a Suitable Problem**:
   - LIS is applicable to problems where the task is to find a subsequence (not necessarily contiguous) that has some specified properties (like being in increasing order, etc.).

2. **Map Problem to LIS**:
   - Map the problem's constraints and conditions to the LIS problem.
   - Understand how the elements in the given problem can be compared or arranged in a way that represents an increasing subsequence.

3. **Create an Array for DP**:
   - Create an array to store the length of the longest increasing subsequence ending at each index.

4. **Dynamic Programming (DP) Approach**:
   - Traverse through the array and, for each element, calculate the length of the longest increasing subsequence ending at that element.
   - Update the DP array accordingly.

5. **Find the Longest Increasing Subsequence**:
   - Once the DP array is filled, traverse it to find the maximum length. This length is the length of the longest increasing subsequence.
   - Based on the DP array, reconstruct the LIS if needed.

6. **Utilize the LIS for Problem Solution**:
   - Depending on the problem, the LIS found can directly answer the question or part of the question.

#### Benefits of Using LIS Method:
- Utilizing the LIS approach often simplifies problem-solving by breaking down the problem into manageable steps.
- It can convert a complex problem into a well-defined algorithmic pattern.

#### Example Usage:
- In the "Minimum Robots for Component Collection" problem, we used a simplified LIS approach to traverse the grid and count the minimum number of robots needed. We identified that robots are needed when moving right or down, representing an "increasing subsequence" in a sense.
*/