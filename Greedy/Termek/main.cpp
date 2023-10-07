#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
/*
Here's a summary of the problem "Termek" (Rooms):

- **Problem Description**:
  The school is planning a grand celebration on the anniversary. They have multiple events scheduled for the day, and some events partially overlap in time. The task is to determine the minimum number of rooms needed so that each event has a reserved room and events don't clash.

- **Task**:
  Create a program that calculates the minimum number of rooms needed and provides a possible room allocation.

- **Input**:
  - The first line of standard input contains the number of events N (1 ≤ N ≤ 100,000).
  - The next N lines each contain the starting and ending time of an event (1 ≤ Ki ≤ Bi ≤ 1440).

- **Output**:
  - The program should output the minimum number of rooms needed for all the events.
  - The following T lines should contain the event numbers allocated to each room, separated by spaces.

- **Example**:
  - **Input**:
    ```
    8
    1100 1200
    500 520
    510 570
    600 630
    630 700
    700 800
    600 800
    650 700
    ```
  - **Output**:
    ```
    4
    2 4 8
    3 7
    5 1
    6
    ```

- **Constraints**:
  - The constraints ensure that the computation can be performed within a reasonable time frame.
*/
struct in{
    int node;
    char c;
    int i;
};

struct Compare{
    bool operator()(in const& p1, in const& p2){
        if(p1.node == p2.node) return p1.c < p2.c;
        return p1.node < p2.node;
    }
};

vector<int> roomNum(100001,0);
vector<int> res[100001];

int main()
{
    int n;
    cin>>n;
    vector<in> v;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,'x',i});
        v.push_back({y,'y',i});
    }
    sort(v.begin(),v.end(), Compare());
    queue<int> next;
    int maxRooms = 0;

    for(int i=0; i<v.size(); i++){
        if(v[i].c == 'x') {
            if(next.empty()){
                maxRooms++;
                next.push(maxRooms);
            }
            res[next.front()].push_back(v[i].i);
            roomNum[v[i].i] = next.front();
            next.pop();
        } else {
            next.push(roomNum[v[i].i]);
        }
    }
    cout<<maxRooms<<'\n';
    for(int i=1; i<=maxRooms; i++){
        for(auto j:res[i]) cout<<j<<" ";
        cout<<'\n';
    }
    return 0;
}
/*
The provided code efficiently solves the problem of determining the minimum number of rooms needed for events, ensuring that events don't clash. Here's a step-by-step explanation of the code:

1. **Understanding the Problem**:
   - The program takes input for the number of events `N` and the starting and ending times of each event.
   - The goal is to determine the minimum number of rooms needed such that each event has a reserved room and events don't overlap.

2. **Approach**:
   - The program processes the events and their start and end times.
   - It keeps track of rooms and allocates events to rooms based on their start and end times.
   - It sorts the events by their start and end times, processing them in a way to minimize the number of rooms needed.

3. **Data Structures**:
   - It uses a custom structure `in` to store event information, including time, type (start or end), and event index.
   - It uses a priority queue to determine the next available room.

4. **Room Allocation**:
   - It processes each event, determining the appropriate room to allocate based on the event's start and end times.
   - If an event starts (`'x'` type), it checks if there's an available room. If not, it increments the room count and assigns the event to a new room.
   - If an event ends (`'y'` type), it returns the room number to the available rooms for future events.

5. **Output**:
   - The program outputs the minimum number of rooms needed and the events allocated to each room.

6. **Time Complexity**:
   - The time complexity of the algorithm is O(N log N) due to the sorting of events.

Overall, the program efficiently calculates the minimum number of rooms needed and optimally allocates events to minimize room usage and ensure events don't overlap.
*/