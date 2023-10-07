#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Here's a summary of the problem "Munkák" (Jobs):

- **Problem Description**:
  An entrepreneur has N orders to fulfill, each with a specified duration and deadline. They can work on one order at a time. The goal is to determine the minimum possible time within which the entrepreneur can complete all the jobs with a delay of at most this amount.

- **Task**:
  Create a program that calculates the minimum possible time such that the entrepreneur can complete all jobs with no more than this delay.

- **Input**:
  - The first line of standard input contains the number of orders N (2 ≤ N ≤ 10,000).
  - The next N lines each contain two integers: the time needed to complete an order Ti (1 ≤ Ti ≤ 100) and the deadline for that order Hi (1 ≤ Hi ≤ 100,000).

- **Output**:
  - The program should output a single integer, representing the minimum possible time for the entrepreneur to complete all jobs with a delay of at most this amount.

- **Example**:
  - **Input**:
    ```
    3
    3 8
    7 7
    1 10
    ```
  - **Output**:
    ```
    2
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
struct in{
    int start;
    int end;
};

struct Compare{
    bool operator()(in const& p1,in const& p2){
        return p1.end < p2.end;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<in> v;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),Compare());
    int time = 0;
    int res = 0;
    for(int i=0; i<v.size(); i++){
        time += v[i].start;
        if(time > v[i].end){
            res = max(res, time - v[i].end);
        }
    }
    cout<<res;
    return 0;
}
/*
### Program "Munkák" Explanation:

1. **Understanding the Problem**:
   - The entrepreneur has N orders, each with a specified duration and deadline.
   - They can work on one order at a time, and the goal is to determine the minimum possible time within which the entrepreneur can complete all the jobs with a delay of at most this amount.

2. **Approach**:
   - Sort the orders based on their deadlines.
   - Iterate through the sorted orders and calculate the delay for each order based on the time taken to complete the previous orders and the current order's deadline.
   - Keep track of the maximum delay encountered.

3. **Algorithm**:
   - Read the number of orders N and their durations and deadlines.
   - Create a structure to store order information: start time, end time (calculated as start time + duration), and deadline.
   - Sort the orders based on their deadlines.
   - Initialize variables to keep track of time and the maximum delay.
   - Iterate through the orders:
     - Update the time as the end time of the previous order or the current order's start time, whichever is greater.
     - Calculate the delay for the current order as the difference between the current time and the order's deadline.
     - Update the maximum delay if the current delay is greater.
   - Output the maximum delay.

4. **Explanation**:
   - The program sorts the orders based on their deadlines and calculates the delay for each order based on the time taken to complete the previous orders and the current order's deadline.
   - It finds the maximum delay encountered, which represents the minimum possible time to complete all jobs with no more than this delay.

5. **Time Complexity**:
   - Sorting the orders: O(N log N)
   - Calculating the delay and finding the maximum delay: O(N)
   - Total: O(N log N)

This approach calculates the minimum possible time for the entrepreneur to complete all jobs with a delay of at most this amount, satisfying the problem requirements.
*/