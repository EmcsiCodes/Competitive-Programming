#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
In this problem, you need to determine the shortest time interval during which you can meet at least half of the guests at an event.

Here's a detailed explanation of the problem:

Input:

The first line of the input contains an integer N, the number of guests (1 ≤ N ≤ 100,000).
The following N lines each contain two integers, the arrival and departure times of each guest (1 ≤ Arrival < Departure ≤ 100,000).
The times are given in the order of arrival.
Objective:

The goal is to find the shortest time interval during which you can meet at least half of the guests.
Output:

The program should output the number of time points in this interval and then the start and end times of this interval.
Example:

For example, given the arrival and departure times of each guest, the program should determine the shortest time interval during which you can meet at least half of the guests.
Constraints:

The time limit for the program is 0.2 seconds.
The memory limit for the program is 32 MB.
*/
int main()
{
    int n;
    vector< pair<int,char> > v;
    cin>>n;
    for(int i=0; i<n; i++) {
        int x,y;
        cin>>x>>y;
        v.push_back({x,'x'}); // Arrival time is represented by 'x'.
        v.push_back({y,'y'}); // Departure time is represented by 'y'.
    }
    sort(v.begin(),v.end()); // Sort the time points (arrival and departure times).

    pair<int,int> res={0,100001}; // Initialize the result interval with a large range.
    int count = 0, l=0, r=0;
    int minMeet;
    if(n%2==0) minMeet = n/2; // If the number of guests is even.
    else minMeet = n/2 + 1; // If the number of guests is odd.

    // Slide a window over the time points to find the shortest interval with at least half of the guests.
    while(r<v.size()){
        while(count!=minMeet && r<v.size()){
            if(v[r].second == 'x') count++; // Count arrivals.
            r++;
        }

        while(l<v.size() && v[l].second == 'x') {
            l++;
        }

        if(count==minMeet && r<v.size() && v[r-1].first - v[l].first < res.second - res.first){
            res.first = v[l].first; // Update the start time of the result interval.
            res.second = v[r-1].first; // Update the end time of the result interval.
        }
        count--;
        l++;

        while(l<=r && v[l].second!='y'){
            l++;
        }
    }

    // Output the number of time points in the shortest interval and the start and end times of the interval.
    cout<<res.second - res.first + 1<<endl;
    cout<<res.first<<" "<<res.second;
    return 0;
}
/*
Input Reading:

The number of guests n is read from input.
For each guest, the arrival and departure times are read, and they are represented by 'x' and 'y' respectively.
Data Storage:

A vector of pairs v is used to store time points (arrival and departure times).
Processing Time Points:

Time points are sorted to process them in order.
A sliding window approach is used to find the shortest time interval with at least half of the guests.
Finding Shortest Interval:

A window is slid from left to right while keeping track of arrivals and departures.
Whenever at least half of the guests are present (count equals minMeet), the current interval is checked for being the shortest so far.
Output:

The number of time points in the shortest interval and the start and end times of this interval are outputted.
Complexity Analysis:
The time complexity of this algorithm is O(N log N) due to the sorting step and the iteration through the time points.
The space complexity is O(N) due to the storage of time points in the vector.
*/