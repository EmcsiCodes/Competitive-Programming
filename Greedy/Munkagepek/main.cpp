#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
/*
Here's a summary of the problem "Munkagépek" (Work Machines):

- **Problem Description**:
  A company takes on one-day jobs, and each job requires a dedicated work machine to be completed. Each job has a deadline that must be met.

- **Task**:
  Write a program that calculates the minimum number of work machines needed to complete all jobs by their respective deadlines.

- **Input**:
  - The first line of standard input contains the number of jobs N (2 ≤ N ≤ 1,000,000).
  - The second line contains the deadlines for the N jobs (1 ≤ Hi ≤ 100,000).

- **Output**:
  - The program should output the minimum number of work machines required to complete all jobs by their deadlines.

- **Example**:
  - **Input**:
    ```
    10
    2 3 2 3 2 9 4 4 4 4
    ```
  - **Output**:
    ```
    3
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame. In 30% of the tests, N ≤ 100.
*/
int main()
{
    int n;
    vector<int> v;
    cin>>n;
    v.push_back(0);
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    multiset<int> robots;
    robots.insert(0);
    for(int i=1; i<=n; i++){
        auto it = robots.begin();
        if(*it >= v[i]){
            robots.insert(1);
        } else {
            auto toErase = robots.lower_bound(*it);
            robots.erase(toErase);
            robots.insert(*it+1);
        }
    }
    cout<<robots.size();
    return 0;
}
/*
### Program "Munkagépek" Explanation:

1. **Understanding the Problem**:
   - The company has one-day jobs, and each job requires a dedicated work machine to be completed.
   - Each job has a deadline, and the company needs to calculate the minimum number of work machines needed to complete all jobs by their respective deadlines.

2. **Approach**:
   - Sort the deadlines of the jobs in ascending order.
   - Iterate through the sorted deadlines and greedily assign the jobs to the work machines in a way that minimizes the number of work machines needed.

3. **Algorithm**:
   - Read the number of jobs N and their respective deadlines.
   - Sort the deadlines in ascending order.
   - Initialize a set of work machines, initially with one work machine.
   - Iterate through the sorted deadlines:
     - Check if the earliest available work machine can complete the job by its deadline:
       - If yes, assign the job to the earliest available work machine.
       - If not, add a new work machine and assign the job to it.
   - Output the total number of work machines needed.

4. **Explanation**:
   - The program sorts the deadlines and assigns jobs to work machines in a way that minimizes the number of work machines needed to complete all jobs by their respective deadlines.
   - It outputs the minimum number of work machines required.

5. **Time Complexity**:
   - Sorting the deadlines: O(N log N)
   - Assigning jobs to work machines: O(N)
   - Total: O(N log N)

This approach calculates the minimum number of work machines needed to complete all jobs by their respective deadlines, satisfying the problem requirements.
*/