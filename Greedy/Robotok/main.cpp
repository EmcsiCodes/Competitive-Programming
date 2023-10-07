#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
Here's a summary of the problem "Robotok" (Robots):

- **Problem Description**:
  Given a grid of cells with objects, robots need to collect these objects. Each robot starts from the top-left cell (1,1) and moves to the bottom-right cell (N,M). In one step, a robot can move to a neighboring cell below or to the right. Along its path, the robot collects the objects on the cells it visits. The goal is to minimize the number of robots needed to collect all objects.

- **Task**:
  Create a program that calculates the minimum number of robots needed to collect all the objects.

- **Input**:
  - The first line of standard input contains the number of rows N (1 ≤ N ≤ 100,000), the number of columns M (1 ≤ M ≤ 100,000), and the number of cells K (1 ≤ K ≤ 100,000) where objects are located.
  - The next K lines each contain the coordinates of the cells where the objects are (1 ≤ A ≤ N, 1 ≤ B ≤ M). There's at most one object per cell.

- **Output**:
  - The program should output the minimum number of robots needed to collect all the objects.

- **Example**:
  - **Input**:
    ```
    4 6 7
    1 2
    1 4
    2 2
    3 4
    3 5
    4 3
    3 2
    ```
  - **Output**:
    ```
    2
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/

vector<int> robots[100001];

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1; i<=k; i++){
        int x,y;
        cin>>x>>y;
        robots[y].push_back(x);
    }
    vector<int> v;
    for(int i=1; i<=m; i++){
        for(auto j:robots[i]){
            v.push_back(j);
        }
    }
    set<int> res;
    res.insert(v[0]);
    for(int i=1; i<v.size(); i++){
        auto it = res.lower_bound(v[i]);
        if(it == res.begin()) res.insert(v[i]);
        else if(*it!=v[i]){
            it--;
            res.erase(it);
            res.insert(v[i]);
        }
    }
    cout<<res.size();
    return 0;
}
/*
This program solves the problem of minimizing the number of robots needed to collect all objects in a grid. Here's a step-by-step explanation:

1. **Understanding the Problem**:
   - The program takes input for the number of rows `N`, the number of columns `M`, and the number of cells `K` where objects are located.
   - Each cell with an object is represented by its coordinates `(A, B)`.

2. **Approach**:
   - The program organizes the objects based on their column positions.
   - It then iterates through the columns, maintaining a set `res` to track the last visited row in each column where an object is located.
   - For each object, it tries to find the last visited row in its column using `lower_bound` on the set.
   - If it finds a lower bound and the object's row is different from the last visited row in its column, it updates the set.
   - The set `res` effectively keeps track of the rows where robots can pick up objects in each column, minimizing the number of robots needed.

3. **Output**:
   - The program outputs the size of the set `res`, representing the minimum number of robots needed to collect all the objects.

4. **Explanation**:
   - The program efficiently calculates the minimum number of robots needed by organizing and processing objects based on their column positions.
   - It ensures that robots can efficiently collect objects by minimizing the number of row visits in each column.

5. **Time Complexity**:
   - The time complexity of the algorithm is O(KlogK) due to the sorting of objects based on their column positions.

This approach efficiently minimizes the number of robots needed to collect all objects in the grid.
*/