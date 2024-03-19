#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
In a distant galaxy, there are two neighboring planets where life has emerged multiple times.
The goal is to determine the periods when there was life on exactly one of these planets.

Input: The input includes the number of periods of life on each of the two planets and the start and end times for each of these periods.

Output: Output the intervals during which only one of the planets had life.

Example:

Input:
2 2
1 5
12 14
3 10
15 18

Output:
1
1 2

Explanation:

In the given example, there are two periods of life on each planet.
The periods when only one planet had life are 1-2 and 12-18.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    // Vector to store intervals for life on each planet
    vector<pair<int, char>> v;

    // Reading and storing intervals for the first planet
    for (int i = 1; i <= a; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, 'x'}); // Start of life on the first planet
        v.push_back({y, 'y'}); // End of life on the first planet
    }

    // Reading and storing intervals for the second planet
    for (int i = 1; i <= b; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, 'x'}); // Start of life on the second planet
        v.push_back({y, 'y'}); // End of life on the second planet
    }

    // Sorting the intervals based on time
    sort(v.begin(), v.end());

    vector<pair<int, int>> res; // Vector to store the resulting intervals

    int count = 0;

    // Iterate through the intervals to find the periods when only one planet had life
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i].second == 'x')
            count++;
        else
            count--;

        if (count == 1 && v[i].first != v[i + 1].first) {
            if (!res.empty() && abs(v[i].first - res.rbegin()->second) <= 1) {
                res.rbegin()->second = v[i + 1].first;
                if (v[i + 1].second == 'x')
                    res.rbegin()->second--;
            } else {
                res.push_back({v[i].first, v[i + 1].first});
                if (v[i + 1].second == 'x')
                    res.rbegin()->second--;
                if (i > 0 && v[i - 1].second == 'x')
                    res.rbegin()->first++;
            }
            if (res.rbegin()->first > res.rbegin()->second)
                res.pop_back();
        }
    }

    // Output the result
    cout << res.size() << '\n';
    for (auto i : res)
        cout << i.first << " " << i.second << '\n';

    return 0;
}
/*
Approach
The approach involves processing the input intervals for each planet, identifying the times when only one planet had life, and then outputting these intervals.

Input Processing
Read the number of periods of life on each planet: a for planet A and b for planet B.
Create a vector of pairs (v) to store the start and end times for each period of life.
For each period of life on planet A, store the start and end times in v with 'x' to represent the start and 'y' to represent the end.
Repeat the same for planet B, appending the intervals to v.
Interval Identification
Sort the intervals based on their start times.
Initialize a count variable to track the number of overlapping intervals.
Traverse the sorted intervals:
If it's a start time ('x'), increment the count.
If it's an end time ('y'), decrement the count.
When the count is 1, it means only one planet has life at that time, and this is a valid interval.
Collect these intervals in the res vector.
Output
Output the count of intervals when only one planet had life.
Output the start and end times for each interval.
*/