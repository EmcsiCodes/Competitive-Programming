#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
/*
Here's a summary of the problem "Hegy" (Mountain):

- **Problem Description**:
  Mountaineers are setting up camps with food supplies on a mountain to aid climbers. N climbers are carrying packages. Each climber specifies until which camp they are willing to carry their packages. The climbers can deposit any amount of their packages at any point before the specified camp. The goal is to distribute the packages evenly among the camps, aiming for the maximum possible number of packages in each camp.

- **Task**:
  Create a program that calculates the minimum number of packages in the camps for an even distribution.

- **Input**:
  - The first line of standard input contains the number of camps M (1 ≤ M ≤ 100,000) and the number of climbers N (1 ≤ N ≤ 200,000).
  - The following N lines each contain two integers separated by a space: the number of packages carried by a climber Di (1 ≤ Di ≤ 1,000,000) and the camp number Hi (1 ≤ Hi ≤ M) until which the climber carries the packages.

- **Output**:
  - The program should output a single number, the minimum number of packages that can be distributed to each camp.

- **Example**:
  - **Input**:
    ```
    10 6
    3 5
    3 5
    14 7
    6 8
    3 10
    10 10
    ```
  - **Output**:
    ```
    3
    ```

- **Constraints**:
  - Time Limit: 0.1 seconds
  - Memory Limit: 32 MB

*/
#define INF 10000000
struct in{
    int cap;
    int h;
};

struct Compare{
    bool operator()(in const& p1, in const& p2){
        return p1.h<p2.h;
    }
};

void fill(set< pair<int,int> > &s, int cap){
    while(cap!=0){    
        auto hi = s.begin();
        auto lo = hi;
        hi++;
        int h1 = lo->first;
        int h2 = INF;
        if(hi!=s.end()) h2 = hi->first;
        if(cap/lo->second + h1 >= h2){
            cap -= (h2 - h1) * (lo->second);        
            pair<int,int> newh = {h2,hi->second+lo->second};
            s.erase(lo);
            s.erase(hi);
            s.insert(newh);
        } else {
            pair<int,int> newhm = {1,cap%lo->second};
            pair<int,int> newh = {cap/lo->second + lo->first,lo->second};
            if(cap%lo->second != 0) {
                newh.second -= newhm.second;
                newhm.first += newh.first;
                s.erase(lo);
                s.insert(newh);
                s.insert(newhm);
            }
            else s.insert(newh);
            return;
        }
    }
}

int main()
{
    int h,n;
    cin>>h>>n;
    vector<in> v;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),Compare());
    set< pair<int,int> > s;
    int lasth = 0;
    for(int i=0; i<v.size(); i++){
        if(v[i].h>lasth) s.insert({0,v[i].h - lasth});
        lasth = v[i].h;
        fill(s,v[i].cap);
    }
    cout<<s.begin()->first;
    return 0;
}
/*
### Program: "Mountain"

1. **Understanding the Problem**:
   - The problem involves distributing packages carried by climbers evenly among camps on a mountain.
   - Each climber specifies until which camp they are willing to carry their packages.
   - The goal is to distribute the packages evenly among the camps, maximizing the number of packages in each camp.

2. **Approach**:
   - Sort the climbers based on their specified camps.
   - Iterate through the climbers, assigning their packages to camps while ensuring even distribution.
   - Output the minimum number of packages that can be distributed to each camp.

3. **Algorithm**:
   - Read input values for the number of camps M, the number of climbers N, and the climbers' package count and specified camps.
   - Create a vector to store the climbers' package count and specified camps.
   - Sort the vector based on the climbers' specified camps.
   - Initialize a set to store the number of packages and corresponding camps.
   - Iterate through the climbers:
     - Assign each climber's packages to camps, ensuring even distribution.
   - Output the minimum number of packages that can be distributed to each camp.

4. **Explanation**:
   - We sort the climbers based on the specified camps.
   - We assign each climber's packages to camps, ensuring even distribution.
   - We output the minimum number of packages that can be distributed to each camp.

5. **Time Complexity**:
   - Sorting the climbers based on specified camps: O(N log N)
   - Iterating through the climbers and distributing packages: O(N)
   - Total: O(N log N)

This approach calculates the minimum number of packages that can be distributed to each camp, satisfying the problem requirements.
*/