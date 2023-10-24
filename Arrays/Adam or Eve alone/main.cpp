#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
This problem involves finding time intervals when we can meet either with Ádám or Éva (individually),

based on their specified time intervals during which they are available.

Input:

The input includes the last possible time within the day (P).
Adam's available time intervals are provided (A) along with their start and end times.
Eve's available time intervals are provided (E) along with their start and end times.
Output:

The output should list the time intervals when we can meet either with Ádám or Éva (individually).

The output includes the number of these time intervals (K) and the start and end times of each interval.

Example:

Given the time constraints and the availability of Ádám and Éva,
determine the time intervals when we can meet with either of them individually.

Constraints:

The input time limit is 0.1 seconds,

The memory limit is 32 MB.

The problem is scored based on specified constraints,

With a focus on cases where P is less than or equal to 100,000.
*/
int main()
{
    int p,n,m;
    cin>>p>>n;
    vector< pair<int,char> > v;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,'x'});
        v.push_back({y,'y'});
    }
    cin>>m;
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,'x'});
        v.push_back({y,'y'});
    }
    sort(v.begin(),v.end());
    int count=0;
    vector< pair<int,int> > res;
    for(int i=0; i<v.size()-1; i++){
        if(v[i].second == 'x') count++;
        else count--;
        if(count == 1 && v[i+1].first!=v[i].first){
            if(!res.empty() && res.rbegin()->second == v[i].first){
                res.rbegin()->second = v[i+1].first;
            }
            else res.push_back({v[i].first,v[i+1].first});
        }
    }
    cout<<res.size()<<endl;
    for(auto i:res) cout<<i.first<<" "<<i.second<<endl;
    return 0;
}
/*
/**
 * \brief Explanation of the Program's Approach:
 *
 * The program aims to find time intervals when we can meet either with Ádám or Éva (individually), based on their specified time intervals. It follows these steps:
 *
 * 1. \b Input \b Reading:
 *    - Reads input values for the last possible time within the day (P), the number of Adam's intervals (n), and the intervals themselves.
 *
 * 2. \b Vector \b Initialization:
 *    - Initializes a vector of pairs (`v`) to store the intervals.
 *
 * 3. \b Interval \b Processing:
 *    - Reads Adam's intervals, marks start and end times, and adds them to the vector `v`. Similarly, it reads Eve's intervals and adds them to `v`.
 *
 * 4. \b Sorting:
 *    - Sorts the intervals in `v` based on their start times.
 *
 * 5. \b Individual \b Meeting \b Intervals:
 *    - Iterates through the sorted intervals and identifies intervals where we can meet either with Ádám or Éva individually. It keeps track of overlapping intervals.
 *
 * 6. \b Output:
 *    - Prints the count and the start and end times of the individual meeting intervals.
 *
 * Overall, the program efficiently determines the time intervals when we can meet either with Ádám or Éva (individually), considering their specified time intervals.
 */