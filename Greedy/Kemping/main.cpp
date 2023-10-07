#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Here's a summary of the problem "Kemping" (Camping):

- **Problem Description**:
  The "Napsugár Kemping" operates K cabins throughout the year. Each guest can reserve a cabin for exactly M days. The camping has gathered all the requests for the whole year in advance. Each guest provided the day number from which they want to book a cabin for M days.

- **Task**:
  Create a program that calculates the maximum number of guests the camping can accommodate.

- **Input**:
  - The first line of standard input contains the number of cabins K (1 ≤ K ≤ 100).
  - The second line contains the number of days M (1 ≤ M ≤ 14).
  - The third line contains the number of requests N (1 ≤ N ≤ 1000).
  - The following N lines each contain a request, which is the day number from which the guest wants to book a cabin for M days.

- **Output**:
  - The program should output the maximum number of guests the camping can accommodate.

- **Example**:
  - **Input**:
    ```
    2 5
    7
    8
    1
    10
    2
    11
    1
    3
    4
    18
    ```
  - **Output**:
    ```
    4
    ```

- **Constraints**:
  - Time Limit: 0.1 seconds
  - Memory Limit: 32 MB
*/
int main()
{
    int k,m,n;
    cin>>k>>m>>n;
    vector<int> v(366 + m,0), getsFree(366 + m,0);
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v[x]++;
    }
    int res = 0;
    for(int i=1; i<=365 + m; i++){
        k += getsFree[i];
        if(k>0 && v[i]>0){
            int p;
            if(k>v[i]) {
                p = v[i];
                k -= p;
            }
            else {
                p = k;
                k = 0;
            }
            res += p;
            getsFree[i+m] += p;
        }
    }
    cout<<res;
    return 0;
}
/*
### Program "Kemping" Explanation:

1. **Understanding the Problem**:
   - The goal is to calculate the maximum number of guests a camping can accommodate given specific rules and guest requests.
   - The camping operates K cabins, and each guest can reserve a cabin for exactly M days.
   - Guests have provided their reservation requests, specifying the day from which they want to book a cabin for M days.

2. **Approach**:
   - We track the number of requests for each day and simulate the reservation process.
   - For each day:
     - Check if cabins are available, i.e., if K > 0.
     - If available cabins and there's a reservation request for that day:
       - Reserve cabins for the request.
       - Update the number of available cabins and the reservation count.
   - Calculate and output the maximum number of guests that the camping can accommodate.

3. **Algorithm**:
   - Read the number of cabins K, number of days M, and number of requests N.
   - Create two vectors to track reservation requests and available cabins for each day.
   - Read and process each reservation request:
     - Increment the count for the request day.
   - Iterate through each day:
     - Update the number of available cabins based on previous reservations and releases.
     - For each reservation request on the current day:
       - If there are available cabins, assign a cabin and decrement the available cabins count.
       - Update the reservation count and mark the day when the cabin will be free again.
     - Track the maximum number of guests that can be accommodated.
   - Output the maximum number of guests.

4. **Explanation**:
   - The program reads input values and processes reservation requests day by day.
   - It keeps track of available cabins, assigns cabins to guests if available, and marks the day when the cabin will be free for use again.
   - Finally, it calculates the maximum number of guests that the camping can accommodate.

5. **Time Complexity**:
   - Processing reservation requests and updating cabin availability: O(N + M), where N is the number of requests and M is the number of days to track.

This approach efficiently calculates the maximum number of guests the camping can accommodate while considering the reservation rules.
*/