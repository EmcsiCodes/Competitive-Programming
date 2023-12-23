#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
/*
Here's a summary of the problem "Koncert" (Concert):

- **Problem Description**:
  A year's concert is held at a venue with M seats. The organizers can receive requests for specific seats. A request can specify a range of seats [A, B], meaning the requester wants to receive a seat for which the seat number S satisfies A ≤ S ≤ B.

- **Task**:
  Create a program that calculates the maximum number of requests that can be fulfilled and provides a suitable distribution of tickets.

- **Input**:
  - The first line of standard input contains the number of seats M (3 ≤ M ≤ 100,000) and the number of requests N (1 ≤ N ≤ 1,000,000).
  - The following N lines each contain a pair of numbers A and B (1 ≤ A ≤ B ≤ M) representing a request.

- **Output**:
  - The program should output the maximum number of requests that can be fulfilled.
  - It should then output K lines, where K is the maximum number of requests. Each line should contain two numbers, the request number and the assigned seat number.

- **Example**:
  - **Input**:
    ```
    10 7
    2 3
    2 5
    3 3
    1 2
    6 7
    2 2
    6 10
    ```
  - **Output**:
    ```
    6
    1 1
    2 2
    3 3
    4 4
    5 5
    6 6
    ```

- **Constraints**:
  - Time Limit: 0.5 seconds
  - Memory Limit: 32 MB
*/
struct in{
    int start;
    int end;
    int i;
};

struct Compare{
    bool operator()(in const& p1, in const& p2){
        return p1.end<p2.end;
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
        v.push_back({x,y,i});
    }
    sort(v.begin(),v.end(),Compare());
    set<int> s;
    for(int i=1; i<=n; i++){
        s.insert(i);
    }
    vector< pair<int,int> > res;
    for(int i=0; i<v.size(); i++){
        auto it = s.lower_bound(v[i].start);
        if(it==s.end() || *it>v[i].end) continue;
        res.push_back({v[i].i,*it});
        s.erase(it);
        if(s.empty()) break;
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i.first<<" " <<i.second<<'\n';
    return 0;
}
/*
### Program "Koncert" Explanation:

1. **Understanding the Problem**:
   - The problem involves fulfilling seat requests for a concert with a limited number of available seats.
   - Each request specifies a range of seats [A, B], and the goal is to maximize the number of fulfilled requests.

2. **Approach**:
   - Sort the requests based on the end of their seat range.
   - Greedily process the requests, assigning seats if available.
   - Output the maximum number of fulfilled requests and the assigned seat numbers.

3. **Algorithm**:
   - Read the number of seats M and the number of requests N.
   - Create a structure to store request information: start seat, end seat, and request number.
   - Sort the requests based on the end of their seat range.
   - Initialize a set to keep track of available seats.
   - Iterate through the sorted requests:
     - Find the lowest available seat greater than or equal to the request start.
     - If found, assign the seat to the request and remove it from available seats.
     - Track the maximum number of fulfilled requests and the assigned seat numbers.
   - Output the maximum number of fulfilled requests and the assigned seat numbers.

4. **Explanation**:
   - The program sorts the requests based on the end of their seat range.
   - It then processes the requests greedily, assigning seats if available and tracking the fulfilled requests.
   - The output includes the maximum number of fulfilled requests and the assigned seat numbers.

5. **Time Complexity**:
   - Sorting the requests: O(N log N)
   - Processing requests and assigning seats: O(N log N)
   - Total: O(N log N)

This approach effectively calculates the maximum number of requests that can be fulfilled and provides a suitable distribution of tickets, satisfying the problem requirements.
*/