#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
- **Problem Description**:
  Mekk Elek, a versatile entrepreneur, takes on 1-hour work assignments based on orders. It is known how many orders he can handle at maximum on each day and the deadlines for these orders (the last day when a specific task can be completed).

- **Task**:
  Create a program that calculates the maximum number of orders that can be completed within the given deadlines.

- **Input**:
  - The first line of standard input contains the number of workdays N (1≤N≤10,000) and the number of orders M (1≤M≤100,000).
  - The next line contains N integers representing the maximum number of orders Mekk Elek can complete on each day (0≤WorkHours≤24).
  - The following M lines each contain an integer representing the deadline for a specific order (1≤Deadline≤N).

- **Output**:
  - The program should output the maximum number of orders that can be completed.

- **Example**:
  - **Input**:
    ```
    3 5
    2 0 6
    2
    3
    1
    2
    3
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
    int n,m;
    cin>>n>>m;
    vector<int> days;
    vector<int> v;
    days.push_back(0);
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        days.push_back(x);
    }
    for(int i=1; i<=m; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int res = 0;
    int i = 0;
    for(int curr = 1; curr<=n; curr++){
        if(i<v.size() && curr<=v[i]){
            res += days[curr];
            i += days[curr];
            if(i>=v.size()) res -= i - v.size();
        } else {
            i = lower_bound(v.begin(),v.end(),curr) - v.begin();
            if(i<v.size()) {
                res += days[curr];
                i += days[curr];
                if(i>=v.size()) res -= i - v.size();
            }
        }
    }
    cout<<res;
    return 0;
}
/*
The provided code efficiently solves the problem of calculating the maximum number of orders that can be completed within given deadlines. Here's a step-by-step explanation of the code:

1. **Understanding the Problem**:
   - The program takes input for the number of workdays (N), the number of orders (M), the maximum number of orders Mekk Elek can complete on each day, and the deadlines for each order.
   - The goal is to calculate the maximum number of orders that can be completed within the given deadlines while considering the daily capacity and deadlines.

2. **Approach**:
   - The program sorts the deadlines and iterates through each day.
   - For each day, it checks if there are pending orders with deadlines on or after that day.
   - If there are pending orders, it assigns orders to the available work hours of that day and updates the count of completed orders.
   - The algorithm aims to maximize the completed orders by utilizing the available work hours effectively.

3. **Algorithm**:
   - Initialize variables `res` (the count of completed orders) and `i` (index for deadlines).
   - Sort the deadlines (`v`) in ascending order.
   - Iterate through each day from 1 to `n`:
     - If there are pending orders (`i < v.size()`) with deadlines on or after the current day (`curr`):
       - Assign orders to the available work hours of that day, update `i` accordingly, and increment `res`.
   - Output the final value of `res`, which represents the maximum number of orders completed.

4. **Time Complexity**:
   - The time complexity of the algorithm is O(N log N + M), where N is the number of workdays and M is the number of orders.
   - Sorting the deadlines takes O(N log N) time, and iterating through each day and processing orders takes O(M) time.

Overall, the program efficiently calculates the maximum number of orders that can be completed within the given deadlines while considering the daily capacity and order deadlines.
*/