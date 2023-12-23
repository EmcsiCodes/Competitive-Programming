#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Here's a summary of the problem "Rendezvény 2 teremben" (Event in 2 Halls):

- **Problem Description**:
  A cultural center has two large auditoriums, A and B. On a given day, they want to host many events in the two halls. The director has collected requests specifying who wants to host an event and when. Naturally, only one event can take place in each hall at a time. If an event ends at time T, the next event can start no earlier than at time T+1.

- **Task**:
  Create a program that calculates the maximum number of events that can be held in the two halls. The program should also provide a schedule for the two halls, ensuring that the maximum number of events is held.

- **Input**:
  - The first line of standard input contains the number of requested events N (1 ≤ N ≤ 1000).
  - The next N lines each contain two integers, the starting time E and ending time T of a requested event (1 ≤ E < T ≤ 720).

- **Output**:
  - The program should output the number of events assigned to Hall A (U) and Hall B (V) in the first line.
  - The second line should contain the sequence of event numbers assigned to Hall A.
  - The third line should contain the sequence of event numbers assigned to Hall B.

- **Example**:
  - **Input**:
    ```
    10
    3 8
    9 20
    13 25
    2 5
    2 4
    13 22
    22 30
    6 10
    7 9
    10 20
    ```
  - **Output**:
    ```
    3 4
    5 8 6
    4 9 10 7
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
    vector<bool> visited(1000,false);
    vector<in> v;
    vector<int> res1,res2;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y,i});
    }
    sort(v.begin(),v.end(),Compare());
    auto start = v.begin();
    visited[start->i] = true;
    while(start!=v.end()){
        res1.push_back(start->i);
        auto it = start;
        while(it!=v.end() && (it->start <= start->end || visited[it->i])) it++;
        start = it;
        if(it!=v.end()) visited[start->i] = true;
    }
    start = v.begin();
    while(start!=v.end() && visited[start->i]) start++;
    while(start!=v.end()){
        res2.push_back(start->i);
        auto it = start;
        while(it!=v.end() && (it->start <= start->end || visited[it->i])) it++;
        start = it;
        if(it!=v.end()) visited[start->i] = true;
    }
    cout<<res1.size()<<" "<<res2.size()<<endl;
    for(auto i:res1) cout<<i<<" ";
    cout<<'\n';
    for(auto i:res2) cout<<i<<" ";
    return 0;
}
/*
This program solves the problem of scheduling events in two halls efficiently. Here's a step-by-step explanation:

1. **Understanding the Problem**:
   - The program takes input for the number of requested events `N`.
   - Each event is represented by a pair of integers (start time `E` and end time `T`), indicating when an event starts and ends.

2. **Approach**:
   - The program sorts the events based on their end times in ascending order, using a custom comparator (`Compare` struct).
   - It maintains two vectors, `res1` and `res2`, to store the events scheduled in Hall A and Hall B, respectively.
   - A boolean vector `visited` is used to keep track of which events have been scheduled.
   - The scheduling process involves iterating through the sorted events:
     - Starting with the first event (`start`), it schedules the event in Hall A (`res1`) and marks it as visited.
     - It then looks for the next available event in the sorted list that can be scheduled in Hall A, considering both start time and whether it has been visited before.
     - This process continues until no more events can be scheduled in Hall A.
     - After that, it looks for the next available event in the sorted list that can be scheduled in Hall B (`res2`).
     - This process continues until no more events can be scheduled in Hall B.

3. **Output**:
   - The program outputs the number of events assigned to Hall A (`res1.size()`) and Hall B (`res2.size()`).
   - It then outputs the event numbers assigned to Hall A and Hall B in separate lines.

4. **Explanation**:
   - The program effectively schedules events in both Hall A and Hall B, ensuring that the maximum number of events are held without overlapping.
   - It keeps track of visited events to avoid scheduling the same event in both halls.

5. **Time Complexity**:
   - The time complexity of the algorithm is O(NlogN) due to the sorting of events based on their end times.

This approach efficiently schedules events in two halls while maximizing the number of events held.
*/