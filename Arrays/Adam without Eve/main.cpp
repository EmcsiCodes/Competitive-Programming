#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
Problem Summary:

The problem revolves around scheduling and finding time intervals where Adam and Eve,
two individuals, are available.
The goal is to identify time periods when Adam is available without conflicting with Eve's availability.

Detailed Explanation:

Input:

The last possible time point (P).
Adam's available time intervals (A intervals).
Eve's available time intervals (E intervals).
Output:

Time intervals when we can meet Adam without conflicting with Eve (K intervals).
Approach:

We need to consider the overlapping time intervals of Adam and Eve and exclude the intervals where Eve is also available.
To do this, we start by considering Adam's intervals. For each of Adam's intervals, we check if there is any overlap with Eve's intervals.
If there's an overlap, we split Adam's interval into two parts, excluding the overlap.
We repeat this process for each Adam interval.
The resulting time intervals are the times when we can meet Adam without conflicting with Eve.
Example:

Suppose Adam is available from 8 to 9, and Eve is available from 9 to 13. The overlap is from 9 to 13, so we exclude this interval, leaving us with the intervals from 8 to 9.
Similarly, other intervals are processed accordingly.
Output Format:

The output includes the number of intervals (K) and then lists the start and end times of each interval.
By systematically handling Adam and Eve's schedules, we can determine the times when Adam is available without conflicting with Eve's schedule.

This problem is a scheduling problem with a focus on finding non-conflicting time intervals, crucial for effective planning and coordination between individuals.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int p, n, m;
    cin >> p >> n;

    // Vector to store intervals for Adam and Eve
    vector<pair<int, string>> v;

    // Reading intervals for Adam
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, "xa"}); // Start of Adam's interval
        v.push_back({y, "ya"}); // End of Adam's interval
    }

    cin >> m;

    // Reading intervals for Eve
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, "xe"}); // Start of Eve's interval
        v.push_back({y, "ye"}); // End of Eve's interval
    }

    sort(v.begin(), v.end()); // Sort the intervals based on time

    int count = 0;
    int val = 0;
    vector<pair<int, int>> res;

    // Iterate through the intervals to find non-conflicting time intervals for Adam
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i].second[0] == 'x') {
            if (v[i].second[1] == 'a')
                val++;
            else
                val--;
            count++;
        } else
            count--;

        if (count == 1 && val == 1) {
            // Adam is available and Eve is not active during this interval
            res.push_back({v[i].first, v[i + 1].first});
        }
    }

    // Handle special cases where the last interval ends while Adam is available
    if (v[v.size() - 2].second == "ye")
        res.push_back({v[v.size() - 2].first, v[v.size() - 1].first});

    // Output the result
    cout << res.size() << endl;
    for (auto i : res) {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}
/*
Approach:
The program uses a systematic approach to identify non-conflicting time intervals for Adam:

It stores the intervals for both Adam and Eve in a vector of pairs. Each pair contains a time point and a string that indicates whether it's the start or end of an interval for Adam (xa or ya) or Eve (xe or ye).

The vector of pairs is sorted in ascending order of time points. This sorting allows us to process the intervals sequentially.

The program maintains a count of active intervals and a count of active intervals specific to Adam (val).

It iterates through the sorted intervals and updates the counts based on whether it's the start or end of an interval for Adam or Eve.

When the count is 1 and val is 1, it means that Adam is available and Eve is not active during this interval. So, it records this interval as a valid time when Adam can meet.

Finally, the program handles any special cases where the last interval ends while Adam is available.

Output Format:
The program prints the number of valid intervals (K) and then lists the start and end times of each valid interval.

Example:
Let's say Adam is available from 8 to 9, and Eve is available from 9 to 13. The overlap is from 9 to 13, so the program excludes this interval, leaving us with the intervals from 8 to 9. Similarly, other intervals are processed accordingly.

This program effectively handles scheduling conflicts and determines when Adam can be available without conflicting with Eve's schedule.
*/