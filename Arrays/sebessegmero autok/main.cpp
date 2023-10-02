#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
This problem involves determining the time intervals when you can encounter speed cameras on a highway, given the service periods of two speed camera cars.

Here's a detailed explanation of the problem:

Input:

The first line of the input contains an integer N, the number of time intervals for the first car's service (1 ≤ N ≤ 100,000).
The following N lines each contain two integers: K1i and V1i, representing the start and end times of each service interval for the first car (1 ≤ K1i ≤ V1i ≤ 100,000,000), in increasing order.
The next line contains an integer M, the number of time intervals for the second car's service (1 ≤ M ≤ 100,000).
The following M lines each contain two integers: K2i and V2i, representing the start and end times of each service interval for the second car (1 ≤ K2i ≤ V2i ≤ 100,000,000), in increasing order.
The intervals for both cars do not overlap (Vi-1 + 1 < Ki).
Objective:

The goal is to determine the time intervals when you can encounter a speed camera on the highway.
Output:

The program should output:
The number of time intervals K when you can encounter a speed camera.
K lines, each containing the start and end times of a time interval when you can encounter a speed camera, in increasing order.
Example:

For example, given the service periods of each speed camera car, the program should determine the time intervals when you can encounter a speed camera.
Constraints:

The time limit for the program is 0.5 seconds.
The memory limit for the program is 32 MB.
*/
int main()
{
    int n,m;
    vector< pair<int,char> > v;  // Vector to store intervals and their types (start or end).
    cin>>n;
    
    // Input the service intervals for the first car.
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,'x'));  // 'x' denotes the start of an interval.
        v.push_back(make_pair(y,'y'));  // 'y' denotes the end of an interval.
    }
    
    cin>>m;
    
    // Input the service intervals for the second car.
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,'x'));  // 'x' denotes the start of an interval.
        v.push_back(make_pair(y,'y'));  // 'y' denotes the end of an interval.
    }
    
    sort(v.begin(),v.end());  // Sort the intervals based on their times.
    
    int c=0;  // Counter to keep track of the number of intervals currently active.
    vector < pair<int,int> > sol;  // Vector to store the resulting intervals.
    sol.push_back(make_pair(v[0].first,0));  // Initialize the first interval.
    
    // Iterate through the sorted intervals to find the time intervals when you can encounter a speed camera.
    for(int i=0; i<v.size(); i++){
        if(v[i].second == 'x') c++;  // Increment counter for interval start.
        else c--;  // Decrement counter for interval end.
        
        // Check if the next interval starts at the same time.
        if(i<v.size()-1 && 1 + v[i].first==v[i+1].first) continue;
        
        // If no active intervals, add the current interval to the result.
        if(c==0) {
            int last = sol.size() - 1;
            sol[last].second = v[i].first;  // Update the end time of the last interval.
            if(i<v.size()-1) sol.push_back(make_pair(v[i+1].first,0));  // Start a new interval if there's one.
        }
    }
    
    cout<<sol.size()<<endl;  // Output the number of time intervals you can encounter a speed camera.
    
    // Output the time intervals when you can encounter a speed camera.
    for(auto i:sol){
        cout<<i.first<<" "<<i.second<<endl;
    }
    
    return 0;
}
/*
Detailed Explanation:
Input Reading:

Read the number of intervals n for the first car's service.
Read the start and end times of each service interval for the first car and store them in the vector v.
Repeat the above steps for the second car's service intervals.
Data Storage:

Use a vector v to store pairs of interval times and their types (start or end).
Processing the Intervals:

Sort the intervals based on their times.
Count Active Intervals:

Iterate through the sorted intervals and count the number of active intervals at each point in time.
Find Time Intervals for Speed Cameras:

Whenever the number of active intervals becomes zero, it signifies a time interval when you can encounter a speed camera.
Output these time intervals.
This program processes the service intervals for two speed camera cars and determines the time intervals when you can encounter a speed camera on the highway, considering the given constraints and objectives of the problem.
*/