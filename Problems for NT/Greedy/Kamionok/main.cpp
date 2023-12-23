#include <iostream>
#include <vector>
#include <set>
using namespace std;
/*
Here's a summary of the problem "Kamionok" (Trucks):

- **Problem Description**:
  A transportation company uses trucks to deliver goods from Kukutyin to Bergengócia. The transit time for the round trip is S days - a truck that departs on the first day arrives in Bergengócia on the Sth day, departs back a day later, and arrives in Kukutyin on the 2*S day. Therefore, the next shipment can start on the 2*S+1 day. Transport demands have arrived, and each demand specifies the latest arrival date in Bergengócia.

- **Task**:
  Create a program that determines the minimum number of trucks needed to fulfill all demands and when the last truck can earliest arrive back in Kukutyin.

- **Input**:
  - The first line of standard input contains the number of demands N (1 ≤ N ≤ 100,000) and the transit time S (1 ≤ S ≤ 1,000).
  - The following N lines each contain a delivery deadline Hi (1 ≤ Hi ≤ 50,000) in increasing order.

- **Output**:
  - The program should output the minimum number of trucks needed in the first line.
  - The second line should contain the day number when the last truck can earliest arrive back in Kukutyin.

- **Example**:
  - **Input**:
    ```
    7 5
    5
    7
    15
    15
    15
    18
    80
    ```
  - **Output**:
    ```
    3
    30
    ```

- **Constraints**:
  - Time Limit: 0.1 seconds
  - Memory Limit: 32 MB
*/
int main()
{
    int n,s;
    cin>>n>>s;
    vector<int> v;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    multiset<int> trucks;
    trucks.insert(2*s);
    for(int i=1; i<v.size(); i++){
        auto curr = trucks.begin();
        if(*curr + s > v[i]){
            trucks.insert(2*s);
        } else {
            trucks.erase(curr);
            trucks.insert(*curr + 2*s);
        }
    }
    cout<<trucks.size()<<'\n';
    cout<<*trucks.rbegin();
    return 0;
}
/*
### Program: "Trucks"

1. **Understanding the Problem**:
   - A transportation company delivers goods from Kukutyin to Bergengócia using trucks.
   - The round trip takes S days: a truck departs on day 1, arrives in Bergengócia on day S, departs back on day S+1, and arrives in Kukutyin on day 2*S.
   - Transport demands have specified the latest arrival date in Bergengócia.

2. **Approach**:
   - We need to find the minimum number of trucks needed to fulfill all demands and determine when the last truck can earliest arrive back in Kukutyin.
   - We can use a greedy approach to allocate demands to trucks efficiently.

3. **Algorithm**:
   - Read input values for the number of demands N and transit time S.
   - Read the delivery deadlines for each demand.
   - Initialize a multiset to keep track of when the trucks will be available after completing a round trip.
   - For each demand:
     - If a truck can reach Bergengócia before or on the delivery deadline, assign the demand to the earliest available truck and update its availability.
     - If not, assign the demand to a new truck and update its availability.
   - Output the minimum number of trucks and the day when the last truck can earliest arrive back in Kukutyin.

4. **Explanation**:
   - We maintain a set of trucks where each truck's availability is tracked.
   - For each demand, we assign it to a truck if possible and update the truck's availability.
   - If a demand cannot be met by any existing truck, we introduce a new truck.

5. **Time Complexity**:
   - Reading input and populating demands: O(N)
   - Assigning demands and updating truck availability: O(N log N) due to the use of a multiset
   - Total: O(N log N)

This approach efficiently determines the minimum number of trucks needed to fulfill all demands and the earliest day the last truck can arrive back in Kukutyin.
*/