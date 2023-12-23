#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
/*
Here's a summary of the problem "Legnagyobb hasznú munkák" (Maximizing Profitable Jobs):

- **Problem Description**:
  Mohó Márton is an entrepreneur who is considering various jobs from a contest. He knows the deadline and profit of each job. He can complete one job in one day, and each day, he can only choose one job to complete. Your task is to create a program that calculates the maximum possible total profit and determines which jobs to complete in order to maximize that profit.

- **Input**:
  - The first line of the standard input contains the number of jobs, N (0 < N ≤ 10,000).
  - The next N lines each contain two integers, where the first integer represents the deadline of the job (0 < H ≤ 10,000), and the second integer represents the profit achievable by completing that job (0 < P ≤ 1000). If a job has a deadline of K, it means that if the job is accepted, it must be completed by the K-th day (on the K-th day is acceptable).

- **Output**:
  - The program should output two lines:
    - The first line should contain the maximum total profit achievable.
    - The second line should contain the indices (1-based) of the jobs to complete in the order they should be completed to maximize the total profit.

- **Example**:
  - **Input**:
    ```
    6
    3 60
    4 40
    1 10
    3 30
    7 70
    4 20
    ```
  - **Output**:
    ```
    220
    6 4 1 2 5
    ```

- **Constraints**:
  - Time Limit: 0.1 seconds
  - Memory Limit: 32 MB
*/
struct in{
    int end;
    int profit;
    int i;
};

struct Compare{
    bool operator()(in const& p1,in const& p2){
        return p1.end<p2.end;
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
        v.push_back({x,y,i});
    }
    sort(v.begin(),v.end(),Compare());
    int day = 1;
    set< pair<int,int> > profits;
    vector<bool> jobs(n+1,true);
    for(int i=0; i<v.size(); i++){
        profits.insert({v[i].profit,v[i].i});
        if(day>v[i].end){
            day--;
            auto it = profits.begin();
            jobs[it->second] = false;
            profits.erase(it);
        }
        day++;
    }
    vector<int> res;
    int sum = 0;
    for(int i=0; i<v.size(); i++){
        if(jobs[v[i].i]) {
            res.push_back(v[i].i);
            sum += v[i].profit;
        }
    }
    cout<<sum<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
### Program "Legnagyobb hasznú munkák" Explanation:

1. **Understanding the Problem**:
   - Mohó Márton wants to maximize his total profit by completing jobs within their deadlines.
   - Each job has a deadline and a corresponding profit if completed within the deadline.

2. **Approach**:
   - Sort the jobs based on their deadlines in ascending order.
   - Use a set to maintain the current available jobs and their profits, sorted by profit.
   - Iterate through the sorted jobs and greedily select the jobs with the highest profit and complete them before their deadlines.
   - Keep track of completed jobs and the total profit.

3. **Algorithm**:
   - Read the number of jobs N and their deadlines and profits.
   - Create a structure to store job information: deadline, profit, and index.
   - Sort the jobs based on their deadlines.
   - Initialize a variable to keep track of the current day and a set to store available jobs and their profits.
   - Iterate through the sorted jobs:
     - Add the job to the set with its profit as the key.
     - If the current day exceeds the job's deadline, remove the job with the least profit from the set (greedy approach).
   - Output the maximum total profit achievable and the indices of the completed jobs.

4. **Explanation**:
   - The program sorts the jobs based on deadlines and iterates through them, selecting jobs with the highest profit and completing them before their deadlines.
   - It outputs the maximum total profit achievable and the indices of the completed jobs.

5. **Time Complexity**:
   - Sorting the jobs based on deadlines: O(N log N)
   - Iterating through the jobs and selecting jobs: O(N log N)
   - Total: O(N log N)

This approach calculates the maximum possible total profit by completing jobs within their deadlines, satisfying the problem requirements.
*/