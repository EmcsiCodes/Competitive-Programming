#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*
This problem involves scheduling meetings between a postmaster and postal workers within a given time period.

Here's a detailed explanation of the problem:

Input:

The first line of the input contains two integers: N, the number of days (1 ≤ N ≤ 1000), and P, the number of postal workers (1 ≤ P ≤ 500).
The following P lines each contain the workdays for each postal worker, represented by N integers.
Objective:

The goal is to determine the shortest interval within which the postmaster can meet all the postal workers.
Output:

The program should output:
The first and last day of the shortest interval during which the postmaster can meet all the postal workers.
Example:

For example, given the workdays of each postal worker, the program should determine the shortest interval during which the postmaster can meet all the workers.
Constraints:

The time limit for the program is 0.2 seconds.
The memory limit for the program is 32 MB.
*/
int main()
{
    int n, p;
    cin >> n >> p;
    vector<vector<int>> v;

    // Read the workdays for each postal worker
    for (int i = 0; i < p; i++)
    {
        vector<int> curr;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            curr.push_back(x);
        }
        v.push_back(curr);
    }

    // Map to keep track of the current workday being considered for each postal worker
    map<pair<int, int>, pair<int, int>> m;

    // Populate the map with the first workday for each postal worker
    for (int i = 0; i < v.size(); i++)
    {
        pair<int, int> pairs = {v[i][0], i};
        m[pairs] = {i, 0};
    }

    // Variables to store the best interval
    pair<int, int> best, pairs;

    // Find the initial best interval
    pairs = m.begin()->first;
    best.first = pairs.first;
    pairs = m.rbegin()->first;
    best.second = pairs.first;

    // Iterate until all workers' workdays are considered
    while (true)
    {
        bool isLegal = false;
        pair<int, int> index, pairs;

        // Find the postal worker with the earliest next workday
        for (auto k = m.begin(); k != m.end(); k++)
        {
            index = k->second;
            if (index.second + 1 < n)
            {
                isLegal = true;
                break;
            }
        }

        if (!isLegal)
            break;
        else
        {
            // Update the map to consider the next workday for this worker
            pairs = {v[index.first][index.second], index.first};
            m.erase(pairs);
            pairs = {v[index.first][index.second + 1], index.first};
            m[pairs] = {index.first, index.second + 1};

            // Update the best interval if a shorter interval is found
            pairs = m.rbegin()->first;
            int newDiff = pairs.first;
            pairs = m.begin()->first;
            newDiff -= pairs.first;
            int bestDiff = best.second - best.first;
            if (newDiff < bestDiff)
            {
                pairs = m.begin()->first;
                best.first = pairs.first;
                pairs = m.rbegin()->first;
                best.second = pairs.first;
            }
        }
    }

    // Output the first and last day of the shortest interval
    cout << best.first << " " << best.second;

    return 0;
}
/*
Approach
Input Reading and Data Structure Setup:

Read the number of days (n) and the number of postal workers (p).
For each postal worker, read their workdays represented by N integers.
We will use a vector of vectors v to store the workdays for each postal worker.
Additionally, a map m is used to keep track of the current workday being considered for each postal worker.
Populate the Map:

For each postal worker, we add the first workday and the worker index to the map m.
Find Initial Best Interval:

Find the earliest and latest workdays among all postal workers and set them as the initial best interval.
Iterative Process to Update the Best Interval:

Iterate until all workers' workdays are considered:
Find the postal worker with the earliest next workday.
Update the map to consider the next workday for this worker.
Update the best interval if a shorter interval is found.
Output the Result:

Output the first and last day of the shortest interval during which the postmaster can meet all the workers.
Explanation of the Iterative Process:

We use a map to efficiently find the next workday for each postal worker.
At each iteration, we find the postal worker with the earliest next workday and update the map accordingly.
While doing this, we keep track of the best interval seen so far.
*/