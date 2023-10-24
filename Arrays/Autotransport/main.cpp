#include <iostream>
#include <vector>
using namespace std;
/*
A car dealer plans to transport cars from a remote country's car factory to their location using a cargo ship. The factory produces a certain number of cars each day,
and the ship has a maximum car capacity.
The ship arrives at the port on a chosen day and stays there until it's fully loaded.
The dealer's objective is to determine the shortest period during which the ship can be loaded,
minimizing the time spent at the port.

Input:

The first line of the input contains the number of days (N) and the maximum number of cars
the ship can carry (H).

The following N lines specify the number of cars produced on each day.

Output:

The output should indicate the start and end day for loading the ship,
ensuring it's filled in the shortest time possible.

Example:

Given the number of days,
ship's car capacity,
and daily car production,
determine the optimal loading period for the ship to minimize port time.

Constraints:

Time limit for input processing: 0.2 seconds
Memory limit: 32 MB
*/

int main()
{
    int n, h;
    cin >> n >> h;
    int r = 0, l = 0;
    vector<int> day;

    // Step 1: Input Reading
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        day.push_back(x);
    }

    int sum = day[0], best = n + 1;
    int p, q;

    // Step 2: Loading Optimization
    while (r < day.size())
    {
        if (sum < h)
        {
            r++;
            sum += day[r];
        }

        if (sum >= h)
        {
            sum -= day[l];

            if (r - l < best)
            {
                best = r - l;
                p = l + 1;
                q = r + 1;
            }

            l++;
        }
    }

    // Step 3: Output
    if (best == n + 1)
        cout << -1;
    else
        cout << p << " " << q;

    return 0;
}
/*
Explanation of the Program's Approach:

The program aims to find the optimal loading period for a cargo ship, minimizing the time spent at the port. It follows these steps:

Input Reading:

Reads the number of days (N) and the maximum number of cars the ship can carry (H).
Reads the daily car production for each day.
Loading Optimization:

Utilizes a sliding window approach to find the shortest period during which the ship can be loaded.
The sum keeps track of the number of cars in the current window.
The r and l pointers define the window, where r is the right end (end of the loading period) and l is the left end (start of the loading period).
The sum is increased by adding cars produced on the current day until the sum is less than h.
When the sum exceeds h, it starts reducing the window size from the left while keeping track of the best loading period.
Output:

Prints the start and end day for loading the ship in the optimal period to minimize port time, or -1 if no optimal period is found.
Overall, the program efficiently determines the optimal loading period for the ship, minimizing the time spent at the port, based on the given constraints and car production data.
*/