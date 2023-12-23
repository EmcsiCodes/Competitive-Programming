#include <iostream>
#include <vector>
#include <map>

using namespace std;
/*
This problem involves choosing a vacation period of K days from a given set of N days, aiming to find a period with the highest expected temperature among the coldest days.

Here's a detailed explanation of the problem:

Input:

The first line of the input contains two integers: N, the number of days (1 ≤ N ≤ 100,000), and K, the desired vacation period length (1 ≤ K ≤ N).
The following N lines each contain an integer Hi, representing the predicted temperature for a day (-100 ≤ Hi ≤ 100).
Objective:

The goal is to determine a vacation period of K days where the coldest day within that period has the highest expected temperature.
Output:

The program should output:
The starting day (sorszám) of the K-day vacation period.
The lowest predicted temperature within that period.
Example:

For example, given the predicted temperatures for each day, the program should determine the starting day and the lowest temperature within a K-day vacation period, satisfying the conditions.
Constraints:

The time limit for the program is 0.1 seconds.
The memory limit for the program is 32 MB.
In 50% of the tests, N ≤ 100.
*/

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> temp;

    // Read the predicted temperatures for each day
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        temp.push_back(x);
    }

    int r = k;
    map<int, int> m;

    // Initialize the map with occurrences for the first K days
    for (int i = 0; i < k; i++) {
        m[temp[i]] += 1;
    }

    pair<int, int> best = {1, m.begin()->first};  // Initialize with the first K-day period

    while (r < n) {
        // Adjust temperature occurrences for the sliding window
        if (m[temp[r - k]] == 1)
            m.erase(temp[r - k]);
        else
            m[temp[r - k]]--;

        m[temp[r]] += 1;

        // Update the best period if a colder day with higher temperature is found
        if (m.begin()->first > best.second) {
            best.first = r - k + 2;
            best.second = m.begin()->first;
        }
        r++;
    }

    // Print the starting day and the lowest predicted temperature for the best period
    cout << best.first << " " << best.second;

    return 0;
}
/*
Input and Initialization:

The program begins by reading two integers, n and k, representing the total number of days and the desired length of the vacation period, respectively.
It then creates a vector named temp to store the predicted temperatures for each day.
Temperature Input:

The code reads the predicted temperatures for each day, storing them in the vector temp.
Sliding Window Approach:

The program employs a sliding window approach to determine the vacation period with the highest expected temperature among the coldest days.
It initializes an integer r to k to start building the sliding window from day k.
Additionally, a map named m is initialized to keep track of temperature occurrences within the sliding window.
Map Initialization:

The program iterates over the first k days and updates the occurrences of each temperature in the map m.
Sliding Window Iteration:

The loop iterates from the (k+1)th day to the Nth day.
For each iteration, the program updates the temperature occurrences in the map based on the sliding window.
It then compares the lowest predicted temperature in the current window with the previous lowest temperature (best.second). If the current window has a lower temperature, it updates the lowest temperature and the starting day (best.first).
Finally, it moves the window forward by incrementing r.
Output:

The program prints the starting day of the K-day vacation period (best.first) and the lowest predicted temperature within that period (best.second).
This approach efficiently finds the desired vacation period of K days where the coldest day within that period has the highest expected temperature.
*/