#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
Here's a summary of the problem "Fényképész legkevesebbszer" (Photographer with the Fewest Sessions):

- **Problem Description**:
  Guests have specified their presence duration at an event, and organizers want to capture them in group photos. A photographer is hired for this purpose, and they commit to staying for a specific duration during each session. During a session, the photographer can take photos at specific time intervals. The goal is to call the photographer the minimum number of times while ensuring everyone is in at least one photo.

- **Task**:
  Create a program that calculates the minimum number of times the photographer needs to be called and specifies the time intervals for each session.

- **Input**:
  - The first line of standard input contains the number of guests N (1 ≤ N ≤ 200,000), the photographer's committed duration per session T (1 ≤ T ≤ 10,000), and the maximum number of photos D that can be taken in a single session (1 ≤ D ≤ T).
  - The next N lines each contain two integers: the arrival time E and departure time U of a guest (1 ≤ E < U ≤ 20,000).

- **Output**:
  - The program should output M+1 lines. The first line contains an integer M, the minimum number of times the photographer needs to be called.
  - The subsequent M lines each contain the time intervals in increasing order, separated by spaces, when a photo should be taken in each session.

- **Example**:
  - **Input**:
    ```
    8 3 2
    1 3
    4 6
    1 4
    4 8
    3 6
    8 12
    2 4
    5 9
    ```
  - **Output**:
    ```
    2
    2 4
    8
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
    bool operator()(in const& p1,in const& p2){
        return p1.start < p2.start;
    }
};

int main()
{
    int n,t,d;
    cin>>n>>t>>d;
    vector<in> v;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    t--;
    sort(v.begin(),v.end(),Compare());
    int i = 0, index = 1;
    vector<int> res[10000];
    while(i<v.size()){
        int last = v[i].end;
        while(i<v.size() && v[i].start<last){
            last = min(last, v[i].end);
            i++;
        }
        last--;
        res[index].push_back(last);
        int photosMade = 1;
        int nextlast = v[i].end;
        while(i<v.size() && photosMade < d && v[i].start <= last + t){
            if(v[i].start < nextlast){
                nextlast = min(nextlast, v[i].end);
                i++;
            } else {
                photosMade++;
                res[index].push_back(nextlast-1);
                nextlast = v[i].end;
            }
        }
        if(i<v.size() && photosMade!=d) res[index].push_back(last + t - 1);
        index++;
    }
    index--;
    cout<<index<<'\n';
    for(int i=1; i<=index; i++){
        for(auto j:res[i]) cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
/*
### Program: "Photographer with the Fewest Sessions"

1. **Understanding the Problem**:
   - The problem involves determining the minimum number of times a photographer needs to be called and specifying the time intervals for each session to capture guests in group photos.
   - The photographer commits to staying for a specific duration during each session and can take a maximum of D photos in a single session.

2. **Approach**:
   - Sort the guests based on their arrival times.
   - Iterate through the guests and track the intervals when the photographer should take photos.
   - Ensure that each session does not exceed the committed duration per session and the maximum number of photos per session.
   - Output the minimum number of times the photographer needs to be called and the time intervals for each session.

3. **Algorithm**:
   - Read input values for the number of guests, N, the photographer's committed duration per session, T, and the maximum number of photos D that can be taken in a single session.
   - Create a vector to store the arrival and departure times of the guests.
   - Sort the vector based on arrival times.
   - Iterate through the guests:
     - Track the time intervals for each session based on the committed duration and maximum photos per session.
   - Output the minimum number of times the photographer needs to be called and the time intervals for each session.

4. **Explanation**:
   - We sort the guests based on their arrival times.
   - We iterate through the guests, tracking the time intervals for each session based on the photographer's commitments.
   - We output the minimum number of times the photographer needs to be called and the time intervals for each session.

5. **Time Complexity**:
   - Sorting the guests based on arrival times: O(N log N)
   - Iterating through the guests: O(N)
   - Total: O(N log N)

This approach finds the minimum number of times the photographer needs to be called and specifies the time intervals for each session to capture guests in group photos, satisfying the problem requirements.
*/