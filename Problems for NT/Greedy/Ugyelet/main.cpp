#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
/*
Here's a summary of the problem "Ügyelet" (Shifts):

- **Problem Description**:
  A large event is looking for volunteers to be on duty during the event. The event lasts for M minutes. A total of N applicants have applied, specifying the duration they are willing to be on duty.
  Create a program that calculates the minimum number of volunteers to be selected, so that at any minute, there are at least two volunteers present.

- **Input**:
  - The first line of standard input contains the number of minutes M (1 ≤ M ≤ 100,000) and the number of applicants N (1 ≤ N ≤ 10,000).
  - The next N lines each contain the starting and ending minute of availability for each applicant, denoted by Ai and Bi (1 ≤ Ai ≤ Bi ≤ M), meaning that the i-th applicant is available from minute Ai to minute Bi (including both Ai and Bi).

- **Output**:
  - The program should output the minimum number of selected applicants K, followed by the indices of the selected K applicants in any order.

- **Example**:
  - **Input**:
    ```
    6 7
    2 3
    3 4
    4 6
    3 6
    1 4
    1 2
    3 5
    ```
  - **Output**:
    ```
    4
    5 6 4 3
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
struct in{
    int start,end,i;
    bool visited;
};

struct Compare{
    bool operator()(in const& p1,in const& p2){
        return p1.start < p2.start;
    }
};

int main()
{
    int n,m;
    cin>>n>>m;
    vector<in> v;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y,i,false});
    }
    sort(v.begin(),v.end(), Compare());
    int start = 0;
    vector<int> res;
    int i = 0;
    while(i<v.size() && start<n){
        int maxx = 0;
        int index = 0;
        int p = 0;
        while(i<v.size() && v[i].start <= start + 1){
            if(maxx <= v[i].end){
                maxx = v[i].end;
                index = v[i].i;
                p = i;
            } 
            i++;
        }
        if(maxx == 0) {
            cout<<0;
            return 0;
        }
        start = maxx;
        res.push_back(index);
        v[p].visited = true;
    }
    if(start!=n) {
        cout<<0;
        return 0;
    }
    i = 0;
    start = 0;
    while(i<v.size() && start<n){
        int maxx = 0;
        int index = 0;
        while(i<v.size() && v[i].start <= start + 1){
            if(!v[i].visited && maxx <= v[i].end){
                maxx = v[i].end;
                index = v[i].i;
            } 
            i++;
        }
        if(maxx == 0) {
            cout<<0;
            return 0;
        }
        start = maxx;
        res.push_back(index);
    }
    if(start!=n) {
        cout<<0;
        return 0;
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
The provided code efficiently solves the problem of selecting the minimum number of volunteers to ensure that at any minute, there are at least two volunteers present during an event. Here's a step-by-step explanation of the code:

1. **Understanding the Problem**:
   - The program takes input for the total duration of the event (M minutes) and the availability intervals of N applicants (specified by start and end minutes).
   - The task is to select the minimum number of volunteers such that at any minute during the event, there are at least two volunteers available.

2. **Approach**:
   - The program uses a greedy approach to select volunteers.
   - It sorts the volunteers based on their start time and iterates through the sorted list.
   - For each volunteer, it selects the one with the maximum end time that doesn't clash with the previous selection.
   - It ensures that there are at least two volunteers available at any minute during the event.

3. **Algorithm**:
   - Sort the volunteers based on their start times.
   - Iterate through the sorted volunteers and select the one with the maximum end time that doesn't clash with the previous selection.
   - Ensure that there are at least two volunteers available at any minute during the event.

4. **Output**:
   - The program outputs the minimum number of selected applicants K and the indices of the selected K applicants in any order.

5. **Time Complexity**:
   - The time complexity of the algorithm is O(N log N) due to the sorting of volunteers based on their start times.
   - The algorithm iterates through the sorted volunteers once, which has a time complexity of O(N).

Overall, the program efficiently calculates the minimum number of volunteers needed to ensure that at any minute, there are at least two volunteers present during the event.
*/