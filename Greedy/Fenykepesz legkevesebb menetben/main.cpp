#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Here's a summary of the problem "Fényképész legkevesebb menetben" (Photographer in the Fewest Rounds):

- **Problem Description**:
  Guests are invited to an event, and each guest specifies their arrival and departure times. The organizers want to capture the participants in photos. The chosen photographer takes photos in rounds, capturing everyone who was present between the round's start time F and end time F+K. Specifically, the photographer captures guests whose arrival time E and departure time T satisfy E < F+K and F ≤ T. The photographer is paid per round, so the goal is to minimize the number of rounds while ensuring everyone is captured in at least one photo.

- **Task**:
  Create a program that calculates the minimum number of rounds needed to capture everyone in at least one photo and specifies the start times of these rounds.

- **Input**:
  - The first line of standard input contains the number of guests N (1 ≤ N ≤ 100,000) and the length of a round K (2 ≤ K ≤ 1,000).
  - The next N lines each contain two integers separated by a space: the arrival time E and departure time T of a guest (1 ≤ E < T < 20,000).

- **Output**:
  - The program should output the minimum number of rounds M needed.
  - The second line should contain M integers separated by spaces, indicating the starting times of the M rounds.

- **Example**:
  - **Input**:
    ```
    6 2
    1 4
    7 12
    2 6
    4 9
    3 13
    8 10
    ```
  - **Output**:
    ```
    2
    4 10
    ```

- **Constraints**:
  - Time Limit: 0.1 seconds
  - Memory Limit: 32 MB
*/
struct in{
    int start;
    int end;
};

struct Compare{
    bool operator()(in const& p1, in const& p2){
        return p1.start<p2.start;
    }
};

int main()
{
    int n,k;
    cin>>n>>k;
    vector<in> v;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),Compare());
    int i = 0;
    vector<int> res;
    while(i<v.size()){
        int last = v[i].end;
        while(i<v.size() && v[i].start <= last){
            last = min(last, v[i].end);
            i++;
        }
        res.push_back(last);
        while(i<v.size() && v[i].start < last + k) i++;
    }
    cout<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
### Program: "Photographer in the Fewest Rounds"

1. **Understanding the Problem**:
   - The problem involves finding the minimum number of rounds needed to capture all guests in photos based on their arrival and departure times.
   - The photographer captures guests in rounds of length K and wants to minimize the number of rounds while ensuring everyone is captured in at least one photo.

2. **Approach**:
   - Sort the guests based on their arrival times.
   - Start iterating through the guests.
   - For each guest:
     - If the guest's arrival time is within the current round's end time, update the round's end time to the minimum of the current round's end time and the guest's departure time.
     - If the guest's arrival time is after the current round's end time, start a new round with the guest's arrival time as the start time and the departure time as the end time.
   - Output the number of rounds and their start times.

3. **Algorithm**:
   - Read input values for the number of guests, N, and the length of a round, K.
   - Create a vector to store the arrival and departure times of the guests.
   - Sort the vector based on arrival times.
   - Iterate through the guests:
     - If the guest's arrival time is within the current round's end time, update the round's end time.
     - If the guest's arrival time is after the current round's end time, start a new round.
   - Output the number of rounds and their start times.

4. **Explanation**:
   - We sort the guests based on their arrival times.
   - We iterate through the guests, updating the round's end time or starting a new round as needed.
   - We output the number of rounds and their start times.

5. **Time Complexity**:
   - Sorting the guests based on arrival times: O(N log N)
   - Iterating through the guests: O(N)
   - Total: O(N log N)

This approach finds the minimum number of rounds needed to capture all guests in photos, satisfying the problem requirements.
*/