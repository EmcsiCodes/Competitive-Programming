#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
- **Problem Description**:
  An assembly plant receives N orders for manufacturing components. Each order specifies the time required to manufacture the component. The plant has at least N machines, and each component can be manufactured on a separate machine. Prior to manufacturing, each component needs preparation, which can be done by only one machine. The time required for preparation is known for each component. After preparation, manufacturing of a component starts immediately.

  Create a program that determines the optimal order of preparing the components to minimize the overall time required for manufacturing all components.

- **Input**:
  - The first line of standard input contains the number of components N (1 ≤ N ≤ 30,000).
  - The second line contains N integers, separated by spaces, representing the time required for preparing each component.
  - The third line contains N integers, separated by spaces, representing the time required to manufacture each component.

- **Output**:
  - The first line of the output should contain the minimum total time required to manufacture all components.
  - The second line should contain the order of preparing the components, separated by spaces, to minimize the total manufacturing time.

- **Example**:
  - **Input**:
    ```
    3
    1 3 3
    4 1 5
    ```
  - **Output**:
    ```
    8
    3 1 2
    ```

- **Constraints**:
  - The values ensure the computation can be performed within a reasonable time frame.
*/
int main()
{
    int n;
    cin>>n;
    vector<int> time;
    vector< pair<int,int> > v;
    time.push_back(0);
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        time.push_back(x);
    }
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v.push_back({x,i});
    }
    sort(v.rbegin(),v.rend());
    int maxTime = 0, prev = 0;
    vector<int> res;
    for(int i=0; i<v.size(); i++){
        maxTime = max(maxTime,prev + v[i].first + time[v[i].second]);
        prev += time[v[i].second];
        res.push_back(v[i].second);
    }
    cout<<maxTime<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
### Optimal Order of Preparing Components

#### Approach:
- The problem involves determining the optimal order of preparing components to minimize the overall manufacturing time.
- The program reads the input, sorts the components based on manufacturing time, and calculates the minimum total time required for manufacturing.

#### Pseudocode:
1. Read input: number of components `n`, preparation times, and manufacturing times for each component.
2. Create a vector of pairs to store manufacturing times and corresponding component numbers.
3. Sort the vector in non-increasing order of manufacturing times.
4. Calculate the minimum total time required for manufacturing by iterating through the sorted vector and adding preparation time for each component.
5. Output the minimum total time and the order of preparing components.

#### Time Complexity:
- The time complexity is O(n log n) due to the sorting of components based on manufacturing times.

### Code Explanation:

1. **Input Reading**:
   - Read the number of components `n`, preparation times, and manufacturing times for each component.

2. **Creating Data Structures**:
   - Create a vector `v` of pairs to store manufacturing times and component numbers.
   - Create a vector `time` to store preparation times, with an additional element at index 0.

3. **Sorting Components**:
   - Sort the vector `v` in non-increasing order of manufacturing times.

4. **Calculating Minimum Total Time**:
   - Iterate through the sorted vector and calculate the minimum total time by adding preparation time and manufacturing time for each component.
   - Keep track of the previous preparation time to calculate the total time for each component.

5. **Output**:
   - Output the minimum total time and the order of preparing components.

---

The code is well-structured and implements the required logic to calculate the minimum total time required for manufacturing components in an optimal order. It follows a clear approach and effectively handles the input and output as per the problem's requirements.
*/