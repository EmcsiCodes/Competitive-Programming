#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
This problem involves finding the intervals during which two friends can go on vacation together, given their available time intervals.

Here's a detailed explanation of the problem:

Input:

The first line of the input contains two integers: N, the number of available time intervals for the first person, and M, the number of available time intervals for the second person (1 ≤ N, M ≤ 100).
The next N lines each describe a time interval for the first person, and the following M lines each describe a time interval for the second person. Each line contains:
E and U, the first and last day of the available time interval for that person (1 ≤ E ≤ U ≤ 365).
Objective:

The goal is to determine the time intervals during which both friends can go on vacation together.
Output:

The program should output:
The number of intervals (K) during which both friends can go on vacation together.
K lines, each containing the first and last day of a joint vacation interval in ascending order of the first day.
Example:

For example, given the available time intervals for both friends, the program should determine the intervals during which they can go on vacation together.
Constraints:

The time limit for the program is 0.1 seconds.
The memory limit for the program is 32 MB.
*/
int main()
{
    int n, m;
    vector<pair<int, int>> v1, v2, sol;
    cin >> n >> m;

    // Read and store the available time intervals for the first person
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v1.push_back(make_pair(x, y));
    }

    // Read and store the available time intervals for the second person
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v2.push_back(make_pair(x, y));
    }

    // Sort the time intervals for both persons based on the start time
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int i = 0, j = 0;

    // Find the overlapping time intervals
    while (i < v1.size() && j < v2.size()) {
        int l = max(v1[i].first, v2[j].first);
        int r = min(v1[i].second, v2[j].second);

        // If the interval is valid (non-empty), add it to the solution
        if (l <= r) {
            if (sol.size() > 0 && sol.back().second == l - 1)
                sol.back().second = r;
            else
                sol.push_back(make_pair(l, r));
        }

        // Move to the next interval based on end times
        if (v1[i].second < v2[j].second)
            i++;
        else
            j++;
    }

    // Output the joint vacation intervals
    cout << sol.size() << endl;
    for (auto i : sol) {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}
/*
Problem Overview:
The problem requires finding the time intervals during which two friends can go on vacation together, given their available time intervals.

Approach:
The program follows these steps to determine the joint vacation intervals:

Input Reading:

Read the number of available time intervals for the first person (n) and the number of available time intervals for the second person (m).
Read and store the time intervals for the first person (v1) and the time intervals for the second person (v2).
Sorting:

Sort the time intervals for both persons based on the start time. This will help in efficiently finding the overlapping intervals.
Finding Overlapping Intervals:

Use two pointers (i and j) to iterate over the sorted intervals of both persons (v1 and v2).
Compare the intervals based on their start and end times to find the overlapping intervals.
If an overlapping interval is found, add it to the solution.
Output:

Output the number of intervals (K) during which both friends can go on vacation together.
Output K lines, each containing the first and last day of a joint vacation interval in ascending order of the first day.
Detailed Explanation:
The program first reads the input values for the number of available time intervals for the first person (n) and the number of available time intervals for the second person (m).
It then processes the time intervals for both persons, storing them in vectors (v1 and v2).
The program sorts the time intervals for both persons based on their start times.
Using two pointers (i and j), the program iterates through the sorted intervals and finds the overlapping intervals.
If an overlapping interval is found, it updates the solution accordingly.
Finally, it prints the number of joint vacation intervals and the first and last day of each interval.
*/