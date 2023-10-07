#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*
- **Problem Description**:
  Given the temperatures recorded for N days, you need to find how many continuous periods have exactly K local warm days and L local cold days.

- **Task**:
  Write a program that calculates the number of continuous periods within the N days that have precisely K local warm days and L local cold days.

- **Input**:
  - The first line of standard input contains the number of days, N (1 ≤ N ≤ 100,000), and the values K and L (1 ≤ K, L ≤ 1000).
  - The second line contains the temperatures recorded for N days, Hi (-100 ≤ Hi ≤ 100).

- **Output**:
  - The program should output the count of intervals where there are exactly K local warm days and L local cold days.

- **Example**:
  - **Input**:
    ```
    13 2 1
    1 1 2 1 0 0 2 0 1 2 1 0 1
    ```
  - **Output**:
    ```
    14
    ```

- **Constraints**:
  - Time Limit: 0.2 seconds
  - Memory Limit: 32 MB
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
Certainly! Let's break down the approach of the program step by step:

**1. Reading Input**:
   - The program starts by reading three pieces of information from the input: `N` (the number of days), `K` (the desired number of local warm days), and `L` (the desired number of local cold days).
   - It also reads the temperatures recorded for each of the `N` days into an array called `a`.

**2. Finding Local Maxima and Minima**:
   - To identify local maxima and minima, the program uses a loop that iterates through the `a` array from the second element (`i = 1`) to the second-to-last element (`i < n - 1`).
   - It checks if the temperature at the current day (`a[i]`) is greater than both the previous day (`a[i - 1]`) and the next day (`a[i + 1]`). If this condition is met, it marks the day as a local maximum by adding a `{1, i + 1}` entry to the `r` vector.
   - Similarly, it checks if the temperature at the current day (`a[i]`) is less than both the previous day (`a[i - 1]`) and the next day (`a[i + 1]`). If this condition is met, it marks the day as a local minimum by adding a `{-1, i + 1}` entry to the `r` vector.

**3. Calculating the Number of Desired Intervals**:
   - The program uses two variables, `mcs` (maximum count of warm days) and `hcs` (maximum count of cold days), to keep track of the count of warm and cold days within a sliding window.
   - It also maintains a variable `ans` to count the desired intervals.

**4. Counting Desired Intervals**:
   - The program then iterates through the `r` vector (which contains information about local maxima and minima) starting from index `1` and going up to the second-to-last element.
   - Within this loop, it updates the counts of warm and cold days based on the type of the local extremum. For example, if the type is `1`, it means it's a local maximum, and the count of warm days (`mcs`) is incremented.
   - It checks if the current window (defined by the interval from index `i - k` to `i`) contains exactly `K` warm days and `L` cold days. If yes, it calculates the length of this interval (the distance between the indices) and adds it to the `ans` variable.
   - This step effectively counts the intervals that meet the specified conditions.

**5. Outputting Results**:
   - Finally, the program prints the value of `ans`, which represents the count of intervals that have exactly `K` local warm days and `L` local cold days.

The approach uses local maxima and minima to identify potential intervals and then checks if these intervals satisfy the warm and cold day counts. If they do, it counts them and accumulates the total count in the `ans` variable, which is eventually printed as the output.
*/