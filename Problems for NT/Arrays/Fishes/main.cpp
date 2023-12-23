#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*

Certainly! Here's the detailed summary of the programming problem "Fishes":

Summary of the Programming Problem "Fishes":

For each type of fish, you know the periods when fishing for that fish is prohibited.

Write a program to determine the intervals when it is allowed to catch any fish.

Input:

The first line of the standard input contains the number of fish types (1≤N≤1000).
The next N lines contain the fishing prohibition periods for each fish type.
In each line, the first number represents the starting day of the prohibition period (1≤Ei≤365), followed by the last day within the year for the prohibition (Ei≤Ui≤365).
Output:

The output should first list the number K of intervals during which it was allowed to catch any fish.
The following K lines should contain the starting and ending day of each interval, in ascending order.
Example:

Given the number of fish types and the prohibition periods for each type, determine the intervals during which it was allowed to catch any fish.
Constraints:

Time limit for input processing: 0.1 seconds
Memory limit: 32 MB
In 20% of the tests, N=2.
*/

int main()
{
    int n;
    vector< pair<int,int> > v,vec;
    cin>>n;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end());
    vec.push_back(make_pair(v[0].first,v[0].second));
    int k=0;
    for(int i=1; i<n; i++){
        if(v[i].first>vec[k].second+1){
            k++;
            vec.push_back(make_pair(v[i].first,v[i].second));
        } else vec[k].second=max(vec[k].second,v[i].second);
    }
    int dbnap=0;
    int p=vec.size()-1;
    if(vec[0].first>1) dbnap++;
    if(vec[p].second<365) dbnap++;
    dbnap+=p;
    cout<<dbnap<<endl;
    if(vec[0].first>1) cout<<1<<" "<<vec[0].first-1<<endl;
    for(int i=0; i<p; i++){
        cout<<vec[i].second+1<<" "<<vec[i+1].first-1<<endl;
    }
    if(vec[p].second<365) cout<<vec[p].second+1<<" "<<365<<endl;
    return 0;
}
/*
The problem involves determining the intervals during which it's allowed to catch any fish, based on provided prohibition periods for each type of fish.

Approach:
Input Reading:
The program begins by reading the number of fish types (n) from the standard input. It then reads the prohibition periods for each fish type, storing them as pairs (start_day, end_day) in a vector v.

Sort and Combine Prohibition Periods:

The prohibition periods are sorted based on their starting days.
Then, the program iterates through the sorted prohibition periods and merges overlapping periods into non-overlapping intervals, stored in a vector vec.
Calculating Total Allowed Fishing Days:
The program calculates the total number of days allowed for fishing by summing up the days in each valid fishing interval. This is denoted by dbnap.

Output Formatting:
The program outputs:

The number of valid fishing intervals (dbnap).
Starting and ending days for each interval, in ascending order.
Detailed Explanation:
The program first reads the number of fish types (n) and their prohibition periods. It then sorts these periods based on the starting day. Next, it iterates through the sorted periods and merges overlapping intervals to create non-overlapping intervals, stored in vec.

The program calculates the total number of days during which fishing is allowed (dbnap). It accounts for intervals before the first prohibition and after the last prohibition. Finally, it prints the total number of intervals and the starting and ending days for each interval.

Conclusion:
The program effectively determines and outputs the intervals during which it is allowed to catch any fish, based on the provided prohibition periods. It carefully handles merging overlapping periods and adheres to the problem's constraints to provide a valid solution.
*/