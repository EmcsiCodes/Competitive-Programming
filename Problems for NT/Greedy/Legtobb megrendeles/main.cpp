#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Here's a summary of the problem "Legtöbb megrendelés" (Most Orders):

- **Problem Description**:
  Mekk Elek is a popular entrepreneur who receives many orders. He knows the start and finish times for each ordered task. Mekk Elek wants to maximize the number of tasks he can accept for the next year, but he can only work on one task at a time. Your task is to create a program that determines the largest possible subset of tasks that can be completed.

- **Input**:
  - The first line of the standard input contains the number of orders, N (1 ≤ N ≤ 10,000).
  - The next N lines each contain two positive integers, where the first integer represents the starting time, K (1 ≤ K), and the second integer represents the finishing time, B (K ≤ B ≤ 365), for each ordered task.

- **Output**:
  - The program should output two lines:
    - The first line should contain the number of selected tasks, M.
    - The second line should contain M space-separated integers representing the indices (1-based) of the selected tasks in any order. If there are multiple valid solutions, you can output any of them.

- **Example**:
  - **Input**:
    ```
    6
    2 3
    2 4
    5 7
    3 4
    2 2
    1 2
    ```
  - **Output**:
    ```
    3
    6 3 4
    ```

- **Constraints**:
  - Time Limit: 0.1 seconds
  - Memory Limit: 32 MB
*/
struct intervals{
    int i;
    int start;
    int end;
};

struct Compare{
    bool operator()(intervals const& p1,intervals const& p2){
        return p1.end < p2.end;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<intervals> v;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({i,x,y});
    }
    sort(v.begin(),v.end(), Compare());
    auto it = v.begin(), last = v.begin();
    vector<int> res;
    while(it!=v.end()){
        res.push_back(it->i);
        while(it!=v.end() && it->start <= last->end) it++;
        last = it;
     }
    cout<<res.size()<<endl;
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
Great! Here's an explanation for the program "Legtöbb megrendelés" (Most Orders):

### Program "Legtöbb megrendelés" Explanation:

1. **Understanding the Problem**:
   - Mekk Elek wants to maximize the number of tasks he can complete within a given time frame.
   - Each task has a start and finish time.
   - The goal is to find the largest possible subset of non-overlapping tasks.

2. **Approach**:
   - Sort the tasks based on their finish times in ascending order.
   - Iterate through the sorted tasks and greedily select tasks that do not overlap.
   - Output the indices of the selected tasks.

3. **Algorithm**:
   - Read the number of orders N and their start and finish times.
   - Create a structure to store task information: index, start time, and finish time.
   - Sort the tasks based on their finish times.
   - Initialize two iterators, one to keep track of the last selected task and one for the current task being considered.
   - Iterate through the sorted tasks:
     - Select the task if its start time is after the finish time of the last selected task.
     - Update the last selected task and move to the next task.
   - Output the number of selected tasks and their indices.

4. **Explanation**:
   - The program sorts the tasks based on their finish times and iterates through them, selecting tasks that do not overlap with the previously selected tasks.
   - It outputs the number of selected tasks and their indices.

5. **Time Complexity**:
   - Sorting the tasks based on finish times: O(N log N)
   - Iterating through the tasks and selecting non-overlapping tasks: O(N)
   - Total: O(N log N)

This approach calculates the largest possible subset of non-overlapping tasks, satisfying the problem requirements.
*/