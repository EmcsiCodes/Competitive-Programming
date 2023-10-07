#include <iostream>
#include <vector>
#include <set>
using namespace std;
/*
Here's a summary of the problem "Ládák balról jobbra" (Boxes from Left to Right):

- **Problem Description**:
  You have a series of boxes. Each box is cube-shaped with one open side. You need to pack the boxes together using a robot that can only move from left to right. The robot can place one box into another if the latter is smaller in size. However, the robot can only move in one direction, and it can either put a box into another previously packed box or leave it separately. The goal is to minimize the number of packed boxes.

- **Task**:
  Create a program that determines the minimum number of boxes required to pack the series of boxes together and specifies which boxes are packed together.

- **Input**:
  - The first line of standard input contains the number of boxes N (0 ≤ N ≤ 10,000).
  - The second line contains N positive integers, representing the sizes of the boxes. Each integer is between 1 and 30,000.

- **Output**:
  - The program should output the minimum number of boxes M required for packing.
  - The following M lines should specify the packing by listing the indices of boxes that are packed together, one line at a time.

- **Example**:
  - **Input**:
    ```
    10
    4 1 5 10 7 9 2 8 3 2
    ```
  - **Output**:
    ```
    4
    1 2
    3 7
    4 5 9 10
    6 8
    ```

- **Constraints**:
  - Time Limit: 0.1 seconds
  - Memory Limit: 32 MB
*/
int main()
{
    int n;
    cin>>n;
    vector< pair<int,int > > v;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v.push_back({x,1});
    }
    multiset< pair<int,int> > s;
    for(int i=v.size()-1; i>=0; i--){
        auto it = s.lower_bound({v[i].first,0});
        if(it == s.begin()){
            v[i].second = s.size();
            s.insert(v[i]);
        }
        else {
            it--;
            s.erase(it);
            v[i].second = it->second;
            s.insert(v[i]);
        }
    }
    cout<<s.size()<<'\n';
    vector<int> res[10001];
    for(int i=0; i<n; i++){
        res[v[i].second].push_back(i+1);
    }
    for(int i=0; i<s.size(); i++){
        for(auto j:res[i]) cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
/*
### Program "Ládák balról jobbra" Explanation:

1. **Understanding the Problem**:
   - The problem involves packing a series of boxes together using a robot that can move from left to right.
   - The robot can place one box into another if the latter is smaller in size, and it can only move in one direction.
   - The goal is to minimize the number of packed boxes.

2. **Approach**:
   - Iterate through the boxes from right to left.
   - Maintain a set to keep track of the available boxes and their sizes.
   - Assign each box to the appropriate group based on the available boxes and their sizes.

3. **Algorithm**:
   - Read the number of boxes N and their sizes.
   - Create a vector of pairs to store each box's size and its assigned group number.
   - Create a multiset to keep track of available boxes and their sizes.
   - Iterate through the boxes from right to left:
     - Find the appropriate group for the current box based on the available boxes and their sizes.
     - Update the available boxes and their sizes accordingly.
   - Output the minimum number of boxes required and specify the packing by listing the indices of boxes packed together for each group.

4. **Explanation**:
   - The program iterates through the boxes from right to left.
   - It assigns each box to the appropriate group based on the available boxes and their sizes.
   - The output includes the minimum number of boxes required and specifies the packing by listing the indices of boxes packed together for each group.

5. **Time Complexity**:
   - Iterating through the boxes: O(N)
   - For each box, finding the appropriate group: O(log N) in average case due to set operations.
   - Total: O(N log N)

This approach calculates the minimum number of boxes required to pack the series of boxes together and specifies which boxes are packed together, satisfying the problem requirements.
*/