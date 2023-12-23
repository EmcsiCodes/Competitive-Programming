#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
- **Problem Description**:
  Residents of Long Street plan to organize a communal WiFi service. They received a favorable offer for a network device with a radius of H meters. Each network device needs to be installed in one of the houses. Each house has specified the point within the house to install the device, which is considered the reference point and is used to calculate the coverage radius.

- **Task**:
  Create a program that determines how many network devices need to be bought and where they should be installed so that every house is within the coverage radius of the nearest access point.

- **Input**:
  - The first line of standard input contains two integers: the number of houses N (2 ≤ N ≤ 10,000) and the coverage radius of the network devices H (1 ≤ H ≤ 1,000).
  - The second line contains exactly N non-negative integers in increasing order. The i-th number represents the distance in meters of the reference point of the i-th house from the first house (0 ≤ Ri, R1 = 0, RN ≤ 10,000,000).

- **Output**:
  - The program should output the minimum number of required network devices M.
  - The next line should contain M integers, the indices of the houses where access points need to be installed.

- **Example**:
  - **Input**:
    ```
    7 20
    0 10 30 40 60 85 100
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
    int n,h;
    cin>>n>>h;
    vector< pair<int,int> > v;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v.push_back({x,i-1});
    }
    vector<int> res;
    auto prev = v.begin();
    while(prev!=v.end()){
        pair<int,int> p = {prev->first + h,1000000};
        auto curr = upper_bound(v.begin(),v.end(),p);        
        curr--;
        res.push_back(curr->second);
        p = {curr->first + h,1000000};
        prev = upper_bound(v.begin(),v.end(),p);
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i+1<<" ";
    return 0;
}
/*
The provided code solves the problem of determining the minimum number of required network devices and their installation locations such that every house is within the coverage radius of the nearest access point. Below is a step-by-step explanation of the code:

1. **Understanding the Problem**:
   - The program takes input for the number of houses (N) and the coverage radius of network devices (H).
   - The goal is to determine the minimum number of network devices needed and where they should be installed so that every house is within the coverage radius of the nearest access point.

2. **Approach**:
   - The program iterates through the distances of the reference points of each house and determines the locations where network devices should be installed based on the coverage radius.
   - It uses the upper_bound function to find the houses that are within the coverage radius of a particular access point.

3. **Algorithm**:
   - Initialize a vector `v` to store the distances of each house's reference point from the first house and their respective indices.
   - Iterate through the distances of the reference points and determine the network device installation locations:
     - For each house, calculate the distance to the next house that can be covered by a network device with the given coverage radius.
     - Add the indices of the houses where network devices should be installed to the result vector `res`.

4. **Output**:
   - Output the minimum number of network devices needed (`res.size()`) and the indices of the houses where the network devices should be installed.

5. **Time Complexity**:
   - The time complexity of the algorithm is O(N log N), where N is the number of houses.
   - The upper_bound function (`upper_bound`) contributes to the log N factor.

Overall, the program efficiently calculates the minimum number of required network devices and their installation locations to ensure that every house is within the coverage radius of the nearest access point.
*/