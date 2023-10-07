#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

/*
**Problem Summary:**

The police are looking for witnesses to a suspicious event that happened at an event. They have recorded the arrival and departure times of every guest. A guest can be a witness to a suspicious event if the event happened after their arrival and before their departure.

Write a program to find the minimum number of guests such that there is a selected guest present at each suspicious event.

**Input:**

- Number of guests (N) and number of suspicious events (M).
- For each guest, their arrival and departure times.
- The times of the suspicious events.

**Output:**

- The number of suspicious events (E) that have witnesses.
- The minimum number of guests (T) that can be witnesses.
- The indices of these witnesses.

**Example:**

- **Input:**
  ```
  5 4
  1 18
  2 8
  6 10
  14 18
  15 25
  7 12 16 20
  ```

- **Output:**
  ```
  4
  2
  1 5
  ```

Here, for each suspicious event, there are at least two guests who were present.
*/

int main()
{
    int n,m;
    cin>>n>>m;
    vector< pair<int,int> > v;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    vector<int> t;
    for(int i=1; i<=m; i++){
        int x;
        cin>>x;
        t.push_back(x);
    }
    sort(v.begin(),v.end());
    int i = 0;
    int j = 0;
    int tNum = 0;
    vector<int> res;
    while(j<m && i<n){
        int maxx = 0;
        int index = 0;
        while(i<n && v[i].first<=t[j]){
            if(maxx <= v[i].second){
                maxx = v[i].second;
                index = i;
            }
            i++;
        }
        if(maxx != 0){
            res.push_back(index + 1);
            while(j<m && t[j]<=maxx) {
                j++;
                tNum++;
            }
        } else j++;
    }
    cout<<tNum<<'\n'<<res.size()<<'\n';
    for(auto i:res) cout<<i<<" ";
    return 0;
}
/*
The provided C++ program solves the problem of finding the minimum number of guests required to be witnesses for a suspicious event. Let's break down the approach step by step.

### 1. **Understanding the Problem:**

The goal is to find the minimum number of guests required to be witnesses for a set of suspicious events, given the arrival and departure times of guests and the times of the suspicious events.

### 2. **Input:**

- Read the number of guests (`n`), the number of suspicious events (`m`), and details of each guest (arrival and departure times).
- Read the times of the suspicious events.

### 3. **Approach:**

- Sort the guests based on their arrival times.
- Iterate through the suspicious events.
- For each event, find the guests who are present during that time.
- Choose the guest with the latest departure time to maximize the number of events they can witness.
- Continue this process until all events are covered.

### 4. **Implementation:**

- Create a vector of pairs to store guest information (arrival and departure times).
- Create a vector to store suspicious event times.
- Sort the guest information based on arrival times.
- Iterate through the events and guests, identifying the guests who can witness each event.
- Output the total number of events with witnesses, the number of guests witnessing, and the indices of these guests.

### 5. **Output:**

- Print the number of suspicious events with witnesses, the number of guests witnessing, and the indices of these guests.

### Example Walkthrough:

Let's walk through an example using the provided input and see how the program finds the minimum number of guests witnessing the suspicious events.

### Input:
```
5 4
1 18
2 8
6 10
14 18
15 25
7 12 16 20
```

### Output:
```
4
2
1 5
```

The approach efficiently identifies the guests witnessing each event, providing the required output.
*/