#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
/*
- **Problem Description**:
  A large-scale event has invited N guests. Each guest has specified their presence duration at the event. The organizer wants to create a table arrangement such that there exists a time frame where all guests seated at the same table will be present. Each table has a maximum capacity of K guests.

  Create a program that calculates the minimum number of tables needed and provides a seating arrangement.

- **Input**:
  - The first line of standard input contains the number of guests, N (1 ≤ N ≤ 500,000), and the table capacity, K (2 ≤ K ≤ 100).
  - The next N lines each contain the arrival and departure times of a guest (1 ≤ E < T ≤ 100,000). A guest arriving at time E and departing at time T will be present at any time x where E ≤ x ≤ T.

- **Output**:
  - The program should output on the first line the minimum number of tables needed, M.
  - The following M lines should each contain the guest numbers to be seated at a table, in any order.

- **Example**:
  - **Input**:
    ```
    7 3
    7 8
    1 3
    2 6
    4 6
    2 5
    1 4
    7 9
    ```
  - **Output**:
    ```
    3
    2 6 5
    3 4
    1 7
    ```

- **Constraints**:
  - The constraints ensure the computation can be performed within a reasonable time frame.
  - In 40% of the tests, N < 10,000 and T ≤ 10,000.
*/
struct in{
    int start;
    int end;
    int i;
};

struct Compare{
    bool operator()(in const& p1,in const& p2){
        return p1.start < p2.start;
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
        v.push_back({x,y,i});
    }
    sort(v.begin(),v.end(),Compare());
    multiset< pair<int,int> > tables;
    vector<int> cap(20000,0);
    int index = 1;
    vector<int> res[20000];
    res[1].push_back(v[0].i);
    cap[1]++;
    tables.insert({v[0].end,1});//cout<<"sziaaa";
    for(int i=0; i<v.size(); i++){
        cout<<v[i].i<<": "<<v[i].start<<" "<<v[i].end<<endl;
    }
    for(int i=1; i<v.size(); i++){
        auto it = tables.lower_bound({v[i].start,1000000});
        if(it==tables.begin()){
            if(cap[it->second]<k){
                res[it->second].push_back(v[i].i);
                tables.insert({v[i].end,it->second});
                cap[it->second]++;
            }
            else {
                index++;
                res[index].push_back(v[i].i);
                tables.insert({v[i].end,index});
                cap[index]++;
                  
            } 
            continue; 
        }
        tables.insert({v[i].end,tables.begin()->second});
        res[tables.begin()->second].push_back(v[i].i);
        cap[tables.begin()->second]++;
        for(auto j=tables.begin(); j!=it; j++) {
            cap[j->second]--;
        }
        tables.erase(tables.begin(),it);
    }
    cout<<index<<endl;
    for(int i=1; i<=index; i++){
        for(auto j:res[i]) cout<<j<<" ";
        cout<<'\n';
    }
    return 0;
}
/*
### Program: "Table Seating Arrangement"

1. **Understanding the Problem**:
   - Given the arrival and departure times of guests, and the maximum capacity of each table, we need to arrange the guests in a way that each table has guests present during some common time frame.

2. **Approach**:
   - Sort the guests based on their arrival times.
   - Iterate through the sorted guest list.
   - For each guest, find an available table (if any) and assign them.
   - If no table is available, create a new table and assign the guest to that table.

3. **Algorithm**:
   - Sort the guests based on their arrival times.
   - Create a multiset to represent tables, sorted by the departure time of the guests at each table.
   - Create an array to track the capacity of each table.
   - Initialize an index for table numbers.
   - Iterate through the sorted guests:
     - Check if any table is available. If available, assign the guest to that table and update the departure time for that table.
     - If no table is available, create a new table, assign the guest to that table, and update the departure time for the new table.
   - Print the number of tables and the guests assigned to each table.

4. **Explanation**:
   - We iterate through the sorted list of guests, and for each guest, we try to find an available table using the `multiset`. If a table is available (i.e., the departure time of the guest at the current table is after the arrival time of the new guest), we assign the guest to that table. If no table is available, we create a new table and assign the guest to that.

5. **Time Complexity**:
   - Sorting the guests: O(N log N)
   - Iterating through the guests: O(N)
   - Total: O(N log N)

This approach ensures that each table has guests present during a common time frame, and we aim to minimize the number of tables used.
*/