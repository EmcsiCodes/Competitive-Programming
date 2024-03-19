#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
The problem, titled "Kézbesítők," involves scheduling meetings between a postmaster and a group of mail carriers.
Each mail carrier has specific work intervals, and the objective is to find the shortest time interval
during which the postmaster can meet with each mail carrier individually.

Here's a more detailed explanation of the problem:

Input:

The first line of the input specifies the number of mail carriers, denoted as K (1 ≤ K ≤ 500).
Following this, there are K blocks of input, each describing a mail carrier's work intervals.
Each block starts with an integer Ni (1 ≤ Ni ≤ 1000), representing the number of work intervals for the current mail carrier.
The subsequent Ni lines in the block describe the start and end days of each work interval for that mail carrier. These intervals are in increasing order of days.
Objective:

The postmaster wants to award a reward to each mail carrier, and these rewards require a personal meeting.
The goal is to determine the shortest continuous time interval during which the postmaster can meet each mail
carrier individually.
Output:

The program should output the start and end days of the shortest continuous interval in which the postmaster can meet all mail carriers.
Example:

For example, if there are three mail carriers and their work intervals are given, the program needs to find the shortest interval during which the postmaster can meet all three.
Constraints:

The time limit for the program is 0.2 seconds.
The memory limit for the program is 32 MB.
*/
int main()
{
    int k;
    cin>>k;
    map< pair<int,int>, pair<int,int> > startDay, endDay;
    vector< vector< pair<int,int> > > v;
    for(int i=0; i<k; i++){
        int n;
        cin>>n;
        vector< pair<int,int> > curr;
        for(int j=0; j<n; j++){
            int x,y;
            cin>>x>>y;
            curr.push_back(make_pair(x,y));
        }
        v.push_back(curr);
    }
    for(int i=0; i<k; i++){
        if(v[i].size()>1){
            startDay[{v[i][0].first,i}] = {i,0};
            endDay[{v[i][0].second,i}] = {i,0};        
        }
    }
    pair<int,int> best={0,1000000};
    bool possible = true;
    int j;
//    cout<<"szevasz";
//    for(auto p=startDay.begin(); p!=startDay.end(); p++) cout<<(p->first).first<<"("<<(p->first).second<<"); ";
//    cout<<endl;
//    for(auto p=endDay.begin(); p!=endDay.end(); p++) cout<<(p->first).first<<"("<<(p->first).second<<"); ";
//    cout<<endl;
    while(possible){
        auto hi = startDay.rbegin()->first.first;
        auto lo = endDay.begin()->first.first;
        if(hi - lo < 0) {
            best = {hi,hi};
            break;
        } else if(hi - lo < best.second - best.first){
            best = {lo,hi};
//            cout<<best.first<<" "<<best.second<<endl;
//            for(auto p=startDay.begin(); p!=startDay.end(); p++) cout<<(p->first).first<<"("<<(p->first).second<<"); ";
//            cout<<endl;
//            for(auto p=endDay.begin(); p!=endDay.end(); p++) cout<<(p->first).first<<"("<<(p->first).second<<"); ";
//            cout<<endl;
        }
        pair<int,int> index;
        index = startDay.begin()->second;
        endDay.erase({v[index.first][index.second].second,index.first});
        startDay.erase({v[index.first][index.second].first,index.first});
        j = index.second + 1;
        if(j<v[index.first].size()){
            startDay[{v[index.first][j].first,index.first}] = {index.first,j};
            endDay[{v[index.first][j].second,index.first}] = {index.first,j};
        } else possible = false;
    }
    cout<<best.first<<" "<<best.second;
    return 0;
}
/*
Problem Overview:
The problem involves finding the shortest continuous time interval during which a postmaster can meet with a group of mail carriers individually. Each mail carrier has specific work intervals, and the task is to determine the shortest continuous time when the postmaster can meet each carrier.

Approach:
The program uses a map to keep track of start and end days for each carrier's work intervals. It then iterates through these intervals to find the shortest continuous time interval during which the postmaster can meet all mail carriers.

Input Reading:
The program starts by reading the number of mail carriers, denoted as k. Following this, it reads the work intervals for each mail carrier and stores them in a vector.

Processing Work Intervals:
For each mail carrier, the program processes their work intervals. If a carrier has more than one work interval, the start and end days of these intervals are stored in a map.

Finding the Shortest Interval:
The program iterates through the intervals and finds the shortest continuous time interval during which the postmaster can meet all mail carriers.

Output:
The program outputs the start and end days of the shortest continuous interval.

Detailed Explanation:
The program uses maps startDay and endDay to store the start and end days of each carrier's work intervals.
It iterates through the intervals to find the shortest continuous time interval
*/