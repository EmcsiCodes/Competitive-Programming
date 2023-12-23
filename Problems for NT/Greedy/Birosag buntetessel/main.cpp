#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
/*
Sure, here's a summary of the problem "Court with Penalties":

- **Problem Description**:
  In a courtroom, one case is heard each day. N clients have scheduled their cases, each with a deadline. If the case cannot be heard by the deadline, a penalty must be paid. The goal is to determine the order of the cases that minimizes the total penalty paid.

- **Input**:
  - The first line of standard input contains the number of cases, N (1 ≤ N ≤ 50,000).
  - The next N lines each contain a deadline and the penalty associated with that deadline (1 ≤ deadline ≤ N, 1 ≤ penalty ≤ 1,100).

- **Output**:
  - The first line should display the minimum total penalty.
  - The second line should list the order of cases that minimizes the penalty.

- **Example**:
  - **Input**:
    ```
    7
    4 70
    2 60
    4 50
    3 40
    1 30
    4 20
    6 10
    ```
  - **Output**:
    ```
    50
    4 2 3 1 7 6 5
    ```

- **Constraints**:
  - Time Limit: 0.3 seconds
  - Memory Limit: 32 MB
*/
struct in{
    int end;
    int c;
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
    vector<int> leaveForEnd;
    vector<in> v;
    for(int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y,i});
    }
    sort(v.begin(),v.end(),Compare());
    multiset< pair<int,int> > fines;
    int day = 1;
    int totalFine = 0;
    for(int i=0; i<v.size(); i++){
        fines.insert({v[i].c,v[i].i});
        if(v[i].end<day){
            day--;
            auto it = fines.begin();
            totalFine += it->first;
            leaveForEnd.push_back(it->second);
            fines.erase(it);
        }
        day++;
    }
    vector<int> res(n+1,0);
    cout<<totalFine<<'\n';
    int p = n;
    for(auto i:leaveForEnd) {
        res[i] = p;
        p--;
    }
    int num = 1;
    for(int i=0; i<v.size(); i++){
        if(res[v[i].i] == 0) {
            res[v[i].i] = num;
            num++;
        }
    }
    for(int i=1; i<=n; i++) cout<<res[i]<<" ";
    return 0;
}
/*
### Program: "Court with Penalties"

1. **Understanding the Problem**:
   - Given cases with deadlines and penalties, the goal is to determine the order of the cases that minimizes the total penalty paid.

2. **Approach**:
   - Sort the cases based on their deadlines in ascending order.
   - Iterate through the cases and assign them a day to be heard, starting from the earliest deadline.
   - Calculate the total penalty based on the assigned days and penalties.

3. **Algorithm**:
   - Read input values for the number of cases, N.
   - Create a vector to store the cases (deadline, penalty, case number).
   - Sort the vector based on deadlines in ascending order.
   - Initialize a multiset to store the penalties and case numbers.
   - Iterate through the sorted cases:
     - Assign the case a day to be heard based on its position in the sorted list.
     - Calculate the total penalty for each case and accumulate it.
     - Store the penalties and case numbers for cases that miss their deadlines.
   - Print the total penalty.
   - Print the order of cases that minimizes the penalty.

4. **Explanation**:
   - We start by sorting the cases based on their deadlines. This allows us to process them in order of their deadlines, minimizing penalties.
   - We iterate through the cases and assign each case a day to be heard based on its position in the sorted list. This ensures that cases with earlier deadlines are heard first.
   - We calculate the total penalty for each case based on the assigned days and penalties.
   - We also store penalties and case numbers for cases that miss their deadlines.
   - Finally, we print the total penalty and the order of cases that minimizes the penalty.

5. **Time Complexity**:
   - Sorting the cases based on deadlines: O(N log N)
   - Iterating through the cases: O(N)
   - Total: O(N log N)

This approach ensures that we assign cases in a way that minimizes the total penalty paid. The goal is to optimize the order of cases to minimize the penalty by assigning cases with earlier deadlines first.
*/