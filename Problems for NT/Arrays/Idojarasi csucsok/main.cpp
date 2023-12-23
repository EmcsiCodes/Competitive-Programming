#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*
For N days, we know the noon temperature. We call a day locally warm (except the first and last days) if the temperature on that day was higher than its two neighbors, and locally cold if it was lower than its two neighbors.

Write a program that determines how many continuous periods within the N days have exactly K locally warm and L locally cold days.

Input:

The first line of the standard input contains the number of days (1≤N≤100 000), as well as the values for K and L (1≤K,L≤1000).
The second line contains the temperatures measured for N days (-100≤Hi≤100).
Output:

The output should be a single line indicating the number of periods within which there were exactly K locally warm and L locally cold days.
Example:

Given the number of days, the values for K and L, and the temperatures recorded for each day, determine the number of periods within which there were exactly K locally warm and L locally cold days.
Constraints:

Time limit for input processing: 0.2 seconds
Memory limit: 32 MB
*/
struct pont
{
    int type, index;
};

int main()
{
    int n, hk, mk;
    cin >> n >> mk >> hk;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<pont> r;
    r.push_back({0, 0});
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i] > a[i - 1] && a[i] > a[i + 1])
        {
            r.push_back({1, i + 1});
        }
        if (a[i] < a[i - 1] && a[i] < a[i + 1])
        {
            r.push_back({-1, i + 1});
        }
    }
    r.push_back({0, n + 1});

    int k = hk + mk;

    int mcs = 0, hcs = 0;
    int ans = 0;

    for (int i = 1; i < r.size() - 1; i++)
    {
        if (i > k)
        {
            if (r[i - k].type == 1)
                mcs--;
            else
                hcs--;
        }

        if (r[i].type == 1)
            mcs++;
        else
            hcs++;

        if (mcs == mk && hcs == hk)
        {
            int alsoI = i - k + 1;
            int felsoI = i;
            int also = abs(r[alsoI].index - r[alsoI-1].index);
            int felso = abs(r[felsoI].index - r[felsoI+1].index);
            ans += also*felso;
        }
    }

    cout << ans << endl;
    return 0;
}
/*
Problem Overview:
The problem involves determining the number of continuous periods within N days that have exactly K locally warm and L locally cold days.

Approach:
Input Reading:
The program starts by reading the number of days (n), the values for K (mk) and L (hk), and the temperatures recorded for each day. It also creates a vector r to store temperature change points.

Temperature Analysis:
The program then iterates through the temperature values, identifying points where the temperature is locally warm or locally cold based on its relationship with its neighbors. These points are stored in the vector r.

Counting Periods:
The program then counts the number of periods that have exactly K locally warm and L locally cold days. It does this by iterating through the temperature change points, maintaining counters for locally warm and cold days in a window of size K+L. When the counters match the required counts, the program calculates the length of the continuous period and adds it to the total count.

Output:
The program prints the count of continuous periods that meet the criteria.

Detailed Explanation:
The program reads the input data and processes the temperatures to identify locally warm and cold days. It then iterates through the points, calculating the length of continuous periods that meet the specified criteria (K locally warm and L locally cold days). The lengths of these periods are added to the total count, which is then printed as the final result.

Conclusion:
The program effectively calculates the count of continuous periods with specific locally warm and cold days as per the given criteria. It analyzes the temperature changes and efficiently identifies the required patterns within the provided temperature data.
*/