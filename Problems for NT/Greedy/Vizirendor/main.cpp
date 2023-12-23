#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
- **Problem Description**:
  There are N settlements along a river, and some of them want to establish a river police station. A police boat can travel A kilometers downstream and B kilometers upstream in one hour.

- **Task**:
  Create a program that determines the minimum number of settlements where river police stations need to be established such that any settlement can be reached within K hours from the police stations.

- **Input**:
  - The first line of standard input contains the number of settlements N (1 ≤ N ≤ 1000), the distance that can be covered in one hour downstream A (1 ≤ A ≤ 100), the distance that can be covered in one hour upstream B (1 ≤ B ≤ 100), and the time duration K (1 ≤ K ≤ 10).
  - The following N-1 lines contain the distances of each settlement from the first settlement, in the downstream direction.

- **Output**:
  - The program should output the number of river police stations to be established M.
  - The next line should contain M numbers, the indices of the settlements where river police stations should be established.

- **Example**:
  - **Input**:
    ```
    7 20 10 1
    10
    20
    30
    60
    90
    100
    ```
  - **Output**:
    ```
    3
    2 5 7
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
int main()
{
    int n,dspeed,uspeed,k;
    cin>>n>>dspeed>>uspeed>>k;
    vector< pair<int,int> > v;
    v.push_back({0,0});
    for(int i=2; i<=n; i++){
        int x;
        cin>>x;
        v.push_back({x,i-1});
    }
    dspeed *= k;
    uspeed *= k;
    auto prev = v.begin();
    vector<int> res;
    while(prev!=v.end()){
        pair<int,int> p = {v[prev->second].first + uspeed, 1000000};
        auto curr = upper_bound(v.begin(),v.end(),p);
        curr--;
        res.push_back(curr->second);
        p = {v[curr->second].first + dspeed,1000000};
        auto next = upper_bound(v.begin(),v.end(),p);
        prev = next;
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i+1<<" ";
    return 0;
}
/*
The provided code solves the problem of determining the minimum number of river police stations that need to be established such that any settlement can be reached within a given time duration. Below is a step-by-step explanation of the code:

1. **Understanding the Problem**:
   - The program takes input for the number of settlements (N), the distance that can be covered downstream in one hour (A), the distance that can be covered upstream in one hour (B), and the time duration (K).
   - The goal is to determine the minimum number of police stations required, considering the given travel speeds and time duration, to ensure that any settlement can be reached within K hours from the police stations.

2. **Approach**:
   - The program calculates the maximum distance that can be covered downstream (`dspeed`) and upstream (`uspeed`) in K hours based on the provided travel speeds.
   - It iterates through the settlements and determines the police station positions based on the distances and the calculated downstream and upstream speeds.

3. **Algorithm**:
   - Initialize a vector `v` to store the distances of each settlement from the first settlement and their respective indices.
   - Calculate the maximum distance that can be covered downstream (`dspeed`) and upstream (`uspeed`) in K hours by multiplying A and B by K.
   - Iterate through the settlements and determine the police station positions:
     - For each settlement, calculate the distance to the next settlement that can be reached upstream (using `uspeed`) and downstream (using `dspeed`) within the given time duration K.
     - Add the indices of the settlements where the police stations should be established to the result vector `res`.

4. **Output**:
   - Output the number of police stations needed (`res.size()`) and the indices of the settlements where the police stations should be established.

5. **Time Complexity**:
   - The time complexity of the algorithm is O(N log N), where N is the number of settlements.
   - The upper bound function (`upper_bound`) and sorting the vector `v` contribute to the log N factor.

Overall, the program efficiently calculates the minimum number of river police stations required to ensure timely reach to any settlement within the given time duration.
*/