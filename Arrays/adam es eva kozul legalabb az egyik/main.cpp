#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

Certainly! Here's the summary with improved formatting for easier copying:

Summary of the Programming Problem "Ádám és Éva közül legalább az egyik":

This problem involves determining time intervals when we can meet either with Ádám or Éva (or both),
based on the specified time intervals during which they are available.

Input:

The input includes the last possible time within the day (P).
Adam's available time intervals are provided (A) along with their start and end times.
Eve's available time intervals are provided (E) along with their start and end times.
Output:

The output should list the time intervals when we can meet either with Ádám or Éva (or both).
The output includes the number of these time intervals (K) and the start and end times of each interval.
Example:

Given the time constraints and the availability of Ádám and Éva,
determine the time intervals when we can meet with either of them.
Constraints:

The input time limit is 0.4 seconds, and the memory limit is 32 MB.
The problem is scored based on specified constraints,
with a focus on cases where P is less than or equal to 100,000.
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
    sort(v.begin(), v.end());
    vector< pair<int,int> > res;
    int count = 0;
    for(int i=0; i<v.size()-1; i++){
        if(v[i].second == 'x') count ++;
        else count --;
        if(count!=0 && v[i]!=v[i+1]){
            if(!res.empty() && res.rbegin()->second == v[i].first) res.rbegin()->second = v[i+1].first;
            else res.push_back({v[i].first, v[i+1].first});
        }
    }
    cout<<res.size()<<endl;
    for(auto i:res) cout<<i.first<<" "<<i.second<<endl;
    return 0;
}
/*
Input Reading:

The program reads the last possible time within the day (P),
the number of Adam's available time intervals (n),
and the intervals themselves.
It then reads the number of Eve's available time intervals (m) and the intervals for Eve.
Interval Processing:

The program combines the intervals for Adam and Eve into a vector of pairs (v),
marking the start and end times with 'x' and 'y' respectively.
Sorting:

The intervals in the vector v are sorted based on their start times.
Overlapping Interval Detection:

The program iterates through the sorted intervals,
maintaining a count to determine overlapping intervals.
Whenever the count becomes non-zero (indicating an overlap),
and the current interval is different from the next one,
the program records the overlapping interval.
Output:

The program prints the count of overlapping intervals and the start and end times of each overlapping interval.
The program effectively finds and displays the time intervals when both Ádám and Éva can meet,
taking into account their respective available time intervals.
It utilizes a sorted approach to efficiently detect overlapping intervals
and presents the results according to the specified format.
*/