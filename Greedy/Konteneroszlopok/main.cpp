#include <iostream>
#include <vector>
#include <set>
using namespace std;
/*
Here's a summary of the problem "Konténeroszlopok" (Container Columns):

- **Problem Description**:
  A shipping company stores and forwards containers in its distribution warehouse. Each container is labeled with its destination, identified by a number. The delivery should be done in order of these destination numbers. Due to space constraints, containers must be stacked in columns. However, a container with a destination number u cannot have a container with a destination number v greater than u on top of it, to avoid repacking during delivery.

- **Task**:
  Create a program that calculates the minimum number of columns needed to stack the containers and provides a valid stacking.

- **Input**:
  - The first line of standard input contains the number of containers N (1 ≤ N ≤ 2,000,000) and the possible destination numbers K (1 ≤ K ≤ 10,000).
  - The second line contains exactly N integers (separated by a space), representing the destination number of each container (1 ≤ Hi ≤ K).

- **Output**:
  - The program should output the smallest number of columns M such that the containers can be stacked into M columns.
  - It should then output N integers (separated by a space), representing the column number for each container when it's placed upon arrival.

- **Example**:
  - **Input**:
    ```
    10 9
    6 3 4 3 8 1 2 7 3 5
    ```
  - **Output**:
    ```
    4
    1 1 2 1 3 1 2 3 3 4
    ```

- **Constraints**:
  - Time Limit: 0.1 seconds
  - Memory Limit: 32 MB
*/
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    multiset< pair<int,int> > s;
    for(int i=v.size()-1; i>=0; i--){
        auto it = s.lower_bound({v[i],0});
        if(it->first == v[i]) {
            s.erase(it);
            s.insert({v[i],it->second});
            v[i] = it->second;
            continue;
        }
        if(it == s.begin()){
            s.insert({v[i],s.size()+1});
            v[i] = s.size();
        } else {
            it--;
            s.erase(it);
            s.insert({v[i],it->second});
            v[i] = it->second;
        }
    }
    cout<<s.size()<<'\n';
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    return 0;
}
/*
### Program "Konténeroszlopok" Explanation:

1. **Understanding the Problem**:
   - The problem involves stacking containers in columns based on their destination numbers.
   - A container with a destination number u cannot have a container with a destination number v greater than u on top of it.

2. **Approach**:
   - Iterate through the containers in reverse order.
   - Maintain a set to keep track of the available columns and their topmost destination numbers.
   - Assign each container to the appropriate column based on the available columns and their topmost destination numbers.

3. **Algorithm**:
   - Read the number of containers N and the possible destination numbers K.
   - Create a vector to store the destination number of each container.
   - Create a multiset to keep track of available columns and their topmost destination numbers.
   - Iterate through the containers in reverse order:
     - Find the appropriate column for the current container based on the available columns and their topmost destination numbers.
     - Update the available columns and their topmost destination numbers accordingly.
   - Output the smallest number of columns M and the column number for each container.

4. **Explanation**:
   - The program iterates through the containers in reverse order.
   - It assigns each container to the appropriate column based on the available columns and their topmost destination numbers.
   - The output includes the smallest number of columns needed and the column number for each container.

5. **Time Complexity**:
   - Iterating through the containers: O(N)
   - For each container, finding the appropriate column: O(log N) in average case due to set operations.
   - Total: O(N log N)

This approach calculates the minimum number of columns needed to stack the containers and provides a valid stacking, satisfying the problem requirements.
*/