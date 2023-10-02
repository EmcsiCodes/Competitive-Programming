#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*
This problem involves finding the time intervals when you can catch all the broadcasts from different television channels.

Here's a detailed explanation of the problem:

Input:

The first line of the input contains an integer N, representing the number of television channels (1 ≤ N ≤ 100).
The following N lines each describe the broadcast schedule for a channel. Each line contains:
Adi, the number of broadcasts for that channel (0 ≤ Adi ≤ 1000).
Adi pairs of numbers, representing the start and end times of each broadcast for that channel, in increasing order (1 ≤ Ki,j < Vi,j < 8640).
Objective:

The goal is to determine when you can catch all the broadcasts from all television channels simultaneously.
Output:

The program should output:
The number of time intervals (L) when you can catch all broadcasts.
L lines, each containing the start and end times of a time interval, sorted in ascending order of the start time.
Example:

For example, given the broadcast schedules for multiple channels, the program should find the time intervals when you can watch all broadcasts from all channels at the same time.
Constraints:

The time limit for the program is 0.1 seconds.
The memory limit for the program is 32 MB.
In 33% of the tests, N = 2.
*/
int main()
{
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> v; // Vector of vectors to store broadcast schedules for each channel

    // Input: Reading broadcast schedules for each channel
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<pair<int, int>> be;
        for (int j = 0; j < m; j++) {
            int a, b;
            cin >> a >> b;
            be.push_back(make_pair(a, b));
        }
        v.push_back(be);
    }

    // Vector of vectors to store the time intervals when all broadcasts can be caught
    vector<vector<int>> sol1, sol2;
    vector<int> be1, be2;

    // Initialize with the broadcast schedule of the first channel
    for (int j = 0; j < v[0].size(); j++) {
        be1.push_back(v[0][j].first);
        be2.push_back(v[0][j].second);
    }
    sol1.push_back(be1);
    sol2.push_back(be2);

    // Iterating through channels
    for (int i = 1; i < v.size(); i++) {
        vector<int> be1, be2;
        // Iterating through broadcasts of the current channel
        for (int j = 0; j < v[i].size(); j++) {
            int it = upper_bound(sol2[i - 1].begin(), sol2[i - 1].end(), v[i][j].first) - sol2[i - 1].begin();
            if (it < sol2[i - 1].size() && v[i][j].second >= sol1[i - 1][it]) {
                if (min(v[i][j].second, sol2[i - 1][it]) != max(v[i][j].first, sol1[i - 1][it])) {
                    be1.push_back(max(v[i][j].first, sol1[i - 1][it]));
                    be2.push_back(min(v[i][j].second, sol2[i - 1][it]));
                }
            }
        }
        sol1.push_back(be1);
        sol2.push_back(be2);
    }

    // Output: Number of time intervals and the intervals themselves
    cout << sol1[n - 1].size() << endl;
    for (int i = 0; i < sol1[n - 1].size(); i++) {
        cout << sol1[n - 1][i] << " " << sol2[n - 1][i] << endl;
    }
    return 0;
}
/*
Problem Description
The problem involves finding time intervals during which you can catch all broadcasts from different television channels. Each channel has a schedule of broadcasts, represented by start and end times. The goal is to determine the overlapping time intervals when you can watch broadcasts from all channels.

Approach to Solving the Problem
Data Representation:

Each channel's schedule is represented using a vector of pairs, where each pair denotes the start and end time of a broadcast for that channel.
All channel schedules are stored in a vector of vectors.
Finding Overlapping Time Intervals:

We start by considering the broadcasts of the first channel. These broadcasts will serve as the basis for our overlapping intervals.
For each subsequent channel:
We compare the broadcasts of the current channel with the overlapping intervals obtained so far.
If there's an overlap, we update the overlapping intervals.
We use upper_bound to efficiently find the overlapping intervals.
Storing Overlapping Intervals:

We maintain two vectors, sol1 and sol2, to store the start and end times of overlapping intervals, respectively.
Each element in these vectors represents a time interval during which broadcasts from all channels overlap.
Output Formatting:

We output the number of time intervals and the intervals themselves in ascending order of the start time.
Detailed Walkthrough of the Code
Input Processing:

The code first reads the number of television channels, n.
For each channel, it reads the number of broadcasts, m, and the start and end times of each broadcast for that channel.
Initialization:

We initialize the vectors sol1 and sol2 with the broadcasts of the first channel.
These vectors will be updated with overlapping intervals as we iterate through the channels.
Finding Overlapping Intervals:

We start iterating from the second channel.
For each channel:
We iterate through its broadcasts and check for overlaps with the intervals obtained so far.
If there's an overlap, we add the overlapping interval to sol1 and sol2.
We use upper_bound to efficiently find the overlapping intervals in the previous channel's schedule.
Output Generation:

Finally, we output the number of overlapping intervals and the intervals themselves in the required format.
Key Insights
Efficient Overlapping Check:

The use of upper_bound helps efficiently find overlapping intervals, optimizing the overall algorithm.
Optimized Data Representation:

Using vectors and pairs to represent broadcast schedules allows for a clean and efficient representation of the problem.
By effectively organizing and processing the broadcast schedules of each channel, the program successfully identifies and outputs the overlapping time intervals during which you can catch all broadcasts.
*/
