#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
**Problem Summary:**

Given observations of cars on a highway (including their license plate numbers, location, and time of observation), determine the fastest cars between consecutive locations.

**Input:**

- Number of locations (N).
- Number of observations (M).
- For each observation:
  - Car license plate number (6-digit integer).
  - Location of observation.
  - Hour of observation (0 to 24*30).
  - Minute of observation (0 to 59).

**Output:**

- For each segment between two locations, output the license plate numbers of the cars that were fastest in that segment.

**Example:**

- **Input:**
  ```
  4 10
  111111 1 1 20
  999999 4 1 25
  999999 3 1 35
  111111 2 1 40
  555555 1 2 0
  999999 2 2 5
  111111 3 2 10
  333333 3 2 15
  555555 2 2 15
  333333 2 2 25
  ```

- **Output:**
  ```
  555555 111111 0
  0 333333 999999
  ```

Here, for the segment between location 1 and 2, car 555555 was the fastest in one direction, while in the opposite direction, cars 333333 and 999999 were equally fast.

*/
#define INF 10000000
struct in{
    int road;
    int hour;
    int min;
};

int main()
{
    int n,m;
    cin>>n>>m;
    unordered_map<int,vector<in>> v;
    for(int i=1; i<=m; i++){
        int x,y,z,q;
        cin>>x>>y>>z>>q;
        v[x].push_back({y,z,q});
    }
    pair<int,int> dp[101][101];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) dp[i][j] = {INF,0};
    }
    for(auto i = v.begin(); i!=v.end(); i++){
        for(int j = 1; j<i->second.size(); j++){
            int time = i->second[j].min + 60 * i->second[j].hour;
            int prevtime = i->second[j-1].min + 60 * i->second[j-1].hour;
            int currtime = time - prevtime;
            if(dp[i->second[j-1].road][i->second[j].road].first > currtime){
                dp[i->second[j-1].road][i->second[j].road].first = currtime;
                dp[i->second[j-1].road][i->second[j].road].second = i->first;
            }
        }
    };
    for(int i=1; i<n; i++){
        cout<<dp[i][i+1].second<<" ";
    }
    cout<<endl;
    for(int i=2; i<=n; i++){
        cout<<dp[i][i-1].second<<" ";
    }
    return 0;
}
/*
Absolutely! Let's dive into a detailed explanation of the program's approach to solving the problem.

### 1. **Understanding the Problem:**

The problem revolves around determining the fastest cars between consecutive locations based on the given observations. The goal is to identify the time taken by each car to travel between locations and find the fastest cars in each segment.

### 2. **Data Representation:**

- The program starts by reading the number of locations (`n`) and the number of observations (`m`).
- It uses an unordered map to store observations, where the keys are car license plate numbers, and the values are vectors of observations for each car.

### 3. **Dynamic Programming to Calculate Fastest Cars:**

- To find the fastest cars for each segment, the program employs dynamic programming (DP). It uses a 2D DP table (`dp`), where `dp[i][j]` stores the fastest car to travel from location `i` to location `j`.

### 4. **Filling the DP Table:**

- The program iterates through each car's observations.
- For each car, it calculates the time difference between consecutive observations, representing the time taken to travel from one location to another.
- It then updates the DP table with the minimum time taken between each pair of locations, along with the car's license plate number.

### 5. **Output:**

- Finally, the program outputs the license plate numbers of the fastest cars for each segment between two locations.

### Example Walkthrough:

Let's walk through an example using the provided input and see how the DP table is filled to find the fastest cars for each segment.

### Input:
```
4 10
111111 1 1 20
999999 4 1 25
999999 3 1 35
111111 2 1 40
555555 1 2 0
999999 2 2 5
111111 3 2 10
333333 3 2 15
555555 2 2 15
333333 2 2 25
```

### DP Table Initialization:
```
dp table:
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
```

### Filling the DP Table:
- The program calculates time differences between consecutive observations for each car and updates the DP table accordingly.

### Output:
```
555555 111111 0
0 333333 999999
```

The approach efficiently computes and stores the fastest cars between consecutive locations, providing the required output.
*/