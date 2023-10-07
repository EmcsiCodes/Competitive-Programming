#include <iostream>
#include <vector>
using namespace std;
/*
- **Problem Description**:
  A tourist agency employs N tour guides and can arrange trips of M days within the K-day tourist season (starting from day K-M+1). Each tour group is accompanied by a tour guide, who is booked for the first and last days of the M-day trip. Requests are made by C groups, indicating their desired starting day during the season.

- **Task**:
  Develop a program to determine the maximum number of requests the agency can fulfill.

- **Input**:
  - The first line of standard input contains the number of tour guides N (1≤N≤10), the season's duration K (1≤K≤20,000), the trip duration M (1≤M≤10), and the number of requests C (1≤C≤10,000).
  - The next line contains C integers representing the desired starting days for the groups in increasing order.

- **Output**:
  - The program should output the maximum number of requests the agency can fulfill.

- **Example**:
  - **Input**:
    ```
    2 10 4 6
    1 2 2 5 6 7
    ```
  - **Output**:
    ```
    4
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
int main()
{
    int n,k,m,c;
    cin>>n>>k>>m>>c;
    vector<int> isFree(30000,0), rendeles(30000,0);
    for(int i=1; i<=c; i++){
        int x;
        cin>>x;
        rendeles[x] += 1;
    }
    int res = 0;
    for(int i=1; i<=k; i++){
        n += isFree[i];
        isFree[i] = 0;
        if(n>0 && rendeles[i]>0){
            n--;
            isFree[i+m] += 1;
            res++;
            rendeles[i]--;
            i--;
        }
    }
    cout<<res;
    return 0;
}
/*
The provided code efficiently solves the problem of maximizing the number of requests the tourist agency can fulfill within a given tourist season. Here's a step-by-step explanation of the code:

1. **Understanding the Problem**:
   - The program takes input for the number of tour guides (N), the duration of the tourist season (K), the trip duration (M), and the number of requests (C).
   - Each tour group is accompanied by a tour guide, and they have specific starting days within the tourist season.
   - The goal is to maximize the number of requests the agency can fulfill, considering the constraints.

2. **Approach**:
   - The program uses a greedy approach to maximize the number of requests.
   - It maintains two vectors, `isFree` and `rendeles`, to keep track of tour guides' availability and the number of requests for each day.
   - It iterates through each day of the tourist season (up to day `K`) and processes requests.
   - For each day, it checks the availability of tour guides (`n`) and the number of pending requests for that day.
   - If there are available tour guides and pending requests, it assigns a tour guide, marks them as unavailable for the trip duration (`M` days), and increments the count of fulfilled requests.
   - It repeats this process for each day in the tourist season.

3. **Algorithm**:
   - Initialize variables `res` (the count of fulfilled requests) and `n` (the available tour guides).
   - Iterate through each day from 1 to `K`:
     - Update the available tour guides by adding the number of guides who have completed their assignments on day `i`.
     - If there are available tour guides (`n > 0`) and pending requests for the current day (`rendeles[i] > 0`):
       - Assign a tour guide to a request, mark the guide as unavailable for `M` days, and increment `res`.
       - Update the number of available guides (`n--`) and reduce the count of pending requests for that day.
   - Output the final value of `res`, which represents the maximum number of requests fulfilled.

4. **Time Complexity**:
   - The time complexity of the algorithm is O(K), where `K` is the duration of the tourist season.
   - The algorithm iterates through each day in the tourist season once.

Overall, the program efficiently calculates the maximum number of requests the tourist agency can fulfill within the given tourist season while considering the availability of tour guides and request constraints.
*/