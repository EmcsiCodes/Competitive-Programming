#include <iostream>
#include <vector>
using namespace std;
/*
- **Problem Description**:
  Along a railway line, there are N stations, and the distances of each station from the starting station are known. A traveler departs from the starting station. The goal is to determine how many stations the traveler can stop at, given the condition that once the traveler stops at a station, the next stop must be at least K kilometers away.

- **Task**:
  Create a program that calculates the maximum number of stations at which the traveler can stop and provides the indices of these stations. The starting and ending stations are mandatory stops.

- **Input**:
  - The first line of standard input contains the number of stations N (2≤N≤100) and the distance K in kilometers (1≤K≤100).
  - The second line contains the distances of each station from the starting station (0=T(1)<T(2)<…<T(N), T(N)≥K).

- **Output**:
  - The program should output the maximum number of stations the traveler can stop at.
  - The next line should contain M numbers, the indices of the stations where the traveler can stop.

- **Example**:
  - **Input**:
    ```
    5 10
    0 5 13 24 28
    ```
  - **Output**:
    ```
    3
    1 3 5
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
vector<int> v;

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<int> res;
    res.push_back(0);
    int endPoint = v[n-1];
    for(int i=1; i<v.size(); i++){
        if(v[res.back()]+k<=v[i] && v[i]+k<=endPoint) res.push_back(i);
    }
    res.push_back(n-1);
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i+1<<" ";
    return 0;

}
/*
The provided code efficiently solves the problem of determining the maximum number of stations a traveler can stop at, given the condition of a minimum distance between stops. Here's a step-by-step explanation of the code:

1. **Understanding the Problem**:
   - The program takes input for the number of stations (N), the minimum distance between stops (K), and the distances of each station from the starting station.
   - The goal is to calculate the maximum number of stations the traveler can stop at, considering the minimum distance constraint.

2. **Approach**:
   - The program iterates through the distances of each station, starting from the second station.
   - For each station, it checks if the distance from the previous station is greater than or equal to K and the distance from the current station to the last station is greater than or equal to K.
   - If both conditions are met, it adds the station index to the result list, representing a valid stop.

3. **Algorithm**:
   - Initialize a vector `res` to store the indices of stations where the traveler can stop.
   - Iterate through each station's distance starting from the second station:
     - Check if the distance from the previous station (`v[res.back()]`) plus K is less than or equal to the current station's distance (`v[i]`).
     - Also, check if the distance from the current station (`v[i]`) plus K is less than or equal to the distance of the last station (`v[n-1]`).
     - If both conditions are met, add the current station's index (`i`) to `res`.
   - Output the size of `res` (representing the number of valid stops) and the indices of stations where the traveler can stop.

4. **Time Complexity**:
   - The time complexity of the algorithm is O(N), where N is the number of stations.
   - The iteration through each station to determine valid stops takes O(N) time.

Overall, the program efficiently calculates the maximum number of stations the traveler can stop at, considering the minimum distance between stops.
*/