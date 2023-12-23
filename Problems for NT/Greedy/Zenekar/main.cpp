#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
/*
- **Problem Description**:
  A popular band is planning its performances for the next year. They have received many invitations for concerts and they need to choose which ones to accept. Each concert request is specified by a pair (e, u) which means the requester wants the band to perform on day k where e ≤ k ≤ u. The goal of the band is to accept as many concert requests as possible.

- **Task**:
  Create a program that calculates which invitations to accept in order to have the maximum number of concerts in the upcoming year.

- **Input**:
  - The first line of standard input contains the number of concert requests N (1 ≤ N ≤ 1000).
  - The following N lines each contain a pair (e, u) separated by a space, representing a concert request where (1 ≤ e ≤ u ≤ 365).

- **Output**:
  - The first line of the output should contain an integer M, the maximum number of concerts that can be accepted.
  - The following M lines should each contain two integers separated by a space. The first integer is the index of an accepted invitation, and the second integer is the day of the concert.

- **Example**:
  - **Input**:
    ```
    6
    2 4
    1 4 
    3 5
    1 3
    3 5
    2 5
    ```
  - **Output**:
    ```
    5
    4 1
    2 2
    3 3
    5 4
    6 5
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
struct in{
    int start;
    int end;
    int i;
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
        v.push_back({x,y,i});
    }
    sort(v.begin(),v.end(),Compare());
    set<int> freeDays;
    for(int i=1; i<=365; i++) freeDays.insert(i);
    vector< pair<int,int> > res;
    for(int i=0; i<v.size(); i++){
        auto it = freeDays.lower_bound(v[i].start);
        if(*it>v[i].end) continue;
        freeDays.erase(it);
        res.push_back({v[i].i,*it});
        if(freeDays.empty()) break;
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i.first<<" "<<i.second<<'\n';
    return 0;
}
/*
The provided code solves the problem of maximizing the number of concerts the band can accept given concert requests and their specified time ranges. Below is a step-by-step explanation of the code:

1. **Understanding the Problem**:
   - The program takes input for the number of concert requests (N) and the time ranges for each concert request.
   - The goal is to maximize the number of concerts the band can accept by selecting appropriate concert requests based on their time ranges.

2. **Approach**:
   - The program sorts the concert requests based on their end times in ascending order.
   - It then iterates through the sorted concert requests and accepts the ones that don't conflict with the previously accepted concerts.

3. **Algorithm**:
   - Define a struct `in` to represent a concert request with start and end times, along with its index.
   - Define a custom comparator `Compare` to sort concert requests based on their end times.
   - Sort the concert requests based on their end times.
   - Initialize a set `freeDays` to store the available days.
   - Iterate through the sorted concert requests:
     - For each request, find the first available day that doesn't conflict with the request's time range.
     - Add the accepted concert request to the result and remove the chosen day from the available days set.
     - Stop the process if there are no more available days.

4. **Output**:
   - Output the maximum number of concerts that can be accepted (`res.size()`) and the indices of the accepted invitations along with their corresponding concert days.

5. **Time Complexity**:
   - The time complexity of the algorithm is O(N log N), where N is the number of concert requests.
   - The sorting operation (`sort`) contributes to the log N factor.

Overall, the program efficiently calculates the maximum number of concerts the band can accept based on the given concert requests and their time ranges.
*/