#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
Here's a summary of the problem "Legtöbb megrendelés határidőre" (Most Orders on Time):

- **Problem Description**:
  Mekk Elek is a popular entrepreneur who receives many orders. Each of his tasks takes exactly one day to complete. All orders have deadlines, and whatever he accepts, he completes on time. Mekk Elek wants to maximize the number of orders he can accept for the next year, but he can only work on one task at a time. Your task is to create a program to select and schedule the largest possible subset of next year's orders so that Mekk Elek can complete as many tasks as possible on time.

- **Input**:
  - The first line of the standard input contains the number of workdays in the year, M (1 ≤ M ≤ 10,000), and the number of orders, N (1 ≤ N ≤ 100,000).
  - The next N lines each contain a positive integer, representing the deadline for each order, H (1 ≤ H ≤ M).

- **Output**:
  - The program should output two lines:
    - The first line should contain the number of selected tasks, M.
    - The second line should contain M pairs of integers separated by a space. Each pair consists of the order number (1-based) and the day (1 to M) on which the corresponding task should be completed. If there are multiple valid solutions, you can output any of them.

- **Example**:
  - **Input**:
    ```
    10 6
    3
    2
    7
    4
    2
    1
    ```
  - **Output**:
    ```
    5
    5 1
    1 3
    2 2
    4 4
    3 7
    ```

- **Constraints**:
  - Time Limit: 0.1 seconds
  - Memory Limit: 32 MB
*/
int main()
{
    int n,m;
    cin>>n>>m;
    vector< pair<int,int> > v;
    for(int i=1; i<=m; i++){
        int x;
        cin>>x;
        v.push_back({x,i});
    }
    sort(v.begin(),v.end());
    int currday = 1;
    vector< pair<int,int> > res;
    for(int i=0; i<m; i++){
        if(currday<=v[i].first){
            res.push_back({v[i].second,currday});
            currday++;
        }
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i.first<<" "<<i.second<<'\n';
    return 0;
}
/*
### Program "Legtöbb megrendelés határidőre" Explanation:

1. **Understanding the Problem**:
   - Mekk Elek wants to maximize the number of orders he can complete within a year, considering the deadlines for each order.
   - He can complete one task (order) in a day, and he aims to complete as many tasks as possible on time.

2. **Approach**:
   - Sort the orders based on their deadlines in ascending order.
   - Assign tasks to days, starting from the earliest deadline, ensuring that each task is completed on or before its deadline.
   - Output the schedule of tasks.

3. **Algorithm**:
   - Read the number of workdays M and the number of orders N.
   - Create a structure to store order information: deadline and order number.
   - Sort the orders based on their deadlines.
   - Initialize a variable `currday` to keep track of the current day.
   - Iterate through the sorted orders:
     - If the current day is less than or equal to the order's deadline:
       - Assign the task to the current day and increment `currday`.
   - Output the number of scheduled tasks and their order numbers with the assigned days.

4. **Explanation**:
   - The program sorts the orders based on their deadlines and assigns tasks to days, ensuring that each task is completed on or before its deadline.
   - It outputs the number of scheduled tasks and their order numbers with the assigned days.

5. **Time Complexity**:
   - Sorting the orders based on deadlines: O(N log N)
   - Assigning tasks to days: O(N)
   - Total: O(N log N)

This approach calculates the largest possible subset of tasks that can be completed on time, satisfying the problem requirements.
*/