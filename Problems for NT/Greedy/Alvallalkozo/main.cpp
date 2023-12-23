#include <iostream>
#include <vector>

using namespace std;
/*
- **Problem Description**:
  A large-scale investment project requires the completion of N different tasks. Each task can be completed in exactly one day, but each task has a prescribed deadline by which it must be completed. An subcontractor has offered to complete any of the tasks, but they can only complete one task in a day.

  Create a program that determines the maximum number of tasks that can be assigned to the subcontractor.

- **Input**:
  - The first line of standard input contains the number of tasks to be completed, N (2 ≤ N ≤ 10,000).
  - The following N lines each contain the deadline for a task (1 ≤ Hi ≤ 300), given in increasing order.

- **Output**:
  - The program should output on the first line the maximum number of tasks, K, that can be assigned to the subcontractor.
  - The next line should contain the K task numbers assigned to the subcontractor, in the order they are assigned. If multiple solutions exist, any valid solution is acceptable.

- **Example**:
  - **Input**:
    ```
    7
    1
    1
    2
    2
    2
    4#include <iostream>
#include <vector>

using namespace std;
/*
- **Problem Description**:
  A large-scale investment project requires the completion of N different tasks. Each task can be completed in exactly one day, but each task has a prescribed deadline by which it must be completed. An subcontractor has offered to complete any of the tasks, but they can only complete one task in a day.

  Create a program that determines the maximum number of tasks that can be assigned to the subcontractor.

- **Input**:
  - The first line of standard input contains the number of tasks to be completed, N (2 ≤ N ≤ 10,000).
  - The following N lines each contain the deadline for a task (1 ≤ Hi ≤ 300), given in increasing order.

- **Output**:
  - The program should output on the first line the maximum number of tasks, K, that can be assigned to the subcontractor.
  - The next line should contain the K task numbers assigned to the subcontractor, in the order they are assigned. If multiple solutions exist, any valid solution is acceptable.

- **Example**:
  - **Input**:
    ```
    7
    1
    1
    2
    2
    2
    4
    4
    ```
  - **Output**:
    ```
    4
    1 3 6 7
    ```

- **Constraints**:
  - The constraints ensure the computation can be performed within a reasonable time frame.
  - In 60% of the tests, N ≤ 100.
*/

int main()
{
    int n, currday = 1;
    cin>>n;
    vector<int> res;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;       
        if(currday<=x){
            res.push_back(i);
            currday++;
        }
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
Certainly! Let's dive deeper into the approach and logic behind the program to solve the task assignment problem.

1. **Understanding the Problem**:
   - The goal is to maximize the number of tasks that can be assigned to a subcontractor, given the task deadlines and the constraint that only one task can be completed in a day.

2. **Approach**:
   - We are given tasks in increasing order of deadlines. To maximize the number of tasks that can be assigned, we should prioritize completing tasks with earlier deadlines.
   - We iterate through each task and check if the current day is less than or equal to the task's deadline. If it is, we can assign the task to the subcontractor, and the subcontractor can complete it on that day.
   - If the current day is greater than the task's deadline, we move on to the next task, as it's not possible to complete the task by its deadline.
   - By iterating through the tasks in order and making these decisions, we maximize the number of tasks that can be completed.

3. **Algorithm**:
   - Initialize `currday` to 1, representing the current day.
   - Iterate through each task:
     - Read the deadline of the current task.
     - If the current day is less than or equal to the task's deadline, assign the task to the subcontractor, and increment the current day.
     - Continue this process for all tasks.

4. **Output**:
   - Output the maximum number of tasks that can be assigned to the subcontractor.
   - Output the task numbers assigned to the subcontractor in the order they are assigned.

5. **Example**:
   - For the given example input:
     ```
     7
     1
     1
     2
     2
     2
     4
     4
     ```
     The algorithm will:
     - Assign tasks with deadlines 1, 1, 2, and 2 to the subcontractor on days 1, 2, 3, and 4 respectively.
     - The maximum number of tasks assigned to the subcontractor is 4.
     - The task numbers assigned are 1, 2, 3, and 4.

   The output will be:
   ```
   4
   1 2 3 4
   ```

This approach ensures that the tasks are completed in the optimal order,
maximizing the number of tasks that can be assigned to the subcontractor while respecting the deadlines.
*/