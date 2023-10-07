#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
/*
Certainly! Here's a summary of the problem "Investment with Subcontractors":

- **Problem Description**:
  A large-scale investment project has plans for N different tasks to be performed. Each task can be completed in exactly one day, but there are specific deadlines for each task. The investor contracts subcontractors to perform the tasks. Each subcontractor can handle any task but only one task per day. The goal is to determine the minimum number of subcontractors needed to ensure all tasks are completed by their respective deadlines.

- **Input**:
  - The first line of standard input contains the number of tasks, N (2 ≤ N ≤ 10,000).
  - The following N lines each contain a deadline for a task (1 ≤ deadline ≤ 300).

- **Output**:
  - The first line should display the minimum number of subcontractors required.
  - The next N lines should list a possible assignment of tasks to subcontractors. The first number on each line represents the task number, the second number represents the subcontractor number, and the third number represents the day when the task will be completed by the subcontractor.

- **Example**:
  - **Input**:
    ```
    7
    1
    2
    1
    3
    2
    2
    3
    ```
  - **Output**:
    ```
    3
    1 1 1
    2 1 2
    3 2 1
    4 3 2
    5 2 2
    6 3 1
    7 1 3
    ```

- **Constraints**:
  - Time Limit: 0.1 seconds
  - Memory Limit: 32 MB
*/
struct ans{
    int i;
    int peopleInd;
    int day;
};

int main()
{
    int n;
    cin>>n;
    vector< pair<int,int> > v;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        v.push_back({x,i});
    }
    sort(v.begin(),v.end());
    multiset< pair<int,int> > people;
    vector<ans> res;
    people.insert({1,1});
    for(int i=0; i<v.size(); i++){
        auto curr = people.begin();
        if(v[i].first >= curr->first){
            res.push_back({v[i].second,curr->second,curr->first});
            people.erase(curr);
            people.insert({curr->first+1,curr->second});
        } else {
            int peopleNum = people.size() + 1;
            res.push_back({v[i].second,peopleNum,1});
            people.insert({2,people.size()+1});
        }
    } 
    cout<<people.size()<<'\n';
    for(auto i:res) cout<<i.i<<" "<<i.peopleInd<<" "<<i.day<<'\n';
    return 0;
}
/*
### Program 4: "Subcontractors in the Investment"

1. **Understanding the Problem**:
   - The goal is to determine the minimum number of subcontractors needed to complete N different jobs by a given deadline.

2. **Approach**:
   - Sort the jobs based on their deadlines.
   - Iterate through the jobs:
     - Assign a job to a subcontractor who is available on the earliest day possible.
     - If no subcontractor is available, assign a new subcontractor.

3. **Algorithm**:
   - Read input values for the number of jobs, N.
   - Create a vector to store the jobs (deadline, job number).
   - Sort the vector based on deadlines in ascending order.
   - Initialize a multiset to store the subcontractors (availability, subcontractor number).
   - Initialize a vector of ans structure to store the results (job number, subcontractor number, day).
   - Iterate through the sorted jobs:
     - Check if there is a subcontractor available on the earliest day.
       - If yes, assign the job to that subcontractor and update their availability.
       - If no, assign a new subcontractor and assign the job to them.
     - Store the job assignment in the results.
   - Print the minimum number of subcontractors needed.
   - Print the job assignments.

4. **Explanation**:
   - We start by sorting the jobs based on their deadlines. This allows us to process them in order of their deadlines.
   - We iterate through the jobs and assign each job to the subcontractor who is available on the earliest day.
   - If no subcontractor is available, we assign the job to a new subcontractor and update their availability.
   - We keep track of the job assignments and subcontractor availability to generate the output.

5. **Time Complexity**:
   - Sorting the jobs based on deadlines: O(N log N)
   - Iterating through the jobs: O(N)
   - Total: O(N log N)

This approach ensures that we assign jobs to subcontractors in a way that minimizes the number of subcontractors needed to meet the deadlines.
*/