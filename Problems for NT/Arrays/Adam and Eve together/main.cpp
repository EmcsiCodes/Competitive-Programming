#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
This problem involves finding time intervals when both Adam and Eve are available for meetings.
Adam and Eve have specified time intervals during which they are available.
The goal is to determine the overlapping time intervals when they can meet.

Input:

The input includes the last time within the day (P).
Adam's available time intervals are provided (A) along with their start and end times.
Eve's available time intervals are provided (E) along with their start and end times.
Output:

The output should list the overlapping time intervals when Adam and Eve can meet.
The output includes the number of overlapping time intervals (K) and the start and end times of each overlapping interval.
Example:

Given the time constraints and the availability of Adam and Eve, determine the time intervals when they can meet.
Constraints:

The input time limit is 0.4 seconds, and the memory limit is 32 MB.
The problem is scored based on specified constraints, with a focus on cases where P is less than or equal to 100,000.
*/
int main()
{
    int p, n, m;

    // Step 1: Input Reading
    cin >> p >> n;

    // Step 2: Vector Initialization for Adam's Time Intervals
    vector<pair<int, char>> v;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, 'x'});
        v.push_back({y, 'y'});
    }

    // Step 3: Vector Initialization for Eve's Time Intervals
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, 'x'});
        v.push_back({y, 'y'});
    }

    // Step 4: Sorting the Time Intervals
    sort(v.begin(), v.end());

    // Step 5: Counting and Determining Overlapping Intervals
    int count = 0;
    vector<pair<int, int>> res;
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i].second == 'x')
            count++;
        else
            count--;

        if (count == 2 && v[i].first != v[i + 1].first)
            res.push_back({v[i].first, v[i + 1].first});
    }

    // Step 6: Output
    cout << res.size() << endl;
    for (auto i : res)
        cout << i.first << " " << i.second << endl;

    return 0;
}
/*
This program determines the overlapping time intervals
when both Adam and Eve are available for meetings.
It takes inputs for the last time within the day (P),
Adam's available time intervals (A), and Eve's available time intervals (E).
It then calculates the common time intervals when both Adam and Eve can meet
and outputs the count and the start and end times of these overlapping intervals.
The code follows the specified constraints and focuses on efficiency for various time intervals.
*/